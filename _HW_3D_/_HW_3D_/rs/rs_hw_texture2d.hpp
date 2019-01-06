#pragma once

#include "rs_hw_texture.hpp"

_HW_3D_OPEN_HW_NAMESPACE_
_HW_3D_OPEN_RS_NAMESPACE_


//
//for simplicity, never read compressed texture back
struct _D3d_texture2d_helper : _D3d_texture_helper_base<_HW_3D_D3D_ Texture2d_desc> {
public:
	using Metadata_type = _HW_3D_D3D_ Texture2d_desc;
	using Handle_type = _HW_3D_D3D_ ITexture2d;
	using Native_handle_type = ID3D11Texture2D;
	using Subresource_type = _D3d_texture_subresource<Handle_type>;
public:
	static _HW_3D_STD_ vector<_HW_3D_STD_ byte>
		read(
			_HW_3D_IN_ Context_type* context,
			_HW_3D_IN_ Subresource_type src,
			_HW_3D_IN_ const Metadata_type& metadata,
			_HW_3D_IN_ const Range2d& range
		) {
		_HW_3D_STD_ vector<_HW_3D_STD_ byte> res;
		auto[pixels, total_size] = pixel_size(metadata);
		total_size *= samples(metadata);

		auto[success, result] = context->map(
			src.texture,
			static_cast<uint32_t>(src),
			_HW_3D_D3D_ Map::read,
			{});
		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to map texture");

		auto[offset, extent] = range;
		auto size = extent.width * extent.height / pixels * total_size;
		auto row_size = extent.width / pixels * total_size;

		res.resize(size);
		_HW_3D_STD_ byte* p_src = reinterpret_cast<_HW_3D_STD_ byte*>(result.pData) + result.RowPitch * offset.y + offset.x / pixels * total_size;
		_HW_3D_STD_ byte* p_dst = res.data();
		for (uint32_t i = 0; i != extent.height; i++) {
			_HW_3D_STD_ memcpy(p_dst, p_src, row_size);
			p_src += result.RowPitch;
			p_dst += row_size;
		}

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
			_HW_3D_IN_ Offset2d dst_offset,
			_HW_3D_IN_ Subresource_type src,
			_HW_3D_IN_ const Range2d& src_range
		) {
		auto src_box = transfer_to_box(src_range);
		context->copy_subresource_region(
			dst.texture,
			static_cast<uint32_t>(dst),
			{ dst_offset.x, dst_offset.y },
			src.texture,
			static_cast<uint32_t>(src),
			&src_box);
	}

	static Extent2d
		size(
			_HW_3D_IN_ const Metadata_type& metadata,
			_HW_3D_IN_ uint32_t level
		) {
		auto width = get_mipmaps_length(metadata.Width, level);
		auto height = get_mipmaps_length(metadata.Height, level);
		if (width || height)
			return Extent2d((_HW_3D_STD_ max)(1u, width), (_HW_3D_STD_ max)(1u, height));
		else
			return Extent2d( 0, 0 );
	}

	static uint32_t
		data_size(
			_HW_3D_IN_ const Metadata_type& metadata,
			_HW_3D_IN_ uint32_t level
		) {
		auto[pixels, total_size] = pixel_size(metadata);
		auto[width, height] = size(metadata, level);
		return (width + pixels - 1) / pixels * total_size * height;
	}

	static uint32_t
		width(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return metadata.Width;
	}

