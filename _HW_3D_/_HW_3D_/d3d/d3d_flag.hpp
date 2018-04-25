#pragma once

#include "d3d_fwd.h"
#include "../utils.hpp"

_HW_3D_OPEN_HW_NAMESPACE_

_HW_3D_OPEN_DXGI_NAMESPACE_
//
//
enum class Display_mode_bit {
	interlaced = DXGI_ENUM_MODES_INTERLACED,
	scaling = DXGI_ENUM_MODES_SCALING,
	stereo = DXGI_ENUM_MODES_STEREO,
	disabeld_stereo = DXGI_ENUM_MODES_DISABLED_STEREO,
};
_HW_3D_HW_FLAG_TYPE_(Display_mode, Display_mode_bit);

//
//
enum class Present_mode_bit {
	test = DXGI_PRESENT_TEST,
	do_not_sequence = DXGI_PRESENT_DO_NOT_SEQUENCE,
	restart = DXGI_PRESENT_RESTART,
	do_not_wait = DXGI_PRESENT_DO_NOT_WAIT,
	stereo_prefer_right = DXGI_PRESENT_STEREO_PREFER_RIGHT,
	stereo_temporary_mono = DXGI_PRESENT_STEREO_TEMPORARY_MONO,
	restrict_to_output = DXGI_PRESENT_RESTRICT_TO_OUTPUT,
	use_duration = DXGI_PRESENT_USE_DURATION,
	allow_tearing = DXGI_PRESENT_ALLOW_TEARING,
};
_HW_3D_HW_FLAG_TYPE_(Present_mode, Present_mode_bit);

//
//
enum class Adapter_flag_bit : Underlying_type_t<DXGI_ADAPTER_FLAG> {
	none = DXGI_ADAPTER_FLAG::DXGI_ADAPTER_FLAG_NONE,
	remote = DXGI_ADAPTER_FLAG::DXGI_ADAPTER_FLAG_REMOTE,
	software = DXGI_ADAPTER_FLAG::DXGI_ADAPTER_FLAG_SOFTWARE,
};
_HW_3D_HW_FLAG_TYPE_(Adapter_flag, Adapter_flag_bit);

//
//
enum class Adapter_flag3_bit : Underlying_type_t<DXGI_ADAPTER_FLAG3> {
	none = DXGI_ADAPTER_FLAG3::DXGI_ADAPTER_FLAG3_NONE,
	remote = DXGI_ADAPTER_FLAG3::DXGI_ADAPTER_FLAG3_REMOTE,
	software = DXGI_ADAPTER_FLAG3::DXGI_ADAPTER_FLAG3_SOFTWARE,
	acg_compatible = DXGI_ADAPTER_FLAG3::DXGI_ADAPTER_FLAG3_ACG_COMPATIBLE,
	support_monitored_fences = DXGI_ADAPTER_FLAG3::DXGI_ADAPTER_FLAG3_SUPPORT_MONITORED_FENCES,
	suuport_non_monitored_fences = DXGI_ADAPTER_FLAG3::DXGI_ADAPTER_FLAG3_SUPPORT_NON_MONITORED_FENCES,
	keyed_mutex_conformance = DXGI_ADAPTER_FLAG3::DXGI_ADAPTER_FLAG3_KEYED_MUTEX_CONFORMANCE,
};
_HW_3D_HW_FLAG_TYPE_(Adapter_flag3, Adapter_flag3_bit);

//
//
enum class Debug_rlo_flag_bit : Underlying_type_t<DXGI_DEBUG_RLO_FLAGS> {
	summary = DXGI_DEBUG_RLO_FLAGS::DXGI_DEBUG_RLO_SUMMARY,
	detail = DXGI_DEBUG_RLO_FLAGS::DXGI_DEBUG_RLO_DETAIL,
	ignore_internal = DXGI_DEBUG_RLO_FLAGS::DXGI_DEBUG_RLO_IGNORE_INTERNAL,
	all = DXGI_DEBUG_RLO_FLAGS::DXGI_DEBUG_RLO_ALL,
};
_HW_3D_HW_FLAG_TYPE_(Debug_rlo_flag, Debug_rlo_flag_bit);


//
//
enum class Multiplane_overlay_ycbcr_flag_bit : Underlying_type_t<DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS> {
	nominal_range = DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS::DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_NOMINAL_RANGE,
	bt709 = DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS::DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_BT709,
	xvycc = DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS::DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAG_xvYCC,
};
_HW_3D_HW_FLAG_TYPE_(Multiplane_overlay_ycbcr_flag, Multiplane_overlay_ycbcr_flag_bit);

//
//
enum class Offer_resource_flag_bit : Underlying_type_t<DXGI_OFFER_RESOURCE_FLAGS> {
	allow_decommit = DXGI_OFFER_RESOURCE_FLAGS::DXGI_OFFER_RESOURCE_FLAG_ALLOW_DECOMMIT,
};
_HW_3D_HW_FLAG_TYPE_(Offer_resource_flag, Offer_resource_flag_bit);

//
//
enum class Overlay_color_space_support_flag_bit : Underlying_type_t<DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG> {
	present = DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG::DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG_PRESENT,
};
_HW_3D_HW_FLAG_TYPE_(Overlay_color_space_support_flag, Overlay_color_space_support_flag_bit);

//
//
enum class Overlay_support_flag_bit : Underlying_type_t<DXGI_OVERLAY_SUPPORT_FLAG> {
	direct = DXGI_OVERLAY_SUPPORT_FLAG::DXGI_OVERLAY_SUPPORT_FLAG_DIRECT,
	scaling = DXGI_OVERLAY_SUPPORT_FLAG::DXGI_OVERLAY_SUPPORT_FLAG_SCALING,
};
_HW_3D_HW_FLAG_TYPE_(Overlay_support_flag, Overlay_support_flag_bit);

//
//
enum class Swap_chain_color_space_support_flag_bit : Underlying_type_t<DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG> {
	present = DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG::DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_PRESENT,
	overlay_present = DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG::DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_OVERLAY_PRESENT,
};
_HW_3D_HW_FLAG_TYPE_(Swap_chain_color_space_support_flag, Swap_chain_color_space_support_flag_bit);

//
//
enum class Swap_chain_flag_bit : Underlying_type_t<DXGI_SWAP_CHAIN_FLAG> {
	nonprerotated = DXGI_SWAP_CHAIN_FLAG::DXGI_SWAP_CHAIN_FLAG_NONPREROTATED,
	allow_mode_switch = DXGI_SWAP_CHAIN_FLAG::DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH,
	gdi_compatible = DXGI_SWAP_CHAIN_FLAG::DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE,
	restricted_content = DXGI_SWAP_CHAIN_FLAG::DXGI_SWAP_CHAIN_FLAG_RESTRICTED_CONTENT,
	restrict_shared_resource_driver = DXGI_SWAP_CHAIN_FLAG::DXGI_SWAP_CHAIN_FLAG_RESTRICT_SHARED_RESOURCE_DRIVER,
	display_only = DXGI_SWAP_CHAIN_FLAG::DXGI_SWAP_CHAIN_FLAG_DISPLAY_ONLY,
	frame_latency_waitbable_object = DXGI_SWAP_CHAIN_FLAG::DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT,
	foreground_layer = DXGI_SWAP_CHAIN_FLAG::DXGI_SWAP_CHAIN_FLAG_FOREGROUND_LAYER,
	fullscreen_video = DXGI_SWAP_CHAIN_FLAG::DXGI_SWAP_CHAIN_FLAG_FULLSCREEN_VIDEO,
	yuv_video = DXGI_SWAP_CHAIN_FLAG::DXGI_SWAP_CHAIN_FLAG_YUV_VIDEO,
	hw_protected = DXGI_SWAP_CHAIN_FLAG::DXGI_SWAP_CHAIN_FLAG_HW_PROTECTED,
	allow_tearing = DXGI_SWAP_CHAIN_FLAG::DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING,
	restricted_to_all_holographic_displays = DXGI_SWAP_CHAIN_FLAG::DXGI_SWAP_CHAIN_FLAG_RESTRICTED_TO_ALL_HOLOGRAPHIC_DISPLAYS,
};
_HW_3D_HW_FLAG_TYPE_(Swap_chain_flag, Swap_chain_flag_bit);

