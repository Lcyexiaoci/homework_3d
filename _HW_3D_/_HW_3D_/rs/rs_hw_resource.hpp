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

_HW_3D_CLOSE_RS_NAMESPACE_

_HW_3D_CLOSE_HW_NAMESPACE_
