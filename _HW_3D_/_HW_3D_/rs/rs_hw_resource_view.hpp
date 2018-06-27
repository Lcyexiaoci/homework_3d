#pragma once

#include "rs_fwd.h"
#include "rs_utils.hpp"

_HW_3D_OPEN_HW_NAMESPACE_
_HW_3D_OPEN_RS_NAMESPACE_

//
//
enum class Resource_view_type {
	_buffer,
	_buffer_ex,
	_texture1d,
	_texture1d_array,
	_texture2d,
	_texture2d_array,
	_texture2dms,
	_texture2dms_array,
	_texture3d,
	_texture_cube,
	_texture_cube_array
};

//
//
struct Render_target_view_tag {};
struct Depth_stencil_view_tag {};
struct Shader_resource_view_tag {};
struct Unordered_access_view_tag {};

//
struct _D3d_view_helper_base {
	using _Format_type = Pixel_format;
	using _Resource_type = _HW_3D_D3D_ IResource;
	
	using _Render_target_view = _HW_3D_D3D_ IRender_target_view;
	using _Depth_stencil_view = _HW_3D_D3D_ IDepth_stencil_view;
	using _Shader_resource_view = _HW_3D_D3D_ IShader_resource_view;
	using _Unordered_access_view = _HW_3D_D3D_ IUnordered_access_view;
	
	using _Native_render_target_view = ID3D11RenderTargetView;
	using _Native_depth_stencil_view = ID3D11DepthStencilView;
	using _Native_shader_resource_view = ID3D11ShaderResourceView;
	using _Native_unordered_access_view = ID3D11UnorderedAccessView;

	using _Render_target_view_desc = _HW_3D_D3D_ Render_target_view_desc;
	using _Depth_stencil_view_desc = _HW_3D_D3D_ Depth_stencil_view_desc;
	using _Shader_resource_view_desc = _HW_3D_D3D_ Shader_resource_view_desc;
	using _Unordered_access_view_desc = _HW_3D_D3D_ Unordered_access_view_desc;

	static _HW_3D_STD_ unique_ptr<_Render_target_view> 
		_create(
			_HW_3D_IN_ Device* device, 
			_HW_3D_IN_ _Resource_type* resource, 
			_HW_3D_IN_ _Render_target_view_desc& desc
		) {
		auto[success, result] = device->create_render_target_view(resource, &desc);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to create a render target view"); 

		return _HW_3D_STD_ move(result);
	}

	static _HW_3D_STD_ unique_ptr<_Depth_stencil_view> 
		_create(
			_HW_3D_IN_ Device* device,
			_HW_3D_IN_ _Resource_type* resource, 
			_HW_3D_IN_ _Depth_stencil_view_desc& desc
		) {
		auto[success, result] = device->create_depth_stencil_view(resource, &desc);
		
		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to create a depth stencil view");

		return _HW_3D_STD_ move(result);
	}

	static _HW_3D_STD_ unique_ptr<_Shader_resource_view> 
		_create(
			_HW_3D_IN_ Device* device, 
			_HW_3D_IN_ _Resource_type* resource, 
			_HW_3D_IN_ _Shader_resource_view_desc& desc
		) {
		auto[success, result] = device->create_shader_resource_view(resource, &desc);
		
		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to create shader resource view");

		return _HW_3D_STD_ move(result);
	}

	static _HW_3D_STD_ unique_ptr<_Unordered_access_view> 
		_create(
			_HW_3D_IN_ Device* device, 
			_HW_3D_IN_ _Resource_type* resource,
			_HW_3D_IN_ _Unordered_access_view_desc& desc
		) {
		auto[success, result] = device->create_unordered_access_view(resource, &desc);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to create unordered access view");

		return _HW_3D_STD_ move(result);
	}
};

//
//
template <Resource_view_type> class _D3d_resource_view_helper;

