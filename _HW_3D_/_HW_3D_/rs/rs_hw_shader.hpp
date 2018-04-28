#pragma once

#include "rs_fwd.h"
#include "rs_utils.hpp"
#include "rs_render_manager.h"
#include "../d3d/d3d_func.hpp"

_HW_3D_OPEN_HW_NAMESPACE_

_HW_3D_OPEN_RS_NAMESPACE_

///
///d3d helper struct

//for simplicity, create shader without classlinkage
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
			_HW_3D_IN_ Device* device
		) {
		auto[success, result] = device->create_vertex_shader(code.data(), code.size(), nullptr);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to create vertex shader");

		return _HW_3D_STD_ move(result);
	}

	static _Source_code_type 
		file_to_source_code(
			_HW_3D_IN_ const Path& file_name,
			_HW_3D_IN_ const _HW_3D_STD_ string& entry_point,
			_HW_3D_IN_ const _HW_3D_STD_ vector<_Shader_macro_type>& macros
		) {
		assert(macros.empty() || (macros.back().Name == nullptr && macros.back().Definition == nullptr));
		assert(file_name.has_filename());

		_Source_code_type res;

		_HW_3D_D3D_ Compile_constant flag = _HW_3D_D3D_ Compile_constant_bit::enable_strictness;
		auto[success, result] = _HW_3D_D3D_ compile_from_file(file_name.wstring(), macros.data(), entry_point, "vs_5_0", flag);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed ot compile vertex shader");

		res.resize(result->get_buffer_size());
		_HW_3D_STD_ memcpy(res.data(), result->get_buffer_pointer(), res.size());

		return res;
	}

	static void 
		make_shader_current(
		_HW_3D_IN_ _Handle_type* handle,
		_HW_3D_IN_ Context* context
	) {
		context->vs_set_shader(handle, {});
	}
};

//
struct _D3d_compute_shader_helper : _D3d_shader_helper_base {
	using _Handle_type = _HW_3D_D3D_ ICompute_shader;
	using _Native_handle_type = ID3D11ComputeShader;

	static _HW_3D_STD_ unique_ptr<_Handle_type>
		create_shader(
			_HW_3D_IN_ const _Source_code_type& code,
			_HW_3D_IN_ Device* device
		) {
		auto[success, result] = device->create_compute_shader(code.data(), code.size(), nullptr);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to create compute shader");

		return _HW_3D_STD_ move(result);
	}

	static _Source_code_type
		file_to_source_code(
			_HW_3D_IN_ const Path& file_name,
			_HW_3D_IN_ const _HW_3D_STD_ string& entry_point,
			_HW_3D_IN_ const _HW_3D_STD_ vector<_Shader_macro_type>& macros
		) {
		assert(macros.empty() || (macros.back().Name == nullptr && macros.back().Definition == nullptr));
		assert(file_name.has_filename());

		_Source_code_type res;

		_HW_3D_D3D_ Compile_constant flag = _HW_3D_D3D_ Compile_constant_bit::enable_strictness;
		auto[success, result] = _HW_3D_D3D_ compile_from_file(file_name.wstring(), macros.data(), entry_point, "cs_5_0", flag);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed ot compile compute shader");

		res.resize(result->get_buffer_size());
		_HW_3D_STD_ memcpy(res.data(), result->get_buffer_pointer(), res.size());

		return res;
	}

	static void
		make_shader_current(
			_HW_3D_IN_ _Handle_type* handle,
			_HW_3D_IN_ Context* context
		) {
		context->cs_set_shader(handle, {});
	}
};

//
struct _D3d_domain_shader_helper : _D3d_shader_helper_base {
	using _Handle_type = _HW_3D_D3D_ IDomain_shader;
	using _Native_handle_type = ID3D11DomainShader;

	static _HW_3D_STD_ unique_ptr<_Handle_type>
		create_shader(
			_HW_3D_IN_ const _Source_code_type& code,
			_HW_3D_IN_ Device* device
		) {
		auto[success, result] = device->create_domain_shader(code.data(), code.size(), nullptr);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to create domain shader");

		return _HW_3D_STD_ move(result);
	}

