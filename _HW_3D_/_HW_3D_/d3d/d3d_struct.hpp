#pragma once

#include "d3d_fwd.h"
#include "d3d_enum.h"
#include "d3d_flag.hpp"

_HW_3D_OPEN_HW_NAMESPACE_

_HW_3D_OPEN_DXGI_NAMESPACE_

//
//
class  Color_value {
	float _r{ 0.0f };
	float _g{ 0.0f };
	float _b{ 0.0f };
	float _a{ 1.0f };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Color_value, D3DCOLORVALUE)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_r, float, r);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_g, float, g);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_b, float, b);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_a, float, a);
};
static_assert(sizeof(Color_value) == sizeof(D3DCOLORVALUE));

inline bool operator==(const Color_value& lhs, const Color_value& rhs) noexcept {
	return (lhs.r == rhs.r)
		&& (lhs.g == rhs.g)
		&& (lhs.b == rhs.b)
		&& (lhs.a == rhs.a);
}

inline bool operator!=(const Color_value& lhs, const Color_value& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Rational {
	UINT _numerator{ 0 };
	UINT _denominator{ 1 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Rational, DXGI_RATIONAL)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_numerator, UINT, Numerator);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_denominator, UINT, Denominator);
};
static_assert(sizeof(Rational) == sizeof(DXGI_RATIONAL));

inline bool operator==(const Rational& lhs, const Rational& rhs) noexcept { //assert gcd(n, d) == 1
	return ((lhs.Numerator == rhs.Numerator)
		&& (lhs.Denominator == rhs.Denominator));
}

inline bool operator!=(const Rational& lhs, const Rational& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Rgb {
	float _red{ 0.0f };
	float _green{ 0.0f };
	float _blue{ 0.0f };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Rgb, DXGI_RGB)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_red, float, Red);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_green, float, Green);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_blue, float, Blue);
};
static_assert(sizeof(Rgb) == sizeof(DXGI_RGB));

inline bool operator==(const Rgb& lhs, const Rgb& rhs) noexcept {
	return (lhs.Red == rhs.Red)
		&& (lhs.Green == rhs.Green)
		&& (lhs.Blue == rhs.Blue);
}

inline bool operator!=(const Rgb& lhs, const Rgb& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Rgba {
	float _r{ 0.0f };
	float _g{ 0.0f };
	float _b{ 0.0f };
	float _a{ 1.0f };
public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Rgba, DXGI_RGBA)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_r, float, r);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_g, float, g);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_b, float, b);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_a, float, a);
};
static_assert(sizeof(Rgba) == sizeof(DXGI_RGBA));

inline bool operator==(const Rgba& lhs, const Rgba& rhs) noexcept {
	return (lhs.r == rhs.r)
		&& (lhs.g == rhs.g)
		&& (lhs.b == rhs.b)
		&& (lhs.a == rhs.a);
}

inline bool operator!=(const Rgba& lhs, const Rgba& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Adapter_desc {
	_HW_3D_STD_ array<WCHAR, 128> _description{};
	UINT _vendor_id{ 0 };
	UINT _device_id{ 0 };
	UINT _sub_sys_id{ 0 };
	UINT _revision{ 0 };
	SIZE_T _dedicated_video_memory{ 0 };
	SIZE_T _dedicated_system_memory{ 0 };
	SIZE_T _shared_system_memory{ 0 };
	LUID _adapter_luid{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Adapter_desc, DXGI_ADAPTER_DESC)
public:
	const _HW_3D_STD_ array<WCHAR, 128>& get_description() const noexcept {
		return _description;
	}

	__declspec(property(get = get_description)) const _HW_3D_STD_ array<WCHAR, 128>& Description;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_vendor_id, UINT, VendorId);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_device_id, UINT, DeviceId);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_sub_sys_id, UINT, SubSysId);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_revision, UINT, Revision);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_dedicated_video_memory, SIZE_T, DedicatedVideoMemory);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_dedicated_system_memory, SIZE_T, DedicatedSystemMemory);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_shared_system_memory, SIZE_T, SharedSystemMemory);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_adapter_luid, LUID, AdapterLuid);
};
static_assert(sizeof(Adapter_desc) == sizeof(DXGI_ADAPTER_DESC));

inline bool operator==(const Adapter_desc& lhs, const Adapter_desc& rhs) noexcept {
	return (lhs.Description == rhs.Description)
		&& (lhs.VendorId == rhs.VendorId)
		&& (lhs.DeviceId == rhs.DeviceId)
		&& (lhs.SubSysId == rhs.SubSysId)
		&& (lhs.Revision == rhs.Revision)
		&& (lhs.DedicatedVideoMemory == rhs.DedicatedVideoMemory)
		&& (lhs.DedicatedSystemMemory == rhs.DedicatedSystemMemory)
		&& (lhs.SharedSystemMemory == rhs.SharedSystemMemory)
		&& (lhs.AdapterLuid.LowPart == rhs.AdapterLuid.LowPart)
		&& (lhs.AdapterLuid.HighPart == rhs.AdapterLuid.HighPart);
}

inline bool operator!=(const Adapter_desc& lhs, const Adapter_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Adapter_desc1 {
	_HW_3D_STD_ array<WCHAR, 128> _description{};
	UINT _vendor_id{ 0 };
	UINT _device_id{ 0 };
	UINT _sub_sys_id{ 0 };
	UINT _revision{ 0 };
	SIZE_T _dedicated_video_memory{ 0 };
	SIZE_T _dedicated_system_memory{ 0 };
	SIZE_T _shared_system_memory{ 0 };
	LUID _adapter_luid{ 0 };
	UINT _flags{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Adapter_desc1, DXGI_ADAPTER_DESC1)
public:
	const _HW_3D_STD_ array<WCHAR, 128>& get_description() const noexcept {
		return _description;
	}

	const Adapter_flag get_flags() const noexcept {
		return Adapter_flag_bit(_flags);
	}

	__declspec(property(get = get_description)) const _HW_3D_STD_ array<WCHAR, 128>& Description;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_vendor_id, UINT, VendorId);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_device_id, UINT, DeviceId);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_sub_sys_id, UINT, SubSysId);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_revision, UINT, Revision);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_dedicated_video_memory, SIZE_T, DedicatedVideoMemory);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_dedicated_system_memory, SIZE_T, DedicatedSystemMemory);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_shared_system_memory, SIZE_T, SharedSystemMemory);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_adapter_luid, LUID, AdapterLuid);
	__declspec(property(get = get_flags)) Adapter_flag Flags;
};
static_assert(sizeof(Adapter_desc1) == sizeof(DXGI_ADAPTER_DESC1));

inline bool operator==(const Adapter_desc1& lhs, const Adapter_desc1& rhs) noexcept {
	return (lhs.Description == rhs.Description)
		&& (lhs.VendorId == rhs.VendorId)
		&& (lhs.DeviceId == rhs.DeviceId)
		&& (lhs.SubSysId == rhs.SubSysId)
		&& (lhs.Revision == rhs.Revision)
		&& (lhs.DedicatedVideoMemory == rhs.DedicatedVideoMemory)
		&& (lhs.DedicatedSystemMemory == rhs.DedicatedSystemMemory)
		&& (lhs.SharedSystemMemory == rhs.SharedSystemMemory)
		&& (lhs.AdapterLuid.LowPart == rhs.AdapterLuid.LowPart)
		&& (lhs.AdapterLuid.HighPart == rhs.AdapterLuid.HighPart)
		&& (lhs.Flags == rhs.Flags);
}

inline bool operator!=(const Adapter_desc1& lhs, const Adapter_desc1& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Adapter_desc2 {
	_HW_3D_STD_ array<WCHAR, 128> _description{};
	UINT _vendor_id{ 0 };
	UINT _device_id{ 0 };
	UINT _sub_sys_id{ 0 };
	UINT _revision{ 0 };
	SIZE_T _dedicated_video_memory{ 0 };
	SIZE_T _dedicated_system_memory{ 0 };
	SIZE_T _shared_system_memory{ 0 };
	LUID _adapter_luid{ 0 };
	UINT _flags{ 0 };
	_HW_3D_DXGI_ Graphic_preemption_granularity _graphic_preemption_granularity{};
	_HW_3D_DXGI_ Compute_preemption_granularity _compute_preemption_granularity{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Adapter_desc2, DXGI_ADAPTER_DESC2)
public:
	const _HW_3D_STD_ array<WCHAR, 128>& get_description() const noexcept {
		return _description;
	}

	const Adapter_flag get_flags() const noexcept {
		return Adapter_flag_bit(_flags);
	}

	__declspec(property(get = get_description)) const _HW_3D_STD_ array<WCHAR, 128>& Description;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_vendor_id, UINT, VendorId);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_device_id, UINT, DeviceId);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_sub_sys_id, UINT, SubSysId);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_revision, UINT, Revision);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_dedicated_video_memory, SIZE_T, DedicatedVideoMemory);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_dedicated_system_memory, SIZE_T, DedicatedSystemMemory);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_shared_system_memory, SIZE_T, SharedSystemMemory);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_adapter_luid, LUID, AdapterLuid);
	__declspec(property(get = get_flags)) Adapter_flag Flags;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_graphic_preemption_granularity, _HW_3D_DXGI_ Graphic_preemption_granularity, GraphicsPreemptionGranularity);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_compute_preemption_granularity, _HW_3D_DXGI_ Compute_preemption_granularity, ComputePreemptionGranularity);
};
static_assert(sizeof(Adapter_desc2) == sizeof(DXGI_ADAPTER_DESC2));

inline bool operator==(const Adapter_desc2& lhs, const Adapter_desc2& rhs) noexcept {
	return (lhs.Description == rhs.Description)
		&& (lhs.VendorId == rhs.VendorId)
		&& (lhs.DeviceId == rhs.DeviceId)
		&& (lhs.SubSysId == rhs.SubSysId)
		&& (lhs.Revision == rhs.Revision)
		&& (lhs.DedicatedVideoMemory == rhs.DedicatedVideoMemory)
		&& (lhs.DedicatedSystemMemory == rhs.DedicatedSystemMemory)
		&& (lhs.SharedSystemMemory == rhs.SharedSystemMemory)
		&& (lhs.AdapterLuid.LowPart == rhs.AdapterLuid.LowPart)
		&& (lhs.AdapterLuid.HighPart == rhs.AdapterLuid.HighPart)
		&& (lhs.Flags == rhs.Flags)
		&& (lhs.GraphicsPreemptionGranularity == rhs.GraphicsPreemptionGranularity)
		&& (lhs.ComputePreemptionGranularity == rhs.ComputePreemptionGranularity);
}

inline bool operator!=(const Adapter_desc2& lhs, const Adapter_desc2& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Adapter_desc3 {
	_HW_3D_STD_ array<WCHAR, 128> _description{};
	UINT _vendor_id{ 0 };
	UINT _device_id{ 0 };
	UINT _sub_sys_id{ 0 };
	UINT _revision{ 0 };
	SIZE_T _dedicated_video_memory{ 0 };
	SIZE_T _dedicated_system_memory{ 0 };
	SIZE_T _shared_system_memory{ 0 };
	LUID _adapter_luid{ 0 };
	Adapter_flag3 _flags{};
	_HW_3D_DXGI_ Graphic_preemption_granularity _graphic_preemption_granularity{};
	_HW_3D_DXGI_ Compute_preemption_granularity _compute_preemption_granularity{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Adapter_desc3, DXGI_ADAPTER_DESC3)
public:
	const _HW_3D_STD_ array<WCHAR, 128>& get_description() const noexcept {
		return _description;
	}

	__declspec(property(get = get_description)) const _HW_3D_STD_ array<WCHAR, 128>& Description;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_vendor_id, UINT, VendorId);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_device_id, UINT, DeviceId);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_sub_sys_id, UINT, SubSysId);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_revision, UINT, Revision);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_dedicated_video_memory, SIZE_T, DedicatedVideoMemory);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_dedicated_system_memory, SIZE_T, DedicatedSystemMemory);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_shared_system_memory, SIZE_T, SharedSystemMemory);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_adapter_luid, LUID, AdapterLuid);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_flags, Adapter_flag3, Flags);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_graphic_preemption_granularity, _HW_3D_DXGI_ Graphic_preemption_granularity, GraphicsPreemptionGranularity);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_compute_preemption_granularity, _HW_3D_DXGI_ Compute_preemption_granularity, ComputePreemptionGranularity);
};
static_assert(sizeof(Adapter_desc3) == sizeof(DXGI_ADAPTER_DESC3));

inline bool operator==(const Adapter_desc3& lhs, const Adapter_desc3& rhs) noexcept {
	return (lhs.Description == rhs.Description)
		&& (lhs.VendorId == rhs.VendorId)
		&& (lhs.DeviceId == rhs.DeviceId)
		&& (lhs.SubSysId == rhs.SubSysId)
		&& (lhs.Revision == rhs.Revision)
		&& (lhs.DedicatedVideoMemory == rhs.DedicatedVideoMemory)
		&& (lhs.DedicatedSystemMemory == rhs.DedicatedSystemMemory)
		&& (lhs.SharedSystemMemory == rhs.SharedSystemMemory)
		&& (lhs.AdapterLuid.LowPart == rhs.AdapterLuid.LowPart)
		&& (lhs.AdapterLuid.HighPart == rhs.AdapterLuid.HighPart)
		&& (lhs.Flags == rhs.Flags)
		&& (lhs.GraphicsPreemptionGranularity == rhs.GraphicsPreemptionGranularity)
		&& (lhs.ComputePreemptionGranularity == rhs.ComputePreemptionGranularity);
}

inline bool operator!=(const Adapter_desc3& lhs, const Adapter_desc3& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Decode_swap_chain_desc {
	UINT _flags{ 0 };
public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Decode_swap_chain_desc, DXGI_DECODE_SWAP_CHAIN_DESC)
public:
};
static_assert(sizeof(Decode_swap_chain_desc) == sizeof(DXGI_DECODE_SWAP_CHAIN_DESC));

inline bool operator==(const Decode_swap_chain_desc& lhs, const Decode_swap_chain_desc& rhs) noexcept {
	return true;
}

inline bool operator!=(const Decode_swap_chain_desc& lhs, const Decode_swap_chain_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Display_color_space {
	_HW_3D_STD_ array<_HW_3D_STD_ array<FLOAT, 2>, 8> _primary_coordinates;
	_HW_3D_STD_ array<_HW_3D_STD_ array<FLOAT, 2>, 16> _white_points;
public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Display_color_space, DXGI_DISPLAY_COLOR_SPACE)
public:
	//TBD
};
static_assert(sizeof(Display_color_space) == sizeof(DXGI_DISPLAY_COLOR_SPACE));

//
//
class Frame_statistics {
	UINT _present_count{ 0 };
	UINT _present_refresh_count{ 0 };
	UINT _sync_refresh_count{ 0 };
	LARGE_INTEGER _sync_qpc_time{ 0 };
	LARGE_INTEGER _sync_gpu_time{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Frame_statistics, DXGI_FRAME_STATISTICS)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_present_count, UINT, PresentCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_present_refresh_count, UINT, PresentRefreshCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_sync_refresh_count, UINT, SyncRefreshCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_sync_qpc_time, LARGE_INTEGER, SyncQPCTime);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_sync_gpu_time, LARGE_INTEGER, SyncGPUTime);
};
static_assert(sizeof(Frame_statistics) == sizeof(DXGI_FRAME_STATISTICS));

inline bool operator==(const Frame_statistics& lhs, const Frame_statistics& rhs) noexcept {
	return (::memcmp(&lhs, &rhs, sizeof(Frame_statistics)) == 0);
}

inline bool operator!=(const Frame_statistics& lhs, const Frame_statistics& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Frame_statistics_media {
	UINT _present_count{ 0 };
	UINT _present_refresh_count{ 0 };
	UINT _sync_refresh_count{ 0 };
	LARGE_INTEGER _sync_qpc_time{ 0 };
	LARGE_INTEGER _sync_gpu_time{ 0 };
	Frame_presentation_mode _composition_mode{};
	UINT _approved_present_duration{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Frame_statistics_media, DXGI_FRAME_STATISTICS_MEDIA)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_present_count, UINT, PresentCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_present_refresh_count, UINT, PresentRefreshCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_sync_refresh_count, UINT, SyncRefreshCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_sync_qpc_time, LARGE_INTEGER, SyncQPCTime);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_sync_gpu_time, LARGE_INTEGER, SyncGPUTime);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_composition_mode, Frame_presentation_mode, CompositionMode);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_approved_present_duration, UINT, ApprovedPresentDuration);
};
static_assert(sizeof(Frame_statistics_media) == sizeof(DXGI_FRAME_STATISTICS_MEDIA));

inline bool operator==(const Frame_statistics_media& lhs, const Frame_statistics_media& rhs) noexcept {
	return ::memcmp(&lhs, &rhs, sizeof(Frame_statistics_media)) == 0;
}

inline bool operator!=(const Frame_statistics_media& lhs, const Frame_statistics_media& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Gamma_control {
	Rgb _scale{};
	Rgb _offset{};
	_HW_3D_STD_ array<Rgb, 1025> _gamma_curve{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Gamma_control, DXGI_GAMMA_CONTROL)
public:
	Gamma_control & set_gamma_curve(const _HW_3D_STD_ array<Rgb, 1025>& curve) {
		_gamma_curve = curve;
		return (*this);
	}

	const _HW_3D_STD_ array<Rgb, 1025>& get_gamma_curve() const noexcept {
		return _gamma_curve;
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_scale, Rgb, Scale);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_offset, Rgb, Offset);
	__declspec(property(get = get_gamma_curve, put = set_gamma_curve)) _HW_3D_STD_ array<Rgb, 1025> GammaCurve;
};
static_assert(sizeof(Gamma_control) == sizeof(DXGI_GAMMA_CONTROL));

inline bool operator==(const Gamma_control& lhs, const Gamma_control& rhs) noexcept {
	return (lhs.Scale == rhs.Scale)
		&& (lhs.Offset == rhs.Offset)
		&& (lhs.GammaCurve == rhs.GammaCurve);
}

inline bool operator!=(const Gamma_control& lhs, const Gamma_control& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Gamma_control_capabilities {
	BOOL _scale_and_offset_supported{ FALSE };
	float _max_converted_value{ 0.0f };
	float _min_converted_value{ 0.0f };
	UINT _num_gamma_control_points{ 0 };
	_HW_3D_STD_ array<float, 1025> _contorl_point_positions{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Gamma_control_capabilities, DXGI_GAMMA_CONTROL_CAPABILITIES)
public:
	const _HW_3D_STD_ array<float, 1025> get_control_point_positions() const noexcept {
		return _contorl_point_positions;
	}

	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_scale_and_offset_supported, BOOL, ScaleAndOffsetSupported);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_max_converted_value, float, MaxConvertedValue);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_min_converted_value, float, MinConvertedValue);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_num_gamma_control_points, UINT, NumGammaControlPoints);
	__declspec(property(get = get_control_point_positions)) const _HW_3D_STD_ array<float, 1025>& ControlPointPositions;
};
static_assert(sizeof(Gamma_control_capabilities) == sizeof(DXGI_GAMMA_CONTROL_CAPABILITIES));

inline bool operator==(const Gamma_control_capabilities& lhs, const Gamma_control_capabilities& rhs) noexcept {
	return (lhs.ScaleAndOffsetSupported == rhs.ScaleAndOffsetSupported)
		&& (lhs.MaxConvertedValue == rhs.MaxConvertedValue)
		&& (lhs.MinConvertedValue == rhs.MinConvertedValue)
		&& (lhs.NumGammaControlPoints == rhs.NumGammaControlPoints)
		&& (::memcmp(lhs.ControlPointPositions.data(), rhs.ControlPointPositions.data(), sizeof(float) * lhs.NumGammaControlPoints) == 0);
}

inline bool operator!=(const Gamma_control_capabilities& lhs, const Gamma_control_capabilities& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Hdr_metadata_hdr10 {
	_HW_3D_STD_ array<UINT16, 2> _red_primary{};
	_HW_3D_STD_ array<UINT16, 2> _green_primary{};
	_HW_3D_STD_ array<UINT16, 2> _blue_primary{};
	_HW_3D_STD_ array<UINT16, 2> _white_point{};
	UINT _max_mastering_luminance{ 0 };
	UINT _min_mastering_luminance{ 0 };
	UINT16 _max_content_light_level{ 0 };
	UINT16 _max_frame_average_light_level{ 0 };
public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Hdr_metadata_hdr10, DXGI_HDR_METADATA_HDR10)
public:
	Hdr_metadata_hdr10 & set_red_primary(_HW_3D_STD_ array<UINT16, 2> val) {
		_red_primary = val;
		return (*this);
	}

	_HW_3D_STD_ array<UINT16, 2> get_red_primary() const noexcept {
		return _red_primary;
	}

	Hdr_metadata_hdr10& set_green_primary(_HW_3D_STD_ array<UINT16, 2> val) {
		_green_primary = val;
		return (*this);
	}

	_HW_3D_STD_ array<UINT16, 2> get_green_primary() const noexcept {
		return _green_primary;
	}

	Hdr_metadata_hdr10& set_blue_primary(_HW_3D_STD_ array<UINT16, 2> val) {
		_blue_primary = val;
		return (*this);
	}

	_HW_3D_STD_ array<UINT16, 2> get_blue_primary() const noexcept {
		return _blue_primary;
	}

	Hdr_metadata_hdr10& set_white_point(_HW_3D_STD_ array<UINT16, 2> val) {
		_white_point = val;
		return (*this);
	}

	_HW_3D_STD_ array<UINT16, 2> get_white_point() const noexcept {
		return _white_point;
	}

	__declspec(property(get = get_red_primary, put = set_red_primary)) _HW_3D_STD_ array<UINT16, 2> RedPrimary;
	__declspec(property(get = get_green_primary, put = set_green_primary)) _HW_3D_STD_ array<UINT16, 2> GreenPrimary;
	__declspec(property(get = get_blue_primary, put = set_blue_primary)) _HW_3D_STD_ array<UINT16, 2> BluePrimary;
	__declspec(property(get = get_white_point, put = set_white_point)) _HW_3D_STD_ array<UINT16, 2> WhitePoint;
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_max_mastering_luminance, UINT, MaxMasteringLuminance);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_min_mastering_luminance, UINT, MinMasteringLuminance);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_max_content_light_level, UINT16, MaxContentLightLevel);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_max_frame_average_light_level, UINT16, MaxFrameAverageLightLevel);
};
static_assert(sizeof(Hdr_metadata_hdr10) == sizeof(DXGI_HDR_METADATA_HDR10));

inline bool operator==(const Hdr_metadata_hdr10& lhs, const Hdr_metadata_hdr10& rhs) noexcept {
	return (lhs.RedPrimary == rhs.RedPrimary)
		&& (lhs.GreenPrimary == rhs.GreenPrimary)
		&& (lhs.BluePrimary == rhs.BluePrimary)
		&& (lhs.WhitePoint == rhs.WhitePoint)
		&& (lhs.MaxMasteringLuminance == rhs.MaxMasteringLuminance)
		&& (lhs.MinMasteringLuminance == rhs.MinMasteringLuminance)
		&& (lhs.MaxContentLightLevel == rhs.MaxContentLightLevel)
		&& (lhs.MaxFrameAverageLightLevel == rhs.MaxFrameAverageLightLevel);
}

inline bool operator!=(const Hdr_metadata_hdr10& lhs, const Hdr_metadata_hdr10& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Sample_desc {
	UINT _count{ 0 };
	UINT _quality{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Sample_desc , DXGI_SAMPLE_DESC)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_count, UINT, Count);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_quality, UINT, Quality);
};
static_assert(sizeof(Sample_desc) == sizeof(DXGI_SAMPLE_DESC));

inline bool operator==(const Sample_desc& lhs, const Sample_desc& rhs) noexcept {
	return (lhs.Count == rhs.Count)
		&& (lhs.Quality == rhs.Quality);
}

inline bool operator!=(const Sample_desc& lhs, const Sample_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Info_queue_message {
	DXGI_DEBUG_ID _producer{};
	Info_queue_message_category _category{};
	Info_queue_message_severity _severity{};
	DXGI_INFO_QUEUE_MESSAGE_ID _id{ 0 };
	const char* _description{ nullptr };
	SIZE_T _byte_length{ 0 };
public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Info_queue_message, DXGI_INFO_QUEUE_MESSAGE)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_producer, DXGI_DEBUG_ID, Producer);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_category, Info_queue_message_category, Category);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_severity, Info_queue_message_severity, Severity);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_id, DXGI_INFO_QUEUE_MESSAGE_ID, ID);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_description, const char*, pDescription);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_byte_length, SIZE_T, DescriptionByteLength);
};
static_assert(sizeof(Info_queue_message) == sizeof(DXGI_INFO_QUEUE_MESSAGE));

inline bool operator==(const Info_queue_message& lhs, const Info_queue_message& rhs) noexcept {
	return (lhs.Category == rhs.Category)
		&& (lhs.Severity == rhs.Severity)
		&& (lhs.ID == rhs.ID)
		&& (lhs.DescriptionByteLength == rhs.DescriptionByteLength)
		&& (lhs.Producer == rhs.Producer)
		&& (::memcmp(lhs.pDescription, rhs.pDescription, lhs.DescriptionByteLength) == 0);
}

inline bool operator!=(const Info_queue_message& lhs, const Info_queue_message& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Info_queue_filter_desc {
	UINT _num_categories{ 0 };
	Info_queue_message_category* _p_category_list{ nullptr };
	UINT _num_severities{ 0 };
	Info_queue_message_severity* _p_severity_list{ nullptr };
	UINT _num_ids{ 0 };
	DXGI_INFO_QUEUE_MESSAGE_ID* _p_id_list{ nullptr };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Info_queue_filter_desc, DXGI_INFO_QUEUE_FILTER_DESC)
public:
	Info_queue_filter_desc & set_categories(Info_queue_message_category* lst, UINT num) {
		_p_category_list = lst;
		_num_categories = num;
		return (*this);
	}

	Info_queue_filter_desc& set_severities(Info_queue_message_severity* lst, UINT num) {
		_p_severity_list = lst;
		_num_severities = num;
		return (*this);
	}

	Info_queue_filter_desc& set_ids(DXGI_INFO_QUEUE_MESSAGE_ID* lst, UINT num) {
		_p_id_list = lst;
		_num_ids = num;
		return (*this);
	}

	UINT get_num_categories() const noexcept {
		return _num_categories;
	}

	const Info_queue_message_category*  get_p_category_list() const noexcept {
		return _p_category_list;
	}

	UINT get_num_severities() const noexcept {
		return _num_severities;
	}

	const Info_queue_message_severity* get_p_severity_list() const noexcept {
		return _p_severity_list;
	}

	UINT get_num_ids() const noexcept {
		return _num_ids;
	}

	const DXGI_INFO_QUEUE_MESSAGE_ID* get_p_id_list() const noexcept {
		return _p_id_list;
	}

	__declspec(property(get = get_num_categories)) UINT NumCategories;
	__declspec(property(get = get_p_category_list)) const Info_queue_message_category* pCategoryList;
	__declspec(property(get = get_num_severities)) UINT NumSeverities;
	__declspec(property(get = get_p_severity_list)) const Info_queue_message_severity* pSeverityList;
	__declspec(property(get = get_num_ids)) UINT NumIDs;
	__declspec(property(get = get_p_id_list)) const DXGI_INFO_QUEUE_MESSAGE_ID* pIDList;

};
static_assert(sizeof(Info_queue_filter_desc) == sizeof(D3D11_INFO_QUEUE_FILTER_DESC));

inline bool operator==(const Info_queue_filter_desc& lhs, const Info_queue_filter_desc& rhs) noexcept {
	return (lhs.NumCategories == rhs.NumCategories)
		&& (lhs.NumIDs == rhs.NumIDs)
		&& (lhs.NumSeverities == rhs.NumSeverities)
		&& (memcmp(lhs.pCategoryList, rhs.pCategoryList, sizeof(Info_queue_message_category) * lhs.NumCategories) == 0)
		&& (memcmp(lhs.pIDList, rhs.pIDList, sizeof(DXGI_INFO_QUEUE_MESSAGE_ID) * lhs.NumIDs) == 0)
		&& (memcmp(lhs.pSeverityList, rhs.pSeverityList, sizeof(Info_queue_message_severity) * lhs.NumSeverities) == 0);
}

inline bool operator!=(const Info_queue_filter_desc& lhs, const Info_queue_filter_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Info_queue_filter {
	Info_queue_filter_desc _allow_list{};
	Info_queue_filter_desc _deny_list{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Info_queue_filter, DXGI_INFO_QUEUE_FILTER)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_allow_list, Info_queue_filter_desc, AllowList);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_deny_list, Info_queue_filter_desc, DenyList);
};
static_assert(sizeof(Info_queue_filter) == sizeof(DXGI_INFO_QUEUE_FILTER));

inline bool operator==(const Info_queue_filter& lhs, const Info_queue_filter& rhs) noexcept {
	return (lhs.AllowList == rhs.AllowList)
		&& (lhs.DenyList == rhs.DenyList);
}

inline bool operator!=(const Info_queue_filter& lhs, const Info_queue_filter& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Jpeg_ac_huffman_table {
	_HW_3D_STD_ array<BYTE, 16> _code_counts{};
	_HW_3D_STD_ array<BYTE, 162> _code_values{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Jpeg_ac_huffman_table, DXGI_JPEG_AC_HUFFMAN_TABLE)
public:
	Jpeg_ac_huffman_table & set_code_counts(_HW_3D_STD_ array<BYTE, 16> val) {
		_code_counts = val;
		return (*this);
	}

	_HW_3D_STD_ array<BYTE, 16> get_code_counts() const noexcept {
		return _code_counts;
	}

	Jpeg_ac_huffman_table& set_code_values(const _HW_3D_STD_ array<BYTE, 162> &val) {
		_code_values = val;
		return (*this);
	}

	_HW_3D_STD_ array<BYTE, 162> get_code_values() const noexcept {
		return _code_values;
	}

	__declspec(property(get = get_code_counts, put = set_code_counts)) _HW_3D_STD_ array<BYTE, 16> CodeCounts;
	__declspec(property(get = get_code_values, put = set_code_values)) _HW_3D_STD_ array<BYTE, 162> CodeValues;
};
static_assert(sizeof(Jpeg_ac_huffman_table) == sizeof(DXGI_JPEG_AC_HUFFMAN_TABLE));

inline bool operator==(const Jpeg_ac_huffman_table& lhs, const Jpeg_ac_huffman_table& rhs) noexcept {
	return (lhs.CodeCounts == rhs.CodeCounts)
		&& (lhs.CodeValues == rhs.CodeValues);
}

inline bool operator!=(const Jpeg_ac_huffman_table& lhs, const Jpeg_ac_huffman_table& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Jpeg_dc_huffman_table {
	_HW_3D_STD_ array<BYTE, 12> _code_counts{};
	_HW_3D_STD_ array<BYTE, 12> _code_values{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Jpeg_dc_huffman_table, DXGI_JPEG_DC_HUFFMAN_TABLE)
public:
	Jpeg_dc_huffman_table & set_code_counts(_HW_3D_STD_ array<BYTE, 12> val) {
		_code_counts = val;
		return (*this);
	}

	_HW_3D_STD_ array<BYTE, 12> get_code_counts() const noexcept {
		return _code_counts;
	}

	Jpeg_dc_huffman_table& set_code_values(_HW_3D_STD_ array<BYTE, 12> &val) {
		_code_values = val;
		return (*this);
	}

	_HW_3D_STD_ array<BYTE, 12> get_code_values() const noexcept {
		return _code_values;
	}

	__declspec(property(get = get_code_counts, put = set_code_counts)) _HW_3D_STD_ array<BYTE, 12> CodeCounts;
	__declspec(property(get = get_code_values, put = set_code_values)) _HW_3D_STD_ array<BYTE, 12> CodeValues;
};
static_assert(sizeof(Jpeg_dc_huffman_table) == sizeof(DXGI_JPEG_DC_HUFFMAN_TABLE));

inline bool operator==(const Jpeg_dc_huffman_table& lhs, const Jpeg_dc_huffman_table& rhs) noexcept {
	return (lhs.CodeCounts == rhs.CodeCounts)
		&& (lhs.CodeValues == rhs.CodeValues);
}

inline bool operator!=(const Jpeg_dc_huffman_table& lhs, const Jpeg_dc_huffman_table& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Jepg_quantization_table {
	_HW_3D_STD_ array<BYTE, 64> _elements{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Jepg_quantization_table, DXGI_JPEG_QUANTIZATION_TABLE)
public:
	Jepg_quantization_table & set_elements(const _HW_3D_STD_ array<BYTE, 64>& val) {
		_elements = val;
		return (*this);
	}

	const _HW_3D_STD_ array<BYTE, 64>& get_elements() const noexcept {
		return _elements;
	}

	__declspec(property(get = get_elements, put = set_elements)) _HW_3D_STD_ array<BYTE, 64> Elements;
};
static_assert(sizeof(Jepg_quantization_table) == sizeof(DXGI_JPEG_QUANTIZATION_TABLE));

inline bool operator==(const Jepg_quantization_table& lhs, const Jepg_quantization_table& rhs) noexcept {
	return (lhs.Elements == rhs.Elements);
}

inline bool operator!=(const Jepg_quantization_table& lhs, const Jepg_quantization_table& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Mapped_rect {
	INT _pitch{ 0 };
	BYTE* _bits{ nullptr };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Mapped_rect, DXGI_MAPPED_RECT)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_pitch, INT, Pitch);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_bits, BYTE*, pBits);
};
static_assert(sizeof(Mapped_rect) == sizeof(DXGI_MAPPED_RECT));

inline bool operator==(const Mapped_rect& lhs, const Mapped_rect& rhs) noexcept {
	return (lhs.Pitch == rhs.Pitch)
		&& (lhs.pBits == rhs.pBits);
}

inline bool operator!=(const Mapped_rect& lhs, const Mapped_rect& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Mode_desc {
	UINT _width{ 0 };
	UINT _height{ 0 };
	Rational _refresh_rate{};
	Format _format{};
	Mode_scanline_order _scanline_ordering{};
	Mode_scaling _scaling{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Mode_desc, DXGI_MODE_DESC)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_width, UINT, Width);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_height, UINT, Height);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_refresh_rate, Rational, RefreshRate);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_format, _HW_3D_DXGI_ Format, Format);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_scanline_ordering, Mode_scanline_order, ScanlineOrdering);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_scaling, Mode_scaling, Scaling);
};
static_assert(sizeof(Mode_desc) == sizeof(DXGI_MODE_DESC));

