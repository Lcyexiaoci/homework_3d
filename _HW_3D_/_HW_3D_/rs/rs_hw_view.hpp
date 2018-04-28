#pragma once

#include "rs_fwd.h"
#include "rs_utils.hpp"

_HW_3D_OPEN_HW_NAMESPACE_

_HW_3D_OPEN_RS_NAMESPACE_

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

	_HW_3D_STD_ unique_ptr<_Render_target_view> 
		_create(
			_HW_3D_IN_ Device* device, 
			_HW_3D_IN_ _Resource_type* resource, 
			_HW_3D_IN_ _Render_target_view_desc& desc
		) {
		auto[success, result] = device->create_render_target_view(resource, &desc);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to create a render target view"); 

		return _HW_3D_STD_ move(result);
	}

	_HW_3D_STD_ unique_ptr<_Depth_stencil_view> 
		_create(
			_HW_3D_IN_ Device* device,
			_HW_3D_IN_ _Resource_type* resource, 
			_HW_3D_IN_ _Depth_stencil_view_desc& desc
		) {
		auto[success, result] = device->create_depth_stencil_view(resource, &desc);
		
		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to create a depth stencil view");

		return _HW_3D_STD_ move(result);
	}

	_HW_3D_STD_ unique_ptr<_Shader_resource_view> 
		_create(
			_HW_3D_IN_ Device* device, 
			_HW_3D_IN_ _Resource_type* resource, 
			_HW_3D_IN_ _Shader_resource_view_desc& desc
		) {
		auto[success, result] = device->create_shader_resource_view(resource, &desc);
		
		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to create shader resource view");

		return _HW_3D_STD_ move(result);
	}

	_HW_3D_STD_ unique_ptr<_Unordered_access_view> 
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
struct _D3d_buffer_view_helper : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ IBuffer;
	using _Rtv_desc = _HW_3D_D3D_ Buffer_rtv;
	using _Uav_desc = _HW_3D_D3D_ Buffer_uav;
	using _Srv_desc = _HW_3D_D3D_ Buffer_srv;


	_Render_target_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Rtv_desc& desc
		) {
		_Render_target_view_desc res;
		res.Format = format;
		res.Buffer = desc;
		return res;
	}

	_Unordered_access_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Uav_desc& desc
		) {
		_Unordered_access_view_desc res;
		res.Format = format;
		res.Buffer = desc;
		return res;
	}

	_Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Srv_desc& desc) {
		_Shader_resource_view_desc res;
		res.Format = format;
		res.Buffer = desc;
		return res;
	}
};

//
struct _D3d_buffer_ex_view_helper : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ IBuffer;
	using _Srv_desc = _HW_3D_D3D_ Buffer_ex_srv;
	using _Uav_desc = _HW_3D_D3D_ Buffer_uav;

	_Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Srv_desc& desc
		) {
		_Shader_resource_view_desc res;
		res.Format = format;
		res.BufferEx = desc;
		return res;
	}

	_Unordered_access_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ _Uav_desc& desc
		) {
		_Unordered_access_view_desc res;
		res.Format = format;
		res.Buffer = desc;
		return res;
	}
};

//
struct _D3d_texture1d_view_helper : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture1d;
	using _Rtv_desc = _HW_3D_D3D_ Tex1d_rtv;
	using _Uav_desc = _HW_3D_D3D_ Tex1d_uav;
	using _Srv_desc = _HW_3D_D3D_ Tex1d_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex1d_dsv;

	_Render_target_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Rtv_desc& desc
		) {
		_Render_target_view_desc res;
		res.Format = format;
		res.Texture1D = desc;
		return res;
	}

	_Unordered_access_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ _Uav_desc& desc
		) {
		_Unordered_access_view_desc res;
		res.Format = format;
		res.Texture1D = desc;
		return res;
	}

	_Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Srv_desc& desc
		) {
		_Shader_resource_view_desc res;
		res.Format = format;
		res.Texture1D = desc;
		return res;
	}

	_Depth_stencil_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Dsv_desc& desc, 
			_HW_3D_IN_ _HW_3D_D3D_ Dsv_flag flags = {}
		) {
		_Depth_stencil_view_desc res;
		res.Format = format;
		res.Texture1D = desc;
		res.Flags = flags;
		return res;
	}
};

//
struct _D3d_texture1d_array_view_helper : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture1d;
	using _Rtv_desc = _HW_3D_D3D_ Tex1d_array_rtv;
	using _Uav_desc = _HW_3D_D3D_ Tex1d_array_uav;
	using _Srv_desc = _HW_3D_D3D_ Tex1d_array_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex1d_array_dsv;

	_Render_target_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Rtv_desc& desc
		) {
		_Render_target_view_desc res;
		res.Format = format;
		res.Texture1DArray = desc;
		return res;
	}

	_Unordered_access_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ _Uav_desc& desc
		) {
		_Unordered_access_view_desc res;
		res.Format = format;
		res.Texture1DArray = desc;
		return res;
	}

	_Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Srv_desc& desc
		) {
		_Shader_resource_view_desc res;
		res.Format = format;
		res.Texture1DArray = desc;
		return res;
	}

	_Depth_stencil_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ _Dsv_desc& desc, 
			_HW_3D_IN_ _HW_3D_D3D_ Dsv_flag flags = {}
		) {
		_Depth_stencil_view_desc res;
		res.Format = format;
		res.Texture1DArray = desc;
		res.Flags = flags;
		return res;
	}
};