	static _Source_code_type
		file_to_source_code(
			_HW_3D_IN_ const Path& file_name,
			_HW_3D_IN_ const _HW_3D_STD_ string& entry_point,
			_HW_3D_IN_ const _HW_3D_STD_ vector<_Shader_macro_type>& macros
		) {
		assert(macros.empty() || (macros.back().Name == nullptr && macros.back().Definition == nullptr));
		assert(file_name.has_filename());

		_Source_code_type res;

		_HW_3D_D3D_ Compile_constant flag = _HW_3D_D3D_ Compile_constant_bit::enable_strictness;
		auto[success, result] = _HW_3D_D3D_ compile_from_file(file_name.wstring(), macros.data(), entry_point, "ds_5_0", flag);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to compile domain shader");

		res.resize(result->get_buffer_size());
		_HW_3D_STD_ memcpy(res.data(), result->get_buffer_pointer(), res.size());

		return res;
	}

	static void
		make_shader_current(
			_HW_3D_IN_ _Handle_type* handle,
			_HW_3D_IN_ Context* context
		) {
		context->ds_set_shader(handle, {});
	}
};

//
struct _D3d_hull_shader_helper : _D3d_shader_helper_base {
	using _Handle_type = _HW_3D_D3D_ IHull_shader;
	using _Native_handle_type = ID3D11HullShader;

	static _HW_3D_STD_ unique_ptr<_Handle_type>
		create_shader(
			_HW_3D_IN_ const _Source_code_type& code,
			_HW_3D_IN_ Device* device
		) {
		auto[success, result] = device->create_hull_shader(code.data(), code.size(), nullptr);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to create hull shader");

		return _HW_3D_STD_ move(result);
	}

	static _Source_code_type
		file_to_source_code(
			_HW_3D_IN_ const Path& file_name,
			_HW_3D_IN_ const _HW_3D_STD_ string& entry_point,
			_HW_3D_IN_ const _HW_3D_STD_ vector<_Shader_macro_type>& macros
		) {
		assert(macros.empty() || (macros.back().Name == nullptr && macros.back().Definition == nullptr));
		assert(file_name.has_filename());

		_Source_code_type res;

		_HW_3D_D3D_ Compile_constant flag = _HW_3D_D3D_ Compile_constant_bit::enable_strictness;
		auto[success, result] = _HW_3D_D3D_ compile_from_file(file_name.wstring(), macros.data(), entry_point, "hs_5_0", flag);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to compile hull shader");

		res.resize(result->get_buffer_size());
		_HW_3D_STD_ memcpy(res.data(), result->get_buffer_pointer(), res.size());

		return res;
	}

	static void 
		make_shader_current(
			_HW_3D_IN_ _Handle_type* handle,
			_HW_3D_IN_ Context* context
		) {
		context->hs_set_shader(handle, {});
	}
};

//
struct _D3d_geometry_shader_helper : _D3d_shader_helper_base {
	using _Handle_type = _HW_3D_D3D_ IGeometry_shader;
	using _Native_handle_type = ID3D11GeometryShader;

	static _HW_3D_STD_ unique_ptr<_Handle_type>
		create_shader(
			_HW_3D_IN_ const _Source_code_type& code,
			_HW_3D_IN_ Device* device
		) {
		auto[success, result] = device->create_geometry_shader(code.data(), code.size(), nullptr);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to create geometry shader");
		
		return _HW_3D_STD_ move(result);
	}

	static _Source_code_type
		file_to_source_code(
			_HW_3D_IN_ const Path& file_name,
			_HW_3D_IN_ const _HW_3D_STD_ string& entry_point,
			_HW_3D_IN_ const _HW_3D_STD_ vector<_Shader_macro_type>& macros
		) {
		assert(macros.empty() || (macros.back().Name == nullptr && macros.back().Definition == nullptr));
		assert(file_name.has_filename());

		_Source_code_type res;

		_HW_3D_D3D_ Compile_constant flag = _HW_3D_D3D_ Compile_constant_bit::enable_strictness;
		auto[success, result] = _HW_3D_D3D_ compile_from_file(file_name.wstring(), macros.data(), entry_point, "gs_5_0", flag);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to compile geometry shader");

		res.resize(result->get_buffer_size());
		_HW_3D_STD_ memcpy(res.data(), result->get_buffer_pointer(), res.size());

		return res;
	}