inline bool operator==(const Mode_desc& lhs, const Mode_desc& rhs) noexcept {
	return (lhs.Width == rhs.Width)
		&& (lhs.Height == rhs.Height)
		&& (lhs.RefreshRate == rhs.RefreshRate)
		&& (lhs.Format == rhs.Format)
		&& (lhs.ScanlineOrdering == rhs.ScanlineOrdering)
		&& (lhs.Scaling == rhs.Scaling);
}

inline bool operator!=(const Mode_desc& lhs, const Mode_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Mode_desc1 {
	UINT _width{ 0 };
	UINT _height{ 0 };
	Rational _refresh_rate{};
	Format _format{};
	Mode_scanline_order _scanline_ordering{};
	Mode_scaling _scaling{};
	BOOL _stereo{ FALSE };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Mode_desc1, DXGI_MODE_DESC1)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_width, UINT, Width);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_height, UINT, Height);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_refresh_rate, Rational, RefreshRate);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_format, _HW_3D_DXGI_ Format, Format);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_scanline_ordering, Mode_scanline_order, ScanlineOrdering);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_scaling, Mode_scaling, Scaling);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_stereo, BOOL, Stereo);
};
static_assert(sizeof(Mode_desc1) == sizeof(DXGI_MODE_DESC1));

inline bool operator==(const Mode_desc1& lhs, const Mode_desc1& rhs) noexcept {
	return (lhs.Width == rhs.Width)
		&& (lhs.Height == rhs.Height)
		&& (lhs.RefreshRate == rhs.RefreshRate)
		&& (lhs.Format == rhs.Format)
		&& (lhs.ScanlineOrdering == rhs.ScanlineOrdering)
		&& (lhs.Scaling == rhs.Scaling)
		&& (lhs.Stereo == rhs.Stereo);
}

inline bool operator!=(const Mode_desc1& lhs, const Mode_desc1& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Output_desc {
	_HW_3D_STD_ array<WCHAR, 32> _device_name{};
	RECT _desktop_coordinates{};
	BOOL _attached_to_desktop{ FALSE };
	Mode_rotation _rotation{};
	HMONITOR _monitor{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Output_desc, DXGI_OUTPUT_DESC)
public:
	const _HW_3D_STD_ array<WCHAR, 32>& get_device_name() const noexcept {
		return _device_name;
	}

	__declspec(property(get = get_device_name)) const _HW_3D_STD_ array<WCHAR, 32>& DeviceName;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_desktop_coordinates, RECT, DesktopCoordinates);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_attached_to_desktop, BOOL, AttachedToDesktop);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_rotation, Mode_rotation, Rotation);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_monitor, HMONITOR, Monitor);
};
static_assert(sizeof(Output_desc) == sizeof(DXGI_OUTPUT_DESC));

inline bool operator==(const Output_desc& lhs, const Output_desc& rhs) noexcept {
	return (lhs.DeviceName == rhs.DeviceName)
		&& (lhs.DesktopCoordinates == rhs.DesktopCoordinates)
		&& (lhs.AttachedToDesktop == rhs.AttachedToDesktop)
		&& (lhs.Rotation == rhs.Rotation)
		&& (lhs.Monitor == rhs.Monitor);
}

inline bool operator!=(const Output_desc& lhs, const Output_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
//
//
class Output_desc1 {
	_HW_3D_STD_ array<WCHAR, 32> _device_name{};
	RECT _desktop_coordinates{};
	BOOL _attached_to_desktop{ FALSE };
	Mode_rotation _rotation{};
	HMONITOR _monitor{ 0 };
	UINT _bits_per_color{ 0 };
	Color_space_type _color_space{};
	_HW_3D_STD_ array<FLOAT, 2> _red_primary{};
	_HW_3D_STD_ array<FLOAT, 2> _green_primary{};
	_HW_3D_STD_ array<FLOAT, 2> _blue_primary{};
	_HW_3D_STD_ array<FLOAT, 2> _white_point{};
	FLOAT _min_luminance{ 0.0f };
	FLOAT _max_luminance{ 0.0f };
	FLOAT _max_full_frame_luminance{ 0.0f };
	//		BOOL _internal_output{ FALSE };  actual definition is different from msdn reference

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Output_desc1, DXGI_OUTPUT_DESC1)
public:
	const _HW_3D_STD_ array<WCHAR, 32>& get_device_name() const noexcept {
		return _device_name;
	}

	_HW_3D_STD_ array<FLOAT, 2> get_red_primary() const noexcept {
		return _red_primary;
	}

	_HW_3D_STD_ array<FLOAT, 2> get_green_primary() const noexcept {
		return _green_primary;
	}

	_HW_3D_STD_ array<FLOAT, 2> get_blue_primary() const noexcept {
		return _blue_primary;
	}

	_HW_3D_STD_ array<FLOAT, 2> get_white_point() const noexcept {
		return _white_point;
	}

	__declspec(property(get = get_device_name)) const _HW_3D_STD_ array<WCHAR, 32>& DeviceName;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_desktop_coordinates, RECT, DesktopCoordinates);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_attached_to_desktop, BOOL, AttachedToDesktop);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_rotation, Mode_rotation, Rotation);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_monitor, HMONITOR, Monitor);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_bits_per_color, UINT, BitsPerColor);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_color_space, Color_space_type, ColorSpace);
	__declspec(property(get = get_red_primary)) _HW_3D_STD_ array<FLOAT, 2> RedPrimary;
	__declspec(property(get = get_green_primary)) _HW_3D_STD_ array<FLOAT, 2> GreenPrimary;
	__declspec(property(get = get_blue_primary)) _HW_3D_STD_ array<FLOAT, 2> BluePrimary;
	__declspec(property(get = get_white_point)) _HW_3D_STD_ array<FLOAT, 2> WhitePoint;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_min_luminance, FLOAT, MinLuminance);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_max_luminance, FLOAT, MaxLuminance);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_max_full_frame_luminance, FLOAT, MaxFullFrameLuminance);
};
static_assert(sizeof(Output_desc1) == sizeof(DXGI_OUTPUT_DESC1));

inline bool operator==(const Output_desc1& lhs, const Output_desc1& rhs) noexcept {
	return (lhs.DeviceName == rhs.DeviceName)
		&& (lhs.DesktopCoordinates == rhs.DesktopCoordinates)
		&& (lhs.AttachedToDesktop == rhs.AttachedToDesktop)
		&& (lhs.Rotation == rhs.Rotation)
		&& (lhs.Monitor == rhs.Monitor)
		&& (lhs.BitsPerColor == rhs.BitsPerColor)
		&& (lhs.ColorSpace == rhs.ColorSpace)
		&& (lhs.RedPrimary == rhs.RedPrimary)
		&& (lhs.GreenPrimary == rhs.GreenPrimary)
		&& (lhs.BluePrimary == rhs.BluePrimary)
		&& (lhs.WhitePoint == rhs.WhitePoint)
		&& (lhs.MinLuminance == rhs.MinLuminance)
		&& (lhs.MaxLuminance == rhs.MaxLuminance)
		&& (lhs.MaxFullFrameLuminance == rhs.MaxFullFrameLuminance);
}

inline bool operator!=(const Output_desc1& lhs, const Output_desc1& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Outdupl_desc {
	Mode_desc _mode_desc{};
	Mode_rotation _rotation{};
	BOOL _desktop_image_in_system_memory{ FALSE };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Outdupl_desc, DXGI_OUTDUPL_DESC)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_mode_desc, _HW_3D_DXGI_ Mode_desc, ModeDesc);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_rotation, Mode_rotation, Rotation);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_desktop_image_in_system_memory, BOOL, DesktopImageInSystemMemory);
};
static_assert(sizeof(Outdupl_desc) == sizeof(DXGI_OUTDUPL_DESC));

inline bool operator==(const Outdupl_desc& lhs, const Outdupl_desc& rhs) noexcept {
	return (lhs.ModeDesc == rhs.ModeDesc)
		&& (lhs.Rotation == rhs.Rotation)
		&& (lhs.DesktopImageInSystemMemory == rhs.DesktopImageInSystemMemory);
}

inline bool operator!=(const Outdupl_desc& lhs, const Outdupl_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Outdupl_pointer_position {
	POINT _position{};
	BOOL _visible{ FALSE };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Outdupl_pointer_position, DXGI_OUTDUPL_POINTER_POSITION)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_position, POINT, Position);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_visible, BOOL, Visible);
};
static_assert(sizeof(Outdupl_pointer_position) == sizeof(DXGI_OUTDUPL_POINTER_POSITION));

inline bool operator==(const Outdupl_pointer_position& lhs, const Outdupl_pointer_position& rhs) noexcept {
	return (lhs.Position.x == rhs.Position.x)
		&& (lhs.Position.y == rhs.Position.y)
		&& (lhs.Visible == rhs.Visible);
}

inline bool operator!=(const Outdupl_pointer_position& lhs, const Outdupl_pointer_position& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Outdupl_frame_info {
	LARGE_INTEGER _last_present_time{ 0 };
	LARGE_INTEGER _last_mouse_update_time{ 0 };
	UINT _accumulated_frames{ 0 };
	BOOL _rects_coalesed{ FALSE };
	BOOL _protected_content_masked_out{ FALSE };
	Outdupl_pointer_position _pointer_positon{};
	UINT _total_metadata_buffer_size{ 0 };
	UINT _pointer_shape_buffer_size{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Outdupl_frame_info, DXGI_OUTDUPL_FRAME_INFO)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_last_present_time, LARGE_INTEGER, LastPresentTime);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_last_mouse_update_time, LARGE_INTEGER, LastMouseUpdateTime);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_accumulated_frames, UINT, AccumulatedFrames);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_rects_coalesed, BOOL, RectsCoalesced);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_protected_content_masked_out, BOOL, ProtectedContentMaskedOut);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_pointer_positon, Outdupl_pointer_position, PointerPosition);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_total_metadata_buffer_size, UINT, TotalMetadataBufferSize);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_pointer_shape_buffer_size, UINT, PointerShapeBufferSize);
};
static_assert(sizeof(Outdupl_frame_info) == sizeof(DXGI_OUTDUPL_FRAME_INFO));

inline bool operator==(const Outdupl_frame_info& lhs, const Outdupl_frame_info& rhs) noexcept {
	return (::memcmp(&lhs.LastPresentTime, &rhs.LastPresentTime, sizeof(LARGE_INTEGER)) == 0) //compare a tempary variable, not a problem
		&& (::memcmp(&lhs.LastMouseUpdateTime, &rhs.LastMouseUpdateTime, sizeof(LARGE_INTEGER)) == 0)
		&& (lhs.AccumulatedFrames == rhs.AccumulatedFrames)
		&& (lhs.RectsCoalesced == rhs.RectsCoalesced)
		&& (lhs.ProtectedContentMaskedOut == rhs.ProtectedContentMaskedOut)
		&& (lhs.PointerPosition == rhs.PointerPosition)
		&& (lhs.TotalMetadataBufferSize == rhs.TotalMetadataBufferSize)
		&& (lhs.PointerShapeBufferSize == rhs.PointerShapeBufferSize);
}

inline bool operator!=(const Outdupl_frame_info& lhs, const Outdupl_frame_info& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Outdupl_move_rect {
	POINT _source_point{};
	RECT _destination_rect{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Outdupl_move_rect, DXGI_OUTDUPL_MOVE_RECT)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_source_point, POINT, SourcePoint);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_destination_rect, RECT, DestinationRect);
};
static_assert(sizeof(Outdupl_move_rect) == sizeof(DXGI_OUTDUPL_MOVE_RECT));

inline bool operator==(const Outdupl_move_rect& lhs, const Outdupl_move_rect& rhs) noexcept {
	return (lhs.SourcePoint.x == rhs.SourcePoint.x)
		&& (lhs.SourcePoint.y == rhs.SourcePoint.y)
		&& (rhs.DestinationRect == rhs.DestinationRect);
}

inline bool operator!=(const Outdupl_move_rect& lhs, const Outdupl_move_rect& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Outdupl_pointer_shape_info {
	UINT _type{ 0 };
	UINT _width{ 0 };
	UINT _height{ 0 };
	UINT _pitch{ 0 };
	POINT _hot_spot{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Outdupl_pointer_shape_info, DXGI_OUTDUPL_POINTER_SHAPE_INFO)
public:
	Outdupl_pointer_shader_type get_type() const noexcept {
		return static_cast<Outdupl_pointer_shader_type>(_type);
	}

	__declspec(property(get = get_type)) Outdupl_pointer_shader_type Type;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_width, UINT, Width);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_height, UINT, Height);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_pitch, UINT, Pitch);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_hot_spot, POINT, HotSpot);
};
static_assert(sizeof(Outdupl_pointer_shape_info) == sizeof(DXGI_OUTDUPL_POINTER_SHAPE_INFO));

inline bool operator==(const Outdupl_pointer_shape_info& lhs, const Outdupl_pointer_shape_info& rhs) noexcept {
	return (lhs.Type == rhs.Type)
		&& (lhs.Width == rhs.Width)
		&& (lhs.Height == rhs.Height)
		&& (lhs.Pitch == rhs.Pitch)
		&& (lhs.HotSpot.x == rhs.HotSpot.x)
		&& (lhs.HotSpot.y == rhs.HotSpot.y);
}

inline bool operator!=(const Outdupl_pointer_shape_info& lhs, const Outdupl_pointer_shape_info& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Present_parameters {
	UINT _dirty_rects_count{ 0 };
	RECT* _p_dirty_rects{ nullptr };
	RECT* _p_scroll_rect{ nullptr };
	POINT* _p_scroll_offset{ nullptr };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Present_parameters, DXGI_PRESENT_PARAMETERS)
public:
	Present_parameters & set_dirty_rects(RECT* rects, UINT count) {
		_dirty_rects_count = count;
		_p_dirty_rects = rects;
		return (*this);
	}

	RECT* get_p_dirty_rects() const noexcept {
		return _p_dirty_rects;
	}

	UINT get_dirty_rects_count() const noexcept {
		return _dirty_rects_count;
	}

	__declspec(property(get = get_dirty_rects_count)) UINT DirtyRectsCount;
	__declspec(property(get = get_p_dirty_rects)) RECT* pDirtyRects;
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_p_scroll_rect, RECT*, pScrollRect);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_p_scroll_offset, POINT*, pScrollOffset);
};
static_assert(sizeof(Present_parameters) == sizeof(DXGI_PRESENT_PARAMETERS));

inline bool operator==(const Present_parameters& lhs, const Present_parameters& rhs) noexcept {
	return (lhs.DirtyRectsCount == rhs.DirtyRectsCount)
		&& (::memcmp(lhs.pDirtyRects, rhs.pDirtyRects, sizeof(RECT) * lhs.DirtyRectsCount) == 0)
		&& (::memcmp(lhs.pScrollOffset, rhs.pScrollRect, sizeof(RECT)) == 0)
		&& (::memcmp(lhs.pScrollOffset, rhs.pScrollOffset, sizeof(POINT)) == 0);
}

inline bool operator!=(const Present_parameters& lhs, const Present_parameters& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Query_video_memory_info {
	UINT64 _budget{ 0 };
	UINT64 _current_usage{ 0 };
	UINT64 _available_for_reservaton{ 0 };
	UINT64 _current_reservation{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Query_video_memory_info, DXGI_QUERY_VIDEO_MEMORY_INFO)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_budget, UINT64, Budget);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_current_usage, UINT64, CurrentUsage);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_available_for_reservaton, UINT64, AvailableForReservation);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_current_reservation, UINT64, CurrentReservation);
};
static_assert(sizeof(Query_video_memory_info) == sizeof(DXGI_QUERY_VIDEO_MEMORY_INFO));

inline bool operator==(const Query_video_memory_info& lhs, const Query_video_memory_info& rhs) noexcept {
	return (lhs.Budget == rhs.Budget)
		&& (lhs.CurrentReservation == rhs.CurrentReservation)
		&& (lhs.CurrentUsage == rhs.CurrentUsage)
		&& (lhs.AvailableForReservation == rhs.AvailableForReservation);
}

inline bool operator!=(const Query_video_memory_info& lhs, const Query_video_memory_info& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Shared_resource {
	HANDLE _handle{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Shared_resource, DXGI_SHARED_RESOURCE)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_handle, HANDLE, Handle);
};
static_assert(sizeof(Shared_resource) == sizeof(DXGI_SHARED_RESOURCE));

inline bool operator==(const Shared_resource& lhs, const Shared_resource& rhs) noexcept {
	return (lhs.Handle == rhs.Handle);
}

inline bool operator!=(const Shared_resource& lhs, const Shared_resource& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Surface_desc {
	UINT _width{ 0 };
	UINT _height{ 0 };
	Format _format{};
	Sample_desc _sample_desc{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Surface_desc, DXGI_SURFACE_DESC)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_width, UINT, Width);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_height, UINT, Height);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_format, _HW_3D_DXGI_ Format, Format);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_sample_desc, _HW_3D_DXGI_ Sample_desc, SampleDesc);
};
static_assert(sizeof(Surface_desc) == sizeof(DXGI_SURFACE_DESC));

inline bool operator==(const Surface_desc& lhs, const Surface_desc& rhs) noexcept {
	return (lhs.Width == rhs.Width)
		&& (lhs.Height == rhs.Height)
		&& (lhs.Format == rhs.Format)
		&& (lhs.SampleDesc == rhs.SampleDesc);
}

inline bool operator!=(const Surface_desc& lhs, const Surface_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Swap_chain_desc {
	Mode_desc _buffer_desc{};
	Sample_desc _sample_desc{};
	Usage _buffer_usage{};
	UINT _buffer_count{ 0 };
	HWND _output_window{ 0 };
	BOOL _windowed{ FALSE };
	Swap_effect _swap_effect{};
	UINT _flags{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Swap_chain_desc, DXGI_SWAP_CHAIN_DESC)
public:
	Swap_chain_desc & set_flags(Swap_chain_flag flags) {
		_flags = decltype(flags)::mask_type(flags);
		return (*this);
	}

	Swap_chain_flag get_flags() const noexcept {
		return Swap_chain_flag_bit(_flags);
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_buffer_desc, Mode_desc, BufferDesc);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_sample_desc, _HW_3D_DXGI_ Sample_desc, SampleDesc);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_buffer_usage, Usage, BufferUsage);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_buffer_count, UINT, BufferCount);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_output_window, HWND, OutputWindow);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_windowed, BOOL, Windowed);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_swap_effect, _HW_3D_DXGI_ Swap_effect, SwapEffect);
	__declspec(property(get = get_flags, put = set_flags)) Swap_chain_flag Flags;
};
static_assert(sizeof(Swap_chain_desc) == sizeof(DXGI_SWAP_CHAIN_DESC));

inline bool operator==(const Swap_chain_desc& lhs, const Swap_chain_desc& rhs) noexcept {
	return (lhs.BufferDesc == rhs.BufferDesc)
		&& (lhs.SampleDesc == rhs.SampleDesc)
		&& (lhs.BufferUsage == rhs.BufferUsage)
		&& (lhs.BufferCount == rhs.BufferCount)
		&& (lhs.OutputWindow == rhs.OutputWindow)
		&& (lhs.Windowed == rhs.Windowed)
		&& (lhs.SwapEffect == rhs.SwapEffect)
		&& (lhs.Flags == rhs.Flags);
}

inline bool operator!=(const Swap_chain_desc& lhs, const Swap_chain_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Swap_chain_desc1 {
	UINT _width{ 0 };
	UINT _height{ 0 };
	Format _format{};
	BOOL _stereo{ FALSE };
	Sample_desc _sample_desc{};
	Usage _buffer_usage{};
	UINT _buffer_count{ 0 };
	Scaling _scaling{};
	Swap_effect _swap_effect{};
	Alpha_mode _alpha_mode{};
	UINT _flags{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Swap_chain_desc1, DXGI_SWAP_CHAIN_DESC1)
public:
	Swap_chain_desc1 & set_flags(Swap_chain_flag flags) {
		_flags = decltype(flags)::mask_type(flags);
		return (*this);
	}

	Swap_chain_flag get_flags() const noexcept {
		return Swap_chain_flag_bit(_flags);
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_width, UINT, Width);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_height, UINT, Height);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_format, _HW_3D_DXGI_ Format, Format);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_stereo, BOOL, Stereo);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_sample_desc, _HW_3D_DXGI_ Sample_desc, SampleDesc);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_buffer_usage, Usage, BufferUsage);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_buffer_count, UINT, BufferCount);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_scaling, _HW_3D_DXGI_ Scaling, Scaling);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_swap_effect, _HW_3D_DXGI_ Swap_effect, SwapEffect);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_alpha_mode, _HW_3D_DXGI_ Alpha_mode, AlphaMode);
	__declspec(property(get = get_flags, put = set_flags)) Swap_chain_flag Flags;
};
static_assert(sizeof(Swap_chain_desc1) == sizeof(DXGI_SWAP_CHAIN_DESC1));

inline bool operator==(const Swap_chain_desc1& lhs, const Swap_chain_desc1& rhs) noexcept {
	return (lhs.Width == rhs.Width)
		&& (lhs.Height == rhs.Height)
		&& (lhs.Format == rhs.Format)
		&& (lhs.Stereo == rhs.Stereo)
		&& (lhs.SampleDesc == rhs.SampleDesc)
		&& (lhs.BufferUsage == rhs.BufferUsage)
		&& (lhs.BufferCount == rhs.BufferCount)
		&& (lhs.Scaling == rhs.Scaling)
		&& (lhs.SwapEffect == rhs.SwapEffect)
		&& (lhs.AlphaMode == rhs.AlphaMode)
		&& (lhs.Flags == rhs.Flags);
}

inline bool operator!=(const Swap_chain_desc1& lhs, const Swap_chain_desc1& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Swap_chain_fullscreen_desc {
	Rational _refresh_rate{};
	Mode_scanline_order _scanline_ordering{};
	Mode_scaling _scaling{};
	BOOL _windowed{ FALSE };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Swap_chain_fullscreen_desc, DXGI_SWAP_CHAIN_FULLSCREEN_DESC)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_refresh_rate, Rational, RefreshRate);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_scanline_ordering, Mode_scanline_order, ScanlineOrdering);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_scaling, Mode_scaling, Scaling);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_windowed, BOOL, Windowed);
};
static_assert(sizeof(Swap_chain_fullscreen_desc) == sizeof(DXGI_SWAP_CHAIN_FULLSCREEN_DESC));

inline bool operator==(const Swap_chain_fullscreen_desc& lhs, const Swap_chain_fullscreen_desc& rhs) noexcept {
	return (lhs.RefreshRate == rhs.RefreshRate)
		&& (lhs.ScanlineOrdering == rhs.ScanlineOrdering)
		&& (lhs.Scaling == rhs.Scaling)
		&& (lhs.Windowed == rhs.Windowed);
}

inline bool operator!=(const Swap_chain_fullscreen_desc& lhs, const Swap_chain_fullscreen_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

_HW_3D_CLOSE_DXGI_NAMESPACE_

_HW_3D_OPEN_D3D_NAMESPACE_

//
//
class Box {
	Uint _left{ 0 };
	Uint _top{ 0 };
	Uint _front{ 0 };
	Uint _right{ 0 };
	Uint _bottom{ 0 };
	Uint _back{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Box, D3D11_BOX)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_left, Uint, left);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_top, Uint, top);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_front, Uint, front);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_right, Uint, right);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_bottom, Uint, bottom);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_back, Uint, back);
};
static_assert(sizeof(Box) == sizeof(D3D11_BOX));

inline bool operator==(const Box& lhs, const Box& rhs) noexcept {
	return (lhs.left == rhs.left)
		&& (lhs.top == rhs.top)
		&& (lhs.front == rhs.front)
		&& (lhs.right == rhs.right)
		&& (lhs.bottom == rhs.bottom)
		&& (lhs.back == rhs.back);
}

inline bool operator!=(const Box& lhs, const Box& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Counter_info {
	Counter _last_device_dependent_counter{};
	Uint _num_simultaneous_counters{ 0 };
	Uint8 _num_detectable_parallel_units{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Counter_info, D3D11_COUNTER_INFO)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_last_device_dependent_counter, Counter, LastDeviceDependentCounter);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_num_simultaneous_counters, Uint, NumSimultaneousCounters);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_num_detectable_parallel_units, Uint8, NumDetectableParallelUnits);
};
static_assert(sizeof(Counter_info) == sizeof(D3D11_COUNTER_INFO));

inline bool operator==(const Counter_info& lhs, const Counter_info& rhs) noexcept {
	return (lhs.LastDeviceDependentCounter == rhs.LastDeviceDependentCounter)
		&& (lhs.NumSimultaneousCounters == rhs.NumSimultaneousCounters)
		&& (lhs.NumDetectableParallelUnits == rhs.NumDetectableParallelUnits);
}

inline bool operator!=(const Counter_info& lhs, const Counter_info& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Draw_instanced_indirect_args {
	Uint _vertex_count_per_instance{ 0 };
	Uint _instance_count{ 0 };
	Uint _start_vertex_location{ 0 };
	Uint _start_instance_location{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Draw_instanced_indirect_args, D3D11_DRAW_INSTANCED_INDIRECT_ARGS)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_vertex_count_per_instance, Uint, VertexCountPerInstance);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_instance_count, Uint, InstanceCount);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_start_vertex_location, Uint, StartVertexLocation);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_start_instance_location, Uint, StartInstanceLocation);
};
static_assert(sizeof(Draw_instanced_indirect_args) == sizeof(D3D11_DRAW_INSTANCED_INDIRECT_ARGS));

inline bool operator==(const Draw_instanced_indirect_args& lhs, const Draw_instanced_indirect_args& rhs) noexcept {
	return (lhs.VertexCountPerInstance == rhs.VertexCountPerInstance)
		&& (lhs.InstanceCount == rhs.InstanceCount)
		&& (lhs.StartVertexLocation == rhs.StartVertexLocation)
		&& (lhs.StartInstanceLocation == rhs.StartInstanceLocation);
}

inline bool operator!=(const Draw_instanced_indirect_args& lhs, const Draw_instanced_indirect_args& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Draw_indexed_instanced_indirect_args {
	Uint _index_count_per_instance{ 0 };
	Uint _instance_count{ 0 };
	Uint _start_index_location{ 0 };
	Int _base_vertex_location{ 0 };
	Uint _start_instance_location{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Draw_indexed_instanced_indirect_args, D3D11_DRAW_INDEXED_INSTANCED_INDIRECT_ARGS)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_index_count_per_instance, Uint, IndexCountPerInstance);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_instance_count, Uint, InstanceCount);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_start_index_location, Uint, StartIndexLocation);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_base_vertex_location, Int, BaseVertexLocation);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_start_instance_location, Uint, StartInstanceLocation);
};
static_assert(sizeof(Draw_indexed_instanced_indirect_args) == sizeof(D3D11_DRAW_INDEXED_INSTANCED_INDIRECT_ARGS));

inline bool operator==(const Draw_indexed_instanced_indirect_args& lhs, const Draw_indexed_instanced_indirect_args& rhs) noexcept {
	return (lhs.IndexCountPerInstance == rhs.IndexCountPerInstance)
		&& (lhs.InstanceCount == rhs.InstanceCount)
		&& (lhs.StartIndexLocation == rhs.StartIndexLocation)
		&& (lhs.BaseVertexLocation == rhs.BaseVertexLocation)
		&& (lhs.StartInstanceLocation == rhs.StartInstanceLocation);
}

inline bool operator!=(const Draw_indexed_instanced_indirect_args& lhs, const Draw_indexed_instanced_indirect_args& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_architecture_info {
	Bool _tile_based_deferred_renderer{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_architecture_info, D3D11_FEATURE_DATA_ARCHITECTURE_INFO)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_tile_based_deferred_renderer, Bool, TileBasedDeferredRenderer);
};
static_assert(sizeof(Feature_data_architecture_info) == sizeof(D3D11_FEATURE_DATA_ARCHITECTURE_INFO));

inline bool operator==(const Feature_data_architecture_info& lhs, const Feature_data_architecture_info& rhs) noexcept {
	return lhs.TileBasedDeferredRenderer == rhs.TileBasedDeferredRenderer;
}

inline bool operator!=(const Feature_data_architecture_info& lhs, const Feature_data_architecture_info& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_d3d9_options {
	Bool _full_non_pow2_texture_support{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_d3d9_options, D3D11_FEATURE_DATA_D3D9_OPTIONS)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_full_non_pow2_texture_support, Bool, FullNonPow2TextureSupport);
};
static_assert(sizeof(Feature_data_d3d9_options) == sizeof(D3D11_FEATURE_DATA_D3D9_OPTIONS));

inline bool operator==(const Feature_data_d3d9_options& lhs, const Feature_data_d3d9_options& rhs) noexcept {
	return lhs.FullNonPow2TextureSupport == rhs.FullNonPow2TextureSupport;
}

inline bool operator!=(const Feature_data_d3d9_options& lhs, const Feature_data_d3d9_options& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_d3d9_options1 {
	Bool _full_non_pow2_texture_supported{ False };
	Bool _depth_as_texture_with_less_equal_comparison_filter_supported{ False };
	Bool _simple_instancing_supported{ False };
	Bool _texture_cube_face_render_target_with_non_cube_depth_stencil_supported{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_d3d9_options1, D3D11_FEATURE_DATA_D3D9_OPTIONS1)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_full_non_pow2_texture_supported, Bool, FullNonPow2TextureSupported);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_depth_as_texture_with_less_equal_comparison_filter_supported, Bool, DepthAsTextureWithLessEqualComparisonFilterSupported);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_simple_instancing_supported, Bool, SimpleInstancingSupported);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_texture_cube_face_render_target_with_non_cube_depth_stencil_supported, Bool, TextureCubeFaceRenderTargetWithNonCubeDepthStencilSupported);
};
static_assert(sizeof(Feature_data_d3d9_options1) == sizeof(D3D11_FEATURE_DATA_D3D9_OPTIONS1));

inline bool operator==(const Feature_data_d3d9_options1& lhs, const Feature_data_d3d9_options1& rhs) noexcept {
	return (lhs.FullNonPow2TextureSupported == rhs.FullNonPow2TextureSupported)
		&& (lhs.DepthAsTextureWithLessEqualComparisonFilterSupported == rhs.DepthAsTextureWithLessEqualComparisonFilterSupported)
		&& (lhs.SimpleInstancingSupported == rhs.SimpleInstancingSupported)
		&& (lhs.TextureCubeFaceRenderTargetWithNonCubeDepthStencilSupported == rhs.TextureCubeFaceRenderTargetWithNonCubeDepthStencilSupported);
}

inline bool operator!=(const Feature_data_d3d9_options1& lhs, const Feature_data_d3d9_options1& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_d3d9_shadow_support {
	Bool _supports_depth_as_texture_with_less_equal_comparison_filter{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_d3d9_shadow_support, D3D11_FEATURE_DATA_D3D9_SHADOW_SUPPORT)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_supports_depth_as_texture_with_less_equal_comparison_filter, Bool, SupportsDepthAsTextureWithLessEqualComparisonFilter);
};
static_assert(sizeof(Feature_data_d3d9_shadow_support) == sizeof(D3D11_FEATURE_DATA_D3D9_SHADOW_SUPPORT));

