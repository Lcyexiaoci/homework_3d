#pragma once

#include "rs_fwd.h"
#include "../d3d/d3d_wrapper.hpp"

_HW_3D_OPEN_HW_NAMESPACE_

_HW_3D_OPEN_RS_NAMESPACE_


//
//don't care all resources life time
class Render_manager {
private:
	using _Constant_buffers = _HW_3D_STD_ pair<uint32_t, _HW_3D_STD_ vector<_HW_3D_D3D_ IBuffer*>>;
	using _Constant_buffers_list = _HW_3D_STD_ array<_Constant_buffers, 6>;

	using _Samplers = _HW_3D_STD_ pair<uint32_t, _HW_3D_STD_ vector<_HW_3D_D3D_ ISampler_state*>>;
	using _Samplers_list = _HW_3D_STD_ array<_Samplers, 6>;

	using _Shader_resource_views = _HW_3D_STD_ pair<uint32_t, _HW_3D_STD_ vector<_HW_3D_D3D_ IShader_resource_view*>>;
	using _Shader_resource_views_list = _HW_3D_STD_ array<_Shader_resource_views, 6>;

	using _Render_target_views = _HW_3D_STD_ pair<uint32_t, _HW_3D_STD_ vector<_HW_3D_D3D_ IRender_target_view*>>;

	using _Blend_state_desc = _HW_3D_D3D_ Blend_desc;
	using _Blend_state_cache_keys = _HW_3D_STD_ vector<_Blend_state_desc>;
	using _Blend_state_cache_values = _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<_HW_3D_D3D_ IBlend_state>>;
	using _Blend_state_cache = _HW_3D_STD_ pair<_Blend_state_cache_keys, _Blend_state_cache_values>;

	using _Rasterizer_state_desc = _HW_3D_D3D_ Rasterizer_desc;
	using _Rasterizer_state_cache_keys = _HW_3D_STD_ vector<_Rasterizer_state_desc>;
	using _Rasterizer_state_cache_values = _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<_HW_3D_D3D_ IRasterizer_state>>;
	using _Rasterizer_state_cache = _HW_3D_STD_ pair<_Rasterizer_state_cache_keys, _Rasterizer_state_cache_values>;

	using _Depth_stencil_state_desc = _HW_3D_D3D_ Depth_stencil_desc;
	using _Depth_stencil_state_cache_keys = _HW_3D_STD_ vector<_Depth_stencil_state_desc>;
	using _Depth_stencil_state_cache_values = _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<_HW_3D_D3D_ IDepth_stencil_state>>;
	using _Depth_stencil_state_cache = _HW_3D_STD_ pair<_Depth_stencil_state_cache_keys, _Depth_stencil_state_cache_values>;

	using _Scissor_rects = _HW_3D_STD_ vector<_HW_3D_D3D_ Rect>;

	using _Viewports = _HW_3D_STD_ vector<_HW_3D_D3D_ Viewport>;
public:
	static Render_manager* current_render_manager();
public:
	Render_manager();

	~Render_manager();

	Native_device* native_device();

	Native_context* native_context();
};



_HW_3D_CLOSE_RS_NAMESPACE_

_HW_3D_CLOSE_HW_NAMESPACE_