//
template <>
class _D3d_resource_view_helper<Resource_view_type::_buffer> : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ IBuffer;
	using _Rtv_desc = _HW_3D_D3D_ Buffer_rtv;
	using _Uav_desc = _HW_3D_D3D_ Buffer_uav;
	using _Srv_desc = _HW_3D_D3D_ Buffer_srv;


	static _Render_target_view_desc 
		_get_desc(
			_HW_3D_IN_ Render_target_view_tag,
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ uint32_t size
		) {
		_Render_target_view_desc res;
		
		_Rtv_desc desc;
		desc.FirstElement = offset;
		desc.NumElements = size;

		res.Format = format;
		res.Buffer = desc;
		return res;
	}

	static _Unordered_access_view_desc 
		_get_desc(
			_HW_3D_IN_ Unordered_access_view_tag,
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ uint32_t size,
			_HW_3D_IN_ _HW_3D_D3D_ Buffer_uav_flag flags
		) {
		_Unordered_access_view_desc res;

		_Uav_desc desc;
		desc.FirstElement = offset;
		desc.NumElements = size;
		desc.Flags = flags;

		res.Format = format;
		res.Buffer = desc;
		return res;
	}

	static _Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Shader_resource_view_tag,
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ uint32_t size
		) {
		_Shader_resource_view_desc res;

		_Srv_desc desc;
		desc.FirstElement = offset;
		desc.NumElements = size;

		res.Format = format;
		res.Buffer = desc;
		return res;
	}

	
};

//
template <>
class _D3d_resource_view_helper<Resource_view_type::_buffer_ex> : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ IBuffer;
	using _Srv_desc = _HW_3D_D3D_ Buffer_ex_srv;
	using _Uav_desc = _HW_3D_D3D_ Buffer_uav;

	static _Shader_resource_view_desc
		_get_desc(
			_HW_3D_IN_ Shader_resource_view_tag,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ uint32_t size,
			_HW_3D_IN_ _HW_3D_D3D_ Buffer_ex_srv_flag flags
		) {
		_Shader_resource_view_desc res;

		_Srv_desc desc;
		desc.FirstElement = offset;
		desc.NumElements = size;
		desc.Flags = flags;

		res.Format = format;
		res.BufferEx = desc;
		return res;
	}

	static _Unordered_access_view_desc
		_get_desc(
			_HW_3D_IN_ Unordered_access_view_tag,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ uint32_t offset,
			_HW_3D_IN_ uint32_t size,
			_HW_3D_IN_ _HW_3D_D3D_ Buffer_uav_flag flags
		) {
		_Unordered_access_view_desc res;
		_Uav_desc desc;
		desc.FirstElement = offset;
		desc.NumElements = size;
		desc.Flags = flags;

		res.Format = format;
		res.Buffer = desc;
		return res;
	}
};

//
template <>
class _D3d_resource_view_helper<Resource_view_type::_texture1d>  : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture1d;
	using _Rtv_desc = _HW_3D_D3D_ Tex1d_rtv;
	using _Uav_desc = _HW_3D_D3D_ Tex1d_uav;
	using _Srv_desc = _HW_3D_D3D_ Tex1d_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex1d_dsv;

	static _Render_target_view_desc 
		_get_desc(
			_HW_3D_IN_ Render_target_view_tag,
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ uint32_t mip_slice
		) {
		_Render_target_view_desc res;

		_Rtv_desc desc;
		desc.MipSlice = mip_slice;

		res.Format = format;
		res.Texture1D = desc;
		return res;
	}

	static _Unordered_access_view_desc 
		_get_desc(
			_HW_3D_IN_ Unordered_access_view_tag,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ uint32_t mip_slice
		) {
		_Unordered_access_view_desc res;
			
		_Uav_desc desc;
		desc.MipSlice = mip_slice;

		res.Format = format;
		res.Texture1D = desc;
		return res;
	}

	static _Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Shader_resource_view_tag,
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ uint32_t first_level,
			_HW_3D_IN_ uint32_t num_levels
		) {
		_Shader_resource_view_desc res;

		_Srv_desc desc;
		desc.MostDetailedMip = first_level;
		desc.MipLevels = num_levels;

		res.Format = format;
		res.Texture1D = desc;
		return res;
	}

	static _Depth_stencil_view_desc 
		_get_desc(
			_HW_3D_IN_ Depth_stencil_view_tag,
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ uint32_t mip_slice,
			_HW_3D_IN_ _HW_3D_D3D_ Dsv_flag flags
		) {
		_Depth_stencil_view_desc res;

		_Dsv_desc desc;
		desc.MipSlice = mip_slice;

		res.Format = format;
		res.Texture1D = desc;
		res.Flags = flags;
		return res;
	}
};