//
//
enum class Map_flag_bit {
	read = DXGI_MAP_READ,
	write = DXGI_MAP_WRITE,
	discard = DXGI_MAP_DISCARD
};
_HW_3D_HW_FLAG_TYPE_(Map_flag, Map_flag_bit);


//
//
enum class Usage_bit : Underlying_type_t<DXGI_USAGE> {
	shader_input = DXGI_USAGE_SHADER_INPUT,
	render_target_output = DXGI_USAGE_RENDER_TARGET_OUTPUT,
	back_buffer = DXGI_USAGE_BACK_BUFFER,
	shared = DXGI_USAGE_SHARED,
	read_only = DXGI_USAGE_READ_ONLY,
	discard_on_present = DXGI_USAGE_DISCARD_ON_PRESENT,
	unordered_access = DXGI_USAGE_UNORDERED_ACCESS,
};
_HW_3D_HW_FLAG_TYPE_(Usage, Usage_bit);

_HW_3D_CLOSE_DXGI_NAMESPACE_

_HW_3D_OPEN_D3D_NAMESPACE_

//
//
enum class Async_get_data_flag_bit : Underlying_type_t<D3D11_ASYNC_GETDATA_FLAG> {
	donoflush = D3D11_ASYNC_GETDATA_FLAG::D3D11_ASYNC_GETDATA_DONOTFLUSH
};
_HW_3D_HW_FLAG_TYPE_(Async_get_data_flag, Async_get_data_flag_bit);

//
//
enum class Clear_flag_bit : Underlying_type_t<D3D11_CLEAR_FLAG> {
	depth = D3D11_CLEAR_FLAG::D3D11_CLEAR_DEPTH,
	stencil = D3D11_CLEAR_FLAG::D3D11_CLEAR_STENCIL,
};
_HW_3D_HW_FLAG_TYPE_(Clear_flag, Clear_flag_bit);

//
//
enum class Color_write_mask_bit : Underlying_type_t<D3D11_COLOR_WRITE_ENABLE> {
	red = D3D11_COLOR_WRITE_ENABLE::D3D11_COLOR_WRITE_ENABLE_RED,
	green = D3D11_COLOR_WRITE_ENABLE::D3D11_COLOR_WRITE_ENABLE_GREEN,
	blue = D3D11_COLOR_WRITE_ENABLE::D3D11_COLOR_WRITE_ENABLE_BLUE,
	alpha = D3D11_COLOR_WRITE_ENABLE::D3D11_COLOR_WRITE_ENABLE_ALPHA,
	all = D3D11_COLOR_WRITE_ENABLE::D3D11_COLOR_WRITE_ENABLE_ALL,
};
_HW_3D_HW_FLAG_TYPE_(Color_write_mask, Color_write_mask_bit);

//
//
enum class Copy_flag_bit : Underlying_type_t<D3D11_COPY_FLAGS> {
	no_overwrite = D3D11_COPY_FLAGS::D3D11_COPY_NO_OVERWRITE,
	discard = D3D11_COPY_FLAGS::D3D11_COPY_DISCARD,
};
_HW_3D_HW_FLAG_TYPE_(Copy_flag, Copy_flag_bit);

//
//
enum class Create_device_flag_bit : Underlying_type_t<D3D11_CREATE_DEVICE_FLAG> {
	single_threaded = D3D11_CREATE_DEVICE_FLAG::D3D11_CREATE_DEVICE_SINGLETHREADED,
	debug = D3D11_CREATE_DEVICE_FLAG::D3D11_CREATE_DEVICE_DEBUG,
	//switch_to_ref = D3D11_CREATE_DEVICE_FLAG::D3D11_CREATE_DEVICE_SWITCH_TO_REF
	prevent_internal_threading_optimizations = D3D11_CREATE_DEVICE_FLAG::D3D11_CREATE_DEVICE_PREVENT_INTERNAL_THREADING_OPTIMIZATIONS,
	bgra_support = D3D11_CREATE_DEVICE_FLAG::D3D11_CREATE_DEVICE_BGRA_SUPPORT,
	debuggable = D3D11_CREATE_DEVICE_FLAG::D3D11_CREATE_DEVICE_DEBUGGABLE,
	prevernt_altering_layer_settings_from_registry = D3D11_CREATE_DEVICE_FLAG::D3D11_CREATE_DEVICE_PREVENT_ALTERING_LAYER_SETTINGS_FROM_REGISTRY,
	disable_gpu_timeout = D3D11_CREATE_DEVICE_FLAG::D3D11_CREATE_DEVICE_DISABLE_GPU_TIMEOUT,
	video_support = D3D11_CREATE_DEVICE_FLAG::D3D11_CREATE_DEVICE_VIDEO_SUPPORT,
};
_HW_3D_HW_FLAG_TYPE_(Create_device_flag, Create_device_flag_bit);

//
//
enum class Create_device_context_state_flag_bit : Underlying_type_t<D3D11_1_CREATE_DEVICE_CONTEXT_STATE_FLAG> {
	single_threaded = D3D11_1_CREATE_DEVICE_CONTEXT_STATE_FLAG::D3D11_1_CREATE_DEVICE_CONTEXT_STATE_SINGLETHREADED
};
_HW_3D_HW_FLAG_TYPE_(Create_device_context_state_flag, Create_device_context_state_flag_bit);

//
//
enum class Fence_flag_bit : Underlying_type_t<D3D11_FENCE_FLAG> {
	none = D3D11_FENCE_FLAG::D3D11_FENCE_FLAG_NONE,
	shared = D3D11_FENCE_FLAG::D3D11_FENCE_FLAG_SHARED,
	shared_cross_adapter = D3D11_FENCE_FLAG::D3D11_FENCE_FLAG_SHARED_CROSS_ADAPTER,
};
_HW_3D_HW_FLAG_TYPE_(Fence_flag, Fence_flag_bit);

