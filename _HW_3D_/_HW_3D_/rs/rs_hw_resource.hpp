#pragma once

#include "rs_fwd.h"
#include "rs_utils.hpp"

_HW_3D_OPEN_HW_NAMESPACE_

_HW_3D_OPEN_RS_NAMESPACE_

//
//
struct Subresource {
	uint32_t mip_slice{ 0 };
	uint32_t array_slice{ 0 };
	uint32_t mip_levels{ 0 };

	explicit operator uint32_t() const {
		return _HW_3D_D3D_ calc_subresource(mip_slice, array_slice, mip_levels);
	}
};

//
//
struct Resource_info {
	Resource_usage usage;
	Resource_bind_flag bind_flag;
	Resource_cpu_access_flag cpu_access_flag;
	Resource_misc_flag misc_flag;

	Resource_info(
		Resource_usage _usage,
		Resource_bind_flag _bind_flag,
		Resource_cpu_access_flag _cpu_access_flag,
		Resource_misc_flag _misc_flag
	) : usage(_usage)
		, bind_flag(_bind_flag)
		, cpu_access_flag(_cpu_access_flag)
		, misc_flag(_misc_flag) {
	}

};

//
//d3d 11.0 specific
struct Hardware_resource {
public:
	//for mapping(cpu/gpu)
	static bool
		is_mappable_as_src(
			_HW_3D_IN_ const Resource_info& info
		) {
		return ((info.cpu_access_flag & Resource_cpu_access_flag::bit_type::read) != Resource_cpu_access_flag{})
			&& (info.usage == Resource_usage::staging);
	}

	static bool 
		is_mappable_as_dst(
			_HW_3D_IN_ const Resource_info& info
		) {
		return ((info.cpu_access_flag & Resource_cpu_access_flag::bit_type::write) != Resource_cpu_access_flag{})
			&& (info.usage == Resource_usage::staging || info.usage == Resource_usage::dynamic);
	}

	static bool
		is_mappable(
			_HW_3D_IN_ const Resource_info& info
		) {
		return is_mappable_as_src(info)
			&& is_mappable_as_dst(info);
	}

	static bool
		is_mappable_as_dst_and_discard(
			_HW_3D_IN_ const Resource_info& info
		) {
		return ((info.cpu_access_flag & Resource_cpu_access_flag::bit_type::write) != Resource_cpu_access_flag{})
			&& (info.usage == Resource_usage::dynamic);
	}

	static bool
		is_mappable_as_dst_and_no_overwrite(
			_HW_3D_IN_ const Resource_info& info
		) {
		return ((info.cpu_access_flag & Resource_cpu_access_flag::bit_type::write) != Resource_cpu_access_flag{})
			&& (info.usage == Resource_usage::dynamic)
			&& ((info.bind_flag & Resource_bind_flag::bit_type::vertex_buffer) != Resource_bind_flag{} ||
			(info.bind_flag & Resource_bind_flag::bit_type::index_buffer) != Resource_bind_flag{});
	}

	static bool
		is_updatable_as_dst(
			_HW_3D_IN_ const Resource_info& info
		) {
		return !((info.usage == Resource_usage::_immutable || info.usage == Resource_usage::dynamic)
			|| (info.bind_flag & Resource_bind_flag::bit_type::depth_stencil) != Resource_bind_flag{});
	}

	//for copy(gpu/gpu)
	static bool
		is_copyable_as_dst(
			_HW_3D_IN_ const Resource_info& info
		) {
		return (info.usage == Resource_usage::_default || info.usage == Resource_usage::staging);
	}
};




_HW_3D_CLOSE_RS_NAMESPACE_

_HW_3D_CLOSE_HW_NAMESPACE_
