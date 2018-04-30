//#pragma once
//
//#include "rs_fwd.h"
//#include "rs_render_manager.h"
//#include "rs_hw_resource.hpp"
//
//_HW_3D_OPEN_HW_NAMESPACE_
//
//_HW_3D_OPEN_RS_NAMESPACE_
//
//
//
////
////
//struct Hardware_texture : Hardware_resource {
//	//format
//	static bool 
//		is_compressed(
//			_HW_3D_IN_ Pixel_format format
//		) {
//		switch (format) {
//		case Pixel_format::bc1_typeless:
//		case Pixel_format::bc1_unorm:
//		case Pixel_format::bc1_unorm_srgb:
//		case Pixel_format::bc2_unorm:
//		case Pixel_format::bc2_unorm_srgb:
//		case Pixel_format::bc3_typeless:
//		case Pixel_format::bc3_unorm:
//		case Pixel_format::bc3_unorm_srgb:
//		case Pixel_format::bc4_typeless:
//		case Pixel_format::bc4_unorm:
//		case Pixel_format::bc4_snorm:
//		case Pixel_format::bc5_typeless:
//		case Pixel_format::bc5_unorm:
//		case Pixel_format::bc5_snorm:
//		case Pixel_format::bc6h_typess:
//		case Pixel_format::bc6h_uf16:
//		case Pixel_format::bc6h_sf16:
//		case Pixel_format::bc7_typeless:
//		case Pixel_format::bc7_unorm:
//		case Pixel_format::bc7_unorm_srgb:
//			return true;
//		default:
//			return false;
//		}
//	}
//
//	static _HW_3D_STD_ pair<uint32_t, uint32_t> 
//		pixel_size(
//			_HW_3D_IN_ Pixel_format format
//		) {
//		switch (format) {
//		case Pixel_format::r32g32b32a32_typeless:
//		case Pixel_format::r32g32b32a32_float:
//		case Pixel_format::r32g32b32a32_int:
//		case Pixel_format::r32g32b32a32_uint:
//			return { 1, 16 };
//		case Pixel_format::r32g32b32_typeless:
//		case Pixel_format::r32g32b32_float:
//		case Pixel_format::r32g32b32_int:
//		case Pixel_format::r32g32b32_uint:
//			return { 1, 12 };
//		case Pixel_format::r16g16b16a16_typeless:
//		case Pixel_format::r16g16b16a16_float:
//		case Pixel_format::r16g16b16a16_unorm:
//		case Pixel_format::r16g16b16a16_uint:
//		case Pixel_format::r16g16b16a16_snorm:
//		case Pixel_format::r16g16b16a16_int:
//		case Pixel_format::r32g32_typeless:
//		case Pixel_format::r32g32_float:
//		case Pixel_format::r32g32_uint:
//		case Pixel_format::r32g32_int:
//		case Pixel_format::r32g8x24_typeless:
//		case Pixel_format::d32_float_s8x24_uint:
//		case Pixel_format::r32_float_x8x24_typeless:
//		case Pixel_format::x32_typeless_g8x24_uint:
//			return { 1, 8 };
//		case Pixel_format::r10g10b10a2_typeless:
//		case Pixel_format::r10g10b10a2_unorm:
//		case Pixel_format::r10g10b10a2_uint:
//		case Pixel_format::r11g11b10_float:
//		case Pixel_format::r8g8b8a8_typeless:
//		case Pixel_format::r8g8b8a8_unorm:
//		case Pixel_format::r8g8b8a8_unorm_srgb:
//		case Pixel_format::r8g8b8a8_uint:
//		case Pixel_format::r8g8b8a8_snorm:
//		case Pixel_format::r8g8b8a8_int:
//		case Pixel_format::r16g16_typeless:
//		case Pixel_format::r16g16_float:
//		case Pixel_format::r16g16_unorm:
//		case Pixel_format::r16g16_uint:
//		case Pixel_format::r16g16_snorm:
//		case Pixel_format::r16g16_int:
//		case Pixel_format::r32_typeless:
//		case Pixel_format::d32_float:
//		case Pixel_format::r32_float:
//		case Pixel_format::r32_uint:
//		case Pixel_format::r32_int:
//		case Pixel_format::r24g8_typeless:
//		case Pixel_format::d24_unorm_s8_uint:
//		case Pixel_format::r24_unorm_x8_typeless:
//		case Pixel_format::x24_typeless_g8_uint:
//		case Pixel_format::r9g9b9e5_sharedexp:
//		case Pixel_format::b8g8r8a8_unorm:
//		case Pixel_format::b8g8r8x8_unorm:
//		case Pixel_format::r10g10b10_xr_bias_a2_unorm:
//		case Pixel_format::b8g8r8a8_typeless:
//		case Pixel_format::b8g8r8a8_unorm_srgb:
//		case Pixel_format::b8g8r8x8_unorm_srgb:
//		case Pixel_format::b8g8r8x8_typeless:
//			return { 1, 4 };
//		case Pixel_format::r8g8_typeless:
//		case Pixel_format::r8g8_unorm:
//		case Pixel_format::r8g8_uint:
//		case Pixel_format::r8g8_snorm:
//		case Pixel_format::r8g8_int:
//		case Pixel_format::r16_typeless:
//		case Pixel_format::r16_float:
//		case Pixel_format::d16_unorm:
//		case Pixel_format::r16_unorm:
//		case Pixel_format::r16_uint:
//		case Pixel_format::r16_snorm:
//		case Pixel_format::r16_int:
//		case Pixel_format::b5g6r5_unorm:
//		case Pixel_format::b5g5r5a1_unorm:
//			return { 1, 2 };
//		case Pixel_format::r8_typeless:
//		case Pixel_format::r8_unorm:
//		case Pixel_format::r8_int:
//		case Pixel_format::r8_uint:
//		case Pixel_format::r8_snorm:
//		case Pixel_format::a8_unorm:
//			return { 1, 1 };
//		case Pixel_format::r1_unorm:
//			return { 8, 1 };
//		case Pixel_format::r8g8_b8g8_unorm:
//		case Pixel_format::g8r8_g8b8_unorm:
//			return { 2, 4 };
//		case Pixel_format::bc1_typeless:
//		case Pixel_format::bc1_unorm:
//		case Pixel_format::bc1_unorm_srgb:
//		case Pixel_format::bc4_snorm:
//		case Pixel_format::bc4_typeless:
//		case Pixel_format::bc4_unorm:
//			return { 16, 8 };
//		case Pixel_format::bc2_typeless:
//		case Pixel_format::bc2_unorm:
//		case Pixel_format::bc2_unorm_srgb:
//		case Pixel_format::bc3_typeless:
//		case Pixel_format::bc3_unorm:
//		case Pixel_format::bc3_unorm_srgb:
//		case Pixel_format::bc5_snorm:
//		case Pixel_format::bc5_typeless:
//		case Pixel_format::bc5_unorm:
//		case Pixel_format::bc6h_sf16:
//		case Pixel_format::bc6h_typess:
//		case Pixel_format::bc6h_uf16:
//		case Pixel_format::bc7_typeless:
//		case Pixel_format::bc7_unorm:
//		case Pixel_format::bc7_unorm_srgb:
//			return { 16, 16 };
//		default:
//			return { 0, 0 };
//		}
//	}
//
//	static bool
//		is_auto_generate_mipmaps(
//			_HW_3D_IN_ Resource_info& info
//		) {
//		return (info.misc_flag & Resource_misc_flag::bit_type::generate_mips) != Resource_misc_flag{};
//	}
//
//	static uint32_t
//		generate_mipmap_levels(
//			_HW_3D_IN_ uint32_t width,
//			_HW_3D_IN_ uint32_t height = 0,
//			_HW_3D_IN_ uint32_t depth = 0
//		);
//
//	static uint32_t
//		get_length_at_level(
//			_HW_3D_IN_ uint32_t length_in_level_0,
//			_HW_3D_IN_ uint32_t level
//		);
//
//	static uint32_t
//		get_level_size(
//			_HW_3D_IN_ Extent1d size,
//			_HW_3D_IN_ uint32_t level
//		);
//
//	static uint32_t
//		get_level_size(
//			_HW_3D_IN_ Extent2d size,
//			_HW_3D_IN_ uint32_t level
//		);
//
//	static uint32_t
//		get_level_size(
//			_HW_3D_IN_ Extent3d size,
//			_HW_3D_IN_ uint32_t level
//		);
//
//	static uint32_t
//		get_level_data_size(
//			_HW_3D_IN_ Extent1d size,
//			_HW_3D_IN_ uint32_t level,
//			_HW_3D_IN_ Pixel_format format
//		);
//
//	static uint32_t
//		get_level_data_size(
//			_HW_3D_IN_ Extent2d size,
//			_HW_3D_IN_ uint32_t level,
//			_HW_3D_IN_ Pixel_format format
//		);
//
//	static uint32_t
//		get_level_data_size(
//			_HW_3D_IN_ Extent3d size,
//			_HW_3D_IN_ uint32_t level,
//			_HW_3D_IN_ Pixel_format format
//		);
//};
//
////
////
//template <typename Texture_type>
//struct Texture_subresource {
//	static_assert(_HW_3D_STD_ is_base_of_v<Hardware_texture, Texture_type>);
//	
//	Texture_type* texture{ nullptr };
//	uint32_t mip_slice{ 0 };
//	uint32_t array_slice{ 0 };
//	uint32_t mip_levels{ 0 };
//
//	explicit operator uint32_t() const {
//		return _HW_3D_D3D_ calc_subresource(mip_slice, array_slice, mip_levels);
//	}
//
//	Texture_subresource() = default;
//	Texture_subresource(const Texture_subresource&) = default;
//	Texture_subresource& operator=(const Texture_subresource&) = default;
//};
//
////
////
//class Hardware_texture1d : Hardware_texture {
//public:
//	using Subresource_type = Texture_subresource<Hardware_texture1d>;
//	using Handle_type = _HW_3D_D3D_ ITexture1d;
//	using Native_handle_type = ID3D11Texture1D;
//	using Metadata = _HW_3D_D3D_ Texture1d_desc;
//public:
//	static _HW_3D_STD_ vector<_HW_3D_STD_ byte>
//		read(
//			_HW_3D_IN_ Subresource_type src,
//			_HW_3D_IN_ const Range1d& range
//		);
//
//	static _HW_3D_STD_ vector<_HW_3D_STD_ byte>
//		read_compressed_texture(
//			_HW_3D_IN_ Subresource_type src,
//			_HW_3D_IN_ const Range1d& range
//		);
//
//	static void
//		write(
//			_HW_3D_IN_ Subresource_type dst,
//			_HW_3D_IN_ const Range1d& range,
//			_HW_3D_IN_ const void* data,
//			_HW_3D_IN_ bool discard = false
//		);
//
//	static void
//		copy(
//			_HW_3D_IN_ Hardware_texture1d* dst,
//			_HW_3D_IN_ Hardware_texture1d* src
//		);
//
//	static void
//		copy(
//			_HW_3D_IN_ Subresource_type dst,
//			_HW_3D_IN_ Offset1d dst_offset,
//			_HW_3D_IN_ Subresource_type src,
//			_HW_3D_IN_ Offset1d src_offset,
//			_HW_3D_IN_ Extent1d size
//		);
//public:
//	Hardware_texture1d(
//		_HW_3D_IN_ const Metadata& desc,
//		_HW_3D_IN_ _HW_3D_D3D_ Subresource_data* data,
//		_HW_3D_IN_ Render_manager* render_manager
//	) : _desc(desc)
//		, _render_manager(render_manager) {
//		auto[success, texture] = _render_manager->device()->create_texture_1d(_desc, data);
//
//		_HW_3D_RS_ASSERT_D3DCALL_SUCCESS_(success, "failed to create texture");
//
//		_texture = _HW_3D_STD_ move(texture);
//	}
//
//	Handle_type*
//		handle() const;
//
//	Native_handle_type*
//		native_handle() const;
//
//	uint32_t
//		width() const;
//
//	uint32_t
//		mip_levels() const;
//
//	uint32_t
//		array_size() const;
//
//	Pixel_format
//		format() const;
//
//	Resource_usage
//		usage() const;
//
//	Resource_cpu_access_flag
//		cpu_access_flag() const;
//
//	Resource_misc_flag
//		misc_flag() const;
//
//	Resource_bind_flag
//		bind_flag() const;
//
//	_HW_3D_STD_ vector<_HW_3D_STD_ byte>
//		read(
//			_HW_3D_IN_ uint32_t level,
//			_HW_3D_IN_ uint32_t array_index,
//			_HW_3D_IN_ const Range1d& range
//		);
//
//	void
//		write(
//			_HW_3D_IN_ uint32_t level,
//			_HW_3D_IN_ uint32_t array_index,
//			_HW_3D_IN_ const Range1d& range,
//			_HW_3D_IN_ const void* data,
//			_HW_3D_IN_ bool discard = false
//		);
//
//	void
//		copy(
//			_HW_3D_IN_ Hardware_texture1d* src_texture
//		);
//
//	void
//		copy(
//			_HW_3D_IN_ uint32_t level,
//			_HW_3D_IN_ uint32_t array_index,
//			_HW_3D_IN_ Offset1d offset,
//			_HW_3D_IN_ Subresource_type src_resource,
//			_HW_3D_IN_ Offset1d src_offset,
//			_HW_3D_IN_ Extent1d size
//		);
//
//	void
//		generate_mipmaps();
//private:
//	_HW_3D_STD_ unique_ptr<Handle_type> _texture;
//	Metadata _desc;
//	Render_manager* const _render_manager;
//};
//
////
////
//class Hardware_texture1d_builder {
//public:
//	Hardware_texture1d_builder();
//
//	~Hardware_texture1d_builder();
//
//	Hardware_texture1d_builder&
//		set_width(
//			_HW_3D_IN_ uint32_t width
//		);
//
//	Hardware_texture1d_builder&
//		set_mip_levels(
//			_HW_3D_IN_ uint32_t level
//		);
//
//	Hardware_texture1d_builder&
//		set_array_size(
//			_HW_3D_IN_ uint32_t array_size
//		);
//
//	Hardware_texture1d_builder&
//		set_pixel_format(
//			_HW_3D_IN_ Pixel_format format
//		);
//
//	Hardware_texture1d_builder&
//		set_resource_usage(
//			_HW_3D_IN_ Resource_usage usage
//		);
//
//	Hardware_texture1d_builder&
//		set_cpu_access_flag(
//			_HW_3D_IN_ Resource_cpu_access_flag flags
//		);
//
//	Hardware_texture1d_builder&
//		set_bind_flag(
//			_HW_3D_IN_ Resource_bind_flag flags
//		);
//
//	Hardware_texture1d_builder&
//		set_misc_flag(
//			_HW_3D_IN_ Resource_misc_flag flags
//		);
//
//	Hardware_texture1d_builder&
//		set_texture_initial_data(
//			_HW_3D_IN_ const void* sys_mem,
//			_HW_3D_IN_ uint32_t row_pitch = 0
//		);
//
//private:
//	Metadata_t<Hardware_texture1d> _desc;
//	_HW_3D_D3D_ Subresource_data _initial_data;
//};
//
////
////
//class Hardware_texture2d : Hardware_texture {
//public:
//	using Subresource_type = Texture_subresource<Hardware_texture2d>;
//	using Handle_type = _HW_3D_D3D_ ITexture2d;
//	using Native_handle_type = ID3D11Texture2D;
//	using Metadata = _HW_3D_D3D_ Texture2d_desc;
//public:
//	static _HW_3D_STD_ vector<_HW_3D_STD_ byte>
//		read(
//			_HW_3D_IN_ Subresource_type src,
//			_HW_3D_IN_ const Range2d& range
//		);
//
//	static _HW_3D_STD_ vector<_HW_3D_STD_ byte>
//		read_compressed_texture(
//			_HW_3D_IN_ Subresource_type src,
//			_HW_3D_IN_ const Range2d& range
//		);
//
//	static void
//		write(
//			_HW_3D_IN_ Subresource_type dst,
//			_HW_3D_IN_ const Range2d& range,
//			_HW_3D_IN_ const void* data,
//			_HW_3D_IN_ uint32_t row_pitch,
//			_HW_3D_IN_ bool discard = false
//		);
//
//	static void
//		copy(
//			_HW_3D_IN_ Hardware_texture2d* dst,
//			_HW_3D_IN_ Hardware_texture2d* src
//		);
//
//	static void
//		copy(
//			_HW_3D_IN_ Subresource_type dst,
//			_HW_3D_IN_ Offset2d dst_offset,
//			_HW_3D_IN_ Subresource_type src,
//			_HW_3D_IN_ Offset2d src_offset,
//			_HW_3D_IN_ Extent2d size
//		);
//public:
//	Hardware_texture2d(
//		_HW_3D_IN_ const Metadata& desc,
//		_HW_3D_IN_ _HW_3D_D3D_ Subresource_data* data,
//		_HW_3D_IN_ Render_manager* render_manager
//	);
//
//	Handle_type*
//		handle() const;
//
//	Native_handle_type*
//		native_handle() const;
//
//	uint32_t
//		width() const;
//
//	uint32_t
//		height() const;
//
//	uint32_t
//		mip_levels() const;
//
//	uint32_t
//		array_size() const;
//
//	Pixel_format
//		format() const;
//
//	uint32_t
//		sample_count() const;
//
//	uint32_t
//		sample_quality() const;
//
//	bool
//		is_multisample() const;
//
//	Resource_usage
//		usage() const;
//
//	Resource_cpu_access_flag
//		cpu_access_flag() const;
//
//	Resource_misc_flag
//		misc_flag() const;
//
//	Resour
//
//
//};
//
//
//_HW_3D_CLOSE_RS_NAMESPACE_
//
//_HW_3D_CLOSE_HW_NAMESPACE_