//
//
enum class Format_support_bit : Underlying_type_t<D3D11_FORMAT_SUPPORT> {
	buffer = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_BUFFER,
	ia_vertex_buffer = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_IA_VERTEX_BUFFER,
	ia_index_buffer = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_IA_INDEX_BUFFER,
	so_buffer = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_SO_BUFFER,
	texture_1d = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_TEXTURE1D,
	texture_2d = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_TEXTURE2D,
	texture_3d = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_TEXTURE3D,
	texture_cube = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_TEXTURECUBE,
	shader_load = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_SHADER_LOAD,
	shader_sample = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_SHADER_SAMPLE,
	shader_sample_comparison = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_SHADER_SAMPLE_COMPARISON,
	shader_sample_mono_text = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_SHADER_SAMPLE_MONO_TEXT,
	mip = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_MIP,
	mip_autogen = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_MIP_AUTOGEN,
	render_target = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_RENDER_TARGET,
	blendable = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_BLENDABLE,
	depth_stencil = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_DEPTH_STENCIL,
	cpu_lockable = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_CPU_LOCKABLE,
	multisample_resolve = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_MULTISAMPLE_RESOLVE,
	display = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_DISPLAY,
	cast_within_bit_layout = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_CAST_WITHIN_BIT_LAYOUT,
	multisample_rendertarget = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_MULTISAMPLE_RENDERTARGET,
	multisample_load = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_MULTISAMPLE_LOAD,
	shader_gather = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_SHADER_GATHER,
	back_buffer_cast = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_BACK_BUFFER_CAST,
	unordered_access_view = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_TYPED_UNORDERED_ACCESS_VIEW,
	shader_gather_comparision = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_SHADER_GATHER_COMPARISON,
	decoder_output = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_DECODER_OUTPUT,
	video_processor_output = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_VIDEO_PROCESSOR_OUTPUT,
	video_processor_input = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_VIDEO_PROCESSOR_INPUT,
	video_encoder = D3D11_FORMAT_SUPPORT::D3D11_FORMAT_SUPPORT_VIDEO_ENCODER,
};
_HW_3D_HW_FLAG_TYPE_(Format_support, Format_support_bit);

//
//
enum class Format_support2_bit : Underlying_type_t<D3D11_FORMAT_SUPPORT2> {
	uav_atomic_add = D3D11_FORMAT_SUPPORT2::D3D11_FORMAT_SUPPORT2_UAV_ATOMIC_ADD,
	uav_atomic_bitwise_ops = D3D11_FORMAT_SUPPORT2::D3D11_FORMAT_SUPPORT2_UAV_ATOMIC_BITWISE_OPS,
	uav_atomic_compare_store_or_compare_exchange = D3D11_FORMAT_SUPPORT2::D3D11_FORMAT_SUPPORT2_UAV_ATOMIC_COMPARE_STORE_OR_COMPARE_EXCHANGE,
	uav_atomic_exchange = D3D11_FORMAT_SUPPORT2::D3D11_FORMAT_SUPPORT2_UAV_ATOMIC_EXCHANGE,
	uav_atomic_signed_min_or_max = D3D11_FORMAT_SUPPORT2::D3D11_FORMAT_SUPPORT2_UAV_ATOMIC_SIGNED_MIN_OR_MAX,
	uav_atomic_unsigned_min_or_max = D3D11_FORMAT_SUPPORT2::D3D11_FORMAT_SUPPORT2_UAV_ATOMIC_UNSIGNED_MIN_OR_MAX,
	uav_typed_load = D3D11_FORMAT_SUPPORT2::D3D11_FORMAT_SUPPORT2_UAV_TYPED_LOAD,
	uav_typed_store = D3D11_FORMAT_SUPPORT2::D3D11_FORMAT_SUPPORT2_UAV_TYPED_STORE,
	output_merger_logic_op = D3D11_FORMAT_SUPPORT2::D3D11_FORMAT_SUPPORT2_OUTPUT_MERGER_LOGIC_OP,
	tiled = D3D11_FORMAT_SUPPORT2::D3D11_FORMAT_SUPPORT2_TILED,
	shareable = D3D11_FORMAT_SUPPORT2::D3D11_FORMAT_SUPPORT2_SHAREABLE,
	multiplane_overlay = D3D11_FORMAT_SUPPORT2::D3D11_FORMAT_SUPPORT2_MULTIPLANE_OVERLAY,
};
_HW_3D_HW_FLAG_TYPE_(Format_support2, Format_support2_bit);

//
//
enum class Query_misc_flag_bit : Underlying_type_t<D3D11_QUERY_MISC_FLAG> {
	predicate = D3D11_QUERY_MISC_FLAG::D3D11_QUERY_MISC_PREDICATEHINT,
};
_HW_3D_HW_FLAG_TYPE_(Query_misc_flag, Query_misc_flag_bit);

//
//
enum class Raise_flag_bit : Underlying_type_t<D3D11_RAISE_FLAG> {
	driver_internal_error = D3D11_RAISE_FLAG::D3D11_RAISE_FLAG_DRIVER_INTERNAL_ERROR,
};
_HW_3D_HW_FLAG_TYPE_(Raise_flag, Raise_flag_bit);

//
//
enum class Shader_cache_support_flag_bit : Underlying_type_t<D3D11_SHADER_CACHE_SUPPORT_FLAGS> {
	none = D3D11_SHADER_CACHE_SUPPORT_FLAGS::D3D11_SHADER_CACHE_SUPPORT_NONE,
	automatic_inproc_cache = D3D11_SHADER_CACHE_SUPPORT_FLAGS::D3D11_SHADER_CACHE_SUPPORT_AUTOMATIC_INPROC_CACHE,
	automatic_disk_cache = D3D11_SHADER_CACHE_SUPPORT_FLAGS::D3D11_SHADER_CACHE_SUPPORT_AUTOMATIC_DISK_CACHE,
};
_HW_3D_HW_FLAG_TYPE_(Shader_cache_support_flag, Shader_cache_support_flag_bit);

//
//
enum class Counter_bit : Underlying_type_t<D3D11_COUNTER> {
	device_dependent = D3D11_COUNTER::D3D11_COUNTER_DEVICE_DEPENDENT_0,
};
_HW_3D_HW_FLAG_TYPE_(Counter, Counter_bit);

//
//
enum class Rldo_flag_bit : Underlying_type_t<D3D11_RLDO_FLAGS> {
	summary = D3D11_RLDO_FLAGS::D3D11_RLDO_SUMMARY,
	detail = D3D11_RLDO_FLAGS::D3D11_RLDO_DETAIL,
	ignore_interanl = D3D11_RLDO_FLAGS::D3D11_RLDO_IGNORE_INTERNAL,
};
_HW_3D_HW_FLAG_TYPE_(Rldo_flag, Rldo_flag_bit);

//
//
enum class Shader_tracking_option_bit : Underlying_type_t<D3D11_SHADER_TRACKING_OPTION> {
	ignore = D3D11_SHADER_TRACKING_OPTION::D3D11_SHADER_TRACKING_OPTION_IGNORE,
	track_uninitialized = D3D11_SHADER_TRACKING_OPTION::D3D11_SHADER_TRACKING_OPTION_TRACK_UNINITIALIZED,
	track_raw = D3D11_SHADER_TRACKING_OPTION::D3D11_SHADER_TRACKING_OPTION_TRACK_RAW,
	track_war = D3D11_SHADER_TRACKING_OPTION::D3D11_SHADER_TRACKING_OPTION_TRACK_WAR,
	track_waw = D3D11_SHADER_TRACKING_OPTION::D3D11_SHADER_TRACKING_OPTION_TRACK_WAW,
	allow_same = D3D11_SHADER_TRACKING_OPTION::D3D11_SHADER_TRACKING_OPTION_ALLOW_SAME,
	track_atomic_consistency = D3D11_SHADER_TRACKING_OPTION::D3D11_SHADER_TRACKING_OPTION_TRACK_ATOMIC_CONSISTENCY,
	track_raw_across_threadgroups = D3D11_SHADER_TRACKING_OPTION::D3D11_SHADER_TRACKING_OPTION_TRACK_RAW_ACROSS_THREADGROUPS,
	track_war_across_threadgroups = D3D11_SHADER_TRACKING_OPTION::D3D11_SHADER_TRACKING_OPTION_TRACK_WAR_ACROSS_THREADGROUPS,
	track_waw_across_threadgroups = D3D11_SHADER_TRACKING_OPTION::D3D11_SHADER_TRACKING_OPTION_TRACK_WAW_ACROSS_THREADGROUPS,
	track_atomic_consistency_across_threadgroups = D3D11_SHADER_TRACKING_OPTION::D3D11_SHADER_TRACKING_OPTION_TRACK_ATOMIC_CONSISTENCY_ACROSS_THREADGROUPS,
	uav_specific_flags = D3D11_SHADER_TRACKING_OPTION::D3D11_SHADER_TRACKING_OPTION_UAV_SPECIFIC_FLAGS,
	all_hazards = D3D11_SHADER_TRACKING_OPTION::D3D11_SHADER_TRACKING_OPTION_ALL_HAZARDS,
	all_hazards_allow_same = D3D11_SHADER_TRACKING_OPTION::D3D11_SHADER_TRACKING_OPTION_ALL_HAZARDS_ALLOWING_SAME,
	all_options = D3D11_SHADER_TRACKING_OPTION::D3D11_SHADER_TRACKING_OPTION_ALL_OPTIONS,
};
_HW_3D_HW_FLAG_TYPE_(Shader_tracking_option, Shader_tracking_option_bit);