inline bool operator==(const Feature_data_d3d9_shadow_support& lhs, const Feature_data_d3d9_shadow_support& rhs) noexcept {
	return (lhs.SupportsDepthAsTextureWithLessEqualComparisonFilter == rhs.SupportsDepthAsTextureWithLessEqualComparisonFilter);
}

inline bool operator!=(const Feature_data_d3d9_shadow_support& lhs, const Feature_data_d3d9_shadow_support& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_d3d9_simple_instancing_support {
	Bool _simple_instancing_supported{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_d3d9_simple_instancing_support, D3D11_FEATURE_DATA_D3D9_SIMPLE_INSTANCING_SUPPORT)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_simple_instancing_supported, Bool, SimpleInstancingSupported);
};
static_assert(sizeof(Feature_data_d3d9_simple_instancing_support) == sizeof(D3D11_FEATURE_DATA_D3D9_SIMPLE_INSTANCING_SUPPORT));

inline bool operator==(const Feature_data_d3d9_simple_instancing_support& lhs, const Feature_data_d3d9_simple_instancing_support& rhs) noexcept {
	return lhs.SimpleInstancingSupported == rhs.SimpleInstancingSupported;
}

inline bool operator!=(const Feature_data_d3d9_simple_instancing_support& lhs, const Feature_data_d3d9_simple_instancing_support& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_d3d10x_hardaware_options {
	Bool _compute_shaders_plus_raw_and_structure_buffers_via_shader_4_x{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_d3d10x_hardaware_options, D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_compute_shaders_plus_raw_and_structure_buffers_via_shader_4_x, Bool, ComputeShaders_Plus_RawAndStructuredBuffers_Via_Shader_4_x);
};
static_assert(sizeof(Feature_data_d3d10x_hardaware_options) == sizeof(D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS));

inline bool operator==(const Feature_data_d3d10x_hardaware_options& lhs, const Feature_data_d3d10x_hardaware_options& rhs) noexcept {
	return lhs.ComputeShaders_Plus_RawAndStructuredBuffers_Via_Shader_4_x == rhs.ComputeShaders_Plus_RawAndStructuredBuffers_Via_Shader_4_x;
}

inline bool operator!=(const Feature_data_d3d10x_hardaware_options& lhs, const Feature_data_d3d10x_hardaware_options& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_d3d11_options {
	Bool _output_merger_logic_op{ False };
	Bool _uav_only_rendering_forced_sample_count{ False };
	Bool _discard_api_is_seen_by_driver{ False };
	Bool _flags_for_update_and_copy_seen_by_driver{ False };
	Bool _clear_view{ False };
	Bool _copy_with_overlap{ False };
	Bool _constant_buffer_partial_update{ False };
	Bool _constant_buffer_offsetting{ False };
	Bool _map_no_overwrite_on_dynamic_constant_buffer{ False };
	Bool _map_no_overwrite_on_dynamic_buffer_srv{ False };
	Bool _multisample_rtv_with_forced_sample_count_one{ False };
	Bool _sad4_shader_instructions{ False };
	Bool _extended_doubles_shader_instructions{ False };
	Bool _extended_resource_sharing{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_d3d11_options, D3D11_FEATURE_DATA_D3D11_OPTIONS)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_output_merger_logic_op, Bool, OutputMergerLogicOp);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_uav_only_rendering_forced_sample_count, Bool, UAVOnlyRenderingForcedSampleCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_discard_api_is_seen_by_driver, Bool, DiscardAPIsSeenByDriver);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_flags_for_update_and_copy_seen_by_driver, Bool, FlagsForUpdateAndCopySeenByDriver);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_clear_view, Bool, ClearView);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_copy_with_overlap, Bool, CopyWithOverlap);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_constant_buffer_partial_update, Bool, ConstantBufferPartialUpdate);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_constant_buffer_offsetting, Bool, ConstantBufferOffsetting);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_map_no_overwrite_on_dynamic_constant_buffer, Bool, MapNoOverwriteOnDynamicConstantBuffer);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_map_no_overwrite_on_dynamic_buffer_srv, Bool, MapNoOverwriteOnDynamicBufferSRV);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_multisample_rtv_with_forced_sample_count_one, Bool, MultisampleRTVWithForcedSampleCountOne);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_sad4_shader_instructions, Bool, SAD4ShaderInstructions);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_extended_doubles_shader_instructions, Bool, ExtendedDoublesShaderInstructions);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_extended_resource_sharing, Bool, ExtendedResourceSharing);
};
static_assert(sizeof(Feature_data_d3d11_options) == sizeof(D3D11_FEATURE_DATA_D3D11_OPTIONS));

inline bool operator==(const Feature_data_d3d11_options& lhs, const Feature_data_d3d11_options& rhs) noexcept {
	return (lhs.ClearView == rhs.ClearView)
		&& (lhs.ConstantBufferOffsetting == rhs.ConstantBufferOffsetting)
		&& (lhs.ConstantBufferPartialUpdate == rhs.ConstantBufferPartialUpdate)
		&& (lhs.CopyWithOverlap == rhs.CopyWithOverlap)
		&& (lhs.DiscardAPIsSeenByDriver == rhs.DiscardAPIsSeenByDriver)
		&& (lhs.ExtendedDoublesShaderInstructions == rhs.ExtendedDoublesShaderInstructions)
		&& (lhs.ExtendedResourceSharing == rhs.ExtendedResourceSharing)
		&& (lhs.FlagsForUpdateAndCopySeenByDriver == rhs.FlagsForUpdateAndCopySeenByDriver)
		&& (lhs.MapNoOverwriteOnDynamicBufferSRV == rhs.MapNoOverwriteOnDynamicBufferSRV)
		&& (lhs.MapNoOverwriteOnDynamicConstantBuffer == rhs.MapNoOverwriteOnDynamicConstantBuffer)
		&& (lhs.MultisampleRTVWithForcedSampleCountOne == rhs.MultisampleRTVWithForcedSampleCountOne)
		&& (lhs.OutputMergerLogicOp == rhs.OutputMergerLogicOp)
		&& (lhs.SAD4ShaderInstructions == rhs.SAD4ShaderInstructions)
		&& (lhs.UAVOnlyRenderingForcedSampleCount == rhs.UAVOnlyRenderingForcedSampleCount);
}

inline bool operator!=(const Feature_data_d3d11_options& lhs, const Feature_data_d3d11_options& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_d3d11_options1 {
	Tiled_resources_tier _tiled_resources_tier{ Tiled_resources_tier::not_supported };
	Bool _min_max_filtering{ False };
	Bool _clear_view_also_supported_depth_only_formats{ False };
	Bool _map_on_default_buffers{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_d3d11_options1, D3D11_FEATURE_DATA_D3D11_OPTIONS1)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_tiled_resources_tier, _HW_3D_D3D_ Tiled_resources_tier, TiledResourcesTier);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_min_max_filtering, Bool, MinMaxFiltering);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_clear_view_also_supported_depth_only_formats, Bool, ClearViewAlsoSupportsDepthOnlyFormats);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_map_on_default_buffers, Bool, MapOnDefaultBuffers);
};
static_assert(sizeof(Feature_data_d3d11_options1) == sizeof(D3D11_FEATURE_DATA_D3D11_OPTIONS1));

inline bool operator==(const Feature_data_d3d11_options1& lhs, const Feature_data_d3d11_options1& rhs) noexcept {
	return (lhs.ClearViewAlsoSupportsDepthOnlyFormats == rhs.ClearViewAlsoSupportsDepthOnlyFormats)
		&& (lhs.MapOnDefaultBuffers == rhs.MapOnDefaultBuffers)
		&& (lhs.MinMaxFiltering == rhs.MinMaxFiltering)
		&& (lhs.TiledResourcesTier == rhs.TiledResourcesTier);
}

inline bool operator!=(const Feature_data_d3d11_options1& lhs, const Feature_data_d3d11_options1& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_d3d11_options2 {
	Bool _ps_specified_stencil_ref_supported{ False };
	Bool _typed_uav_load_additional_formats{ False };
	Bool _rovs_supported{ False };
	Conservative_rasterization_tier _conservative_rasterization_tier{ Conservative_rasterization_tier::none };
	Tiled_resources_tier _tiled_resources_tier{ Tiled_resources_tier::not_supported };
	Bool _map_on_default_textures{ False };
	Bool _standard_swizzle{ False };
	Bool _unified_memory_architecture{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_d3d11_options2, D3D11_FEATURE_DATA_D3D11_OPTIONS2)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_ps_specified_stencil_ref_supported, Bool, PSSpecifiedStencilRefSupported);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_typed_uav_load_additional_formats, Bool, TypedUAVLoadAdditionalFormats);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_rovs_supported, Bool, ROVsSupported);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_conservative_rasterization_tier, _HW_3D_D3D_ Conservative_rasterization_tier, ConservativeRasterizationTier);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_tiled_resources_tier, _HW_3D_D3D_ Tiled_resources_tier, TiledResourcesTier);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_map_on_default_textures, Bool, MapOnDefaultTextures);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_standard_swizzle, Bool, StandardSwizzle);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_unified_memory_architecture, Bool, UnifiedMemoryArchitecture);
};
static_assert(sizeof(Feature_data_d3d11_options2) == sizeof(D3D11_FEATURE_DATA_D3D11_OPTIONS2));

inline bool operator==(const Feature_data_d3d11_options2& lhs, const Feature_data_d3d11_options2& rhs) noexcept {
	return (lhs.ConservativeRasterizationTier == rhs.ConservativeRasterizationTier)
		&& (lhs.MapOnDefaultTextures == rhs.MapOnDefaultTextures)
		&& (lhs.PSSpecifiedStencilRefSupported == rhs.PSSpecifiedStencilRefSupported)
		&& (lhs.ROVsSupported == rhs.ROVsSupported)
		&& (lhs.StandardSwizzle == rhs.StandardSwizzle)
		&& (lhs.TiledResourcesTier == rhs.TiledResourcesTier)
		&& (lhs.TypedUAVLoadAdditionalFormats == rhs.TypedUAVLoadAdditionalFormats)
		&& (lhs.UnifiedMemoryArchitecture == rhs.UnifiedMemoryArchitecture);
}

inline bool operator!=(const Feature_data_d3d11_options2& lhs, const Feature_data_d3d11_options2& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_d3d11_options3 {
	Bool _vp_and_rt_array_index_from_any_shader_feeding_rasterizer{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_d3d11_options3, D3D11_FEATURE_DATA_D3D11_OPTIONS3)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_vp_and_rt_array_index_from_any_shader_feeding_rasterizer, Bool, VPAndRTArrayIndexFromAnyShaderFeedingRasterizer);
};
static_assert(sizeof(Feature_data_d3d11_options3) == sizeof(D3D11_FEATURE_DATA_D3D11_OPTIONS3));

inline bool operator==(const Feature_data_d3d11_options3& lhs, const Feature_data_d3d11_options3& rhs) noexcept {
	return lhs.VPAndRTArrayIndexFromAnyShaderFeedingRasterizer == rhs.VPAndRTArrayIndexFromAnyShaderFeedingRasterizer;
}

inline bool operator!=(const Feature_data_d3d11_options3& lhs, const Feature_data_d3d11_options3& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_d3d11_options4 {
	Bool _extended_nv12_shared_texture_supported{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_d3d11_options4, D3D11_FEATURE_DATA_D3D11_OPTIONS4)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_extended_nv12_shared_texture_supported, Bool, ExtendedNV12SharedTextureSupported);
};
static_assert(sizeof(Feature_data_d3d11_options4) == sizeof(D3D11_FEATURE_DATA_D3D11_OPTIONS4));

inline bool operator==(const Feature_data_d3d11_options4& lhs, const Feature_data_d3d11_options4& rhs) noexcept {
	return lhs.ExtendedNV12SharedTextureSupported == rhs.ExtendedNV12SharedTextureSupported;
}

inline bool operator!=(const Feature_data_d3d11_options4& lhs, const Feature_data_d3d11_options4& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_doubles {
	Bool _double_precision_float_shader_ops{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_doubles, D3D11_FEATURE_DATA_DOUBLES)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_double_precision_float_shader_ops, Bool, DoublePrecisionFloatShaderOps);
};
static_assert(sizeof(Feature_data_doubles) == sizeof(D3D11_FEATURE_DATA_DOUBLES));

inline bool operator==(const Feature_data_doubles& lhs, const Feature_data_doubles& rhs) noexcept {
	return lhs.DoublePrecisionFloatShaderOps == rhs.DoublePrecisionFloatShaderOps;
}

inline bool operator!=(const Feature_data_doubles& lhs, const Feature_data_doubles& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_format_support {
	_HW_3D_DXGI_ Format _in_format{};
	Uint _out_format_support{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_format_support, D3D11_FEATURE_DATA_FORMAT_SUPPORT)
public:
	Format_support get_out_format_support() const noexcept {
		return Format_support_bit(_out_format_support);
	}

	__declspec(property(get = get_out_format_support)) Format_support OutFormatSupport;
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_in_format, _HW_3D_DXGI_ Format, InFormat);
};
static_assert(sizeof(Feature_data_format_support) == sizeof(D3D11_FEATURE_DATA_FORMAT_SUPPORT));

inline bool operator==(const Feature_data_format_support& lhs, const Feature_data_format_support& rhs) noexcept {
	return (lhs.InFormat == rhs.InFormat)
		&& (lhs.OutFormatSupport == rhs.OutFormatSupport);
}

inline bool operator!=(const Feature_data_format_support& lhs, const Feature_data_format_support& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_format_support2 {
	_HW_3D_DXGI_ Format _in_format{};
	Uint _out_format_support_2{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_format_support2, D3D11_FEATURE_DATA_FORMAT_SUPPORT2)
public:
	Format_support2 get_out_format_support_2() const noexcept {
		return Format_support2_bit(_out_format_support_2);
	}

	__declspec(property(get = get_out_format_support_2)) Format_support2 OutFormatSupport2;
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_in_format, _HW_3D_DXGI_ Format, InFormat);
};
static_assert(sizeof(Feature_data_format_support2) == sizeof(D3D11_FEATURE_DATA_FORMAT_SUPPORT2));

inline bool operator==(const Feature_data_format_support2& lhs, const Feature_data_format_support2& rhs) noexcept {
	return (lhs.InFormat == rhs.InFormat)
		&& (lhs.OutFormatSupport2 == rhs.OutFormatSupport2);
}

inline bool operator!=(const Feature_data_format_support2& lhs, const Feature_data_format_support2& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_gpu_virtual_address_support {
	Uint _max_gpu_virtual_address_bits_per_resource{ 0 };
	Uint _max_gpu_virtual_address_bits_per_process{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_gpu_virtual_address_support, D3D11_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_max_gpu_virtual_address_bits_per_resource, Uint, MaxGPUVirtualAddressBitsPerResource);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_max_gpu_virtual_address_bits_per_process, Uint, MaxGPUVirtualAddressBitsPerProcess);
};
static_assert(sizeof(Feature_data_gpu_virtual_address_support) == sizeof(D3D11_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT));

inline bool operator==(const Feature_data_gpu_virtual_address_support& lhs, const Feature_data_gpu_virtual_address_support& rhs) {
	return (lhs.MaxGPUVirtualAddressBitsPerProcess == rhs.MaxGPUVirtualAddressBitsPerProcess)
		&& (lhs.MaxGPUVirtualAddressBitsPerResource == rhs.MaxGPUVirtualAddressBitsPerResource);
}

inline bool operator!=(const Feature_data_gpu_virtual_address_support& lhs, const Feature_data_gpu_virtual_address_support& rhs) {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_marker_support {
	Bool _profile{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_marker_support, D3D11_FEATURE_DATA_MARKER_SUPPORT)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_profile, Bool, Profile);
};
static_assert(sizeof(Feature_data_marker_support) == sizeof(D3D11_FEATURE_DATA_MARKER_SUPPORT));

inline bool operator==(const Feature_data_marker_support& lhs, const Feature_data_marker_support& rhs) noexcept {
	return lhs.Profile == rhs.Profile;
}

inline bool operator!=(const Feature_data_marker_support& lhs, const Feature_data_marker_support& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_shader_cache {
	Uint _support_flags{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_shader_cache, D3D11_FEATURE_DATA_SHADER_CACHE)
public:
	Shader_cache_support_flag get_support_flags() const noexcept {
		return Shader_cache_support_flag_bit(_support_flags);
	}

	__declspec(property(get = get_support_flags)) Shader_cache_support_flag SupportFlags;
};
static_assert(sizeof(Feature_data_shader_cache) == sizeof(D3D11_FEATURE_DATA_SHADER_CACHE));

inline bool operator==(const Feature_data_shader_cache& lhs, const Feature_data_shader_cache& rhs) noexcept {
	return lhs.SupportFlags == rhs.SupportFlags;
}

inline bool operator!=(const Feature_data_shader_cache& lhs, const Feature_data_shader_cache& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_shader_min_precision_support {
	Uint _pixel_shader_min_precision{ 0 };
	Uint _all_other_shader_stages_min_precision{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_shader_min_precision_support, D3D11_FEATURE_DATA_SHADER_MIN_PRECISION_SUPPORT)
public:

	Shader_min_precision_support get_pixel_shader_min_precision() const noexcept {
		return Shader_min_precision_support_bit(_pixel_shader_min_precision);
	}

	Shader_min_precision_support get_all_other_shader_stages_min_precision() const noexcept {
		return Shader_min_precision_support_bit(_all_other_shader_stages_min_precision);
	}

	__declspec(property(get = get_pixel_shader_min_precision)) Shader_min_precision_support PixelShaderMinPrecision;
	__declspec(property(get = get_all_other_shader_stages_min_precision)) Shader_min_precision_support AllOtherShaderStagesMinPrecision;
};
static_assert(sizeof(Feature_data_shader_min_precision_support) == sizeof(D3D11_FEATURE_DATA_SHADER_MIN_PRECISION_SUPPORT));

inline bool operator==(const Feature_data_shader_min_precision_support& lhs, const Feature_data_shader_min_precision_support& rhs) noexcept {
	return (lhs.AllOtherShaderStagesMinPrecision == rhs.AllOtherShaderStagesMinPrecision)
		&& (lhs.PixelShaderMinPrecision == rhs.PixelShaderMinPrecision);
}

inline bool operator!=(const Feature_data_shader_min_precision_support& lhs, const Feature_data_shader_min_precision_support& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Feature_data_threading {
	Bool _driver_concurrent_creates{ False };
	Bool _driver_command_lists{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Feature_data_threading, D3D11_FEATURE_DATA_THREADING)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_driver_concurrent_creates, Bool, DriverConcurrentCreates);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_driver_command_lists, Bool, DriverCommandLists);
};
static_assert(sizeof(Feature_data_threading) == sizeof(D3D11_FEATURE_DATA_THREADING));

inline bool operator==(const Feature_data_threading& lhs, const Feature_data_threading& rhs) noexcept {
	return (lhs.DriverConcurrentCreates == rhs.DriverConcurrentCreates)
		&& (lhs.DriverCommandLists == rhs.DriverCommandLists);
}

inline bool operator!=(const Feature_data_threading& lhs, const Feature_data_threading& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Query_data_pipeline_statistics {
	Uint64 _ia_vertices{ 0 };
	Uint64 _ia_primitives{ 0 };
	Uint64 _vs_invocations{ 0 };
	Uint64 _gs_invocations{ 0 };
	Uint64 _gs_primitives{ 0 };
	Uint64 _c_invocations{ 0 };
	Uint64 _c_primitives{ 0 };
	Uint64 _ps_invocations{ 0 };
	Uint64 _hs_invocations{ 0 };
	Uint64 _ds_invocations{ 0 };
	Uint64 _cs_invocations{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Query_data_pipeline_statistics, D3D11_QUERY_DATA_PIPELINE_STATISTICS)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_ia_vertices, Uint64, IAVertices);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_ia_primitives, Uint64, IAPrimitives);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_vs_invocations, Uint64, VSInvocations);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_gs_invocations, Uint64, GSInvocations);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_gs_primitives, Uint64, GSPrimitives);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_c_invocations, Uint64, CInvocations);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_c_primitives, Uint64, CPrimitives);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_ps_invocations, Uint64, PSInvocations);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_hs_invocations, Uint64, HSInvocations);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_ds_invocations, Uint64, DSInvocations);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_cs_invocations, Uint64, CSInvocations);
};
static_assert(sizeof(Query_data_pipeline_statistics) == sizeof(D3D11_QUERY_DATA_PIPELINE_STATISTICS));

inline bool operator==(const Query_data_pipeline_statistics& lhs, const Query_data_pipeline_statistics& rhs) noexcept {
	return (lhs.IAVertices == rhs.IAVertices)
		&& (lhs.IAPrimitives == rhs.IAPrimitives)
		&& (lhs.VSInvocations == rhs.VSInvocations)
		&& (lhs.GSInvocations == rhs.GSInvocations)
		&& (lhs.GSPrimitives == rhs.GSPrimitives)
		&& (lhs.CInvocations == rhs.CInvocations)
		&& (lhs.CPrimitives == rhs.CPrimitives)
		&& (lhs.PSInvocations == rhs.PSInvocations)
		&& (lhs.HSInvocations == rhs.HSInvocations)
		&& (lhs.DSInvocations == rhs.DSInvocations)
		&& (lhs.CSInvocations == rhs.CSInvocations);
}

inline bool operator!=(const Query_data_pipeline_statistics& lhs, const Query_data_pipeline_statistics& rhs) {
	return !operator==(lhs, rhs);
}

//
//
class Query_data_so_statistics {
	Uint64 _num_primitives_written{ 0 };
	Uint64 _primitives_storage_needed{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Query_data_so_statistics, D3D11_QUERY_DATA_SO_STATISTICS)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_num_primitives_written, Uint64, NumPrimitivesWritten);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_primitives_storage_needed, Uint64, PrimitivesStorageNeeded);
};
static_assert(sizeof(Query_data_so_statistics) == sizeof(D3D11_QUERY_DATA_SO_STATISTICS));

inline bool operator==(const Query_data_so_statistics& lhs, const Query_data_so_statistics& rhs) noexcept {
	return (lhs.NumPrimitivesWritten == rhs.NumPrimitivesWritten)
		&& (lhs.PrimitivesStorageNeeded == rhs.PrimitivesStorageNeeded);
}

inline bool operator!=(const Query_data_so_statistics& lhs, const Query_data_so_statistics& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Query_data_timestamp_disjoint {
	Uint64 _frequency{ 0 };
	Bool _disjoint{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Query_data_timestamp_disjoint, D3D11_QUERY_DATA_TIMESTAMP_DISJOINT)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_frequency, Uint64, Frequency);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_disjoint, Bool, Disjoint);
};
static_assert(sizeof(Query_data_timestamp_disjoint) == sizeof(D3D11_QUERY_DATA_TIMESTAMP_DISJOINT));

inline bool operator==(const Query_data_timestamp_disjoint& lhs, const Query_data_timestamp_disjoint& rhs) noexcept {
	return (lhs.Frequency == rhs.Frequency)
		&& (lhs.Disjoint == rhs.Disjoint);
}

inline bool operator!=(const Query_data_timestamp_disjoint& lhs, const Query_data_timestamp_disjoint& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Rect {
	Long _left{ 0 };
	Long _top{ 0 };
	Long _right{ 0 };
	Long _bottom{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Rect, D3D11_RECT)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_left, Long, left);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_top, Long, top);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_right, Long, right);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_bottom, Long, bottom);
};
static_assert(sizeof(Rect) == sizeof(D3D11_RECT));

inline bool operator==(const Rect& lhs, const Rect& rhs) noexcept {
	return (lhs.left == rhs.left)
		&& (lhs.right == rhs.right)
		&& (lhs.top == rhs.top)
		&& (lhs.bottom == rhs.bottom);
}

inline bool operator!=(const Rect& lhs, const Rect& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class So_declaration_entry {
	Uint _stream{ 0 };
	Pcstr _semantic_name{ nullptr };
	Uint _semantic_index{ 0 };
	Byte _start_component{ 0 };
	Byte _compoent_count{ 0 };
	Byte _output_slot{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(So_declaration_entry, D3D11_SO_DECLARATION_ENTRY)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_stream, Uint, Stream);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_semantic_name, Pcstr, SemanticName);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_semantic_index, Uint, SemanticIndex);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_start_component, Byte, StartComponent);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_compoent_count, Byte, ComponentCount);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_output_slot, Byte, OutputSlot);
};
static_assert(sizeof(So_declaration_entry) == sizeof(D3D11_SO_DECLARATION_ENTRY));

inline bool operator==(const So_declaration_entry& lhs, const So_declaration_entry& rhs) noexcept {
	return (lhs.Stream == rhs.Stream)
		&& (lhs.SemanticIndex == rhs.SemanticIndex)
		&& (lhs.SemanticName == rhs.SemanticName)
		&& (lhs.ComponentCount == rhs.ComponentCount)
		&& (lhs.OutputSlot == rhs.OutputSlot);
}

inline bool operator!=(const So_declaration_entry& lhs, const So_declaration_entry& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Viewport {
	Float _top_left_x{ 0.0f };
	Float _top_left_y{ 0.0f };
	Float _width{ 0.0f };
	Float _height{ 0.0f };
	Float _min_depth{ 0.0f };
	Float _max_depth{ 0.0f };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Viewport, D3D11_VIEWPORT)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_top_left_x, Float, TopLeftX);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_top_left_y, Float, TopLeftY);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_width, Float, Width);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_height, Float, Height);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_min_depth, Float, MinDepth);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_max_depth, Float, MaxDepth);
};
static_assert(sizeof(Viewport) == sizeof(D3D11_VIEWPORT));

inline bool operator==(const Viewport& lhs, const Viewport& rhs) noexcept {
	return (lhs.TopLeftX == rhs.TopLeftX)
		&& (lhs.TopLeftY == rhs.TopLeftY)
		&& (lhs.Width == rhs.Width)
		&& (lhs.Height == rhs.Height)
		&& (lhs.MinDepth == rhs.MinDepth)
		&& (lhs.MaxDepth == rhs.MaxDepth);
}

inline bool operator!=(const Viewport& lhs, const Viewport& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Message {
	Message_category _category{};
	Message_severity _severity{};
	Message_id _id{};
	const char* _p_description{ nullptr };
	Size_t _description_byte_length{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Message, D3D11_MESSAGE)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_category, Message_category, Category);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_severity, Message_severity, Severity);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_id, Message_id, ID);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_p_description, const char*, pDescription);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_description_byte_length, Size_t, DescriptionByteLength);
};
static_assert(sizeof(Message) == sizeof(D3D11_MESSAGE));

inline bool operator==(const Message& lhs, const Message& rhs) noexcept {
	return (lhs.Category == rhs.Category)
		&& (lhs.Severity == rhs.Severity)
		&& (lhs.ID == rhs.ID)
		&& (lhs.DescriptionByteLength == rhs.DescriptionByteLength)
		&& (memcmp(lhs.pDescription, rhs.pDescription, lhs.DescriptionByteLength) == 0);
}

inline bool operator!=(const Message& lhs, const Message& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Buffer_rtv {
	union {
		Uint _first_element;
		Uint _element_offset;
	};
	union {
		Uint _num_elements;
		Uint _element_width;
	};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Buffer_rtv, D3D11_BUFFER_RTV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_element, Uint, FirstElement);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_element_offset, Uint, ElementOffset);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_num_elements, Uint, NumElements);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_element_width, Uint, ElementWidth);
};
static_assert(sizeof(Buffer_rtv) == sizeof(D3D11_BUFFER_RTV));

inline bool operator==(const Buffer_rtv& lhs, const Buffer_rtv& rhs) noexcept {
	return (lhs.FirstElement == rhs.FirstElement)
		&& (lhs.ElementWidth == rhs.ElementWidth);
}

inline bool operator!=(const Buffer_rtv& lhs, const Buffer_rtv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Buffer_srv {
	union {
		Uint _first_element;
		Uint _element_offset;
	};
	union {
		Uint _num_elements;
		Uint _element_width;
	};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Buffer_srv, D3D11_BUFFER_SRV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_element, Uint, FirstElement);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_element_offset, Uint, ElementOffset);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_num_elements, Uint, NumElements);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_element_width, Uint, ElementWidth);
};
static_assert(sizeof(Buffer_srv) == sizeof(D3D11_BUFFER_SRV));

inline bool operator==(const Buffer_srv& lhs, const Buffer_srv& rhs) noexcept {
	return (lhs.FirstElement == rhs.FirstElement)
		&& (lhs.ElementWidth == rhs.ElementWidth);
}

inline bool operator!=(const Buffer_srv& lhs, const Buffer_srv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Buffer_uav {
	Uint _first_element{ 0 };
	Uint _num_elements{ 0 };
	Uint _flags{ 0 };
public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Buffer_uav, D3D11_BUFFER_UAV)
public:
	Buffer_uav & set_flags(Buffer_uav_flag flags_) {
		_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Buffer_uav_flag get_flags() const noexcept {
		return Buffer_uav_flag_bit(_flags);
	}

	__declspec(property(get = get_flags, put = set_flags)) Buffer_uav_flag Flags;
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_element, Uint, FirstElement);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_num_elements, Uint, NumElements);
};
static_assert(sizeof(Buffer_uav) == sizeof(D3D11_BUFFER_UAV));

inline bool operator==(const Buffer_uav& lhs, const Buffer_uav& rhs) noexcept {
	return (lhs.FirstElement == rhs.FirstElement)
		&& (lhs.NumElements == rhs.NumElements)
		&& (lhs.Flags == rhs.Flags);
}

inline bool operator!=(const Buffer_uav& lhs, const Buffer_uav& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Buffer_ex_srv {
	Uint _first_element{ 0 };
	Uint _num_elements{ 0 };
	Uint _flags{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Buffer_ex_srv, D3D11_BUFFEREX_SRV)
public:
	Buffer_ex_srv & set_flags(Buffer_ex_srv_flag flags_) {
		_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Buffer_ex_srv_flag get_flags() const noexcept {
		return Buffer_ex_srv_flag_bit(_flags);
	}

	__declspec(property(get = get_flags, put = set_flags)) Buffer_ex_srv_flag Flags;
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_element, Uint, FirstElement);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_num_elements, Uint, NumElements);
};
static_assert(sizeof(Buffer_ex_srv) == sizeof(D3D11_BUFFEREX_SRV));

inline bool operator==(const Buffer_ex_srv& lhs, const Buffer_ex_srv& rhs) noexcept {
	return (lhs.FirstElement == rhs.FirstElement)
		&& (lhs.NumElements == rhs.NumElements)
		&& (lhs.Flags == rhs.Flags);
}

inline bool operator!=(const Buffer_ex_srv& lhs, const Buffer_ex_srv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Mapped_subresource {
	void *_p_data{ nullptr };
	Uint _row_pitch{ 0 };
	Uint _depth_pitch{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Mapped_subresource, D3D11_MAPPED_SUBRESOURCE)
public:

	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_p_data, void*, pData);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_row_pitch, Uint, RowPitch);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_depth_pitch, Uint, DepthPitch);
};
static_assert(sizeof(Mapped_subresource) == sizeof(D3D11_MAPPED_SUBRESOURCE));

inline bool operator==(const Mapped_subresource& lhs, const Mapped_subresource& rhs) noexcept {
	return (lhs.pData == rhs.pData)
		&& (lhs.RowPitch == rhs.RowPitch)
		&& (lhs.DepthPitch == rhs.DepthPitch);
}

inline bool operator!=(const Mapped_subresource& lhs, const Mapped_subresource& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Subresource_data {
	const void* _p_sys_mem{ nullptr };
	Uint _sys_mem_pitch{ 0 };
	Uint _sys_mem_slice_pitch{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Subresource_data, D3D11_SUBRESOURCE_DATA)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_p_sys_mem, const void*, pSysMem);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_sys_mem_pitch, Uint, SysMemPitch);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_sys_mem_slice_pitch, Uint, SysMemSlicePitch);
};
static_assert(sizeof(Subresource_data) == sizeof(D3D11_SUBRESOURCE_DATA));

inline bool operator==(const Subresource_data& lhs, const Subresource_data& rhs) noexcept {
	return (lhs.pSysMem == rhs.pSysMem)
		&& (lhs.SysMemPitch == rhs.SysMemPitch)
		&& (lhs.SysMemSlicePitch == rhs.SysMemSlicePitch);
}

inline bool operator!=(const Subresource_data& lhs, const Subresource_data& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Subresource_tiling {
	Uint _width_in_tiles{ 0 };
	Uint16 _height_in_tiles{ 0 };
	Uint16 _depth_in_tiles{ 0 };
	Uint _start_tile_index_in_overall_resource{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Subresource_tiling, D3D11_SUBRESOURCE_TILING)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_width_in_tiles, Uint, WidthInTiles);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_height_in_tiles, Uint16, HeightInTiles);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_depth_in_tiles, Uint16, DepthInTiles);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_start_tile_index_in_overall_resource, Uint, StartTileIndexInOverallResource);
};
static_assert(sizeof(Subresource_tiling) == sizeof(D3D11_SUBRESOURCE_TILING));

