#include "rs_hw_buffer.h"

namespace {
	//
	//
	_HW_3D_INLINE_FUNCTION_ _HW_3D_RS_ Resource_info 
		transfer(
			_HW_3D_IN_ const _HW_3D_RS_ Hardware_buffer::Metadata& metadata
		) {
		return _HW_3D_RS_ Resource_info(metadata.Usage, metadata.BindFlags, metadata.CPUAccessFlags, metadata.MiscFlags);
	}

	//
	//
	void
		write_buffer_via_map(
			_HW_3D_IN_ _HW_3D_D3D_ IDevice_context* context,
			_HW_3D_IN_ _HW_3D_D3D_ IBuffer* buffer,
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ uint32_t size,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ _HW_3D_D3D_ Map map_type
		) {
		auto[success, result] = context->map(buffer, 0, map_type, {});
		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to map buffer");

		_HW_3D_STD_ memcpy(reinterpret_cast<_HW_3D_STD_ byte*>(result.pData) + offset, data, size);

		context->unmap(buffer, 0);
	}

	//
	//
	void 
		write_buffer_via_update(
			_HW_3D_IN_ _HW_3D_D3D_ IDevice_context* context,
			_HW_3D_IN_ _HW_3D_D3D_ IBuffer* buffer,
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ uint32_t size,
			_HW_3D_IN_ const void* data
		) {
		_HW_3D_RS_ Box dst_box = _HW_3D_RS_ transfer_to_box(_HW_3D_RS_ Offset1d(offset), _HW_3D_RS_ Extent1d(size));
		context->update_subresource(buffer, 0, &dst_box, data, 0, 0);
	}
}
//
//
_HW_3D_STD_ vector<_HW_3D_STD_ byte> 
_HW_3D_RS_ Hardware_buffer::read(
	_HW_3D_IN_ Hardware_buffer* buffer,
	_HW_3D_IN_ uint32_t offset,
	_HW_3D_IN_ uint32_t size
) {
	_HW_3D_STD_ vector<_HW_3D_STD_ byte> res;
	
#ifdef _DEBUG
	auto info = transfer(buffer->_desc);
	
	if (!is_mappable_as_src(info))
		_HW_3D_TRHOW_EXCEPTION_(Error_type::d3d11, "try to read from no-readable buffer");

	if (offset >= buffer->size())
		_HW_3D_TRHOW_EXCEPTION_(Error_type::logic, "offset size is larger that whole buffer size");
#endif
	auto context = buffer->_render_manager->context();

	auto[success, result] = context->map(buffer->handle(), 0, _HW_3D_D3D_ Map::read, {});
	_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to map buffer");

	res.resize((_HW_3D_STD_ min)(buffer->size() - offset, size));
	_HW_3D_STD_ memcpy(res.data(), reinterpret_cast<_HW_3D_STD_ byte*>(result.pData) + offset, res.size());

	context->unmap(buffer->handle(), 0);

	return res;
}

//
//
void 
_HW_3D_RS_ Hardware_buffer::write(
	_HW_3D_IN_ Hardware_buffer* buffer,
	_HW_3D_IN_ uint32_t offset,
	_HW_3D_IN_ uint32_t size,
	_HW_3D_IN_ const void* data,
	_HW_3D_IN_ bool discard
) {
	auto info = transfer(buffer->_desc);
#ifdef _DEBUG
	if (!is_mappable_as_dst(info) && !is_updatable_as_dst(info))
		_HW_3D_TRHOW_EXCEPTION_(Error_type::d3d11, "try to write to no-writable buffer");

	if (data == nullptr || size == 0)
		_HW_3D_TRHOW_EXCEPTION_(Error_type::logic, "try to write nothing to buffer");

	if (offset >= buffer->size())
		_HW_3D_TRHOW_EXCEPTION_(Error_type::logic, "offset size if larger than whole buffer size");
#endif
	auto context = buffer->_render_manager->context();

	size = (_HW_3D_STD_ min)(size, buffer->size() - offset);
	
	if (is_mappable_as_dst(info)) {
		_HW_3D_D3D_ Map map_type = discard ? _HW_3D_D3D_ Map::write_discard : _HW_3D_D3D_ Map::write;
		write_buffer_via_map(context, buffer->handle(), offset, size, data, map_type);
	}
	else {
		write_buffer_via_update(context, buffer->handle(), offset, size, data);
	}
}

//
//
void 
_HW_3D_RS_ Hardware_buffer::copy(
	_HW_3D_IN_ Hardware_buffer* dst,
	_HW_3D_IN_ Hardware_buffer* src
) {
#ifdef _DEBUG
	auto info = transfer(dst->_desc);

	if (!is_copyable_as_dst(info))
		_HW_3D_TRHOW_EXCEPTION_(Error_type::d3d11, "try to copy to no-copyable buffer");

	if (src == nullptr)
		_HW_3D_TRHOW_EXCEPTION_(Error_type::logic, "try to copy from an empty buffer");

	if (src == dst)
		_HW_3D_TRHOW_EXCEPTION_(Error_type::logic, "try to copy between the same buffer");

	if (src->size() != dst->size())
		_HW_3D_TRHOW_EXCEPTION_(Error_type::logic, "try to copy between different size buffer");

	if (dst->_render_manager != src->_render_manager)
		_HW_3D_TRHOW_EXCEPTION_(Error_type::logic, "try to copy between different hardware");
#endif

	auto context = dst->_render_manager->context();
	
	context->copy_resource(dst->handle(), src->handle());
}

//
//
void 
_HW_3D_RS_ Hardware_buffer::copy(
	_HW_3D_IN_ Hardware_buffer* dst,
	_HW_3D_IN_ uint32_t dst_offset,
	_HW_3D_IN_ Hardware_buffer* src,
	_HW_3D_IN_ uint32_t src_offset,
	_HW_3D_IN_ uint32_t size
) {
#ifdef _DEBUG
	auto info = transfer(dst->_desc);

	if (!is_copyable_as_dst(info))
		_HW_3D_TRHOW_EXCEPTION_(Error_type::d3d11, "try to copy to no-copyable buffer"); 

	if (src == nullptr)
		_HW_3D_TRHOW_EXCEPTION_(Error_type::logic, "try to copy from an empty buffer");

	if (src == dst)
		_HW_3D_TRHOW_EXCEPTION_(Error_type::logic, "try to copy between the same buffer");

	if (dst->_render_manager != src->_render_manager)
		_HW_3D_TRHOW_EXCEPTION_(Error_type::logic, "try to copy between different hardware");

	if (src_offset + size > src->size() || dst_offset + size >= dst->size())
		_HW_3D_TRHOW_EXCEPTION_(Error_type::logic, "invalid arguments");
#endif

	auto context = dst->_render_manager->context();
	auto src_box = transfer_to_box(Offset1d(src_offset), Extent1d(size));

	context->copy_subresource_region(dst->handle(), 0, { dst_offset, 0, 0 }, src->handle(), 0, &src_box);
}