//
//
enum class Bind_flag_bit : Underlying_type_t<D3D11_BIND_FLAG> {
	vertex_buffer = D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER,
	index_buffer = D3D11_BIND_FLAG::D3D11_BIND_INDEX_BUFFER,
	constant_buffer = D3D11_BIND_FLAG::D3D11_BIND_CONSTANT_BUFFER,
	shader_resource = D3D11_BIND_FLAG::D3D11_BIND_SHADER_RESOURCE,
	stream_output = D3D11_BIND_FLAG::D3D11_BIND_STREAM_OUTPUT,
	render_target = D3D11_BIND_FLAG::D3D11_BIND_RENDER_TARGET,
	depth_stencil = D3D11_BIND_FLAG::D3D11_BIND_DEPTH_STENCIL,
	unordered_access = D3D11_BIND_FLAG::D3D11_BIND_UNORDERED_ACCESS,
	decoder = D3D11_BIND_FLAG::D3D11_BIND_DECODER,
	video_encoder = D3D11_BIND_FLAG::D3D11_BIND_VIDEO_ENCODER,
};
_HW_3D_HW_FLAG_TYPE_(Bind_flag, Bind_flag_bit);

//
//
enum class Buffer_ex_srv_flag_bit : Underlying_type_t<D3D11_BUFFEREX_SRV_FLAG> {
	raw = D3D11_BUFFEREX_SRV_FLAG::D3D11_BUFFEREX_SRV_FLAG_RAW,
};
_HW_3D_HW_FLAG_TYPE_(Buffer_ex_srv_flag, Buffer_ex_srv_flag_bit);

//
//
enum class Buffer_uav_flag_bit : Underlying_type_t<D3D11_BUFFER_UAV_FLAG> {
	raw = D3D11_BUFFER_UAV_FLAG::D3D11_BUFFER_UAV_FLAG_RAW,
	append = D3D11_BUFFER_UAV_FLAG::D3D11_BUFFER_UAV_FLAG_APPEND,
	counter = D3D11_BUFFER_UAV_FLAG::D3D11_BUFFER_UAV_FLAG_COUNTER,
};
_HW_3D_HW_FLAG_TYPE_(Buffer_uav_flag, Buffer_uav_flag_bit);

//
//
enum class Check_multisample_quality_levels_flag_bit : Underlying_type_t<D3D11_CHECK_MULTISAMPLE_QUALITY_LEVELS_FLAG> {
	tiled_resource = D3D11_CHECK_MULTISAMPLE_QUALITY_LEVELS_FLAG::D3D11_CHECK_MULTISAMPLE_QUALITY_LEVELS_TILED_RESOURCE,
};
_HW_3D_HW_FLAG_TYPE_(Check_multisample_quality_levels_flag, Check_multisample_quality_levels_flag_bit);

//
//
enum class Cpu_access_flag_bit : Underlying_type_t<D3D11_CPU_ACCESS_FLAG> {
	write = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE,
	read = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_READ,
};
_HW_3D_HW_FLAG_TYPE_(Cpu_access_flag, Cpu_access_flag_bit);

//
//
enum class Dsv_flag_bit : Underlying_type_t<D3D11_DSV_FLAG> {
	depth = D3D11_DSV_FLAG::D3D11_DSV_READ_ONLY_DEPTH,
	stencil = D3D11_DSV_FLAG::D3D11_DSV_READ_ONLY_STENCIL,
};
_HW_3D_HW_FLAG_TYPE_(Dsv_flag, Dsv_flag_bit);

//
//
enum class Map_flag_bit : Underlying_type_t<D3D11_MAP_FLAG> {
	do_not_wait = D3D11_MAP_FLAG::D3D11_MAP_FLAG_DO_NOT_WAIT,
};
_HW_3D_HW_FLAG_TYPE_(Map_flag, Map_flag_bit);

//
//
enum class Resource_misc_flag_bit : Underlying_type_t<D3D11_RESOURCE_MISC_FLAG> {
	generate_mips = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_GENERATE_MIPS,
	shared = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_SHARED,
	texturecube = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_TEXTURECUBE,
	drawindirect_args = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_DRAWINDIRECT_ARGS,
	buffer_allow_raw_views = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_BUFFER_ALLOW_RAW_VIEWS,
	buffer_structured = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_BUFFER_STRUCTURED,
	resource_clamp = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_RESOURCE_CLAMP,
	shared_keyedmutex = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX,
	gdi_compatible = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_GDI_COMPATIBLE,
	shared_nthandle = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_SHARED_NTHANDLE,
	restricted_content = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_RESTRICTED_CONTENT,
	restrict_shared_resource = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE,
	restrict_shared_resource_driver = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE_DRIVER,
	guarded = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_GUARDED,
	tile_pool = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_TILE_POOL,
	tiled = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_TILED,
	hw_protected = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_HW_PROTECTED,
};
_HW_3D_HW_FLAG_TYPE_(Resource_misc_flag, Resource_misc_flag_bit);

//
//
enum class Tile_copy_flag_bit : Underlying_type_t<D3D11_TILE_COPY_FLAG> {
	no_overwrite = D3D11_TILE_COPY_FLAG::D3D11_TILE_COPY_NO_OVERWRITE,
	linear_buffer_to_swizzled_tiled_resource = D3D11_TILE_COPY_FLAG::D3D11_TILE_COPY_LINEAR_BUFFER_TO_SWIZZLED_TILED_RESOURCE,
	swizzled_tiled_resource_to_linear_buffer = D3D11_TILE_COPY_FLAG::D3D11_TILE_COPY_SWIZZLED_TILED_RESOURCE_TO_LINEAR_BUFFER,
};
_HW_3D_HW_FLAG_TYPE_(Tile_copy_flag, Tile_copy_flag_bit);

//
//
enum class Tile_mapping_flag_bit : Underlying_type_t<D3D11_TILE_MAPPING_FLAG> {
	no_overwrite = D3D11_TILE_MAPPING_FLAG::D3D11_TILE_MAPPING_NO_OVERWRITE,
};
_HW_3D_HW_FLAG_TYPE_(Tile_mapping_flag, Tile_mapping_flag_bit);

//
//
enum class Tile_range_flag_bit : Underlying_type_t<D3D11_TILE_RANGE_FLAG> {
	null = D3D11_TILE_RANGE_FLAG::D3D11_TILE_RANGE_NULL,
	skip = D3D11_TILE_RANGE_FLAG::D3D11_TILE_RANGE_SKIP,
	reuse_single_tile = D3D11_TILE_RANGE_FLAG::D3D11_TILE_RANGE_REUSE_SINGLE_TILE,
};
_HW_3D_HW_FLAG_TYPE_(Tile_range_flag, Tile_range_flag_bit);

