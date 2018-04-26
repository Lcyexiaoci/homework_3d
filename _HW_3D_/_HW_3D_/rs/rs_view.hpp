#pragma once

#include "rs_fwd.h"
#include "rs_utils.hpp"

_HW_3D_OPEN_HW_NAMESPACE_

_HW_3D_OPEN_RS_NAMESPACE_

//
struct _D3d_view_helper_base {
	using _Format_type = Native_pixel_format;
	using _Render_target_view = _HW_3D_D3D_ IRender_target_view;
	using _Depth_stencil_view = _HW_3D_D3D_ IDepth_stencil_view;
	using _Shader_resource_view = _HW_3D_D3D_ IShader_resource_view;
	using _Unordered_access_view = _HW_3D_D3D_ IUnordered_access_view;
	using _Native_render_target_view = ID3D11RenderTargetView;
	using _Native_depth_stencil_view = ID3D11DepthStencilView;
	using _Native_shader_resource_view = ID3D11ShaderResourceView;
	using _Native_unordered_access_view = ID3D11UnorderedAccessView;
};

//
struct _D3d_buffer_view_helper : _D3d_view_helper_base {
	using _Resource_type = Hardware_buffer;
	using _Rtv_desc = _HW_3D_D3D_ Buffer_rtv;
	using _Uav_desc = _HW_3D_D3D_ Buffer_uav;
	using _Srv_desc = _HW_3D_D3D_ Buffer_srv;
};

//
struct _D3d_buffer_ex_view_helper : _D3d_view_helper_base {
	using _Resource_type = Hardware_buffer;
	using _Srv_desc = _HW_3D_D3D_ Buffer_ex_srv;
	using _Uav_desc = _HW_3D_D3D_ Buffer_uav;
};

//
struct _D3d_texture1d_view_helper : _D3d_view_helper_base {
	using _Resource_type = Hardware_texture1d;
	using _Rtv_desc = _HW_3D_D3D_ Tex1d_rtv;
	using _Uav_desc = _HW_3D_D3D_ Tex1d_uav;
	using _Srv_desc = _HW_3D_D3D_ Tex1d_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex1d_dsv;
};

//
struct _D3d_texture1d_array_view_helper : _D3d_view_helper_base {
	using _Resource_type = Hardware_texture1d;
	using _Rtv_desc = _HW_3D_D3D_ Tex1d_array_rtv;
	using _Uav_desc = _HW_3D_D3D_ Tex1d_array_uav;
	using _Srv_desc = _HW_3D_D3D_ Tex1d_array_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex1d_array_dsv;
};

//
struct _D3d_texture2d_view_helper : _D3d_view_helper_base {
	using _Resource_type = Hardware_texture2d;
	using _Rtv_desc = _HW_3D_D3D_ Tex2d_rtv;
	using _Uav_desc = _HW_3D_D3D_ Tex2d_uav;
	using _Srv_desc = _HW_3D_D3D_ Tex2d_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex2d_dsv;
};

//
struct _D3d_texture2d_array_view_helper : _D3d_view_helper_base {
	using _Resource_type = Hardware_texture2d;
	using _Rtv_desc = _HW_3D_D3D_ Tex2d_array_rtv;
	using _Uav_desc = _HW_3D_D3D_ Tex2d_array_uav;
	using _Srv_desc = _HW_3D_D3D_ Tex2d_array_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex2d_array_dsv;
};

//
struct _D3d_texture2dms_view_helper : _D3d_view_helper_base {
	using _Resource_type = Hardware_texture2d;
	using _Rtv_desc = _HW_3D_D3D_ Tex2dms_rtv;
	using _Srv_desc = _HW_3D_D3D_ Tex2dms_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex2dms_dsv;
};

//
struct _D3d_texture2dms_array_view_helper : _D3d_view_helper_base {
	using _Resource_type = Hardware_texture2d;
	using _Rtv_desc = _HW_3D_D3D_ Tex2dms_array_rtv;
	using _Srv_desc = _HW_3D_D3D_ Tex2dms_array_srv;
	using _Dsv_desc = _HW_3D_D3D_ Tex2dms_array_dsv;
};

//
struct _D3d_texture3d_view_helper : _D3d_view_helper_base {
	using _Resource_type = Hardware_texture3d;
	using _Rtv_desc = _HW_3D_D3D_ Tex3d_rtv;
	using _Srv_desc = _HW_3D_D3D_ Tex3d_srv;
	using _Uav_desc = _HW_3D_D3D_ Tex3d_uav;
};

//
struct _D3d_texture_cube_view_helper : _D3d_view_helper_base {
	using _Resource_type = Hardware_texture2d;
	using _Srv_desc = _HW_3D_D3D_ Texcube_srv;
};

//
struct _D3d_texture_cube_array_view_helper : _D3d_view_helper_base {
	using _Resource_type = Hardware_texture2d;
	using _Srv_desc = _HW_3D_D3D_ Texcube_array_srv;
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