	static uint32_t
		height(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return metadata.Height;
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

	static uint32_t
		samples(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return metadata.SampleDesc.Count;
	}

	static _HW_3D_STD_ unique_ptr<Handle_type>
		create(
			_HW_3D_IN_ Device_type* device,
			_HW_3D_IN_ const Metadata_type& metadata,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ uint32_t row_pitch,
			_HW_3D_IN_ uint32_t slice_pitch
		) {
		_HW_3D_D3D_ Subresource_data init_data;
		init_data.pSysMem = data;
		init_data.SysMemPitch = row_pitch;
		init_data.SysMemSlicePitch = slice_pitch;
		
		auto[success, texture] = device->create_texture_2d(metadata, &init_data);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to create texture2d");

		return _HW_3D_STD_ move(texture);
	}

	template <Resource_view_type type, typename... Args>
	static _HW_3D_STD_ enable_if_t<_HW_3D_STD_ is_same_v<Handle_type, typename _D3d_resource_view_helper<type>::_Resource_type>, _HW_3D_STD_ unique_ptr<Render_target_view>>
		create_render_target_view(
			_HW_3D_IN_ Device_type* device,
			_HW_3D_IN_ Handle_type* src,
			_HW_3D_IN_ Pixel_format format,
			Args&&... args
		) {
		return _D3d_resource_view::create_render_target_view<type>(device, src, format, _HW_3D_STD_ forward<Args>(args)...);
	}

	template <Resource_view_type type, typename... Args>
	static _HW_3D_STD_ enable_if_t<_HW_3D_STD_ is_same_v<Handle_type, typename _D3d_resource_view_helper<type>::_Resource_type>, _HW_3D_STD_ unique_ptr<Shader_resource_view>>
		create_shader_resource_view(
			_HW_3D_IN_ Device_type* device,
			_HW_3D_IN_ Handle_type* src,
			_HW_3D_IN_ Pixel_format format,
			Args&&... args
		) {
		return _D3d_resource_view::create_shader_resource_view<type>(device, src, format, _HW_3D_STD_ forward<Args>(args)...);
	}

	template <Resource_view_type type, typename... Args>
	static _HW_3D_STD_ enable_if_t<_HW_3D_STD_ is_same_v<Handle_type, typename _D3d_resource_view_helper<type>::_Resource_type>, _HW_3D_STD_ unique_ptr<Depth_stencil_view>>
		create_depth_stencil_view(
			_HW_3D_IN_ Device_type* device,
			_HW_3D_IN_ Handle_type* src,
			_HW_3D_IN_ Pixel_format format,
			Args&&... args
		) {
		return _D3d_resource_view::create_depth_stencil_view<type>(device, src, format, _HW_3D_STD_ forward<Args>(args)...);
	}

	template <Resource_view_type type, typename... Args>
	static _HW_3D_STD_ enable_if_t<_HW_3D_STD_ is_same_v<Handle_type, typename _D3d_resource_view_helper<type>::_Resource_type>, _HW_3D_STD_ unique_ptr<Unordered_access_view>>
		create_unordered_access_view(
			_HW_3D_IN_ Device_type* device,
			_HW_3D_IN_ Handle_type* src,
			_HW_3D_IN_ Pixel_format format,
			Args&&... args
		) {
		return _D3d_resource_view::create_unordered_access_view<type>(device, src, format, _HW_3D_STD_ forward<Args>(args)...);
	}

	static void
		write_via_mapping(
			_HW_3D_IN_ Context_type* context,
			_HW_3D_IN_ Subresource_type dst,
			_HW_3D_IN_ const Metadata_type& metadata,
			_HW_3D_IN_ const Range2d& range,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ uint32_t row_pitch,
			_HW_3D_IN_ Resource_write_hint hint
		) {
		auto map_type = d3d_map_type(hint);

		auto[success, result] = context->map(
			dst.texture,
			static_cast<uint32_t>(dst),
			map_type,
			{});
		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to map texture 2d");
		
		auto[pixels, total_size] = pixel_size(metadata);
		total_size *= samples(metadata);
		
		auto[offset, extent] = range;
		auto row_size = extent.width / pixels * total_size;
		row_pitch = row_pitch == 0 ? row_size : row_pitch;

		_HW_3D_STD_ byte* p_dst = reinterpret_cast<_HW_3D_STD_ byte*>(result.pData) + result.RowPitch * offset.y + offset.x / pixels * total_size;
		const _HW_3D_STD_ byte* p_src = reinterpret_cast<const _HW_3D_STD_ byte*>(data);
		for (uint32_t i = 0; i != extent.height; i++) {
			_HW_3D_STD_ memcpy(p_dst, p_src, row_size);
			p_dst += result.RowPitch;
			p_src += row_pitch;
		}

		context->unmap(dst.texture, static_cast<uint32_t>(dst));
	}

	static void
		write_via_update(
			_HW_3D_IN_ Context_type* context,
			_HW_3D_IN_ Subresource_type dst,
			_HW_3D_IN_ const Range2d& range,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ uint32_t row_pitch
		) {
		auto dst_box = _HW_3D_RS_ transfer_to_box(range);
		context->update_subresource(dst.texture, static_cast<uint32_t>(dst), &dst_box, data, row_pitch, 0);
	}

	static void
		resolve(
			_HW_3D_IN_ Context_type* context,
			_HW_3D_IN_ Subresource_type dst,
			_HW_3D_IN_ Subresource_type src,
			_HW_3D_IN_ Pixel_format format
		) {
		context->resolve_subresource(dst.texture, static_cast<uint32_t>(dst), src.texture, static_cast<uint32_t>(src), format);
	}
};

//
//
template <typename Texture2d_helper> 
class _THardware_texture2d {
public:
	using _My_helper = Texture2d_helper;
	//using _My_helper = _D3d_texture2d_helper;
	using _My_type = _THardware_texture2d<Texture2d_helper>;
	