//
//
enum class Parameter_flag_bit : Underlying_type_t<D3D_PARAMETER_FLAGS> {
	none = D3D_PARAMETER_FLAGS::D3D_PF_NONE,
	in = D3D_PARAMETER_FLAGS::D3D_PF_IN,
	out = D3D_PARAMETER_FLAGS::D3D_PF_OUT,
};
_HW_3D_HW_FLAG_TYPE_(Parameter_flag, Parameter_flag_bit);

//
//
enum class Shader_cbuffer_flag_bit : Underlying_type_t<D3D_SHADER_CBUFFER_FLAGS> {
	userpacked = D3D_SHADER_CBUFFER_FLAGS::D3D_CBF_USERPACKED,
};
_HW_3D_HW_FLAG_TYPE_(Shader_cbuffer_flag, Shader_cbuffer_flag_bit);

//
//
enum class Shader_input_flag_bit : Underlying_type_t<D3D_SHADER_INPUT_FLAGS> {
	userpacked = D3D_SHADER_INPUT_FLAGS::D3D_SIF_USERPACKED,
	comparison_sampler = D3D_SHADER_INPUT_FLAGS::D3D_SIF_COMPARISON_SAMPLER,
	texture_component_0 = D3D_SHADER_INPUT_FLAGS::D3D_SIF_TEXTURE_COMPONENT_0,
	texture_component_1 = D3D_SHADER_INPUT_FLAGS::D3D_SIF_TEXTURE_COMPONENT_1,
	texutre_components = D3D_SHADER_INPUT_FLAGS::D3D_SIF_TEXTURE_COMPONENTS,
	unused = D3D_SHADER_INPUT_FLAGS::D3D_SIF_UNUSED,
};
_HW_3D_HW_FLAG_TYPE_(Shader_input_flag, Shader_input_flag_bit);

//
//
enum class Shader_variable_flag_bit : Underlying_type_t<D3D_SHADER_VARIABLE_FLAGS> {
	userpacked = D3D_SHADER_VARIABLE_FLAGS::D3D_SVF_USERPACKED,
	used = D3D_SHADER_VARIABLE_FLAGS::D3D_SVF_USED,
	interface_pointer = D3D_SHADER_VARIABLE_FLAGS::D3D_SVF_INTERFACE_POINTER,
	interface_parameter = D3D_SHADER_VARIABLE_FLAGS::D3D_SVF_INTERFACE_PARAMETER,
};
_HW_3D_HW_FLAG_TYPE_(Shader_variable_flag, Shader_variable_flag_bit);

//
//
enum class Trace_component_mask_bit : Underlying_type_t<D3D11_TRACE_COMPONENT_MASK> {
	x = D3D11_TRACE_COMPONENT_X,
	y = D3D11_TRACE_COMPONENT_Y,
	z = D3D11_TRACE_COMPONENT_Z,
	w = D3D11_TRACE_COMPONENT_W,
};
_HW_3D_HW_FLAG_TYPE_(Trace_component_mask, Trace_component_mask_bit);

//
//
enum class Trace_misc_operations_mask_bit : Underlying_type_t<D3D11_TRACE_MISC_OPERATIONS_MASK> {
	gs_emit = D3D11_TRACE_MISC_GS_EMIT,
	gs_cut = D3D11_TRACE_MISC_GS_CUT,
	ps_discard = D3D11_TRACE_MISC_PS_DISCARD,
	gs_emit_stream = D3D11_TRACE_MISC_GS_EMIT_STREAM,
	gs_cut_stream = D3D11_TRACE_MISC_GS_CUT_STREAM,
	halt = D3D11_TRACE_MISC_HALT,
	message = D3D11_TRACE_MISC_MESSAGE,
};
_HW_3D_HW_FLAG_TYPE_(Trace_misc_operations_mask, Trace_misc_operations_mask_bit);

//
//
enum class Shader_min_precision_support_bit : Underlying_type_t<D3D11_SHADER_MIN_PRECISION_SUPPORT> {
	_10_bit = D3D11_SHADER_MIN_PRECISION_SUPPORT::D3D11_SHADER_MIN_PRECISION_10_BIT,
	_16_bit = D3D11_SHADER_MIN_PRECISION_SUPPORT::D3D11_SHADER_MIN_PRECISION_16_BIT,
};
_HW_3D_HW_FLAG_TYPE_(Shader_min_precision_support, Shader_min_precision_support_bit);

//
//
enum class Compile_constant_bit {
	debug = D3DCOMPILE_DEBUG,
	skip_validation = D3DCOMPILE_SKIP_VALIDATION,
	skip_optimization = D3DCOMPILE_SKIP_OPTIMIZATION,
	pack_matrix_row_major = D3DCOMPILE_PACK_MATRIX_ROW_MAJOR,
	pack_matrix_column_major = D3DCOMPILE_PACK_MATRIX_COLUMN_MAJOR,
	partial_precision = D3DCOMPILE_PARTIAL_PRECISION,
	force_vs_software_no_opt = D3DCOMPILE_FORCE_VS_SOFTWARE_NO_OPT,
	force_ps_software_no_opt = D3DCOMPILE_FORCE_PS_SOFTWARE_NO_OPT,
	no_preshader = D3DCOMPILE_NO_PRESHADER,
	avoid_flow_control = D3DCOMPILE_AVOID_FLOW_CONTROL,
	prefer_flow_control = D3DCOMPILE_PREFER_FLOW_CONTROL,
	enable_strictness = D3DCOMPILE_ENABLE_STRICTNESS,
	enable_backwards_compatibility = D3DCOMPILE_ENABLE_BACKWARDS_COMPATIBILITY,
	ieee_strictness = D3DCOMPILE_IEEE_STRICTNESS,
	optimization_level_0 = D3DCOMPILE_OPTIMIZATION_LEVEL0,
	optimization_level_1 = D3DCOMPILE_OPTIMIZATION_LEVEL1,
	optimization_level_2 = D3DCOMPILE_OPTIMIZATION_LEVEL2,
	optimization_level_3 = D3DCOMPILE_OPTIMIZATION_LEVEL3,
	reserved_16 = D3DCOMPILE_RESERVED16,
	reserved_17 = D3DCOMPILE_RESERVED17,
	warnings_are_errors = D3DCOMPILE_WARNINGS_ARE_ERRORS,
	resources_may_alias = D3DCOMPILE_RESOURCES_MAY_ALIAS,
	enable_unbounded_descriptor_tables = D3DCOMPILE_ENABLE_UNBOUNDED_DESCRIPTOR_TABLES,
	all_resources_bound = D3DCOMPILE_ALL_RESOURCES_BOUND,
	debug_name_for_source = D3DCOMPILE_DEBUG_NAME_FOR_SOURCE,
	debug_name_for_binary = D3DCOMPILE_DEBUG_NAME_FOR_BINARY,
};
_HW_3D_HW_FLAG_TYPE_(Compile_constant, Compile_constant_bit);

