#pragma once

#include "rs_fwd.h"
#include "../d3d/d3d_func.hpp"




_HW_3D_OPEN_HW_NAMESPACE_

_HW_3D_OPEN_RS_NAMESPACE_
///
///
///struct 

//
//
template <typename _Ty, _HW_3D_STD_ size_t _Dim>
class _TData_array : public _HW_3D_STD_ array<_Ty, _Dim> {
	static_assert(_HW_3D_STD_ is_arithmetic_v<_Ty>);
public:
	static constexpr _HW_3D_STD_ size_t dimension = _Dim;
public:
	constexpr _TData_array() {
		_HW_3D_STD_ memset(this->data(), 0, this->size() * sizeof(_Ty));
	}

	template <
		typename _Other, 
		_HW_3D_STD_ size_t _Other_dim,
		typename = _HW_3D_STD_ enable_if_t<(_Other_dim <= _Dim && _HW_3D_STD_ is_assignable_v<_Ty&, _Other>)>>
		explicit constexpr _TData_array(const _TData_array<_Other, _Other_dim>& other)
		: _TData_array() {
		if constexpr (_HW_3D_STD_ is_same_v<_Ty, _Other>) {
			_HW_3D_STD_ memcpy(this->data(), other.data(), sizeof(_Ty) * _Other_dim);
		}
		else {
			for (uint32_t i = 0; i != _Other_dim; i++)
				this->at(i) = other.at(i);
		}
	}

	template <
		typename ... _Args,
		typename = _HW_3D_STD_ enable_if_t<((sizeof...(_Args) <= _Dim) && _HW_3D_STD_ conjunction_v<_HW_3D_STD_ is_assignable<_Ty&, _Args>...>)>>
		explicit constexpr _TData_array(_Args&&... args)
		: _TData_array() {
		auto iter = this->begin();
		((*iter++ = _HW_3D_STD_ forward<_Args>(args)), ...);
	}

	template <
		_HW_3D_STD_ size_t _Index,
		typename = _HW_3D_STD_ enable_if_t<(_Index < _Dim)>>
		auto& get() & {
		return this->at(_Index);
	}

	template <
		_HW_3D_STD_ size_t _Index,
		typename = _HW_3D_STD_ enable_if_t<(_Index < _Dim)>>
		const auto& get() const & {
		return this->at(_Index);
	}

	template <
		_HW_3D_STD_ size_t _Index,
		typename = _HW_3D_STD_ enable_if_t<(_Index < _Dim)>>
		auto&& get() && {
		return this->at(_Index);
	}
};

//
//
template <typename _Ty, _HW_3D_STD_ size_t _Dim>
class _TOffset : public _TData_array<_Ty, _Dim> {
	static_assert(_Dim > 0 && _Dim < 4);

	using _My_base = _TData_array<_Ty, _Dim>;
public:
	using _My_base::_My_base;
	using _My_base::get;

	void set_x(_Ty x) {
		this->at(0) = x;
	}

	template <
		_HW_3D_STD_ size_t Dim = _Dim, 
		typename = _HW_3D_STD_ enable_if_t<(Dim > 1)>>
		void set_y(_Ty y) {
		this->at(1) = y;
	}

	template <
		_HW_3D_STD_ size_t Dim = _Dim,
		typename = _HW_3D_STD_ enable_if_t<(Dim > 2)>>
		void set_z(_Ty z) {
		this->at(2) = z;
	}

	_Ty get_x() const {
		return this->at(0);
	}

	template <
		_HW_3D_STD_ size_t Dim = _Dim,
		typename = _HW_3D_STD_ enable_if_t<(Dim > 1)>>
		_Ty get_y() const {
		return this->at(1);
	}

	template <
		_HW_3D_STD_ size_t Dim = _Dim,
		typename = _HW_3D_STD_ enable_if_t<(Dim > 2)>>
		_Ty get_z() const {
		return this->at(2);
	}

	__declspec(property(put = set_x, get = get_x)) _Ty x;
	__declspec(property(put = set_y, get = get_y)) _Ty y;
	__declspec(property(put = set_z, get = get_z)) _Ty z;
};

template <typename _Ty, _HW_3D_STD_ size_t _Dim>
struct _HW_3D_STD_ tuple_size<_TOffset<_Ty, _Dim>> : public  _HW_3D_STD_ integral_constant<_HW_3D_STD_ size_t, _Dim> {};