//
struct _D3d_texture2d_view_helper : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture2d;
	using _Rtv_desc = _HW_3D_D3D_ Tex2d_rtv;
	using _Uav_desc = _HW_3D_D3D_ Tex2d_uav;
	using _Srv_desc = _HW_3D_D3D_ Tex2d_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex2d_dsv;

	_Render_target_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Rtv_desc& desc
		) {
		_Render_target_view_desc res;
		res.Format = format;
		res.Texture2D = desc;
		return res;
	}

	_Unordered_access_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ _Uav_desc& desc
		) {
		_Unordered_access_view_desc res;
		res.Format = format;
		res.Texture2D = desc;
		return res;
	}

	_Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Srv_desc& desc
		) {
		_Shader_resource_view_desc res;
		res.Format = format;
		res.Texture2D = desc;
		return res;
	}

	_Depth_stencil_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Dsv_desc& desc, 
			_HW_3D_IN_ _HW_3D_D3D_ Dsv_flag flags = {}
		) {
		_Depth_stencil_view_desc res;
		res.Format = format;
		res.Texture2D = desc;
		res.Flags = flags;
		return res;
	}
};

//
struct _D3d_texture2d_array_view_helper : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture2d;
	using _Rtv_desc = _HW_3D_D3D_ Tex2d_array_rtv;
	using _Uav_desc = _HW_3D_D3D_ Tex2d_array_uav;
	using _Srv_desc = _HW_3D_D3D_ Tex2d_array_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex2d_array_dsv;

	_Render_target_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Rtv_desc& desc
		) {
		_Render_target_view_desc res;
		res.Format = format;
		res.Texture2DArray = desc;
		return res;
	}

	_Unordered_access_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Uav_desc& desc
		) {
		_Unordered_access_view_desc res;
		res.Format = format;
		res.Texture2DArray = desc;
		return res;
	}

	_Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Srv_desc& desc
		) {
		_Shader_resource_view_desc res;
		res.Format = format;
		res.Texture2DArray = desc;
		return res;
	}

	_Depth_stencil_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ _Dsv_desc& desc,
			_HW_3D_IN_ _HW_3D_D3D_ Dsv_flag flags = {}
		) {
		_Depth_stencil_view_desc res;
		res.Format = format;
		res.Texture2DArray = desc;
		res.Flags = flags;
		return res;
	}
};

//
struct _D3d_texture2dms_view_helper : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture2d;
	using _Rtv_desc = _HW_3D_D3D_ Tex2dms_rtv;
	using _Srv_desc = _HW_3D_D3D_ Tex2dms_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex2dms_dsv;

	_Render_target_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Rtv_desc& desc
		) {
		_Render_target_view_desc res;
		res.Format = format;
		res.Texture2DMS = desc;
		return res;
	}

	_Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Srv_desc& desc
		) {
		_Shader_resource_view_desc res;
		res.Format = format;
		res.Texture2DMS = desc;
		return res;
	}

	_Depth_stencil_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ _Dsv_desc& desc,
			_HW_3D_IN_ _HW_3D_D3D_ Dsv_flag flags = {}
		) {
		_Depth_stencil_view_desc res;
		res.Format = format;
		res.Texture2DMS = desc;
		res.Flags = flags;
		return res;
	}
};

//
struct _D3d_texture2dms_array_view_helper : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture2d;
	using _Rtv_desc = _HW_3D_D3D_ Tex2dms_array_rtv;
	using _Srv_desc = _HW_3D_D3D_ Tex2dms_array_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex2dms_array_dsv;

	_Render_target_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ _Rtv_desc& desc
		) {
		_Render_target_view_desc res;
		res.Format = format;
		res.Texture2DMSArray = desc;
		return res;
	}

	_Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format,
			_HW_3D_IN_ _Srv_desc& desc
		) {
		_Shader_resource_view_desc res;
		res.Format = format;
		res.Texture2DMSArray = desc;
		return res;
	}

	_Depth_stencil_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Dsv_desc& desc,
			_HW_3D_IN_ _HW_3D_D3D_ Dsv_flag flags = {}
		) {
		_Depth_stencil_view_desc res;
		res.Format = format;
		res.Texture2DMSArray = desc;
		res.Flags = flags;
		return res;
	}
};