inline bool operator==(const Subresource_tiling& lhs, const Subresource_tiling& rhs) noexcept {
	return (lhs.WidthInTiles == rhs.WidthInTiles)
		&& (lhs.HeightInTiles == rhs.HeightInTiles)
		&& (lhs.DepthInTiles == rhs.DepthInTiles)
		&& (lhs.StartTileIndexInOverallResource == rhs.StartTileIndexInOverallResource);
}

inline bool operator!=(const Subresource_tiling& lhs, const Subresource_tiling& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex1d_array_dsv {
	Uint _mip_slice{ 0 };
	Uint _first_array_slice{ 0 };
	Uint _array_size{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex1d_array_dsv, D3D11_TEX1D_ARRAY_DSV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_array_slice, Uint, FirstArraySlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_array_size, Uint, ArraySize);
};
static_assert(sizeof(Tex1d_array_dsv) == sizeof(D3D11_TEX1D_ARRAY_DSV));

inline bool operator==(const Tex1d_array_dsv& lhs, const Tex1d_array_dsv& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice)
		&& (lhs.FirstArraySlice == rhs.FirstArraySlice)
		&& (lhs.ArraySize == rhs.ArraySize);
}

inline bool operator!=(const Tex1d_array_dsv& lhs, const Tex1d_array_dsv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex1d_array_rtv {
	Uint _mip_slice{ 0 };
	Uint _first_array_slice{ 0 };
	Uint _array_size{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex1d_array_rtv, D3D11_TEX1D_ARRAY_RTV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_array_slice, Uint, FirstArraySlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_array_size, Uint, ArraySize);
};
static_assert(sizeof(Tex1d_array_rtv) == sizeof(D3D11_TEX1D_ARRAY_RTV));

inline bool operator==(const Tex1d_array_rtv& lhs, const Tex1d_array_rtv& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice)
		&& (lhs.FirstArraySlice == rhs.FirstArraySlice)
		&& (lhs.ArraySize == rhs.ArraySize);
}

inline bool operator!=(const Tex1d_array_rtv& lhs, const Tex1d_array_rtv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex1d_array_srv {
	Uint _most_detailed_mip{ 0 };
	Uint _mip_levels{ 0 };
	Uint _first_array_slice{ 0 };
	Uint _array_size{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex1d_array_srv, D3D11_TEX1D_ARRAY_SRV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_most_detailed_mip, Uint, MostDetailedMip);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_levels, Uint, MipLevels);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_array_slice, Uint, FirstArraySlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_array_size, Uint, ArraySize);
};
static_assert(sizeof(Tex1d_array_srv) == sizeof(D3D11_TEX1D_ARRAY_SRV));

inline bool operator==(const Tex1d_array_srv& lhs, const Tex1d_array_srv& rhs) noexcept {
	return (lhs.MostDetailedMip == rhs.MostDetailedMip)
		&& (lhs.MipLevels == rhs.MipLevels)
		&& (lhs.FirstArraySlice == rhs.FirstArraySlice)
		&& (lhs.ArraySize == rhs.ArraySize);
}

inline bool operator!=(const Tex1d_array_srv& lhs, const Tex1d_array_srv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex1d_array_uav {
	Uint _mip_slice{ 0 };
	Uint _first_array_slice{ 0 };
	Uint _array_size{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex1d_array_uav, D3D11_TEX1D_ARRAY_UAV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_array_slice, Uint, FirstArraySlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_array_size, Uint, ArraySize);
};
static_assert(sizeof(Tex1d_array_uav) == sizeof(D3D11_TEX1D_ARRAY_UAV));

inline bool operator==(const Tex1d_array_uav& lhs, const Tex1d_array_uav& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice)
		&& (lhs.FirstArraySlice == rhs.FirstArraySlice)
		&& (lhs.ArraySize == rhs.ArraySize);
}

inline bool operator!=(const Tex1d_array_uav& lhs, const Tex1d_array_uav& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex1d_dsv {
	Uint _mip_slice{ 0 };
public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex1d_dsv, D3D11_TEX1D_DSV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
};
static_assert(sizeof(Tex1d_dsv) == sizeof(D3D11_TEX1D_DSV));

inline bool operator==(const Tex1d_dsv& lhs, const Tex1d_dsv& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice);
}

inline bool operator!=(const Tex1d_dsv& lhs, const Tex1d_dsv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex1d_rtv {
	Uint _mip_slice{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex1d_rtv, D3D11_TEX1D_RTV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
};
static_assert(sizeof(Tex1d_rtv) == sizeof(D3D11_TEX1D_RTV));

inline bool operator==(const Tex1d_rtv& lhs, const Tex1d_rtv& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice);
}

inline bool operator!=(const Tex1d_rtv& lhs, const Tex1d_rtv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex1d_srv {
	Uint _most_detailed_mip{ 0 };
	Uint _mip_levels{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex1d_srv, D3D11_TEX1D_SRV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_most_detailed_mip, Uint, MostDetailedMip);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_levels, Uint, MipLevels);
};
static_assert(sizeof(Tex1d_srv) == sizeof(D3D11_TEX1D_SRV));

inline bool operator==(const Tex1d_srv& lhs, const Tex1d_srv& rhs) noexcept {
	return (lhs.MostDetailedMip == rhs.MostDetailedMip)
		&& (lhs.MipLevels == rhs.MipLevels);
}

inline bool operator!=(const Tex1d_srv& lhs, const Tex1d_srv& rhs) {
	return !operator==(lhs, rhs);
}

//
//
class Tex1d_uav {
	Uint _mip_slice{ 0 };
public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex1d_uav, D3D11_TEX1D_UAV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
};
static_assert(sizeof(Tex1d_uav) == sizeof(D3D11_TEX1D_UAV));

inline bool operator==(const Tex1d_uav& lhs, const Tex1d_uav& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice);
}

inline bool operator!=(const Tex1d_uav& lhs, const Tex1d_uav& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex2d_array_dsv {
	Uint _mip_slice{ 0 };
	Uint _first_array_slice{ 0 };
	Uint _array_size{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2d_array_dsv, D3D11_TEX2D_ARRAY_DSV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_array_slice, Uint, FirstArraySlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_array_size, Uint, ArraySize);
};
static_assert(sizeof(Tex2d_array_dsv) == sizeof(D3D11_TEX2D_ARRAY_DSV));

inline bool operator==(const Tex2d_array_dsv& lhs, const Tex2d_array_dsv& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice)
		&& (lhs.FirstArraySlice == rhs.FirstArraySlice)
		&& (lhs.ArraySize == rhs.ArraySize);
}

inline bool operator!=(const Tex2d_array_dsv& lhs, const Tex2d_array_dsv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex2d_array_rtv {
	Uint _mip_slice{ 0 };
	Uint _first_array_slice{ 0 };
	Uint _array_size{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2d_array_rtv, D3D11_TEX2D_ARRAY_RTV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_array_slice, Uint, FirstArraySlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_array_size, Uint, ArraySize);
};
static_assert(sizeof(Tex2d_array_rtv) == sizeof(D3D11_TEX2D_ARRAY_RTV));

inline bool operator==(const Tex2d_array_rtv& lhs, const Tex2d_array_rtv& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice)
		&& (lhs.FirstArraySlice == rhs.FirstArraySlice)
		&& (lhs.ArraySize == rhs.ArraySize);
}

inline bool operator!=(const Tex2d_array_rtv& lhs, const Tex2d_array_rtv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex2d_array_srv {
	Uint _most_detailed_mip{ 0 };
	Uint _mip_levels{ 0 };
	Uint _first_array_slice{ 0 };
	Uint _array_size{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2d_array_srv, D3D11_TEX2D_ARRAY_SRV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_most_detailed_mip, Uint, MostDetailedMip);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_levels, Uint, MipLevels);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_array_slice, Uint, FirstArraySlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_array_size, Uint, ArraySize);
};
static_assert(sizeof(Tex2d_array_srv) == sizeof(D3D11_TEX2D_ARRAY_SRV));

inline bool operator==(const Tex2d_array_srv& lhs, const Tex2d_array_srv& rhs) noexcept {
	return (lhs.MostDetailedMip == rhs.MostDetailedMip)
		&& (lhs.MipLevels == rhs.MipLevels)
		&& (lhs.FirstArraySlice == rhs.FirstArraySlice)
		&& (lhs.ArraySize == rhs.ArraySize);
}

inline bool operator!=(const Tex2d_array_srv& lhs, const Tex2d_array_srv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex2d_array_uav {
	Uint _mip_slice{ 0 };
	Uint _first_array_slice{ 0 };
	Uint _array_size{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2d_array_uav, D3D11_TEX2D_ARRAY_UAV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_array_slice, Uint, FirstArraySlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_array_size, Uint, ArraySize);
};
static_assert(sizeof(Tex2d_array_uav) == sizeof(D3D11_TEX2D_ARRAY_UAV));

inline bool operator==(const Tex2d_array_uav& lhs, const Tex2d_array_uav& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice)
		&& (lhs.FirstArraySlice == rhs.FirstArraySlice)
		&& (lhs.ArraySize == rhs.ArraySize);
}

inline bool operator!=(const Tex2d_array_uav& lhs, const Tex2d_array_uav& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex2d_array_rtv1 {
	Uint _mip_slice{ 0 };
	Uint _first_array_slice{ 0 };
	Uint _array_size{ 0 };
	Uint _plane_slice{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2d_array_rtv1, D3D11_TEX2D_ARRAY_RTV1)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_array_slice, Uint, FirstArraySlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_array_size, Uint, ArraySize);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_plane_slice, Uint, PlaneSlice);
};
static_assert(sizeof(Tex2d_array_rtv1) == sizeof(D3D11_TEX2D_ARRAY_RTV1));

inline bool operator==(const Tex2d_array_rtv1& lhs, const Tex2d_array_rtv1& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice)
		&& (lhs.FirstArraySlice == rhs.FirstArraySlice)
		&& (lhs.ArraySize == rhs.ArraySize)
		&& (lhs.PlaneSlice == rhs.PlaneSlice);
}

inline bool operator!=(const Tex2d_array_rtv1& lhs, const Tex2d_array_rtv1& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex2d_array_srv1 {
	Uint _most_detailed_mip{ 0 };
	Uint _mip_levels{ 0 };
	Uint _first_array_slice{ 0 };
	Uint _array_size{ 0 };
	Uint _plane_slice{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2d_array_srv1, D3D11_TEX2D_ARRAY_SRV1)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_most_detailed_mip, Uint, MostDetailedMip);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_levels, Uint, MipLevels);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_array_slice, Uint, FirstArraySlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_array_size, Uint, ArraySize);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_plane_slice, Uint, PlaneSlice);
};
static_assert(sizeof(Tex2d_array_srv1) == sizeof(D3D11_TEX2D_ARRAY_SRV1));

inline bool operator==(const Tex2d_array_srv1& lhs, const Tex2d_array_srv1& rhs) noexcept {
	return (lhs.MostDetailedMip == rhs.MostDetailedMip)
		&& (lhs.MipLevels == rhs.MipLevels)
		&& (lhs.FirstArraySlice == rhs.FirstArraySlice)
		&& (lhs.ArraySize == rhs.ArraySize)
		&& (lhs.PlaneSlice == rhs.PlaneSlice);
}

inline bool operator!=(const Tex2d_array_srv1& lhs, const Tex2d_array_srv1& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex2d_array_uav1 {
	Uint _mip_slice{ 0 };
	Uint _first_array_slice{ 0 };
	Uint _array_size{ 0 };
	Uint _plane_slice{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2d_array_uav1, D3D11_TEX2D_ARRAY_UAV1)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_array_slice, Uint, FirstArraySlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_array_size, Uint, ArraySize);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_plane_slice, Uint, PlaneSlice);
};
static_assert(sizeof(Tex2d_array_uav1) == sizeof(D3D11_TEX2D_ARRAY_UAV1));

inline bool operator==(const Tex2d_array_uav1& lhs, const Tex2d_array_uav1& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice)
		&& (lhs.FirstArraySlice == rhs.FirstArraySlice)
		&& (lhs.ArraySize == rhs.ArraySize)
		&& (lhs.PlaneSlice == rhs.PlaneSlice);
}

inline bool operator!=(const Tex2d_array_uav1& lhs, const Tex2d_array_uav1& rhs) noexcept {
	return !operator==(lhs, rhs);
}


//
//
class Tex2d_dsv {
	Uint _mip_slice{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2d_dsv, D3D11_TEX2D_DSV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
};
static_assert(sizeof(Tex2d_dsv) == sizeof(D3D11_TEX2D_DSV));

inline bool operator==(const Tex2d_dsv& lhs, const Tex2d_dsv& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice);
}

inline bool operator!=(const Tex2d_dsv& lhs, const Tex2d_dsv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex2d_rtv {
	Uint _mip_slice{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2d_rtv, D3D11_TEX2D_RTV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
};
static_assert(sizeof(Tex2d_rtv) == sizeof(D3D11_TEX2D_RTV));

inline bool operator==(const Tex2d_rtv& lhs, const Tex2d_rtv& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice);
}

inline bool operator!=(const Tex2d_rtv& lhs, const Tex2d_rtv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex2d_srv {
	Uint _most_detailed_mip{ 0 };
	Uint _mip_levels{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2d_srv, D3D11_TEX2D_SRV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_most_detailed_mip, Uint, MostDetailedMip);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_levels, Uint, MipLevels);
};
static_assert(sizeof(Tex2d_srv) == sizeof(D3D11_TEX2D_SRV));

inline bool operator==(const Tex2d_srv& lhs, const Tex2d_srv& rhs) noexcept {
	return (lhs.MostDetailedMip == rhs.MostDetailedMip)
		&& (lhs.MipLevels == rhs.MipLevels);
}

inline bool operator!=(const Tex2d_srv& lhs, const Tex2d_srv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex2d_uav {
	Uint _mip_slice{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2d_uav, D3D11_TEX2D_UAV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
};
static_assert(sizeof(Tex2d_uav) == sizeof(D3D11_TEX2D_UAV));

inline bool operator==(const Tex2d_uav& lhs, const Tex2d_uav& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice);
}

inline bool operator!=(const Tex2d_uav& lhs, const Tex2d_uav& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex2d_rtv1 {
	Uint _mip_slice{ 0 };
	Uint _plane_slice{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2d_rtv1, D3D11_TEX2D_RTV1)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_plane_slice, Uint, PlaneSlice);
};
static_assert(sizeof(Tex2d_rtv1) == sizeof(D3D11_TEX2D_RTV1));

inline bool operator==(const Tex2d_rtv1& lhs, const Tex2d_rtv1& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice)
		&& (lhs.PlaneSlice == rhs.PlaneSlice);
}

inline bool operator!=(const Tex2d_rtv1& lhs, const Tex2d_rtv1& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex2d_srv1 {
	Uint _most_detailed_mip{ 0 };
	Uint _mip_levels{ 0 };
	Uint _plane_slice{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2d_srv1, D3D11_TEX2D_SRV1)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_most_detailed_mip, Uint, MostDetailedMip);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_levels, Uint, MipLevels);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_plane_slice, Uint, PlaneSlice);
};
static_assert(sizeof(Tex2d_srv1) == sizeof(D3D11_TEX2D_SRV1));

inline bool operator==(const Tex2d_srv1& lhs, const Tex2d_srv1& rhs) noexcept {
	return (lhs.MipLevels == rhs.MipLevels)
		&& (lhs.PlaneSlice == rhs.PlaneSlice)
		&& (lhs.MostDetailedMip == rhs.MostDetailedMip);
}

inline bool operator!=(const Tex2d_srv1& lhs, const Tex2d_srv1& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex2d_uav1 {
	Uint _mip_slice{ 0 };
	Uint _plane_slice{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2d_uav1, D3D11_TEX2D_UAV1)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_plane_slice, Uint, PlaneSlice);
};
static_assert(sizeof(Tex2d_uav1) == sizeof(D3D11_TEX2D_UAV1));

inline bool operator==(const Tex2d_uav1& lhs, const Tex2d_uav1& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice)
		&& (lhs.PlaneSlice == rhs.PlaneSlice);
}

inline bool operator!=(const Tex2d_uav1& lhs, const Tex2d_uav1& rhs) noexcept {
	return !operator==(lhs, rhs);
}


//
//
class Tex2dms_array_dsv {
	Uint _first_array_slice{ 0 };
	Uint _array_size{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2dms_array_dsv, D3D11_TEX2DMS_ARRAY_DSV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_array_slice, Uint, FirstArraySlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_array_size, Uint, ArraySize);
};
static_assert(sizeof(Tex2dms_array_dsv) == sizeof(D3D11_TEX2DMS_ARRAY_DSV));

inline bool operator==(const Tex2dms_array_dsv& lhs, const Tex2dms_array_dsv& rhs) noexcept {
	return (lhs.ArraySize == rhs.ArraySize)
		&& (lhs.FirstArraySlice == rhs.FirstArraySlice);
}

inline bool operator!=(const Tex2dms_array_dsv& lhs, const Tex2dms_array_dsv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex2dms_array_rtv {
	Uint _first_array_slice{ 0 };
	Uint _array_size{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2dms_array_rtv, D3D11_TEX2DMS_ARRAY_RTV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_array_slice, Uint, FirstArraySlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_array_size, Uint, ArraySize);
};
static_assert(sizeof(Tex2dms_array_rtv) == sizeof(D3D11_TEX2DMS_ARRAY_RTV));

inline bool operator==(const Tex2dms_array_rtv& lhs, const Tex2dms_array_rtv& rhs) noexcept {
	return (lhs.ArraySize == rhs.ArraySize)
		&& (lhs.FirstArraySlice == rhs.FirstArraySlice);
}

inline bool operator!=(const Tex2dms_array_rtv& lhs, const Tex2dms_array_rtv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex2dms_array_srv {
	Uint _first_array_slice{ 0 };
	Uint _array_size{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2dms_array_srv, D3D11_TEX2DMS_ARRAY_SRV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_array_slice, Uint, FirstArraySlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_array_size, Uint, ArraySize);
};
static_assert(sizeof(Tex2dms_array_srv) == sizeof(D3D11_TEX2DMS_ARRAY_SRV));

inline bool operator==(const Tex2dms_array_srv& lhs, const Tex2dms_array_srv& rhs) noexcept {
	return (lhs.ArraySize == rhs.ArraySize)
		&& (lhs.FirstArraySlice == rhs.FirstArraySlice);
}

inline bool operator!=(const Tex2dms_array_srv& lhs, const Tex2dms_array_srv& rhs) noexcept {
	return !operator==(lhs, rhs);
}


//
//
class Tex2dms_dsv {
	Uint _unused{ 0 };
public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2dms_dsv, D3D11_TEX2DMS_DSV)
public:
};
static_assert(sizeof(Tex2dms_dsv) == sizeof(D3D11_TEX2DMS_DSV));

inline bool operator==(const Tex2dms_dsv& lhs, const Tex2dms_dsv& rhs) noexcept {
	return true;
}

inline bool operator!=(const Tex2dms_dsv& lhs, const Tex2dms_dsv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex2dms_rtv {
	Uint _unused{ 0 };
public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2dms_rtv, D3D11_TEX2DMS_RTV)
public:
};
static_assert(sizeof(Tex2dms_rtv) == sizeof(D3D11_TEX2DMS_RTV));

inline bool operator==(const Tex2dms_rtv& lhs, const Tex2dms_rtv& rhs) noexcept {
	return true;
}

inline bool operator!=(const Tex2dms_rtv& lhs, const Tex2dms_rtv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex2dms_srv {
	Uint _unused{ 0 };
public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex2dms_srv, D3D11_TEX2DMS_SRV)
public:

};
static_assert(sizeof(Tex2dms_srv) == sizeof(D3D11_TEX2DMS_SRV));

inline bool operator==(const Tex2dms_srv& lhs, const Tex2dms_srv& rhs) noexcept {
	return true;
}

inline bool operator!=(const Tex2dms_srv& lhs, const Tex2dms_srv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex3d_rtv {
	Uint _mip_slice{ 0 };
	Uint _first_wslice{ 0 };
	Uint _wsize{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex3d_rtv, D3D11_TEX3D_RTV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_wslice, Uint, FirstWSlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_wsize, Uint, WSize);
};
static_assert(sizeof(Tex3d_rtv) == sizeof(D3D11_TEX3D_RTV));

inline bool operator==(const Tex3d_rtv& lhs, const Tex3d_rtv& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice)
		&& (lhs.FirstWSlice == rhs.FirstWSlice)
		&& (lhs.WSize == rhs.WSize);
}

inline bool operator!=(const Tex3d_rtv& lhs, const Tex3d_rtv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex3d_srv {
	Uint _most_detailed_mip{ 0 };
	Uint _mip_levels{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex3d_srv, D3D11_TEX3D_SRV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_most_detailed_mip, Uint, MostDetailedMip);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_levels, Uint, MipLevels);
};
static_assert(sizeof(Tex3d_srv) == sizeof(D3D11_TEX3D_SRV));

inline bool operator==(const Tex3d_srv& lhs, const Tex3d_srv& rhs) noexcept {
	return (lhs.MipLevels == rhs.MipLevels)
		&& (lhs.MostDetailedMip == rhs.MostDetailedMip);
}

inline bool operator!=(const Tex3d_srv& lhs, const Tex3d_srv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tex3d_uav {
	Uint _mip_slice{ 0 };
	Uint _first_wslice{ 0 };
	Uint _wsize{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tex3d_uav, D3D11_TEX3D_UAV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_slice, Uint, MipSlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_wslice, Uint, FirstWSlice);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_wsize, Uint, WSize);
};
static_assert(sizeof(Tex3d_uav) == sizeof(D3D11_TEX3D_UAV));

inline bool operator==(const Tex3d_uav& lhs, const Tex3d_uav& rhs) noexcept {
	return (lhs.MipSlice == rhs.MipSlice)
		&& (lhs.FirstWSlice == rhs.FirstWSlice)
		&& (lhs.WSize == rhs.WSize);
}

inline bool operator!=(const Tex3d_uav& lhs, const Tex3d_uav& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Texcube_array_srv {
	Uint _most_detailed_mip{ 0 };
	Uint _mip_levels{ 0 };
	Uint _first_2d_array_face{ 0 };
	Uint _num_cubes{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Texcube_array_srv, D3D11_TEXCUBE_ARRAY_SRV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_most_detailed_mip, Uint, MostDetailedMip);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_levels, Uint, MipLevels);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_first_2d_array_face, Uint, First2DArrayFace);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_num_cubes, Uint, NumCubes);
};
static_assert(sizeof(Texcube_array_srv) == sizeof(D3D11_TEXCUBE_ARRAY_SRV));

inline bool operator==(const Texcube_array_srv& lhs, const Texcube_array_srv& rhs) noexcept {
	return (lhs.MipLevels == rhs.MipLevels)
		&& (lhs.MostDetailedMip == rhs.MostDetailedMip)
		&& (lhs.First2DArrayFace == rhs.First2DArrayFace)
		&& (lhs.NumCubes == rhs.NumCubes);
}

inline bool operator!=(const Texcube_array_srv& lhs, const Texcube_array_srv& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Texcube_srv {
	Uint _most_detailed_mip{ 0 };
	Uint _mip_levels{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Texcube_srv, D3D11_TEXCUBE_SRV)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_most_detailed_mip, Uint, MostDetailedMip);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_levels, Uint, MipLevels);
};
static_assert(sizeof(Texcube_srv) == sizeof(D3D11_TEXCUBE_SRV));

inline bool operator==(const Texcube_srv& lhs, const Texcube_srv& rhs) noexcept {
	return (lhs.MipLevels == rhs.MipLevels)
		&& (lhs.MostDetailedMip == rhs.MostDetailedMip);
}

inline bool operator!=(const Texcube_srv& lhs, const Texcube_srv& rhs) noexcept {
	return !operator==(lhs, rhs);
}


//
//
class Tile_region_size {
	Uint _num_tiles{ 0 };
	Bool _use_box{ False };
	Uint _width{ 0 };
	Uint16 _height{ 0 };
	Uint16 _depth{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tile_region_size, D3D11_TILE_REGION_SIZE)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_num_tiles, Uint, NumTiles);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_use_box, Bool, bUseBox);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_width, Uint, Width);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_height, Uint16, Height);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_depth, Uint16, Depth);
};
static_assert(sizeof(Tile_region_size) == sizeof(D3D11_TILE_REGION_SIZE));

inline bool operator==(const Tile_region_size& lhs, const Tile_region_size& rhs) noexcept {
	return (lhs.NumTiles == rhs.NumTiles)
		&& (lhs.bUseBox == rhs.bUseBox)
		&& (lhs.Width == rhs.Width)
		&& (lhs.Height == rhs.Height)
		&& (lhs.Depth == rhs.Depth);
}

inline bool operator!=(const Tile_region_size& lhs, const Tile_region_size& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tiled_resource_coordinate {
	Uint _x{ 0 };
	Uint _y{ 0 };
	Uint _z{ 0 };
	Uint _subresource{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tiled_resource_coordinate, D3D11_TILED_RESOURCE_COORDINATE)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_x, Uint, X);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_y, Uint, Y);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_z, Uint, Z);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_subresource, Uint, Subresource);
};
static_assert(sizeof(Tiled_resource_coordinate) == sizeof(D3D11_TILED_RESOURCE_COORDINATE));

inline bool operator==(const Tiled_resource_coordinate& lhs, const Tiled_resource_coordinate& rhs) noexcept {
	return (lhs.X == rhs.X)
		&& (lhs.Y == rhs.Y)
		&& (lhs.Z == rhs.Z)
		&& (lhs.Subresource == rhs.Subresource);
}

inline bool operator!=(const Tiled_resource_coordinate& lhs, const Tiled_resource_coordinate& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Tile_shape {
	Uint _width_in_texels{ 0 };
	Uint _height_in_texels{ 0 };
	Uint _depth_in_texels{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Tile_shape, D3D11_TILE_SHAPE)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_width_in_texels, Uint, WidthInTexels);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_height_in_texels, Uint, HeightInTexels);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_depth_in_texels, Uint, DepthInTexels);
};
static_assert(sizeof(Tile_shape) == sizeof(D3D11_TILE_SHAPE));

inline bool operator==(const Tile_shape& lhs, const Tile_shape& rhs) noexcept {
	return (lhs.WidthInTexels == rhs.WidthInTexels)
		&& (lhs.HeightInTexels == rhs.HeightInTexels)
		&& (lhs.DepthInTexels == rhs.DepthInTexels);
}

inline bool operator!=(const Tile_shape& lhs, const Tile_shape& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Shader_macro {
	Pcstr _name{ nullptr };
	Pcstr _definition{ nullptr };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Shader_macro, D3D_SHADER_MACRO)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_name, Pcstr, Name);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_definition, Pcstr, Definition);
};
static_assert(sizeof(Shader_macro) == sizeof(D3D_SHADER_MACRO));

inline bool operator==(const Shader_macro& lhs, const Shader_macro& rhs) noexcept {
	return (strcmp(lhs.Name, rhs.Name) == 0)
		&& (strcmp(lhs.Definition, rhs.Definition) == 0);
}

inline bool operator!=(const Shader_macro& lhs, const Shader_macro& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Render_target_blend_desc {
	Bool		_blend_enabled{ False };
	Blend		_src_blend_rgb{ Blend::one };
	Blend		_dst_blend_rgb{ Blend::zero };
	Blend_op		_blend_op_rgb{ Blend_op::add };
	Blend		_src_blend_alpha{ Blend::one };
	Blend		_dst_blend_alpha{ Blend::zero };
	Blend_op		_blend_op_alpha{ Blend_op::add };
	Uint8     _write_mask{ 0xff };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Render_target_blend_desc, D3D11_RENDER_TARGET_BLEND_DESC)
public:
	Render_target_blend_desc & set_write_mask(Color_write_mask mask) {
		_write_mask = decltype(mask)::mask_type(mask);
		return (*this);
	}

	Color_write_mask get_write_mask() const noexcept {
		return Color_write_mask_bit(_write_mask);
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_blend_enabled, Bool, BlendEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_src_blend_rgb, Blend, SrcBlend);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_dst_blend_rgb, Blend, DestBlend);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_blend_op_rgb, _HW_3D_D3D_ Blend_op, BlendOp);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_src_blend_alpha, Blend, SrcBlendAlpha);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_dst_blend_alpha, Blend, DestBlendAlpha);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_blend_op_alpha, _HW_3D_D3D_ Blend_op, BlendOpAlpha);
	__declspec(property(get = get_write_mask, put = set_write_mask)) Color_write_mask RenderTargetWriteMask;
};
static_assert(sizeof(Render_target_blend_desc) == sizeof(D3D11_RENDER_TARGET_BLEND_DESC));

inline bool operator==(const Render_target_blend_desc& lhs, const Render_target_blend_desc& rhs) noexcept {
	return (lhs.BlendEnable == rhs.BlendEnable)
		&& (lhs.SrcBlend == rhs.SrcBlend)
		&& (lhs.DestBlend == rhs.DestBlend)
		&& (lhs.BlendOp == rhs.BlendOp)
		&& (lhs.SrcBlendAlpha == rhs.SrcBlendAlpha)
		&& (lhs.DestBlendAlpha == rhs.DestBlendAlpha)
		&& (lhs.BlendOpAlpha == rhs.BlendOpAlpha)
		&& (lhs.RenderTargetWriteMask == rhs.RenderTargetWriteMask);
}

inline bool operator!=(const Render_target_blend_desc& lhs, const Render_target_blend_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}


//
//
class Render_target_blend_desc1 {
	Bool		_blend_enabled{ False };
	Bool        _logic_op_enable{ False };
	Blend		_src_blend_rgb{ Blend::one };
	Blend		_dst_blend_rgb{ Blend::zero };
	Blend_op		_blend_op_rgb{ Blend_op::add };
	Blend		_src_blend_alpha{ Blend::one };
	Blend		_dst_blend_alpha{ Blend::zero };
	Blend_op		_blend_op_alpha{ Blend_op::add };
	Logic_op     _logic_op{ Logic_op::noop };
	Uint8    _write_mask{ 0xff };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Render_target_blend_desc1, D3D11_RENDER_TARGET_BLEND_DESC1)
public:
	Render_target_blend_desc1 & set_write_mask(Color_write_mask mask) {
		_write_mask = decltype(mask)::mask_type(mask);
		return (*this);
	}

	Color_write_mask get_write_mask() const noexcept {
		return Color_write_mask_bit(_write_mask);
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_blend_enabled, Bool, BlendEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_logic_op_enable, Bool, LogicOpEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_src_blend_rgb, Blend, SrcBlend);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_dst_blend_rgb, Blend, DestBlend);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_blend_op_rgb, _HW_3D_D3D_ Blend_op, BlendOp);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_src_blend_alpha, Blend, SrcBlendAlpha);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_dst_blend_alpha, Blend, DestBlendAlpha);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_blend_op_alpha, _HW_3D_D3D_ Blend_op, BlendOpAlpha);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_logic_op, _HW_3D_D3D_ Logic_op, LogicOp);
	__declspec(property(get = get_write_mask, put = set_write_mask)) Color_write_mask RenderTargetWriteMask;
};
static_assert(sizeof(Render_target_blend_desc1) == sizeof(D3D11_RENDER_TARGET_BLEND_DESC1));

inline bool operator==(const Render_target_blend_desc1& lhs, const Render_target_blend_desc1& rhs) noexcept {
	return (lhs.BlendEnable == rhs.BlendEnable)
		&& (lhs.LogicOpEnable == rhs.LogicOpEnable)
		&& (lhs.SrcBlend == rhs.SrcBlend)
		&& (lhs.DestBlend == rhs.DestBlend)
		&& (lhs.BlendOp == rhs.BlendOp)
		&& (lhs.SrcBlendAlpha == rhs.SrcBlendAlpha)
		&& (lhs.DestBlendAlpha == rhs.DestBlendAlpha)
		&& (lhs.BlendOpAlpha == rhs.BlendOpAlpha)
		&& (lhs.LogicOp == rhs.LogicOp)
		&& (lhs.RenderTargetWriteMask == rhs.RenderTargetWriteMask);
}

inline bool operator!=(const Render_target_blend_desc1& lhs, const Render_target_blend_desc1& rhs) noexcept {
	return !operator==(lhs, rhs);
}