	static void
		make_shader_current(
			_HW_3D_IN_ _Handle_type* handle,
			_HW_3D_IN_ Context* context
		) {
		context->gs_set_shader(handle, {});
	}
};

//
struct _D3d_pixel_shader_helper : _D3d_shader_helper_base {
	using _Handle_type = _HW_3D_D3D_ IPixel_shader;
	using _Native_handle_type = ID3D11PixelShader;

	static _HW_3D_STD_ unique_ptr<_Handle_type>
		create_shader(
			_HW_3D_IN_ const _Source_code_type& code,
			_HW_3D_IN_ Device* device
		) {
		auto[success, result] = device->create_pixel_shader(code.data(), code.size(), nullptr);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to create pixel shader");

		return _HW_3D_STD_ move(result);
	}

	static _Source_code_type
		file_to_source_code(
			_HW_3D_IN_ const Path& file_name,
			_HW_3D_IN_ const _HW_3D_STD_ string& entry_point,
			_HW_3D_IN_ const _HW_3D_STD_ vector<_Shader_macro_type>& macros
		) {
		assert(macros.empty() || (macros.back().Name == nullptr && macros.back().Definition == nullptr));
		assert(file_name.has_filename());

		_Source_code_type res;

		_HW_3D_D3D_ Compile_constant flag = _HW_3D_D3D_ Compile_constant_bit::enable_strictness;
		auto[success, result] = _HW_3D_D3D_ compile_from_file(file_name.wstring(), macros.data(), entry_point, "ps_5_0", flag);

		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to compile geometry shadre");

		res.resize(result->get_buffer_size());
		_HW_3D_STD_ memcpy(res.data(), result->get_buffer_pointer(), res.size());

		return res;
	}

	static void
		make_shader_current(
			_HW_3D_IN_ _Handle_type* handle,
			_HW_3D_IN_ Context* context
		) {
		context->ps_set_shader(handle, {});
	}
};

///
///shader
template <typename _Shader_helper>
class _TShader {
	static_assert(is_shader_helper_v<_Shader_helper>);
public:
	using Handle_type = typename _Shader_helper::_Handle_type;
	using Native_handle_type = typename _Shader_helper::_Native_handle_type;
	using Source_code_type = typename _Shader_helper::_Source_code_type;
	using Native_helper_type = _Shader_helper;
	using Shader_macro_type = typename _Shader_helper::_Shader_macro_type;
public:
	_TShader(
		_HW_3D_IN_ const Source_code_type& code, 
		_HW_3D_IN_ Render_manager* render_manager
	)	: _source_code(code)
		, _render_manager(render_manager) {
		assert(_render_manager != nullptr);
		_shader = _Shader_helper::create_shader(code, render_manager->native_device());
	}

	Handle_type* 
		handle() const {
		return _shader.get();
	}

	Native_handle_type* 
		native_handle() const {
		return _shader->get();
	}

	const Source_code_type& 
		source_code() const {
		return _source_code;
	}
private:
	_TShader(const _TShader&) = delete;
	_TShader& operator=(const _TShader&) = delete;
private:
	_HW_3D_STD_ unique_ptr<Handle_type> _shader;
	const Source_code_type _source_code;
	Render_manager* const _render_manager;
};

///
///shader builer
template <typename _Shader>
class _TShader_builder {
private:
	using _Shader_macro_names = _HW_3D_STD_ vector<_HW_3D_STD_ string>;
	using _Shader_macro_definitions = _HW_3D_STD_ vector<_HW_3D_STD_ string>;
	using _Shader_macros = _HW_3D_STD_ pair<_Shader_macro_names, _Shader_macro_definitions>;
	using _Source_code_type = typename _Shader::Source_code_type;
	using _Shader_macro_type = typename _Shader::Shader_macro_type;
public:
	_TShader_builder() = default;
	_TShader_builder(const _TShader_builder&) = default;
	_TShader_builder& operator=(const _TShader_builder&) = default;
	_TShader_builder(_TShader_builder&&) = default;
	_TShader_builder& operator=(_TShader_builder&&) = default;

	~_TShader_builder() {}

	_TShader_builder& 
		set_shader_source_file(
			_HW_3D_IN_ const Path& file_name
		) {
		if (auto ext = file_name.extension(); ext != ".cso" && ext != ".hlsl")
			_HW_3D_TRHOW_EXCEPTION_(Error_type::logic, "invalid shader source file type");
		_path = file_name;
		return *this;
	}