	using Handle_type = typename _My_helper::Handle_type;
	using Native_handle_type = typename _My_helper::Native_handle_type;
	using Metadata_type = typename _My_helper::Metadata_type;
	using Subresource_type = typename _My_helper::Subresource_type;
public:
	static void
		copy(
			_HW_3D_IN_ _My_type* dst,
			_HW_3D_IN_ _My_type* src
		) {
#ifdef _DEBUG
		if (!_My_helper::is_copyable_as_dst(dst->_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy a no copyable texture");

		if (dst == src)
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy between same texture");

		if (dst->size() != src->size())
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy between different size");

		if (dst->_render_manager != src->_render_manager)
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy between different context");
#endif
		_My_helper::copy(dst->_render_manager->context(), dst->handle(), src->handle());
	}

	static void
		copy(
			_HW_3D_IN_ _My_type* dst,
			_HW_3D_IN_ uint32_t dst_level,
			_HW_3D_IN_ uint32_t dst_array_index,
			_HW_3D_IN_ Offset2d offset,
			_HW_3D_IN_ _My_type* src,
			_HW_3D_IN_ uint32_t src_level,
			_HW_3D_IN_ uint32_t src_array_index,
			_HW_3D_IN_ const Range2d& src_range
		) {
#ifdef _DEBUG
		if (!_My_helper::is_copyable_as_dst(dst->_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy a no copyable texture");

		if (dst == src && dst_level == src_level && dst_array_index == src_array_index)
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy between same texture");

		if (dst->_render_manager != src->_render_manager)
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to copy between different context");
#endif
		_My_helper::copy(
			dst->_render_manager->context(),
			Subresource_type(dst->handle(), dst_level, dst_array_index),
			offset,
			Subresource_type(src->handle(), src_level, src_array_index),
			src_range);
	}

	static void
		resolve(
			_HW_3D_IN_ _My_type* dst,
			_HW_3D_IN_ uint32_t dst_level,
			_HW_3D_IN_ uint32_t dst_array_index,
			_HW_3D_IN_ _My_type* src,
			_HW_3D_IN_ uint32_t src_level,
			_HW_3D_IN_ uint32_t src_array_index,
			_HW_3D_IN_ Pixel_format format
		) {
#ifdef _DEBUG
		if (dst->_render_manager != src->_render_manager)
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to resolve between different context");
#endif
		_My_helper::resolve(
			dst->_render_manager->context(),
			Subresource_type(dst->handle(), dst_level, dst_array_index),
			Subresource_type(src->handle(), src_level, src_array_index),
			format);
	}

public:
	_THardware_texture2d(
		_HW_3D_IN_ const Metadata_type& metadata,
		_HW_3D_IN_ const void* initial_data,
		_HW_3D_IN_ uint32_t row_pitch,
		_HW_3D_IN_ uint32_t slice_pitch,
		_HW_3D_IN_ Render_manager* render_manager
	) : _metadata(metadata)
		, _render_manager(render_manager) {
		_texture = _My_helper::create(_render_manager->device(), _metadata, initial_data, row_pitch, slice_pitch);
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
			_HW_3D_IN_ const Range2d& range
		) {
#ifdef _DEBUG
		if (!_My_helper::is_mappable_as_src(_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to read form no-readable texture");
#endif
		return _My_helper::read(_render_manager->context(), Subresource_type(_texture.get(), level, array_index), _metadata, range);
	}

	void
		write(
			_HW_3D_IN_ uint32_t level,
			_HW_3D_IN_ uint32_t array_index,
			_HW_3D_IN_ const Range2d& range,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ uint32_t row_pitch
		) {
#ifdef _DEBUG
		if (!_My_helper::is_updatable_as_dst(_metadata))
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "should update via mapped pointer");
#endif
		_My_helper::write_via_update(
			_render_manager->context(),
			Subresource_type(_texture.get(), level, array_index),
			range,
			data,
			row_pitch);
	}

	void
		write_via_mapping(
			_HW_3D_IN_ uint32_t level,
			_HW_3D_IN_ uint32_t array_index,
			_HW_3D_IN_ const Range2d& range,
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

	Extent2d
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
		height() const {
		return _My_helper::height(_metadata);
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

	uint32_t
		samples() const {
		return _My_helper::samples(_metadata);
	}

	template <Resource_view_type type, typename... Args>
	auto create_render_target_view(
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ Args&&... args
		) {
		return _My_helper::template create_render_target_view<type>(_render_manager->device(), _texture.get(), format, _HW_3D_STD_ forward<Args>(args)...);
	}

	template <Resource_view_type type, typename... Args>
	auto create_shader_resource_view(
		_HW_3D_IN_ Pixel_format format,
		_HW_3D_IN_ Args&&... args
	) {
		return _My_helper::template create_shader_resource_view<type>(_render_manager->device(), _texture.get(), format, _HW_3D_STD_ forward<Args>(args)...);
	}

	template <Resource_view_type type, typename... Args>
	auto create_depth_stencil_view(
		_HW_3D_IN_ Pixel_format format,
		_HW_3D_IN_ Args&&... args
	) {
		return _My_helper::template create_depth_stencil_view<type>(_render_manager->device(), _texture.get(), format, _HW_3D_STD_ forward<Args>(args)...);
	}

	template <Resource_view_type type, typename... Args>
	auto create_unordered_access_view(
		_HW_3D_IN_ Pixel_format format,
		_HW_3D_IN_ Args&&... args
	) {
		return _My_helper::template create_unordered_access_view<type>(_render_manager->device(), _texture.get(), format, _HW_3D_STD_ forward<Args>(args)...);
	}

private:
	_HW_3D_STD_ unique_ptr<Handle_type> _texture;
	Metadata_type _metadata;
	Render_manager* const _render_manager;
};

//
//
template <typename Texture2d_helper, typename _My_base = typename Texture2d_helper::Metadata_type>
struct _THardware_texture2d_builder : _My_base {
	using Hardware_texture2d_type = _THardware_texture2d<Texture2d_helper>;

	_HW_3D_STD_ unique_ptr<Hardware_texture2d_type>
		create(
			_HW_3D_IN_ const void* pdata,
			_HW_3D_IN_ uint32_t row_pitch,
			_HW_3D_IN_ uint32_t slice_pitch,
			_HW_3D_IN_ Render_manager* render_manager = nullptr
		) {
		render_manager = render_manager == nullptr ? Render_manager::current_render_manager() : render_manager;

		if (render_manager == nullptr)
			_HW_3D_THROW_EXCEPTION_(Error_type::logic, "try to create texture without hardware");

		return _HW_3D_STD_ make_unique<Hardware_texture2d_type>(*this, pdata, row_pitch, slice_pitch, render_manager);
	}
};

//
//
using Hardware_texture2d = _THardware_texture2d<_D3d_texture2d_helper>;
using Hardware_texture2d_builder = _THardware_texture2d_builder<_D3d_texture2d_helper>;



_HW_3D_CLOSE_RS_NAMESPACE_
_HW_3D_CLOSE_HW_NAMESPACE_

