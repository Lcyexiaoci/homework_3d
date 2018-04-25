#pragma once

#include "rs_fwd.h"
#include "rs_utils.hpp"
#include "rs_render_manager.h"

_HW_3D_OPEN_HW_NAMESPACE_

_HW_3D_OPEN_RS_NAMESPACE_

///
///d3d helper struct

//
struct _D3d_shader_helper_base {
	using _Shader_macro_type = _HW_3D_D3D_ Shader_macro;
	using _Source_code_type = _HW_3D_STD_ vector<_HW_3D_STD_ byte>;
};

//
struct _D3d_vertex_shader_helper : _D3d_shader_helper_base {
	using _Handle_type = _HW_3D_D3D_ IVertex_shader;
	using _Native_handle_type = ID3D11VertexShader;

	static _HW_3D_STD_ unique_ptr<_Handle_type>
		create_shader(
			_HW_3D_IN_ const _Source_code_type& code,
			_HW_3D_IN_ Native_device* device
		) {

	}
};


_HW_3D_CLOSE_RS_NAMESPACE_

_HW_3D_CLOSE_HW_NAMESPACE_