//
template <>
class _D3d_resource_view_helper<Resource_view_type::_texture1d_array> : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture1d;
	using _Rtv_desc = _HW_3D_D3D_ Tex1d_array_rtv;
	using _Uav_desc = _HW_3D_D3D_ Tex1d_array_uav;
	using _Srv_desc = _HW_3D_D3D_ Tex1d_array_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex1d_array_dsv;

	static _Render_target_view_desc 
		_get_desc(
			_HW_3D_IN_ Render_target_view_tag,
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ uint32_t mip_slice,
			_HW_3D_IN_ uint32_t first_index,
			_HW_3D_IN_ uint32_t array_size
		) {
		_Render_target_view_desc res;

		_Rtv_desc desc;
		desc.MipSlice = mip_slice;
		desc.FirstArraySlice = first_index;
		desc.ArraySize = array_size;

		res.Format = format;
		res.Texture1DArray = desc;
		return res;
	}

	static _Unordered_access_view_desc 
		_get_desc(
			_HW_3D_IN_ Unordered_access_view_tag,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ uint32_t mip_slice,
			_HW_3D_IN_ uint32_t first_index,
			_HW_3D_IN_ uint32_t array_size
		) {
		_Unordered_access_view_desc res;

		_Uav_desc desc;
		desc.MipSlice = mip_slice;
		desc.FirstArraySlice = first_index;
		desc.ArraySize = array_size;

		res.Format = format;
		res.Texture1DArray = desc;
		return res;
	}

	static _Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Shader_resource_view_tag,
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ uint32_t first_level,
			_HW_3D_IN_ uint32_t num_level,
			_HW_3D_IN_ uint32_t first_index,
			_HW_3D_IN_ uint32_t array_size
		) {
		_Shader_resource_view_desc res;

		_Srv_desc desc;
		desc.MostDetailedMip = first_level;
		desc.MipLevels = num_level;
		desc.FirstArraySlice = first_index;
		desc.ArraySize = array_size;

		res.Format = format;
		res.Texture1DArray = desc;
		return res;
	}

	static _Depth_stencil_view_desc
		_get_desc(
			_HW_3D_IN_ Depth_stencil_view_tag,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ uint32_t mip_slice,
			_HW_3D_IN_ uint32_t first_index,
			_HW_3D_IN_ uint32_t array_size,
			_HW_3D_IN_ _HW_3D_D3D_ Dsv_flag flags = {}
		) {
		_Depth_stencil_view_desc res;

		_Dsv_desc desc;
		desc.MipSlice = mip_slice;
		desc.FirstArraySlice = first_index;
		desc.ArraySize = array_size;

		res.Format = format;
		res.Texture1DArray = desc;
		res.Flags = flags;
		return res;
	}
};

