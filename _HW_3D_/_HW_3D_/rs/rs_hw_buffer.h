#pragma once

#include "rs_fwd.h"
#include "rs_utils.hpp"
#include "rs_hw_resource.hpp"
#include "rs_render_manager.h"

_HW_3D_OPEN_HW_NAMESPACE_

_HW_3D_OPEN_RS_NAMESPACE_

//
//
class Hardware_buffer : Hardware_resource {
public:
	using Handle_type = _HW_3D_D3D_ IBuffer;
	using Native_handle_type = ID3D11Buffer;
	using Metadata = _HW_3D_D3D_ Buffer_desc;
public:
	static _HW_3D_STD_ vector<_HW_3D_STD_ byte>
		read(
			_HW_3D_IN_ Hardware_buffer* buffer, 
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ uint32_t size
		);

	static void
		write(
			_HW_3D_IN_ Hardware_buffer* buffer,
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ uint32_t size,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ bool discard = false
		);

	static void
		copy(
			_HW_3D_IN_ Hardware_buffer* dst,
			_HW_3D_IN_ uint32_t dst_offset,
			_HW_3D_IN_ Hardware_buffer* src,
			_HW_3D_IN_ uint32_t src_offset,
			_HW_3D_IN_ uint32_t size
		);

	static void
		copy(
			_HW_3D_IN_ Hardware_buffer* dst,
			_HW_3D_IN_ Hardware_buffer* src
		);
public:
	Hardware_buffer(
		_HW_3D_IN_ const Metadata& desc,
		_HW_3D_IN_ _HW_3D_D3D_ Subresource_data* data,
		_HW_3D_IN_ Render_manager* render_manager
	) : _desc(desc)
		, _render_manager(render_manager) {
		auto[success, buffer] = _render_manager->device()->create_buffer(_desc, data);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to create buffer");

		_buffer = _HW_3D_STD_ move(buffer);
	}

	Handle_type* 
		handle() const;

	Native_handle_type* 
		native_handle() const;

	uint32_t 
		size() const;

	uint32_t 
		stride() const;

	Resource_usage 
		usage() const;

	Resource_cpu_access_flag
		cpu_access_flag() const;

	Resource_misc_flag 
		misc_flag() const;

	Resource_bind_flag 
		bind_flag() const;

	_HW_3D_STD_ vector<_HW_3D_STD_ byte>
		read(
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ uint32_t size
		);

	void
		write(
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ uint32_t size,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ bool disscard
		);

	void
		copy(
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ Hardware_buffer* src_buffer,
			_HW_3D_IN_ uint32_t src_offset,
			_HW_3D_IN_ uint32_t size
		);

	void
		copy(
			_HW_3D_IN_ Hardware_buffer* src_buffer
		);

private:
	Hardware_buffer(const Hardware_buffer&) = delete;
	Hardware_buffer& operator=(const Hardware_buffer&) = delete;
	Hardware_buffer(Hardware_buffer&&) = delete;
	Hardware_buffer& operator=(Hardware_buffer&&) = delete;

private:
	_HW_3D_STD_ unique_ptr<Handle_type> _buffer;
	Metadata _desc;
	Render_manager* const _render_manager;
};

class Hardware_buffer_builder {
public:
	Hardware_buffer_builder() {}

	~Hardware_buffer_builder() {}

	Hardware_buffer_builder& 
		set_buffer_size(
			_HW_3D_IN_ uint32_t size
		);

	Hardware_buffer_builder&
		set_resource_usage(
			_HW_3D_IN_ Resource_usage usage
		);

	Hardware_buffer_builder&
		set_bind_flag(
			_HW_3D_IN_ Resource_bind_flag flags
		);

	Hardware_buffer_builder&
		set_cpu_access_flag(
			_HW_3D_IN_ Resource_cpu_access_flag flags
		);

	Hardware_buffer_builder&
		set_misc_flag(
			_HW_3D_IN_ Resource_misc_flag flags
		);

	Hardware_buffer_builder&
		set_structure_stride(
			_HW_3D_IN_ uint32_t stride
		);

	Hardware_buffer_builder&
		set_buffer_initial_data(
			_HW_3D_IN_ const void* sys_meme,
			_HW_3D_IN_ uint32_t pitch = 0,
			_HW_3D_IN_ uint32_t slice_pitch = 0
		);

	_HW_3D_STD_ unique_ptr<Hardware_buffer>
		create(
			_HW_3D_IN_ Render_manager* render_manager = nullptr
		) {
		render_manager = render_manager == nullptr ? Render_manager::current_render_manager() : render_manager;
		if (render_manager == nullptr)
			_HW_3D_TRHOW_EXCEPTION_(Error_type::logic, "try to create buffer without hardware");
		return _HW_3D_STD_ make_unique<Hardware_buffer>(_desc, &_initial_data, render_manager);
	}
private:
	Metadata_t<Hardware_buffer> _desc;
	_HW_3D_D3D_ Subresource_data _initial_data;
};

