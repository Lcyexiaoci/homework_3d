#pragma once

#include "../fwd.h"
#include "../utils.hpp"
#include "../log.hpp"
#include "../d3d/d3d_wrapper.hpp"

#define _HW_3D_RS_	_HW_3D_HW_ rs::

#define _HW_3D_OPEN_RS_NAMESPACE_	namespace rs {
#define _HW_3D_CLOSE_RS_NAMESPACE_	}

#define _HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(res, msg)					\
	if (res != _HW_3D_D3D_ Result::ok)								\
		_HW_3D_TRHOW_EXCEPTION_(_HW_3D_HW_ Error_type::d3d11, msg)

#define _HW_3D_RS_ASSERT_DXGICALL_SUCCESS_(res, msg)				\
	if (res != _HW_3D_DXGI_ Result::ok)								\
		_HW_3D_TRHOW_EXCEPTION_(_HW_3D_HW_ Error_type::d3d11, msg)


_HW_3D_OPEN_HW_NAMESPACE_

_HW_3D_OPEN_RS_NAMESPACE_
///
///import type

//import native api type, d3d specific
using Factory = _HW_3D_DXGI_ IFactory;
using Adapteer = _HW_3D_DXGI_ IAdapter;
using Context = _HW_3D_D3D_ IDevice_context;
using Device = _HW_3D_D3D_ IDevice;
using Resource_usage = _HW_3D_D3D_ Usage;
using Resource_bind_flag = _HW_3D_D3D_ Bind_flag;
using Resource_cpu_access_flag = _HW_3D_D3D_ Cpu_access_flag;
using Resource_misc_flag = _HW_3D_D3D_ Resource_misc_flag;
using Pixel_format = _HW_3D_DXGI_ Format;

using Native_factory = IDXGIFactory;
using Native_adapter = IDXGIAdapter;
using Native_context = ID3D11DeviceContext;
using Native_device = ID3D11Device;

//import utils struct
using Rect = _HW_3D_D3D_ Rect;
using Box = _HW_3D_D3D_ Box;

//for simplicity, import d3d enum type
using Shader_type = _HW_3D_D3D_ Shader_type;
using Polygon_fill_mode = _HW_3D_D3D_ Fill_mode;
using Polygon_cull_mode = _HW_3D_D3D_ Cull_mode;
using Depth_write_mask = _HW_3D_D3D_ Depth_write_mask;
using Comparison_func = _HW_3D_D3D_ Comparison_func;
using Stencil_op = _HW_3D_D3D_ Stencil_op;
using Blend_factor = _HW_3D_D3D_ Blend;
using Blend_op = _HW_3D_D3D_ Blend_op;
using Texture_filter = _HW_3D_D3D_ Filter;
using Texture_address_mode = _HW_3D_D3D_ Texture_address_mode;

//forward declaration
class Hardware_buffer;
class Hardware_texture1d;
class Hardware_texture2d;
class Hardware_texture3d;


_HW_3D_CLOSE_RS_NAMESPACE_

_HW_3D_CLOSE_HW_NAMESPACE_