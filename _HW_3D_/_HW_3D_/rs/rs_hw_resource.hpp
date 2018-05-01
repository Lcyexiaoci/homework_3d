#pragma once

#include "rs_fwd.h"
#include "rs_utils.hpp"

_HW_3D_OPEN_HW_NAMESPACE_

_HW_3D_OPEN_RS_NAMESPACE_

//
//
enum class Resource_write_hint {
	none,
	discard,
	no_override,
};

//
//
_HW_3D_INLINE_FUNCTION_ _HW_3D_D3D_ Map
	d3d_map_type(
		_HW_3D_IN_ Resource_write_hint hint
	) {
	switch (hint) {
	case Resource_write_hint::discard:
		return _HW_3D_D3D_ Map::write_discard;
	case Resource_write_hint::no_override:
		return _HW_3D_D3D_ Map::write_no_overwrite;
	default:
		return _HW_3D_D3D_ Map::write;
	}
}

//
//
template <typename _Metadata_type>
struct _D3d_resource_helper_base {
public:
	using Metadata_type = _Metadata_type;
	using Context_type = _HW_3D_D3D_ IDevice_context;
	using Device_type = _HW_3D_D3D_ IDevice;
public:
	static bool
		is_mappable_as_src(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return ((metadata.CPUAccessFlags & Resource_cpu_access_flag::bit_type::read) != Resource_cpu_access_flag{})
			&& (metadata.Usage == Resource_usage::staging);
	}

	static bool
		is_mappable_as_dst(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return ((metadata.CPUAccessFlags & Resource_cpu_access_flag::bit_type::write) != Resource_cpu_access_flag{})
			&& (metadata.Usage == Resource_usage::staging || metadata.Usage == Resource_usage::dynamic);
	}

	static bool
		is_mappable(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return is_mappable_as_src(metadata)
			&& is_mappable_as_dst(metadata);
	}

	static bool
		is_mappable_as_dst_and_discard(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return ((metadata.CPUAccessFlags & Resource_cpu_access_flag::bit_type::write) != Resource_cpu_access_flag{})
			&& (metadata.Usage == Resource_usage::dynamic);
	}

	static bool
		is_mappable_as_dst_and_no_overwrite(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return ((metadata.CPUAccessFlags & Resource_cpu_access_flag::bit_type::write) != Resource_cpu_access_flag{})
			&& (metadata.Usage == Resource_usage::dynamic)
			&& ((metadata.BindFlags & Resource_bind_flag::bit_type::vertex_buffer) != Resource_bind_flag{} ||
			(metadata.BindFlags & Resource_bind_flag::bit_type::index_buffer) != Resource_bind_flag{});
	}

	static bool
		is_updatable_as_dst(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return !((metadata.Usage == Resource_usage::_immutable || metadata.Usage == Resource_usage::dynamic)
			|| (metadata.BindFlags & Resource_bind_flag::bit_type::depth_stencil) != Resource_bind_flag{});
	}

	//for copy(gpu/gpu)
	static bool
		is_copyable_as_dst(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return (metadata.Usage == Resource_usage::_default || metadata.Usage == Resource_usage::staging);
	}

	//for view
	static bool
		is_used_as_unordered_access_view(
			_HW_3D_IN_ Metadata_type& metadata
		) {
		return (metadata.BindFlags & Resource_bind_flag::bit_type::unordered_access) != Resource_bind_flag{};
	}

	static bool
		is_used_as_render_target_view(
			_HW_3D_IN_ Metadata_type& metadata
		) {
		return (metadata.BindFlags & Resource_bind_flag::bit_type::render_target) != Resource_bind_flag{};
	}

	static bool
		is_used_as_depth_stencil_view(
			_HW_3D_IN_ Metadata_type& metadata
		) {
		return (metadata.BindFlags & Resource_bind_flag::bit_type::depth_stencil) != Resource_bind_flag{};
	}

	static bool
		is_used_as_shader_resource_view(
			_HW_3D_IN_ Metadata_type& metadata
		) {
		return (metadata.BindFlags & Resource_bind_flag::bit_type::shader_resource) != Resource_bind_flag{};
	}

};