//
//
enum class Shader_require_bit {
	doubles = D3D_SHADER_REQUIRES_DOUBLES,
	early_depth_stencil = D3D_SHADER_REQUIRES_EARLY_DEPTH_STENCIL,
	uavs_at_every_stage = D3D_SHADER_REQUIRES_UAVS_AT_EVERY_STAGE,
	_64_uavs = D3D_SHADER_REQUIRES_64_UAVS,
	minimum_precison = D3D_SHADER_REQUIRES_MINIMUM_PRECISION,
	_11_1_double_extensions = D3D_SHADER_REQUIRES_11_1_DOUBLE_EXTENSIONS,
	_11_1_shader_extentions = D3D_SHADER_REQUIRES_11_1_SHADER_EXTENSIONS,
	level_9_comparison_filtering = D3D_SHADER_REQUIRES_LEVEL_9_COMPARISON_FILTERING,
	tiled_resources = D3D_SHADER_REQUIRES_TILED_RESOURCES,
	stencil_ref = D3D_SHADER_REQUIRES_STENCIL_REF,
	inner_coverage = D3D_SHADER_REQUIRES_INNER_COVERAGE,
	typed_uav_load_additional_formats = D3D_SHADER_REQUIRES_TYPED_UAV_LOAD_ADDITIONAL_FORMATS,
	requires_rovs = D3D_SHADER_REQUIRES_ROVS,
	viewport_and_rt_array_index_from_any_shader_feeding_rasterizer = D3D_SHADER_REQUIRES_VIEWPORT_AND_RT_ARRAY_INDEX_FROM_ANY_SHADER_FEEDING_RASTERIZER,
};
_HW_3D_HW_FLAG_TYPE_(Shader_require, Shader_require_bit);

//
//
enum class Component_mask_bit {
	x = D3D_COMPONENT_MASK_X,
	y = D3D_COMPONENT_MASK_Y,
	z = D3D_COMPONENT_MASK_Z,
	w = D3D_COMPONENT_MASK_W,
};
_HW_3D_HW_FLAG_TYPE_(Component_mask, Component_mask_bit);

//
//
enum class Trace_register_flag_bit {
	relative_indexing = D3D11_TRACE_REGISTER_FLAGS_RELATIVE_INDEXING,
};
_HW_3D_HW_FLAG_TYPE_(Trace_register_flag, Trace_register_flag_bit);

//
//
enum class Shader_trace_flag_bit {
	record_register_writes = D3D11_SHADER_TRACE_FLAG_RECORD_REGISTER_WRITES,
	record_register_reads = D3D11_SHADER_TRACE_FLAG_RECORD_REGISTER_READS,
};
_HW_3D_HW_FLAG_TYPE_(Shader_trace_flag, Shader_trace_flag_bit);

//
//
enum class Debug_feature_mask_bit {
	finish_per_render_op = D3D11_DEBUG_FEATURE_FINISH_PER_RENDER_OP,
	flush_per_render_op = D3D11_DEBUG_FEATURE_FLUSH_PER_RENDER_OP,
	present_per_render_op = D3D11_DEBUG_FEATURE_PRESENT_PER_RENDER_OP,
	always_discard_offered_resource = D3D11_DEBUG_FEATURE_ALWAYS_DISCARD_OFFERED_RESOURCE,
	never_discard_offered_resource = D3D11_DEBUG_FEATURE_NEVER_DISCARD_OFFERED_RESOURCE,
	avoid_behavior_changing_debug_aids = D3D11_DEBUG_FEATURE_AVOID_BEHAVIOR_CHANGING_DEBUG_AIDS,
	disable_tiled_resource_mapping_tracking_and_validation = D3D11_DEBUG_FEATURE_DISABLE_TILED_RESOURCE_MAPPING_TRACKING_AND_VALIDATION,
};
_HW_3D_HW_FLAG_TYPE_(Debug_feature_mask, Debug_feature_mask_bit);

//
//
enum class Compiler_strip_flag_bit : Underlying_type_t<D3DCOMPILER_STRIP_FLAGS> {
	reflection_data = D3DCOMPILER_STRIP_FLAGS::D3DCOMPILER_STRIP_REFLECTION_DATA,
	debug_info = D3DCOMPILER_STRIP_FLAGS::D3DCOMPILER_STRIP_DEBUG_INFO,
	test_blobs = D3DCOMPILER_STRIP_FLAGS::D3DCOMPILER_STRIP_TEST_BLOBS,
	private_data = D3DCOMPILER_STRIP_FLAGS::D3DCOMPILER_STRIP_PRIVATE_DATA,
	root_signature = D3DCOMPILER_STRIP_FLAGS::D3DCOMPILER_STRIP_ROOT_SIGNATURE
};
_HW_3D_HW_FLAG_TYPE_(Compiler_strip_flag, Compiler_strip_flag_bit);

_HW_3D_CLOSE_D3D_NAMESPACE_

template <>
struct Flag_traits<_HW_3D_DXGI_ Display_mode_bit> {
	using Bit_type = _HW_3D_DXGI_ Display_mode_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::stereo) |
		Mask_type(Bit_type::scaling) |
		Mask_type(Bit_type::disabeld_stereo) |
		Mask_type(Bit_type::interlaced)
	};
};

template <>
struct Flag_traits<_HW_3D_DXGI_ Present_mode_bit> {
	using Bit_type = _HW_3D_DXGI_ Present_mode_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::allow_tearing) |
		Mask_type(Bit_type::do_not_sequence) |
		Mask_type(Bit_type::do_not_wait) |
		Mask_type(Bit_type::restart) |
		Mask_type(Bit_type::restrict_to_output) |
		Mask_type(Bit_type::stereo_prefer_right) |
		Mask_type(Bit_type::stereo_temporary_mono) |
		Mask_type(Bit_type::test) |
		Mask_type(Bit_type::use_duration)
	};
};

template <>
struct Flag_traits<_HW_3D_DXGI_ Adapter_flag_bit> {
	using Bit_type = _HW_3D_DXGI_ Adapter_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::none) |
		Mask_type(Bit_type::remote) |
		Mask_type(Bit_type::software)
	};
};

template <>
struct Flag_traits<_HW_3D_DXGI_ Adapter_flag3_bit> {
	using Bit_type = _HW_3D_DXGI_ Adapter_flag3_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::acg_compatible) |
		Mask_type(Bit_type::keyed_mutex_conformance) |
		Mask_type(Bit_type::none) |
		Mask_type(Bit_type::remote) |
		Mask_type(Bit_type::software) |
		Mask_type(Bit_type::support_monitored_fences) |
		Mask_type(Bit_type::suuport_non_monitored_fences)
	};
};

template <>
struct Flag_traits<_HW_3D_DXGI_ Debug_rlo_flag_bit> {
	using Bit_type =_HW_3D_DXGI_  Debug_rlo_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::all)
	};
};

template <>
struct Flag_traits<_HW_3D_DXGI_ Multiplane_overlay_ycbcr_flag_bit> {
	using Bit_type = _HW_3D_DXGI_ Multiplane_overlay_ycbcr_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::bt709) |
		Mask_type(Bit_type::nominal_range) |
		Mask_type(Bit_type::xvycc)
	};
};

template <>
struct Flag_traits<_HW_3D_DXGI_ Offer_resource_flag_bit> {
	using Bit_type = _HW_3D_DXGI_ Offer_resource_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::allow_decommit)
	};
};

template <>
struct Flag_traits<_HW_3D_DXGI_ Overlay_color_space_support_flag_bit> {
	using Bit_type = _HW_3D_DXGI_ Overlay_color_space_support_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::present)
	};
};

template <>
struct Flag_traits<_HW_3D_DXGI_ Overlay_support_flag_bit> {
	using Bit_type = _HW_3D_DXGI_ Overlay_support_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::direct) |
		Mask_type(Bit_type::scaling)
	};
};

