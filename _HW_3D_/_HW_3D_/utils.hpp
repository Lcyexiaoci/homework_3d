#pragma once

/*
define basic utility types need for whole projects
*/

#include "fwd.h"

_HW_3D_OPEN_HW_NAMESPACE_

///
///
///
///type template 

//default all flag bit or result, specifyed by each type
template <typename Bit_type>
struct Flag_traits {
	enum {
		all_flags = 0
	};
};

//flag template 
template <typename Bit_type, typename Mask_type>
class Flags final {
	//require
	static_assert(_HW_3D_STD_ is_integral_v<Mask_type>);

public: // type define
	using bit_type = Bit_type;
	using mask_type = Mask_type;

private:
	using _My_traits = Flag_traits<bit_type>;

public:
	constexpr Flags() : _mask(0) {}

	constexpr Flags(bit_type bit) : _mask(static_cast<mask_type>(bit)) {}

	Flags(const Flags& other) : _mask(other._mask) {}

	/*operator overload*/

	Flags& operator=(const Flags& rhs) noexcept {
		_mask = rhs._mask;
		return (*this);
	}

	Flags& operator|=(const Flags& rhs) noexcept {
		_mask |= rhs._mask;
		return (*this);
	}

	Flags& operator&=(const Flags& rhs) noexcept {
		_mask &= rhs._mask;
		return (*this);
	}

	Flags& operator^=(const Flags& rhs) noexcept {
		_mask ^= rhs._mask;
		return (*this);
	}

	Flags operator|(const Flags& rhs) const noexcept {
		Flags res{ *this };
		res |= rhs;
		return res;
	}

	Flags operator&(const Flags& rhs) const noexcept {
		Flags res{ *this };
		res &= rhs;
		return res;
	}

	Flags& operator^(const Flags& rhs) const noexcept {
		Flags res{ *this };
		res ^= rhs;
		return res;
	}

	bool operator!() const noexcept {
		return !_mask;
	}

	Flags operator~() const noexcept {
		Flags res{ *this };
		res._mask ^= _My_traits::all_flags;
	}

	bool operator==(const Flags& rhs) const noexcept {
		return _mask == rhs._mask;
	}

	bool operator!=(const Flags& rhs) const noexcept {
		return _mask != rhs._mask;
	}

	/*type conversion*/

	explicit operator bool() const noexcept {
		return _mask != 0;
	}

	explicit operator mask_type() const noexcept {
		return _mask;
	}
private:
	mask_type _mask;
};

template <typename Bit_type, typename Mask_type>
Flags<Bit_type, Mask_type> operator|(Bit_type bit, const Flags<Bit_type, Mask_type>& flags) {
	return flags | bit;
}

template <typename Bit_type, typename Mask_type>
Flags<Bit_type, Mask_type> operator&(Bit_type bit, const Flags<Bit_type, Mask_type>& flags) {
	return flags & bit;
}

template <typename Bit_type, typename Mask_type>
Flags<Bit_type, Mask_type> operator^(Bit_type bit, const Flags<Bit_type, Mask_type>& flags) {
	return flags ^ bit;
}

//compressed pair
struct Zero_first_other_second_tag_t {};

struct One_first_other_second_tag_t {};

template <typename Ty1, 
	typename Ty2, 
	bool = std::is_empty<Ty1>::value && !std::is_final<Ty1>::value> //if Ty1 is empty and could inherent from
class Compressed_pair final : public Ty1 {
private:
	Ty2 _my_val2;

	using _My_base = Ty1;
public:
	template <typename... Args2>
	constexpr explicit Compressed_pair(
		Zero_first_other_second_tag_t,
		Args2&&... args2)
		: Ty1()
		, _my_val2(std::forward<Args2>(args2)...) {
	}


	template <typename Args1, typename... Args2>
	Compressed_pair(
		One_first_other_second_tag_t,
		Args1&& args1,
		Args2&&... args2)
		: Ty1(std::forward<Args1>(args1))
		, _my_val2(std::forward<Args2>(args2)...) {
	}

