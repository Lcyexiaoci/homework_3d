#pragma once

#include "d3d_fwd.h"
#include "d3d_wrapper.hpp"

_HW_3D_OPEN_HW_NAMESPACE_

_HW_3D_OPEN_DXGI_NAMESPACE_

//
//
_HW_3D_INLINE_FUNCTION_ _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IFactory>>
create_factory() {
	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IFactory>> res;

	auto&[r, fac] = res;

	IDXGIFactory* raw_fac = nullptr;
	r = static_cast<Result>(CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)(&raw_fac)));

	fac = _HW_3D_STD_ make_unique<_Factory<true>>(raw_fac);

	return res;
}

_HW_3D_INLINE_FUNCTION_ _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IFactory1>>
create_factory1() {
	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IFactory1>> res;

	auto&[r, fac] = res;

	IDXGIFactory1* raw_fac = nullptr;
	r = static_cast<Result>(CreateDXGIFactory1(__uuidof(IDXGIFactory1), (void**)(&raw_fac)));

	fac = _HW_3D_STD_ make_unique<_Factory1<true>>(raw_fac);

	return res;
}

_HW_3D_INLINE_FUNCTION_ _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IFactory2>>
create_facotry2(UINT flags) {
	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IFactory2>> res;

	auto&[r, fac] = res;

	IDXGIFactory2* raw_fac = nullptr;
	r = static_cast<Result>(CreateDXGIFactory2(flags, __uuidof(IDXGIFactory), (void**)(&raw_fac)));

	fac = _HW_3D_STD_ make_unique<_Factory2<true>>(raw_fac);

	return res;
}

_HW_3D_INLINE_FUNCTION_ _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDebug>>
get_dubug_interface() {
	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDebug>> res;

	auto&[r, d] = res;

	IDXGIDebug* raw_ptr = nullptr;
	r = static_cast<Result>(DXGIGetDebugInterface(__uuidof(IDXGIDebug), (void**)(&raw_ptr)));

	d = _HW_3D_STD_ make_unique<_Debug<true>>(raw_ptr);

	return res;
}

_HW_3D_INLINE_FUNCTION_ _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IInfo_queue>>
get_info_queue_interface() {
	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IInfo_queue>> res;

	auto&[r, iq] = res;

	IDXGIInfoQueue* raw_ptr = nullptr;
	r = static_cast<Result>(DXGIGetDebugInterface(__uuidof(IDXGIInfoQueue), (void**)(&raw_ptr)));

	iq = _HW_3D_STD_ make_unique<_Info_queue<true>>(raw_ptr);

	return res;
}

_HW_3D_INLINE_FUNCTION_ _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDebug1>>
get_debug_interface1(UINT flags) {
	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDebug1>> res;

	auto&[r, d] = res;

	IDXGIDebug1* raw_ptr = nullptr;
	r = static_cast<Result>(DXGIGetDebugInterface1(flags, __uuidof(IDXGIDebug1), (void**)(&raw_ptr)));

	d = _HW_3D_STD_ make_unique<_Debug1<true>>(raw_ptr);

	return res;
}

_HW_3D_CLOSE_DXGI_NAMESPACE_

_HW_3D_OPEN_D3D_NAMESPACE_

_HW_3D_INLINE_FUNCTION_ _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDevice>, Feature_level, _HW_3D_STD_ unique_ptr<IDevice_context>>
create_device(
	_HW_3D_IN_ _HW_3D_DXGI_ IAdapter* adpater,
	_HW_3D_IN_ Driver_type driver_type,
	_HW_3D_IN_ ::HMODULE software,
	_HW_3D_IN_ Create_device_flag flags,
	_HW_3D_IN_ const _HW_3D_STD_ vector<Feature_level>& feature_levels,
	_HW_3D_IN_ Uint sdk_version
) {
	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDevice>, Feature_level, _HW_3D_STD_ unique_ptr<IDevice_context>> res;

	auto&[r, device, flev, device_context] = res;

	ID3D11Device* raw_device = nullptr;
	ID3D11DeviceContext* raw_device_context = nullptr;
	r = static_cast<Result>(D3D11CreateDevice(
		value_ptr(adpater),
		(D3D_DRIVER_TYPE)driver_type,
		software,
		Create_device_flag::mask_type(flags),
		(const D3D_FEATURE_LEVEL*)(feature_levels.data()),
		Uint(feature_levels.size()),
		sdk_version,
		&raw_device,
		(D3D_FEATURE_LEVEL*)&flev,
		&raw_device_context
	));

	device = _HW_3D_STD_ make_unique<_Device<true>>(raw_device);
	device_context = _HW_3D_STD_ make_unique<_Device_context<true>>(raw_device_context);

	return res;
}