template <>
struct Flag_traits<_HW_3D_DXGI_ Swap_chain_color_space_support_flag_bit> {
	using Bit_type = _HW_3D_DXGI_ Swap_chain_color_space_support_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::overlay_present) |
		Mask_type(Bit_type::present)
	};
};

template <>
struct Flag_traits<_HW_3D_DXGI_ Swap_chain_flag_bit> {
	using Bit_type = _HW_3D_DXGI_ Swap_chain_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::allow_mode_switch) |
		Mask_type(Bit_type::allow_tearing) |
		Mask_type(Bit_type::display_only) |
		Mask_type(Bit_type::foreground_layer) |
		Mask_type(Bit_type::frame_latency_waitbable_object) |
		Mask_type(Bit_type::fullscreen_video) |
		Mask_type(Bit_type::gdi_compatible) |
		Mask_type(Bit_type::hw_protected) |
		Mask_type(Bit_type::nonprerotated) |
		Mask_type(Bit_type::restricted_content) |
		Mask_type(Bit_type::restricted_to_all_holographic_displays) |
		Mask_type(Bit_type::restrict_shared_resource_driver) |
		Mask_type(Bit_type::yuv_video)
	};
};

template <>
struct Flag_traits<_HW_3D_DXGI_ Map_flag_bit> {
	using Bit_type = _HW_3D_DXGI_ Map_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::read) |
		Mask_type(Bit_type::write) |
		Mask_type(Bit_type::discard)
	};
};