	Ty1& first() noexcept {
		return (*this);
	}

	const Ty1& first() const noexcept {
		return (*this);
	}

	volatile Ty1& first() volatile noexcept {
		return (*this);
	}

	const volatile Ty1& first() const volatile noexcept {
		return (*this);
	}

	Ty2& second() noexcept {
		return (_my_val2);
	}

	const Ty2& second() const noexcept {
		return (_my_val2);
	}

	volatile Ty2& second() volatile noexcept {
		return (_my_val2);
	}

	const volatile Ty2& second() const volatile noexcept {
		return (_my_val2);
	}
};

template <
	typename Ty1,
	typename Ty2>
class Compressed_pair<Ty1, Ty2, false> final {
private:
	Ty1 _my_val1;
	Ty2 _my_val2;
public:
	template <typename... Args2>
	constexpr explicit Compressed_pair(
		Zero_first_other_second_tag_t,
		Args2&&... args2)
		: _my_val1()
		, _my_val2(std::forward<Args2>(args2)...) {

	}

	template <typename Args1, typename... Args2>
	Compressed_pair(
		One_first_other_second_tag_t,
		Args1&& args1,
		Args2&&... args2)
		: _my_val1(std::forward<Args1>(args1))
		, _my_val2(std::forward<Args2>(args2)...) {
	}

	Ty1& first() noexcept {
		return (_my_val1);
	}

	const Ty1& first() const noexcept {
		return (_my_val1);
	}

	volatile Ty1& first() volatile noexcept {
		return (_my_val1);
	}

	const volatile Ty1& first() const volatile noexcept {
		return (_my_val1);
	}

	Ty2& second() noexcept {
		return (_my_val2);
	}

	const Ty2& second() const noexcept {
		return (_my_val2);
	}

	volatile Ty2& second() volatile noexcept {
		return (_my_val2);
	}

	const volatile Ty2& second() const volatile noexcept {
		return (_my_val2);
	}
};

//allocator wrapper
template <typename Alloc_type>
struct Alloc_wrapper : Alloc_type {
	//type alias
	using _My_base = Alloc_type;
	using _My_traits = std::allocator_traits<Alloc_type>;

	using value_type = typename _My_traits::value_type;
	using pointer = typename _My_traits::pointer;
	using const_pointer = typename _My_traits::const_pointer;
	using void_pointer = typename _My_traits::void_pointer;
	using const_void_pointer = typename _My_traits::const_void_pointer;

	using reference = typename std::conditional<
		std::is_void<value_type>::value,
		int,
		value_type>::type&;
	using const_reference = typename std::conditional <
		std::is_void<const value_type>::value,
		const int,
		const value_type>::type&;

	using size_type = typename _My_traits::size_type;
	using difference_type = typename _My_traits::difference_type;

	using propagate_on_container_copy_assignment = typename _My_traits::propagate_on_container_copy_assignment;
	using propagate_on_container_move_assignment = typename _My_traits::propagate_on_container_move_assignment;
	using propagate_on_container_swap = typename _My_traits::propagate_on_container_swap;
	using is_always_equal = typename _My_traits::is_always_equal;

	Alloc_wrapper select_on_container_copy_construction(/*unused*/) const {
		return (_My_traits::select_on_container_copy_construction(*this));
	}

	template <typename Other_type>
	struct rebind {
		using Other_alloc_type = typename _My_traits::template rebind_alloc<Other_type>;
		using other = Alloc_wrapper<Other_alloc_type>;
	};

	pointer address(reference value) const {
		return (std::pointer_traits<pointer>::pointer_to(value));
	}

	const_pointer address(const_reference value) const {
		return (std::pointer_traits<const_pointer>::pointer_to(value));
	}

	Alloc_wrapper() noexcept(std::is_nothrow_default_constructible<Alloc_type>::value)
		: _My_base() {

	}

