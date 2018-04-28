#pragma once

#include "rs_fwd.h"
#include "rs_render_manager.h"
#include "rs_hw_resource.hpp"

_HW_3D_OPEN_HW_NAMESPACE_

_HW_3D_OPEN_RS_NAMESPACE_

struct Hardware_texture : Hardware_resource {
	//format
	static bool 
		is_compressed(
			_HW_3D_IN_ Pixel_format format
		) {
		switch (format) {
		case Pixel_format::bc1_typeless:
		case Pixel_format::bc1_unorm:
		case Pixel_format::bc1_unorm_srgb:
		case Pixel_format::bc2_unorm:
		case Pixel_format::bc2_unorm_srgb:
		case Pixel_format::bc3_typeless:
		case Pixel_format::bc3_unorm:
		case Pixel_format::bc3_unorm_srgb:
		case Pixel_format::bc4_typeless:
		case Pixel_format::bc4_unorm:
		case Pixel_format::bc4_snorm:
		case Pixel_format::bc5_typeless:
		case Pixel_format::bc5_unorm:
		case Pixel_format::bc5_snorm:
		case Pixel_format::bc6h_typess:
		case Pixel_format::bc6h_uf16:
		case Pixel_format::bc6h_sf16:
		case Pixel_format::bc7_typeless:
		case Pixel_format::bc7_unorm:
		case Pixel_format::bc7_unorm_srgb:
			return true;
		default:
			return false;
		}
	}