//
//
class Blend_desc {
	Bool _alpha_to_coverage_enable{ False };
	Bool _independent_blend_enable{ False };
	_HW_3D_STD_ array<Render_target_blend_desc, 8> _render_targets;

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Blend_desc, D3D11_BLEND_DESC)
public:
	const _HW_3D_STD_ array<Render_target_blend_desc, 8>& get_render_targets() const noexcept {
		return _render_targets;
	}

	Blend_desc& set_render_target(const Render_target_blend_desc& render_target_, _HW_3D_STD_ size_t index) {
		assert(index < _render_targets.size());
		_render_targets[index] = render_target_;
		return (*this);
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_alpha_to_coverage_enable, Bool, AlphaToCoverageEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_independent_blend_enable, Bool, IndependentBlendEnable);
	__declspec(property(get = get_render_targets)) const _HW_3D_STD_ array<Render_target_blend_desc, 8>& RenderTarget;
};
static_assert(sizeof(Blend_desc) == sizeof(D3D11_BLEND_DESC));

inline bool operator==(const Blend_desc& lhs, const Blend_desc& rhs) noexcept {
	return (lhs.AlphaToCoverageEnable == rhs.AlphaToCoverageEnable)
		&& (lhs.IndependentBlendEnable == rhs.IndependentBlendEnable)
		&& (lhs.RenderTarget == rhs.RenderTarget);
}

inline bool operator!=(const Blend_desc& lhs, const Blend_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Blend_desc1 {
	Bool _alpha_to_coverage_enable{ False };
	Bool _independent_blend_enable{ False };
	_HW_3D_STD_ array<Render_target_blend_desc1, 8> _render_targets;

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Blend_desc1, D3D11_BLEND_DESC1)
public:
	const _HW_3D_STD_ array<Render_target_blend_desc1, 8>& get_render_targets() const noexcept {
		return _render_targets;
	}

	Blend_desc1& set_render_target(const Render_target_blend_desc1& render_target_, _HW_3D_STD_ size_t index) {
		assert(index < _render_targets.size());
		_render_targets[index] = render_target_;
		return (*this);
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_alpha_to_coverage_enable, Bool, AlphaToCoverageEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_independent_blend_enable, Bool, IndependentBlendEnable);
	__declspec(property(get = get_render_targets)) const _HW_3D_STD_ array<Render_target_blend_desc1, 8>& RenderTarget;
};
static_assert(sizeof(Blend_desc1) == sizeof(D3D11_BLEND_DESC1));

inline bool operator==(const Blend_desc1& lhs, const Blend_desc1& rhs) noexcept {
	return (lhs.AlphaToCoverageEnable == rhs.AlphaToCoverageEnable)
		&& (lhs.IndependentBlendEnable == rhs.IndependentBlendEnable)
		&& (lhs.RenderTarget == rhs.RenderTarget);
}

inline bool operator!=(const Blend_desc1& lhs, const Blend_desc1& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Counter_desc {
	Counter _counter{};
	Uint _misc_flags{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Counter_desc, D3D11_COUNTER_DESC)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_counter, _HW_3D_D3D_ Counter, Counter);
};
static_assert(sizeof(Counter_desc) == sizeof(D3D11_COUNTER_DESC));

inline bool operator==(const Counter_desc& lhs, const Counter_desc& rhs) noexcept {
	return (lhs.Counter == rhs.Counter);
}

inline bool operator!=(const Counter_desc& lhs, const Counter_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Depth_stencil_op_desc {
	Stencil_op _stencil_fail_op{ Stencil_op::keep };
	Stencil_op _stencil_depth_fail_op{ Stencil_op::keep };
	Stencil_op _stencil_pass_op{ Stencil_op::keep };
	Comparison_func _stencil_func{ Comparison_func::always };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Depth_stencil_op_desc, D3D11_DEPTH_STENCILOP_DESC)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_stencil_fail_op, Stencil_op, StencilFailOp);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_stencil_depth_fail_op, Stencil_op, StencilDepthFailOp);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_stencil_pass_op, Stencil_op, StencilPassOp);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_stencil_func, Comparison_func, StencilFunc);
};
static_assert(sizeof(Depth_stencil_op_desc) == sizeof(D3D11_DEPTH_STENCILOP_DESC));

inline bool operator==(const Depth_stencil_op_desc& lhs, const Depth_stencil_op_desc& rhs) noexcept {
	return (lhs.StencilDepthFailOp == rhs.StencilDepthFailOp)
		&& (lhs.StencilFailOp == rhs.StencilFailOp)
		&& (lhs.StencilPassOp == rhs.StencilPassOp)
		&& (lhs.StencilFunc == rhs.StencilFunc);
}

inline bool operator!=(const Depth_stencil_op_desc& lhs, const Depth_stencil_op_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Depth_stencil_desc {
	Bool _depth_enable{ True };
	Depth_write_mask _depth_write_mask{ Depth_write_mask::all };
	Comparison_func _depth_func{ Comparison_func::less };
	Bool _stencil_enable{ False };
	Uint8 _stencil_read_mask{ D3D11_DEFAULT_STENCIL_READ_MASK };
	Uint8 _stencil_write_mask{ D3D11_DEFAULT_STENCIL_WRITE_MASK };
	Depth_stencil_op_desc _front_face{};
	Depth_stencil_op_desc _back_face{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Depth_stencil_desc, D3D11_DEPTH_STENCIL_DESC)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_depth_enable, Bool, DepthEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_depth_write_mask, _HW_3D_D3D_ Depth_write_mask, DepthWriteMask);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_depth_func, Comparison_func, DepthFunc);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_stencil_enable, Bool, StencilEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_stencil_read_mask, Uint8, StencilReadMask);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_stencil_write_mask, Uint8, StencilWriteMask);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_front_face, Depth_stencil_op_desc, FrontFace);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_back_face, Depth_stencil_op_desc, BackFace);
};
static_assert(sizeof(Depth_stencil_desc) == sizeof(D3D11_DEPTH_STENCIL_DESC));

inline bool operator==(const Depth_stencil_desc& lhs, const Depth_stencil_desc& rhs) noexcept {
	return (lhs.BackFace == rhs.BackFace)
		&& (lhs.DepthEnable == rhs.DepthEnable)
		&& (lhs.DepthFunc == rhs.DepthFunc)
		&& (lhs.DepthWriteMask == rhs.DepthWriteMask)
		&& (lhs.FrontFace == rhs.FrontFace)
		&& (lhs.StencilEnable == rhs.StencilEnable)
		&& (lhs.StencilReadMask == rhs.StencilReadMask)
		&& (lhs.StencilWriteMask == rhs.StencilWriteMask);
}

inline bool operator!=(const Depth_stencil_desc& lhs, const Depth_stencil_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Input_element_desc {
	Pcstr _semantic_name{ nullptr };
	Uint _semantic_index{ 0 };
	_HW_3D_DXGI_ Format _format{};
	Uint _input_slot{ 0 };
	Uint _aligned_byte_offset{ 0 };
	Input_classification _input_slot_class{};
	Uint _instance_data_step_rate{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Input_element_desc, D3D11_INPUT_ELEMENT_DESC)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_semantic_name, Pcstr, SemanticName);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_semantic_index, Uint, SemanticIndex);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_format, _HW_3D_DXGI_ Format, Format);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_input_slot, Uint, InputSlot);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_aligned_byte_offset, Uint, AlignedByteOffset);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_input_slot_class, Input_classification, InputSlotClass);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_instance_data_step_rate, Uint, InstanceDataStepRate);
};
static_assert(sizeof(Input_element_desc) == sizeof(D3D11_INPUT_ELEMENT_DESC));

inline bool operator==(const Input_element_desc& lhs, const Input_element_desc& rhs) noexcept {
	return (lhs.AlignedByteOffset == rhs.AlignedByteOffset)
		&& (lhs.Format == rhs.Format)
		&& (lhs.SemanticIndex == rhs.SemanticIndex)
		&& (strcmp(lhs.SemanticName, rhs.SemanticName) == 0)
		&& (lhs.InputSlot == rhs.InputSlot)
		&& (lhs.InputSlotClass == rhs.InputSlotClass)
		&& (lhs.InstanceDataStepRate == rhs.InstanceDataStepRate);
}

inline bool operator!=(const Input_element_desc& lhs, const Input_element_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Query_desc {
	Query _query{};
	Uint _misc_flags{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Query_desc, D3D11_QUERY_DESC)
public:
	Query_desc & set_misc_flags(Query_misc_flag flags) {
		_misc_flags = decltype(flags)::mask_type(flags);
		return *(this);
	}

	Query_misc_flag get_misc_flags() const noexcept {
		return Query_misc_flag_bit(_misc_flags);
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_query, _HW_3D_D3D_ Query, Query);
	__declspec(property(get = get_misc_flags, put = set_misc_falgs)) Query_misc_flag MiscFlags;
};
static_assert(sizeof(Query_desc) == sizeof(D3D11_QUERY_DESC));

inline bool operator==(const Query_desc& lhs, const Query_desc& rhs) noexcept {
	return (lhs.Query == rhs.Query)
		&& (lhs.MiscFlags == rhs.MiscFlags);
}

inline bool operator!=(const Query_desc& lhs, const Query_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Query_desc1 {
	Query _query{};
	Uint _misc_flags{ 0 };
	Context_type _context_type{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Query_desc1, D3D11_QUERY_DESC1)
public:
	Query_desc1 & set_misc_flags(Query_misc_flag flags) {
		_misc_flags = decltype(flags)::mask_type(flags);
		return (*this);
	}

	Query_misc_flag get_misc_flags() const noexcept {
		return Query_misc_flag_bit(_misc_flags);
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_query, _HW_3D_D3D_ Query, Query);
	__declspec(property(get = get_misc_flags, put = set_misc_flags)) Query_misc_flag MiscFlags;
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_context_type, _HW_3D_D3D_ Context_type, ContextType);
};
static_assert(sizeof(Query_desc1) == sizeof(D3D11_QUERY_DESC1));

inline bool operator==(const Query_desc1& lhs, const Query_desc1& rhs) noexcept {
	return (lhs.ContextType == rhs.ContextType)
		&& (lhs.MiscFlags == rhs.MiscFlags)
		&& (lhs.Query == rhs.Query);
}

inline bool operator!=(const Query_desc1& lhs, const Query_desc1& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Rasterizer_desc {
	Fill_mode _fill_mode{ Fill_mode::solid };
	Cull_mode _cull_mode{ Cull_mode::back };
	Bool _front_counter_clockwise{ False };
	Int _depth_bias{ 0 };
	Float _depth_bias_clamp{ 0.0f };
	Float _slope_scale_depth_bias{ 0.0f };
	Bool _depth_clip_enable{ True };
	Bool _scissor_enable{ False };
	Bool _multisample_enable{ False };
	Bool _antialiased_line_enable{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Rasterizer_desc, D3D11_RASTERIZER_DESC)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_fill_mode, _HW_3D_D3D_ Fill_mode, FillMode);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_cull_mode, _HW_3D_D3D_ Cull_mode, CullMode);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_front_counter_clockwise, Bool, FrontCounterClockwise);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_depth_bias, Int, DepthBias);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_depth_bias_clamp, Float, DepthBiasClamp);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_slope_scale_depth_bias, Float, SlopeScaledDepthBias);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_depth_clip_enable, Bool, DepthClipEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_scissor_enable, Bool, ScissorEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_multisample_enable, Bool, MultisampleEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_antialiased_line_enable, Bool, AntialiasedLineEnable);
};
static_assert(sizeof(Rasterizer_desc) == sizeof(D3D11_RASTERIZER_DESC));

inline bool operator==(const Rasterizer_desc& lhs, const Rasterizer_desc& rhs) noexcept {
	return (lhs.FillMode == rhs.FillMode)
		&& (lhs.CullMode == rhs.CullMode)
		&& (lhs.FrontCounterClockwise == rhs.FrontCounterClockwise)
		&& (lhs.DepthBias == rhs.DepthBias)
		&& (lhs.DepthBiasClamp == rhs.DepthBiasClamp)
		&& (lhs.DepthClipEnable == rhs.DepthClipEnable)
		&& (lhs.SlopeScaledDepthBias == rhs.SlopeScaledDepthBias)
		&& (lhs.ScissorEnable == rhs.ScissorEnable)
		&& (lhs.MultisampleEnable == rhs.MultisampleEnable)
		&& (lhs.AntialiasedLineEnable == rhs.AntialiasedLineEnable);
}

inline bool operator!=(const Rasterizer_desc& lhs, const Rasterizer_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Rasterizer_desc1 {
	Fill_mode _fill_mode{ Fill_mode::solid };
	Cull_mode _cull_mode{ Cull_mode::back };
	Bool _front_counter_clockwise{ False };
	Int _depth_bias{ 0 };
	Float _depth_bias_clamp{ 0.0f };
	Float _slope_scale_depth_bias{ 0.0f };
	Bool _depth_clip_enable{ True };
	Bool _scissor_enable{ False };
	Bool _multisample_enable{ False };
	Bool _antialiased_line_enable{ False };
	Uint _forced_sample_count{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Rasterizer_desc1, D3D11_RASTERIZER_DESC1)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_fill_mode, _HW_3D_D3D_ Fill_mode, FillMode);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_cull_mode, _HW_3D_D3D_ Cull_mode, CullMode);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_front_counter_clockwise, Bool, FrontCounterClockwise);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_depth_bias, Int, DepthBias);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_depth_bias_clamp, Float, DepthBiasClamp);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_slope_scale_depth_bias, Float, SlopeScaledDepthBias);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_depth_clip_enable, Bool, DepthClipEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_scissor_enable, Bool, ScissorEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_multisample_enable, Bool, MultisampleEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_antialiased_line_enable, Bool, AntialiasedLineEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_forced_sample_count, Uint, ForcedSampleCount);
};
static_assert(sizeof(Rasterizer_desc1) == sizeof(D3D11_RASTERIZER_DESC1));

inline bool operator==(const Rasterizer_desc1& lhs, const Rasterizer_desc1& rhs) noexcept {
	return (lhs.FillMode == rhs.FillMode)
		&& (lhs.CullMode == rhs.CullMode)
		&& (lhs.FrontCounterClockwise == rhs.FrontCounterClockwise)
		&& (lhs.DepthBias == rhs.DepthBias)
		&& (lhs.DepthBiasClamp == rhs.DepthBiasClamp)
		&& (lhs.DepthClipEnable == rhs.DepthClipEnable)
		&& (lhs.SlopeScaledDepthBias == rhs.SlopeScaledDepthBias)
		&& (lhs.ScissorEnable == rhs.ScissorEnable)
		&& (lhs.MultisampleEnable == rhs.MultisampleEnable)
		&& (lhs.AntialiasedLineEnable == rhs.AntialiasedLineEnable)
		&& (lhs.ForcedSampleCount == rhs.ForcedSampleCount);
}

inline bool operator!=(const Rasterizer_desc1& lhs, const Rasterizer_desc1& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Rasterizer_desc2 {
	Fill_mode _fill_mode{ Fill_mode::solid };
	Cull_mode _cull_mode{ Cull_mode::back };
	Bool _front_counter_clockwise{ False };
	Int _depth_bias{ 0 };
	Float _depth_bias_clamp{ 0.0f };
	Float _slope_scale_depth_bias{ 0.0f };
	Bool _depth_clip_enable{ True };
	Bool _scissor_enable{ False };
	Bool _multisample_enable{ False };
	Bool _antialiased_line_enable{ False };
	Uint _forced_sample_count{ 0 };
	Conservative_rasterization_mode _conservative_raster{ Conservative_rasterization_mode::off };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Rasterizer_desc2, D3D11_RASTERIZER_DESC2)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_fill_mode, _HW_3D_D3D_ Fill_mode, FillMode);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_cull_mode, _HW_3D_D3D_ Cull_mode, CullMode);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_front_counter_clockwise, Bool, FrontCounterClockwise);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_depth_bias, Int, DepthBias);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_depth_bias_clamp, Float, DepthBiasClamp);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_slope_scale_depth_bias, Float, SlopeScaledDepthBias);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_depth_clip_enable, Bool, DepthClipEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_scissor_enable, Bool, ScissorEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_multisample_enable, Bool, MultisampleEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_antialiased_line_enable, Bool, AntialiasedLineEnable);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_forced_sample_count, Uint, ForcedSampleCount);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_conservative_raster, Conservative_rasterization_mode, ConservativeRaster);
};
static_assert(sizeof(Rasterizer_desc2) == sizeof(D3D11_RASTERIZER_DESC2));

inline bool operator==(const Rasterizer_desc2& lhs, const Rasterizer_desc2& rhs) noexcept {
	return (lhs.FillMode == rhs.FillMode)
		&& (lhs.CullMode == rhs.CullMode)
		&& (lhs.FrontCounterClockwise == rhs.FrontCounterClockwise)
		&& (lhs.DepthBias == rhs.DepthBias)
		&& (lhs.DepthBiasClamp == rhs.DepthBiasClamp)
		&& (lhs.DepthClipEnable == rhs.DepthClipEnable)
		&& (lhs.SlopeScaledDepthBias == rhs.SlopeScaledDepthBias)
		&& (lhs.ScissorEnable == rhs.ScissorEnable)
		&& (lhs.MultisampleEnable == rhs.MultisampleEnable)
		&& (lhs.AntialiasedLineEnable == rhs.AntialiasedLineEnable)
		&& (lhs.ForcedSampleCount == rhs.ForcedSampleCount)
		&& (lhs.ConservativeRaster == rhs.ConservativeRaster);
}

inline bool operator!=(const Rasterizer_desc2& lhs, const Rasterizer_desc2& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Sampler_desc {
	Filter _filter{ Filter::std_linear_linear_linear };
	Texture_address_mode _address_u{ Texture_address_mode::clamp };
	Texture_address_mode _address_v{ Texture_address_mode::clamp };
	Texture_address_mode _address_w{ Texture_address_mode::clamp };
	Float _mip_lod_bias{ 0.0f };
	Uint _max_anisotropy{ 1 };
	Comparison_func _comparison_func{ Comparison_func::never };
	_HW_3D_STD_ array<Float, 4> _border_color{ 1.0f, 1.0f, 1.0f, 1.0f };
	Float _min_lod{ -FLT_MAX };
	Float _max_lod{ FLT_MAX };
public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Sampler_desc, D3D11_SAMPLER_DESC)
public:
	Sampler_desc & set_border_color(Float r, Float g, Float b, Float a) {
		_border_color[0] = r;
		_border_color[1] = g;
		_border_color[2] = b;
		_border_color[3] = a;
		return (*this);
	}

	const _HW_3D_STD_ array<Float, 4>& get_border_color() const noexcept {
		return _border_color;
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_filter, _HW_3D_D3D_ Filter, Filter);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_address_u, Texture_address_mode, AddressU);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_address_v, Texture_address_mode, AddressV);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_address_w, Texture_address_mode, AddressW);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_lod_bias, Float, MipLODBias);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_max_anisotropy, Uint, MaxAnisotropy);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_comparison_func, _HW_3D_D3D_ Comparison_func, ComparisonFunc);
	__declspec(property(get = get_border_color)) const _HW_3D_STD_ array<Float, 4>& BorderColor;
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_min_lod, Float, MinLOD);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_max_lod, Float, MaxLOD);
};
static_assert(sizeof(Sampler_desc) == sizeof(D3D11_SAMPLER_DESC));

inline bool operator==(const Sampler_desc& lhs, const Sampler_desc& rhs) noexcept {
	return (lhs.Filter == rhs.Filter)
		&& (lhs.AddressU == rhs.AddressU)
		&& (lhs.AddressV == rhs.AddressV)
		&& (lhs.AddressW == rhs.AddressW)
		&& (lhs.MipLODBias == rhs.MipLODBias)
		&& (lhs.MaxAnisotropy == rhs.MaxAnisotropy)
		&& (lhs.ComparisonFunc == rhs.ComparisonFunc)
		&& (lhs.BorderColor == rhs.BorderColor)
		&& (lhs.MinLOD == rhs.MinLOD)
		&& (lhs.MaxLOD == rhs.MaxLOD);
}

inline bool operator!=(const Sampler_desc& lhs, const Sampler_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Info_queue_filter_desc {
	Uint _num_categories{ 0 };
	Message_category* _p_category_list{ nullptr };
	Uint _num_severities{ 0 };
	Message_severity* _p_severity_list{ nullptr };
	Uint _num_ids{ 0 };
	Message_id* _p_id_list{ nullptr };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Info_queue_filter_desc, D3D11_INFO_QUEUE_FILTER_DESC)
public:
	Info_queue_filter_desc & set_categories(Message_category* lst, Uint num) {
		_p_category_list = lst;
		_num_categories = num;
		return (*this);
	}

	Info_queue_filter_desc& set_severities(Message_severity* lst, Uint num) {
		_p_severity_list = lst;
		_num_severities = num;
		return (*this);
	}

	Info_queue_filter_desc& set_ids(Message_id* lst, Uint num) {
		_p_id_list = lst;
		_num_ids = num;
		return (*this);
	}

	Uint get_num_categories() const noexcept {
		return _num_categories;
	}

	const Message_category*  get_p_category_list() const noexcept {
		return _p_category_list;
	}

	Uint get_num_severities() const noexcept {
		return _num_severities;
	}

	const Message_severity* get_p_severity_list() const noexcept {
		return _p_severity_list;
	}

	Uint get_num_ids() const noexcept {
		return _num_ids;
	}

	const Message_id* get_p_id_list() const noexcept {
		return _p_id_list;
	}

	__declspec(property(get = get_num_categories)) Uint NumCategories;
	__declspec(property(get = get_p_category_list)) const Message_category* pCategoryList;
	__declspec(property(get = get_num_severities)) Uint NumSeverities;
	__declspec(property(get = get_p_severity_list)) const Message_severity* pSeverityList;
	__declspec(property(get = get_num_ids)) Uint NumIDs;
	__declspec(property(get = get_p_id_list)) const Message_id* pIDList;

};
static_assert(sizeof(Info_queue_filter_desc) == sizeof(D3D11_INFO_QUEUE_FILTER_DESC));

inline bool operator==(const Info_queue_filter_desc& lhs, const Info_queue_filter_desc& rhs) noexcept {
	return (lhs.NumCategories == rhs.NumCategories)
		&& (lhs.NumIDs == rhs.NumIDs)
		&& (lhs.NumSeverities == rhs.NumSeverities)
		&& (memcmp(lhs.pCategoryList, rhs.pCategoryList, sizeof(Message_category) * lhs.NumCategories) == 0)
		&& (memcmp(lhs.pIDList, rhs.pIDList, sizeof(Message_id) * lhs.NumIDs) == 0)
		&& (memcmp(lhs.pSeverityList, rhs.pSeverityList, sizeof(Message_severity) * lhs.NumSeverities) == 0);
}

inline bool operator!=(const Info_queue_filter_desc& lhs, const Info_queue_filter_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Buffer_desc {
	Uint _byte_width{ 0 };
	Usage _usage{};
	Uint _bind_flags{ 0 };
	Uint _cpu_access_flags{ 0 };
	Uint _misc_flags{ 0 };
	Uint _structure_byte_stride{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Buffer_desc, D3D11_BUFFER_DESC)
public:
	Buffer_desc & set_bind_flags(Bind_flag flags) {
		_bind_flags = decltype(flags)::mask_type(flags);
		return (*this);
	}

	Bind_flag get_bind_flags() const noexcept {
		return Bind_flag_bit(_bind_flags);
	}

	Buffer_desc& set_cpu_access_flags(Cpu_access_flag flags) {
		_cpu_access_flags = decltype(flags)::mask_type(flags);
		return (*this);
	}

	Cpu_access_flag get_cpu_access_flags() const noexcept {
		return Cpu_access_flag_bit(_cpu_access_flags);
	}

	Buffer_desc& set_misc_flags(Resource_misc_flag flags) {
		_misc_flags = decltype(flags)::mask_type(flags);
		return (*this);
	}

	Resource_misc_flag get_misc_flags() const noexcept {
		return Resource_misc_flag_bit(_misc_flags);
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_byte_width, Uint, ByteWidth);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_usage, _HW_3D_D3D_ Usage, Usage);
	__declspec(property(get = get_bind_flags, put = set_bind_flags)) Bind_flag BindFlags;
	__declspec(property(get = get_cpu_access_flags, put = set_cpu_access_flags)) Cpu_access_flag CPUAccessFlags;
	__declspec(property(get = get_misc_flags, put = set_misc_flags)) Resource_misc_flag MiscFlags;
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_structure_byte_stride, Uint, StructureByteStride);

};
static_assert(sizeof(Buffer_desc) == sizeof(D3D11_BUFFER_DESC));

inline bool operator==(const Buffer_desc& lhs, const Buffer_desc& rhs) noexcept {
	return (lhs.ByteWidth == rhs.ByteWidth)
		&& (lhs.Usage == rhs.Usage)
		&& (lhs.BindFlags == rhs.BindFlags)
		&& (lhs.CPUAccessFlags == rhs.CPUAccessFlags)
		&& (lhs.MiscFlags == rhs.MiscFlags)
		&& (lhs.StructureByteStride == rhs.StructureByteStride);
}

inline bool operator!=(const Buffer_desc& lhs, const Buffer_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Depth_stencil_view_desc {
	_HW_3D_DXGI_ Format _format;
	Dsv_dimension _view_dimension;
	Uint _flags;
	union {
		Tex1d_dsv _texture_1d;
		Tex1d_array_dsv _texture_1d_array;
		Tex2d_dsv _texture_2d;
		Tex2d_array_dsv _texture_2d_array;
		Tex2dms_dsv _texture_2d_ms;
		Tex2dms_array_dsv _texture_2d_ms_array;
	};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Depth_stencil_view_desc, D3D11_DEPTH_STENCIL_VIEW_DESC)
public:
	Depth_stencil_view_desc & set_flags(Dsv_flag flags_) {
		_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Dsv_flag get_flags() const noexcept {
		return Dsv_flag_bit(_flags);
	}

	Depth_stencil_view_desc& set_texture_1d(const Tex1d_dsv& tex) {
		_view_dimension = Dsv_dimension::texture1d;
		_texture_1d = tex;
		return (*this);
	}

	Tex1d_dsv get_texture_1d() const noexcept {
		assert(_view_dimension == Dsv_dimension::texture1d);
		return _texture_1d;
	}

	Depth_stencil_view_desc& set_texture_1d_array(const Tex1d_array_dsv& tex) {
		_view_dimension = Dsv_dimension::texture1darray;
		_texture_1d_array = tex;
		return (*this);
	}

	Tex1d_array_dsv get_texture_1d_array() const noexcept {
		assert(_view_dimension == Dsv_dimension::texture1darray);
		return _texture_1d_array;
	}

	Depth_stencil_view_desc& set_texture_2d(const Tex2d_dsv& tex) {
		_view_dimension = Dsv_dimension::texture2d;
		_texture_2d = tex;
		return (*this);
	}

	Tex2d_dsv get_texture_2d() const noexcept {
		assert(_view_dimension == Dsv_dimension::texture2d);
		return _texture_2d;
	}

	Depth_stencil_view_desc& set_texture_2d_array(const Tex2d_array_dsv& tex) {
		_view_dimension = Dsv_dimension::texture2darray;
		_texture_2d_array = tex;
		return (*this);
	}

	Tex2d_array_dsv get_texture_2d_array() const noexcept {
		assert(_view_dimension == Dsv_dimension::texture2darray);
		return _texture_2d_array;
	}

	Depth_stencil_view_desc& set_texture_2d_ms(const Tex2dms_dsv& tex) {
		_view_dimension = Dsv_dimension::texture2dms;
		_texture_2d_ms = tex;
		return (*this);
	}

	Tex2dms_dsv get_texture_2d_ms() const noexcept {
		assert(_view_dimension == Dsv_dimension::texture2dms);
		return _texture_2d_ms;
	}

	Depth_stencil_view_desc& set_texture_2d_ms_array(const Tex2dms_array_dsv& tex) {
		_view_dimension = Dsv_dimension::texture2dmsarray;
		_texture_2d_ms_array = tex;
		return (*this);
	}

	Tex2dms_array_dsv get_texture_2d_ms_array() const noexcept {
		assert(_view_dimension == Dsv_dimension::texture2dmsarray);
		return _texture_2d_ms_array;
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_format, _HW_3D_DXGI_ Format, Format);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_view_dimension, Dsv_dimension, ViewDimension);
	__declspec(property(get = get_flags, put = put_flags)) Dsv_flag Flags;
	__declspec(property(get = get_texture_1d, put = set_texture_1d)) Tex1d_dsv Texture1D;
	__declspec(property(get = get_texture_1d_array, put = set_texture_1d_array)) Tex1d_array_dsv Texture1DArray;
	__declspec(property(get = get_texture_2d, put = set_texture_2d)) Tex2d_dsv Texture2D;
	__declspec(property(get = get_texture_2d_array, put = set_texture_2d_array)) Tex2d_array_dsv Texture2DArray;
	__declspec(property(get = get_texture_2d_ms, put = set_texture_2d_ms)) Tex2dms_dsv Texture2DMS;
	__declspec(property(get = get_texture_2d_ms_array, put = set_texture_2d_ms_array)) Tex2dms_array_dsv Texture2DMSArray;
};
static_assert(sizeof(Depth_stencil_view_desc) == sizeof(D3D11_DEPTH_STENCIL_VIEW_DESC));

inline bool operator==(const Depth_stencil_view_desc& lhs, const Depth_stencil_view_desc& rhs) noexcept {
	if (lhs.Format != rhs.Format || lhs.ViewDimension != rhs.ViewDimension || lhs.Flags != rhs.Flags)
		return false;
	switch (lhs.ViewDimension) {
	case Dsv_dimension::texture1d:
		return lhs.Texture1D == rhs.Texture1D;
	case Dsv_dimension::texture1darray:
		return lhs.Texture1DArray == rhs.Texture1DArray;
	case Dsv_dimension::texture2d:
		return lhs.Texture2D == rhs.Texture2D;
	case Dsv_dimension::texture2darray:
		return lhs.Texture2DArray == rhs.Texture2DArray;
	case Dsv_dimension::texture2dms:
		return lhs.Texture2DMS == rhs.Texture2DMS;
	case Dsv_dimension::texture2dmsarray:
		return lhs.Texture2DMSArray == rhs.Texture2DMSArray;
	default:
		return false;
	}
}

inline bool operator!=(const Depth_stencil_view_desc& lhs, const Depth_stencil_view_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Packed_mip_desc {
	Uint8 _num_standard_mips{ 0 };
	Uint8 _num_packed_mips{ 0 };
	Uint _num_tiles_for_packed_mips{ 0 };
	Uint _start_tile_index_in_overall_resource{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Packed_mip_desc, D3D11_PACKED_MIP_DESC)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_num_standard_mips, Uint8, NumStandardMips);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_num_packed_mips, Uint8, NumPackedMips);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_num_tiles_for_packed_mips, Uint, NumTilesForPackedMips);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_start_tile_index_in_overall_resource, Uint, StartTileIndexInOverallResource);
};
static_assert(sizeof(Packed_mip_desc) == sizeof(D3D11_PACKED_MIP_DESC));

inline bool operator==(const Packed_mip_desc& lhs, const Packed_mip_desc& rhs) noexcept {
	return (lhs.NumPackedMips == rhs.NumPackedMips)
		&& (lhs.NumStandardMips == rhs.NumStandardMips)
		&& (lhs.NumTilesForPackedMips == rhs.NumTilesForPackedMips)
		&& (lhs.StartTileIndexInOverallResource == rhs.StartTileIndexInOverallResource);
}

