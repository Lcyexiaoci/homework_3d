#pragma once

#include "rs_hw_resource.hpp"
#include "rs_hw_resource_view.hpp"

_HW_3D_OPEN_HW_NAMESPACE_
_HW_3D_OPEN_RS_NAMESPACE_

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

	static uint32_t
		size(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return metadata.ByteWidth;
	}

	static uint32_t
		stride(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return metadata.StructureByteStride;
	}

	static _HW_3D_STD_ unique_ptr<Handle_type>
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

	template <Resource_view_type type, typename... Args>
	static _HW_3D_STD_ enable_if_t<_HW_3D_STD_ is_same_v<Handle_type, typename _D3d_resource_view_helper<type>::_Resource_type>, _HW_3D_STD_ unique_ptr<Render_target_view>>
		create_render_target_view(
			_HW_3D_IN_ Device_type* device,
			_HW_3D_IN_ Handle_type* src,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ Args&&... args
		) {
		return _D3d_resource_view::create_render_target_view<type>(device, src, format, _HW_3D_STD_ forward<Args>(args)...);
	}

	template <Resource_view_type type, typename... Args>
	static _HW_3D_STD_ enable_if_t<_HW_3D_STD_ is_same_v<Handle_type, typename _D3d_resource_view_helper<type>::_Resource_type>, _HW_3D_STD_ unique_ptr<Shader_resource_view>>
		create_shader_resource_view(
			_HW_3D_IN_ Device_type* device,
			_HW_3D_IN_ Handle_type* src,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ Args&&... args
		) {
		return _D3d_resource_view::create_shader_resource_view<type>(device, src, format, _HW_3D_STD_ forward<Args>(args)...);
	}

	template <Resource_view_type type, typename... Args>
	static _HW_3D_STD_ enable_if_t<_HW_3D_STD_ is_same_v<Handle_type, typename _D3d_resource_view_helper<type>::_Resource_type>, _HW_3D_STD_ unique_ptr<Depth_stencil_view>>
		create_depth_stencil_view(
			_HW_3D_IN_ Device_type* device,
			_HW_3D_IN_ Handle_type* src,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ Args&&... args
		) {
		return _D3d_resource_view::create_depth_stencil_view<type>(device, src, format, _HW_3D_STD_ forward<Args>(args)...);
	}

	template <Resource_view_type type, typename... Args>
	static _HW_3D_STD_ enable_if_t<_HW_3D_STD_ is_same_v<Handle_type, typename _D3d_resource_view_helper<type>::_Resource_type>, _HW_3D_STD_ unique_ptr<Unordered_access_view>>
		create_unordered_access_view(
			_HW_3D_IN_ Device_type* device,
			_HW_3D_IN_ Handle_type* src,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ Args&&... args
		) {
		return _D3d_resource_view::create_unordered_access_view<type>(device, src, format, _HW_3D_STD_ forward<Args>(args)...);
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
	
	//using _My_helper = _D3d_buffer_helper;
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

	Handle_type* handle() const {
		return _buffer.get();
	}

	Native_handle_type* native_handle() const {
		return _buffer->get();
	}

	uint32_t size() const {
		return _My_helper::size(_metadata);
	}

	uint32_t stride() const {
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

	void write (
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

	void write_via_mapping(
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

	void copy(
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

	void copy(
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

	template <Resource_view_type type, typename... Args>
	auto create_render_target_view(
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ Args&&... args
		) {
		return _My_helper::template create_render_target_view<type>(_render_manager->device(), _buffer.get(), format, _HW_3D_STD_ forward<Args>(args)...);
	}

	template <Resource_view_type type, typename... Args>
	auto create_shader_resource_view(
		_HW_3D_IN_ Pixel_format format,
		_HW_3D_IN_ Args&&... args
	) {
		return _My_helper::template create_shader_resource_view<type>(_render_manager->device(), _buffer.get(), format, _HW_3D_STD_ forward<Args>(args)...);
	}

	template <Resource_view_type type, typename... Args>
	auto create_depth_stencil_view(
		_HW_3D_IN_ Pixel_format format,
		_HW_3D_IN_ Args&&... args
	) {
		return _My_helper::template create_depth_stencil_view<type>(_render_manager->device(), _buffer.get(), format, _HW_3D_STD_ forward<Args>(args)...);
	}

	template <Resource_view_type type, typename... Args>
	auto create_unordered_access_view(
		_HW_3D_IN_ Pixel_format format,
		_HW_3D_IN_ Args&&... args
	) {
		return _My_helper::template create_unordered_access_view<type>(_render_manager->device(), _buffer.get(), format, _HW_3D_STD_ forward<Args>(args)...);
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


_HW_3D_CLOSE_RS_NAMESPACE_
_HW_3D_CLOSE_HW_NAMESPACE_