	_TShader_builder& 
		set_shader_macro(
			_HW_3D_IN_ const _HW_3D_STD_ string& name, 
			_HW_3D_IN_ const _HW_3D_STD_ string& definition
		) {
		if (auto n_iter = _HW_3D_STD_ find(_macros.first.begin(), _macros.first.end(), name); n_iter == _macros.first.end()) {
			_macros.first.emplace_back(name);
			_macros.second.emplace_back(definition);
		}
		else {
			auto index = n_iter - _macros.first.begin();
			_macros.second.at(index) = definition;
		}
		return *this;
	}

	_TShader_builder& 
		set_shader_entry(
			_HW_3D_IN_ const _HW_3D_STD_ string& entry_point
		) {
		_entry = entry_point;
		return *this;
	}
	
	_HW_3D_STD_ unique_ptr<_Shader>
		create(
			_HW_3D_IN_ Render_manager* render_manager = nullptr
		);
private:
	static _HW_3D_STD_ vector<_Shader_macro_type> 
		_setup_shader_macros(
			_HW_3D_IN_ const _Shader_macros& macros
		) {
		_HW_3D_STD_ vector<_Shader_macro_type> res;
		
		if (!macros.first.empty()) {
			res.resize(macros.first.size() + 1);
			auto n_iter = macros.first.begin();
			auto d_iter = macros.second.begin();
			auto iter = res.begin();
			for (auto e_iter = macros.first.end(); n_iter != e_iter; n_iter++, d_iter++, iter++) {
				iter->Name = n_iter->c_str();
				iter->Definition = d_iter->c_str();
			}
		}
		return res;
	}

	static _Source_code_type _setup_source_code(
		_HW_3D_IN_ const Path& path,
		_HW_3D_IN_ const _HW_3D_STD_ string& entry,
		_HW_3D_IN_ const _HW_3D_STD_ vector<_Shader_macro_type>& macros
	) {
		_Source_code_type res;

		if (path.extension().string() == ".cso") {
#ifdef _HW_3D_LOG_MSG_
			if (!entry.empty() || !macros.empty()) {
				_HW_3D_HW_ Log_manager::get_instance().log_message("set macro and entry is useless for cso file");
			}
#endif
			res = read_binary_file(path);
		}
		else {
			res = (typename _Shader::Native_helper_type)::file_to_source_code(path, entry, macros);
		}
		return res;
	}
private:
	Path _path;
	typename _Shader::Source_code_type _code;
	_Shader_macros _macros;
	_HW_3D_STD_ string _entry_;
};

//
template <typename _Shader>
_HW_3D_STD_ unique_ptr<_Shader> _TShader_builder<_Shader>::create(_HW_3D_IN_ Render_manager* render_manager) {
	auto macros = _setup_shader_macros(_macros);
	_code = _setup_source_code(_path, _entry, macros);
	
	render_manager = render_manager == nullptr ? Render_manager::current_render_manager() : render_manager;
	if (render_manager == nullptr)
		_HW_3D_TRHOW_EXCEPTION_(Error_type::logic, "try to create shader without hardware"); 

	return _HW_3D_STD_ make_unique<_Shader>(_code, render_manager);
}

using Vertex_shader = _TShader<_D3d_vertex_shader_helper>;
using Compute_shader = _TShader<_D3d_compute_shader_helper>;
using Geometry_shader = _TShader<_D3d_geometry_shader_helper>;
using Hull_shader = _TShader<_D3d_hull_shader_helper>;
using Domain_shader = _TShader<_D3d_domain_shader_helper>;
using Pixel_shader = _TShader<_D3d_pixel_shader_helper>;

using Vertex_shader_builder = _TShader_builder<Vertex_shader>;
using Compute_shader_builder = _TShader_builder<Compute_shader>;
using Geometry_shader_builder = _TShader_builder<Geometry_shader>;
using Hull_shader_builder = _TShader_builder<Hull_shader>;
using Domain_shader_builder = _TShader_builder<Domain_shader>;
using Pixel_shader_builder = _TShader_builder<Pixel_shader>;

_HW_3D_CLOSE_RS_NAMESPACE_

_HW_3D_CLOSE_HW_NAMESPACE_