struct _D3d_buffer_helper : _D3d_resource_helper_base<_HW_3D_D3D_ Buffer_desc> {
public:
	using Metadata_type = _HW_3D_D3D_ Buffer_desc;
	using Handle_type = _HW_3D_D3D_ IBuffer;
	using Native_handle_type = ID3D11Buffer;
	using Subresource_type = Handle_type * ;

public:
	static _HW_3D_STD_ vector<_HW_3D_STD_ byte>
		read(
			_HW_3D_IN_ Context_type* context,
			_HW_3D_IN_ Subresource_type src,
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ uint32_t size
		) {
		_HW_3D_STD_ vector<_HW_3D_STD_ byte> res;
	
		auto[success, result] = context->map(src, 0, _HW_3D_D3D_ Map::read, {});
		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to map buffer");

		res.resize(size);
		_HW_3D_STD_ memcpy(res.data(), reinterpret_cast<_HW_3D_STD_ byte*>(result.pData) + offset, res.size());

		context->unmap(src, 0);

		return res;
	}

	static void
		copy(
			_HW_3D_IN_ Context_type* context,
			_HW_3D_IN_ Handle_type* dst,
			_HW_3D_IN_ Handle_type* src
		) {
		context->copy_resource(dst, src);
	}

	static void
		copy(
			_HW_3D_IN_ Context_type* context,
			_HW_3D_IN_ Subresource_type dst,
			_HW_3D_IN_ uint32_t dst_offset,
			_HW_3D_IN_ Subresource_type src,
			_HW_3D_IN_ uint32_t src_offset,
			_HW_3D_IN_ uint32_t size
		) {
		auto src_box = transfer_to_box(Offset1d(src_offset), Extent1d(size));

		context->copy_subresource_region(dst, 0, { dst_offset, 0, 0 }, src, 0, &src_box);
	}

	uint32_t
		size(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return metadata.ByteWidth;
	}

	uint32_t
		stride(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return metadata.StructureByteStride;
	}

	_HW_3D_STD_ unique_ptr<Handle_type>
		create(
			_HW_3D_IN_ Device_type* device,
			_HW_3D_IN_ const Metadata_type& metadata,
			_HW_3D_IN_ const void* data
		) {
		_HW_3D_D3D_ Subresource_data init_data;
		init_data.pSysMem = data;
		auto[success, buffer] = device->create_buffer(metadata, &init_data);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to create buffer");

		return _HW_3D_STD_ move(buffer);
	}

	static void
		write_via_mapping(
			_HW_3D_IN_ Context_type* context,
			_HW_3D_IN_ Subresource_type dst,
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ uint32_t size,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ Resource_write_hint hint
		) {
		_HW_3D_D3D_ Map map_type = d3d_map_type(hint);

		auto[success, result] = context->map(dst, 0, map_type, {});
		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to map buffer");

		_HW_3D_STD_ memcpy(reinterpret_cast<_HW_3D_STD_ byte*>(result.pData) + offset, data, size);
		
		context->unmap(dst, 0);
	}

	static void
		write_via_update(
			_HW_3D_IN_ Context_type* context,
			_HW_3D_IN_ Subresource_type dst,
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ uint32_t size,
			_HW_3D_IN_ const void* data
		) {
		auto dst_box = _HW_3D_RS_ transfer_to_box(_HW_3D_RS_ Offset1d(offset), _HW_3D_RS_ Extent1d(size));
		context->update_subresource(dst, 0, &dst_box, data, 0, 0);
	}
};

//
template <typename Buffer_helper>
class _THardware_buffer {
public:
	using _My_helper = Buffer_helper;
	using _My_type = _THardware_buffer<Buffer_helper>;

	using Handle_type = typename _My_helper::Handle_type;
	using Native_handle_type = typename _My_helper::Native_handle_type;
	using Metadata_type = typename _My_helper::Metadata_type;

public:
	_THardware_buffer(
		_HW_3D_IN_ const Metadata_type& metadata,
		_HW_3D_IN_ const void* initial_data,
		_HW_3D_IN_ Render_manager* render_manager
	) : _metadata(metadata)
		, _render_manager(render_manager) {
		_buffer = _My_helper::create(_render_manager->device(), _metadata, initial_data);
	}

