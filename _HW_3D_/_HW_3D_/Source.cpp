#include "utils.hpp"
#include <iostream>
#include "d3d\d3d_flag.hpp"
#include "d3d\d3d_enum.h"
#include "d3d\d3d_struct.hpp"
#include "d3d\d3d_wrapper.hpp"
#include "d3d\d3d_func.hpp"

enum class T : uint8_t {
	
};

void test_wrapper();

int main() {
	using namespace hw;

	Underlying_type_t<int> a{ 0 };
	std::cout << sizeof(a) << std::endl;

	Underlying_type_t<T> b;
	std::cout << sizeof(b) << std::endl;


	test_wrapper();
}

void test_wrapper() {
#define _TEST_DXGI_WRAPPER_(_Type) \
	auto p ## _Type = _HW_3D_STD_ make_unique<_HW_3D_DXGI_ _Type<false>>(nullptr)
#define _TEST_D3D_WRAPPER_(_Type) \
	auto p ## _Type = _HW_3D_STD_ make_unique<_HW_3D_D3D_ _Type<false>>(nullptr)
	{//test dxgi wrapper
	_TEST_DXGI_WRAPPER_(_Resource);
	_TEST_DXGI_WRAPPER_(_Output);
	_TEST_DXGI_WRAPPER_(_Output_duplication);

	}
	{//test d3d wrapper

	}
#undef _TEST_DXGI_WRAPPER_
#undef _TEST_D3D_WRAPPER_
}