template <_HW_3D_STD_ size_t _Index, typename _Ty, _HW_3D_STD_ size_t _Dim>
struct _HW_3D_STD_ tuple_element<_Index, _TOffset<_Ty, _Dim>> {
	static_assert(_Index < _Dim);
	using type = _Ty;
};

template <typename _Ty, _HW_3D_STD_ size_t _Dim>
bool operator==(_TOffset<_Ty, _Dim> lhs, _TOffset<_Ty, _Dim> rhs) noexcept {
	return _HW_3D_STD_ memcmp(_HW_3D_STD_ addressof(lhs), _HW_3D_STD_ addressof(rhs), sizeof(lhs)) == 0;
}

template <typename _Ty, _HW_3D_STD_ size_t _Dim>
bool operator!=(_TOffset<_Ty, _Dim> lhs, _TOffset<_Ty, _Dim> rhs) noexcept {
	return !(lhs == rhs);
}

using Offset1d = _TOffset<uint32_t, 1>;
using Offset2d = _TOffset<uint32_t, 2>;
using Offset3d = _TOffset<uint32_t, 3>;


//
//
template <typename _Ty, _HW_3D_STD_ size_t _Dim>
class _TExtent : public _TData_array<_Ty, _Dim> {
	static_assert(_Dim > 0 && _Dim < 4);

	using _My_base = _TData_array<_Ty, _Dim>;
public:
	using _My_base::_My_base;
	using _My_base::get;

	void set_width(_Ty width) {
		this->at(0) = width;
	}

	template <
		_HW_3D_STD_ size_t Dim = _Dim,
		typename = _HW_3D_STD_ enable_if_t<(Dim > 1)>>
		void set_height(_Ty height) {
		this->at(1) = height;
	}

	template <
		_HW_3D_STD_ size_t Dim = _Dim,
		typename = _HW_3D_STD_ enable_if_t<(Dim > 2)>>
		void set_depth(_Ty depth) {
		this->at(2) = depth;
	}

	_Ty get_width() const {
		return this->at(0);
	}

	template <
		_HW_3D_STD_ size_t Dim = _Dim,
		typename = _HW_3D_STD_ enable_if_t<(Dim > 1)>>
		_Ty get_height() const {
		return this->at(1);
	}

	template <
		_HW_3D_STD_ size_t Dim = _Dim,
		typename = _HW_3D_STD_ enable_if_t<(Dim > 2)>>
		_Ty get_depth() const {
		return this->at(2);
	}

	__declspec(property(get = get_width, put = set_width)) _Ty width;
	__declspec(property(get = get_height, put = set_height)) _Ty height;
	__declspec(property(get = get_depth, put = set_depth)) _Ty depth;
};

template <typename _Ty, _HW_3D_STD_ size_t _Dim>
struct _HW_3D_STD_ tuple_size<_TExtent<_Ty, _Dim>> : public _HW_3D_STD_ integral_constant<_HW_3D_STD_ size_t, _Dim> {};

template <_HW_3D_STD_ size_t _Index, typename _Ty, _HW_3D_STD_ size_t _Dim>
struct _HW_3D_STD_ tuple_element<_Index, _TExtent<_Ty, _Dim>> {
	static_assert(_Index < _Dim);
	using type = _Ty;
};

template <typename _Ty, _HW_3D_STD_ size_t _Dim>
bool operator==(_TExtent<_Ty, _Dim> lhs, _TExtent<_Ty, _Dim> rhs) noexcept {
	return _HW_3D_STD_ memcmp(_HW_3D_STD_ addressof(lhs), _HW_3D_STD_ addressof(rhs), sizeof(rhs)) == 0;
}

template <typename _Ty, _HW_3D_STD_ size_t _Dim>
bool operator!=(_TExtent<_Ty, _Dim> lhs, _TExtent<_Ty, _Dim> rhs) noexcept {
	return !(lhs == rhs);
}

using Extent1d = _TExtent<uint32_t, 1>;
using Extent2d = _TExtent<uint32_t, 2>;
using Extent3d = _TExtent<uint32_t, 3>;