//
template <>
class _D3d_resource_view_helper<Resource_view_type::_texture2d> : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture2d;
	using _Rtv_desc = _HW_3D_D3D_ Tex2d_rtv;
	using _Uav_desc = _HW_3D_D3D_ Tex2d_uav;
	using _Srv_desc = _HW_3D_D3D_ Tex2d_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex2d_dsv;

	static _Render_target_view_desc 
		_get_desc(
			_HW_3D_IN_ Render_target_view_tag,
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ uint32_t mip_slice
		) {
		_Render_target_view_desc res;

		_Rtv_desc desc;
		desc.MipSlice = mip_slice;

		res.Format = format;
		res.Texture2D = desc;
		return res;
	}

	static _Unordered_access_view_desc
		_get_desc(
			_HW_3D_IN_ Unordered_access_view_tag,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ uint32_t mip_slice
		) {
		_Unordered_access_view_desc res;

		_Uav_desc desc;
		desc.MipSlice = mip_slice;

		res.Format = format;
		res.Texture2D = desc;
		return res;
	}

	static _Shader_resource_view_desc
		_get_desc(
			_HW_3D_IN_ Shader_resource_view_tag,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ uint32_t first_level,
			_HW_3D_IN_ uint32_t num_levels
		) {
		_Shader_resource_view_desc res;

		_Srv_desc desc;
		desc.MostDetailedMip = first_level;
		desc.MipLevels = num_levels;

		res.Format = format;
		res.Texture2D = desc;
		return res;
	}

	static _Depth_stencil_view_desc 
		_get_desc(
			_HW_3D_IN_ Depth_stencil_view_tag,
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ uint32_t mip_slice,
			_HW_3D_IN_ _HW_3D_D3D_ Dsv_flag flags
		) {
		_Depth_stencil_view_desc res;

		_Dsv_desc desc;
		desc.MipSlice = mip_slice;

		res.Format = format;
		res.Texture2D = desc;
		res.Flags = flags;
		return res;
	}
};

//
template <>
struct _D3d_resource_view_helper<Resource_view_type::_texture2d_array> : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture2d;
	using _Rtv_desc = _HW_3D_D3D_ Tex2d_array_rtv;
	using _Uav_desc = _HW_3D_D3D_ Tex2d_array_uav;
	using _Srv_desc = _HW_3D_D3D_ Tex2d_array_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex2d_array_dsv;

	static _Render_target_view_desc
		_get_desc(
			_HW_3D_IN_ Render_target_view_tag,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ uint32_t mip_slice,
			_HW_3D_IN_ uint32_t first_index,
			_HW_3D_IN_ uint32_t array_size
		) {
		_Render_target_view_desc res;

		_Rtv_desc desc;
		desc.MipSlice = mip_slice;
		desc.FirstArraySlice = first_index;
		desc.ArraySize = array_size;

		res.Format = format;
		res.Texture2DArray = desc;
		return res;
	}

	static _Unordered_access_view_desc
		_get_desc(
			_HW_3D_IN_ Unordered_access_view_tag,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ uint32_t mip_slice,
			_HW_3D_IN_ uint32_t first_index,
			_HW_3D_IN_ uint32_t array_size
		) {
		_Unordered_access_view_desc res;

		_Uav_desc desc;
		desc.MipSlice = mip_slice;
		desc.FirstArraySlice = first_index;
		desc.ArraySize = array_size;

		res.Format = format;
		res.Texture2DArray = desc;
		return res;
	}

	static _Shader_resource_view_desc
		_get_desc(
			_HW_3D_IN_ Shader_resource_view_tag,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ uint32_t first_level,
			_HW_3D_IN_ uint32_t num_levels,
			_HW_3D_IN_ uint32_t first_index,
			_HW_3D_IN_ uint32_t array_size
		) {
		_Shader_resource_view_desc res;

		_Srv_desc desc;
		desc.MostDetailedMip = first_level;
		desc.MipLevels = num_levels;
		desc.FirstArraySlice = first_index;
		desc.ArraySize = array_size;

		res.Format = format;
		res.Texture2DArray = desc;
		return res;
	}

	static _Depth_stencil_view_desc 
		_get_desc(
			_HW_3D_IN_ Depth_stencil_view_tag,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ uint32_t mip_slice,
			_HW_3D_IN_ uint32_t first_index,
			_HW_3D_IN_ uint32_t array_size,
			_HW_3D_IN_ _HW_3D_D3D_ Dsv_flag flags
		) {
		_Depth_stencil_view_desc res;

		_Dsv_desc desc;
		desc.MipSlice = mip_slice;
		desc.FirstArraySlice = first_index;
		desc.ArraySize = array_size;

		res.Format = format;
		res.Texture2DArray = desc;
		res.Flags = flags;
		return res;
	}
};

