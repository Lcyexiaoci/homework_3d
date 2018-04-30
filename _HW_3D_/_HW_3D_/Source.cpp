#include "utils.hpp"
#include <iostream>
#include "d3d\d3d_flag.hpp"
#include "d3d\d3d_enum.h"
#include "d3d\d3d_struct.hpp"
#include "d3d\d3d_wrapper.hpp"
#include "d3d\d3d_func.hpp"

#include "rs\rs_utils.hpp"
#include "rs\rs_render_manager.h"
#include "rs\rs_hw_shader.hpp"
#include "rs\rs_hw_view.hpp"
#include "rs\rs_hw_resource.hpp"

void test_d3d_wrapper();
void test_rs_utils();
void test_rs_view_base();

int main() {
	_HW_3D_RS_ Hardware_buffer_builder builder;
	builder.Usage = _HW_3D_RS_ Resource_usage::dynamic;
	

	test_rs_utils();
	std::getchar();
}

void test_d3d_wrapper() {
#define _TEST_DXGI_WRAPPER_(_Type) \
	auto p ## _Type = _HW_3D_STD_ make_unique<_HW_3D_DXGI_ _Type<false>>(nullptr)
#define _TEST_D3D_WRAPPER_(_Type) \
	auto p ## _Type = _HW_3D_STD_ make_unique<_HW_3D_D3D_ _Type<false>>(nullptr)
	{//test dxgi wrapper
	_TEST_DXGI_WRAPPER_(_Resource);
	_TEST_DXGI_WRAPPER_(_Output);
	_TEST_DXGI_WRAPPER_(_Output_duplication);
	_TEST_DXGI_WRAPPER_(_Adapter);
	_TEST_DXGI_WRAPPER_(_Debug);
	_TEST_DXGI_WRAPPER_(_Display_control);
	_TEST_DXGI_WRAPPER_(_Decode_swap_chain);
	_TEST_DXGI_WRAPPER_(_Surface);
	_TEST_DXGI_WRAPPER_(_Keyed_mutex);
	_TEST_DXGI_WRAPPER_(_Info_queue);
	_TEST_DXGI_WRAPPER_(_Swap_chain);
	_TEST_DXGI_WRAPPER_(_Device);
	_TEST_DXGI_WRAPPER_(_Factory);
	_TEST_DXGI_WRAPPER_(_Swap_chain_media);
	_TEST_DXGI_WRAPPER_(_Adapter1);
	_TEST_DXGI_WRAPPER_(_Adapter2);
	_TEST_DXGI_WRAPPER_(_Adapter3);
	_TEST_DXGI_WRAPPER_(_Adapter4);
	_TEST_DXGI_WRAPPER_(_Debug1);
	_TEST_DXGI_WRAPPER_(_Device1);
	_TEST_DXGI_WRAPPER_(_Device2);
	_TEST_DXGI_WRAPPER_(_Device3);
	_TEST_DXGI_WRAPPER_(_Device4);
	_TEST_DXGI_WRAPPER_(_Output1);
	_TEST_DXGI_WRAPPER_(_Output2);
	_TEST_DXGI_WRAPPER_(_Output3);
	_TEST_DXGI_WRAPPER_(_Output4);
	_TEST_DXGI_WRAPPER_(_Output5);
	_TEST_DXGI_WRAPPER_(_Output6);
	_TEST_DXGI_WRAPPER_(_Surface1);
	_TEST_DXGI_WRAPPER_(_Surface2);
	_TEST_DXGI_WRAPPER_(_Resource1);
	_TEST_DXGI_WRAPPER_(_Swap_chain1);
	_TEST_DXGI_WRAPPER_(_Swap_chain2);
	_TEST_DXGI_WRAPPER_(_Swap_chain3);
	_TEST_DXGI_WRAPPER_(_Swap_chain4);
	_TEST_DXGI_WRAPPER_(_Factory1);
	_TEST_DXGI_WRAPPER_(_Factory2);
	_TEST_DXGI_WRAPPER_(_Factory3);
	_TEST_DXGI_WRAPPER_(_Factory4);
	_TEST_DXGI_WRAPPER_(_Factory5);
	_TEST_DXGI_WRAPPER_(_Factory_media);
	}
	{//test d3d wrapper
	_TEST_D3D_WRAPPER_(_Blend_state);
	_TEST_D3D_WRAPPER_(_Blend_state1);
	_TEST_D3D_WRAPPER_(_Command_list);
	_TEST_D3D_WRAPPER_(_Counter);
	_TEST_D3D_WRAPPER_(_Depth_stencil_state);
	_TEST_D3D_WRAPPER_(_Device_context_state);
	_TEST_D3D_WRAPPER_(_Fence);
	_TEST_D3D_WRAPPER_(_Input_layout);
	_TEST_D3D_WRAPPER_(_Multithread);
	_TEST_D3D_WRAPPER_(_Query);
	_TEST_D3D_WRAPPER_(_Query1);
	_TEST_D3D_WRAPPER_(_Predicate);
	_TEST_D3D_WRAPPER_(_Rasterizer_state);
	_TEST_D3D_WRAPPER_(_Rasterizer_state1);
	_TEST_D3D_WRAPPER_(_Rasterizer_state2);
	_TEST_D3D_WRAPPER_(_Sampler_state);
	_TEST_D3D_WRAPPER_(_Resource);
	_TEST_D3D_WRAPPER_(_Buffer);
	_TEST_D3D_WRAPPER_(_Texture1d);
	_TEST_D3D_WRAPPER_(_Texture2d);
	_TEST_D3D_WRAPPER_(_Texture2d1);
	_TEST_D3D_WRAPPER_(_Texture3d);
	_TEST_D3D_WRAPPER_(_Texture3d1);
	_TEST_D3D_WRAPPER_(_Depth_stencil_view);
	_TEST_D3D_WRAPPER_(_Render_target_view);
	_TEST_D3D_WRAPPER_(_Render_target_view1);
	_TEST_D3D_WRAPPER_(_Shader_resource_view);
	_TEST_D3D_WRAPPER_(_Shader_resource_view1);
	_TEST_D3D_WRAPPER_(_Unordered_access_view);
	_TEST_D3D_WRAPPER_(_Unordered_access_view1);
	_TEST_D3D_WRAPPER_(_Class_instance);
	_TEST_D3D_WRAPPER_(_Class_linkage);
	_TEST_D3D_WRAPPER_(_Compute_shader);
	_TEST_D3D_WRAPPER_(_Domain_shader);
	_TEST_D3D_WRAPPER_(_Geometry_shader);
	_TEST_D3D_WRAPPER_(_Hull_shader);
	_TEST_D3D_WRAPPER_(_Pixel_shader);
	_TEST_D3D_WRAPPER_(_Vertex_shader);
	_TEST_D3D_WRAPPER_(_Linking_node);
	_TEST_D3D_WRAPPER_(_Module_instance);
	_TEST_D3D_WRAPPER_(_Module);
	_TEST_D3D_WRAPPER_(_Blob);
	_TEST_D3D_WRAPPER_(_User_defined_annotation);
	_TEST_D3D_WRAPPER_(_Linker);
	_TEST_D3D_WRAPPER_(_Library_reflection);
	_TEST_D3D_WRAPPER_(_Shader_reflection);
	_TEST_D3D_WRAPPER_(_Shader_trace);
	_TEST_D3D_WRAPPER_(_Shader_trace_factory);
	_TEST_D3D_WRAPPER_(_Function_linking_graph);
	_TEST_D3D_WRAPPER_(_Device);
	_TEST_D3D_WRAPPER_(_Device_context);
	_TEST_D3D_WRAPPER_(_Device_context1);
	_TEST_D3D_WRAPPER_(_Device_context2);
	_TEST_D3D_WRAPPER_(_Device_context3);
	_TEST_D3D_WRAPPER_(_Device_context4);
	_TEST_D3D_WRAPPER_(_Device1);
	_TEST_D3D_WRAPPER_(_Device2);
	_TEST_D3D_WRAPPER_(_Device3);
	_TEST_D3D_WRAPPER_(_Device4);
	_TEST_D3D_WRAPPER_(_Device5);
	_TEST_D3D_WRAPPER_(_Debug);
	_TEST_D3D_WRAPPER_(_Info_queue);
	_TEST_D3D_WRAPPER_(_Ref_default_tracking_options);
	_TEST_D3D_WRAPPER_(_Ref_tracking_options);
	_TEST_D3D_WRAPPER_(_Tracing_device);
	}
#undef _TEST_DXGI_WRAPPER_
#undef _TEST_D3D_WRAPPER_
}