template <typename _Ty, _HW_3D_STD_ size_t _Dim>
struct _TRange {
	static_assert(_Dim > 0 && _Dim < 4 && alignof(_Ty) == alignof(_TOffset<_Ty, _Dim>) && alignof(_Ty) == alignof(_TExtent<_Ty, _Dim>));

	_TOffset<_Ty, _Dim> offset;
	_TExtent<_Ty, _Dim> extent;

	_TRange() = default;
	_TRange(const _TRange&) = default;
	_TRange& operator=(const _TRange&) = default;

	template <
		typename _Offset_other_type, 
		typename _Extent_other_type,
		_HW_3D_STD_ size_t _Offset_other_dim, 
		_HW_3D_STD_ size_t _Extent_other_dim,
		typename = _HW_3D_STD_ enable_if_t<
			(_HW_3D_STD_ is_constructible_v<_TOffset<_Ty, _Dim>, const _TOffset<_Offset_other_type, _Offset_other_dim> &> && 
			_HW_3D_STD_ is_constructible_v<_TExtent<_Ty, _Dim>, const _TExtent<_Extent_other_type, _Extent_other_dim> &>)>>
		_TRange(
			const _TOffset<_Offset_other_type, _Offset_other_dim>& offset_,
			const _TExtent<_Extent_other_type, _Extent_other_dim>& extent_
		) : offset(offset_)
		, extent(extent_) {
	}

	template <
		typename... _Args, 
		_HW_3D_STD_ enable_if_t<((sizeof...(_Args)) == 2 * _Dim 
			&& _HW_3D_STD_ conjunction_v<_HW_3D_STD_ is_assignable<_Ty&, _Args>...>), int> = 0>
	_TRange(_Args&&... args) {
		auto ptr = _HW_3D_STD_ addressof(*offset.begin());
		((*ptr++ = _HW_3D_STD_ forward<_Args>(args)), ...);
	}

	template <
		_HW_3D_STD_ size_t _Index, 
		typename = _HW_3D_STD_ enable_if_t<(_Index < 2)>>
	auto& get() & {
		if constexpr (_Index == 0) {
			return offset;
		}
		else {
			return extent;
		}
	}

	template <
		_HW_3D_STD_ size_t _Index, 
		typename = _HW_3D_STD_ enable_if_t<(_Index < 2)>>
	const auto& get() const & {
		if constexpr (_Index == 0) {
			return offset;
		}
		else {
			return extent;
		}
	}

	template <
		_HW_3D_STD_ size_t _Index,
		typename = _HW_3D_STD_ enable_if_t<(_Index < 2)>>
		auto&& get() && {
		if constexpr (_Index == 0) {
			return offset;
		}
		else {
			return extent;
		}
	}

};

template <typename _Ty, _HW_3D_STD_ size_t _Dim>
struct _HW_3D_STD_ tuple_size<_TRange<_Ty, _Dim>> : public _HW_3D_STD_ integral_constant<_HW_3D_STD_ size_t, 2> {};

template <typename _Ty, _HW_3D_STD_ size_t _Dim>
struct _HW_3D_STD_ tuple_element<0, _TRange<_Ty, _Dim>> { 
	using type = _HW_3D_RS_ _TOffset<_Ty, _Dim>; 
};

template <typename _Ty, _HW_3D_STD_ size_t _Dim>
struct _HW_3D_STD_ tuple_element<1, _TRange<_Ty, _Dim>> {
	using type = _HW_3D_RS_ _TExtent<_Ty, _Dim>;
};

template <typename _Ty, _HW_3D_STD_ size_t _Dim>
bool operator==(const _TRange<_Ty, _Dim>& lhs, const _TRange<_Ty, _Dim>& rhs) noexcept {
	return (lhs.offset == rhs.offset)
		&& (lhs.extent == rhs.extent);
}

template <typename _Ty, _HW_3D_STD_ size_t _Dim>
bool operator!=(const _TRange<_Ty, _Dim>& lhs, const _TRange<_Ty, _Dim>& rhs) noexcept {
	return !(lhs == rhs);
}

using Range1d = _TRange<uint32_t, 1>;
using Range2d = _TRange<uint32_t, 2>;
using Range3d = _TRange<uint32_t, 3>;

///
///
///helper function