//
template <>
struct _D3d_resource_view_helper<Resource_view_type::_texture2dms> : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture2d;
	using _Rtv_desc = _HW_3D_D3D_ Tex2dms_rtv;
	using _Srv_desc = _HW_3D_D3D_ Tex2dms_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex2dms_dsv;

	static _Render_target_view_desc 
		_get_desc(
			_HW_3D_IN_ Render_target_view_tag,
			_HW_3D_IN_ Pixel_format format 
		) {
		_Render_target_view_desc res;

		_Rtv_desc desc;

		res.Format = format;
		res.Texture2DMS = desc;
		return res;
	}

	static _Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Shader_resource_view_tag,
			_HW_3D_IN_ Pixel_format format
		) {
		_Shader_resource_view_desc res;

		_Srv_desc desc;

		res.Format = format;
		res.Texture2DMS = desc;
		return res;
	}

	static _Depth_stencil_view_desc 
		_get_desc(
			_HW_3D_IN_ Depth_stencil_view_tag,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ _HW_3D_D3D_ Dsv_flag flags
		) {
		_Depth_stencil_view_desc res;

		_Dsv_desc desc;

		res.Format = format;
		res.Texture2DMS = desc;
		res.Flags = flags;
		return res;
	}
};

//
template <>
struct _D3d_resource_view_helper<Resource_view_type::_texture2dms_array> : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture2d;
	using _Rtv_desc = _HW_3D_D3D_ Tex2dms_array_rtv;
	using _Srv_desc = _HW_3D_D3D_ Tex2dms_array_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex2dms_array_dsv;

	static _Render_target_view_desc
		_get_desc(
			_HW_3D_IN_ Render_target_view_tag,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ uint32_t first_index,
			_HW_3D_IN_ uint32_t array_size
	) {
		_Render_target_view_desc res;

		_Rtv_desc desc;
		desc.FirstArraySlice = first_index;
		desc.ArraySize = array_size;

		res.Format = format;
		res.Texture2DMSArray = desc;
		return res;
	}

	static _Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Shader_resource_view_tag,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ uint32_t first_index,
			_HW_3D_IN_ uint32_t array_size
		) {
		_Shader_resource_view_desc res;

		_Srv_desc desc;
		desc.FirstArraySlice = first_index;
		desc.ArraySize = array_size;

		res.Format = format;
		res.Texture2DMSArray = desc;
		return res;
	}

	static _Depth_stencil_view_desc 
		_get_desc(
			_HW_3D_IN_ Depth_stencil_view_tag,
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ uint32_t first_index,
			_HW_3D_IN_ uint32_t array_size,
			_HW_3D_IN_ _HW_3D_D3D_ Dsv_flag flags = {}
		) {
		_Depth_stencil_view_desc res;

		_Dsv_desc desc;
		desc.FirstArraySlice = first_index;
		desc.ArraySize = array_size;

		res.Format = format;
		res.Texture2DMSArray = desc;
		res.Flags = flags;
		return res;
	}
};

