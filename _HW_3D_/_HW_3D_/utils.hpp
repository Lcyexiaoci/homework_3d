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
_HW_3D_INLINE_VARIABLE_ _Ty* _Singleton<_Ty>::_instance = nullptr;

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

///
///
///
///helper function
_HW_3D_INLINE_FUNCTION_ _HW_3D_STD_ vector<_HW_3D_STD_ byte>
read_binary_file(
	_HW_3D_IN_ const Path& path
) {
	_HW_3D_STD_ vector<_HW_3D_STD_ byte> res;

	if (!path.has_filename())
		return res;

	if (_HW_3D_STD_ ifstream ifs(path.wstring(), _HW_3D_STD_ ios::binary | _HW_3D_STD_ ios::ate); ifs.is_open()) {
		auto length = ifs.tellg();
		res.resize(length);

		ifs.seekg(0, _HW_3D_STD_ ios::beg);
		ifs.read(reinterpret_cast<char*>(res.data()), length);
		ifs.close();
	}

	return res;
}

_HW_3D_CLOSE_HW_NAMESPACE_