	Handle_type* 
		handle() const {
		return _buffer.get();
	}

	Native_handle_type* 
		native_handle() const {
		return _buffer->get();
	}

	uint32_t
		size() const {
		return _My_helper::size(_metadata);
	}

	uint32_t
		stride() const {
		return _My_helper::stride(_metadata);
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ byte>
		read(
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ uint32_t size
		) {
#ifdef _DEBUG
		if (!_My_helper::is_mappable_as_src(_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to read from no-readabel buffer");
#endif
		size = (_HW_3D_STD_ min)(this->size() - offset, size);
		return _My_helper::read(_render_manager->context(), _buffer.get(), offset, size);
	}

	void
		write (
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ uint32_t size,
			_HW_3D_IN_ const void* data
		) {
#ifdef _DEBUG
		if (!_My_helper::is_updatable_as_dst(_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "should update via mapped pointer");
#endif
		size = (_HW_3D_STD_ min)(this->size() - offset, size);
		_My_helper::write_via_update(_render_manager->context(), _buffer.get(), offset, size, data);
	}

	void 
		write_via_mapping(
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ uint32_t size,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ Resource_write_hint hint
		) {
#ifdef _DEBUG
		if (!_My_helper::is_mappable_as_dst(_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "should not update via mapped pointer");

		if (hint == Resource_write_hint::discard && !_My_helper::is_mappable_as_dst_and_discard(_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to dicard a un-discardable buffer");

		if (hint == Resource_write_hint::no_override && !_My_helper::is_mappable_as_dst_and_no_override(_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "invalid resource write hint");
#endif
		size = (_HW_3D_STD_ min)(this->size() - offset, size);
		_My_helper::write_via_mapping(_render_manager->context(), _buffer.get(), offset, size, hint);
	}

	void
		copy(
			_HW_3D_IN_ _My_type* other
		) {
#ifdef _DEBUG
		if (!_My_helper::is_copyable_as_dst(_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy to a no copyable buffer");

		if (this == other)
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy between same buffer");

		if (this->size() != other->size())
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy between different size buffer");

		if (this->_render_manager != other->_render_manager)
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy between differnt context");
#endif
		_My_helper::copy(_render_manager->context(), _buffer.get(), other->_buffer.get());
	}

	void
		copy(
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ _My_type* other,
			_HW_3D_IN_ uint32_t src_offset,
			_HW_3D_IN_ uint32_t size
		) {
#ifdef _DEBUG
		if (!_My_helper::is_copyable_as_dst(_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy to a no copyable buffer");

		if (this->_render_manager != other->_render_manager)
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy between differnt context");
#endif
		_My_helper::copy(_render_manager->context(), _buffer.get(), offset, other->handle(), src_offset, size);
	}
private:
	_HW_3D_STD_ unique_ptr<Handle_type> _buffer;
	Metadata_type _metadata;
	Render_manager* const _render_manager;
};

//
//
template <typename Buffer_helper, typename _My_base = typename Buffer_helper::Metadata_type>
struct _THardware_buffer_builder : _My_base {
	using Hardware_buffer_type = _THardware_buffer<Buffer_helper>;

	_HW_3D_STD_ unique_ptr<Hardware_buffer_type>
		create(
			_HW_3D_IN_ const void* pdata = nullptr,
			_HW_3D_IN_ Render_manager* render_manager = nullptr
		) {
		render_manager = render_manager == nullptr ? Render_manager::current_render_manager() : render_manager;
		if (render_manager == nullptr)
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to create buffer without hardware");
		return _HW_3D_STD_ make_unique<Hardware_buffer_type>(*this, pdata, render_manager);
	}
};

//
using Hardware_buffer = _THardware_buffer<_D3d_buffer_helper>;
using Hardware_buffer_builder = _THardware_buffer_builder<_D3d_buffer_helper>;


template <typename _Texture_desc, typename = _HW_3D_STD_ void_t<>>
struct _Has_member_sample_desc : _HW_3D_STD_ false_type {

};

template <typename _Texture_desc>
struct _Has_member_sample_desc<_Texture_desc, _HW_3D_STD_ void_t<decltype(_Texture_desc::_sample_desc)>> : _HW_3D_STD_ true_type {

};

template <typename _Texture_desc>
constexpr bool _has_member_sample_desc_v = _Has_member_sample_desc<_Texture_desc>::value;

template <typename _Metadata_type>
struct _D3d_texture_helper_base : _D3d_resource_helper_base<_Metadata_type> {
public:
	using Metadata_type = _Metadata_type;
	using _My_base = _D3d_resource_helper_base<_Metadata_type>;
public:
	static bool
		is_compressed(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		using _Fmt = _HW_3D_DXGI_ Format;
		switch (metadata.Format) {
		case _Fmt::bc1_typeless:
		case _Fmt::bc1_unorm:
		case _Fmt::bc1_unorm_srgb:
		case _Fmt::bc2_unorm:
		case _Fmt::bc2_unorm_srgb:
		case _Fmt::bc3_typeless:
		case _Fmt::bc3_unorm:
		case _Fmt::bc3_unorm_srgb:
		case _Fmt::bc4_typeless:
		case _Fmt::bc4_unorm:
		case _Fmt::bc4_snorm:
		case _Fmt::bc5_typeless:
		case _Fmt::bc5_unorm:
		case _Fmt::bc5_snorm:
		case _Fmt::bc6h_typess:
		case _Fmt::bc6h_uf16:
		case _Fmt::bc6h_sf16:
		case _Fmt::bc7_typeless:
		case _Fmt::bc7_unorm:
		case _Fmt::bc7_unorm_srgb:
			return true;
		default:
			return false;
		}
	}

	static _HW_3D_STD_ pair<uint32_t, uint32_t>
		pixel_size(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		using _Fmt = _HW_3D_DXGI_ Format;
		switch (metadata.Format) {
		case _Fmt::r32g32b32a32_typeless:
		case _Fmt::r32g32b32a32_float:
		case _Fmt::r32g32b32a32_int:
		case _Fmt::r32g32b32a32_uint:
			return { 1, 16 };
		case _Fmt::r32g32b32_typeless:
		case _Fmt::r32g32b32_float:
		case _Fmt::r32g32b32_int:
		case _Fmt::r32g32b32_uint:
			return { 1, 12 };
		case _Fmt::r16g16b16a16_typeless:
		case _Fmt::r16g16b16a16_float:
		case _Fmt::r16g16b16a16_unorm:
		case _Fmt::r16g16b16a16_uint:
		case _Fmt::r16g16b16a16_snorm:
		case _Fmt::r16g16b16a16_int:
		case _Fmt::r32g32_typeless:
		case _Fmt::r32g32_float:
		case _Fmt::r32g32_uint:
		case _Fmt::r32g32_int:
		case _Fmt::r32g8x24_typeless:
		case _Fmt::d32_float_s8x24_uint:
		case _Fmt::r32_float_x8x24_typeless:
		case _Fmt::x32_typeless_g8x24_uint:
			return { 1, 8 };
		case _Fmt::r10g10b10a2_typeless:
		case _Fmt::r10g10b10a2_unorm:
		case _Fmt::r10g10b10a2_uint:
		case _Fmt::r11g11b10_float:
		case _Fmt::r8g8b8a8_typeless:
		case _Fmt::r8g8b8a8_unorm:
		case _Fmt::r8g8b8a8_unorm_srgb:
		case _Fmt::r8g8b8a8_uint:
		case _Fmt::r8g8b8a8_snorm:
		case _Fmt::r8g8b8a8_int:
		case _Fmt::r16g16_typeless:
		case _Fmt::r16g16_float:
		case _Fmt::r16g16_unorm:
		case _Fmt::r16g16_uint:
		case _Fmt::r16g16_snorm:
		case _Fmt::r16g16_int:
		case _Fmt::r32_typeless:
		case _Fmt::d32_float:
		case _Fmt::r32_float:
		case _Fmt::r32_uint:
		case _Fmt::r32_int:
		case _Fmt::r24g8_typeless:
		case _Fmt::d24_unorm_s8_uint:
		case _Fmt::r24_unorm_x8_typeless:
		case _Fmt::x24_typeless_g8_uint:
		case _Fmt::r9g9b9e5_sharedexp:
		case _Fmt::b8g8r8a8_unorm:
		case _Fmt::b8g8r8x8_unorm:
		case _Fmt::r10g10b10_xr_bias_a2_unorm:
		case _Fmt::b8g8r8a8_typeless:
		case _Fmt::b8g8r8a8_unorm_srgb:
		case _Fmt::b8g8r8x8_unorm_srgb:
		case _Fmt::b8g8r8x8_typeless:
			return { 1, 4 };
		case _Fmt::r8g8_typeless:
		case _Fmt::r8g8_unorm:
		case _Fmt::r8g8_uint:
		case _Fmt::r8g8_snorm:
		case _Fmt::r8g8_int:
		case _Fmt::r16_typeless:
		case _Fmt::r16_float:
		case _Fmt::d16_unorm:
		case _Fmt::r16_unorm:
		case _Fmt::r16_uint:
		case _Fmt::r16_snorm:
		case _Fmt::r16_int:
		case _Fmt::b5g6r5_unorm:
		case _Fmt::b5g5r5a1_unorm:
			return { 1, 2 };
		case _Fmt::r8_typeless:
		case _Fmt::r8_unorm:
		case _Fmt::r8_int:
		case _Fmt::r8_uint:
		case _Fmt::r8_snorm:
		case _Fmt::a8_unorm:
			return { 1, 1 };
		case _Fmt::r1_unorm:
			return { 8, 1 };
		case _Fmt::r8g8_b8g8_unorm:
		case _Fmt::g8r8_g8b8_unorm:
			return { 2, 4 };
		case _Fmt::bc1_typeless:
		case _Fmt::bc1_unorm:
		case _Fmt::bc1_unorm_srgb:
		case _Fmt::bc4_snorm:
		case _Fmt::bc4_typeless:
		case _Fmt::bc4_unorm:
			return { 16, 8 };
		case _Fmt::bc2_typeless:
		case _Fmt::bc2_unorm:
		case _Fmt::bc2_unorm_srgb:
		case _Fmt::bc3_typeless:
		case _Fmt::bc3_unorm:
		case _Fmt::bc3_unorm_srgb:
		case _Fmt::bc5_snorm:
		case _Fmt::bc5_typeless:
		case _Fmt::bc5_unorm:
		case _Fmt::bc6h_sf16:
		case _Fmt::bc6h_typess:
		case _Fmt::bc6h_uf16:
		case _Fmt::bc7_typeless:
		case _Fmt::bc7_unorm:
		case _Fmt::bc7_unorm_srgb:
			return { 16, 16 };
		default:
			return { 0, 0 };
		}
	}

	static bool
		is_auto_generate_mipmaps(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return ((metadata.MiscFlags & Resource_misc_flag::bit_type::generate_mips) != Resource_misc_flag{} 
			&& ((metadata.BindFlags & Resource_bind_flag::bit_type::shader_resource) != Resource_bind_flag{} || 
				(metadata.BindFlags & Resource_bind_flag::bit_type::render_target) != Resource_bind_flag{}));
	}

	static bool
		is_multisample(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		if constexpr(_has_member_sample_desc_v<Metadata_type>) {
			return metadata.SampleDesc.Count != 1;
		}
		else {
			return false;
		}
	}

	static bool
		is_updatable_as_dst(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return _My_base::is_updatable_as_dst(metadata) && !is_multisample(metadata);
	}
};

template <typename _Texture_type>
struct _D3d_texture_subresource {
	_Texture_type* texture;
	uint32_t mip_slice;
	uint32_t array_slice;
	uint32_t mip_levels;

	_D3d_texture_subresource(
		_HW_3D_IN_ _Texture_type* texture_ = nullptr,
		_HW_3D_IN_ uint32_t mip_slice_ = 0,
		_HW_3D_IN_ uint32_t array_slice_ = 0,
		_HW_3D_IN_ uint32_t mip_levels_ = 0
	) : texture(nullptr)
		, mip_slice(mip_slice_)
		, array_slice(array_slice_)
		, mip_levels(mip_levels_) {

	}

	explicit operator uint32_t() const {
		return _HW_3D_D3D_ calc_subresource(mip_slice, array_slice, mip_levels);
	}

	_D3d_texture_subresource(const _D3d_texture_subresource&) = default;
	_D3d_texture_subresource& operator=(const _D3d_texture_subresource&) = default;
};

//
//for simplicity, read and write only in a level and array slice
struct _D3d_texture1d_helper : _D3d_texture_helper_base<_HW_3D_D3D_ Texture1d_desc> {
public:
	using Metadata_type = _HW_3D_D3D_ Texture1d_desc;
	using Handle_type = _HW_3D_D3D_ ITexture1d;
	using Native_handle_type = ID3D11Texture2D;
	using Subresource_type = _D3d_texture_subresource<Handle_type>;
public:

	static _HW_3D_STD_ vector<_HW_3D_STD_ byte>
		read(
			_HW_3D_IN_ Context_type* context,
			_HW_3D_IN_ Subresource_type src,
			_HW_3D_IN_ const Metadata_type& metadata,
			_HW_3D_IN_ const Range1d& range
		) {
		_HW_3D_STD_ vector<_HW_3D_STD_ byte> res;
		auto[pixels, total_size] = pixel_size(metadata);

		auto[success, result] = context->map(
			src.texture,
			static_cast<uint32_t>(src),
			_HW_3D_D3D_ Map::read,
			{});
		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to map buffer");

		auto offset = range.offset.x / pixels * total_size;
		auto size = range.extent.width / pixels * total_size;

		res.resize(size);
		_HW_3D_STD_ memcpy(res.data(), reinterpret_cast<_HW_3D_STD_ byte*>(result.pData) + offset, res.size());

		context->unmap(src.texture, static_cast<uint32_t>(src));

		return res;
	}

	static void
		copy(
			_HW_3D_IN_ Context_type* context,
			_HW_3D_IN_ Handle_type* dst,
			_HW_3D_IN_ Handle_type* src
		) {
		context->copy_resource(dst, src);
	}

	static void
		copy(
			_HW_3D_IN_ Context_type* context,
			_HW_3D_IN_ Subresource_type dst,
			_HW_3D_IN_ Offset1d dst_offset,
			_HW_3D_IN_ Subresource_type src,
			_HW_3D_IN_ const Range2d& src_range
		) {
		auto src_box = transfer_to_box(src_range);
		context->copy_subresource_region(
			dst.texture, 
			static_cast<uint32_t>(dst), 
			{dst_offset.x},
			src.texture,
			static_cast<uint32_t>(src),
			&src_box);
	}

	static Extent1d
		size(
			_HW_3D_IN_ const Metadata_type& metadata,
			_HW_3D_IN_ uint32_t level
		) {
		return get_mipmaps_length(metadata.Width, level);
	}

	static uint32_t
		data_size(
			_HW_3D_IN_ const Metadata_type& metadata,
			_HW_3D_IN_ uint32_t level
		) {
		auto[pixels, total_size] = pixel_size(metadata);
		auto width = size(metadata, level).width;
		return (width + pixels - 1) / pixels * total_size;
	}

	static uint32_t
		width(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return metadata.Width;
	}

	static uint32_t
		mip_levels(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return metadata.MipLevels;
	}

	static uint32_t
		array_size(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return metadata.ArraySize;
	}

	static Pixel_format
		format(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return metadata.Format;
	}

	_HW_3D_STD_ unique_ptr<Handle_type>
		create(
			_HW_3D_IN_ Device_type* device,
			_HW_3D_IN_ const Metadata_type& metadata,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ uint32_t row_pitch
		) {
		_HW_3D_D3D_ Subresource_data init_data;
		init_data.pSysMem = data;
		init_data.SysMemPitch = row_pitch;
		auto[success, texture] = device->create_texture_1d(metadata, &init_data);
		
		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "faield to create texture1d");

		return _HW_3D_STD_ move(texture);
	}

	static void
		write_via_mapping(
			_HW_3D_IN_ Context_type* context,
			_HW_3D_IN_ Subresource_type dst,
			_HW_3D_IN_ const Metadata_type& metadata,
			_HW_3D_IN_ const Range1d& range,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ Resource_write_hint hint
		) {
		auto map_type = d3d_map_type(hint);

		auto[success, result] = context->map(dst.texture, static_cast<uint32_t>(dst), map_type, {});
		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to map texture 1d");

		auto[pixels, total_size] = pixel_size(metadata);
		
		auto offset = range.offset.x / pixels * total_size;
		auto size = range.extent.width / pixels * total_size;

		_HW_3D_STD_ memcpy(reinterpret_cast<_HW_3D_STD_ byte*>(result.pData) + offset, data, size);
		
		context->unmap(dst.texture, static_cast<uint32_t>(dst));
	}

	static void
		write_via_update(
			_HW_3D_IN_ Context_type* context,
			_HW_3D_IN_ Subresource_type dst,
			_HW_3D_IN_ const Range1d& range,
			_HW_3D_IN_ const void* data
		) {
		auto dst_box = _HW_3D_RS_ transfer_to_box(range);
		context->update_subresource(dst.texture, static_cast<uint32_t>(dst), &dst_box, data, 0, 0);
	}
};

//
//
template <typename Texture1d_helper>
class _THardware_texture1d {
public:
	using _My_helper = Texture1d_helper;
	using _My_type = _THardware_texture1d<Texture1d_helper>;

	using Handle_type = typename _My_helper::Handle_type;
	using Native_handle_type = typename _My_helper::Native_handle_type;
	using Metadata_type = typename _My_helper::Metadata_type;
	using Subresource_type = typename _My_helper::Subresource_type;

public:
	_THardware_texture1d(
		_HW_3D_IN_ const Metadata_type& metadata,
		_HW_3D_IN_ const void* initial_data,
		_HW_3D_IN_ uint32_t row_pitch,
		_HW_3D_IN_ Render_manager* render_manager
	) : _metadata(metadata)
		, _render_manager(render_manager) {
		_texture = _My_helper::create(_render_manager->device(), _metadata, row_pitch, render_manager);
	}

	Handle_type*
		handle() const {
		return _texture.get();
	}

	Native_handle_type*
		native_handle() const {
		return _texture->get();
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ byte>
		read(
			_HW_3D_IN_ uint32_t level,
			_HW_3D_IN_ uint32_t array_index,
			_HW_3D_IN_ const Range1d& range
		) {
#ifdef _DEBUG
		if (!_My_helper::is_mappable_as_src(_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to read form no-readable texture");
#endif
		return _My_helper::read(_render_manager->context(), Subresource_type(_texture.get(), level, array_index), _metadata, range);
	}

	void
		copy(
			_HW_3D_IN_ _My_type* other
		) {
#ifdef _DEBUG
		if (!_My_helper::is_copyable_as_dst(_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy a no copyable texture");

		if (this == other)
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy between same texture");

		if (this->size() != other->size())
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy between different size");

		/*should be a compatible format, too relunctant*/

		if (this->_render_manager != other->_render_manager)
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy between different context");
#endif
		_My_helper::copy(_render_manager->context(), _texture.get(), other->handle());
	}

	void
		copy(
			_HW_3D_IN_ uint32_t level,
			_HW_3D_IN_ uint32_t array_index,
			_HW_3D_IN_ Offset1d offset,
			_HW_3D_IN_ _My_type* other,
			_HW_3D_IN_ uint32_t src_lev,
			_HW_3D_IN_ uint32_t src_array_idx,
			_HW_3D_IN_ const Range1d& src_range
		) {
#ifdef _DEBUG
		if (!_My_helper::is_copyable_as_dst(_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy a no copyable texture");

		if (this == other && level == src_lev && array_index == src_array_idx)
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy between same texture");

		if (this->_render_manager != other->_render_manager)
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy between different context");
#endif
		_My_helper::copy(
			_render_manager->context(), 
			Subresource_type(_texture.get(), level, array_index), 
			offset,
			Subresource_type(other->handle(), src_lev, src_array_idx),
			src_range);
	}

	void
		write(
			_HW_3D_IN_ uint32_t level,
			_HW_3D_IN_ uint32_t array_index,
			_HW_3D_IN_ const Range1d& range,
			_HW_3D_IN_ const void* data
		) {
#ifdef _DEBUG
		if (!_My_helper::is_updatable_as_dst(_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "should update via mapped pointer");
#endif
		_My_helper::write_via_update(
			_render_manager->context(),
			Subresource_type(_texture.get(), level, array_index),
			range,
			data);
	}

	void
		write_via_mapping(
			_HW_3D_IN_ uint32_t level,
			_HW_3D_IN_ uint32_t array_index,
			_HW_3D_IN_ const Range1d& range,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ Resource_write_hint hint
		) {
#ifdef _DEBUG
		if (!_My_helper::is_mappable_as_dst(_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "should not update via mapped pointer");

		if (hint == Resource_write_hint::discard && !_My_helper::is_mappable_as_dst_and_discard(_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to dicard a un-discardable buffer");

		if (hint == Resource_write_hint::no_override && !_My_helper::is_mappable_as_dst_and_no_override(_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "invalid resource write hint");
#endif
		_My_helper::write_via_mapping(
			_render_manager->context(),
			Subresource_type(_texture.get(), level, array_index),
			_metadata,
			range,
			data,
			hint);
	}

	bool
		is_compressed() const {
		return _My_helper::is_compressed(_metadata);
	}

	bool
		is_multisample() const {
		return _My_helper::is_multisample(_metadata);
	}

	Extent1d
		size(
			_HW_3D_IN_ uint32_t level = 0
		) const {
		return _My_helper::size(_metadata, level);
	}

	uint32_t
		data_size(
			_HW_3D_IN_ uint32_t level = 0
		) const {
		return  _My_helper::data_size(_metadata, level);
	}

	uint32_t
		width() const {
		return _My_helper::width(_metadata);
	}

	uint32_t
		mip_levels() const {
		return _My_helper::mip_levels(_metadata);
	}

	uint32_t
		array_size() const {
		return _My_helper::array_size(_metadata);
	}

	Pixel_format
		format() const {
		return _My_helper::format(_metadata);
	}
private:
	_HW_3D_STD_ unique_ptr<Handle_type> _texture;
	Metadata_type _metadata;
	Render_manager* const _render_manager;
};

//
//
template <typename Texture1d_helper, typename _My_base = typename Texture1d_helper::Metadata_type>
struct _THardware_texture1d_builder : _My_base {
	using Hardware_texture1d_type = _THardware_texture1d<Texture1d_helper>;

	_HW_3D_STD_ unique_ptr<Hardware_texture1d_type>
		create(
			_HW_3D_IN_ const void* pdata,
			_HW_3D_IN_ uint32_t row_pitch,
			_HW_3D_IN_ Render_manager* render_manager = nullptr
		) {
		render_manager = render_manager == nullptr ? Render_manager::current_render_manager() : render_manager;

		if (render_manager == nullptr)
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to create texture without hardware");

		return _HW_3D_STD_ make_unique<Hardware_texture1d_type>(*this, pdata, row_pitch, render_manager);
	}
};

//
//
using Hardware_texture1d = _THardware_texture1d<_D3d_texture1d_helper>;
using Hardware_texture1d_builder = _THardware_texture1d_builder<_D3d_texture1d_helper>;

_HW_3D_CLOSE_RS_NAMESPACE_

_HW_3D_CLOSE_HW_NAMESPACE_