//
template <>
struct _D3d_resource_view_helper<Resource_view_type::_texture3d> : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture3d;
	using _Rtv_desc = _HW_3D_D3D_ Tex3d_rtv;
	using _Srv_desc = _HW_3D_D3D_ Tex3d_srv;
	using _Uav_desc = _HW_3D_D3D_ Tex3d_uav;

	static _Render_target_view_desc
		_get_desc(
			_HW_3D_IN_ Render_target_view_tag,
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ uint32_t mip_slice,
			_HW_3D_IN_ uint32_t first_slice,
			_HW_3D_IN_ uint32_t slice_size
		) {
		_Render_target_view_desc res;

		_Rtv_desc desc;
		desc.MipSlice = mip_slice;
		desc.FirstWSlice = first_slice;
		desc.WSize = slice_size;

		res.Format = format;
		res.Texture3D = desc;
		return res;
	}

	static _Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Shader_resource_view_tag,
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ uint32_t first_level,
			_HW_3D_IN_ uint32_t num_levels
		) {
		_Shader_resource_view_desc res;

		_Srv_desc desc;
		desc.MostDetailedMip = first_level;
		desc.MipLevels = num_levels;

		res.Format = format;
		res.Texture3D = desc;
		return res;
	}

	static _Unordered_access_view_desc
		_get_desc(
			_HW_3D_IN_ Unordered_access_view_tag,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ uint32_t mip_slice,
			_HW_3D_IN_ uint32_t first_slice,
			_HW_3D_IN_ uint32_t slice_size
		) {
		_Unordered_access_view_desc res;

		_Uav_desc desc;
		desc.MipSlice = mip_slice;
		desc.FirstWSlice = first_slice;
		desc.WSize = slice_size;

		res.Format = format;
		res.Texture3D = desc;
		return res;
	}
};

//
template <>
struct _D3d_resource_view_helper<Resource_view_type::_texture_cube> : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture2d;
	using _Srv_desc = _HW_3D_D3D_ Texcube_srv;

	static _Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Shader_resource_view_tag,
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ uint32_t first_level,
			_HW_3D_IN_ uint32_t num_levels
		) {
		_Shader_resource_view_desc res;

		_Srv_desc desc;
		desc.MostDetailedMip = first_level;
		desc.MipLevels = num_levels;

		res.Format = format;
		res.TextureCube = desc;
		return res;
	}
};

//
template <>
struct _D3d_resource_view_helper<Resource_view_type::_texture_cube_array> : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture2d;
	using _Srv_desc = _HW_3D_D3D_ Texcube_array_srv;

	static _Shader_resource_view_desc
		_get_desc(
			_HW_3D_IN_ Shader_resource_view_tag,
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ uint32_t first_level,
			_HW_3D_IN_ uint32_t num_levels,
			_HW_3D_IN_ uint32_t first_index,
			_HW_3D_IN_ uint32_t num_cubes
		) {
		_Shader_resource_view_desc res;

		_Srv_desc desc;
		desc.MostDetailedMip = first_level;
		desc.MipLevels = num_levels;
		desc.First2DArrayFace = first_index;
		desc.NumCubes = num_cubes;

		res.Format = format;
		res.TextureCubeArray = desc;
		return res;
	}
};

//
template <typename _View_helper, typename = _HW_3D_STD_ void_t<>>
struct _D3d_is_render_target_view_constructible : _HW_3D_STD_ false_type {
};

template <typename _View_helper>
struct _D3d_is_render_target_view_constructible<_View_helper, _HW_3D_STD_ void_t<typename _View_helper::_Rtv_desc>> : _HW_3D_STD_ true_type {
};

template <typename _View_helper>
_HW_3D_INLINE_VARIABLE_ constexpr bool D3d_is_render_target_view_constructible_v = _D3d_is_render_target_view_constructible<_View_helper>::value;

//
template <typename _View_helper, typename = _HW_3D_STD_ void_t<>>
struct _D3d_is_shader_resource_view_constructible : _HW_3D_STD_ false_type {
};

template <typename _View_helper>
struct _D3d_is_shader_resource_view_constructible<_View_helper, _HW_3D_STD_ void_t<typename _View_helper::_Srv_desc>> : _HW_3D_STD_ true_type {
};

template <typename _View_helper>
_HW_3D_INLINE_VARIABLE_ constexpr bool D3d_is_shader_resource_view_constructible_v = _D3d_is_shader_resource_view_constructible<_View_helper>::value;