template <>
struct Flag_traits<_HW_3D_DXGI_ Usage_bit> {
	using Bit_type = _HW_3D_DXGI_ Usage_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::shader_input) |
		Mask_type(Bit_type::render_target_output) |
		Mask_type(Bit_type::back_buffer) |
		Mask_type(Bit_type::shared) |
		Mask_type(Bit_type::read_only) |
		Mask_type(Bit_type::discard_on_present) |
		Mask_type(Bit_type::unordered_access)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Async_get_data_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Async_get_data_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::donoflush)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Clear_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Clear_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::depth) |
		Mask_type(Bit_type::stencil)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Color_write_mask_bit> {
	using Bit_type = _HW_3D_D3D_ Color_write_mask_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::all)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Copy_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Copy_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::no_overwrite) |
		Mask_type(Bit_type::discard)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Create_device_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Create_device_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::bgra_support) |
		Mask_type(Bit_type::debug) |
		Mask_type(Bit_type::debuggable) |
		Mask_type(Bit_type::disable_gpu_timeout) |
		Mask_type(Bit_type::prevent_internal_threading_optimizations) |
		Mask_type(Bit_type::prevernt_altering_layer_settings_from_registry) |
		Mask_type(Bit_type::single_threaded) |
		Mask_type(Bit_type::video_support)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Create_device_context_state_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Create_device_context_state_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::single_threaded)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Fence_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Fence_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::none) |
		Mask_type(Bit_type::shared) |
		Mask_type(Bit_type::shared_cross_adapter)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Format_support_bit> {
	using Bit_type = _HW_3D_D3D_ Format_support_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::back_buffer_cast) |
		Mask_type(Bit_type::blendable) |
		Mask_type(Bit_type::buffer) |
		Mask_type(Bit_type::cast_within_bit_layout) |
		Mask_type(Bit_type::cpu_lockable) |
		Mask_type(Bit_type::decoder_output) |
		Mask_type(Bit_type::depth_stencil) |
		Mask_type(Bit_type::display) |
		Mask_type(Bit_type::ia_index_buffer) |
		Mask_type(Bit_type::ia_vertex_buffer) |
		Mask_type(Bit_type::mip) |
		Mask_type(Bit_type::mip_autogen) |
		Mask_type(Bit_type::multisample_load) |
		Mask_type(Bit_type::multisample_rendertarget) |
		Mask_type(Bit_type::multisample_resolve) |
		Mask_type(Bit_type::render_target) |
		Mask_type(Bit_type::shader_gather) |
		Mask_type(Bit_type::shader_gather_comparision) |
		Mask_type(Bit_type::shader_load) |
		Mask_type(Bit_type::shader_sample) |
		Mask_type(Bit_type::shader_sample_comparison) |
		Mask_type(Bit_type::shader_sample_mono_text) |
		Mask_type(Bit_type::so_buffer) |
		Mask_type(Bit_type::unordered_access_view) |
		Mask_type(Bit_type::video_processor_input) |
		Mask_type(Bit_type::video_encoder) |
		Mask_type(Bit_type::video_processor_output) |
		Mask_type(Bit_type::texture_1d) |
		Mask_type(Bit_type::texture_2d) |
		Mask_type(Bit_type::texture_3d) |
		Mask_type(Bit_type::texture_cube)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Format_support2_bit> {
	using Bit_type = _HW_3D_D3D_ Format_support2_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::multiplane_overlay) |
		Mask_type(Bit_type::output_merger_logic_op) |
		Mask_type(Bit_type::shareable) |
		Mask_type(Bit_type::tiled) |
		Mask_type(Bit_type::uav_atomic_add) |
		Mask_type(Bit_type::uav_atomic_bitwise_ops) |
		Mask_type(Bit_type::uav_atomic_compare_store_or_compare_exchange) |
		Mask_type(Bit_type::uav_atomic_exchange) |
		Mask_type(Bit_type::uav_atomic_signed_min_or_max) |
		Mask_type(Bit_type::uav_atomic_unsigned_min_or_max) |
		Mask_type(Bit_type::uav_typed_load) |
		Mask_type(Bit_type::uav_typed_store)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Query_misc_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Query_misc_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::predicate)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Raise_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Raise_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::driver_internal_error)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Shader_cache_support_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Shader_cache_support_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::none) |
		Mask_type(Bit_type::automatic_inproc_cache) |
		Mask_type(Bit_type::automatic_disk_cache)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Counter_bit> {
	using Bit_type = _HW_3D_D3D_ Counter_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::device_dependent)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Rldo_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Rldo_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::summary) |
		Mask_type(Bit_type::detail) |
		Mask_type(Bit_type::ignore_interanl)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Shader_tracking_option_bit> {
	using Bit_type = _HW_3D_D3D_ Shader_tracking_option_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::allow_same) |
		Mask_type(Bit_type::all_hazards) |
		Mask_type(Bit_type::all_hazards_allow_same) |
		Mask_type(Bit_type::all_options) |
		Mask_type(Bit_type::ignore) |
		Mask_type(Bit_type::track_atomic_consistency) |
		Mask_type(Bit_type::track_atomic_consistency_across_threadgroups) |
		Mask_type(Bit_type::track_raw) |
		Mask_type(Bit_type::track_raw_across_threadgroups) |
		Mask_type(Bit_type::track_uninitialized) |
		Mask_type(Bit_type::track_war) |
		Mask_type(Bit_type::track_war_across_threadgroups) |
		Mask_type(Bit_type::track_waw) |
		Mask_type(Bit_type::track_waw_across_threadgroups) |
		Mask_type(Bit_type::uav_specific_flags)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Bind_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Bind_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::constant_buffer) |
		Mask_type(Bit_type::decoder) |
		Mask_type(Bit_type::depth_stencil) |
		Mask_type(Bit_type::index_buffer) |
		Mask_type(Bit_type::render_target) |
		Mask_type(Bit_type::shader_resource) |
		Mask_type(Bit_type::stream_output) |
		Mask_type(Bit_type::unordered_access) |
		Mask_type(Bit_type::vertex_buffer) |
		Mask_type(Bit_type::video_encoder)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Buffer_ex_srv_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Buffer_ex_srv_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::raw)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Buffer_uav_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Buffer_uav_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::raw) |
		Mask_type(Bit_type::append) |
		Mask_type(Bit_type::counter)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Check_multisample_quality_levels_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Check_multisample_quality_levels_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::tiled_resource)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Cpu_access_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Cpu_access_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::read) |
		Mask_type(Bit_type::write)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Dsv_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Dsv_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::depth) |
		Mask_type(Bit_type::stencil)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Map_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Map_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::do_not_wait)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Resource_misc_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Resource_misc_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::buffer_allow_raw_views) |
		Mask_type(Bit_type::buffer_structured) |
		Mask_type(Bit_type::drawindirect_args) |
		Mask_type(Bit_type::gdi_compatible) |
		Mask_type(Bit_type::generate_mips) |
		Mask_type(Bit_type::guarded) |
		Mask_type(Bit_type::hw_protected) |
		Mask_type(Bit_type::resource_clamp) |
		Mask_type(Bit_type::restricted_content) |
		Mask_type(Bit_type::restrict_shared_resource) |
		Mask_type(Bit_type::restrict_shared_resource_driver) |
		Mask_type(Bit_type::shared) |
		Mask_type(Bit_type::shared_keyedmutex) |
		Mask_type(Bit_type::shared_nthandle)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Tile_copy_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Tile_copy_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::linear_buffer_to_swizzled_tiled_resource) |
		Mask_type(Bit_type::no_overwrite) |
		Mask_type(Bit_type::swizzled_tiled_resource_to_linear_buffer)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Tile_mapping_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Tile_mapping_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::no_overwrite)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Tile_range_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Tile_range_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::null) |
		Mask_type(Bit_type::reuse_single_tile) |
		Mask_type(Bit_type::skip)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Parameter_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Parameter_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::none) |
		Mask_type(Bit_type::in) |
		Mask_type(Bit_type::out)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Shader_cbuffer_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Shader_cbuffer_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::userpacked)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Shader_input_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Shader_input_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::userpacked) |
		Mask_type(Bit_type::comparison_sampler) |
		Mask_type(Bit_type::texture_component_0) |
		Mask_type(Bit_type::texture_component_1) |
		Mask_type(Bit_type::texutre_components) |
		Mask_type(Bit_type::unused)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Shader_variable_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Shader_variable_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::userpacked) |
		Mask_type(Bit_type::used) |
		Mask_type(Bit_type::interface_parameter) |
		Mask_type(Bit_type::interface_pointer)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Trace_component_mask_bit> {
	using Bit_type = _HW_3D_D3D_ Trace_component_mask_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::x) |
		Mask_type(Bit_type::y) |
		Mask_type(Bit_type::z) |
		Mask_type(Bit_type::w)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Trace_misc_operations_mask_bit> {
	using Bit_type = _HW_3D_D3D_ Trace_misc_operations_mask_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::gs_emit) |
		Mask_type(Bit_type::gs_cut) |
		Mask_type(Bit_type::ps_discard) |
		Mask_type(Bit_type::gs_emit_stream) |
		Mask_type(Bit_type::gs_cut_stream) |
		Mask_type(Bit_type::halt) |
		Mask_type(Bit_type::message)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Shader_min_precision_support_bit> {
	using Bit_type = _HW_3D_D3D_ Shader_min_precision_support_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::_10_bit) |
		Mask_type(Bit_type::_16_bit)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Compile_constant_bit> {
	using Bit_type = _HW_3D_D3D_ Compile_constant_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::all_resources_bound) |
		Mask_type(Bit_type::avoid_flow_control) |
		Mask_type(Bit_type::debug) |
		Mask_type(Bit_type::debug_name_for_binary) |
		Mask_type(Bit_type::debug_name_for_source) |
		Mask_type(Bit_type::enable_backwards_compatibility) |
		Mask_type(Bit_type::enable_strictness) |
		Mask_type(Bit_type::enable_unbounded_descriptor_tables) |
		Mask_type(Bit_type::force_ps_software_no_opt) |
		Mask_type(Bit_type::force_vs_software_no_opt) |
		Mask_type(Bit_type::ieee_strictness) |
		Mask_type(Bit_type::no_preshader) |
		Mask_type(Bit_type::optimization_level_0) |
		Mask_type(Bit_type::optimization_level_1) |
		Mask_type(Bit_type::optimization_level_2) |
		Mask_type(Bit_type::optimization_level_3) |
		Mask_type(Bit_type::pack_matrix_column_major) |
		Mask_type(Bit_type::pack_matrix_row_major) |
		Mask_type(Bit_type::partial_precision) |
		Mask_type(Bit_type::prefer_flow_control) |
		Mask_type(Bit_type::reserved_16) |
		Mask_type(Bit_type::reserved_17) |
		Mask_type(Bit_type::resources_may_alias) |
		Mask_type(Bit_type::skip_optimization) |
		Mask_type(Bit_type::skip_validation) |
		Mask_type(Bit_type::warnings_are_errors)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Shader_require_bit> {
	using Bit_type = _HW_3D_D3D_ Shader_require_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::doubles) |
		Mask_type(Bit_type::early_depth_stencil) |
		Mask_type(Bit_type::inner_coverage) |
		Mask_type(Bit_type::level_9_comparison_filtering) |
		Mask_type(Bit_type::minimum_precison) |
		Mask_type(Bit_type::requires_rovs) |
		Mask_type(Bit_type::stencil_ref) |
		Mask_type(Bit_type::tiled_resources) |
		Mask_type(Bit_type::typed_uav_load_additional_formats) |
		Mask_type(Bit_type::uavs_at_every_stage) |
		Mask_type(Bit_type::viewport_and_rt_array_index_from_any_shader_feeding_rasterizer) |
		Mask_type(Bit_type::_11_1_double_extensions) |
		Mask_type(Bit_type::_11_1_shader_extentions) |
		Mask_type(Bit_type::_64_uavs)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Component_mask_bit> {
	using Bit_type = _HW_3D_D3D_ Component_mask_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::x) |
		Mask_type(Bit_type::y) |
		Mask_type(Bit_type::z) |
		Mask_type(Bit_type::w)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Trace_register_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Trace_register_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::relative_indexing)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Shader_trace_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Shader_trace_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::record_register_reads) |
		Mask_type(Bit_type::record_register_writes)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Debug_feature_mask_bit> {
	using Bit_type = _HW_3D_D3D_ Debug_feature_mask_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::finish_per_render_op) |
		Mask_type(Bit_type::flush_per_render_op) |
		Mask_type(Bit_type::present_per_render_op) |
		Mask_type(Bit_type::always_discard_offered_resource) |
		Mask_type(Bit_type::never_discard_offered_resource) |
		Mask_type(Bit_type::avoid_behavior_changing_debug_aids) |
		Mask_type(Bit_type::disable_tiled_resource_mapping_tracking_and_validation)
	};
};

template <>
struct Flag_traits<_HW_3D_D3D_ Compiler_strip_flag_bit> {
	using Bit_type = _HW_3D_D3D_ Compiler_strip_flag_bit;
	using Mask_type = Underlying_type_t<Bit_type>;

	enum {
		all_flags =
		Mask_type(Bit_type::debug_info) |
		Mask_type(Bit_type::reflection_data) |
		Mask_type(Bit_type::test_blobs) |
		Mask_type(Bit_type::private_data) |
		Mask_type(Bit_type::root_signature)
	};
};

_HW_3D_CLOSE_HW_NAMESPACE_