//transfer <offset, extent> to Box
_HW_3D_INLINE_FUNCTION_ Box transfer_to_box(Offset1d offset, Extent1d extent) {
	Box res;

	res.left = offset.x;
	res.right = offset.x + extent.width;
	res.top = 0;
	res.bottom = 1;
	res.front = 0;
	res.back = 1;

	return res;
}

_HW_3D_INLINE_FUNCTION_ Box transfer_to_box(Offset2d offset, Extent2d extent) {
	Box res;

	res.left = offset.x;
	res.right = offset.x + extent.width;
	res.top = offset.y;
	res.bottom = offset.y + extent.height;
	res.front = 0;
	res.back = 1;

	return res;
}

_HW_3D_INLINE_FUNCTION_ Box transfer_to_box(Offset3d offset, Extent3d extent) {
	Box res;

	res.left = offset.x;
	res.right = offset.x + extent.width;
	res.top = offset.y;
	res.bottom = offset.y + extent.height;
	res.front = offset.z;
	res.back = offset.z + extent.depth;

	return res;
}

_HW_3D_INLINE_FUNCTION_ Box transfer_to_box(const Range1d& range) {
	return transfer_to_box(range.offset, range.extent);
}

_HW_3D_INLINE_FUNCTION_ Box transfer_to_box(const Range2d& range) {
	return transfer_to_box(range.offset, range.extent);
}

_HW_3D_INLINE_FUNCTION_ Box transfer_to_box(const Range3d& range) {
	return transfer_to_box(range.offset, range.extent);
}

_HW_3D_INLINE_FUNCTION_ uint32_t get_mipmaps_length(uint32_t length0, uint32_t level) {
	return length0 >> level;
}

_HW_3D_INLINE_FUNCTION_ uint32_t get_max_level(uint32_t length) {
	uint32_t res;
	while (length >> res) res++;
	return res;
}

_HW_3D_INLINE_FUNCTION_ uint32_t get_mip_levels(Extent1d size) {
	return get_max_level(size.width);
}

_HW_3D_INLINE_FUNCTION_ uint32_t get_mip_levels(Extent2d size) {
	uint32_t res = get_max_level(size.width);
	return (_HW_3D_STD_ max)(res, get_max_level(size.height));
}

_HW_3D_INLINE_FUNCTION_ uint32_t get_mip_levels(Extent3d size) {
	uint32_t res = get_max_level(size.width);
	res = (_HW_3D_STD_ max)(res, get_max_level(size.height));
	return (_HW_3D_STD_ max)(res, get_max_level(size.depth));
}

///
///
/// type function
template <typename _Shader_helper, typename = _HW_3D_STD_ void_t<>>
struct Is_shader_helper : public _HW_3D_STD_ false_type {

};

template <typename _Shader_helper>
struct Is_shader_helper <
	_Shader_helper,
	_HW_3D_STD_ void_t<
	typename _Shader_helper::_Handle_type,
	typename _Shader_helper::_Native_handle_type,
	typename _Shader_helper::_Source_code_type,
	typename _Shader_helper::_Shader_macro_type,
	decltype(
		_Shader_helper::create_shader(
			_HW_3D_STD_ declval<const typename _Shader_helper::_Source_code_type &>(),
			_HW_3D_STD_ declval<Native_device*>())),
	decltype(
		_Shader_helper::file_to_source_code(
			_HW_3D_STD_ declval<const _HW_3D_HW_ Path&>(),
			_HW_3D_STD_ declval<const _HW_3D_STD_ string&>(),
			_HW_3D_STD_ declval<const _HW_3D_STD_ vector<typename _Shader_helper::_Shader_macro_type>&>())),
	decltype(
		_Shader_helper::make_shader_current(
			_HW_3D_STD_ declval<typename _Shader_helper::_Handle_type *>(),
			_HW_3D_STD_ declval<Native_context*>()))
	>> : public _HW_3D_STD_ true_type {

};

template <typename _Shader_helper> 
constexpr bool is_shader_helper_v = Is_shader_helper<_Shader_helper>::value;

_HW_3D_CLOSE_RS_NAMESPACE_

_HW_3D_CLOSE_HW_NAMESPACE_



constexpr _HW_3D_STD_ size_t a = _HW_3D_STD_ tuple_size_v<_HW_3D_RS_ Offset1d>;
constexpr _HW_3D_STD_ tuple_element_t<0, _HW_3D_RS_ Offset1d> b = 1;