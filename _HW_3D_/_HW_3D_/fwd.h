#pragma once

#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <cassert>
#include <ctime>

#include <type_traits>
#include <array>
#include <vector>
#include <functional>
#include <mutex>
#include <thread>
#include <tuple>
#include <memory>
#include <string>
#include <algorithm>
#include <atomic>
#include <exception>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <any>
#include <optional>
#include <variant>
#include <filesystem>
#include <memory_resource>

#include <d3d11_4.h>
#include <dxgiformat.h>
#include <d3d11shader.h>
#include <d3d11shadertracing.h>
#include <d3dcompiler.h>
#include <Unknwn.h>
#include <dxgidebug.h>
#include <dxgi1_6.h>
#include <DirectXMath.h> 

/*
for parameter declaration;
*/
#define _HW_3D_IN_ 
#define _HW_3D_OUT_
#define _HW_3D_IN_OUT_ 

/*
for namespace
*/

#define _HW_3D_STD_ ::std::
#define _HW_3D_HW_	hw::

#define _HW_3D_OPEN_HW_NAMESPACE_		namespace hw {
#define _HW_3D_CLOSE_HW_NAMESPACE_		}

/*
for concurrency
*/

#ifdef _HW_3D_MULTITHREAD_
#define _HW_3D_SCOPED_LOCK_(mtx) _HW_3D_STD_ lock_guard sl_ ##mtx{mtx}
#else
#define _HW_3D_SCOPED_LOCK_(mtx)
#endif

#define _HW_3D_DEFAULT_MUTEX_NAME_ _default_mtx
#define _HW_3D_AUTO_SCOPED_LOCK_() _HW_3D_SCOPED_LOCK_(_HW_3D_DEFAULT_MUTEX_NAME_)

/*

*/

#define _HW_3D_TRHOW_EXCEPTION_(error_type, msg) throw _HW_3D_HW_ Hw_exception(error_type, msg, __FILE__, __LINE__)

#define _HW_3D_NO_VTABLE_ __declspec(novtable)

/*
inline, it seems that plain inline have some bug
*/
#define _HW_3D_INLINE_FUNCTION_ __forceinline

#define _HW_3D_INLINE_VARIABLE_ __declspec(selectany)

/*

*/
//flag type def macro
#define _HW_3D_HW_FLAG_TYPE_(Flag_type, Bit_type)											\
using Flag_type = _HW_3D_HW_ Flags<Bit_type, _HW_3D_HW_ Underlying_type_t<Bit_type>>;		\
																							\
_HW_3D_INLINE_FUNCTION_ Flag_type operator|(Bit_type bit0, Bit_type bit1) {					\
	return Flag_type (bit0) | bit1;															\
}																							\
																							\
_HW_3D_INLINE_FUNCTION_ Flag_type operator~(Bit_type bit) {									\
	return ~Flag_type (bit);																\
}

//type def
_HW_3D_OPEN_HW_NAMESPACE_

using Bool = BOOL;
using Int = INT;
using Int8 = INT8;
using Int16 = INT16;
using Int32 = INT32;
using Int64 = INT64;
using Uint = UINT;
using Uint8 = UINT8;
using Uint16 = UINT16;
using Uint32 = UINT32;
using Uint64 = UINT64;
using Pcstr = LPCSTR;
using Pvoid = LPVOID;
using Long = LONG;
using Byte = BYTE;
using Size_t = SIZE_T;
using Float = FLOAT;
using Double = DOUBLE;
using Ulong = ULONG;

using Path = _HW_3D_STD_ experimental::filesystem::path;

_HW_3D_CLOSE_HW_NAMESPACE_