#pragma once

#include "rs_hw_resource.hpp"

_HW_3D_OPEN_HW_NAMESPACE_
_HW_3D_OPEN_RS_NAMESPACE_

template <typename _Texture_desc, typename = _HW_3D_STD_ void_t<>>
struct _Has_member_sample_desc : _HW_3D_STD_ false_type {

};

template <typename _Texture_desc>
struct _Has_member_sample_desc<_Texture_desc, _HW_3D_STD_ void_t<decltype(_Texture_desc::_sample_desc)>> : _HW_3D_STD_ true_type {

};

template <typename _Texture_desc>
constexpr bool _has_member_sample_desc_v = _Has_member_sample_desc<_Texture_desc>::value;

template <typename _Metadata_type>
struct _D3d_texture_helper_base : _D3d_resource_helper_base<_Metadata_type> {
public:
	using Metadata_type = _Metadata_type;
	using _My_base = _D3d_resource_helper_base<_Metadata_type>;
public:
	static bool
		is_compressed(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		using _Fmt = _HW_3D_DXGI_ Format;
		switch (metadata.Format) {
		case _Fmt::bc1_typeless:
		case _Fmt::bc1_unorm:
		case _Fmt::bc1_unorm_srgb:
		case _Fmt::bc2_unorm:
		case _Fmt::bc2_unorm_srgb:
		case _Fmt::bc3_typeless:
		case _Fmt::bc3_unorm:
		case _Fmt::bc3_unorm_srgb:
		case _Fmt::bc4_typeless:
		case _Fmt::bc4_unorm:
		case _Fmt::bc4_snorm:
		case _Fmt::bc5_typeless:
		case _Fmt::bc5_unorm:
		case _Fmt::bc5_snorm:
		case _Fmt::bc6h_typess:
		case _Fmt::bc6h_uf16:
		case _Fmt::bc6h_sf16:
		case _Fmt::bc7_typeless:
		case _Fmt::bc7_unorm:
		case _Fmt::bc7_unorm_srgb:
			return true;
		default:
			return false;
		}
	}