void test_rs_utils() {
	_HW_3D_RS_ Offset1d a(1.0f);
	_HW_3D_RS_ Offset2d b(a);
	std::cout << a.x << std::endl;
	std::cout << b.x << ", " << b.y << std::endl;

	_HW_3D_RS_ Extent1d x(1.1);
	_HW_3D_RS_ Extent2d y(1, 2.2);
	_HW_3D_RS_ Extent3d z(y);
	z.depth = 3;
	std::cout << x.width << std::endl;
	std::cout << y.width << ", " << y.height << std::endl;
	std::cout << z.width << ", " << y.height << ", " << z.depth << std::endl;

	_HW_3D_RS_ Range2d m(a, y);
	std::cout << "<" << m.offset.x << ", " << m.offset.y << "> - <"
		<< m.extent.width << ", " << m.extent.height << ">" << std::endl;

	std::cout << std::is_constructible_v<_HW_3D_RS_ Offset2d, const _HW_3D_RS_ Offset1d &> << std::endl;
	std::cout << std::is_constructible_v<_HW_3D_RS_ Extent2d, const _HW_3D_RS_ Extent2d &> << std::endl;

	_HW_3D_RS_ Range3d n(1, 2, 3, 4, 5, 6);
	std::cout << "< " << n.offset.x << ", " << n.offset.y << ", " << n.offset.z << "> - <"
		<< n.extent.width << ", " << n.extent.height << ", " << n.extent.depth << ">" << std::endl;
}

void test_rs_view_base() {
#define _TEST_VIEW_BASE_(type) \
	std::cout << #type << ": " << sizeof(_HW_3D_RS_ _D3d_view_base<_HW_3D_RS_ _D3d_ ##type ##_view_helper>) <<"\n" << std::endl

	_TEST_VIEW_BASE_(buffer);
	_TEST_VIEW_BASE_(buffer_ex);
	_TEST_VIEW_BASE_(texture1d);
	_TEST_VIEW_BASE_(texture1d_array);
	_TEST_VIEW_BASE_(texture2d);
	_TEST_VIEW_BASE_(texture2d_array);
	_TEST_VIEW_BASE_(texture2dms);
	_TEST_VIEW_BASE_(texture2dms_array);
	_TEST_VIEW_BASE_(texture3d);
	_TEST_VIEW_BASE_(texture_cube);
	_TEST_VIEW_BASE_(texture_cube_array);

#undef _TEST_VIEW_BASE_
}