inline bool operator!=(const Packed_mip_desc& lhs, const Packed_mip_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Render_target_view_desc {
	_HW_3D_DXGI_ Format _format;
	Rtv_dimension _view_dimension;
	union {
		Buffer_rtv _buffer;
		Tex1d_rtv _texture_1d;
		Tex1d_array_rtv _texture_1d_array;
		Tex2d_rtv _texture_2d;
		Tex2d_array_rtv _texture_2d_array;
		Tex2dms_rtv _texture_2d_ms;
		Tex2dms_array_rtv _texture_2d_ms_array;
		Tex3d_rtv _texture_3d;
	};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Render_target_view_desc, D3D11_RENDER_TARGET_VIEW_DESC)
public:
	Render_target_view_desc & set_buffer(const Buffer_rtv& buf) {
		_view_dimension = Rtv_dimension::buffer;
		_buffer = buf;
		return (*this);
	}

	Buffer_rtv get_buffer() const noexcept {
		assert(_view_dimension == Rtv_dimension::buffer);
		return _buffer;
	}

	Render_target_view_desc& set_texture_1d(const Tex1d_rtv& tex) {
		_view_dimension = Rtv_dimension::texture1d;
		_texture_1d = tex;
		return (*this);
	}

	Tex1d_rtv get_texture_1d() const noexcept {
		assert(_view_dimension == Rtv_dimension::texture1d);
		return _texture_1d;
	}

	Render_target_view_desc& set_texture_1d_array(const Tex1d_array_rtv& tex) {
		_view_dimension = Rtv_dimension::texture1darray;
		_texture_1d_array = tex;
		return (*this);
	}

	Tex1d_array_rtv get_texture_1d_array() const noexcept {
		assert(_view_dimension == Rtv_dimension::texture1darray);
		return _texture_1d_array;
	}

	Render_target_view_desc& set_texture_2d(const Tex2d_rtv& tex) {
		_view_dimension = Rtv_dimension::texture2d;
		_texture_2d = tex;
		return (*this);
	}

	Tex2d_rtv get_texture_2d() const noexcept {
		assert(_view_dimension == Rtv_dimension::texture2d);
		return _texture_2d;
	}

	Render_target_view_desc& set_texture_2d_array(const Tex2d_array_rtv& tex) {
		_view_dimension = Rtv_dimension::texture2darray;
		_texture_2d_array = tex;
		return (*this);
	}

	Tex2d_array_rtv get_texture_2d_array() const noexcept {
		assert(_view_dimension == Rtv_dimension::texture2darray);
		return _texture_2d_array;
	}

	Render_target_view_desc& set_texture_2d_ms(const Tex2dms_rtv& tex) {
		_view_dimension = Rtv_dimension::texture2dms;
		_texture_2d_ms = tex;
		return (*this);
	}

	Tex2dms_rtv get_texture_2d_ms() const noexcept {
		assert(_view_dimension == Rtv_dimension::texture2dms);
		return _texture_2d_ms;
	}

	Render_target_view_desc& set_texture_2d_ms_array(const Tex2dms_array_rtv& tex) {
		_view_dimension = Rtv_dimension::texture2dmsarray;
		_texture_2d_ms_array = tex;
		return (*this);
	}

	Tex2dms_array_rtv get_texture_2d_ms_array() const noexcept {
		assert(_view_dimension == Rtv_dimension::texture2dmsarray);
		return _texture_2d_ms_array;
	}

	Render_target_view_desc& set_texture_3d(const Tex3d_rtv& tex) {
		_view_dimension = Rtv_dimension::texture3d;
		_texture_3d = tex;
		return (*this);
	}

	Tex3d_rtv get_texture_3d() const noexcept {
		assert(_view_dimension == Rtv_dimension::texture3d);
		return _texture_3d;
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_format, _HW_3D_DXGI_ Format, Format);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_view_dimension, Rtv_dimension, ViewDimension);
	//实际上ViewDimension并不是一个trivial的变量，这里仅仅为了少些几行代码
	__declspec(property(get = get_buffer, put = set_buffer)) Buffer_rtv Buffer;
	__declspec(property(get = get_texture_1d, put = set_texture_1d)) Tex1d_rtv Texture1D;
	__declspec(property(get = get_texture_1d_array, put = set_texture_1d_array)) Tex1d_array_rtv Texture1DArray;
	__declspec(property(get = get_texture_2d, put = set_texture_2d)) Tex2d_rtv Texture2D;
	__declspec(property(get = get_texture_2d_array, put = set_texture_2d_array)) Tex2d_array_rtv Texture2DArray;
	__declspec(property(get = get_texture_2d_ms, put = set_texture_2d_ms)) Tex2dms_rtv Texture2DMS;
	__declspec(property(get = get_texture_2d_ms_array, put = set_texture_2d_ms_array)) Tex2dms_array_rtv Texture2DMSArray;
	__declspec(property(get = get_texture_3d, put = set_texture_3d)) Tex3d_rtv Texture3D;
};
static_assert(sizeof(Render_target_view_desc) == sizeof(D3D11_RENDER_TARGET_VIEW_DESC));

inline bool operator==(const Render_target_view_desc& lhs, const Render_target_view_desc& rhs) noexcept {
	if (lhs.Format != rhs.Format || lhs.ViewDimension != rhs.ViewDimension)
		return false;
	switch (lhs.ViewDimension) {
	case Rtv_dimension::buffer:
		return lhs.Buffer == rhs.Buffer;
	case Rtv_dimension::texture1d:
		return lhs.Texture1D == rhs.Texture1D;
	case Rtv_dimension::texture1darray:
		return lhs.Texture1DArray == rhs.Texture1DArray;
	case Rtv_dimension::texture2d:
		return lhs.Texture2D == rhs.Texture2D;
	case Rtv_dimension::texture2darray:
		return lhs.Texture2DArray == rhs.Texture2DArray;
	case Rtv_dimension::texture2dms:
		return lhs.Texture2DMS == rhs.Texture2DMS;
	case Rtv_dimension::texture2dmsarray:
		return lhs.Texture2DMSArray == rhs.Texture2DMSArray;
	case Rtv_dimension::texture3d:
		return lhs.Texture3D == rhs.Texture3D;
	default:
		return false;
	}
}

inline bool operator!=(const Render_target_view_desc& lhs, const Render_target_view_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Render_target_view_desc1 {
	_HW_3D_DXGI_ Format _format;
	Rtv_dimension _view_dimension;
	union {
		Buffer_rtv _buffer;
		Tex1d_rtv _texture_1d;
		Tex1d_array_rtv _texture_1d_array;
		Tex2d_rtv1 _texture_2d;
		Tex2d_array_rtv1 _texture_2d_array;
		Tex2dms_rtv _texture_2d_ms;
		Tex2dms_array_rtv _texture_2d_ms_array;
		Tex3d_rtv _texture_3d;
	};
public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Render_target_view_desc1, D3D11_RENDER_TARGET_VIEW_DESC1)
public:
	Render_target_view_desc1 & set_buffer(const Buffer_rtv& buf) {
		_view_dimension = Rtv_dimension::buffer;
		_buffer = buf;
		return (*this);
	}

	Buffer_rtv get_buffer() const noexcept {
		assert(_view_dimension == Rtv_dimension::buffer);
		return _buffer;
	}

	Render_target_view_desc1& set_texture_1d(const Tex1d_rtv& tex) {
		_view_dimension = Rtv_dimension::texture1d;
		_texture_1d = tex;
		return (*this);
	}

	Tex1d_rtv get_texture_1d() const noexcept {
		assert(_view_dimension == Rtv_dimension::texture1d);
		return _texture_1d;
	}

	Render_target_view_desc1& set_texture_1d_array(const Tex1d_array_rtv& tex) {
		_view_dimension = Rtv_dimension::texture1darray;
		_texture_1d_array = tex;
		return (*this);
	}

	Tex1d_array_rtv get_texture_1d_array() const noexcept {
		assert(_view_dimension == Rtv_dimension::texture1darray);
		return _texture_1d_array;
	}

	Render_target_view_desc1& set_texture_2d(const Tex2d_rtv1& tex) {
		_view_dimension = Rtv_dimension::texture2d;
		_texture_2d = tex;
		return (*this);
	}

	Tex2d_rtv1 get_texture_2d() const noexcept {
		assert(_view_dimension == Rtv_dimension::texture2d);
		return _texture_2d;
	}

	Render_target_view_desc1& set_texture_2d_array(const Tex2d_array_rtv1& tex) {
		_view_dimension = Rtv_dimension::texture2darray;
		_texture_2d_array = tex;
		return (*this);
	}

	Tex2d_array_rtv1 get_texture_2d_array() const noexcept {
		assert(_view_dimension == Rtv_dimension::texture2darray);
		return _texture_2d_array;
	}

	Render_target_view_desc1& set_texture_2d_ms(const Tex2dms_rtv& tex) {
		_view_dimension = Rtv_dimension::texture2dms;
		_texture_2d_ms = tex;
		return (*this);
	}

	Tex2dms_rtv get_texture_2d_ms() const noexcept {
		assert(_view_dimension == Rtv_dimension::texture2dms);
		return _texture_2d_ms;
	}

	Render_target_view_desc1& set_texture_2d_ms_array(const Tex2dms_array_rtv& tex) {
		_view_dimension = Rtv_dimension::texture2dmsarray;
		_texture_2d_ms_array = tex;
		return (*this);
	}

	Tex2dms_array_rtv get_texture_2d_ms_array() const noexcept {
		assert(_view_dimension == Rtv_dimension::texture2dmsarray);
		return _texture_2d_ms_array;
	}

	Render_target_view_desc1& set_texture_3d(const Tex3d_rtv& tex) {
		_view_dimension = Rtv_dimension::texture3d;
		_texture_3d = tex;
		return (*this);
	}

	Tex3d_rtv get_texture_3d() const noexcept {
		assert(_view_dimension == Rtv_dimension::texture3d);
		return _texture_3d;
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_format, _HW_3D_DXGI_ Format, Format);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_view_dimension, Rtv_dimension, ViewDimension);
	__declspec(property(get = get_buffer, put = set_buffer)) Buffer_rtv Buffer;
	__declspec(property(get = get_texture_1d, put = set_texture_1d)) Tex1d_rtv Texture1D;
	__declspec(property(get = get_texture_1d_array, put = set_texture_1d_array)) Tex1d_array_rtv Texture1DArray;
	__declspec(property(get = get_texture_2d, put = set_texture_2d)) Tex2d_rtv1 Texture2D;
	__declspec(property(get = get_texture_2d_array, put = set_texture_2d_array)) Tex2d_array_rtv1 Texture2DArray;
	__declspec(property(get = get_texture_2d_ms, put = set_texture_2d_ms)) Tex2dms_rtv Texture2DMS;
	__declspec(property(get = get_texture_2d_ms_array, put = set_texture_2d_ms_array)) Tex2dms_array_rtv Texture2DMSArray;
	__declspec(property(get = get_texture_3d, put = set_texture_3d)) Tex3d_rtv Texture3D;
};
static_assert(sizeof(Render_target_view_desc1) == sizeof(D3D11_RENDER_TARGET_VIEW_DESC1));

inline bool operator==(const Render_target_view_desc1& lhs, const Render_target_view_desc1& rhs) noexcept {
	if (lhs.Format != rhs.Format || lhs.ViewDimension != rhs.ViewDimension)
		return false;
	switch (lhs.ViewDimension) {
	case Rtv_dimension::buffer:
		return lhs.Buffer == rhs.Buffer;
	case Rtv_dimension::texture1d:
		return lhs.Texture1D == rhs.Texture1D;
	case Rtv_dimension::texture1darray:
		return lhs.Texture1DArray == rhs.Texture1DArray;
	case Rtv_dimension::texture2d:
		return lhs.Texture2D == rhs.Texture2D;
	case Rtv_dimension::texture2darray:
		return lhs.Texture2DArray == rhs.Texture2DArray;
	case Rtv_dimension::texture2dms:
		return lhs.Texture2DMS == rhs.Texture2DMS;
	case Rtv_dimension::texture2dmsarray:
		return lhs.Texture2DMSArray == rhs.Texture2DMSArray;
	case Rtv_dimension::texture3d:
		return lhs.Texture3D == rhs.Texture3D;
	default:
		return false;
	}
}

inline bool operator!=(const Render_target_view_desc1& lhs, const Render_target_view_desc1& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Shader_resource_view_desc {
	_HW_3D_DXGI_ Format _format;
	Srv_dimension _view_dimension;
	union {
		Buffer_srv _buffer;
		Tex1d_srv _texture_1d;
		Tex1d_array_srv _texture_1d_array;
		Tex2d_srv _texture_2d;
		Tex2d_array_srv _texture_2d_array;
		Tex2dms_srv _texture_2d_ms;
		Tex2dms_array_srv _texture_2d_ms_array;
		Tex3d_srv _texture_3d;
		Texcube_srv _texture_cube;
		Texcube_array_srv _texture_cube_array;
		Buffer_ex_srv _buffer_ex;
	};
public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Shader_resource_view_desc, D3D11_SHADER_RESOURCE_VIEW_DESC)
public:
	Shader_resource_view_desc & set_buffer(const Buffer_srv& buf) {
		_view_dimension = Srv_dimension::buffer;
		_buffer = buf;
		return (*this);
	}

	Buffer_srv get_buffer() const noexcept {
		assert(_view_dimension == Srv_dimension::buffer);
		return _buffer;
	}

	Shader_resource_view_desc& set_texture_1d(const Tex1d_srv& tex) {
		_view_dimension = Srv_dimension::texture1d;
		_texture_1d = tex;
		return (*this);
	}

	Tex1d_srv get_texture_1d() const noexcept {
		assert(_view_dimension == Srv_dimension::texture1d);
		return _texture_1d;
	}

	Shader_resource_view_desc& set_texture_1d_array(const Tex1d_array_srv& tex) {
		_view_dimension = Srv_dimension::texture1darray;
		_texture_1d_array = tex;
		return (*this);
	}

	Tex1d_array_srv get_texture_1d_array() const noexcept {
		assert(_view_dimension == Srv_dimension::texture1darray);
		return _texture_1d_array;
	}

	Shader_resource_view_desc& set_texture_2d(const Tex2d_srv& tex) {
		_view_dimension = Srv_dimension::texture2d;
		_texture_2d = tex;
		return (*this);
	}

	Tex2d_srv get_texture_2d() const noexcept {
		assert(_view_dimension == Srv_dimension::texture2d);
		return _texture_2d;
	}

	Shader_resource_view_desc& set_texture_2d_array(const Tex2d_array_srv& tex) {
		_view_dimension = Srv_dimension::texture2darray;
		_texture_2d_array = tex;
		return (*this);
	}

	Tex2d_array_srv get_texture_2d_array() const noexcept {
		assert(_view_dimension == Srv_dimension::texture2darray);
		return _texture_2d_array;
	}

	Shader_resource_view_desc& set_texture_2d_ms(const Tex2dms_srv& tex) {
		_view_dimension = Srv_dimension::texture2dms;
		_texture_2d_ms = tex;
		return (*this);
	}

	Tex2dms_srv get_texture_2d_ms() const noexcept {
		assert(_view_dimension == Srv_dimension::texture2dms);
		return _texture_2d_ms;
	}

	Shader_resource_view_desc& set_texture_2d_ms_array(const Tex2dms_array_srv& tex) {
		_view_dimension = Srv_dimension::texture2dmsarray;
		_texture_2d_ms_array = tex;
		return (*this);
	}

	Tex2dms_array_srv get_texture_2d_ms_array() const noexcept {
		assert(_view_dimension == Srv_dimension::texture2dmsarray);
		return _texture_2d_ms_array;
	}

	Shader_resource_view_desc& set_texture_3d(const Tex3d_srv& tex) {
		_view_dimension = Srv_dimension::texture3d;
		_texture_3d = tex;
		return (*this);
	}

	Tex3d_srv get_texture_3d() const noexcept {
		assert(_view_dimension == Srv_dimension::texture3d);
		return _texture_3d;
	}

	Shader_resource_view_desc& set_texture_cube(const Texcube_srv& tex) {
		_view_dimension = Srv_dimension::texturecube;
		_texture_cube = tex;
		return (*this);
	}

	Texcube_srv get_texture_cube() const noexcept {
		assert(_view_dimension == Srv_dimension::texturecube);
		return _texture_cube;
	}

	Shader_resource_view_desc& set_texture_cube_array(const Texcube_array_srv& tex) {
		_view_dimension = Srv_dimension::texturecubearray;
		_texture_cube_array = tex;
		return (*this);
	}

	Texcube_array_srv get_texture_cube_array() const noexcept {
		assert(_view_dimension == Srv_dimension::texturecubearray);
		return _texture_cube_array;
	}

	Shader_resource_view_desc& set_buffer_ex(const Buffer_ex_srv& buf) {
		_view_dimension = Srv_dimension::bufferex;
		_buffer_ex = buf;
		return (*this);
	}

	Buffer_ex_srv get_buffer_ex() const noexcept {
		assert(_view_dimension == Srv_dimension::bufferex);
		return _buffer_ex;
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_format, _HW_3D_DXGI_ Format, Format);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_view_dimension, Srv_dimension, ViewDimension);
	__declspec(property(get = get_buffer, put = set_buffer)) Buffer_srv Buffer;
	__declspec(property(get = get_texture_1d, put = set_texture_1d)) Tex1d_srv Texture1D;
	__declspec(property(get = get_texture_1d_array, put = set_texture_1d_array)) Tex1d_array_srv Texture1DArray;
	__declspec(property(get = get_texture_2d, put = set_texture_2d)) Tex2d_srv Texture2D;
	__declspec(property(get = get_texture_2d_array, put = set_texture_2d_array)) Tex2d_array_srv Texture2DArray;
	__declspec(property(get = get_texture_2d_ms, put = set_texture_2d_ms)) Tex2dms_srv Texture2DMS;
	__declspec(property(get = get_texture_2d_ms_array, put = set_texture_2d_ms_array)) Tex2dms_array_srv Texture2DMSArray;
	__declspec(property(get = get_texture_3d, put = set_texture_3d)) Tex3d_srv Texture3D;
	__declspec(property(get = get_texture_cube, put = set_texture_cube)) Texcube_srv TextureCube;
	__declspec(property(get = get_texture_cube_array, put = set_texture_cube_array)) Texcube_array_srv TextureCubeArray;
	__declspec(property(get = get_buffer_ex, put = set_buffer_ex)) Buffer_ex_srv BufferEx;
};
static_assert(sizeof(Shader_resource_view_desc) == sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC));

inline bool operator==(const Shader_resource_view_desc& lhs, const Shader_resource_view_desc& rhs) noexcept {
	if (lhs.Format != rhs.Format || lhs.ViewDimension != rhs.ViewDimension)
		return false;
	switch (lhs.ViewDimension) {
	case Srv_dimension::buffer:
		return lhs.Buffer == rhs.Buffer;
	case Srv_dimension::bufferex:
		return lhs.BufferEx == rhs.BufferEx;
	case Srv_dimension::texture1d:
		return lhs.Texture1D == rhs.Texture1D;
	case Srv_dimension::texture1darray:
		return lhs.Texture1DArray == rhs.Texture1DArray;
	case Srv_dimension::texture2d:
		return lhs.Texture2D == rhs.Texture2D;
	case Srv_dimension::texture2darray:
		return lhs.Texture2DArray == rhs.Texture2DArray;
	case Srv_dimension::texture2dms:
		return lhs.Texture2DMS == rhs.Texture2DMS;
	case Srv_dimension::texture2dmsarray:
		return lhs.Texture2DMSArray == rhs.Texture2DMSArray;
	case Srv_dimension::texture3d:
		return lhs.Texture3D == rhs.Texture3D;
	case Srv_dimension::texturecube:
		return lhs.TextureCube == rhs.TextureCube;
	case Srv_dimension::texturecubearray:
		return lhs.TextureCubeArray == rhs.TextureCubeArray;
	default:
		return false;
	}
}

inline bool operator!=(const Shader_resource_view_desc& lhs, const Shader_resource_view_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Shader_resource_view_desc1 {
	_HW_3D_DXGI_ Format _format;
	Srv_dimension _view_dimension;
	union {
		Buffer_srv _buffer;
		Tex1d_srv _texture_1d;
		Tex1d_array_srv _texture_1d_array;
		Tex2d_srv1 _texture_2d;
		Tex2d_array_srv1 _texture_2d_array;
		Tex2dms_srv _texture_2d_ms;
		Tex2dms_array_srv _texture_2d_ms_array;
		Tex3d_srv _texture_3d;
		Texcube_srv _texture_cube;
		Texcube_array_srv _texture_cube_array;
		Buffer_ex_srv _buffer_ex;
	};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Shader_resource_view_desc1, D3D11_SHADER_RESOURCE_VIEW_DESC1)
public:
	Shader_resource_view_desc1 & set_buffer(const Buffer_srv& buf) {
		_view_dimension = Srv_dimension::buffer;
		_buffer = buf;
		return (*this);
	}

	Buffer_srv get_buffer() const noexcept {
		assert(_view_dimension == Srv_dimension::buffer);
		return _buffer;
	}

	Shader_resource_view_desc1& set_texture_1d(const Tex1d_srv& tex) {
		_view_dimension = Srv_dimension::texture1d;
		_texture_1d = tex;
		return (*this);
	}

	Tex1d_srv get_texture_1d() const noexcept {
		assert(_view_dimension == Srv_dimension::texture1d);
		return _texture_1d;
	}

	Shader_resource_view_desc1& set_texture_1d_array(const Tex1d_array_srv& tex) {
		_view_dimension = Srv_dimension::texture1darray;
		_texture_1d_array = tex;
		return (*this);
	}

	Tex1d_array_srv get_texture_1d_array() const noexcept {
		assert(_view_dimension == Srv_dimension::texture1darray);
		return _texture_1d_array;
	}

	Shader_resource_view_desc1& set_texture_2d(const Tex2d_srv1& tex) {
		_view_dimension = Srv_dimension::texture2d;
		_texture_2d = tex;
		return (*this);
	}

	Tex2d_srv1 get_texture_2d() const noexcept {
		assert(_view_dimension == Srv_dimension::texture2d);
		return _texture_2d;
	}

	Shader_resource_view_desc1& set_texture_2d_array(const Tex2d_array_srv1& tex) {
		_view_dimension = Srv_dimension::texture2darray;
		_texture_2d_array = tex;
		return (*this);
	}

	Tex2d_array_srv1 get_texture_2d_array() const noexcept {
		assert(_view_dimension == Srv_dimension::texture2darray);
		return _texture_2d_array;
	}

	Shader_resource_view_desc1& set_texture_2d_ms(const Tex2dms_srv& tex) {
		_view_dimension = Srv_dimension::texture2dms;
		_texture_2d_ms = tex;
		return (*this);
	}

	Tex2dms_srv get_texture_2d_ms() const noexcept {
		assert(_view_dimension == Srv_dimension::texture2dms);
		return _texture_2d_ms;
	}

	Shader_resource_view_desc1& set_texture_2d_ms_array(const Tex2dms_array_srv& tex) {
		_view_dimension = Srv_dimension::texture2dmsarray;
		_texture_2d_ms_array = tex;
		return (*this);
	}

	Tex2dms_array_srv get_texture_2d_ms_array() const noexcept {
		assert(_view_dimension == Srv_dimension::texture2dmsarray);
		return _texture_2d_ms_array;
	}

	Shader_resource_view_desc1& set_texture_3d(const Tex3d_srv& tex) {
		_view_dimension = Srv_dimension::texture3d;
		_texture_3d = tex;
		return (*this);
	}

	Tex3d_srv get_texture_3d() const noexcept {
		assert(_view_dimension == Srv_dimension::texture3d);
		return _texture_3d;
	}

	Shader_resource_view_desc1& set_texture_cube(const Texcube_srv& tex) {
		_view_dimension = Srv_dimension::texturecube;
		_texture_cube = tex;
		return (*this);
	}

	Texcube_srv get_texture_cube() const noexcept {
		assert(_view_dimension == Srv_dimension::texturecube);
		return _texture_cube;
	}

	Shader_resource_view_desc1& set_texture_cube_array(const Texcube_array_srv& tex) {
		_view_dimension = Srv_dimension::texturecubearray;
		_texture_cube_array = tex;
		return (*this);
	}

	Texcube_array_srv get_texture_cube_array() const noexcept {
		assert(_view_dimension == Srv_dimension::texturecubearray);
		return _texture_cube_array;
	}

	Shader_resource_view_desc1& set_buffer_ex(const Buffer_ex_srv& buf) {
		_view_dimension = Srv_dimension::bufferex;
		_buffer_ex = buf;
		return (*this);
	}

	Buffer_ex_srv get_buffer_ex() const noexcept {
		assert(_view_dimension == Srv_dimension::bufferex);
		return _buffer_ex;
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_format, _HW_3D_DXGI_ Format, Format);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_view_dimension, Srv_dimension, ViewDimension);
	__declspec(property(get = get_buffer, put = set_buffer)) Buffer_srv Buffer;
	__declspec(property(get = get_texture_1d, put = set_texture_1d)) Tex1d_srv Texture1D;
	__declspec(property(get = get_texture_1d_array, put = set_texture_1d_array)) Tex1d_array_srv Texture1DArray;
	__declspec(property(get = get_texture_2d, put = set_texture_2d)) Tex2d_srv1 Texture2D;
	__declspec(property(get = get_texture_2d_array, put = set_texture_2d_array)) Tex2d_array_srv1 Texture2DArray;
	__declspec(property(get = get_texture_2d_ms, put = set_texture_2d_ms)) Tex2dms_srv Texture2DMS;
	__declspec(property(get = get_texture_2d_ms_array, put = set_texture_2d_ms_array)) Tex2dms_array_srv Texture2DMSArray;
	__declspec(property(get = get_texture_3d, put = set_texture_3d)) Tex3d_srv Texture3D;
	__declspec(property(get = get_texture_cube, put = set_texture_cube)) Texcube_srv TextureCube;
	__declspec(property(get = get_texture_cube_array, put = set_texture_cube_array)) Texcube_array_srv TextureCubeArray;
	__declspec(property(get = get_buffer_ex, put = set_buffer_ex)) Buffer_ex_srv BufferEx;
};
static_assert(sizeof(Shader_resource_view_desc1) == sizeof(D3D11_SHADER_RESOURCE_VIEW_DESC1));

inline bool operator==(const Shader_resource_view_desc1& lhs, const Shader_resource_view_desc1& rhs) noexcept {
	if (lhs.Format != rhs.Format || lhs.ViewDimension != rhs.ViewDimension)
		return false;
	switch (lhs.ViewDimension) {
	case Srv_dimension::buffer:
		return lhs.Buffer == rhs.Buffer;
	case Srv_dimension::bufferex:
		return lhs.BufferEx == rhs.BufferEx;
	case Srv_dimension::texture1d:
		return lhs.Texture1D == rhs.Texture1D;
	case Srv_dimension::texture1darray:
		return lhs.Texture1DArray == rhs.Texture1DArray;
	case Srv_dimension::texture2d:
		return lhs.Texture2D == rhs.Texture2D;
	case Srv_dimension::texture2darray:
		return lhs.Texture2DArray == rhs.Texture2DArray;
	case Srv_dimension::texture2dms:
		return lhs.Texture2DMS == rhs.Texture2DMS;
	case Srv_dimension::texture2dmsarray:
		return lhs.Texture2DMSArray == rhs.Texture2DMSArray;
	case Srv_dimension::texture3d:
		return lhs.Texture3D == rhs.Texture3D;
	case Srv_dimension::texturecube:
		return lhs.TextureCube == rhs.TextureCube;
	case Srv_dimension::texturecubearray:
		return lhs.TextureCubeArray == rhs.TextureCubeArray;
	default:
		return false;
	}
}

inline bool operator!=(const Shader_resource_view_desc1& lhs, const Shader_resource_view_desc1& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Texture1d_desc {
	Uint _width{ 0 };
	Uint _mip_levels{ 0 };
	Uint _array_size{ 0 };
	_HW_3D_DXGI_ Format _format{};
	Usage _usage{};
	Uint _bind_flags{ 0 };
	Uint _cpu_access_flags{ 0 };
	Uint _misc_flags{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Texture1d_desc, D3D11_TEXTURE1D_DESC)
public:
	Texture1d_desc & set_bind_flags(Bind_flag flags_) {
		_bind_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Bind_flag get_bind_flags() const noexcept {
		return Bind_flag_bit(_bind_flags);
	}

	Texture1d_desc& set_cpu_access_flags(Cpu_access_flag flags_) {
		_cpu_access_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Cpu_access_flag get_cpu_access_flags() const noexcept {
		return Cpu_access_flag_bit(_cpu_access_flags);
	}

	Texture1d_desc& set_misc_flags(Resource_misc_flag flags_) {
		_misc_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Resource_misc_flag get_misc_flags() const noexcept {
		return Resource_misc_flag_bit(_misc_flags);
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_width, Uint, Width);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_levels, Uint, MipLevels);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_array_size, Uint, ArraySize);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_format, _HW_3D_DXGI_ Format, Format);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_usage, _HW_3D_D3D_ Usage, Usage);
	__declspec(property(get = get_bind_flags, put = set_bind_flags)) Bind_flag BindFlags;
	__declspec(property(get = get_cpu_access_flags, put = set_cpu_access_flags)) Cpu_access_flag CPUAccessFlags;
	__declspec(property(get = get_misc_flags, put = set_misc_flags)) Resource_misc_flag MiscFlags;
};
static_assert(sizeof(Texture1d_desc) == sizeof(D3D11_TEXTURE1D_DESC));

inline bool operator==(const Texture1d_desc& lhs, const Texture1d_desc& rhs) noexcept {
	return (lhs.Width == rhs.Width)
		&& (lhs.MipLevels == rhs.MipLevels)
		&& (lhs.ArraySize == rhs.ArraySize)
		&& (lhs.Format == rhs.Format)
		&& (lhs.Usage == rhs.Usage)
		&& (lhs.BindFlags == rhs.BindFlags)
		&& (lhs.CPUAccessFlags == rhs.CPUAccessFlags)
		&& (lhs.MiscFlags == rhs.MiscFlags);
}

inline bool operator!=(const Texture1d_desc& lhs, const Texture1d_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Texture2d_desc {
	Uint _width{ 0 };
	Uint _height{ 0 };
	Uint _mip_levels{ 0 };
	Uint _array_size{ 0 };
	_HW_3D_DXGI_ Format _format{};
	_HW_3D_DXGI_ Sample_desc _sample_desc{};
	Usage _usage{};
	Uint _bind_flags{ 0 };
	Uint _cpu_access_flags{ 0 };
	Uint _misc_flags{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Texture2d_desc, D3D11_TEXTURE2D_DESC)
public:
	Texture2d_desc & set_bind_flags(Bind_flag flags_) {
		_bind_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Bind_flag get_bind_flags() const noexcept {
		return Bind_flag_bit(_bind_flags);
	}

	Texture2d_desc& set_cpu_access_flags(Cpu_access_flag flags_) {
		_cpu_access_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Cpu_access_flag get_cpu_access_flags() const noexcept {
		return Cpu_access_flag_bit(_cpu_access_flags);
	}

	Texture2d_desc& set_misc_flags(Resource_misc_flag flags_) {
		_misc_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Resource_misc_flag get_misc_flags() const noexcept {
		return Resource_misc_flag_bit(_misc_flags);
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_width, Uint, Width);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_height, Uint, Height);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_levels, Uint, MipLevels);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_array_size, Uint, ArraySize);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_format, _HW_3D_DXGI_ Format, Format);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_sample_desc, _HW_3D_DXGI_ Sample_desc, SampleDesc);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_usage, _HW_3D_D3D_ Usage, Usage);
	__declspec(property(get = get_bind_flags, put = set_bind_flags)) Bind_flag BindFlags;
	__declspec(property(get = get_cpu_access_flags, put = set_cpu_access_flags)) Cpu_access_flag CPUAccessFlags;
	__declspec(property(get = get_misc_flags, put = set_misc_flags)) Resource_misc_flag MiscFlags;
};
static_assert (sizeof(Texture2d_desc) == sizeof(D3D11_TEXTURE2D_DESC));

inline bool operator==(const Texture2d_desc& lhs, const Texture2d_desc& rhs) noexcept {
	return (lhs.Width == rhs.Width)
		&& (lhs.Height == rhs.Height)
		&& (lhs.MipLevels == rhs.MipLevels)
		&& (lhs.ArraySize == rhs.ArraySize)
		&& (lhs.Format == rhs.Format)
		&& (lhs.SampleDesc == rhs.SampleDesc)
		&& (lhs.Usage == rhs.Usage)
		&& (lhs.BindFlags == rhs.BindFlags)
		&& (lhs.CPUAccessFlags == rhs.CPUAccessFlags)
		&& (lhs.MiscFlags == rhs.MiscFlags);
}

inline bool operator!=(const Texture2d_desc& lhs, const Texture2d_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Texture2d_desc1 {
	Uint _width{ 0 };
	Uint _height{ 0 };
	Uint _mip_levels{ 0 };
	Uint _array_size{ 0 };
	_HW_3D_DXGI_ Format _format{};
	_HW_3D_DXGI_ Sample_desc _sample_desc{};
	Usage _usage{};
	Uint _bind_flags{ 0 };
	Uint _cpu_access_flags{ 0 };
	Uint _misc_flags{ 0 };
	Texture_layout _texture_layout{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Texture2d_desc1, D3D11_TEXTURE2D_DESC1)
public:
	Texture2d_desc1 & set_bind_flags(Bind_flag flags_) {
		_bind_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Bind_flag get_bind_flags() const noexcept {
		return Bind_flag_bit(_bind_flags);
	}

	Texture2d_desc1& set_cpu_access_flags(Cpu_access_flag flags_) {
		_cpu_access_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Cpu_access_flag get_cpu_access_flags() const noexcept {
		return Cpu_access_flag_bit(_cpu_access_flags);
	}

	Texture2d_desc1& set_misc_flags(Resource_misc_flag flags_) {
		_misc_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Resource_misc_flag get_misc_flags() const noexcept {
		return Resource_misc_flag_bit(_misc_flags);
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_width, Uint, Width);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_height, Uint, Height);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_levels, Uint, MipLevels);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_array_size, Uint, ArraySize);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_format, _HW_3D_DXGI_ Format, Format);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_sample_desc, _HW_3D_DXGI_ Sample_desc, SampleDesc);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_usage, _HW_3D_D3D_ Usage, Usage);
	__declspec(property(get = get_bind_flags, put = set_bind_flags)) Bind_flag BindFlags;
	__declspec(property(get = get_cpu_access_flags, put = set_cpu_access_flags)) Cpu_access_flag CPUAccessFlags;
	__declspec(property(get = get_misc_flags, put = set_misc_flags)) Resource_misc_flag MiscFlags;
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_texture_layout, _HW_3D_D3D_ Texture_layout, TextureLayout);
};
static_assert (sizeof(Texture2d_desc1) == sizeof(D3D11_TEXTURE2D_DESC1));

