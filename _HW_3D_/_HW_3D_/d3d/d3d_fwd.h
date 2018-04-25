#pragma once


#include "../fwd.h"
#include "../utils.hpp"

#define _HW_3D_D3D_		_HW_3D_HW_ d3d::
#define _HW_3D_DXGI_	_HW_3D_HW_ dxgi::

#define _HW_3D_OPEN_D3D_NAMESPACE_		namespace d3d {
#define _HW_3D_CLOSE_D3D_NAMESPACE_		}

#define _HW_3D_OPEN_DXGI_NAMESPACE_		namespace dxgi {
#define _HW_3D_CLOSE_DXGI_NAMESPACE_	}



//struct
#define _HW_3D_D3D_STRUCT_WRAPPER_(Wrapper, D3d_type)							\
	Wrapper() {}																\
																				\
	Wrapper(const Wrapper& other) {												\
		_HW_3D_STD_ memcpy(this, &other, sizeof(*this));						\
	}																			\
																				\
	Wrapper& operator=(const Wrapper& other) {									\
		_HW_3D_STD_ memcpy(this, &other, sizeof(*this));						\
	}																			\
																				\
	operator const D3d_type&() const {											\
		return *reinterpret_cast<const D3d_type*>(this);						\
	}																			\
																				\
	operator D3d_type&() {														\
		return *reinterpret_cast<D3d_type*>(this);								\
	}																			\
																				\
	const D3d_type* value_ptr() const {											\
		return reinterpret_cast<const D3d_type*>(this);							\
	}																			\
																				\
	D3d_type* value_ptr() {														\
		return reinterpret_cast<D3d_type*>(this);								\
	}

//property
#define _HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(variable, Type, name)				\
	auto set ##variable(Type variable ##_v) {									\
		variable = _HW_3D_STD_ move(variable ##_v);								\
		return (*this);															\
	}																			\
																				\
	Type get ##variable() const noexcept {										\
		return variable;														\
	}																			\
																				\
	__declspec(property(get = get ##variable, put = set ##variable)) Type name

#define _HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(variable, Type, name)		\
	Type get ##variable() const noexcept {										\
		return variable;														\
	}																			\
																				\
	__declspec(property(get = get ##variable)) Type name
	

//bool
#ifndef True
#define True TRUE
#endif

#ifndef False
#define False FALSE
#endif