//
struct _D3d_texture3d_view_helper : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture3d;
	using _Rtv_desc = _HW_3D_D3D_ Tex3d_rtv;
	using _Srv_desc = _HW_3D_D3D_ Tex3d_srv;
	using _Uav_desc = _HW_3D_D3D_ Tex3d_uav;

	_Render_target_view_desc
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Rtv_desc& desc
		) {
		_Render_target_view_desc res;
		res.Format = format;
		res.Texture3D = desc;
		return res;
	}

	_Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Srv_desc& desc
		) {
		_Shader_resource_view_desc res;
		res.Format = format;
		res.Texture3D = desc;
		return res;
	}

	_Unordered_access_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Uav_desc& desc
		) {
		_Unordered_access_view_desc res;
		res.Format = format;
		res.Texture3D = desc;
		return res;
	}
};

//
struct _D3d_texture_cube_view_helper : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture2d;
	using _Srv_desc = _HW_3D_D3D_ Texcube_srv;

	_Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Srv_desc& desc
		) {
		_Shader_resource_view_desc res;
		res.Format = format;
		res.TextureCube = desc;
		return res;
	}
};

//
struct _D3d_texture_cube_array_view_helper : _D3d_view_helper_base {
	using _Resource_type = _HW_3D_D3D_ ITexture2d;
	using _Srv_desc = _HW_3D_D3D_ Texcube_array_srv;

	_Shader_resource_view_desc 
		_get_desc(
			_HW_3D_IN_ Pixel_format format, 
			_HW_3D_IN_ _Srv_desc& desc
		) {
		_Shader_resource_view_desc res;
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

//
template <typename _View_helper, typename = _HW_3D_STD_ void_t<>>
struct _D3d_is_shader_resource_view_constructible : _HW_3D_STD_ false_type {
};

template <typename _View_helper>
struct _D3d_is_shader_resource_view_constructible<_View_helper, _HW_3D_STD_ void_t<typename _View_helper::_Srv_desc>> : _HW_3D_STD_ true_type {
};

//
template <typename _View_helper, typename = _HW_3D_STD_ void_t<>>
struct _D3d_is_depth_stencil_view_constructible : _HW_3D_STD_ false_type {
};

template <typename _View_helper>
struct _D3d_is_depth_stencil_view_constructible<_View_helper, _HW_3D_STD_ void_t<typename _View_helper::_Dsv_desc>> : _HW_3D_STD_ true_type {
};

//
template <typename _View_helper, typename = _HW_3D_STD_ void_t<>>
struct _D3d_is_unordered_access_view_constructible : _HW_3D_STD_ false_type {
};

template <typename _View_helper>
struct _D3d_is_unordered_access_view_constructible<_View_helper, _HW_3D_STD_ void_t<typename _View_helper::_Uav_desc>> : _HW_3D_STD_ true_type {
};

//
template <typename _View_helper, bool = _D3d_is_render_target_view_constructible<_View_helper>::value>
struct _D3d_render_target_view_base {
};

template <typename _View_helper>
struct _D3d_render_target_view_base<_View_helper, true> {
	_HW_3D_STD_ unique_ptr<typename _View_helper::_Render_target_view> _render_target_view;
};

//
template <typename _View_helper, bool = _D3d_is_shader_resource_view_constructible<_View_helper>::value>
struct _D3d_shader_resource_view_base : _D3d_render_target_view_base<_View_helper> {
};

template <typename _View_helper>
struct _D3d_shader_resource_view_base<_View_helper, true> : _D3d_render_target_view_base<_View_helper> {
	_HW_3D_STD_ unique_ptr<typename _View_helper::_Shader_resource_view> _shader_resource_view;
};

//
template <typename _View_helper, bool = _D3d_is_depth_stencil_view_constructible<_View_helper>::value>
struct _D3d_depth_stencil_view_base : _D3d_shader_resource_view_base<_View_helper> {
};

template <typename _View_helper>
struct _D3d_depth_stencil_view_base<_View_helper, true> : _D3d_shader_resource_view_base<_View_helper> {
	_HW_3D_STD_ unique_ptr<typename _View_helper::_Depth_stencil_view> _depth_stencil_view;
};

//
template <typename _View_helper, bool = _D3d_is_unordered_access_view_constructible<_View_helper>::value>
struct _D3d_unordered_access_view_base : _D3d_depth_stencil_view_base<_View_helper> {
};

template <typename _View_helper>
struct _D3d_unordered_access_view_base<_View_helper, true> : _D3d_depth_stencil_view_base<_View_helper> {
	_HW_3D_STD_ unique_ptr<typename _View_helper::_Unordered_access_view> _unordered_access_view;
};

//
template <typename _View_helper>
struct _D3d_view_base : _D3d_unordered_access_view_base<_View_helper> {

};

_HW_3D_CLOSE_RS_NAMESPACE_

_HW_3D_CLOSE_HW_NAMESPACE_