	static _HW_3D_STD_ pair<uint32_t, uint32_t>
		pixel_size(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		using _Fmt = _HW_3D_DXGI_ Format;
		switch (metadata.Format) {
		case _Fmt::r32g32b32a32_typeless:
		case _Fmt::r32g32b32a32_float:
		case _Fmt::r32g32b32a32_int:
		case _Fmt::r32g32b32a32_uint:
			return { 1, 16 };
		case _Fmt::r32g32b32_typeless:
		case _Fmt::r32g32b32_float:
		case _Fmt::r32g32b32_int:
		case _Fmt::r32g32b32_uint:
			return { 1, 12 };
		case _Fmt::r16g16b16a16_typeless:
		case _Fmt::r16g16b16a16_float:
		case _Fmt::r16g16b16a16_unorm:
		case _Fmt::r16g16b16a16_uint:
		case _Fmt::r16g16b16a16_snorm:
		case _Fmt::r16g16b16a16_int:
		case _Fmt::r32g32_typeless:
		case _Fmt::r32g32_float:
		case _Fmt::r32g32_uint:
		case _Fmt::r32g32_int:
		case _Fmt::r32g8x24_typeless:
		case _Fmt::d32_float_s8x24_uint:
		case _Fmt::r32_float_x8x24_typeless:
		case _Fmt::x32_typeless_g8x24_uint:
			return { 1, 8 };
		case _Fmt::r10g10b10a2_typeless:
		case _Fmt::r10g10b10a2_unorm:
		case _Fmt::r10g10b10a2_uint:
		case _Fmt::r11g11b10_float:
		case _Fmt::r8g8b8a8_typeless:
		case _Fmt::r8g8b8a8_unorm:
		case _Fmt::r8g8b8a8_unorm_srgb:
		case _Fmt::r8g8b8a8_uint:
		case _Fmt::r8g8b8a8_snorm:
		case _Fmt::r8g8b8a8_int:
		case _Fmt::r16g16_typeless:
		case _Fmt::r16g16_float:
		case _Fmt::r16g16_unorm:
		case _Fmt::r16g16_uint:
		case _Fmt::r16g16_snorm:
		case _Fmt::r16g16_int:
		case _Fmt::r32_typeless:
		case _Fmt::d32_float:
		case _Fmt::r32_float:
		case _Fmt::r32_uint:
		case _Fmt::r32_int:
		case _Fmt::r24g8_typeless:
		case _Fmt::d24_unorm_s8_uint:
		case _Fmt::r24_unorm_x8_typeless:
		case _Fmt::x24_typeless_g8_uint:
		case _Fmt::r9g9b9e5_sharedexp:
		case _Fmt::b8g8r8a8_unorm:
		case _Fmt::b8g8r8x8_unorm:
		case _Fmt::r10g10b10_xr_bias_a2_unorm:
		case _Fmt::b8g8r8a8_typeless:
		case _Fmt::b8g8r8a8_unorm_srgb:
		case _Fmt::b8g8r8x8_unorm_srgb:
		case _Fmt::b8g8r8x8_typeless:
			return { 1, 4 };
		case _Fmt::r8g8_typeless:
		case _Fmt::r8g8_unorm:
		case _Fmt::r8g8_uint:
		case _Fmt::r8g8_snorm:
		case _Fmt::r8g8_int:
		case _Fmt::r16_typeless:
		case _Fmt::r16_float:
		case _Fmt::d16_unorm:
		case _Fmt::r16_unorm:
		case _Fmt::r16_uint:
		case _Fmt::r16_snorm:
		case _Fmt::r16_int:
		case _Fmt::b5g6r5_unorm:
		case _Fmt::b5g5r5a1_unorm:
			return { 1, 2 };
		case _Fmt::r8_typeless:
		case _Fmt::r8_unorm:
		case _Fmt::r8_int:
		case _Fmt::r8_uint:
		case _Fmt::r8_snorm:
		case _Fmt::a8_unorm:
			return { 1, 1 };
		case _Fmt::r1_unorm:
			return { 8, 1 };
		case _Fmt::r8g8_b8g8_unorm:
		case _Fmt::g8r8_g8b8_unorm:
			return { 2, 4 };
		case _Fmt::bc1_typeless:
		case _Fmt::bc1_unorm:
		case _Fmt::bc1_unorm_srgb:
		case _Fmt::bc4_snorm:
		case _Fmt::bc4_typeless:
		case _Fmt::bc4_unorm:
			return { 16, 8 };
		case _Fmt::bc2_typeless:
		case _Fmt::bc2_unorm:
		case _Fmt::bc2_unorm_srgb:
		case _Fmt::bc3_typeless:
		case _Fmt::bc3_unorm:
		case _Fmt::bc3_unorm_srgb:
		case _Fmt::bc5_snorm:
		case _Fmt::bc5_typeless:
		case _Fmt::bc5_unorm:
		case _Fmt::bc6h_sf16:
		case _Fmt::bc6h_typess:
		case _Fmt::bc6h_uf16:
		case _Fmt::bc7_typeless:
		case _Fmt::bc7_unorm:
		case _Fmt::bc7_unorm_srgb:
			return { 16, 16 };
		default:
			return { 0, 0 };
		}
	}

	static bool
		is_auto_generate_mipmaps(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return ((metadata.MiscFlags & Resource_misc_flag::bit_type::generate_mips) != Resource_misc_flag{} 
			&& ((metadata.BindFlags & Resource_bind_flag::bit_type::shader_resource) != Resource_bind_flag{} || 
				(metadata.BindFlags & Resource_bind_flag::bit_type::render_target) != Resource_bind_flag{}));
	}

	static bool
		is_multisample(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		if constexpr(_has_member_sample_desc_v<Metadata_type>) {
			return metadata.SampleDesc.Count != 1;
		}
		else {
			return false;
		}
	}

	static bool
		is_updatable_as_dst(
			_HW_3D_IN_ const Metadata_type& metadata
		) {
		return _My_base::is_updatable_as_dst(metadata) && !is_multisample(metadata);
	}
};

template <typename _Texture_type>
struct _D3d_texture_subresource {
	_Texture_type* texture;
	uint32_t mip_slice;
	uint32_t array_slice;
	uint32_t mip_levels;

	_D3d_texture_subresource(
		_HW_3D_IN_ _Texture_type* texture_ = nullptr,
		_HW_3D_IN_ uint32_t mip_slice_ = 0,
		_HW_3D_IN_ uint32_t array_slice_ = 0,
		_HW_3D_IN_ uint32_t mip_levels_ = 0
	) : texture(nullptr)
		, mip_slice(mip_slice_)
		, array_slice(array_slice_)
		, mip_levels(mip_levels_) {

	}

	explicit operator uint32_t() const {
		return _HW_3D_D3D_ calc_subresource(mip_slice, array_slice, mip_levels);
	}

	_D3d_texture_subresource(const _D3d_texture_subresource&) = default;
	_D3d_texture_subresource& operator=(const _D3d_texture_subresource&) = default;
};


_HW_3D_CLOSE_RS_NAMESPACE_
_HW_3D_CLOSE_HW_NAMESPACE_