_HW_3D_INLINE_FUNCTION_ _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDevice>, Feature_level, _HW_3D_STD_ unique_ptr<IDevice_context>, _HW_3D_STD_ unique_ptr<_HW_3D_DXGI_ ISwap_chain>>
create_device_and_swap_chain(
	_HW_3D_IN_ _HW_3D_DXGI_ IAdapter* adapter,
	_HW_3D_IN_ Driver_type driver_type,
	_HW_3D_IN_ HMODULE software,
	_HW_3D_IN_ Create_device_flag flags,
	_HW_3D_IN_ const _HW_3D_STD_ vector<Feature_level>& feature_levels,
	_HW_3D_IN_ Uint sdk_version,
	_HW_3D_IN_ const _HW_3D_DXGI_ Swap_chain_desc& swap_chain_desc
) {
	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDevice>, Feature_level, _HW_3D_STD_ unique_ptr<IDevice_context>, _HW_3D_STD_ unique_ptr<_HW_3D_DXGI_ ISwap_chain>> res;

	auto&[r, device, flev, device_context, swap_chain] = res;

	ID3D11Device* raw_device = nullptr;
	ID3D11DeviceContext* raw_context = nullptr;
	IDXGISwapChain* raw_swap_chain = nullptr;
	r = static_cast<Result>(D3D11CreateDeviceAndSwapChain(
		value_ptr(adapter),
		(D3D_DRIVER_TYPE)driver_type,
		software,
		Create_device_flag::mask_type(flags),
		(const D3D_FEATURE_LEVEL*)(feature_levels.data()),
		Uint(feature_levels.size()),
		sdk_version,
		value_ptr(swap_chain_desc),
		&raw_swap_chain,
		&raw_device,
		(D3D_FEATURE_LEVEL*)&flev,
		&raw_context
	));

	device = _HW_3D_STD_ make_unique<_Device<true>>(raw_device);
	device_context = _HW_3D_STD_ make_unique<_Device_context<true>>(raw_context);
	swap_chain = _HW_3D_STD_ make_unique<_HW_3D_DXGI_ _Swap_chain<true>>(raw_swap_chain);

	return res;
}

_HW_3D_INLINE_FUNCTION_ Uint
calc_subresource(
	_HW_3D_IN_ Uint mip_slice,
	_HW_3D_IN_ Uint array_slice,
	_HW_3D_IN_ Uint mip_levels
) {
	return D3D11CalcSubresource(mip_slice, array_slice, mip_levels);
}

_HW_3D_INLINE_FUNCTION_ _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBlob>>
compile_from_file(
	_HW_3D_IN_ const _HW_3D_STD_ wstring& file_name,
	_HW_3D_IN_ const Shader_macro* define,
	_HW_3D_IN_ const _HW_3D_STD_ string& entry_point,
	_HW_3D_IN_ const _HW_3D_STD_ string& target,
	_HW_3D_IN_ Compile_constant flags
) {
	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBlob>> res;

	auto&[r, blob_or_err] = res;

	ID3DBlob* binary_code = nullptr;
	ID3DBlob* error_message = nullptr;
	r = static_cast<Result>(D3DCompileFromFile(
		file_name.c_str(),
		value_ptr(define),
		D3D_COMPILE_STANDARD_FILE_INCLUDE,
		entry_point.c_str(),
		target.c_str(),
		Compile_constant::mask_type(flags),
		0,
		&binary_code,
		&error_message
	));

	if (r == Result::ok) {
		blob_or_err = _HW_3D_STD_ make_unique<_Blob<true>>(binary_code);
	}
	else {
		blob_or_err = _HW_3D_STD_ make_unique<_Blob<true>>(error_message);
		if (binary_code) binary_code->Release();
	}

	return res;
}


_HW_3D_INLINE_FUNCTION_ _HW_3D_STD_ unique_ptr<_HW_3D_DXGI_ IDevice>
transfer_device(
	_HW_3D_IN_ IDevice* device
) {
	_HW_3D_STD_ unique_ptr<_HW_3D_DXGI_ IDevice> res;

	auto result = device->query_interface(__uuidof(IDXGIDevice));

	if (_HW_3D_STD_ get<0>(result) == S_OK) {
		res = _HW_3D_STD_ make_unique<_HW_3D_DXGI_ _Device<true>>(reinterpret_cast<IDXGIDevice*>(_HW_3D_STD_ get<1>(result)));
	}

	return res;
}

_HW_3D_CLOSE_D3D_NAMESPACE_

_HW_3D_CLOSE_HW_NAMESPACE_