//
//
_HW_3D_INLINE_FUNCTION_ Hardware_buffer::Handle_type* 
Hardware_buffer::handle() const {
	return _buffer.get();
}

_HW_3D_INLINE_FUNCTION_ Hardware_buffer::Native_handle_type* 
Hardware_buffer::native_handle() const {
	return _buffer->get();
}

_HW_3D_INLINE_FUNCTION_ uint32_t 
Hardware_buffer::size() const {
	return _desc.ByteWidth;
}

_HW_3D_INLINE_FUNCTION_ uint32_t 
Hardware_buffer::stride() const {
	return _desc.StructureByteStride;
}

_HW_3D_INLINE_FUNCTION_ Resource_usage 
Hardware_buffer::usage() const {
	return _desc.Usage;
}

_HW_3D_INLINE_FUNCTION_ Resource_cpu_access_flag 
Hardware_buffer::cpu_access_flag() const {
	return _desc.CPUAccessFlags;
}

_HW_3D_INLINE_FUNCTION_ Resource_misc_flag
Hardware_buffer::misc_flag() const {
	return _desc.MiscFlags;
}

_HW_3D_INLINE_FUNCTION_ Resource_bind_flag 
Hardware_buffer::bind_flag() const {
	return _desc.BindFlags;
}

_HW_3D_INLINE_FUNCTION_ _HW_3D_STD_ vector<_HW_3D_STD_ byte>
Hardware_buffer::read(
	_HW_3D_IN_ uint32_t offset,
	_HW_3D_IN_ uint32_t size
) {
	return read(this, offset, size);
}

_HW_3D_INLINE_FUNCTION_ void
Hardware_buffer::write(
	_HW_3D_IN_ uint32_t offset,
	_HW_3D_IN_ uint32_t size,
	_HW_3D_IN_ const void* data,
	_HW_3D_IN_ bool disscard
) {
	write(this, offset, size, data, disscard);
}

_HW_3D_INLINE_FUNCTION_ void
Hardware_buffer::copy(
	_HW_3D_IN_ uint32_t offset,
	_HW_3D_IN_ Hardware_buffer* src_buffer,
	_HW_3D_IN_ uint32_t src_offset,
	_HW_3D_IN_ uint32_t size
) {
	copy(this, offset, src_buffer, src_offset, size);
}

_HW_3D_INLINE_FUNCTION_ void
Hardware_buffer::copy(
	_HW_3D_IN_ Hardware_buffer* src_buffer
) {
	copy(this, src_buffer);
}


_HW_3D_INLINE_FUNCTION_ Hardware_buffer_builder& 
Hardware_buffer_builder::set_buffer_size(
	_HW_3D_IN_ uint32_t size
) {
	_desc.ByteWidth = size;
	return *this;
}

_HW_3D_INLINE_FUNCTION_	Hardware_buffer_builder&
Hardware_buffer_builder::set_resource_usage(
	_HW_3D_IN_ Resource_usage usage
) {
	_desc.Usage = usage;
	return *this;
}

_HW_3D_INLINE_FUNCTION_ Hardware_buffer_builder&
Hardware_buffer_builder::set_bind_flag(
	_HW_3D_IN_ Resource_bind_flag flags
) {
	_desc.BindFlags = flags;
	return *this;
}

_HW_3D_INLINE_FUNCTION_ Hardware_buffer_builder&
Hardware_buffer_builder::set_cpu_access_flag(
	_HW_3D_IN_ Resource_cpu_access_flag flags
) {
	_desc.CPUAccessFlags = flags;
	return *this;
}

_HW_3D_INLINE_FUNCTION_ Hardware_buffer_builder&
Hardware_buffer_builder::set_misc_flag(
	_HW_3D_IN_ Resource_misc_flag flags
) {
	_desc.MiscFlags = flags;
	return *this;
}

_HW_3D_INLINE_FUNCTION_ Hardware_buffer_builder&
Hardware_buffer_builder::set_structure_stride(
	_HW_3D_IN_ uint32_t stride
) {
	_desc.StructureByteStride = stride;
	return *this;
}

_HW_3D_INLINE_FUNCTION_ Hardware_buffer_builder&
Hardware_buffer_builder::set_buffer_initial_data(
	_HW_3D_IN_ const void* sys_mem,
	_HW_3D_IN_ uint32_t pitch,
	_HW_3D_IN_ uint32_t slice_pitch
) {
	_initial_data.pSysMem = sys_mem;
	_initial_data.SysMemPitch = pitch;
	_initial_data.SysMemSlicePitch = slice_pitch;

	return *this;
}

_HW_3D_CLOSE_RS_NAMESPACE_

_HW_3D_CLOSE_HW_NAMESPACE_