//
template <typename _View_helper, typename = _HW_3D_STD_ void_t<>>
struct _D3d_is_depth_stencil_view_constructible : _HW_3D_STD_ false_type {
};

template <typename _View_helper>
struct _D3d_is_depth_stencil_view_constructible<_View_helper, _HW_3D_STD_ void_t<typename _View_helper::_Dsv_desc>> : _HW_3D_STD_ true_type {
};

template <typename _View_helper>
_HW_3D_INLINE_VARIABLE_ constexpr bool D3d_is_depth_stencil_view_constructible_v = _D3d_is_depth_stencil_view_constructible<_View_helper>::value;

//
template <typename _View_helper, typename = _HW_3D_STD_ void_t<>>
struct _D3d_is_unordered_access_view_constructible : _HW_3D_STD_ false_type {
};

template <typename _View_helper>
struct _D3d_is_unordered_access_view_constructible<_View_helper, _HW_3D_STD_ void_t<typename _View_helper::_Uav_desc>> : _HW_3D_STD_ true_type {
};

template <typename _View_helper>
struct D3d_is_unordered_access_view_constructbile_v = _D3d_is_unordered_access_view_constructible<_View_helper>::value;

struct _D3d_resource_view {

	template <Resource_view_type type, typename... Args>
	static _HW_3D_STD_ enable_if_t<D3d_is_render_target_view_constructible_v<_D3d_resource_view_helper<type>>, _HW_3D_STD_ unique_ptr<Render_target_view>>
		create_render_target_view(Device* device, typename _D3d_resource_view_helper<type>::_Resource_type* resource, Pixel_format format, Args&&... args) {
		return _D3d_resource_view_helper<type>::_create(device, resource, _D3d_resource_view_helper<type>::_get_desc(Render_target_view_tag{}, format, _HW_3D_STD_ forward<Args>(args)...));
	}

	template <Resource_view_type type, typename... Args>
	static _HW_3D_STD_ enable_if_t<D3d_is_shader_resource_view_constructible_v<_D3d_resource_view_helper<type>>, _HW_3D_STD_ unique_ptr<Shader_resource_view>>
		create_shader_resource_view(Device* device, typename _D3d_resource_view_helper<type>::_Resource_type* resource, Pixel_format format, Args&&... args) {
		return _D3d_resource_view_helper<type>::_create(device, resource, _D3d_resource_view_helper<type>::_get_desc(Shader_resource_view_tag{}, format, _HW_3D_STD_ forward<Args>(args)...));
	}

	template <Resource_view_type type, typename... Args>
	static _HW_3D_STD_ enable_if_t<D3d_is_depth_stencil_view_constructible_v<_D3d_resource_view_helper<type>>, _HW_3D_STD_ unique_ptr<Depth_stencil_view>>
		create_depth_stencil_view(Device* device, typename _D3d_resource_view_helper<type>::_Resource_type* resource, Pixel_format format, Args&&... args) {
		return _D3d_resource_view_helper<type>::_create(device, resource, _D3d_resource_view_helper<type>::_get_desc(Depth_stencil_view_tag{}, format, _HW_3D_STD_ forward<Args>(args)...));
	}

	template <Resource_view_type type, typename... Args>
	static _HW_3D_STD_ enable_if_t<D3d_is_unordered_access_view_constructbile_v<_D3d_resource_view_helper<type>>, _HW_3D_STD_ unique_ptr<Unordered_access_view>>
		create_unordered_access_view(Device* device, typename _D3d_resource_view_helper<type>::_Resource_type* resource, Pixel_format format, Args&&... args) {
		return _D3d_resource_view_helper<type>::_create(device, resource, _D3d_resource_view_helper<type>::_get_desc(Unordered_access_view_tag{}, format, _HW_3D_STD_ forward<Args>(args)...));
	}
};

_HW_3D_CLOSE_RS_NAMESPACE_

_HW_3D_CLOSE_HW_NAMESPACE_