inline bool operator==(const Texture2d_desc1& lhs, const Texture2d_desc1& rhs) noexcept {
	return (lhs.Width == rhs.Width)
		&& (lhs.Height == rhs.Height)
		&& (lhs.MipLevels == rhs.MipLevels)
		&& (lhs.ArraySize == rhs.ArraySize)
		&& (lhs.Format == rhs.Format)
		&& (lhs.SampleDesc == rhs.SampleDesc)
		&& (lhs.Usage == rhs.Usage)
		&& (lhs.BindFlags == rhs.BindFlags)
		&& (lhs.CPUAccessFlags == rhs.CPUAccessFlags)
		&& (lhs.MiscFlags == rhs.MiscFlags)
		&& (lhs.TextureLayout == rhs.TextureLayout);
}

inline bool operator!=(const Texture2d_desc1& lhs, const Texture2d_desc1& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Texture3d_desc {
	Uint _width{ 0 };
	Uint _height{ 0 };
	Uint _depth{ 0 };
	Uint _mip_levels{ 0 };
	_HW_3D_DXGI_ Format _format{};
	Usage _usage{};
	Uint _bind_flags{ 0 };
	Uint _cpu_access_flags{ 0 };
	Uint _misc_flags{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Texture3d_desc, D3D11_TEXTURE3D_DESC)
public:
	Texture3d_desc & set_bind_flags(Bind_flag flags_) {
		_bind_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Bind_flag get_bind_flags() const noexcept {
		return Bind_flag_bit(_bind_flags);
	}

	Texture3d_desc& set_cpu_access_flags(Cpu_access_flag flags_) {
		_cpu_access_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Cpu_access_flag get_cpu_access_flags() const noexcept {
		return Cpu_access_flag_bit(_cpu_access_flags);
	}

	Texture3d_desc& set_misc_flags(Resource_misc_flag flags_) {
		_misc_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Resource_misc_flag get_misc_flags() const noexcept {
		return Resource_misc_flag_bit(_misc_flags);
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_width, Uint, Width);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_height, Uint, Height);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_depth, Uint, Depth);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_levels, Uint, MipLevels);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_format, _HW_3D_DXGI_ Format, Format);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_usage, _HW_3D_D3D_ Usage, Usage);
	__declspec(property(get = get_bind_flags, put = set_bind_flags)) Bind_flag BindFlags;
	__declspec(property(get = get_cpu_access_flags, put = set_cpu_access_flags)) Cpu_access_flag CPUAccessFlags;
	__declspec(property(get = get_misc_flags, put = set_misc_flags)) Resource_misc_flag MiscFlags;
};
static_assert (sizeof(Texture3d_desc) == sizeof(D3D11_TEXTURE3D_DESC));

inline bool operator==(const Texture3d_desc& lhs, const Texture3d_desc& rhs) noexcept {
	return (lhs.Width == rhs.Width)
		&& (lhs.Height == rhs.Height)
		&& (lhs.Depth == rhs.Depth)
		&& (lhs.MipLevels == rhs.MipLevels)
		&& (lhs.Format == rhs.Format)
		&& (lhs.Usage == rhs.Usage)
		&& (lhs.BindFlags == rhs.BindFlags)
		&& (lhs.CPUAccessFlags == rhs.CPUAccessFlags)
		&& (lhs.MiscFlags == rhs.MiscFlags);
}

inline bool operator!=(const Texture3d_desc& lhs, const Texture3d_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Texture3d_desc1 {
	Uint _width{ 0 };
	Uint _height{ 0 };
	Uint _depth{ 0 };
	Uint _mip_levels{ 0 };
	_HW_3D_DXGI_ Format _format{};
	Usage _usage{};
	Uint _bind_flags{ 0 };
	Uint _cpu_access_flags{ 0 };
	Uint _misc_flags{ 0 };
	Texture_layout _texture_layout{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Texture3d_desc1, D3D11_TEXTURE3D_DESC1)
public:
	Texture3d_desc1 & set_bind_flags(Bind_flag flags_) {
		_bind_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Bind_flag get_bind_flags() const noexcept {
		return Bind_flag_bit(_bind_flags);
	}

	Texture3d_desc1& set_cpu_access_flags(Cpu_access_flag flags_) {
		_cpu_access_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Cpu_access_flag get_cpu_access_flags() const noexcept {
		return Cpu_access_flag_bit(_cpu_access_flags);
	}

	Texture3d_desc1& set_misc_flags(Resource_misc_flag flags_) {
		_misc_flags = decltype(flags_)::mask_type(flags_);
		return (*this);
	}

	Resource_misc_flag get_misc_flags() const noexcept {
		return Resource_misc_flag_bit(_misc_flags);
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_width, Uint, Width);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_height, Uint, Height);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_depth, Uint, Depth);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_mip_levels, Uint, MipLevels);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_format, _HW_3D_DXGI_ Format, Format);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_usage, _HW_3D_D3D_ Usage, Usage);
	__declspec(property(get = get_bind_flags, put = set_bind_flags)) Bind_flag BindFlags;
	__declspec(property(get = get_cpu_access_flags, put = set_cpu_access_flags)) Cpu_access_flag CPUAccessFlags;
	__declspec(property(get = get_misc_flags, put = set_misc_flags)) Resource_misc_flag MiscFlags;
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_texture_layout, _HW_3D_D3D_ Texture_layout, TextureLayout);
};
static_assert (sizeof(Texture3d_desc1) == sizeof(D3D11_TEXTURE3D_DESC1));

inline bool operator==(const Texture3d_desc1& lhs, const Texture3d_desc1& rhs) noexcept {
	return (lhs.Width == rhs.Width)
		&& (lhs.Height == rhs.Height)
		&& (lhs.Depth == rhs.Depth)
		&& (lhs.MipLevels == rhs.MipLevels)
		&& (lhs.Format == rhs.Format)
		&& (lhs.Usage == rhs.Usage)
		&& (lhs.BindFlags == rhs.BindFlags)
		&& (lhs.CPUAccessFlags == rhs.CPUAccessFlags)
		&& (lhs.MiscFlags == rhs.MiscFlags)
		&& (lhs.TextureLayout == rhs.TextureLayout);
}

inline bool operator!=(const Texture3d_desc1& lhs, const Texture3d_desc1& rhs) {
	return !operator==(lhs, rhs);
}

//
//
class Unordered_access_view_desc {
	_HW_3D_DXGI_ Format _format;
	Uav_dimension _view_dimension;
	union {
		Buffer_uav _buffer;
		Tex1d_uav _texture_1d;
		Tex1d_array_uav _texture_1d_array;
		Tex2d_uav _texture_2d;
		Tex2d_array_uav _texture_2d_array;
		Tex3d_uav _texture_3d;
	};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Unordered_access_view_desc, D3D11_UNORDERED_ACCESS_VIEW_DESC)
public:
	Unordered_access_view_desc & set_buffer(const Buffer_uav& buf) {
		_view_dimension = Uav_dimension::buffer;
		_buffer = buf;
		return (*this);
	}

	Buffer_uav get_buffer() const noexcept {
		assert(_view_dimension == Uav_dimension::buffer);
		return _buffer;
	}

	Unordered_access_view_desc& set_texture_1d(const Tex1d_uav& tex) {
		_view_dimension = Uav_dimension::texture1d;
		_texture_1d = tex;
		return (*this);
	}

	Tex1d_uav get_texture_1d() const noexcept {
		assert(_view_dimension == Uav_dimension::texture1d);
		return _texture_1d;
	}

	Unordered_access_view_desc& set_texture_1d_array(const Tex1d_array_uav& tex) {
		_view_dimension = Uav_dimension::texture1darray;
		_texture_1d_array = tex;
		return (*this);
	}

	Tex1d_array_uav get_texture_1d_array() const noexcept {
		assert(_view_dimension == Uav_dimension::texture1darray);
		return _texture_1d_array;
	}

	Unordered_access_view_desc& set_texture_2d(const Tex2d_uav& tex) {
		_view_dimension = Uav_dimension::texture2d;
		_texture_2d = tex;
		return (*this);
	}

	Tex2d_uav get_texture_2d() const noexcept {
		assert(_view_dimension == Uav_dimension::texture2d);
		return _texture_2d;
	}

	Unordered_access_view_desc& set_texture_2d_array(const Tex2d_array_uav& tex) {
		_view_dimension = Uav_dimension::texture2darray;
		_texture_2d_array = tex;
		return (*this);
	}

	Tex2d_array_uav get_texture_2d_array() const noexcept {
		assert(_view_dimension == Uav_dimension::texture2darray);
		return _texture_2d_array;
	}

	Unordered_access_view_desc& set_texture_3d(const Tex3d_uav& tex) {
		_view_dimension = Uav_dimension::texture3d;
		_texture_3d = tex;
		return (*this);
	}

	Tex3d_uav get_texture_3d() const noexcept {
		assert(_view_dimension == Uav_dimension::texture3d);
		return _texture_3d;
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_format, _HW_3D_DXGI_ Format, Format);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_view_dimension, Uav_dimension, ViewDimension);
	__declspec(property(get = get_buffer, put = set_buffer)) Buffer_uav Buffer;
	__declspec(property(get = get_texture_1d, put = set_texture_1d)) Tex1d_uav Texture1D;
	__declspec(property(get = get_texture_1d_array, put = set_texture_1d_array)) Tex1d_array_uav Texture1DArray;
	__declspec(property(get = get_texture_2d, put = set_texture_2d)) Tex2d_uav Texture2D;
	__declspec(property(get = get_texture_2d_array, put = set_texture_2d_array)) Tex2d_array_uav Texture2DArray;
	__declspec(property(get = get_texture_3d, put = set_texture_3d)) Tex3d_uav Texture3D;
};
static_assert(sizeof(Unordered_access_view_desc) == sizeof(D3D11_UNORDERED_ACCESS_VIEW_DESC));

inline bool operator==(const Unordered_access_view_desc& lhs, const Unordered_access_view_desc& rhs) noexcept {
	if (lhs.Format != rhs.Format || lhs.ViewDimension != rhs.ViewDimension)
		return false;

	switch (lhs.ViewDimension) {
	case Uav_dimension::buffer:
		return lhs.Buffer == rhs.Buffer;
	case Uav_dimension::texture1d:
		return lhs.Texture1D == rhs.Texture1D;
	case Uav_dimension::texture1darray:
		return lhs.Texture1DArray == rhs.Texture1DArray;
	case Uav_dimension::texture2d:
		return lhs.Texture2D == rhs.Texture2D;
	case Uav_dimension::texture2darray:
		return lhs.Texture2DArray == rhs.Texture2DArray;
	case Uav_dimension::texture3d:
		return lhs.Texture3D == rhs.Texture3D;
	default:
		return false;
	}
}

inline bool operator!=(const Unordered_access_view_desc& lhs, const Unordered_access_view_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Unordered_access_view_desc1 {
	_HW_3D_DXGI_ Format _format;
	Uav_dimension _view_dimension;
	union {
		Buffer_uav _buffer;
		Tex1d_uav _texture_1d;
		Tex1d_array_uav _texture_1d_array;
		Tex2d_uav1 _texture_2d;
		Tex2d_array_uav1 _texture_2d_array;
		Tex3d_uav _texture_3d;
	};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Unordered_access_view_desc1, D3D11_UNORDERED_ACCESS_VIEW_DESC1)
public:
	Unordered_access_view_desc1 & set_buffer(const Buffer_uav& buf) {
		_view_dimension = Uav_dimension::buffer;
		_buffer = buf;
		return (*this);
	}

	Buffer_uav get_buffer() const noexcept {
		assert(_view_dimension == Uav_dimension::buffer);
		return _buffer;
	}

	Unordered_access_view_desc1& set_texture_1d(const Tex1d_uav& tex) {
		_view_dimension = Uav_dimension::texture1d;
		_texture_1d = tex;
		return (*this);
	}

	Tex1d_uav get_texture_1d() const noexcept {
		assert(_view_dimension == Uav_dimension::texture1d);
		return _texture_1d;
	}

	Unordered_access_view_desc1& set_texture_1d_array(const Tex1d_array_uav& tex) {
		_view_dimension = Uav_dimension::texture1darray;
		_texture_1d_array = tex;
		return (*this);
	}

	Tex1d_array_uav get_texture_1d_array() const noexcept {
		assert(_view_dimension == Uav_dimension::texture1darray);
		return _texture_1d_array;
	}

	Unordered_access_view_desc1& set_texture_2d(const Tex2d_uav1& tex) {
		_view_dimension = Uav_dimension::texture2d;
		_texture_2d = tex;
		return (*this);
	}

	Tex2d_uav1 get_texture_2d() const noexcept {
		assert(_view_dimension == Uav_dimension::texture2d);
		return _texture_2d;
	}

	Unordered_access_view_desc1& set_texture_2d_array(const Tex2d_array_uav1& tex) {
		_view_dimension = Uav_dimension::texture2darray;
		_texture_2d_array = tex;
		return (*this);
	}

	Tex2d_array_uav1 get_texture_2d_array() const noexcept {
		assert(_view_dimension == Uav_dimension::texture2darray);
		return _texture_2d_array;
	}

	Unordered_access_view_desc1& set_texture_3d(const Tex3d_uav& tex) {
		_view_dimension = Uav_dimension::texture3d;
		_texture_3d = tex;
		return (*this);
	}

	Tex3d_uav get_texture_3d() const noexcept {
		assert(_view_dimension == Uav_dimension::texture3d);
		return _texture_3d;
	}

	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_format, _HW_3D_DXGI_ Format, Format);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_view_dimension, Uav_dimension, ViewDimension);
	__declspec(property(get = get_buffer, put = set_buffer)) Buffer_uav Buffer;
	__declspec(property(get = get_texture_1d, put = set_texture_1d)) Tex1d_uav Texture1D;
	__declspec(property(get = get_texture_1d_array, put = set_texture_1d_array)) Tex1d_array_uav Texture1DArray;
	__declspec(property(get = get_texture_2d, put = set_texture_2d)) Tex2d_uav1 Texture2D;
	__declspec(property(get = get_texture_2d_array, put = set_texture_2d_array)) Tex2d_array_uav1 Texture2DArray;
	__declspec(property(get = get_texture_3d, put = set_texture_3d)) Tex3d_uav Texture3D;
};
static_assert(sizeof(Unordered_access_view_desc1) == sizeof(D3D11_UNORDERED_ACCESS_VIEW_DESC1));

inline bool operator==(const Unordered_access_view_desc1& lhs, const Unordered_access_view_desc1& rhs) noexcept {
	if (lhs.Format != rhs.Format || lhs.ViewDimension != rhs.ViewDimension)
		return false;

	switch (lhs.ViewDimension) {
	case Uav_dimension::buffer:
		return lhs.Buffer == rhs.Buffer;
	case Uav_dimension::texture1d:
		return lhs.Texture1D == rhs.Texture1D;
	case Uav_dimension::texture1darray:
		return lhs.Texture1DArray == rhs.Texture1DArray;
	case Uav_dimension::texture2d:
		return lhs.Texture2D == rhs.Texture2D;
	case Uav_dimension::texture2darray:
		return lhs.Texture2DArray == rhs.Texture2DArray;
	case Uav_dimension::texture3d:
		return lhs.Texture3D == rhs.Texture3D;
	default:
		return false;
	}
}

inline bool operator!=(const Unordered_access_view_desc1& lhs, const Unordered_access_view_desc1& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Class_instance_desc {
	Uint _instance_id{ 0 };
	Uint _instance_index{ 0 };
	Uint _type_id{ 0 };
	Uint _constant_buffer{ 0 };
	Uint _base_constant_buffer_offset{ 0 };
	Uint _base_texture{ 127 };
	Uint _base_sampler{ 15 };
	Bool _created{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Class_instance_desc, D3D11_CLASS_INSTANCE_DESC)
public:

	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_instance_id, Uint, InstanceId);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_instance_index, Uint, InstanceIndex);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_type_id, Uint, TypeId);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_constant_buffer, Uint, ConstantBuffer);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_base_constant_buffer_offset, Uint, BaseConstantBufferOffset);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_base_texture, Uint, BaseTexture);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_base_sampler, Uint, BaseSampler);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_created, Bool, Created);
};
static_assert(sizeof(Class_instance_desc) == sizeof(D3D11_CLASS_INSTANCE_DESC));

inline bool operator==(const Class_instance_desc& lhs, const Class_instance_desc& rhs) noexcept {
	return (lhs.InstanceId == rhs.InstanceId)
		&& (lhs.InstanceIndex == rhs.InstanceIndex)
		&& (lhs.TypeId == rhs.TypeId)
		&& (lhs.ConstantBuffer == rhs.ConstantBuffer)
		&& (lhs.BaseConstantBufferOffset == rhs.BaseConstantBufferOffset)
		&& (lhs.BaseTexture == rhs.BaseTexture)
		&& (lhs.BaseSampler == rhs.BaseSampler)
		&& (lhs.Created == rhs.Created);
}

inline bool operator!=(const Class_instance_desc& lhs, const Class_instance_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Compute_shader_trace_desc {
	Uint64 _invocation{ 0 };
	_HW_3D_STD_ array<Uint, 3> _thread_id_in_group{ 0, 0, 0 };
	_HW_3D_STD_ array<Uint, 3> _thread_group_id{ 0, 0, 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Compute_shader_trace_desc, D3D11_COMPUTE_SHADER_TRACE_DESC)
public:
	_HW_3D_STD_ array<Uint, 3> get_thread_id_in_group() const noexcept {
		return _thread_id_in_group;
	}

	_HW_3D_STD_ array<Uint, 3> get_thread_group_id() const noexcept {
		return _thread_group_id;
	}

	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_invocation, Uint64, Invocation);
	__declspec(property(get = get_thread_id_in_group)) _HW_3D_STD_ array<Uint, 3> ThreadIDInGroup;
	__declspec(property(get = get_thread_group_id)) _HW_3D_STD_ array<Uint, 3> ThreadGroupID;
};
static_assert(sizeof(Compute_shader_trace_desc) == sizeof(D3D11_COMPUTE_SHADER_TRACE_DESC));

inline bool operator==(const Compute_shader_trace_desc& lhs, const Compute_shader_trace_desc& rhs) noexcept {
	return (lhs.Invocation == rhs.Invocation)
		&& (lhs.ThreadIDInGroup == rhs.ThreadIDInGroup)
		&& (lhs.ThreadGroupID == rhs.ThreadGroupID);
}

inline bool operator!=(const Compute_shader_trace_desc& lhs, const Compute_shader_trace_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Domain_shader_trace_desc {
	Uint64 _invocation{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Domain_shader_trace_desc, D3D11_DOMAIN_SHADER_TRACE_DESC)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_invocation, Uint64, Invocation);
};
static_assert(sizeof(Domain_shader_trace_desc) == sizeof(D3D11_DOMAIN_SHADER_TRACE_DESC));

inline bool operator==(const Domain_shader_trace_desc& lhs, const Domain_shader_trace_desc& rhs) noexcept {
	return (lhs.Invocation == rhs.Invocation);
}

inline bool operator!=(const Domain_shader_trace_desc& lhs, const Domain_shader_trace_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Function_desc {
	Uint _version{ 0 };
	Pcstr _creator{ nullptr };
	Uint _flags{ 0 };
	Uint _constant_buffers{ 0 };
	Uint _bound_resources{ 0 };
	Uint _instruction_count{ 0 };
	Uint _temp_register_count{ 0 };
	Uint _temp_array_count{ 0 };
	Uint _def_count{ 0 };
	Uint _dcl_count{ 0 };
	Uint _texture_normal_instructions{ 0 };
	Uint _texture_load_instructions{ 0 };
	Uint _texture_comp_instructions{ 0 };
	Uint _texture_bias_instructions{ 0 };
	Uint _texture_gradient_instructions{ 0 };
	Uint _float_instruction_count{ 0 };
	Uint _int_instruction_count{ 0 };
	Uint _uint_instruction_count{ 0 };
	Uint _static_flow_control_count{ 0 };
	Uint _dynamic_flow_control_count{ 0 };
	Uint _macro_instruction_count{ 0 };
	Uint _array_instruction_count{ 0 };
	Uint _mov_instruction_count{ 0 };
	Uint _movc_instruction_count{ 0 };
	Uint _conversion_instruction_count{ 0 };
	Uint _bitwise_instruction_count{ 0 };
	Feature_level _min_feature_level{};
	Uint64 _required_feature_flags{ 0 };
	Pcstr _name{ nullptr };
	Int _function_parameter_count{ 0 };
	Bool _has_return{ False };
	Bool _has_10level9_vertex_shader{ False };
	Bool _has_10level9_pixel_shader{ False };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Function_desc, D3D11_FUNCTION_DESC)
public:
	Compile_constant get_flags() const noexcept {
		return Compile_constant_bit(_flags);
	}

	Shader_require get_required_feature_flags() const noexcept {
		return Shader_require_bit(_required_feature_flags);
	}

	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_version, Uint, Version);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_creator, Pcstr, Creator);
	__declspec(property(get = get_flags)) Compile_constant Flags;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_constant_buffers, Uint, ConstantBuffers);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_bound_resources, Uint, BoundResources);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_instruction_count, Uint, InstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_temp_register_count, Uint, TempRegisterCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_temp_array_count, Uint, TempArrayCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_def_count, Uint, DefCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_dcl_count, Uint, DclCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_texture_normal_instructions, Uint, TextureNormalInstructions);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_texture_load_instructions, Uint, TextureLoadInstructions);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_texture_comp_instructions, Uint, TextureCompInstructions);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_texture_bias_instructions, Uint, TextureBiasInstructions);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_texture_gradient_instructions, Uint, TextureGradientInstructions);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_float_instruction_count, Uint, FloatInstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_int_instruction_count, Uint, IntInstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_uint_instruction_count, Uint, UintInstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_static_flow_control_count, Uint, StaticFlowControlCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_dynamic_flow_control_count, Uint, DynamicFlowControlCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_macro_instruction_count, Uint, MacroInstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_array_instruction_count, Uint, ArrayInstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_mov_instruction_count, Uint, MovInstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_movc_instruction_count, Uint, MovcInstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_conversion_instruction_count, Uint, ConversionInstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_bitwise_instruction_count, Uint, BitwiseInstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_min_feature_level, Feature_level, MinFeatureLevel);
	__declspec(property(get = get_required_feature_flags)) Shader_require RequiredFeatureFlags;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_name, Pcstr, Name);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_function_parameter_count, Int, FunctionParameterCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_has_return, Bool, HasReturn);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_has_10level9_vertex_shader, Bool, Has10Level9VertexShader);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_has_10level9_pixel_shader, Bool, Has10Level9PixelShader);
};
static_assert(sizeof(Function_desc) == sizeof(D3D11_FUNCTION_DESC));

inline bool operator==(const Function_desc& lhs, const Function_desc& rhs) noexcept {
	return (lhs.Version == rhs.Version)
		&& (strcmp(lhs.Creator, rhs.Creator) == 0)
		&& (lhs.Flags == rhs.Flags)
		&& (lhs.ConstantBuffers == rhs.ConstantBuffers)
		&& (lhs.BoundResources == rhs.BoundResources)
		&& (lhs.InstructionCount == rhs.InstructionCount)
		&& (lhs.TempRegisterCount == rhs.TempRegisterCount)
		&& (lhs.TempArrayCount == rhs.TempArrayCount)
		&& (lhs.DefCount == rhs.DefCount)
		&& (lhs.DclCount == rhs.DclCount)
		&& (lhs.TextureNormalInstructions == rhs.TextureNormalInstructions)
		&& (lhs.TextureLoadInstructions == rhs.TextureLoadInstructions)
		&& (lhs.TextureCompInstructions == rhs.TextureCompInstructions)
		&& (lhs.TextureBiasInstructions == rhs.TextureBiasInstructions)
		&& (lhs.TextureGradientInstructions == rhs.TextureGradientInstructions)
		&& (lhs.FloatInstructionCount == rhs.FloatInstructionCount)
		&& (lhs.IntInstructionCount == rhs.IntInstructionCount)
		&& (lhs.UintInstructionCount == rhs.UintInstructionCount)
		&& (lhs.StaticFlowControlCount == rhs.StaticFlowControlCount)
		&& (lhs.DynamicFlowControlCount == rhs.DynamicFlowControlCount)
		&& (lhs.MacroInstructionCount == rhs.MacroInstructionCount)
		&& (lhs.ArrayInstructionCount == rhs.ArrayInstructionCount)
		&& (lhs.MovInstructionCount == rhs.MovInstructionCount)
		&& (lhs.MovcInstructionCount == rhs.MovcInstructionCount)
		&& (lhs.ConversionInstructionCount == rhs.ConversionInstructionCount)
		&& (lhs.BitwiseInstructionCount == rhs.BitwiseInstructionCount)
		&& (lhs.MinFeatureLevel == rhs.MinFeatureLevel)
		&& (lhs.RequiredFeatureFlags == rhs.RequiredFeatureFlags)
		&& (strcmp(lhs.Name, rhs.Name) == 0)
		&& (lhs.FunctionParameterCount == rhs.FunctionParameterCount)
		&& (lhs.HasReturn == rhs.HasReturn)
		&& (lhs.Has10Level9VertexShader == rhs.Has10Level9VertexShader)
		&& (lhs.Has10Level9PixelShader == rhs.Has10Level9PixelShader);
}

inline bool operator!=(const Function_desc& lhs, const Function_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Geometry_shader_trace_desc {
	Uint64 _invocation{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Geometry_shader_trace_desc, D3D11_GEOMETRY_SHADER_TRACE_DESC)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_invocation, Uint64, Invocation);
};
static_assert(sizeof(Geometry_shader_trace_desc) == sizeof(D3D11_GEOMETRY_SHADER_TRACE_DESC));

inline bool operator==(const Geometry_shader_trace_desc& lhs, const Geometry_shader_trace_desc& rhs) noexcept {
	return (lhs.Invocation == rhs.Invocation);
}

inline bool operator!=(const Geometry_shader_trace_desc& lhs, const Geometry_shader_trace_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Hull_shader_trace_desc {
	Uint64 _invocation{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Hull_shader_trace_desc, D3D11_HULL_SHADER_TRACE_DESC)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_invocation, Uint64, Invocation);
};
static_assert(sizeof(Hull_shader_trace_desc) == sizeof(D3D11_HULL_SHADER_TRACE_DESC));

inline bool operator==(const Hull_shader_trace_desc& lhs, const Hull_shader_trace_desc& rhs) noexcept {
	return (lhs.Invocation == rhs.Invocation);
}

inline bool operator!=(const Hull_shader_trace_desc& lhs, const Hull_shader_trace_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Library_desc {
	Pcstr _creator{ nullptr };
	Uint _flags{ 0 };
	Uint _function_count{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Library_desc, D3D11_LIBRARY_DESC)
public:
	Compile_constant get_flags() const noexcept {
		return Compile_constant_bit(_flags);
	}

	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_creator, Pcstr, Creator);
	__declspec(property(get = get_flags)) Compile_constant  Flags;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_function_count, Uint, FunctionCount);
};
static_assert(sizeof(Library_desc) == sizeof(D3D11_LIBRARY_DESC));

inline bool operator==(const Library_desc& lhs, const Library_desc& rhs) noexcept {
	return (lhs.Flags == rhs.Flags)
		&& (lhs.FunctionCount == rhs.FunctionCount)
		&& (strcmp(lhs.Creator, rhs.Creator) == 0);
}

inline bool operator!=(const Library_desc& lhs, const Library_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Parameter_desc {
	Pcstr _name{ nullptr };
	Pcstr _semantic_name{ nullptr };
	Shader_variable_type _type{};
	Shader_variable_class _class{};
	Uint _rows{ 0 };
	Uint _columns{ 0 };
	Interpolation_mode _interpolation_mode{};
	Parameter_flag _flags{};
	Uint _first_in_register{ 0 };
	Uint _first_in_component{ 0 };
	Uint _first_out_register{ 0 };
	Uint _first_out_component{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Parameter_desc, D3D11_PARAMETER_DESC)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_name, Pcstr, Name);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_semantic_name, Pcstr, SemanticName);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_type, Shader_variable_type, Type);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_class, Shader_variable_class, Class);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_rows, Uint, Rows);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_columns, Uint, Columns);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_interpolation_mode, Interpolation_mode, InterpolationMode);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_flags, Parameter_flag, Flags);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_first_in_register, Uint, FirstInRegister);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_first_in_component, Uint, FirstInComponent);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_first_out_register, Uint, FirstOutRegister);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_first_out_component, Uint, FirstOutComponent);
};
static_assert(sizeof(Parameter_desc) == sizeof(D3D11_PARAMETER_DESC));

inline bool operator==(const Parameter_desc& lhs, const Parameter_desc& rhs) noexcept {
	return (lhs.Type == rhs.Type)
		&& (lhs.Class == rhs.Class)
		&& (lhs.Rows == rhs.Rows)
		&& (lhs.Columns == rhs.Columns)
		&& (lhs.InterpolationMode == rhs.InterpolationMode)
		&& (lhs.Flags == rhs.Flags)
		&& (lhs.FirstInRegister == rhs.FirstInRegister)
		&& (lhs.FirstInComponent == rhs.FirstInComponent)
		&& (lhs.FirstOutRegister == rhs.FirstOutRegister)
		&& (lhs.FirstOutComponent == rhs.FirstOutComponent)
		&& (strcmp(lhs.Name, rhs.Name) == 0)
		&& (strcmp(lhs.SemanticName, rhs.SemanticName) == 0);
}

inline bool operator!=(const Parameter_desc& lhs, const Parameter_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Pixel_shader_trace_desc {
	Uint64 _invocation{ 0 };
	Int _x{ 0 };
	Int _y{ 0 };
	Uint64 _sample_mask{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Pixel_shader_trace_desc, D3D11_PIXEL_SHADER_TRACE_DESC)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_invocation, Uint64, Invocation);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_x, Int, X);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_y, Int, Y);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_sample_mask, Uint64, SampleMask);
};
static_assert(sizeof(Pixel_shader_trace_desc) == sizeof(D3D11_PIXEL_SHADER_TRACE_DESC));

inline bool operator==(const Pixel_shader_trace_desc& lhs, const Pixel_shader_trace_desc& rhs) noexcept {
	return (lhs.Invocation == rhs.Invocation)
		&& (lhs.X == rhs.X)
		&& (lhs.Y == rhs.Y)
		&& (lhs.SampleMask == rhs.SampleMask);
}

inline bool operator!=(const Pixel_shader_trace_desc& lhs, const Pixel_shader_trace_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Shader_buffer_desc {
	Pcstr _name{ nullptr };
	Cbuffer_type _type{};
	Uint _variables{ 0 };
	Uint _size{ 0 };
	Uint _flags{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Shader_buffer_desc, D3D11_SHADER_BUFFER_DESC)
public:
	Shader_cbuffer_flag get_flags() const noexcept {
		return Shader_cbuffer_flag_bit(_flags);
	}

	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_name, Pcstr, Name);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_type, Cbuffer_type, Type);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_variables, Uint, Variables);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_size, Uint, Size);
	__declspec(property(get = get_flags)) Shader_cbuffer_flag uFlags;
};
static_assert(sizeof(Shader_buffer_desc) == sizeof(D3D11_SHADER_BUFFER_DESC));

inline bool operator==(const Shader_buffer_desc& lhs, const Shader_buffer_desc& rhs) noexcept {
	return (lhs.Type == rhs.Type)
		&& (lhs.Variables == rhs.Variables)
		&& (lhs.Size == rhs.Size)
		&& (lhs.uFlags == rhs.uFlags)
		&& (strcmp(lhs.Name, rhs.Name) == 0);
}