	Alloc_wrapper(const Alloc_wrapper& other) noexcept(std::is_nothrow_copy_constructible<Alloc_type>::value)
		: _My_base(other) {

	}

	Alloc_wrapper(Alloc_wrapper&& other) noexcept(std::is_nothrow_move_constructible<Alloc_type>::value)
		: _My_base(std::move(other)) {

	}

	template <
		typename Other_alloc_type,
		typename = typename std::enable_if<!std::is_same<Alloc_wrapper, typename std::decay<Other_alloc_type>::type>::value>::type>
		Alloc_wrapper(Other_alloc_type&& other)
		: _My_base(std::forward<Other_alloc_type>(other)) {

	}

	Alloc_wrapper& operator=(const Alloc_wrapper& other) noexcept(std::is_nothrow_copy_assignable<Alloc_type>::value) {
		_My_base::operator=(other);
		return (*this);
	}

	Alloc_wrapper& operator=(Alloc_wrapper&& other) noexcept(std::is_nothrow_move_assignable<Alloc_type>::value) {
		_My_base::operator=(std::move(other));
		return (*this);
	}

	template <
		typename Other_alloc_type,
		typename = typename std::enable_if<!std::is_same<Alloc_wrapper, typename std::decay<Other_alloc_type>::type>::value>::type>
		Alloc_wrapper& operator=(Other_alloc_type&& other) {
		_My_base::operator=(std::forward<Other_alloc_type>(other));
		return (*this);
	}

	pointer allocate(size_type count) {
		return (_My_base::allocate(count));
	}

	pointer allocate(size_type count, const_void_pointer hint) {
		return (_My_traits::allocate(*this, count, hint));
	}

	void deallocate(pointer ptr, size_type count) {
		_My_base::deallocate(ptr, count);
	}

	template <typename Ty, typename... Args>
	void construct(Ty* ptr, Args&&... args) {
		_My_traits::construct(*this, ptr, std::forward<Args>(args)...);
	}

	template <typename Ty>
	void destroy(Ty* ptr) {
		_My_traits::destroy(*this, ptr);
	}

	size_type max_size() const noexcept {
		return (_My_traits::max_size(*this));
	}
};

template <typename Ty, typename Other>
inline bool operator==(const Alloc_wrapper<Ty>& lhs, const Alloc_wrapper<Other>& rhs) noexcept {
	return (static_cast<const Ty&>(lhs) == static_cast<const Other&>(rhs));
}

template <typename Ty, typename Other>
inline bool operator!=(const Alloc_wrapper<Ty>& lhs, const Alloc_wrapper<Other>& rhs) noexcept {
	return (!(lhs == rhs));
}

///
///
///
/// design pattern

//singleton
template <typename _Ty>
class _Singleton {
public:
	_Singleton() {
		assert(_instance == nullptr);
		_instance = static_cast<_Ty*>(this);
	}

	~_Singleton() {
		assert(_instance != nullptr);
		_instance = nullptr;
	}

	static _Ty& get_instance() {
		assert(_instance != nullptr);
		return *_instance;
	}
private:
	_Singleton(const _Singleton&) = delete;
	_Singleton& operator=(const _Singleton&) = delete;
	_Singleton(_Singleton&&) = delete;
	_Singleton& operator=(_Singleton&&) = delete;
protected:
	static _Ty* _instance;
};

template <typename _Ty>
inline _Ty* _Singleton<_Ty>::_instance = nullptr;

///
///
///
/// type function
template <typename Ty, bool = _HW_3D_STD_ is_enum_v<Ty>>
struct Underlying_type {
	using type = Ty;
};

template <typename Ty> 
struct Underlying_type<Ty, true> {
	using type = _HW_3D_STD_ underlying_type_t<Ty>;
};

template <typename Ty>
using Underlying_type_t = typename Underlying_type<Ty>::type;

_HW_3D_CLOSE_HW_NAMESPACE_