	static _HW_3D_STD_ pair<uint32_t, uint32_t> 
		pixel_size(
			_HW_3D_IN_ Pixel_format format
		) {
		switch (format) {
		case Pixel_format::r32g32b32a32_typeless:
		case Pixel_format::r32g32b32a32_float:
		case Pixel_format::r32g32b32a32_int:
		case Pixel_format::r32g32b32a32_uint:
			return { 1, 16 };
		case Pixel_format::r32g32b32_typeless:
		case Pixel_format::r32g32b32_float:
		case Pixel_format::r32g32b32_int:
		case Pixel_format::r32g32b32_uint:
			return { 1, 12 };
		case Pixel_format::r16g16b16a16_typeless:
		case Pixel_format::r16g16b16a16_float:
		case Pixel_format::r16g16b16a16_unorm:
		case Pixel_format::r16g16b16a16_uint:
		case Pixel_format::r16g16b16a16_snorm:
		case Pixel_format::r16g16b16a16_int:
		case Pixel_format::r32g32_typeless:
		case Pixel_format::r32g32_float:
		case Pixel_format::r32g32_uint:
		case Pixel_format::r32g32_int:
		case Pixel_format::r32g8x24_typeless:
		case Pixel_format::d32_float_s8x24_uint:
		case Pixel_format::r32_float_x8x24_typeless:
		case Pixel_format::x32_typeless_g8x24_uint:
			return { 1, 8 };
		case Pixel_format::r10g10b10a2_typeless:
		case Pixel_format::r10g10b10a2_unorm:
		case Pixel_format::r10g10b10a2_uint:
		case Pixel_format::r11g11b10_float:
		case Pixel_format::r8g8b8a8_typeless:
		case Pixel_format::r8g8b8a8_unorm:
		case Pixel_format::r8g8b8a8_unorm_srgb:
		case Pixel_format::r8g8b8a8_uint:
		case Pixel_format::r8g8b8a8_snorm:
		case Pixel_format::r8g8b8a8_int:
		case Pixel_format::r16g16_typeless:
		case Pixel_format::r16g16_float:
		case Pixel_format::r16g16_unorm:
		case Pixel_format::r16g16_uint:
		case Pixel_format::r16g16_snorm:
		case Pixel_format::r16g16_int:
		case Pixel_format::r32_typeless:
		case Pixel_format::d32_float:
		case Pixel_format::r32_float:
		case Pixel_format::r32_uint:
		case Pixel_format::r32_int:
		case Pixel_format::r24g8_typeless:
		case Pixel_format::d24_unorm_s8_uint:
		case Pixel_format::r24_unorm_x8_typeless:
		case Pixel_format::x24_typeless_g8_uint:
		case Pixel_format::r9g9b9e5_sharedexp:
		case Pixel_format::b8g8r8a8_unorm:
		case Pixel_format::b8g8r8x8_unorm:
		case Pixel_format::r10g10b10_xr_bias_a2_unorm:
		case Pixel_format::b8g8r8a8_typeless:
		case Pixel_format::b8g8r8a8_unorm_srgb:
		case Pixel_format::b8g8r8x8_unorm_srgb:
		case Pixel_format::b8g8r8x8_typeless:
			return { 1, 4 };
		case Pixel_format::r8g8_typeless:
		case Pixel_format::r8g8_unorm:
		case Pixel_format::r8g8_uint:
		case Pixel_format::r8g8_snorm:
		case Pixel_format::r8g8_int:
		case Pixel_format::r16_typeless:
		case Pixel_format::r16_float:
		case Pixel_format::d16_unorm:
		case Pixel_format::r16_unorm:
		case Pixel_format::r16_uint:
		case Pixel_format::r16_snorm:
		case Pixel_format::r16_int:
		case Pixel_format::b5g6r5_unorm:
		case Pixel_format::b5g5r5a1_unorm:
			return { 1, 2 };
		case Pixel_format::r8_typeless:
		case Pixel_format::r8_unorm:
		case Pixel_format::r8_int:
		case Pixel_format::r8_uint:
		case Pixel_format::r8_snorm:
		case Pixel_format::a8_unorm:
			return { 1, 1 };
		case Pixel_format::r1_unorm:
			return { 8, 1 };
		case Pixel_format::r8g8_b8g8_unorm:
		case Pixel_format::g8r8_g8b8_unorm:
			return { 2, 4 };
		case Pixel_format::bc1_typeless:
		case Pixel_format::bc1_unorm:
		case Pixel_format::bc1_unorm_srgb:
		case Pixel_format::bc4_snorm:
		case Pixel_format::bc4_typeless:
		case Pixel_format::bc4_unorm:
			return { 16, 8 };
		case Pixel_format::bc2_typeless:
		case Pixel_format::bc2_unorm:
		case Pixel_format::bc2_unorm_srgb:
		case Pixel_format::bc3_typeless:
		case Pixel_format::bc3_unorm:
		case Pixel_format::bc3_unorm_srgb:
		case Pixel_format::bc5_snorm:
		case Pixel_format::bc5_typeless:
		case Pixel_format::bc5_unorm:
		case Pixel_format::bc6h_sf16:
		case Pixel_format::bc6h_typess:
		case Pixel_format::bc6h_uf16:
		case Pixel_format::bc7_typeless:
		case Pixel_format::bc7_unorm:
		case Pixel_format::bc7_unorm_srgb:
			return { 16, 16 };
		default:
			return { 0, 0 };
		}
	}

	static bool
		is_compatible(
			_HW_3D_IN_ Pixel_format dst,
			_HW_3D_IN_ Pixel_format src
		);

	static bool
		is_auto_generate_mipmaps(
			_HW_3D_IN_ Resource_info& info
		) {
		return (info.misc_flag & Resource_misc_flag::bit_type::generate_mips) != Resource_misc_flag{};
	}

	static bool
		is_used_as_unordered_access_view(
			_HW_3D_IN_ Resource_info& info
		) {
		return (info.bind_flag & Resource_bind_flag::bit_type::unordered_access) != Resource_bind_flag{};
	}

	static bool 
		is_used_as_render_target_view(
			_HW_3D_IN_ Resource_info& info
		) {
		return (info.bind_flag & Resource_bind_flag::bit_type::render_target) != Resource_bind_flag{};
	}

	static bool 
		is_used_as_depth_stencil_view(
			_HW_3D_IN_ Resource_info& info
		) {
		return (info.bind_flag & Resource_bind_flag::bit_type::depth_stencil) != Resource_bind_flag{};
	}

	static bool
		is_used_as_shader_resource_view(
			_HW_3D_IN_ Resource_info& info
		) {
		return (info.bind_flag & Resource_bind_flag::bit_type::shader_resource) != Resource_bind_flag{};
	}
};


_HW_3D_CLOSE_RS_NAMESPACE_

_HW_3D_CLOSE_HW_NAMESPACE_