inline bool operator!=(const Shader_buffer_desc& lhs, const Shader_buffer_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Shader_desc {
	Uint _version{ 0 };
	Pcstr _creator{ nullptr };
	Uint _flags{ 0 };
	Uint _constant_buffers{ 0 };
	Uint _bound_resources{ 0 };
	Uint _input_parameters{ 0 };
	Uint _output_parameters{ 0 };
	Uint _instruction_count{ 0 };
	Uint _temp_register_count{ 0 };
	Uint _temp_array_count{ 0 };
	Uint _def_count{ 0 };
	Uint _dcl_count{ 0 };
	Uint _texture_normal_instructions{ 0 };
	Uint _texture_load_instructions{ 0 };
	Uint _texture_comp_instructions{ 0 };
	Uint _texture_bias_instructions{ 0 };
	Uint _texture_gradient_instructions{ 0 };
	Uint _float_instruction_count{ 0 };
	Uint _int_instruction_count{ 0 };
	Uint _uint_instruction_count{ 0 };
	Uint _static_flow_control_count{ 0 };
	Uint _dynamic_flow_control_count{ 0 };
	Uint _macro_instruction_count{ 0 };
	Uint _array_instruction_count{ 0 };
	Uint _cut_instruction_count{ 0 };
	Uint _emit_instruction_count{ 0 };
	Primitive_topology _gs_output_topology{};
	Uint _gs_max_output_vertex_count{ 0 };
	Primitive _input_primitive{ 0 };
	Uint _patch_constant_parameters{ 0 };
	Uint _gs_instance_count{ 0 };
	Uint _control_points{ 0 };
	Tessellator_output_primitive _hs_output_primitive{};
	Tessellator_partitioning _hs_partitioning{};
	Tessellator_domain _tessellator_domain{};
	Uint _barrier_instructions{ 0 };
	Uint _interlocked_instructions{ 0 };
	Uint _texture_store_instructions{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Shader_desc, D3D11_SHADER_DESC)
public:
	Compile_constant get_flags() const noexcept {
		return Compile_constant_bit(_flags);
	}

	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_version, Uint, Version);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_creator, Pcstr, Creator);
	__declspec(property(get = get_flags)) Compile_constant Flags;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_constant_buffers, Uint, ConstantBuffers);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_bound_resources, Uint, BoundResources);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_input_parameters, Uint, InputParameters);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_output_parameters, Uint, OutputParameters);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_instruction_count, Uint, InstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_temp_register_count, Uint, TempRegisterCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_temp_array_count, Uint, TempArrayCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_def_count, Uint, DefCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_dcl_count, Uint, DclCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_texture_normal_instructions, Uint, TextureNormalInstructions);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_texture_load_instructions, Uint, TextureLoadInstructions);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_texture_comp_instructions, Uint, TextureCompInstructions);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_texture_bias_instructions, Uint, TextureBiasInstructions);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_texture_gradient_instructions, Uint, TextureGradientInstructions);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_float_instruction_count, Uint, FloatInstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_int_instruction_count, Uint, IntInstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_uint_instruction_count, Uint, UintInstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_static_flow_control_count, Uint, StaticFlowControlCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_dynamic_flow_control_count, Uint, DynamicFlowControlCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_macro_instruction_count, Uint, MacroInstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_array_instruction_count, Uint, ArrayInstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_cut_instruction_count, Uint, CutInstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_emit_instruction_count, Uint, EmitInstructionCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_gs_output_topology, Primitive_topology, GSOutputTopology);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_gs_max_output_vertex_count, Uint, GSMaxOutputVertexCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_input_primitive, Primitive, InputPrimitive);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_patch_constant_parameters, Uint, PatchConstantParameters);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_gs_instance_count, Uint, cGSInstanceCount);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_control_points, Uint, cControlPoints);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_hs_output_primitive, Tessellator_output_primitive, HSOutputPrimitive);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_hs_partitioning, Tessellator_partitioning, HSPartitioning);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_tessellator_domain, _HW_3D_D3D_ Tessellator_domain, TessellatorDomain);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_barrier_instructions, Uint, cBarrierInstructions);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_interlocked_instructions, Uint, cInterlockedInstructions);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_texture_store_instructions, Uint, cTextureStoreInstructions);
};
static_assert(sizeof(Shader_desc) == sizeof(D3D11_SHADER_DESC));

inline bool operator==(const Shader_desc& lhs, const Shader_desc& rhs) noexcept {
	return (lhs.Version == rhs.Version)
		&& (lhs.Flags == rhs.Flags)
		&& (lhs.ConstantBuffers == rhs.ConstantBuffers)
		&& (lhs.BoundResources == rhs.BoundResources)
		&& (lhs.InputParameters == rhs.InputParameters)
		&& (lhs.OutputParameters == rhs.OutputParameters)
		&& (lhs.InstructionCount == rhs.InstructionCount)
		&& (lhs.TempRegisterCount == rhs.TempRegisterCount)
		&& (lhs.TempArrayCount == rhs.TempArrayCount)
		&& (lhs.DefCount == rhs.DefCount)
		&& (lhs.DclCount == rhs.DclCount)
		&& (lhs.TextureNormalInstructions == rhs.TextureNormalInstructions)
		&& (lhs.TextureCompInstructions == rhs.TextureCompInstructions)
		&& (lhs.TextureBiasInstructions == rhs.TextureBiasInstructions)
		&& (lhs.TextureGradientInstructions == rhs.TextureGradientInstructions)
		&& (lhs.FloatInstructionCount == rhs.FloatInstructionCount)
		&& (lhs.IntInstructionCount == rhs.IntInstructionCount)
		&& (lhs.UintInstructionCount == rhs.UintInstructionCount)
		&& (lhs.StaticFlowControlCount == rhs.StaticFlowControlCount)
		&& (lhs.MacroInstructionCount == rhs.MacroInstructionCount)
		&& (lhs.ArrayInstructionCount == rhs.ArrayInstructionCount)
		&& (lhs.CutInstructionCount == rhs.CutInstructionCount)
		&& (lhs.EmitInstructionCount == rhs.EmitInstructionCount)
		&& (lhs.GSOutputTopology == rhs.GSOutputTopology)
		&& (lhs.GSMaxOutputVertexCount == rhs.GSMaxOutputVertexCount)
		&& (lhs.InputPrimitive == rhs.InputPrimitive)
		&& (lhs.PatchConstantParameters == rhs.PatchConstantParameters)
		&& (lhs.cGSInstanceCount == rhs.cGSInstanceCount)
		&& (lhs.cControlPoints == rhs.cControlPoints)
		&& (lhs.HSOutputPrimitive == rhs.HSOutputPrimitive)
		&& (lhs.HSPartitioning == rhs.HSPartitioning)
		&& (lhs.TessellatorDomain == rhs.TessellatorDomain)
		&& (lhs.cBarrierInstructions == rhs.cBarrierInstructions)
		&& (lhs.cInterlockedInstructions == rhs.cInterlockedInstructions)
		&& (lhs.cTextureStoreInstructions == rhs.cTextureStoreInstructions)
		&& (strcmp(lhs.Creator, rhs.Creator) == 0);
}

inline bool operator!=(const Shader_desc& lhs, const Shader_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Shader_input_bind_desc {
	Pcstr _name{ nullptr };
	Shader_input_type _type{};
	Uint _bind_point{ 0 };
	Uint _bind_count{ 0 };
	Uint _flags{ 0 };
	Resource_return_type _return_type{};
	Srv_dimension _dimension{};
	Uint _num_samples{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Shader_input_bind_desc, D3D11_SHADER_INPUT_BIND_DESC)
public:
	Shader_input_flag get_flags() const noexcept {
		return Shader_input_flag_bit(_flags);
	}

	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_name, Pcstr, Name);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_type, Shader_input_type, Type);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_bind_point, Uint, BindPoint);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_bind_count, Uint, BindCount);
	__declspec(property(get = get_flags)) Shader_input_flag uFlags;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_return_type, Resource_return_type, ReturnType);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_dimension, Srv_dimension, Dimension);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_num_samples, Uint, NumSamples);
};
static_assert(sizeof(Shader_input_bind_desc) == sizeof(D3D11_SHADER_INPUT_BIND_DESC));

inline bool operator==(const Shader_input_bind_desc& lhs, const Shader_input_bind_desc& rhs) noexcept {
	return (lhs.Type == rhs.Type)
		&& (lhs.BindCount == rhs.BindCount)
		&& (lhs.BindPoint == rhs.BindPoint)
		&& (lhs.uFlags == rhs.uFlags)
		&& (lhs.ReturnType == rhs.ReturnType)
		&& (lhs.Dimension == rhs.Dimension)
		&& (lhs.NumSamples == rhs.NumSamples)
		&& (strcmp(lhs.Name, rhs.Name) == 0);
}

inline bool operator!=(const Shader_input_bind_desc& lhs, const Shader_input_bind_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Shader_type_desc {
	Shader_variable_class _class{};
	Shader_variable_type _type{};
	Uint _rows{ 0 };
	Uint _columns{ 0 };
	Uint _elements{ 0 };
	Uint _members{ 0 };
	Uint _offset{ 0 };
	Pcstr _name{ nullptr };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Shader_type_desc, D3D11_SHADER_TYPE_DESC);
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_class, Shader_variable_class, Class);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_type, Shader_variable_type, Type);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_rows, Uint, Rows);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_columns, Uint, Columns);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_elements, Uint, Elements);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_members, Uint, Members);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_offset, Uint, Offset);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_name, Pcstr, Name);
};
static_assert(sizeof(Shader_type_desc) == sizeof(D3D11_SHADER_TYPE_DESC));

inline bool operator==(const Shader_type_desc& lhs, const Shader_type_desc& rhs) noexcept {
	return (lhs.Class == rhs.Class)
		&& (lhs.Type == rhs.Type)
		&& (lhs.Rows == rhs.Rows)
		&& (lhs.Columns == rhs.Columns)
		&& (lhs.Elements == rhs.Elements)
		&& (lhs.Members == rhs.Members)
		&& (lhs.Offset == rhs.Offset)
		&& (strcmp(lhs.Name, rhs.Name) == 0);
}

inline bool operator!=(const Shader_type_desc& lhs, const Shader_type_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Shader_variable_desc {
	Pcstr _name{ nullptr };
	Uint _start_offset{ 0 };
	Uint _size{ 0 };
	Uint _flags{ 0 };
	Pvoid _default_value{ nullptr };
	Uint _start_texture{ 0 };
	Uint _texture_size{ 0 };
	Uint _start_sampler{ 0 };
	Uint _sampler_size{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Shader_variable_desc, D3D11_SHADER_VARIABLE_DESC)
public:

	Shader_variable_flag get_flags() const noexcept {
		return Shader_variable_flag_bit(_flags);
	}

	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_name, Pcstr, Name);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_start_offset, Uint, StartOffset);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_size, Uint, Size);
	__declspec(property(get = get_flags)) Shader_variable_flag uFlags;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_default_value, Pvoid, DefaultValue);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_start_texture, Uint, StartTexture);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_texture_size, Uint, TextureSize);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_start_sampler, Uint, StartSampler);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_sampler_size, Uint, SamplerSize);
};
static_assert(sizeof(Shader_variable_desc) == sizeof(D3D11_SHADER_VARIABLE_DESC));

inline bool operator==(const Shader_variable_desc& lhs, const Shader_variable_desc& rhs) noexcept {
	return (lhs.StartOffset == rhs.StartOffset)
		&& (lhs.Size == rhs.Size)
		&& (lhs.uFlags == rhs.uFlags)
		&& (lhs.DefaultValue == rhs.DefaultValue)
		&& (lhs.StartTexture == rhs.StartTexture)
		&& (lhs.TextureSize == rhs.TextureSize)
		&& (lhs.StartSampler == rhs.StartSampler)
		&& (lhs.SamplerSize == rhs.SamplerSize)
		&& (strcmp(lhs.Name, rhs.Name) == 0);
}

inline bool operator!=(const Shader_variable_desc& lhs, const Shader_variable_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Signature_parameter_desc {
	Pcstr _semantic_name{ nullptr };
	Uint _semantic_index{ 0 };
	Uint _register{ 0 };
	Name _system_value_type{};
	Register_component_type _component_type{};
	Byte _mask{ 0 };
	Byte _read_write_mask{ 0 };
	Uint _stream{ 0 };
	Min_precision _min_precision{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Signature_parameter_desc, D3D11_SIGNATURE_PARAMETER_DESC)
public:
	Component_mask get_mask() const noexcept {
		return Component_mask_bit(_mask);
	}

	Component_mask get_read_write_mask() const noexcept {
		return Component_mask_bit(_read_write_mask);
	}

	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_semantic_name, Pcstr, SemanticName);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_semantic_index, Uint, SemanticIndex);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_register, Uint, Register);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_system_value_type, Name, SystemValueType);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_component_type, Register_component_type, ComponentType);
	__declspec(property(get = get_mask)) Component_mask Mask;
	__declspec(property(get = get_read_write_mask)) Component_mask ReadWriteMask;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_stream, Uint, Stream);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_min_precision, _HW_3D_D3D_ Min_precision, MinPrecision);
};
static_assert(sizeof(Signature_parameter_desc) == sizeof(D3D11_SIGNATURE_PARAMETER_DESC));

inline bool operator==(const Signature_parameter_desc& lhs, const Signature_parameter_desc& rhs) noexcept {
	return (lhs.SemanticIndex == rhs.SemanticIndex)
		&& (lhs.Register == rhs.Register)
		&& (lhs.SystemValueType == rhs.SystemValueType)
		&& (lhs.ComponentType == rhs.ComponentType)
		&& (lhs.Mask == rhs.Mask)
		&& (lhs.ReadWriteMask == rhs.ReadWriteMask)
		&& (lhs.Stream == rhs.Stream)
		&& (lhs.MinPrecision == rhs.MinPrecision)
		&& (strcmp(lhs.SemanticName, rhs.SemanticName) == 0);
}

inline bool operator!=(const Signature_parameter_desc& lhs, const Signature_parameter_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Trace_register {
	Trace_register_type _reg_type;
	union {
		Uint16 _index_1d;
		_HW_3D_STD_ array<Uint16, 2> _index_2d;
	};
	Uint8 _operand_index;
	Uint8 _flags;

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Trace_register, D3D11_TRACE_REGISTER)
public:
	Trace_register_flag get_flags() const noexcept {
		return Trace_register_flag_bit(_flags);
	}

	_HW_3D_STD_ array<Uint16, 2> get_index_2d() const noexcept {
		return _index_2d;
	}

	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_reg_type, Trace_register_type, RegType);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_index_1d, Uint16, Index1D);
	__declspec(property(get = get_index_2d)) _HW_3D_STD_ array<Uint16, 2> Index2D;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_operand_index, Uint8, OperandIndex);
	__declspec(property(get = get_flags)) Trace_register_flag Flags;
};
static_assert(sizeof(Trace_register) == sizeof(D3D11_TRACE_REGISTER));

inline bool operator==(const Trace_register& lhs, const Trace_register& rhs) noexcept {
	return (lhs.RegType == rhs.RegType)
		&& (lhs.Index2D == rhs.Index2D) //if an undefined behavior when valid value is Index1D
		&& (lhs.OperandIndex == rhs.OperandIndex)
		&& (lhs.Flags == rhs.Flags);
}

inline bool operator!=(const Trace_register& lhs, const Trace_register& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Vertex_shader_trace_desc {
	Uint64 _invocation{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Vertex_shader_trace_desc, D3D11_VERTEX_SHADER_TRACE_DESC)
public:
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_invocation, Uint64, Invocation);
};
static_assert(sizeof(Vertex_shader_trace_desc) == sizeof(D3D11_VERTEX_SHADER_TRACE_DESC));

inline bool operator==(const Vertex_shader_trace_desc& lhs, const Vertex_shader_trace_desc& rhs) noexcept {
	return (lhs.Invocation == rhs.Invocation);
}

inline bool operator!=(const Vertex_shader_trace_desc& lhs, const Vertex_shader_trace_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Shader_trace_desc {
	Shader_type _type;
	Uint _flags;
	union {
		Vertex_shader_trace_desc _vertex_shader_trace_desc;
		Hull_shader_trace_desc _hull_shader_trace_desc;
		Domain_shader_trace_desc _domain_shader_trace_desc;
		Geometry_shader_trace_desc _geometry_shader_trace_desc;
		Pixel_shader_trace_desc _pixel_shader_trace_desc;
		Compute_shader_trace_desc _compute_shader_trace_desc;
	};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Shader_trace_desc, D3D11_SHADER_TRACE_DESC)
public:
	Shader_trace_flag get_flags() const noexcept {
		return Shader_trace_flag_bit(_flags);
	}

	Vertex_shader_trace_desc get_vertex_shader_trace_desc() const noexcept {
		assert(_type == Shader_type::vertex);
		return _vertex_shader_trace_desc;
	}

	Hull_shader_trace_desc get_hull_shader_trace_desc() const noexcept {
		assert(_type == Shader_type::hull);
		return _hull_shader_trace_desc;
	}

	Domain_shader_trace_desc get_domain_shader_trace_desc() const noexcept {
		assert(_type == Shader_type::domain);
		return _domain_shader_trace_desc;
	}

	Geometry_shader_trace_desc get_geometry_shader_trace_desc() const noexcept {
		assert(_type == Shader_type::geometry);
		return _geometry_shader_trace_desc;
	}

	Pixel_shader_trace_desc get_pixel_shader_trace_desc() const noexcept {
		assert(_type == Shader_type::pixel);
		return _pixel_shader_trace_desc;
	}

	Compute_shader_trace_desc get_compute_shader_trace_desc() const noexcept {
		assert(_type == Shader_type::compute);
		return _compute_shader_trace_desc;
	}

	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_type, Shader_type, Type);
	__declspec(property(get = get_flags)) Shader_trace_flag Flags;
	__declspec(property(get = get_vertex_shader_trace_desc)) _HW_3D_D3D_ Vertex_shader_trace_desc VertexShaderTraceDesc;
	__declspec(property(get = get_hull_shader_trace_desc)) _HW_3D_D3D_ Hull_shader_trace_desc HullShaderTraceDesc;
	__declspec(property(get = get_domain_shader_trace_desc)) _HW_3D_D3D_ Domain_shader_trace_desc DomainShaderTraceDesc;
	__declspec(property(get = get_geometry_shader_trace_desc)) _HW_3D_D3D_ Geometry_shader_trace_desc GeometryShaderTraceDesc;
	__declspec(property(get = get_pixel_shader_trace_desc)) _HW_3D_D3D_ Pixel_shader_trace_desc PixelShaderTraceDesc;
	__declspec(property(get = get_compute_shader_trace_desc)) _HW_3D_D3D_ Compute_shader_trace_desc ComputeShaderTraceDesc;
};
static_assert(sizeof(Shader_trace_desc) == sizeof(D3D11_SHADER_TRACE_DESC));

inline bool operator==(const Shader_trace_desc& lhs, const Shader_trace_desc& rhs) noexcept {
	if (lhs.Flags != rhs.Flags || lhs.Type != rhs.Type)
		return false;

	switch (lhs.Type) {
	case Shader_type::vertex:
		return lhs.VertexShaderTraceDesc == rhs.VertexShaderTraceDesc;
	case Shader_type::hull:
		return lhs.HullShaderTraceDesc == rhs.HullShaderTraceDesc;
	case Shader_type::domain:
		return lhs.DomainShaderTraceDesc == rhs.DomainShaderTraceDesc;
	case Shader_type::geometry:
		return lhs.GeometryShaderTraceDesc == rhs.GeometryShaderTraceDesc;
	case Shader_type::pixel:
		return lhs.PixelShaderTraceDesc == rhs.PixelShaderTraceDesc;
	case Shader_type::compute:
		return lhs.ComputeShaderTraceDesc == rhs.ComputeShaderTraceDesc;
	default:
		return false;
	}
}

inline bool operator!=(const Shader_trace_desc& lhs, const Shader_trace_desc& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Trace_value {
	_HW_3D_STD_ array<Uint, 4> _bits;
	Trace_component_mask _valid_mask;

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Trace_value, D3D11_TRACE_VALUE)
public:
	_HW_3D_STD_ array<Uint, 4> get_bits() const noexcept {
		return _bits;
	}

	__declspec(property(get = get_bits)) _HW_3D_STD_ array<Uint, 4> Bits;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_valid_mask, Trace_component_mask, ValidMask);
};
static_assert(sizeof(Trace_value) == sizeof(D3D11_TRACE_VALUE));

inline bool operator==(const Trace_value& lhs, const Trace_value& rhs) noexcept {
	auto bits_lhs = lhs.Bits;
	auto bits_rhs = rhs.Bits;
	return (lhs.ValidMask == rhs.ValidMask)
		&& (lhs.ValidMask & Trace_component_mask_bit::x ? bits_lhs[0] == bits_rhs[0] : true)
		&& (lhs.ValidMask & Trace_component_mask_bit::y ? bits_lhs[1] == bits_rhs[1] : true)
		&& (lhs.ValidMask & Trace_component_mask_bit::z ? bits_lhs[2] == bits_rhs[2] : true)
		&& (lhs.ValidMask & Trace_component_mask_bit::w ? bits_lhs[3] == bits_rhs[3] : true);
}

inline bool operator!=(const Trace_value& lhs, const Trace_value& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Trace_step {
	Uint _id{ 0 };
	Bool _instruction_active{ False };
	Uint8 _num_register_written{ 0 };
	Uint8 _num_register_read{ 0 };
	Trace_misc_operations_mask _misc_operations{};
	Uint _opcode_type{ 0 };
	Uint64 _current_global_cycle{ 0 };

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Trace_step, D3D11_TRACE_STEP)
public:

	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_id, Uint, ID);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_instruction_active, Bool, InstructionActive);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_num_register_written, Uint8, NumRegistersWritten);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_num_register_read, Uint8, NumRegistersRead);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_misc_operations, Trace_misc_operations_mask, MiscOperations);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_opcode_type, Uint, OpcodeType);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_current_global_cycle, Uint64, CurrentGlobalCycle);
};
static_assert(sizeof(Trace_step) == sizeof(D3D11_TRACE_STEP));

inline bool operator==(const Trace_step& lhs, const Trace_step& rhs) noexcept {
	return (lhs.ID == rhs.ID)
		&& (lhs.InstructionActive == rhs.InstructionActive)
		&& (lhs.NumRegistersRead == rhs.NumRegistersRead)
		&& (lhs.NumRegistersWritten == rhs.NumRegistersWritten)
		&& (lhs.MiscOperations == rhs.MiscOperations)
		&& (lhs.OpcodeType == rhs.OpcodeType)
		&& (lhs.CurrentGlobalCycle == rhs.CurrentGlobalCycle);
}

inline bool operator!=(const Trace_step& lhs, const Trace_step& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Trace_stats {
	Shader_trace_desc _trace_desc;
	Uint8 _num_invocations_in_stamp{ 0 };
	Uint8 _target_stamp_index{ 0 };
	Uint _num_trace_steps{ 0 };
	_HW_3D_STD_ array<Trace_component_mask, 32> _input_mask{};
	_HW_3D_STD_ array<Trace_component_mask, 32> _output_mask{};
	Uint16 _num_temps{ 0 };
	Uint16 _max_indexable_temp_index{ 0 };
	_HW_3D_STD_ array<Uint16, 4096> _indexable_temp_size{};
	Uint16 _immediate_constant_buffer_size{ 0 };
	_HW_3D_STD_ array<_HW_3D_STD_ array<Uint, 2>, 4> _pixel_position{};
	_HW_3D_STD_ array<Uint64, 4> _pixel_coverage_mask{};
	_HW_3D_STD_ array<Uint64, 4> _pixel_discard_mask{};
	_HW_3D_STD_ array<Uint64, 4> _pixel_coverage_mask_after_shader{};
	_HW_3D_STD_ array<Uint64, 4> _pixel_coverage_mask_after_a2c_sample_mask{};
	_HW_3D_STD_ array<Uint64, 4> _pixel_coverage_mask_after_a2c_sample_mask_depth{};
	_HW_3D_STD_ array<Uint64, 4> _pixel_coverage_mask_after_a2c_sample_mask_depht_stencil{};
	Bool _ps_outputs_depth{ False };
	Bool _ps_outputs_mask{ False };
	Trace_gs_input_primitive _gs_input_primitive{};
	Bool _gs_inputs_primitive_id{ False };
	_HW_3D_STD_ array<Trace_component_mask, 32> _hs_output_patch_constant_mask{};
	_HW_3D_STD_ array<Trace_component_mask, 32> _ds_input_patch_constant_mask{};

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Trace_stats, D3D11_TRACE_STATS)
public:
	const _HW_3D_STD_ array<Trace_component_mask, 32>& get_input_mask() const noexcept {
		return _input_mask;
	};

	const _HW_3D_STD_ array<Trace_component_mask, 32>& get_output_mask() const noexcept {
		return _output_mask;
	};

	const _HW_3D_STD_ array<Uint16, 4096>& get_indexable_temp_size() const noexcept {
		return _indexable_temp_size;
	};

	const _HW_3D_STD_ array<_HW_3D_STD_ array<Uint, 2>, 4>& get_pixel_position() const noexcept {
		return _pixel_position;
	};

	const _HW_3D_STD_ array<Uint64, 4>& get_pixel_coverage_mask() const noexcept {
		return _pixel_coverage_mask;
	};

	const _HW_3D_STD_ array<Uint64, 4>& get_pixel_discard_mask() const noexcept {
		return _pixel_discard_mask;
	};

	const _HW_3D_STD_ array<Uint64, 4>& get_pixel_coverage_mask_after_shader() const noexcept {
		return _pixel_coverage_mask_after_shader;
	};

	const _HW_3D_STD_ array<Uint64, 4>& get_pixel_coverage_mask_after_a2c_sample_mask() const noexcept {
		return _pixel_coverage_mask_after_a2c_sample_mask;
	};

	const _HW_3D_STD_ array<Uint64, 4>& get_pixel_coverage_mask_after_a2c_sample_mask_depth() const noexcept {
		return _pixel_coverage_mask_after_a2c_sample_mask_depth;
	};

	const _HW_3D_STD_ array<Uint64, 4>& get_pixel_coverage_mask_after_a2c_sample_mask_depht_stencil() const noexcept {
		return _pixel_coverage_mask_after_a2c_sample_mask_depht_stencil;
	};

	const _HW_3D_STD_ array<Trace_component_mask, 32>& get_hs_output_patch_constant_mask() const noexcept {
		return _hs_output_patch_constant_mask;
	};

	const _HW_3D_STD_ array<Trace_component_mask, 32>& get_ds_input_patch_constant_mask() const noexcept {
		return _ds_input_patch_constant_mask;
	};

	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_trace_desc, Shader_trace_desc, TraceDesc);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_num_invocations_in_stamp, Uint8, NumInvocationsInStamp);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_target_stamp_index, Uint8, TargetStampIndex);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_num_trace_steps, Uint, NumTraceSteps);
	__declspec(property(get = get_input_mask)) const _HW_3D_STD_ array<Trace_component_mask, 32>& InputMask;
	__declspec(property(get = get_output_mask)) const _HW_3D_STD_ array<Trace_component_mask, 32>& OutputMask;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_num_temps, Uint16, NumTemps);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_max_indexable_temp_index, Uint16, MaxIndexableTempIndex);
	__declspec(property(get = get_indexable_temp_size)) const _HW_3D_STD_ array<Uint16, 4096>& IndexableTempSize;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_immediate_constant_buffer_size, Uint16, ImmediateConstantBufferSize);
	__declspec(property(get = get_pixel_position)) const _HW_3D_STD_ array<_HW_3D_STD_ array<Uint, 2>, 4>& PixelPosition;
	__declspec(property(get = get_pixel_coverage_mask)) const _HW_3D_STD_ array<Uint64, 4>& PixelCoverageMask;
	__declspec(property(get = get_pixel_discard_mask)) const _HW_3D_STD_ array<Uint64, 4>& PixelDiscardedMask;
	__declspec(property(get = get_pixel_coverage_mask_after_shader)) const _HW_3D_STD_ array<Uint64, 4>& PixelCoverageMaskAfterShader;
	__declspec(property(get = get_pixel_coverage_mask_after_a2c_sample_mask)) const _HW_3D_STD_ array<Uint64, 4>& PixelCoverageMaskAfterA2CSampleMask;
	__declspec(property(get = get_pixel_coverage_mask_after_a2c_sample_mask_depth)) const _HW_3D_STD_ array<Uint64, 4>& PixelCoverageMaskAfterA2CSampleMaskDepth;
	__declspec(property(get = get_pixel_coverage_mask_after_a2c_sample_mask_depht_stencil)) const _HW_3D_STD_ array<Uint64, 4>& PixelCoverageMaskAfterA2CSampleMaskDepthStencil;
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_ps_outputs_depth, Bool, PSOutputsDepth);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_ps_outputs_mask, Bool, PSOutputsMask);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_gs_input_primitive, Trace_gs_input_primitive, GSInputPrimitive);
	_HW_3D_D3D_STRUCT_READONLY_TRIVIAL_PROPERTY_(_gs_inputs_primitive_id, Bool, GSInputsPrimitiveID);
	__declspec(property(get = get_hs_output_patch_constant_mask)) const _HW_3D_STD_ array<Trace_component_mask, 32>& HSOutputPatchConstantMask;
	__declspec(property(get = get_ds_input_patch_constant_mask)) const _HW_3D_STD_ array<Trace_component_mask, 32>& DSInputPatchConstantMask;
};
static_assert(sizeof(Trace_stats) == sizeof(D3D11_TRACE_STATS));

inline bool operator==(const Trace_stats& lhs, const Trace_stats& rhs) noexcept {
	return (lhs.TraceDesc == rhs.TraceDesc)
		&& (lhs.NumInvocationsInStamp == rhs.NumInvocationsInStamp)
		&& (lhs.TargetStampIndex == rhs.TargetStampIndex)
		&& (lhs.NumTraceSteps == rhs.NumTraceSteps)
		&& (lhs.InputMask == rhs.InputMask)
		&& (lhs.OutputMask == rhs.OutputMask)
		&& (lhs.NumTemps == rhs.NumTemps)
		&& (lhs.MaxIndexableTempIndex == rhs.MaxIndexableTempIndex)
		&& (lhs.IndexableTempSize == rhs.IndexableTempSize)
		&& (lhs.ImmediateConstantBufferSize == rhs.ImmediateConstantBufferSize)
		&& (lhs.PixelPosition == rhs.PixelPosition)
		&& (lhs.PixelCoverageMask == rhs.PixelCoverageMask)
		&& (lhs.PixelDiscardedMask == rhs.PixelDiscardedMask)
		&& (lhs.PixelCoverageMaskAfterShader == rhs.PixelCoverageMaskAfterShader)
		&& (lhs.PixelCoverageMaskAfterA2CSampleMask == rhs.PixelCoverageMaskAfterA2CSampleMask)
		&& (lhs.PixelCoverageMaskAfterA2CSampleMaskDepth == rhs.PixelCoverageMaskAfterA2CSampleMaskDepth)
		&& (lhs.PixelCoverageMaskAfterA2CSampleMaskDepthStencil == rhs.PixelCoverageMaskAfterA2CSampleMaskDepthStencil)
		&& (lhs.PSOutputsDepth == rhs.PSOutputsDepth)
		&& (lhs.PSOutputsMask == rhs.PSOutputsMask)
		&& (lhs.GSInputPrimitive == rhs.GSInputPrimitive)
		&& (lhs.GSInputsPrimitiveID == rhs.GSInputsPrimitiveID)
		&& (lhs.HSOutputPatchConstantMask == rhs.HSOutputPatchConstantMask)
		&& (lhs.DSInputPatchConstantMask == rhs.DSInputPatchConstantMask);
}

inline bool operator!=(const Trace_stats& lhs, const Trace_stats& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Info_queue_filter {
	Info_queue_filter_desc _allow_list;
	Info_queue_filter_desc _deny_list;

public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Info_queue_filter, D3D11_INFO_QUEUE_FILTER)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_allow_list, Info_queue_filter_desc, AllowList);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_deny_list, Info_queue_filter_desc, DenyList);
};
static_assert(sizeof(Info_queue_filter) == sizeof(D3D11_INFO_QUEUE_FILTER));

inline bool operator==(const Info_queue_filter& lhs, const Info_queue_filter& rhs) noexcept {
	return (lhs.AllowList == rhs.AllowList)
		&& (lhs.DenyList == rhs.DenyList);
}

inline bool operator!=(const Info_queue_filter& lhs, const Info_queue_filter& rhs) noexcept {
	return !operator==(lhs, rhs);
}

//
//
class Shader_data {
	LPCVOID _p_bytecode = nullptr;
	Size_t _bytecode_length = 0;
public:
	_HW_3D_D3D_STRUCT_WRAPPER_(Shader_data, D3D_SHADER_DATA)
public:
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_p_bytecode, LPCVOID, pBytecode);
	_HW_3D_D3D_STRUCT_TRIVIAL_PROPERTY_(_bytecode_length, Size_t, BytecodeLength);
};
static_assert(sizeof(Shader_data) == sizeof(D3D_SHADER_DATA));

inline bool operator==(const Shader_data& lhs, const Shader_data& rhs) noexcept {
	return (lhs.BytecodeLength == rhs.BytecodeLength)
		&& (_HW_3D_STD_ memcmp(lhs.pBytecode, rhs.pBytecode, lhs.BytecodeLength) == 0);
}

inline bool operator!=(const Shader_data& lhs, const Shader_data& rhs) noexcept {
	return (!(lhs == rhs));
}


_HW_3D_CLOSE_D3D_NAMESPACE_

_HW_3D_CLOSE_HW_NAMESPACE_