#pragma once

#include "d3d_fwd.h"
#include "d3d_flag.hpp"
#include "d3d_struct.hpp"
#include "d3d_enum.h"

_HW_3D_OPEN_HW_NAMESPACE_

//
//
class _HW_3D_NO_VTABLE_ IBase {
public:
	virtual ULONG
		add_ref(
		) = 0;

	//lower api, unsafe
	virtual _HW_3D_STD_ tuple<HRESULT, void*>
		query_interface(
			_HW_3D_IN_ REFIID riid
		) = 0;

	virtual ULONG
		release(
		) = 0;

	//ugly but useful
	virtual IUnknown* get() = 0;

	virtual const IUnknown* get() const = 0;

	virtual ~IBase() {}
};


_HW_3D_OPEN_DXGI_NAMESPACE_

//forward declaration
class IOutput;
class ISurface;
class IResource;
class ISwap_chain;
class ISwap_chain1;
class IOutput_duplication;
class ISurface2;

//
//
class _HW_3D_NO_VTABLE_ IObject : public IBase {
public:
	virtual _HW_3D_STD_ tuple<Result, void*>
		get_parent(
			_HW_3D_IN_ REFIID riid
		) = 0;

	virtual Result
		get_private_data(
			_HW_3D_IN_ REFGUID name,
			_HW_3D_IN_OUT_ UINT* size,
			_HW_3D_OUT_ void* data
		) = 0;

	virtual Result
		set_private_data(
			_HW_3D_IN_ REFGUID name,
			_HW_3D_IN_ UINT size,
			_HW_3D_IN_ const void* data
		) = 0;

	virtual Result
		get_private_data_interface(
			_HW_3D_IN_ REFGUID name,
			_HW_3D_IN_ const IBase* unknown
		) = 0;

	virtual IDXGIObject* get() = 0;

	virtual const IDXGIObject* get() const = 0;

	virtual ~IObject() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, IDXGIObject>);

//
//
class _HW_3D_NO_VTABLE_ IAdapter : public IObject {
public:
	virtual _HW_3D_STD_ tuple<Result, LARGE_INTEGER>
		check_interface_support(
			_HW_3D_IN_ REFGUID interface_name
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IOutput>>
		enum_outputs(
			_HW_3D_IN_ UINT output
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Adapter_desc>
		get_desc(
		) = 0;

	virtual IDXGIAdapter* get() = 0;

	virtual const IDXGIAdapter* get() const = 0;

	virtual ~IAdapter() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIObject, IDXGIAdapter>);

//
//
class _HW_3D_NO_VTABLE_ IAdapter1 : public IAdapter {
public:
	virtual _HW_3D_STD_ tuple<Result, Adapter_desc1>
		get_desc1(
		) = 0;

	virtual IDXGIAdapter1* get() = 0;

	virtual const IDXGIAdapter1* get() const = 0;

	virtual ~IAdapter1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIAdapter, IDXGIAdapter1>);

//
//
class _HW_3D_NO_VTABLE_ IAdapter2 : public IAdapter1 {
public:
	virtual _HW_3D_STD_ tuple<Result, Adapter_desc2>
		get_desc2(
		) = 0;

	virtual IDXGIAdapter2* get() = 0;

	virtual const IDXGIAdapter2* get() const = 0;

	virtual ~IAdapter2() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIAdapter1, IDXGIAdapter2>);

//
//
class _HW_3D_NO_VTABLE_ IAdapter3 : public IAdapter2 {
public:
	virtual _HW_3D_STD_ tuple<Result, Query_video_memory_info>
		query_video_memory_info(
			_HW_3D_IN_ UINT node_index,
			_HW_3D_IN_ Memory_segment_group group
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, DWORD>
		register_hardware_content_protection_teardown_status_event(
			_HW_3D_IN_ HANDLE h_event
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, DWORD>
		register_video_memory_budget_change_notification_event(
			_HW_3D_IN_ HANDLE h_event
		) = 0;

	virtual Result
		set_video_memory_reservation(
			_HW_3D_IN_ UINT node_index,
			_HW_3D_IN_ Memory_segment_group group,
			_HW_3D_IN_ UINT64 reservation
		) = 0;

	virtual void
		unregister_hardware_content_protection_teardown_status(
			_HW_3D_IN_ DWORD cookie
		) = 0;

	virtual void
		unregister_video_memory_budget_change_notification(
			_HW_3D_IN_ DWORD cookie
		) = 0;

	virtual IDXGIAdapter3* get() = 0;

	virtual const IDXGIAdapter3* get() const = 0;

	virtual ~IAdapter3() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIAdapter2, IDXGIAdapter3>);

//
//
class _HW_3D_NO_VTABLE_ IAdapter4 : public IAdapter3 {
public:
	virtual _HW_3D_STD_ tuple<Result, Adapter_desc3>
		get_desc3(
		) = 0;

	virtual IDXGIAdapter4* get() = 0;

	virtual const IDXGIAdapter4* get() const = 0;

	virtual ~IAdapter4() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIAdapter3, IDXGIAdapter4>);

//
//
class _HW_3D_NO_VTABLE_ IDebug : public IBase {
public:
	virtual Result
		report_live_objects(
			_HW_3D_IN_ GUID appid,
			_HW_3D_IN_ Debug_rlo_flag flags
		) = 0;

	virtual IDXGIDebug* get() = 0;

	virtual const IDXGIDebug* get() const = 0;

	virtual ~IDebug() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, IDXGIDebug>);

//
//
class _HW_3D_NO_VTABLE_ IDebug1 : public IDebug {
public:
	virtual void
		disable_leak_tracking_for_thread(
		) = 0;

	virtual void
		enabled_leak_tracking_for_thread(
		) = 0;

	virtual BOOL
		is_leak_tracking_enabled_for_thread(
		) = 0;

	virtual IDXGIDebug1* get() = 0;

	virtual const IDXGIDebug1* get() const = 0;

	virtual ~IDebug1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIDebug, IDXGIDebug1>);

//
//
class _HW_3D_NO_VTABLE_ IDecode_swap_chain : public IBase {
public:
	virtual Multiplane_overlay_ycbcr_flag
		get_color_space(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, UINT, UINT>
		get_dest_size(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, RECT>
		get_source_rect(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, RECT>
		get_target_rect(
		) = 0;

	virtual Result
		present_buffer(
			_HW_3D_IN_ UINT buffer_to_present,
			_HW_3D_IN_ UINT sync_interval,
			_HW_3D_IN_ Present_mode flags
		) = 0;

	virtual Result
		set_color_space(
			_HW_3D_IN_ Multiplane_overlay_ycbcr_flag color_space
		) = 0;

	virtual Result
		set_dest_size(
			_HW_3D_IN_ UINT width,
			_HW_3D_IN_ UINT height
		) = 0;

	virtual Result
		set_source_rect(
			_HW_3D_IN_ const RECT& rect
		) = 0;

	virtual Result
		set_target_rect(
			_HW_3D_IN_ const RECT& rect
		) = 0;

	virtual IDXGIDecodeSwapChain* get() = 0;

	virtual const IDXGIDecodeSwapChain* get() const = 0;

	virtual ~IDecode_swap_chain() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, IDXGIDecodeSwapChain>);

//
//
class _HW_3D_NO_VTABLE_ IDevice : public IObject {
public:
	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISurface>>>
		create_surface(
			_HW_3D_IN_ const Surface_desc& desc,
			_HW_3D_IN_ UINT num_surfaces,
			_HW_3D_IN_ Usage usage,
			_HW_3D_IN_ const Shared_resource* p_shared_resource
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter>>
		get_adapter(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, INT>
		get_gpu_thread_priority(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<Residency>>
		query_resource_residency(
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBase*>& resouces
		) = 0;

	virtual Result
		set_gpu_thread_priority(
			_HW_3D_IN_ INT priority
		) = 0;

	virtual IDXGIDevice* get() = 0;

	virtual const IDXGIDevice* get() const = 0;

	virtual ~IDevice() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIObject, IDXGIDevice>);

//
//
class _HW_3D_NO_VTABLE_ IDevice1 : public IDevice {
public:
	virtual _HW_3D_STD_ tuple<Result, UINT>
		get_maximum_frame_latency(
		) = 0;

	virtual Result
		set_maximum_frame_latency(
			_HW_3D_IN_ UINT max_latency
		) = 0;

	virtual IDXGIDevice1* get() = 0;

	virtual const IDXGIDevice1* get() const = 0;

	virtual ~IDevice1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIDevice, IDXGIDevice1>);

//
//
class _HW_3D_NO_VTABLE_ IDevice2 : public IDevice1 {
public:
	virtual Result
		enqueue_set_event(
			_HW_3D_IN_ HANDLE h_event
		) = 0;

	virtual Result
		offer_resources(
			_HW_3D_IN_ const _HW_3D_STD_ vector<IResource*>&  resources,
			_HW_3D_IN_ Offer_resource_priority priority
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, BOOL>
		reclaim_resources(
			_HW_3D_IN_ const _HW_3D_STD_ vector<IResource*>& resources
		) = 0;

	virtual IDXGIDevice2* get() = 0;

	virtual const IDXGIDevice2* get() const = 0;

	virtual ~IDevice2() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIDevice1, IDXGIDevice2>);

//
//
class _HW_3D_NO_VTABLE_ IDevice3 : public IDevice2 {
public:
	virtual void
		trim(
		) = 0;

	virtual IDXGIDevice3* get() = 0;

	virtual const IDXGIDevice3* get() const = 0;

	virtual ~IDevice3() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIDevice2, IDXGIDevice3>);

//
//
class _HW_3D_NO_VTABLE_ IDevice4 : public IDevice3 {
public:
	virtual Result
		offer_resource1(
			_HW_3D_IN_ const _HW_3D_STD_ vector<IResource*>& resources,
			_HW_3D_IN_ Offer_resource_priority priority,
			_HW_3D_IN_ Offer_resource_flag flags
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<Reclaim_resource_results>>
		reclaim_resources1(
			_HW_3D_IN_ const _HW_3D_STD_ vector<IResource*>& resources
		) = 0;

	virtual IDXGIDevice4* get() = 0;

	virtual const IDXGIDevice4* get() const = 0;

	virtual ~IDevice4() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIDevice3, IDXGIDevice4>);

//
//
class _HW_3D_NO_VTABLE_ IDevice_subobject : public IObject {
public:
	virtual _HW_3D_STD_ tuple<Result, void*>
		get_device(
			_HW_3D_IN_ REFIID riid
		) = 0;

	virtual IDXGIDeviceSubObject* get() = 0;

	virtual const IDXGIDeviceSubObject* get() const = 0;

	virtual ~IDevice_subobject() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIObject, IDXGIDeviceSubObject>);

//
//
class _HW_3D_NO_VTABLE_ IDisplay_control : public IBase {
public:
	virtual BOOL
		is_stereo_enabled(
		) = 0;

	virtual void
		set_stereo_enabled(
			BOOL enabled
		) = 0;

	virtual IDXGIDisplayControl* get() = 0;

	virtual const IDXGIDisplayControl* get() const = 0;

	virtual ~IDisplay_control() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, IDXGIDisplayControl>);

//
//
class _HW_3D_NO_VTABLE_ IFactory : public IObject {
public:
	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter>>
		create_software_adapter(
			_HW_3D_IN_ HMODULE mod
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISwap_chain>>
		create_swap_chain(
			_HW_3D_IN_ IBase* device,
			_HW_3D_IN_ Swap_chain_desc& desc
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter>>
		enum_adapters(
			_HW_3D_IN_ UINT adapter
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, HWND>
		get_window_association(
		) = 0;

	virtual Result
		make_window_association(
			_HW_3D_IN_ HWND window_handle,
			_HW_3D_IN_ UINT flags
		) = 0;

	virtual IDXGIFactory* get() = 0;

	virtual const IDXGIFactory* get() const = 0;

	virtual ~IFactory() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, IDXGIFactory>);

//
//
class _HW_3D_NO_VTABLE_ IFactory1 : public IFactory {
public:
	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter1>>
		enum_adapters1(
			_HW_3D_IN_ UINT adapter
		) = 0;

	virtual BOOL
		is_current(
		) = 0;

	virtual IDXGIFactory1* get() = 0;

	virtual const IDXGIFactory1* get() const = 0;

	virtual ~IFactory1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIFactory, IDXGIFactory1>);

//
//
class _HW_3D_NO_VTABLE_ IFactory2 : public IFactory1 {
public:
	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISwap_chain1>>
		create_swap_chain_for_composition(
			_HW_3D_IN_ IBase* device,
			_HW_3D_IN_ const Swap_chain_desc1& desc,
			_HW_3D_IN_ IOutput* restrict_to_output
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISwap_chain1>>
		create_swap_chain_for_core_window(
			_HW_3D_IN_ IBase* device,
			_HW_3D_IN_ IBase* window,
			_HW_3D_IN_ const Swap_chain_desc1& desc,
			_HW_3D_IN_ IOutput* restrict_to_output
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISwap_chain1>>
		create_swap_chain_for_hwnd(
			_HW_3D_IN_ IBase* device,
			_HW_3D_IN_ HWND hwnd,
			_HW_3D_IN_ const Swap_chain_desc1& desc,
			_HW_3D_IN_ const Swap_chain_fullscreen_desc* full_screen_desc,
			_HW_3D_IN_ IOutput* restrict_to_output
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, LUID>
		get_shared_resource_adapter_luid(
			_HW_3D_IN_ HANDLE resource
		) = 0;

	virtual BOOL
		is_windowed_stereo_enabled(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, DWORD>
		register_occlusion_status_event(
			_HW_3D_IN_ HANDLE h_event
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, DWORD>
		register_occlusion_status_window(
			_HW_3D_IN_ HWND windhow_handle,
			_HW_3D_IN_ UINT msg
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, DWORD>
		register_stereo_status_event(
			_HW_3D_IN_ HANDLE h_event
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, DWORD>
		register_stereo_status_window(
			_HW_3D_IN_ HWND window_handle,
			_HW_3D_IN_ UINT msg
		) = 0;

	virtual void
		unregister_occlusion_status(
			_HW_3D_IN_ DWORD cookie
		) = 0;

	virtual void
		unregister_stereo_stauts(
			_HW_3D_IN_ DWORD cookie
		) = 0;

	virtual IDXGIFactory2* get() = 0;

	virtual const IDXGIFactory2* get() const = 0;

	virtual ~IFactory2() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIFactory1, IDXGIFactory2>);

//
//
class _HW_3D_NO_VTABLE_ IFactory3 : public IFactory2 {
public:
	virtual UINT
		get_creation_flags(
		) = 0;

	virtual IDXGIFactory3* get() = 0;

	virtual const IDXGIFactory3* get() const = 0;

	virtual ~IFactory3() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIFactory2, IDXGIFactory3>);

//
//
class _HW_3D_NO_VTABLE_ IFactory4 : public IFactory3 {
public:
	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter>>
		enum_adapter_by_luid(
			_HW_3D_IN_ LUID adapter_luid,
			_HW_3D_IN_ REFIID riid
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter>>
		enum_warp_adapter(
			_HW_3D_IN_ REFIID riid
		) = 0;

	virtual IDXGIFactory4* get() = 0;

	virtual const IDXGIFactory4* get() const = 0;

	virtual ~IFactory4() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIFactory3, IDXGIFactory4>);

//
//
class _HW_3D_NO_VTABLE_ IFactory5 : public IFactory4 {
public:
	virtual Result
		check_feature_support(
			_HW_3D_IN_ Feature feature,
			_HW_3D_IN_ void* feature_support_data,
			_HW_3D_IN_ UINT feature_support_data_size
		) = 0;

	virtual IDXGIFactory5* get() = 0;

	virtual const IDXGIFactory5* get() const = 0;

	virtual ~IFactory5() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIFactory4, IDXGIFactory5>);

//
//
class _HW_3D_NO_VTABLE_ IFactory_media : public IBase {
public:
	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDecode_swap_chain>>
		create_decode_swap_chain_for_composition_surface_handle(
			_HW_3D_IN_ IBase* device,
			_HW_3D_IN_ HANDLE surface,
			_HW_3D_IN_ Decode_swap_chain_desc& desc,
			_HW_3D_IN_ IResource* decode_buffers,
			_HW_3D_IN_ IOutput* restrict_to_output
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISwap_chain1>>
		create_swap_chain_for_composition_surface_handle(
			_HW_3D_IN_ IBase* devcie,
			_HW_3D_IN_ HANDLE surface,
			_HW_3D_IN_ const Swap_chain_desc1& desc,
			_HW_3D_IN_ IOutput* restrict_to_output
		) = 0;

	virtual IDXGIFactoryMedia* get() = 0;

	virtual const IDXGIFactoryMedia* get() const = 0;

	virtual ~IFactory_media() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, IDXGIFactoryMedia>);

//
//
class _HW_3D_NO_VTABLE_ IInfo_queue : public IBase {
public:
	virtual Result
		add_application_message(
			_HW_3D_IN_ Info_queue_message_severity severity,
			_HW_3D_IN_ const _HW_3D_STD_ string& description
		) = 0;

	virtual Result
		add_message(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_message_category category,
			_HW_3D_IN_ Info_queue_message_severity severity,
			_HW_3D_IN_ DXGI_INFO_QUEUE_MESSAGE_ID id,
			_HW_3D_IN_ const _HW_3D_STD_ string& description
		) = 0;

	virtual Result
		add_retrieval_filter_entries(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_filter& filter
		) = 0;

	virtual Result
		add_storage_filter_entries(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_filter& filter
		) = 0;

	virtual void
		clear_retrieval_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual void
		clear_stroage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual void
		clear_stored_messages(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual BOOL
		get_break_on_category(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_message_category category
		) = 0;

	virtual BOOL
		get_break_on_id(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ DXGI_INFO_QUEUE_MESSAGE_ID id
		) = 0;

	virtual BOOL
		get_break_on_severity(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_message_severity severity
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Info_queue_message>
		get_message(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ UINT64 message_index
		) = 0;

	virtual UINT64
		get_message_count_limit(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual BOOL
		get_mute_debug_output(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual UINT64
		get_num_messages_allowed_by_storage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual UINT64
		get_num_message_denied_by_storage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual UINT64
		get_num_message_discarded_by_message_count_limit(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual UINT64
		get_num_stored_messages(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual UINT64
		get_num_stored_messages_allowed_by_retrieval_filters(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Info_queue_filter>
		get_retrieval_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual UINT
		get_retrieval_filter_stack_size(
			_HW_3D_IN_ DXGI_DEBUG_ID produer
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Info_queue_filter>
		get_storage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual UINT
		get_storage_filter_stack_size(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual void
		pop_retrieval_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual void
		pop_storage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual Result
		push_copy_of_retrieval_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID produer
		) = 0;

	virtual Result
		push_copy_of_storage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual Result
		push_deny_all_retrieval_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual Result
		push_deny_all_storage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual Result
		push_empty_retrieval_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual Result
		push_empty_storage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) = 0;

	virtual Result
		push_retrieval_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_filter& filter
		) = 0;

	virtual Result
		push_storage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_filter& filter
		) = 0;

	virtual Result
		set_break_on_category(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_message_category category,
			_HW_3D_IN_ BOOL enable
		) = 0;

	virtual Result
		set_break_on_id(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ DXGI_INFO_QUEUE_MESSAGE_ID id,
			_HW_3D_IN_ BOOL enable
		) = 0;

	virtual Result
		set_break_on_severity(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_message_severity severity,
			_HW_3D_IN_ BOOL enable
		) = 0;

	virtual Result
		set_message_count_limit(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ UINT64 message_count_limit
		) = 0;

	virtual void
		set_mute_debug_output(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ BOOL mute
		) = 0;

	virtual IDXGIInfoQueue* get() = 0;

	virtual const IDXGIInfoQueue* get() const = 0;

	virtual ~IInfo_queue() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, IDXGIInfoQueue>);

//
//
class _HW_3D_NO_VTABLE_ IKeyed_mutex : public IDevice_subobject {
public:
	virtual Result
		acquire_sync(
			_HW_3D_IN_ UINT64 key,
			_HW_3D_IN_ DWORD milliseconds
		) = 0;

	virtual Result
		release_sync(
			_HW_3D_IN_ UINT64 key
		) = 0;

	virtual IDXGIKeyedMutex* get() = 0;

	virtual const IDXGIKeyedMutex* get() const = 0;

	virtual ~IKeyed_mutex() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIDeviceSubObject, IDXGIKeyedMutex>);

//
//
class _HW_3D_NO_VTABLE_ IOutput : public IObject {
public:
	virtual _HW_3D_STD_ tuple<Result, Mode_desc>
		find_closest_matching_mode(
			_HW_3D_IN_ const Mode_desc& mode_to_match,
			_HW_3D_IN_ IBase* device
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Output_desc>
		get_desc(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<Mode_desc>>
		get_display_mode_list(
			_HW_3D_IN_ Format enum_format,
			_HW_3D_IN_ Display_mode flags
		) = 0;

	virtual Result
		get_display_surface_data(
			_HW_3D_IN_ ISurface* dest
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Frame_statistics>
		get_frame_statistics(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Gamma_control>
		get_camma_control(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Gamma_control_capabilities>
		get_gamma_control_capabilities(
		) = 0;

	virtual void
		release_ownership(
		) = 0;

	virtual Result
		set_display_surface(
			_HW_3D_IN_ ISurface* scanout_surface
		) = 0;

	virtual Result
		set_gamma_control(
			_HW_3D_IN_ const Gamma_control& arr
		) = 0;

	virtual Result
		take_ownership(
			_HW_3D_IN_ IBase* device,
			BOOL exclusive
		) = 0;

	virtual Result
		wait_for_v_blank(
		) = 0;

	virtual IDXGIOutput* get() = 0;

	virtual const IDXGIOutput* get() const = 0;

	virtual ~IOutput() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIObject, IDXGIOutput>);

//
//
class _HW_3D_NO_VTABLE_ IOutput1 : public IOutput {
public:
	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IOutput_duplication>>
		duplicate_output(
			_HW_3D_IN_ IBase* device
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Mode_desc1>
		find_closest_matching_mode1(
			_HW_3D_IN_ const Mode_desc1& mode_to_match,
			_HW_3D_IN_ IBase* concerned_device
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<Mode_desc1>>
		get_display_mode_list1(
			_HW_3D_IN_ Format enum_format,
			_HW_3D_IN_ Display_mode flags
		) = 0;

	virtual Result
		get_display_surface_data1(
			_HW_3D_IN_ IResource* dest
		) = 0;

	virtual IDXGIOutput1* get() = 0;

	virtual const IDXGIOutput1* get() const = 0;

	virtual ~IOutput1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIOutput, IDXGIOutput1>);

//
//
class _HW_3D_NO_VTABLE_ IOutput2 : public IOutput1 {
public:
	virtual BOOL
		supports_overlays(
		) = 0;

	virtual IDXGIOutput2* get() = 0;

	virtual const IDXGIOutput2* get() const = 0;

	virtual ~IOutput2() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIOutput1, IDXGIOutput2>);

//
//
class _HW_3D_NO_VTABLE_ IOutput3 : public IOutput2 {
public:
	virtual _HW_3D_STD_ tuple<Result, Overlay_support_flag>
		check_overlay_support(
			_HW_3D_IN_ Format enum_format,
			_HW_3D_IN_ IBase* device
		) = 0;

	virtual IDXGIOutput3* get() = 0;

	virtual const IDXGIOutput3* get() const = 0;

	virtual ~IOutput3() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIOutput2, IDXGIOutput3>);

//
//
class _HW_3D_NO_VTABLE_ IOutput4 : public IOutput3 {
public:
	virtual _HW_3D_STD_ tuple<Result, Overlay_color_space_support_flag>
		check_overlay_color_space_support(
			_HW_3D_IN_ Format format,
			_HW_3D_IN_ Color_space_type color_space,
			_HW_3D_IN_ IBase* device
		) = 0;

	virtual IDXGIOutput4* get() = 0;

	virtual const IDXGIOutput4* get() const = 0;

	virtual ~IOutput4() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIOutput3, IDXGIOutput4>);

//
//
class _HW_3D_NO_VTABLE_ IOutput5 : public IOutput4 {
public:
	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IOutput_duplication>>
		duplicate_output1(
			_HW_3D_IN_ IBase* device,
			_HW_3D_IN_ /*unused*/ UINT flags,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Format>& formats
		) = 0;

	virtual IDXGIOutput5* get() = 0;

	virtual const IDXGIOutput5* get() const = 0;

	virtual ~IOutput5() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIOutput4, IDXGIOutput5>);

//
//
class _HW_3D_NO_VTABLE_ IOutput6 : public IOutput5 {
public:
	virtual _HW_3D_STD_ tuple<Result, Output_desc1>
		get_desc1(
		) = 0;

	virtual IDXGIOutput6* get() = 0;

	virtual const IDXGIOutput6* get() const = 0;

	virtual ~IOutput6() { }
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIOutput5, IDXGIOutput6>);

//
//
class _HW_3D_NO_VTABLE_ IOutput_duplication : public IObject {
public:
	virtual _HW_3D_STD_ tuple<Result, Outdupl_frame_info, _HW_3D_STD_ unique_ptr<IResource>>
		acquire_next_frame(
			_HW_3D_IN_ UINT timeout_in_milliseconds
		) = 0;

	virtual Outdupl_desc
		get_desc(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<RECT>>
		get_frame_dirty_rects(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<Outdupl_move_rect>>
		get_frame_move_rects(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Outdupl_pointer_shape_info>
		get_frame_pointer_shape(
			_HW_3D_IN_ UINT buffer_size,
			_HW_3D_OUT_ void* buffer,
			_HW_3D_OUT_ UINT* buffer_size_required
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Mapped_rect>
		map_desktop_surface(
		) = 0;

	virtual Result
		release_frame(
		) = 0;

	virtual Result
		unmap_desktop_surface(
		) = 0;

	virtual IDXGIOutputDuplication* get() = 0;

	virtual const IDXGIOutputDuplication* get() const = 0;

	virtual ~IOutput_duplication() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIObject, IDXGIOutputDuplication>);

//
//
class _HW_3D_NO_VTABLE_ IResource : public IDevice_subobject {
public:
	virtual _HW_3D_STD_ tuple<Result, Resource_priority>
		get_eviction_priority(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, HANDLE>
		get_shared_handle(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Usage>
		get_usage(
		) = 0;

	virtual Result
		set_eviction_priority(
			_HW_3D_IN_ Resource_priority eviction_priority
		) = 0;

	virtual IDXGIResource* get() = 0;

	virtual const IDXGIResource* get() const = 0;

	virtual ~IResource() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIDeviceSubObject, IDXGIResource>);

//
//
class _HW_3D_NO_VTABLE_ IResource1 : public IResource {
public:
	virtual _HW_3D_STD_ tuple<Result, HANDLE>
		create_shared_handle(
			_HW_3D_IN_ const SECURITY_ATTRIBUTES& attributes,
			_HW_3D_IN_ DWORD access,
			_HW_3D_IN_ const _HW_3D_STD_ wstring& name
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISurface2>>
		create_subresource_surface(
			_HW_3D_IN_ UINT index
		) = 0;

	virtual IDXGIResource1* get() = 0;

	virtual const IDXGIResource1* get() const = 0;

	virtual ~IResource1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIResource, IDXGIResource1>);

//
//
class _HW_3D_NO_VTABLE_ ISurface : public IDevice_subobject {
public:
	virtual _HW_3D_STD_ tuple<Result, Surface_desc>
		get_desc(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Mapped_rect>
		map(
			_HW_3D_IN_ Map_flag flags
		) = 0;

	virtual Result
		unmap(
		) = 0;

	virtual IDXGISurface* get() = 0;

	virtual const IDXGISurface* get() const = 0;

	virtual ~ISurface() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIDeviceSubObject, IDXGISurface>);

//
//
class _HW_3D_NO_VTABLE_ ISurface1 : public ISurface {
public:
	virtual _HW_3D_STD_ tuple<Result, HDC>
		get_dc(
			_HW_3D_IN_ BOOL discard
		) = 0;

	virtual Result
		release_dc(
			_HW_3D_IN_ RECT* dirty_rect
		) = 0;

	virtual IDXGISurface1* get() = 0;

	virtual const IDXGISurface1* get() const = 0;

	virtual ~ISurface1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGISurface, IDXGISurface1>);

//
//
class _HW_3D_NO_VTABLE_ ISurface2 : public ISurface1 {
public:
	virtual Result
		get_resource(
			_HW_3D_IN_ REFIID riid,
			_HW_3D_IN_ void** p_parent_resource,
			_HW_3D_IN_ UINT* p_subresource_index
		) = 0;

	virtual IDXGISurface2* get() = 0;

	virtual const IDXGISurface2* get() const = 0;

	virtual ~ISurface2() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGISurface1, IDXGISurface2>);

//
//
class _HW_3D_NO_VTABLE_ ISwap_chain : public IDevice_subobject {
public:
	virtual _HW_3D_STD_ tuple<Result, void*>
		get_buffer(
			_HW_3D_IN_ UINT buffer,
			_HW_3D_IN_ REFIID riid
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IOutput>>
		get_containing_output(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Swap_chain_desc>
		get_desc(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Frame_statistics>
		get_frame_statistics(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, BOOL, _HW_3D_STD_ unique_ptr<IOutput>>
		get_fullscreen_state(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, UINT>
		get_last_present_count(
		) = 0;

	virtual Result
		present(
			_HW_3D_IN_ UINT interval,
			_HW_3D_IN_ Present_mode flags
		) = 0;

	virtual Result
		resize_buffers(
			_HW_3D_IN_ UINT buffer_count,
			_HW_3D_IN_ UINT width,
			_HW_3D_IN_ UINT height,
			_HW_3D_IN_ Format format,
			_HW_3D_IN_ Swap_chain_flag flags
		) = 0;

	virtual Result
		resize_target(
			_HW_3D_IN_ const Mode_desc& parameters
		) = 0;

	virtual Result
		set_fullscreen_state(
			_HW_3D_IN_ BOOL fullscreen,
			_HW_3D_IN_ IOutput* target
		) = 0;

	virtual IDXGISwapChain* get() = 0;

	virtual const IDXGISwapChain* get() const = 0;

	virtual ~ISwap_chain() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGIDeviceSubObject, IDXGISwapChain>);

//
//
class _HW_3D_NO_VTABLE_ ISwap_chain1 : public ISwap_chain {
public:
	virtual _HW_3D_STD_ tuple<Result, Rgba>
		get_background_color(
		) = 0;

	virtual Result
		get_core_window(
			_HW_3D_IN_ REFIID refiid,
			_HW_3D_OUT_ void** unk
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Swap_chain_desc1>
		get_desc1(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Swap_chain_fullscreen_desc>
		get_fullscreeen_desc(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, HWND>
		get_hwnd(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IOutput>>
		get_restrict_to_output(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Mode_rotation>
		get_rotation(
		) = 0;

	virtual BOOL
		is_temporary_mono_supported(
		) = 0;

	virtual Result
		present1(
			_HW_3D_IN_ UINT sync_interval,
			_HW_3D_IN_ Present_mode flags,
			_HW_3D_IN_ const Present_parameters& parameters
		) = 0;

	virtual Result
		set_background_color(
			_HW_3D_IN_ const Rgba& color
		) = 0;

	virtual Result
		set_rotation(
			_HW_3D_IN_ Mode_rotation rotation
		) = 0;

	virtual IDXGISwapChain1* get() = 0;

	virtual const IDXGISwapChain* get() const = 0;

	virtual ~ISwap_chain1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGISwapChain, IDXGISwapChain1>);

//
//
class _HW_3D_NO_VTABLE_ ISwap_chain2 : public ISwap_chain1 {
public:
	virtual HANDLE
		get_frame_latency_waitable_object(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, DXGI_MATRIX_3X2_F>
		get_matrix_transform(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, UINT>
		get_maximum_frame_latency(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, UINT, UINT>
		get_source_size(
		) = 0;

	virtual Result
		set_matrix_transform(
			_HW_3D_IN_ const DXGI_MATRIX_3X2_F& matrix
		) = 0;

	virtual Result
		set_maximum_frame_latency(
			_HW_3D_IN_ UINT max_latency
		) = 0;

	virtual Result
		set_source_size(
			_HW_3D_IN_ UINT width,
			_HW_3D_IN_ UINT height
		) = 0;

	virtual IDXGISwapChain2* get() = 0;

	virtual const IDXGISwapChain2* get() const = 0;

	virtual ~ISwap_chain2() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGISwapChain1, IDXGISwapChain2>);

//
//
class _HW_3D_NO_VTABLE_ ISwap_chain3 : public ISwap_chain2 {
public:
	virtual _HW_3D_STD_ tuple<Result, Swap_chain_color_space_support_flag>
		check_color_space_support(
			_HW_3D_IN_ Color_space_type color_space
		) = 0;

	virtual UINT
		get_current_back_buffer_index(
		) = 0;

	virtual Result
		resize_buffers1(
			_HW_3D_IN_ UINT width,
			_HW_3D_IN_ UINT height,
			_HW_3D_IN_ Format format,
			_HW_3D_IN_ Swap_chain_flag flags,
			_HW_3D_IN_ const _HW_3D_STD_ vector<UINT>& masks,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBase*>& present_queue
		) = 0;

	virtual Result
		set_color_space1(
			_HW_3D_IN_ Color_space_type color_space
		) = 0;

	virtual IDXGISwapChain3* get() = 0;

	virtual const IDXGISwapChain3* get() const = 0;

	virtual ~ISwap_chain3() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGISwapChain2, IDXGISwapChain3>);

//
//
class _HW_3D_NO_VTABLE_ ISwap_chain4 : public ISwap_chain3 {
public:
	virtual Result
		set_hdr_meta_data(
			_HW_3D_IN_ Hdr_metadata_type type,
			_HW_3D_IN_ UINT size,
			_HW_3D_IN_ void* meta_data
		) = 0;

	virtual IDXGISwapChain4* get() = 0;

	virtual const IDXGISwapChain4* get() const = 0;

	virtual ~ISwap_chain4() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IDXGISwapChain3, IDXGISwapChain4>);

//
//
class _HW_3D_NO_VTABLE_ ISwap_chain_media : public IBase {
public:
	virtual _HW_3D_STD_ tuple<Result, UINT, UINT>
		check_present_duration_support(
			_HW_3D_IN_ UINT desired_present_duration
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Frame_statistics_media>
		get_frame_statistics_media(
		) = 0;

	virtual Result
		set_present_duration(
			_HW_3D_IN_ UINT duration
		) = 0;

	virtual IDXGISwapChainMedia* get() = 0;

	virtual const IDXGISwapChainMedia* get() const = 0;

	virtual ~ISwap_chain_media() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, IDXGISwapChainMedia>);

_HW_3D_CLOSE_DXGI_NAMESPACE_


_HW_3D_OPEN_D3D_NAMESPACE_

class IBlend_state;
class IBuffer;
class IClass_linkage;
class ICompute_shader;
class ICounter;
class IDevice_context;
class IDepth_stencil_state;
class IResource;
class IDepth_stencil_view;
class IDomain_shader;
class IGeometry_shader;
class IHull_shader;
class IInput_layout;
class IPixel_shader;
class IPredicate;
class IQuery;
class IRasterizer_state;
class IRender_target_view;
class ISampler_state;
class IShader_resource_view;
class ITexture1d;
class ITexture2d;
class ITexture3d;
class IUnordered_access_view;
class IVertex_shader;
class IBlend_state1;
class IDevice_context1;
class IDevice_context_state;
class IRasterizer_state1;
class IDevice_context2;
class IDevice_context3;
class IQuery1;
class IRasterizer_state2;
class IRender_target_view1;
class IShader_resource_view1;
class ITexture2d1;
class ITexture3d1;
class IUnordered_access_view1;
class IFence;
class IClass_instance;
class IView;
class ILinking_node;
class IModule;
class IModule_instance;
class IBlob;
class IShader_reflection_constant_buffer;
class IFunction_parameter_reflection;
class IShader_reflection_variable;

//
//
class _HW_3D_NO_VTABLE_ IDevice : public IBase {
public:
	virtual _HW_3D_STD_ tuple<Result, Counter_type, Uint>
		check_counter(
			_HW_3D_IN_ const Counter_desc& desc,
			_HW_3D_OUT_ _HW_3D_STD_ string* p_name,
			_HW_3D_OUT_ _HW_3D_STD_ string* p_uints,
			_HW_3D_OUT_ _HW_3D_STD_ string* p_description
		) = 0;

	virtual Counter_info
		check_counter_info(
		) = 0;

	virtual Result
		check_feature_support(
			_HW_3D_IN_ Feature feature,
			_HW_3D_OUT_ void * p_data,
			_HW_3D_IN_ Uint data_size
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Format_support>
		check_format_support(
			_HW_3D_IN_ _HW_3D_DXGI_ Format format
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Uint>
		check_multisample_quality_levels(
			_HW_3D_IN_ _HW_3D_DXGI_ Format format,
			_HW_3D_IN_ Uint sample_count
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBlend_state>>
		create_blend_state(
			_HW_3D_IN_ const Blend_desc& desc
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBuffer>>
		create_buffer(
			_HW_3D_IN_ const Buffer_desc& desc,
			_HW_3D_IN_ const Subresource_data* p_data
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IClass_linkage>>
		create_class_linkage(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ICompute_shader>>
		create_compute_shader(
			_HW_3D_IN_ const void* shader_byte_code,
			_HW_3D_IN_ Size_t code_length,
			_HW_3D_IN_ IClass_linkage* p_linage
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ICounter>>
		create_counter(
			_HW_3D_IN_ const Counter_desc& desc
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDevice_context>>
		create_deferred_context(
			/*unused*/ Uint flags = 0
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDepth_stencil_state>>
		create_depth_stencil_state(
			_HW_3D_IN_ const Depth_stencil_desc& desc
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDepth_stencil_view>>
		create_depth_stencil_view(
			_HW_3D_IN_ IResource* p_resource,
			_HW_3D_IN_ const Depth_stencil_view_desc* p_desc
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDomain_shader>>
		create_domain_shader(
			_HW_3D_IN_ const void* shader_byte_code,
			_HW_3D_IN_ Size_t code_length,
			_HW_3D_IN_ IClass_linkage* p_linage
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IGeometry_shader>>
		create_geometry_shader(
			_HW_3D_IN_ const void* shader_byte_code,
			_HW_3D_IN_ Size_t code_length,
			_HW_3D_IN_ IClass_linkage* p_linage
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IGeometry_shader>>
		create_geometry_shader_with_stream_output(
			_HW_3D_IN_ const void* shader_byte_code,
			_HW_3D_IN_ Size_t code_length,
			_HW_3D_IN_ const _HW_3D_STD_ vector<So_declaration_entry>& entrys,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& buffer_strides,
			_HW_3D_IN_ Uint rasteried_stream,
			_HW_3D_IN_ IClass_linkage* p_linage
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IHull_shader>>
		create_hull_shader(
			_HW_3D_IN_ const void* shader_byte_code,
			_HW_3D_IN_ Size_t code_length,
			_HW_3D_IN_ IClass_linkage* p_linage
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IInput_layout>>
		create_input_layout(
			_HW_3D_IN_ const  _HW_3D_STD_ vector<Input_element_desc>& descs,
			_HW_3D_IN_ const void* shader_byte_code,
			_HW_3D_IN_ Size_t code_length
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IPixel_shader>>
		create_pixel_shader(
			_HW_3D_IN_ const void* shader_byte_code,
			_HW_3D_IN_ Size_t code_length,
			_HW_3D_IN_ IClass_linkage* p_linage
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IPredicate>>
		create_perdicate(
			_HW_3D_IN_ const Query_desc& desc
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IQuery>>
		create_query(
			_HW_3D_IN_ const Query_desc& desc
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IRasterizer_state>>
		create_rasterizer_state(
			_HW_3D_IN_ const Rasterizer_desc& desc
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IRender_target_view>>
		create_render_target_view(
			_HW_3D_IN_ IResource* p_resource,
			_HW_3D_IN_ const Render_target_view_desc* p_desc
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISampler_state>>
		create_sampler_state(
			_HW_3D_IN_ const Sampler_desc& desc
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IShader_resource_view>>
		create_shader_resource_view(
			_HW_3D_IN_ IResource* p_resource,
		_HW_3D_IN_ const Shader_resource_view_desc* p_desc
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ITexture1d>>
		create_texture_1d(
			_HW_3D_IN_ const Texture1d_desc& desc,
			_HW_3D_IN_ const Subresource_data* p_data
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ITexture2d>>
		create_texture_2d(
			_HW_3D_IN_ const Texture2d_desc& desc,
			_HW_3D_IN_ const Subresource_data* p_data
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ITexture3d>>
		create_texture_3d(
			_HW_3D_IN_ const Texture3d_desc& desc,
			_HW_3D_IN_ const Subresource_data* p_data
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IUnordered_access_view>>
		create_unordered_access_view(
			_HW_3D_IN_ IResource* p_resouce,
			_HW_3D_IN_ const Unordered_access_view_desc* p_desc
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IVertex_shader>>
		create_vertex_shader(
			_HW_3D_IN_ const void* shader_byte_code,
			_HW_3D_IN_ Size_t code_length,
			_HW_3D_IN_ IClass_linkage* p_linage
		) = 0;

	virtual Create_device_flag
		get_creation_falgs(
		) = 0;

	virtual Result
		get_device_removed_reason(
		) = 0;

	virtual Raise_flag
		get_exception_mode(
		) = 0;

	virtual Feature_level
		get_feature_level(
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IDevice_context>
		get_immediate_context(
		) = 0;

	virtual Result
		get_private_data(
			_HW_3D_IN_ REFGUID guid,
			_HW_3D_IN_OUT_ Uint* p_size,
			_HW_3D_OUT_ void * p_data
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, void*>
		open_shared_resource(
			_HW_3D_IN_ HANDLE h_resource,
			_HW_3D_IN_ REFIID returned_interface
		) = 0;

	virtual Result
		set_exception_mode(
			_HW_3D_IN_ Raise_flag flags
		) = 0;

	virtual Result
		set_private_data(
			_HW_3D_IN_ REFGUID guid,
			_HW_3D_IN_ Uint size,
			_HW_3D_IN_ const void* p_data
		) = 0;

	virtual Result
		set_private_data_interface(
			_HW_3D_IN_ REFGUID guid,
			_HW_3D_IN_ const IBase* p_data
		) = 0;

	virtual ID3D11Device* get() = 0;

	virtual const ID3D11Device* get() const = 0;

	virtual ~IDevice() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3D11Device>);

//
//
class _HW_3D_NO_VTABLE_ IDevice1 : public IDevice {
public:
	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBlend_state1>>
		create_blend_state1(
			_HW_3D_IN_ const Blend_desc1& desc
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDevice_context1>>
		create_deferred_context1(
			/*unused*/ Uint flags = 0
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Feature_level, _HW_3D_STD_ unique_ptr<IDevice_context_state>>
		create_device_context_state(
			_HW_3D_IN_ Create_device_context_state_flag flags,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Feature_level>& feature_levels,
			_HW_3D_IN_ Uint sdk_version,
			_HW_3D_IN_ REFIID enumlated_interface
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IRasterizer_state1>>
		create_rasterizer_state1(
			_HW_3D_IN_ const Rasterizer_desc1& desc
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IDevice_context1>
		get_immediate_context1(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, void*>
		open_shared_resource1(
			_HW_3D_IN_ HANDLE h_resource,
			_HW_3D_IN_ REFIID returned_interface
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, void*>
		open_shared_resource_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ wstring& name,
			_HW_3D_IN_ DWORD desired_access,
			_HW_3D_IN_ REFIID returned_interface
		) = 0;

	virtual ID3D11Device1* get() = 0;

	virtual const ID3D11Device1* get() const = 0;

	virtual ~IDevice1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11Device, ID3D11Device1>);

//
//
class _HW_3D_NO_VTABLE_ IDevice2 : public IDevice1 {
public:
	virtual _HW_3D_STD_ tuple<Result, Uint>
		check_multisample_quality_levels1(
			_HW_3D_IN_ _HW_3D_DXGI_ Format format,
			_HW_3D_IN_ Uint sample_count,
			_HW_3D_IN_ Check_multisample_quality_levels_flag flags
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDevice_context2>>
		create_deferred_context2(
			/*unused */ Uint flags = 0
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IDevice_context2>
		get_immediate_context2(
		) = 0;

	virtual Subresource_tiling
		get_resource_tiling(
			_HW_3D_IN_ IResource* resource,
			_HW_3D_OUT_ Uint* num_tiles,
			_HW_3D_OUT_ Packed_mip_desc* packed_mip_desc,
			_HW_3D_OUT_ Tile_shape* shape_for_non_packed_mips,
			_HW_3D_IN_OUT_ Uint* num_subresource_tilings,
			_HW_3D_IN_ Uint first_subresource_tilling
		) = 0;

	virtual ID3D11Device2* get() = 0;

	virtual const ID3D11Device2* get() const = 0;

	virtual ~IDevice2() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11Device1, ID3D11Device2>);

//
//
class _HW_3D_NO_VTABLE_ IDevice3 : public IDevice2 {
public:
	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDevice_context3>>
		create_deferred_context3(
			/*unused*/ Uint flags = 0
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IQuery1>>
		create_query1(
			_HW_3D_IN_ const Query_desc1& desc
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IRasterizer_state2>>
		create_rasterizer_state2(
			_HW_3D_IN_ const Rasterizer_desc2& desc
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IRender_target_view1>>
		create_render_target_view1(
			_HW_3D_IN_ IResource* resource,
			_HW_3D_IN_ const Render_target_view_desc1& desc
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IShader_resource_view1>>
		create_shader_resource_view1(
			_HW_3D_IN_ IResource* resource,
			_HW_3D_IN_ const Shader_resource_view_desc1& desc
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ITexture2d1>>
		create_texture_2d1(
			_HW_3D_IN_ const Texture2d_desc1& desc,
			_HW_3D_IN_ const Subresource_data* data
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ITexture3d1>>
		create_texture_3d1(
			_HW_3D_IN_ const Texture3d_desc1& desc,
			_HW_3D_IN_ const Subresource_data* data
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IUnordered_access_view1>>
		create_unordered_access_view1(
			_HW_3D_IN_ IResource* resouce,
			_HW_3D_IN_ const Unordered_access_view_desc1& desc
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IDevice_context3>
		get_immediate_context3(
		) = 0;

	virtual void
		read_from_subresource(
			_HW_3D_OUT_ void* data,
			_HW_3D_IN_ Uint row_pitch,
			_HW_3D_IN_ Uint depth_pitch,
			_HW_3D_IN_ IResource* resouce,
			_HW_3D_IN_ Uint sub_resource,
			_HW_3D_IN_ const Box* box
		) = 0;

	virtual void
		write_to_subresource(
			_HW_3D_IN_ IResource* resouce,
			_HW_3D_IN_ Uint subresource,
			_HW_3D_IN_ const Box* box,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ Uint row_pitch,
			_HW_3D_IN_ Uint depth_pitch
		) = 0;

	virtual ID3D11Device3* get() = 0;

	virtual const ID3D11Device3* get() const = 0;

	virtual ~IDevice3() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11Device2, ID3D11Device3>);

//
//
class _HW_3D_NO_VTABLE_ IDevice4 : public IDevice3 {
public:
	virtual _HW_3D_STD_ tuple<Result, DWORD>
		register_device_removed_event(
			_HW_3D_IN_ HANDLE h_event
		) = 0;

	virtual void
		unregister_device_removed(
			_HW_3D_IN_ DWORD cookie
		) = 0;

	virtual ID3D11Device4* get() = 0;

	virtual const ID3D11Device4* get() const = 0;

	virtual ~IDevice4() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11Device3, ID3D11Device4>);

//
//
class _HW_3D_NO_VTABLE_ IDevice5 : public IDevice4 {
public:
	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IFence>>
		create_fence(
			_HW_3D_IN_ Uint64 value,
			_HW_3D_IN_ Fence_flag flags,
			_HW_3D_IN_ REFIID riid
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IFence>>
		open_shared_fence(
			_HW_3D_IN_ HANDLE fence,
			_HW_3D_IN_ REFIID returned_interface
		) = 0;

	virtual ID3D11Device5* get() = 0;

	virtual const ID3D11Device5* get() const = 0;

	virtual ~IDevice5() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11Device4, ID3D11Device5>);

//
//
class _HW_3D_NO_VTABLE_ IDevice_child : public IBase {
public:
	virtual _HW_3D_STD_ unique_ptr<IDevice>
		get_device(
		) = 0;

	virtual Result
		get_private_data(
			_HW_3D_IN_ REFGUID guid,
			_HW_3D_IN_OUT_ Uint* size,
			_HW_3D_OUT_ void* data
		) = 0;

	virtual Result
		set_private_data(
			_HW_3D_IN_ REFGUID guid,
			_HW_3D_IN_ Uint size,
			_HW_3D_IN_ const void* data
		) = 0;

	virtual Result
		set_private_data_interface(
			_HW_3D_IN_ REFGUID guid,
			_HW_3D_IN_ const IBase* data
		) = 0;

	virtual ID3D11DeviceChild* get() = 0;

	virtual const ID3D11DeviceChild* get() const = 0;

	virtual ~IDevice_child() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3D11DeviceChild>);

//
//
class _HW_3D_NO_VTABLE_ IAsynchronous : public IDevice_child {
public:
	virtual Uint
		get_data_size(
		) = 0;

	virtual ID3D11Asynchronous* get() = 0;

	virtual const ID3D11Asynchronous* get() const = 0;

	virtual ~IAsynchronous() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11Asynchronous>);

//
//
class _HW_3D_NO_VTABLE_ IBlend_state : public IDevice_child {
public:
	virtual Blend_desc
		get_desc(
		) = 0;

	virtual ID3D11BlendState* get() = 0;

	virtual const ID3D11BlendState* get() const = 0;

	virtual ~IBlend_state() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11BlendState>);

//
//
class _HW_3D_NO_VTABLE_ IBlend_state1 : public IBlend_state {
public:
	virtual Blend_desc1
		get_desc1(
		) = 0;

	virtual ID3D11BlendState1* get() = 0;

	virtual const ID3D11BlendState1* get() const = 0;

	virtual ~IBlend_state1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11BlendState, ID3D11BlendState1>);

//
//
class _HW_3D_NO_VTABLE_ ICommand_list : public IDevice_child {
public:
	virtual /*unused*/ Uint
		get_context_flags(
		) = 0;

	virtual ID3D11CommandList* get() = 0;

	virtual const ID3D11CommandList* get() const = 0;

	virtual ~ICommand_list() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11CommandList>);

//
//
class _HW_3D_NO_VTABLE_ ICounter : public IAsynchronous {
public:
	virtual Counter_desc
		get_desc(
		) = 0;

	virtual ID3D11Counter* get() = 0;

	virtual const ID3D11Counter* get() const = 0;

	virtual ~ICounter() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11Asynchronous, ID3D11Counter>);

//
//
class _HW_3D_NO_VTABLE_ IDepth_stencil_state : public IDevice_child {
public:
	virtual Depth_stencil_desc
		get_desc(
		) = 0;

	virtual ID3D11DepthStencilState* get() = 0;

	virtual const ID3D11DepthStencilState* get() const = 0;

	virtual ~IDepth_stencil_state() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11DepthStencilState>);

//
//
class _HW_3D_NO_VTABLE_ IDevice_context : public IDevice_child {
public:
	virtual void
		begin(
			_HW_3D_IN_ IAsynchronous* async
		) = 0;

	virtual void
		clear_depth_stencil_view(
			_HW_3D_IN_ IDepth_stencil_view* view,
			_HW_3D_IN_ Clear_flag flags,
			_HW_3D_IN_ Float depth,
			_HW_3D_IN_ Uint8 stencil
		) = 0;

	virtual void
		clear_render_target_view(
			_HW_3D_IN_ IRender_target_view*  view,
			_HW_3D_IN_ const _HW_3D_STD_ array<Float, 4>& color
		) = 0;

	virtual void
		clear_state(
		) = 0;

	virtual void
		clear_unordered_access_view_float(
			_HW_3D_IN_ IUnordered_access_view* view,
			_HW_3D_IN_ const _HW_3D_STD_ array<Float, 4>& val
		) = 0;

	virtual void
		clear_unordered_access_view_uint(
			_HW_3D_IN_ IUnordered_access_view* view,
			_HW_3D_IN_ const _HW_3D_STD_ array<Uint, 4>& val
		) = 0;

	virtual void
		copy_resource(
			_HW_3D_IN_ IResource* dst,
			_HW_3D_IN_ IResource* src
		) = 0;

	virtual void
		copy_structure_count(
			_HW_3D_IN_ IBuffer* dst,
			_HW_3D_IN_ Uint aligned_offset,
			_HW_3D_IN_ IUnordered_access_view* src
		) = 0;

	virtual void
		copy_subresource_region(
			_HW_3D_IN_ IResource* dst,
			_HW_3D_IN_ Uint dst_subresource,
			_HW_3D_IN_ _HW_3D_STD_ array<Uint, 3> offset,
			_HW_3D_IN_ IResource* src,
			_HW_3D_IN_ Uint src_subresource,
			_HW_3D_IN_ const Box* range
		) = 0;

	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>
		cs_get_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) = 0;

	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>>
		cs_get_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_samplers
		) = 0;

	virtual _HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<ICompute_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>>
		cs_get_shader(
		) = 0;


	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>>
		cs_get_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_views
		) = 0;

	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IUnordered_access_view>>
		cs_get_unordered_access_views(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_uavs
		) = 0;

	virtual  void
		cs_set_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& constant_buffers
		) = 0;

	virtual void
		cs_set_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<ISampler_state*>& samplers
		) = 0;

	virtual void
		cs_set_shader(
			_HW_3D_IN_ ICompute_shader* shader,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IClass_instance*>& instances
		) = 0;

	virtual void
		cs_set_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IShader_resource_view*>& views
		) = 0;

	virtual void
		cs_set_unordered_access_views(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IUnordered_access_view*>& views,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& initial_counts
		) = 0;

	virtual void
		dispatch(
			_HW_3D_IN_ _HW_3D_STD_ array<Uint, 3> size
		) = 0;

	virtual void
		dispatch_indirect(
			_HW_3D_IN_ IBuffer* buffer,
			_HW_3D_IN_ Uint offset
		) = 0;

	virtual void
		draw(
			_HW_3D_IN_ Uint count,
			_HW_3D_IN_ Uint first
		) = 0;

	virtual void
		draw_auto(
		) = 0;

	virtual void
		draw_indexed(
			_HW_3D_IN_ Uint count,
			_HW_3D_IN_ Uint first,
			_HW_3D_IN_ Int base_vertex
		) = 0;

	virtual void
		draw_indexed_instanced(
			_HW_3D_IN_ Uint count,
			_HW_3D_IN_ Uint instance_count,
			_HW_3D_IN_ Uint first,
			_HW_3D_IN_ Int base_vertex,
			_HW_3D_IN_ Uint first_isntance
		) = 0;

	virtual void
		draw_indexed_instanced_indirect(
			_HW_3D_IN_ IBuffer* buffer,
			_HW_3D_IN_ Uint offset
		) = 0;

	virtual void
		draw_instanced(
			_HW_3D_IN_ Uint count,
			_HW_3D_IN_ Uint instance_count,
			_HW_3D_IN_ Uint first,
			_HW_3D_IN_ Uint first_instance
		) = 0;

	virtual void
		draw_instanced_indirect(
			_HW_3D_IN_ IBuffer* buffer,
			_HW_3D_IN_ Uint offset
		) = 0;

	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>
		ds_get_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) = 0;

	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>>
		ds_get_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_samplers
		) = 0;

	virtual _HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IDomain_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>>
		ds_get_shader(
		) = 0;

	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>>
		ds_get_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_views
		) = 0;

	virtual  void
		ds_set_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& constant_buffers
		) = 0;

	virtual void
		ds_set_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<ISampler_state*>& samplers
		) = 0;

	virtual void
		ds_set_shader(
			_HW_3D_IN_ IDomain_shader* shader,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IClass_instance*>& instances
		) = 0;

	virtual void
		ds_set_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IShader_resource_view*>& views
		) = 0;

	virtual void
		end(
			_HW_3D_IN_ IAsynchronous* async
		) = 0;

	virtual void
		execute_command_list(
			_HW_3D_IN_ ICommand_list *command_list,
			_HW_3D_IN_ Bool restore_context_state
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ICommand_list>>
		finish_command_list(
			_HW_3D_IN_ Bool restore_deferred_context_state
		) = 0;

	virtual void
		flush(
		) = 0;

	virtual void
		generate_mips(
			_HW_3D_IN_ IShader_resource_view* view
		) = 0;

	virtual /*unused*/ Uint
		get_context_flags(
		) = 0;

	virtual Result
		get_data(
			_HW_3D_IN_ IAsynchronous* aysnc,
			_HW_3D_OUT_ void* data,
			_HW_3D_IN_ Uint size,
			_HW_3D_IN_ Async_get_data_flag flags
		) = 0;

	virtual _HW_3D_STD_ tuple<Bool, _HW_3D_STD_ unique_ptr<IPredicate>>
		get_predication(
		) = 0;

	virtual Float
		get_resource_min_lod(
			_HW_3D_IN_ IResource* resource
		) = 0;

	virtual Device_context_type
		get_type(
		) = 0;

	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>
		gs_get_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) = 0;

	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>>
		gs_get_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_samplers
		) = 0;

	virtual _HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IGeometry_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>>
		gs_get_shader(
		) = 0;


	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>>
		gs_get_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_views
		) = 0;

	virtual  void
		gs_set_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& constant_buffers
		) = 0;

	virtual void
		gs_set_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<ISampler_state*>& samplers
		) = 0;

	virtual void
		gs_set_shader(
			_HW_3D_IN_ IGeometry_shader* shader,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IClass_instance*>& instances
		) = 0;

	virtual void
		gs_set_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IShader_resource_view*>& views
		) = 0;

	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>
		hs_get_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) = 0;

	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>>
		hs_get_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_samplers
		) = 0;

	virtual _HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IHull_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>>
		hs_get_shader(
		) = 0;


	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>>
		hs_get_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_views
		) = 0;

	virtual  void
		hs_set_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& constant_buffers
		) = 0;

	virtual void
		hs_set_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<ISampler_state*>& samplers
		) = 0;

	virtual void
		hs_set_shader(
			_HW_3D_IN_ IHull_shader* shader,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IClass_instance*>& instances
		) = 0;

	virtual void
		hs_set_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IShader_resource_view*>& views
		) = 0;

	virtual _HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IBuffer>,  _HW_3D_DXGI_ Format, Uint>
		ia_get_index_buffer(
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IInput_layout>
		ia_get_input_layout(
		) = 0;

	virtual Primitive_topology
		ia_get_primitive_topology(
		) = 0;

	virtual _HW_3D_STD_ vector<_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IBuffer>, Uint, Uint>>
		ia_get_vertex_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) = 0;

	virtual void
		ia_set_index_buffer(
			_HW_3D_IN_ IBuffer* index_buffer,
			_HW_3D_IN_ _HW_3D_DXGI_ Format format,
			_HW_3D_IN_ Uint offset
		) = 0;

	virtual void
		ia_set_input_layout(
			_HW_3D_IN_ IInput_layout* layout
		) = 0;

	virtual void
		ia_set_primitive_topology(
			_HW_3D_IN_ Primitive_topology topology
		) = 0;

	virtual void
		ia_set_vertex_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*> buffers,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint> strides,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint> offsets
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Mapped_subresource>
		map(
			_HW_3D_IN_ IResource* resource,
			_HW_3D_IN_ Uint subresource,
			_HW_3D_IN_ Map type,
			_HW_3D_IN_ Map_flag flags
		) = 0;

	virtual _HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IBlend_state>, _HW_3D_STD_ array<Float, 4>, Uint>
		om_get_blend_state(
		) = 0;

	virtual _HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IDepth_stencil_state>, Uint>
		om_get_depth_stencil_state(
		) = 0;

	virtual _HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IRender_target_view>>, _HW_3D_STD_ unique_ptr<IDepth_stencil_view>>
		om_get_render_targets(
			Uint num_views
		) = 0;

	virtual _HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IRender_target_view>>, _HW_3D_STD_ unique_ptr<IDepth_stencil_view>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IUnordered_access_view>>>
		om_get_render_targets_and_unordered_access_views(
			_HW_3D_IN_ Uint num_rtvs,
			_HW_3D_IN_ Uint uav_start_slot,
			_HW_3D_IN_ Uint num_uavs
		) = 0;

	virtual void
		om_set_blend_state(
			_HW_3D_IN_ IBlend_state* state,
			_HW_3D_IN_ const _HW_3D_STD_ array<Float, 4>& blend_color,
			_HW_3D_IN_ Uint sample_mask
		) = 0;

	virtual void
		om_set_depth_stencil_state(
			_HW_3D_IN_ IDepth_stencil_state* state,
			_HW_3D_IN_ Uint stencil_ref
		) = 0;

	virtual void
		om_set_render_targets(
			_HW_3D_IN_ const _HW_3D_STD_ vector<IRender_target_view*>& rtvs,
			_HW_3D_IN_ IDepth_stencil_view* dsv
		) = 0;

	virtual void
		om_set_render_targets_and_unordered_access_views(
			_HW_3D_IN_ const _HW_3D_STD_ vector<IRender_target_view*>& rtvs,
			_HW_3D_IN_ IDepth_stencil_view* dsv,
			_HW_3D_IN_ Uint uav_start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IUnordered_access_view*>& uavs,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& uav_init_count
		) = 0;

	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>
		ps_get_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) = 0;

	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>>
		ps_get_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_samplers
		) = 0;

	virtual _HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IPixel_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>>
		ps_get_shader(
		) = 0;


	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>>
		ps_get_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_views
		) = 0;

	virtual  void
		ps_set_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& constant_buffers
		) = 0;

	virtual void
		ps_set_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<ISampler_state*>& samplers
		) = 0;

	virtual void
		ps_set_shader(
			_HW_3D_IN_ IPixel_shader* shader,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IClass_instance*>& instances
		) = 0;

	virtual void
		ps_set_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IShader_resource_view*>& views
		) = 0;

	virtual void
		resolve_subresource(
			_HW_3D_IN_ IResource* dst,
			_HW_3D_IN_ Uint dst_subresource,
			_HW_3D_IN_ IResource* src,
			_HW_3D_IN_ Uint src_subresource,
			_HW_3D_IN_ _HW_3D_DXGI_ Format format
		) = 0;

	virtual _HW_3D_STD_ vector<Rect>
		rs_get_scissor_rects(
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IRasterizer_state>
		rs_get_state(
		) = 0;

	virtual _HW_3D_STD_ vector<Viewport>
		rs_get_viewports(
		) = 0;

	virtual void
		rs_set_scissor_rects(
			_HW_3D_IN_ const _HW_3D_STD_ vector<Rect>& rects
		) = 0;

	virtual void
		rs_set_state(
			_HW_3D_IN_ IRasterizer_state* state
		) = 0;

	virtual void
		rs_set_viewports(
			_HW_3D_IN_ const _HW_3D_STD_ vector<Viewport>& viewports
		) = 0;

	virtual void
		set_predication(
			_HW_3D_IN_ IPredicate* predicate,
			_HW_3D_IN_ Bool value
		) = 0;

	virtual void
		set_resource_min_lod(
			_HW_3D_IN_ IResource* resource,
			_HW_3D_IN_ Float min_lod
		) = 0;

	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>
		so_get_targets(
			_HW_3D_IN_ Uint num_buffers
		) = 0;

	virtual void
		so_set_targets(
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& buffers,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& offset
		) = 0;

	virtual void
		unmap(
			_HW_3D_IN_ IResource* resouce,
			_HW_3D_IN_ Uint subresouce
		) = 0;

	virtual void
		update_subresource(
			_HW_3D_IN_ IResource* dst,
			_HW_3D_IN_ Uint subresource,
			_HW_3D_IN_ const Box* box,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ Uint src_row_pitch,
			_HW_3D_IN_ Uint src_depth_pitch
		) = 0;

	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>
		vs_get_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) = 0;

	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>>
		vs_get_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_samplers
		) = 0;

	virtual _HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IVertex_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>>
		vs_get_shader(
		) = 0;


	virtual _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>>
		vs_get_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_views
		) = 0;

	virtual  void
		vs_set_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& constant_buffers
		) = 0;

	virtual void
		vs_set_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<ISampler_state*>& samplers
		) = 0;

	virtual void
		vs_set_shader(
			_HW_3D_IN_ IVertex_shader* shader,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IClass_instance*>& instances
		) = 0;

	virtual void
		vs_set_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IShader_resource_view*>& views
		) = 0;

	virtual ID3D11DeviceContext* get() = 0;

	virtual const ID3D11DeviceContext* get() const = 0;

	virtual ~IDevice_context() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11DeviceContext>);

//
//
class _HW_3D_NO_VTABLE_ IDevice_context1 : public IDevice_context {
public:
	virtual void
		clear_view(
			_HW_3D_IN_ IView* view,
			_HW_3D_IN_ const _HW_3D_STD_ array<Float, 4>& color,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Rect>& rects
		) = 0;

	virtual void
		copy_subresource_region1(
			_HW_3D_IN_ IResource* dst,
			_HW_3D_IN_ Uint dst_subresource,
			_HW_3D_IN_ _HW_3D_STD_ array<Uint, 3> offset,
			_HW_3D_IN_ IResource* src,
			_HW_3D_IN_ Uint src_subresource,
			_HW_3D_IN_ const Box* box,
			_HW_3D_IN_ Copy_flag flags
		) = 0;

	virtual _HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>>
		cs_get_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) = 0;

	virtual void
		cs_set_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& buffses,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& first_constant,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& num_constant
		) = 0;

	virtual void
		discard_resource(
			_HW_3D_IN_ IResource* resource
		) = 0;

	virtual void
		discard_view(
			_HW_3D_IN_ IView* view
		) = 0;

	virtual void
		discard_view1(
			_HW_3D_IN_ IView* view,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Rect>& rects
		) = 0;

	virtual _HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>>
		ds_get_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) = 0;

	virtual void
		ds_set_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& buffses,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& first_constant,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& num_constant
		) = 0;

	virtual _HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>>
		gs_get_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) = 0;

	virtual void
		gs_set_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& buffses,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& first_constant,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& num_constant
		) = 0;

	virtual _HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>>
		hs_get_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) = 0;

	virtual void
		hs_set_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& buffses,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& first_constant,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& num_constant
		) = 0;

	virtual _HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>>
		ps_get_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) = 0;

	virtual void
		ps_set_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& buffses,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& first_constant,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& num_constant
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IDevice_context_state>
		swap_device_context_state(
			_HW_3D_IN_ IDevice_context_state* state
		) = 0;

	virtual void
		update_subresource1(
			_HW_3D_IN_ IResource* dst,
			_HW_3D_IN_ Uint dst_subresource,
			_HW_3D_IN_ const Box* box,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ Uint src_row_pitch,
			_HW_3D_IN_ Uint src_depth_pitch,
			_HW_3D_IN_ Copy_flag flags
		) = 0;

	virtual _HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>>
		vs_get_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) = 0;

	virtual void
		vs_set_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& buffses,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& first_constant,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& num_constant
		) = 0;

	virtual ID3D11DeviceContext1* get() = 0;

	virtual const ID3D11DeviceContext1* get() const = 0;

	virtual ~IDevice_context1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceContext, ID3D11DeviceContext1>);

//
//
class _HW_3D_NO_VTABLE_ IDevice_context2 : public IDevice_context1 {
public:
	virtual void
		update_tiles(
			_HW_3D_IN_ IResource* dst,
			_HW_3D_IN_ const Tiled_resource_coordinate& resource_coordinate,
			_HW_3D_IN_ const Tile_region_size& size,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ Tile_copy_flag flags
		) = 0;

	virtual void
		begin_event_int(
			_HW_3D_IN_ const _HW_3D_STD_ wstring& label,
			_HW_3D_IN_ Int data
		) = 0;

	virtual Result
		copy_tile_mapping(
			_HW_3D_IN_ IResource* dst,
			_HW_3D_IN_ const Tiled_resource_coordinate& dst_coord,
			_HW_3D_IN_ IResource* src,
			_HW_3D_IN_ const Tiled_resource_coordinate& src_coord,
			_HW_3D_IN_ const Tile_region_size& size,
			_HW_3D_IN_ Tile_mapping_flag flags
		) = 0;

	virtual void
		copy_tiles(
			_HW_3D_IN_ IResource* resouce,
			_HW_3D_IN_ const Tiled_resource_coordinate& region_coord,
			_HW_3D_IN_ const Tile_region_size& size,
			_HW_3D_IN_ IBuffer* buffer,
			_HW_3D_IN_ Uint64 offset,
			_HW_3D_IN_ Tile_copy_flag flags
		) = 0;

	virtual void
		end_event(
		) = 0;

	virtual Bool
		is_annotation_enabled(
		) = 0;

	virtual Result
		resize_tile_pool(
			_HW_3D_IN_ IBuffer* pool,
			_HW_3D_IN_ Uint64 size
		) = 0;

	virtual void
		set_marker_int(
			_HW_3D_IN_ const _HW_3D_STD_ wstring& label,
			_HW_3D_IN_ Int data
		) = 0;

	virtual void
		tiled_resource_barrier(
			_HW_3D_IN_ IDevice_child* before,
			_HW_3D_IN_ IDevice_child* after
		) = 0;

	virtual Result
		update_tile_mappings(
			_HW_3D_IN_ IResource* reource,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Tiled_resource_coordinate>& coords,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Tile_region_size>& sizes,
			_HW_3D_IN_ IBuffer* pool,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Tile_range_flag>& range_flags,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& range_offset,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& tile_counts,
			_HW_3D_IN_ Tile_mapping_flag flags
		) = 0;


	virtual ID3D11DeviceContext2* get() = 0;

	virtual const ID3D11DeviceContext2* get() const = 0;

	virtual ~IDevice_context2() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceContext1, ID3D11DeviceContext2>);

//
//
class _HW_3D_NO_VTABLE_ IDevice_context3 : public IDevice_context2 {
public:
	virtual void
		flush1(
			_HW_3D_IN_ Context_type type,
			_HW_3D_IN_ HANDLE h_event
		) = 0;

	virtual Bool
		get_hardware_protection_state(
		) = 0;

	virtual void
		set_hardware_protection_state(
			Bool enabled
		) = 0;

	virtual ID3D11DeviceContext3* get() = 0;

	virtual const ID3D11DeviceContext3* get() const = 0;

	virtual ~IDevice_context3() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceContext2, ID3D11DeviceContext3>);

//
//
class _HW_3D_NO_VTABLE_ IDevice_context4 : public IDevice_context3 {
public:
	virtual Result
		signal(
			_HW_3D_IN_ IFence* fence,
			Uint64 value
		) = 0;

	virtual Result
		wait(
			_HW_3D_IN_ IFence* fence,
			Uint64 value
		) = 0;


	virtual ID3D11DeviceContext4* get() = 0;

	virtual const ID3D11DeviceContext4* get() const = 0;

	virtual ~IDevice_context4() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceContext3, ID3D11DeviceContext4>);

//
//
class _HW_3D_NO_VTABLE_ IDevice_context_state : public IDevice_child {
public:
	virtual ID3DDeviceContextState* get() = 0;

	virtual const ID3DDeviceContextState* get() const = 0;

	virtual ~IDevice_context_state() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3DDeviceContextState>);

//
//
class _HW_3D_NO_VTABLE_ IFence : public IDevice_child {
public:
	virtual _HW_3D_STD_ tuple<Result, HANDLE>
		create_shared_handle(
			_HW_3D_IN_ const SECURITY_ATTRIBUTES* attributes,
			_HW_3D_IN_ DWORD access,
			_HW_3D_IN_ const _HW_3D_STD_ wstring& name
		) = 0;


	virtual Uint64
		get_complete_value(
		) = 0;

	virtual Result
		set_event_on_completion(
			_HW_3D_IN_ Uint64 value,
			_HW_3D_IN_ HANDLE h_event
		) = 0;

	virtual ID3D11Fence* get() = 0;

	virtual const ID3D11Fence* get() const = 0;

	virtual ~IFence() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11Fence>);

//
//
class _HW_3D_NO_VTABLE_ IInput_layout : public IDevice_child {
public:
	virtual ID3D11InputLayout* get() = 0;

	virtual const ID3D11InputLayout* get() const = 0;

	virtual ~IInput_layout() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11InputLayout>);

//
//
class _HW_3D_NO_VTABLE_ IMultithread : public IBase {
public:
	virtual void
		enter(
		) = 0;

	virtual Bool
		get_multithread_protected(
		) = 0;

	virtual void
		leave(
		) = 0;

	virtual Bool
		set_multithrewad_protected(
			_HW_3D_IN_ Bool protect
		) = 0;

	virtual ID3D11Multithread* get() = 0;

	virtual const ID3D11Multithread* get() const = 0;

	virtual ~IMultithread() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3D11Multithread>);

//
//
class _HW_3D_NO_VTABLE_ IQuery : public IAsynchronous {
public:
	virtual Query_desc
		get_desc(
		) = 0;

	virtual ID3D11Query* get() = 0;

	virtual const ID3D11Query* get() const = 0;

	virtual ~IQuery() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11Asynchronous, ID3D11Query>);

//
//
class _HW_3D_NO_VTABLE_ IPredicate : public IQuery {
public:
	virtual ID3D11Predicate* get() = 0;

	virtual const ID3D11Predicate* get() const = 0;

	virtual ~IPredicate() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11Query, ID3D11Predicate>);

//
//
class _HW_3D_NO_VTABLE_ IQuery1 : public IQuery {
public:
	virtual Query_desc1
		get_desc1(
		) = 0;

	virtual ID3D11Query1* get() = 0;

	virtual const ID3D11Query1* get() const = 0;

	virtual ~IQuery1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11Query, ID3D11Query1>);

//
//
class _HW_3D_NO_VTABLE_ IRasterizer_state : public IDevice_child {
public:
	virtual Rasterizer_desc
		get_desc(
		) = 0;

	virtual ID3D11RasterizerState* get() = 0;

	virtual const ID3D11RasterizerState* get() const = 0;

	virtual ~IRasterizer_state() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11RasterizerState>);

//
//
class _HW_3D_NO_VTABLE_ IRasterizer_state1 : public IRasterizer_state {
public:
	virtual Rasterizer_desc1
		get_desc1(
		) = 0;

	virtual ID3D11RasterizerState1* get() = 0;

	virtual const ID3D11RasterizerState1* get() const = 0;

	virtual ~IRasterizer_state1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11RasterizerState, ID3D11RasterizerState1>);

//
//
class _HW_3D_NO_VTABLE_ IRasterizer_state2 : public IRasterizer_state1 {
public:
	virtual Rasterizer_desc2
		get_desc2(
		) = 0;

	virtual ID3D11RasterizerState2* get() = 0;

	virtual const ID3D11RasterizerState2* get() const = 0;

	virtual ~IRasterizer_state2() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11RasterizerState1, ID3D11RasterizerState2>);

//
//
class _HW_3D_NO_VTABLE_ ISampler_state : public IDevice_child {
public:
	virtual Sampler_desc
		get_desc(
		) = 0;

	virtual ID3D11SamplerState* get() = 0;

	virtual const ID3D11SamplerState* get() const = 0;

	virtual ~ISampler_state() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11SamplerState>);

//
//
class _HW_3D_NO_VTABLE_ IDebug : public IBase {
public:
	virtual Debug_feature_mask
		get_feature_mask(
		) = 0;

	virtual Uint
		get_present_per_render_op_delay(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr< _HW_3D_DXGI_ ISwap_chain>>
		get_swap_chain(
		) = 0;

	virtual Result
		report_live_device_objects(
			_HW_3D_IN_ Rldo_flag flags
		) = 0;


	virtual Result
		set_feature_mask(
			_HW_3D_IN_ Debug_feature_mask mask
		) = 0;

	virtual Result
		set_persent_per_render_op_delay(
			_HW_3D_IN_ Uint millisecnds  //not safe
		) = 0;

	virtual Result
		set_swap_chain(
			_HW_3D_IN_ _HW_3D_DXGI_ ISwap_chain* swap_chain
		) = 0;

	virtual Result
		validate_context(
			_HW_3D_IN_ IDevice_context* context
		) = 0;

	virtual Result
		validate_context_for_dispatch(
			_HW_3D_IN_ IDevice_context* context
		) = 0;

	virtual ID3D11Debug* get() = 0;

	virtual const ID3D11Debug* get() const = 0;

	virtual ~IDebug() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3D11Debug>);

//
//
class _HW_3D_NO_VTABLE_ IInfo_queue : public IBase {
public:
	virtual Result
		add_application_message(
			_HW_3D_IN_ Message_severity severty,
			_HW_3D_IN_ const _HW_3D_STD_ string& description
		) = 0;

	virtual Result
		add_message(
			_HW_3D_IN_ Message_category category,
			_HW_3D_IN_ Message_severity severiry,
			_HW_3D_IN_ Message_id id,
			_HW_3D_IN_ const _HW_3D_STD_ string& description
		) = 0;

	virtual Result
		add_retrieval_filter_entries(
			_HW_3D_IN_ Info_queue_filter& filter
		) = 0;

	virtual Result
		add_storage_filter_entries(
			_HW_3D_IN_ Info_queue_filter& filter
		) = 0;

	virtual void
		clear_retrieval_filter(
		) = 0;

	virtual void
		clear_storage_filter(
		) = 0;

	virtual void
		clear_storage_messages(
		) = 0;

	virtual Bool
		get_break_on_category(
			_HW_3D_IN_ Message_category category
		) = 0;

	virtual Bool
		get_break_on_id(
			_HW_3D_IN_ Message_id id
		) = 0;

	virtual Bool
		get_break_on_severity(
			_HW_3D_IN_ Message_severity severity
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Message>
		get_message(
			_HW_3D_IN_ Uint64 index,
			_HW_3D_IN_ Size_t *length
		) = 0;

	virtual Uint64
		get_message_count_limit(
		) = 0;

	virtual Bool
		get_mute_debug_output(
		) = 0;

	virtual Uint64
		get_num_messages_allowed_by_storage_filter(
		) = 0;

	virtual Uint64
		get_num_messages_denied_by_storage_filter(
		) = 0;

	virtual Uint64
		get_num_messages_discarded_by_message_count_limit(
		) = 0;

	virtual Uint64
		get_num_stored_messages(
		) = 0;

	virtual Uint64
		get_num_stored_messages_allowed_by_retrieval_filter(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Info_queue_filter>
		get_retrieval_filter(
			_HW_3D_IN_OUT_ Size_t *length
		) = 0;

	virtual Uint
		get_retrieval_filter_stack_size(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Info_queue_filter>
		get_storage_filter(
			_HW_3D_IN_OUT_ Size_t* length
		) = 0;

	virtual Uint
		get_storage_filter_stack_size(
		) = 0;

	virtual void
		pop_retrieval_filter(
		) = 0;

	virtual void
		pop_storage_filter(
		) = 0;

	virtual Result
		push_copy_of_retrieval_filter(
		) = 0;

	virtual Result
		push_copy_of_storage_filter(
		) = 0;

	virtual Result
		push_empty_retrieval_filter(
		) = 0;

	virtual Result
		push_empty_storage_filter(
		) = 0;

	virtual Result
		push_retrieval_filter(
			_HW_3D_IN_ Info_queue_filter& filter
		) = 0;

	virtual Result
		push_storage_filter(
			_HW_3D_IN_ Info_queue_filter& filter
		) = 0;

	virtual Result
		set_break_on_category(
			_HW_3D_IN_ Message_category category,
			_HW_3D_IN_ Bool enable
		) = 0;

	virtual Result
		set_break_on_id(
			_HW_3D_IN_ Message_id id,
			_HW_3D_IN_ Bool enable
		) = 0;

	virtual Result
		set_bread_on_severity(
			_HW_3D_IN_ Message_severity severity,
			_HW_3D_IN_ Bool enable
		) = 0;

	virtual Result
		set_message_count_limit(
			_HW_3D_IN_ Uint64 message_count_limit
		) = 0;

	virtual void
		set_mute_debug_output(
			_HW_3D_IN_ Bool mute
		) = 0;

	virtual ID3D11InfoQueue* get() = 0;

	virtual const ID3D11InfoQueue* get() const = 0;

	virtual ~IInfo_queue() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3D11InfoQueue>);

//
//
class _HW_3D_NO_VTABLE_ IRef_default_tracking_options : public IBase {
public:
	virtual Result
		set_tracking_options(
			_HW_3D_IN_ Shader_tracking_resource_type type,
			_HW_3D_IN_ Shader_tracking_option options
		) = 0;

	virtual ID3D11RefDefaultTrackingOptions* get() = 0;

	virtual const ID3D11RefDefaultTrackingOptions* get() const = 0;

	virtual ~IRef_default_tracking_options() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3D11RefDefaultTrackingOptions>);

//
//
class _HW_3D_NO_VTABLE_ IRef_tracking_options : public IBase {
public:
	virtual Result
		set_tracking_options(
			_HW_3D_IN_ Shader_tracking_option options
		) = 0;

	virtual ID3D11RefTrackingOptions* get() = 0;

	virtual const ID3D11RefTrackingOptions* get() const = 0;

	virtual ~IRef_tracking_options() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3D11RefTrackingOptions>);

//
//
class _HW_3D_NO_VTABLE_ ITracing_device : public IBase {
public:
	virtual Result
		set_shader_tracking_options(
			_HW_3D_IN_ IBase* shader,
			_HW_3D_IN_ Shader_tracking_option options
		) = 0;

	virtual Result
		set_shader_tracking_options_by_type(
			_HW_3D_IN_ Shader_tracking_resource_type type,
			_HW_3D_IN_ Shader_tracking_option options
		) = 0;

	virtual ID3D11TracingDevice* get() = 0;

	virtual const ID3D11TracingDevice* get() const = 0;

	virtual ~ITracing_device() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3D11TracingDevice>);

//
//
class _HW_3D_NO_VTABLE_ IResource : public IDevice_child {
public:
	virtual  _HW_3D_DXGI_ Resource_priority
		get_eviction_priority(
		) = 0;

	virtual Resource_dimension
		get_type(
		) = 0;

	virtual void
		set_eviction_priority(
			_HW_3D_IN_ _HW_3D_DXGI_ Resource_priority priority
		) = 0;

	virtual ID3D11Resource* get() = 0;

	virtual const ID3D11Resource* get() const = 0;

	virtual ~IResource() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11Resource>);

//
//
class _HW_3D_NO_VTABLE_ IBuffer : public IResource {
public:
	virtual Buffer_desc
		get_desc(
		) = 0;

	virtual ID3D11Buffer* get() = 0;

	virtual const ID3D11Buffer* get() const = 0;

	virtual ~IBuffer() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11Resource, ID3D11Buffer>);

//
//
class _HW_3D_NO_VTABLE_ IView : public IDevice_child {
public:
	virtual _HW_3D_STD_ unique_ptr<IResource>
		get_resource(
		) = 0;

	virtual ID3D11View* get() = 0;

	virtual const ID3D11View* get() const = 0;

	virtual ~IView() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11View>);

//
//
class _HW_3D_NO_VTABLE_ IDepth_stencil_view : public IView {
public:
	virtual Depth_stencil_view_desc
		get_desc(
		) = 0;

	virtual ID3D11DepthStencilView* get() = 0;

	virtual const ID3D11DepthStencilView* get() const = 0;

	virtual ~IDepth_stencil_view() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11View, ID3D11DepthStencilView>);

//
//
class _HW_3D_NO_VTABLE_ IRender_target_view : public IView {
public:
	virtual Render_target_view_desc
		get_desc(
		) = 0;

	virtual ID3D11RenderTargetView* get() = 0;

	virtual const ID3D11RenderTargetView* get() const = 0;

	virtual ~IRender_target_view() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11View, ID3D11RenderTargetView>);

//
//
class _HW_3D_NO_VTABLE_ IRender_target_view1 : public IRender_target_view {
public:
	virtual Render_target_view_desc1
		get_desc1(
		) = 0;

	virtual ID3D11RenderTargetView1* get() = 0;

	virtual const ID3D11RenderTargetView1* get() const = 0;

	virtual ~IRender_target_view1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11RenderTargetView, ID3D11RenderTargetView1>);

//
//
class _HW_3D_NO_VTABLE_ IShader_resource_view : public IView {
public:
	virtual Shader_resource_view_desc
		get_desc(
		) = 0;

	virtual ID3D11ShaderResourceView* get() = 0;

	virtual const ID3D11ShaderResourceView* get() const = 0;

	virtual ~IShader_resource_view() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11View, ID3D11ShaderResourceView>);

//
//
class _HW_3D_NO_VTABLE_ IShader_resource_view1 : public IShader_resource_view {
public:
	virtual Shader_resource_view_desc1
		get_desc1(
		) = 0;

	virtual ID3D11ShaderResourceView1* get() = 0;

	virtual const ID3D11ShaderResourceView1* get() const = 0;

	virtual ~IShader_resource_view1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11ShaderResourceView, ID3D11ShaderResourceView1>);

//
//
class _HW_3D_NO_VTABLE_ ITexture1d : public IResource {
public:
	virtual Texture1d_desc
		get_desc(
		) = 0;

	virtual ID3D11Texture1D* get() = 0;

	virtual const ID3D11Texture1D* get() const = 0;

	virtual ~ITexture1d() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11Resource, ID3D11Texture1D>);

//
//
class _HW_3D_NO_VTABLE_ ITexture2d : public IResource {
public:
	virtual Texture2d_desc
		get_desc(
		) = 0;

	virtual ID3D11Texture2D* get() = 0;

	virtual const ID3D11Texture2D* get() const = 0;

	virtual ~ITexture2d() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11Resource, ID3D11Texture2D>);

//
//
class _HW_3D_NO_VTABLE_ ITexture2d1 : public ITexture2d {
public:
	virtual Texture2d_desc1
		get_desc1(
		) = 0;

	virtual ID3D11Texture2D1* get() = 0;

	virtual const ID3D11Texture2D1* get() const = 0;

	virtual ~ITexture2d1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11Texture2D, ID3D11Texture2D1>);

//
//
class _HW_3D_NO_VTABLE_ ITexture3d : public IResource {
public:
	virtual Texture3d_desc
		get_desc(
		) = 0;

	virtual ID3D11Texture3D* get() = 0;

	virtual const ID3D11Texture3D* get() const = 0;

	virtual ~ITexture3d() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11Resource, ID3D11Texture3D>);

//
//
class _HW_3D_NO_VTABLE_ ITexture3d1 : public ITexture3d {
public:
	virtual Texture3d_desc1
		get_desc1(
		) = 0;

	virtual ID3D11Texture3D1* get() = 0;

	virtual const ID3D11Texture3D1* get() const = 0;

	virtual ~ITexture3d1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11Texture3D, ID3D11Texture3D1>);

//
//
class _HW_3D_NO_VTABLE_ IUnordered_access_view : public IView {
public:
	virtual Unordered_access_view_desc
		get_desc(
		) = 0;

	virtual ID3D11UnorderedAccessView* get() = 0;

	virtual const ID3D11UnorderedAccessView* get() const = 0;

	virtual ~IUnordered_access_view() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11View, ID3D11UnorderedAccessView>);

//
//
class _HW_3D_NO_VTABLE_ IUnordered_access_view1 : public IUnordered_access_view {
public:
	virtual Unordered_access_view_desc1
		get_desc1(
		) = 0;

	virtual ID3D11UnorderedAccessView1* get() = 0;

	virtual const ID3D11UnorderedAccessView1* get() const = 0;

	virtual ~IUnordered_access_view1() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11UnorderedAccessView, ID3D11UnorderedAccessView1>);

//
//
class _HW_3D_NO_VTABLE_ IClass_instance : public IDevice_child {
public:
	virtual _HW_3D_STD_ unique_ptr<IClass_linkage>
		get_class_linkage(
		) = 0;

	virtual Class_instance_desc
		get_desc(
		) = 0;

	virtual _HW_3D_STD_ string
		get_instance_name(
		) = 0;

	virtual _HW_3D_STD_ string
		get_type_name(
		) = 0;

	virtual ID3D11ClassInstance* get() = 0;

	virtual const ID3D11ClassInstance* get() const = 0;

	virtual ~IClass_instance() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11ClassInstance>);

//
//
class _HW_3D_NO_VTABLE_ IClass_linkage : public IDevice_child {
public:
	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IClass_instance>>
		create_class_instance(
			_HW_3D_IN_ const _HW_3D_STD_ string& type_name,
			_HW_3D_IN_ Uint constant_buffer_offset,
			_HW_3D_IN_ Uint constant_vector_offset,
			_HW_3D_IN_ Uint texture_offset,
			_HW_3D_IN_ Uint sampler_offset
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IClass_instance>>
		get_class_instance(
			_HW_3D_IN_ const _HW_3D_STD_ string& name,
			_HW_3D_IN_ Uint index
		) = 0;

	virtual ID3D11ClassLinkage* get() = 0;

	virtual const ID3D11ClassLinkage* get() const = 0;

	virtual ~IClass_linkage() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11ClassLinkage>);

//
//
class _HW_3D_NO_VTABLE_ ICompute_shader : public IDevice_child {
public:
	virtual ID3D11ComputeShader* get() = 0;

	virtual const ID3D11ComputeShader* get() const = 0;

	virtual ~ICompute_shader() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11ComputeShader>);

//
//
class _HW_3D_NO_VTABLE_ IDomain_shader : public IDevice_child {
public:
	virtual ID3D11DomainShader* get() = 0;

	virtual const ID3D11DomainShader* get() const = 0;

	virtual ~IDomain_shader() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11DomainShader>);

//
//
class _HW_3D_NO_VTABLE_ IFunction_linking_graph : public IBase {
public:
	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ILinking_node>>
		call_function(
			_HW_3D_IN_ const _HW_3D_STD_ string& moduel_instance_namespace,
			_HW_3D_IN_ IModule* module_with_function_protoype,
			_HW_3D_IN_ const _HW_3D_STD_ string& function_name
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IModule_instance>, _HW_3D_STD_ unique_ptr<IBlob>>
		create_module_instance(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBlob>>
		generate_hlsl(
			_HW_3D_IN_ /*unused*/ Uint flags
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBlob>>
		get_last_error(
		) = 0;

	virtual Result
		pass_value(
			_HW_3D_IN_ ILinking_node* src,
			_HW_3D_IN_ Int src_parameter_index,
			_HW_3D_IN_ ILinking_node* dst,
			_HW_3D_IN_ Int dst_parameter_index
		) = 0;

	virtual Result
		pass_value_with_swizzle(
			_HW_3D_IN_ ILinking_node* src,
			_HW_3D_IN_ Int src_parameter_index,
			_HW_3D_IN_ const _HW_3D_STD_ string& src_swizzle,
			_HW_3D_IN_ ILinking_node* dst,
			_HW_3D_IN_ Int dst_parameter_index,
			_HW_3D_IN_ const _HW_3D_STD_ string& dst_swizzle
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ILinking_node>>
		set_input_signature(
			_HW_3D_IN_ const _HW_3D_STD_ vector<Parameter_desc>& parameters
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ILinking_node>>
		set_output_signature(
			_HW_3D_IN_ const _HW_3D_STD_ vector<Parameter_desc>& parameters
		) = 0;

	virtual ID3D11FunctionLinkingGraph* get() = 0;

	virtual const ID3D11FunctionLinkingGraph* get() const = 0;

	virtual ~IFunction_linking_graph() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3D11FunctionLinkingGraph>);

//
//msdn different from implementation, don't use this, only interface, no impl
class _HW_3D_NO_VTABLE_ IFunction_reflection : public IBase {
public:
	virtual _HW_3D_STD_ unique_ptr<IShader_reflection_constant_buffer>
		get_constant_buffer_by_index(
			_HW_3D_IN_ Uint buffer_index
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IShader_reflection_constant_buffer>
		get_constant_buffer_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Function_desc>
		get_desc(
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IFunction_parameter_reflection>
		get_function_parameter(
			_HW_3D_IN_ Int parameter_index
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Shader_input_bind_desc>
		get_resource_binding_desc(
			_HW_3D_IN_ Uint resource_index
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Shader_input_bind_desc>
		get_resource_binding_desc_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IShader_reflection_variable>
		get_variable_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name
		) = 0;

	virtual ~IFunction_reflection() {}
};

//
//msdn different from implementation, don't use this, only interface, no impl
class _HW_3D_NO_VTABLE_ IFunction_parameter_reflection : public IBase {
public:
	virtual _HW_3D_STD_ tuple<Result, Parameter_desc>
		get_desc(
		) = 0;

	virtual ~IFunction_parameter_reflection() {}
};

//
//
class _HW_3D_NO_VTABLE_ IGeometry_shader : public IDevice_child {
public:
	virtual ID3D11GeometryShader* get() = 0;

	virtual const ID3D11GeometryShader* get() const = 0;

	virtual ~IGeometry_shader() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11GeometryShader>);

//
//
class _HW_3D_NO_VTABLE_ IHull_shader : public IDevice_child {
public:
	virtual ID3D11HullShader* get() = 0;

	virtual const ID3D11HullShader* get() const = 0;

	virtual ~IHull_shader() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11HullShader>);

//
//
class _HW_3D_NO_VTABLE_ ILibrary_reflection : public IBase {
public:
	virtual _HW_3D_STD_ tuple<Result, Library_desc>
		get_desc(
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IFunction_reflection>
		get_function_by_index(
			_HW_3D_IN_ Int function_index
		) = 0;

	virtual ID3D11LibraryReflection* get() = 0;

	virtual const ID3D11LibraryReflection* get() const = 0;

	virtual ~ILibrary_reflection() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3D11LibraryReflection>);

//
//
class _HW_3D_NO_VTABLE_ ILinker : public IBase {
public:
	virtual Result
		add_clip_plane_from_cbuffer(
			_HW_3D_IN_ Uint slot,
			_HW_3D_IN_ Uint entry
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBlob>, _HW_3D_STD_ unique_ptr<IBlob>>
		link(
			_HW_3D_IN_ IModule_instance* entry,
			_HW_3D_IN_ const _HW_3D_STD_ string& entry_name,
			_HW_3D_IN_ const _HW_3D_STD_ string& target_name,
			_HW_3D_IN_ /*unused*/ Uint flags
		) = 0;

	virtual Result
		use_library(
			_HW_3D_IN_ IModule_instance* lib
		) = 0;

	virtual ID3D11Linker* get() = 0;

	virtual const ID3D11Linker* get() const = 0;

	virtual ~ILinker() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3D11Linker>);

//
//
class _HW_3D_NO_VTABLE_ ILinking_node : public IBase {
public:
	virtual ID3D11LinkingNode* get() = 0;

	virtual const ID3D11LinkingNode* get() const = 0;

	virtual ~ILinking_node() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3D11LinkingNode>);

//
//
class _HW_3D_NO_VTABLE_ IModule : public IBase {
public:
	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IModule_instance>>
		create_instance(
			_HW_3D_IN_ const _HW_3D_STD_ string& name
		) = 0;

	virtual ID3D11Module* get() = 0;

	virtual const ID3D11Module* get() const = 0;

	virtual ~IModule() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3D11Module>);

//
//
class _HW_3D_NO_VTABLE_ IModule_instance : public IBase {
public:
	virtual Result
		bind_constant_buffer(
			_HW_3D_IN_ Uint src_slot,
			_HW_3D_IN_ Uint dst_slot,
			_HW_3D_IN_ Uint dst_offset
		) = 0;

	virtual Result
		bind_constant_buffer_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name,
			_HW_3D_IN_ Uint dst_slot,
			_HW_3D_IN_ Uint dst_offset
		) = 0;

	virtual Result
		bind_resource(
			_HW_3D_IN_ Uint src_slot,
			_HW_3D_IN_ Uint dst_slot,
			_HW_3D_IN_ Uint count
		) = 0;

	virtual Result
		bind_resource_as_unordered_access_view(
			_HW_3D_IN_ Uint src_srv_slot,
			_HW_3D_IN_ Uint dst_uav_slot,
			_HW_3D_IN_ Uint count
		) = 0;

	virtual Result
		bind_resource_as_unordered_access_view_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name,
			_HW_3D_IN_ Uint dst_uav_slot,
			_HW_3D_IN_ Uint count
		) = 0;

	virtual Result
		bind_resource_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name,
			_HW_3D_IN_ Uint dst_slot,
			_HW_3D_IN_ Uint count
		) = 0;

	virtual Result
		bind_sampler(
			_HW_3D_IN_ Uint src_slot,
			_HW_3D_IN_ Uint dst_slot,
			_HW_3D_IN_ Uint count
		) = 0;

	virtual Result
		bind_sampler_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name,
			_HW_3D_IN_ Uint dst_slot,
			_HW_3D_IN_ Uint count
		) = 0;

	virtual Result
		bind_unordered_access_view(
			_HW_3D_IN_ Uint src_slot,
			_HW_3D_IN_ Uint dst_slot,
			_HW_3D_IN_ Uint count
		) = 0;

	virtual Result
		bind_unordered_access_view_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name,
			_HW_3D_IN_ Uint dst_slot,
			_HW_3D_IN_ Uint count
		) = 0;

	virtual ID3D11ModuleInstance* get() = 0;

	virtual const ID3D11ModuleInstance* get() const = 0;

	virtual ~IModule_instance() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3D11ModuleInstance>);

//
//
class _HW_3D_NO_VTABLE_ IPixel_shader : public IDevice_child {
public:
	virtual ID3D11PixelShader* get() = 0;

	virtual const ID3D11PixelShader* get() const = 0;

	virtual ~IPixel_shader() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11PixelShader>);

//
//
class _HW_3D_NO_VTABLE_ IShader_reflection : public IBase {
public:
	virtual Uint
		get_bitwise_instruction_count(
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IShader_reflection_constant_buffer>
		get_constant_buffer_by_index(
			_HW_3D_IN_ Uint index
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IShader_reflection_constant_buffer>
		get_constant_buffer_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name
		) = 0;

	virtual Uint
		get_conversion_instruction_count(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Shader_desc>
		get_desc(
		) = 0;

	virtual Primitive
		get_gs_input_primitive(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Signature_parameter_desc>
		get_input_parameter_desc(
			_HW_3D_IN_ Uint parameter_index
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Feature_level>
		get_min_feature_level(
		) = 0;

	virtual Uint
		get_movc_instruction_count(
		) = 0;

	virtual Uint
		get_mov_instruction_count(
		) = 0;

	virtual Uint
		get_num_interface_slots(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Signature_parameter_desc>
		get_output_paramter_desc(
			_HW_3D_IN_ Uint parameter_index
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Signature_parameter_desc>
		get_patch_constant_parameter_desc(
			_HW_3D_IN_ Uint parameter_index
		) = 0;

	virtual Shader_require
		get_requires_flags(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Shader_input_bind_desc>
		get_resource_binding_desc(
			_HW_3D_IN_ Uint resource_index
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Shader_input_bind_desc>
		get_resource_binding_desc_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name
		) = 0;

	virtual _HW_3D_STD_ tuple<Uint, _HW_3D_STD_ array<Uint, 3>>
		get_thread_group_size(
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IShader_reflection_variable>
		get_variable_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name
		) = 0;

	virtual Bool
		is_sampler_frequency_shader(
		) = 0;

	virtual ID3D11ShaderReflection* get() = 0;

	virtual const ID3D11ShaderReflection* get() const = 0;

	virtual ~IShader_reflection() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3D11ShaderReflection>);

//
//msdn different from implementation, don't use this, only interface, no impl
class _HW_3D_NO_VTABLE_ IShader_reflection_constant_buffer : public IBase {
public:
	virtual _HW_3D_STD_ tuple<Result, Shader_buffer_desc>
		get_desc(
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IShader_reflection_variable>
		get_variable_by_index(
			_HW_3D_IN_ Uint index
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IShader_reflection_variable>
		get_variable_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name
		) = 0;

	virtual ~IShader_reflection_constant_buffer() {}
};

//
//msdn different from implementation, don't use this, only interface, no impl
class _HW_3D_NO_VTABLE_ IShader_reflection_type : public IBase {
public:
	virtual _HW_3D_STD_ unique_ptr<IShader_reflection_type>
		get_base_class(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Shader_type_desc>
		get_desc(
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IShader_reflection_type>
		get_interface_by_index(
			_HW_3D_IN_ Uint index
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IShader_reflection_type>
		get_member_type_by_index(
			_HW_3D_IN_ Uint index
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IShader_reflection_type>
		get_member_type_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name
		) = 0;

	virtual _HW_3D_STD_ string
		get_member_type_name(
			_HW_3D_IN_ Uint index
		) = 0;

	virtual Uint
		get_num_interfaces(
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IShader_reflection_type>
		get_sub_type(
		) = 0;

	virtual Result
		implements_interface(
			_HW_3D_IN_ IShader_reflection_type* base
		) = 0;

	virtual Result
		is_equal(
			_HW_3D_IN_ IShader_reflection_type* type
		) = 0;

	virtual Result
		is_of_type(
			_HW_3D_IN_ IShader_reflection_type* type
		) = 0;

	virtual ~IShader_reflection_type() {}
};

//
//msdn different from implementation, don't use this, only interface here, no impl
class _HW_3D_NO_VTABLE_ IShader_reflection_variable : public IBase {
public:
	virtual _HW_3D_STD_ unique_ptr<IShader_reflection_constant_buffer>
		get_buffer(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Shader_variable_desc>
		get_desc(
		) = 0;

	virtual Uint
		get_interface_slot(
			_HW_3D_IN_ Uint array_index
		) = 0;

	virtual _HW_3D_STD_ unique_ptr<IShader_reflection_type>
		get_type(
		) = 0;

	virtual ~IShader_reflection_variable() {}
};

//
//
class _HW_3D_NO_VTABLE_ IShader_trace : public IBase {
public:
	virtual _HW_3D_STD_ tuple<Result, Trace_value>
		get_initial_register_contents(
			_HW_3D_IN_ Trace_register& reg
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Trace_register, Trace_value>
		get_read_register(
			_HW_3D_IN_ Uint step_index,
			_HW_3D_IN_ Uint read_register_index
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Trace_step>
		get_step(
			_HW_3D_IN_ Uint step_index
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Trace_stats>
		get_trace_stats(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Trace_register, Trace_value>
		get_written_register(
			_HW_3D_IN_ Uint step_index,
			_HW_3D_IN_ Uint written_register_index
		) = 0;

	virtual Result
		ps_select_stamp(
			_HW_3D_IN_ Uint sample_index
		) = 0;

	virtual void
		reset_trace(
		) = 0;

	virtual _HW_3D_STD_ tuple<Result, Uint64>
		trace_ready(
		) = 0;

	virtual ID3D11ShaderTrace* get() = 0;

	virtual const ID3D11ShaderTrace* get() const = 0;

	virtual ~IShader_trace() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3D11ShaderTrace>);

//
//
class _HW_3D_NO_VTABLE_ IShader_trace_factory : public IBase {
public:
	virtual _HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IShader_trace>>
		create_shader_trace(
			_HW_3D_IN_ IBase* shader,
			_HW_3D_IN_ Shader_trace_desc& desc
		) = 0;

	virtual ID3D11ShaderTraceFactory* get() = 0;

	virtual const ID3D11ShaderTraceFactory* get() const = 0;

	virtual ~IShader_trace_factory() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3D11ShaderTraceFactory>);

//
//
class _HW_3D_NO_VTABLE_ IVertex_shader : public IDevice_child {
public:
	virtual ID3D11VertexShader* get() = 0;

	virtual const ID3D11VertexShader* get() const = 0;

	virtual ~IVertex_shader() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, ID3D11VertexShader>);

//
//
class _HW_3D_NO_VTABLE_ IBlob : public IBase {
public:
	virtual LPVOID
		get_buffer_pointer(
		) = 0;

	virtual Size_t
		get_buffer_size(
		) = 0;

	virtual ID3DBlob* get() = 0;

	virtual const ID3DBlob* get() const = 0;

	virtual ~IBlob() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3DBlob>);

//
//msdn different from implementation, don't use this, only interface here, no impl
class _HW_3D_NO_VTABLE_ IInclude : public IBase {
public:
	virtual Result
		close(
			_HW_3D_IN_ LPCVOID data
		) = 0;

	virtual Result
		open(
			_HW_3D_IN_ Include_type type,
			_HW_3D_IN_ const _HW_3D_STD_ string& file_name,
			_HW_3D_IN_ LPCVOID parent_data,
			_HW_3D_OUT_ LPCVOID* data,
			_HW_3D_OUT_ Uint* size
		) = 0;

	virtual ~IInclude() {}
};

//
//
class _HW_3D_NO_VTABLE_ IUser_defined_annotation : public IBase {
public:
	virtual Int
		begin_event(
			_HW_3D_IN_ const _HW_3D_STD_ wstring& name
		) = 0;

	virtual Int
		end_event(
		) = 0;

	virtual Bool
		get_status(
		) = 0;

	virtual void
		set_marker(
			_HW_3D_IN_ const _HW_3D_STD_ wstring& name
		) = 0;

	virtual ID3DUserDefinedAnnotation* get() = 0;

	virtual const ID3DUserDefinedAnnotation* get() const = 0;

	virtual ~IUser_defined_annotation() {}
};
static_assert(_HW_3D_STD_ is_base_of_v<IUnknown, ID3DUserDefinedAnnotation>);

_HW_3D_CLOSE_D3D_NAMESPACE_

///
///helper class/ function
//value_ptr()
template <typename _Ty, typename = _HW_3D_STD_ void_t<>>
struct _Has_value_ptr_method : public _HW_3D_STD_ false_type {};

template <typename _Ty>
struct _Has_value_ptr_method<_Ty,
	_HW_3D_STD_ void_t<decltype(_HW_3D_STD_ declval<_HW_3D_STD_ decay_t<_Ty>>().value_ptr())>>
	: public _HW_3D_STD_ true_type {};
	
template <typename _Ty>
constexpr bool _Has_value_ptr_method_v = _Has_value_ptr_method<_Ty>::value;

//
//
template <typename Interface>
auto value_ptr(Interface* p_interface) {
	if constexpr (_HW_3D_STD_ is_base_of_v<IBase, Interface>)
		return p_interface ? p_interface->get() : nullptr;
	else if constexpr (_Has_value_ptr_method_v<Interface>)
		return p_interface ? p_interface->value_ptr() : nullptr;
	else
		return p_interface;
}

template <typename Interface>
auto value_ptr(const Interface* p_interface) {
	if constexpr (_HW_3D_STD_ is_base_of_v<IBase, Interface>)
		return p_interface ? p_interface->get() : nullptr;
	else if constexpr (_Has_value_ptr_method_v<Interface>)
		return p_interface ? p_interface->value_ptr() : nullptr;
	else
		return p_interface;
}

template <typename Interface, typename = _HW_3D_STD_ enable_if_t<_HW_3D_STD_ is_base_of_v<IBase, Interface>>>
auto values_ptr(const _HW_3D_STD_ vector<Interface*>& interface_) {
	_HW_3D_STD_ vector<_HW_3D_STD_ decay_t<decltype((value_ptr(interface_[0])))>> res;

	res.reserve(interface_.size());
	_HW_3D_STD_ for_each(interface_.begin(), interface_.end(), [&res](auto ptr) {res.push_back(value_ptr(ptr)); });

	return res;
}

template <typename Ty>
auto value_ptr(Ty& value) {
	if constexpr (_HW_3D_STD_ is_base_of_v<IBase, Ty>)
		return value.get();
	else if constexpr (_Has_value_ptr_method_v<Ty>)
		return value.value_ptr();
	else
		return &value;
}

template <typename Ty>
auto value_ptr(const Ty& value) {
	if constexpr (_HW_3D_STD_ is_base_of_v<IBase, Ty>)
		return value.get();
	else if constexpr (_Has_value_ptr_method_v<Ty>)
		return value.value_ptr();
	else
		return &value;
}

///
/// wrapper hierarchy implementation
struct D3d_wrapper_alloc_base {
#ifdef _HW_3D_MULTITHREAD_
	using Memory_pool_type = _HW_3D_STD_ pmr::synchronized_pool_resource;
#else
	using Memory_pool_type = _HW_3D_STD_ pmr::unsynchronized_pool_resource;
#endif

	static Memory_pool_type memory_pool;

	static void* operator new(_HW_3D_STD_ size_t size) {
		return memory_pool.allocate(size);
	}

	static void operator delete(void* ptr, _HW_3D_STD_ size_t size) {
		return memory_pool.deallocate(ptr, size);
	}
};

inline D3d_wrapper_alloc_base::Memory_pool_type D3d_wrapper_alloc_base::memory_pool{};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TBase : public Interface, public D3d_wrapper_alloc_base {
	static_assert(_HW_3D_STD_ is_base_of_v<IBase, Interface> && _HW_3D_STD_ is_base_of_v<IUnknown, Ty>);
public:
	explicit _TBase(Ty* handle)
		: _handle{ handle } {
	}

	_TBase(const _TBase&) = delete;
	_TBase& operator=(const _TBase&) = delete;
	_TBase(_TBase&&) = delete;
	_TBase& operator=(_TBase&&) = delete;

	ULONG add_ref() override {
		return _handle->AddRef();
	}

	_HW_3D_STD_ tuple<HRESULT, void*>
		query_interface(
			_HW_3D_IN_ REFIID riid
		) override {
		_HW_3D_STD_ tuple<HRESULT, void*> res; //make sure rvo

		auto&[r, r1] = res;
		r = _handle->QueryInterface(riid, &r1);

		return res;
	}

	ULONG release() override {
		return _handle->Release();
	}

	virtual ~_TBase() {
		if constexpr (own) {
			if (_handle) _handle->Release();
		}
	}
protected:
	Ty * _handle{ nullptr };
};

_HW_3D_OPEN_DXGI_NAMESPACE_

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TObject : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IObject, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIObject, Ty>);
public:
	explicit _TObject(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {
	}

	_HW_3D_STD_ tuple<Result, void*>
		get_parent(
			_HW_3D_IN_ REFIID riid
		) override {
		_HW_3D_STD_ tuple<Result, void*> res;

		auto&[r, r1] = res;
		r = static_cast<Result>(this->_handle->GetParent(riid, &r1));

		return res;
	}

	Result
		get_private_data(
			_HW_3D_IN_ REFGUID name,
			_HW_3D_IN_OUT_ UINT* size,
			_HW_3D_OUT_ void* data
		) override {
		return static_cast<Result>(this->_handle->GetPrivateData(name, size, data));
	}

	Result
		set_private_data(
			_HW_3D_IN_ REFGUID name,
			_HW_3D_IN_ UINT size,
			_HW_3D_IN_ const void* data
		) override {
		return static_cast<Result>(this->_handle->SetPrivateData(name, size, data));
	}

	Result
		get_private_data_interface(
			_HW_3D_IN_ REFGUID name,
			_HW_3D_IN_ const IBase* unknown
		) override {
		return static_cast<Result>(this->_handle->SetPrivateDataInterface(name, value_ptr(unknown)));
	}

	virtual ~_TObject() {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice_subobject : public _TObject<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice_subobject, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIDeviceSubObject, Ty>);
public:
	explicit _TDevice_subobject(Ty* handle)
		: _TObject<Interface, Ty, own>(handle) {
	}

	_HW_3D_STD_ tuple<Result, void*>
		get_device(
			_HW_3D_IN_ REFIID riid
		) override {
		_HW_3D_STD_ tuple<Result, void*> res;

		auto&[r, r1] = res;
		r = static_cast<Result>(this->_handle->GetDevice(riid, &r1));

		return res;
	}

	virtual ~_TDevice_subobject() {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TResource : public _TDevice_subobject<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IResource, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIResource, Ty>);
public:
	explicit _TResource(Ty* handle)
		: _TDevice_subobject<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, Resource_priority>
		get_eviction_priority(
		) override {
		_HW_3D_STD_ tuple<Result, Resource_priority> res;

		auto&[r, priority] = res;
		r = static_cast<Result>(this->_handle->GetEvictionPriority((UINT*)(&priority)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, HANDLE>
		get_shared_handle(
		) override {
		_HW_3D_STD_ tuple<Result, HANDLE> res;

		auto&[r, h] = res;
		r = static_cast<Result>(this->_handle->GetSharedHandle(&h));

		return res;
	}

	_HW_3D_STD_ tuple<Result, Usage>
		get_usage(
		) override {
		_HW_3D_STD_ tuple<Result, Usage> res;

		auto&[r, usage] = res;
		r = static_cast<Result>(this->_handle->GetUsage((DXGI_USAGE*)(&usage)));

		return res;
	}

	virtual Result
		set_eviction_priority(
			_HW_3D_IN_ Resource_priority eviction_priority
		) override {
		return static_cast<Result>(this->_handle->SetEvictionPriority(UINT(eviction_priority)));
	}

	virtual ~_TResource() {}
};

//
//
template <bool own>
class _Resource : public _TResource<IResource, IDXGIResource, own> {
public:
	explicit _Resource(IDXGIResource* handle)
		: _TResource<IResource, IDXGIResource, own>(handle) {

	}

	IDXGIResource* get() override {
		return this->_handle;
	}

	const IDXGIResource* get() const override {
		return this->_handle;
	}

	~_Resource() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TOutput : public _TObject<Interface, Ty, own> {
public:
	explicit _TOutput(Ty* handle)
		: _TObject<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, Mode_desc>
		find_closest_matching_mode(
			_HW_3D_IN_ const Mode_desc& mode_to_match,
			_HW_3D_IN_ IBase* device
		) override {
		_HW_3D_STD_ tuple<Result, Mode_desc> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->FindClosestMatchingMode(value_ptr(mode_to_match), value_ptr(desc), value_ptr(device)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, Output_desc>
		get_desc(
		) override {
		_HW_3D_STD_ tuple<Result, Output_desc> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->GetDesc(value_ptr(desc)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<Mode_desc>>
		get_display_mode_list(
			_HW_3D_IN_ Format enum_format,
			_HW_3D_IN_ Display_mode flags
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<Mode_desc>> res;

		auto&[r, descs] = res;

		UINT num{ 0 };
		this->_handle->GetDisplayModeList(DXGI_FORMAT(enum_format), Display_mode::mask_type(flags), &num, nullptr);

		descs.resize(num);
		r = static_cast<Result>(this->_handle->GetDisplayModeList(DXGI_FORMAT(enum_format), Display_mode::mask_type(flags), &num, reinterpret_cast<DXGI_MODE_DESC*>(descs.data())));
		return res;
	}

	Result
		get_display_surface_data(
			_HW_3D_IN_ ISurface* dest
		) override {
		return static_cast<Result>(this->_handle->GetDisplaySurfaceData(value_ptr(dest)));
	}

	_HW_3D_STD_ tuple<Result, Frame_statistics>
		get_frame_statistics(
		) override {
		_HW_3D_STD_ tuple<Result, Frame_statistics> res;

		auto&[r, statistics] = res;
		r = static_cast<Result>(this->_handle->GetFrameStatistics(value_ptr(statistics)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, Gamma_control>
		get_camma_control(
		) override {
		_HW_3D_STD_ tuple<Result, Gamma_control> res;

		auto&[r, gamma] = res;
		r = static_cast<Result>(this->_handle->GetGammaControl(value_ptr(gamma)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, Gamma_control_capabilities>
		get_gamma_control_capabilities(
		) override {
		_HW_3D_STD_ tuple<Result, Gamma_control_capabilities> res;

		auto&[r, gamma] = res;
		r = static_cast<Result>(this->_handle->GetGammaControlCapabilities(value_ptr(gamma)));

		return res;
	}

	void
		release_ownership(
		) override {
		this->_handle->ReleaseOwnership();
	}

	Result
		set_display_surface(
			_HW_3D_IN_ ISurface* scanout_surface
		) override {
		return static_cast<Result>(this->_handle->SetDisplaySurface(value_ptr(scanout_surface)));
	}

	Result
		set_gamma_control(
			_HW_3D_IN_ const Gamma_control& arr
		) override {
		return static_cast<Result>(this->_handle->SetGammaControl(value_ptr(arr)));
	}

	Result
		take_ownership(
			_HW_3D_IN_ IBase* device,
			BOOL exclusive
		) override {
		return static_cast<Result>(this->_handle->TakeOwnership(value_ptr(device), exclusive));
	}

	Result
		wait_for_v_blank(
		) override {
		return static_cast<Result>(this->_handle->WaitForVBlank());
	}

	virtual ~_TOutput() {}
};

//
//
template <bool own>
class _Output : public _TOutput<IOutput, IDXGIOutput, own> {
public:
	explicit _Output(IDXGIOutput* handle)
		: _TOutput<IOutput, IDXGIOutput, own>(handle) {
	}

	IDXGIOutput* get() override {
		return this->_handle;
	}

	const IDXGIOutput* get() const override {
		return this->_handle;
	}

	~_Output() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TOutput_duplication : public _TObject<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IOutput_duplication, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIOutputDuplication, Ty>);
public:
	explicit _TOutput_duplication(Ty* handle)
		: _TObject<Interface, Ty, own>(handle) {
	}

	_HW_3D_STD_ tuple<Result, Outdupl_frame_info, _HW_3D_STD_ unique_ptr<IResource>>
		acquire_next_frame(
			_HW_3D_IN_ UINT timeout_in_milliseconds
		) override {
		_HW_3D_STD_ tuple<Result, Outdupl_frame_info, _HW_3D_STD_ unique_ptr<IResource>> res;

		auto&[r, info, resources] = res;

		IDXGIResource* p_resource = nullptr;
		r = static_cast<Result>(this->_handle->AcquireNextFrame(timeout_in_milliseconds, value_ptr(info), &p_resource));

		resources = _HW_3D_STD_ make_unique<_Resource<true>>(p_resource);

		return res;
	}

	Outdupl_desc
		get_desc(
		) override {
		Outdupl_desc res;
		this->_handle->GetDesc(value_ptr(res));
		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<RECT>>
		get_frame_dirty_rects(
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<RECT>> res;

		auto&[r, rects] = res;

		UINT size = 0;
		this->_handle->GetFrameDirtyRects(0, rects.data(), &size);

		assert(size % sizeof(RECT) == 0);
		rects.resize(size / sizeof(RECT));
		r = static_cast<Result>(this->_handle->GetFrameDirtyRects(size, rects.data(), &size));

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<Outdupl_move_rect>>
		get_frame_move_rects(
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<Outdupl_move_rect>> res;

		auto&[r, rects] = res;

		UINT size = 0;
		this->_handle->GetFrameMoveRects(0, (DXGI_OUTDUPL_MOVE_RECT*)(rects.data()), &size);

		assert(size % sizeof(DXGI_OUTDUPL_MOVE_RECT) == 0);
		rects.resize(size / sizeof(DXGI_OUTDUPL_MOVE_RECT));
		r = static_cast<Result>(this->_handle->GetFrameMoveRects(size, (DXGI_OUTDUPL_MOVE_RECT*)(rects.data()), &size));

		return res;
	}

	_HW_3D_STD_ tuple<Result, Outdupl_pointer_shape_info>
		get_frame_pointer_shape(
			_HW_3D_IN_ UINT buffer_size,
			_HW_3D_OUT_ void* buffer,
			_HW_3D_OUT_ UINT* buffer_size_required
		) override {
		_HW_3D_STD_ tuple<Result, Outdupl_pointer_shape_info> res;

		auto&[r, info] = res;
		r = static_cast<Result>(this->_handle->GetFramePointerShape(buffer_size, buffer, buffer_size_required, value_ptr(info)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, Mapped_rect>
		map_desktop_surface(
		) override {
		_HW_3D_STD_ tuple<Result, Mapped_rect> res;

		auto&[r, rect] = res;
		r = static_cast<Result>(this->_handle->MapDesktopSurface(value_ptr(rect)));

		return res;
	}

	Result
		release_frame(
		) override {
		return static_cast<Result>(this->_handle->ReleaseFrame());
	}

	Result
		unmap_desktop_surface(
		) override {
		return static_cast<Result>(this->_handle->UnMapDesktopSurface());
	}

	virtual ~_TOutput_duplication() {}
};

//
//
template <bool own>
class _Output_duplication : public _TOutput_duplication<IOutput_duplication, IDXGIOutputDuplication, own> {
public:
	explicit _Output_duplication(IDXGIOutputDuplication* handle)
		: _TOutput_duplication<IOutput_duplication, IDXGIOutputDuplication, own>(handle) {

	}

	IDXGIOutputDuplication* get() override {
		return this->_handle;
	}

	const IDXGIOutputDuplication* get() const override {
		return this->_handle;
	}

	~_Output_duplication() final {}

};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TAdapter : public _TObject<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IAdapter, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIAdapter, Ty>);
public:
	explicit _TAdapter(Ty* handle)
		: _TObject<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, LARGE_INTEGER>
		check_interface_support(
			_HW_3D_IN_ REFGUID interface_name
		) override {
		_HW_3D_STD_ tuple<Result, LARGE_INTEGER> res;

		auto&[r, r1] = res;
		r = static_cast<Result>(this->_handle->CheckInterfaceSupport(interface_name, &r1));

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IOutput>>
		enum_outputs(
			_HW_3D_IN_ UINT output
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IOutput>> res;

		auto&[r, outputs] = res;

		IDXGIOutput* p_output = nullptr;
		r = static_cast<Result>(this->_handle->EnumOutputs(output, &p_output));

		outputs = _HW_3D_STD_ make_unique<_Output<true>>(p_output);

		return res;
	}

	_HW_3D_STD_ tuple<Result, Adapter_desc>
		get_desc(
		) override {
		_HW_3D_STD_ tuple<Result, Adapter_desc> res;

		auto &[r, desc] = res;
		r = static_cast<Result>(this->_handle->GetDesc(value_ptr(desc)));

		return res;
	}

	virtual ~_TAdapter() {}
};

//
//
template <bool own>
class _Adapter : public _TAdapter<IAdapter, IDXGIAdapter, own> {
public:
	explicit _Adapter(IDXGIAdapter* handle)
		: _TAdapter<IAdapter, IDXGIAdapter, own>(handle) {

	}

	IDXGIAdapter* get() override {
		return this->_handle;
	}

	const IDXGIAdapter* get() const override {
		return this->_handle;
	}

	~_Adapter() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDebug : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDebug, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIDebug, Ty>);
public:
	explicit _TDebug(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	Result
		report_live_objects(
			_HW_3D_IN_ GUID appid,
			_HW_3D_IN_ Debug_rlo_flag flags
		) override {
		return static_cast<Result>(this->_handle->ReportLiveObjects(appid, static_cast<DXGI_DEBUG_RLO_FLAGS>(Debug_rlo_flag::mask_type(flags))));
	}

	virtual ~_TDebug() {}
};

//
//
template <bool own>
class _Debug : public _TDebug<IDebug, IDXGIDebug, own> {
public:
	explicit _Debug(IDXGIDebug* handle)
		: _TDebug<IDebug, IDXGIDebug, own>(handle) {

	}

	IDXGIDebug* get() override {
		return this->_handle;
	}

	const IDXGIDebug* get() const override {
		return this->_handle;
	}

	~_Debug() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDisplay_control : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDisplay_control, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIDisplayControl, Ty>);
public:
	explicit  _TDisplay_control(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	BOOL
		is_stereo_enabled(
		) override {
		return this->_handle->IsStereoEnabled();
	}

	void
		set_stereo_enabled(
			BOOL enabled
		) override {
		this->_handle->SetStereoEnabled(enabled);
	}

	virtual ~_TDisplay_control() {}
};

//
//
template <bool own>
class _Display_control : public _TDisplay_control<IDisplay_control, IDXGIDisplayControl, own> {
public:
	explicit _Display_control(IDXGIDisplayControl* handle)
		: _TDisplay_control<IDisplay_control, IDXGIDisplayControl, own>(handle) {

	}

	IDXGIDisplayControl* get() override {
		return this->_handle;
	}

	const IDXGIDisplayControl* get() const override {
		return this->_handle;
	}

	~_Display_control() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDecode_swap_chain : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDecode_swap_chain, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIDecodeSwapChain, Ty>);
public:
	explicit _TDecode_swap_chain(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	Multiplane_overlay_ycbcr_flag
		get_color_space(
		) override {
		DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS res = this->_handle->GetColorSpace();
		return Multiplane_overlay_ycbcr_flag_bit(res);
	}

	_HW_3D_STD_ tuple<Result, UINT, UINT>
		get_dest_size(
		) override {
		_HW_3D_STD_ tuple<Result, UINT, UINT> res;

		auto&[r, w, h] = res;
		r = static_cast<Result>(this->_handle->GetDestSize(&w, &h));

		return res;
	}

	_HW_3D_STD_ tuple<Result, RECT>
		get_source_rect(
		) override {
		_HW_3D_STD_ tuple<Result, RECT> res;

		auto&[r, rect] = res;
		r = static_cast<Result>(this->_handle->GetSourceRect(&rect));

		return res;
	}

	_HW_3D_STD_ tuple<Result, RECT>
		get_target_rect(
		) override {
		_HW_3D_STD_ tuple<Result, RECT> res;

		auto&[r, rect] = res;
		r = static_cast<Result>(this->_handle->GetTargetRect(&rect));

		return res;
	}

	Result
		present_buffer(
			_HW_3D_IN_ UINT buffer_to_present,
			_HW_3D_IN_ UINT sync_interval,
			_HW_3D_IN_ Present_mode flags
		) override {
		return static_cast<Result>(this->_handle->PresentBuffer(buffer_to_present, sync_interval, Present_mode::mask_type(flags)));
	}

	Result
		set_color_space(
			_HW_3D_IN_ Multiplane_overlay_ycbcr_flag color_space
		) override {
		return static_cast<Result>(this->_handle->SetColorSpace(static_cast<DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS>(Multiplane_overlay_ycbcr_flag::mask_type(color_space))));
	}

	Result
		set_dest_size(
			_HW_3D_IN_ UINT width,
			_HW_3D_IN_ UINT height
		) override {
		return static_cast<Result>(this->_handle->SetDestSize(width, height));
	}


	Result
		set_source_rect(
			_HW_3D_IN_ const RECT& rect
		) override {
		return static_cast<Result>(this->_handle->SetSourceRect(&rect));
	}


	Result
		set_target_rect(
			_HW_3D_IN_ const RECT& rect
		) override {
		return static_cast<Result>(this->_handle->SetTargetRect(&rect));
	}

	virtual ~_TDecode_swap_chain() {}
};

//
//
template <bool own>
class _Decode_swap_chain : public _TDecode_swap_chain<IDecode_swap_chain, IDXGIDecodeSwapChain, own> {
public:
	explicit _Decode_swap_chain(IDXGIDecodeSwapChain* handle)
		: _TDecode_swap_chain<IDecode_swap_chain, IDXGIDecodeSwapChain, own>(handle) {

	}

	IDXGIDecodeSwapChain* get() override {
		return this->_handle;
	}

	const IDXGIDecodeSwapChain* get() const override {
		return this->_handle;
	}

	~_Decode_swap_chain() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TSurface : public _TDevice_subobject<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ISurface, Interface> && _HW_3D_STD_ is_base_of_v<IDXGISurface, Ty>);
public:
	explicit _TSurface(Ty* handle)
		: _TDevice_subobject<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, Surface_desc>
		get_desc(
		) override {
		_HW_3D_STD_ tuple<Result, Surface_desc> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->GetDesc(value_ptr(desc)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, Mapped_rect>
		map(
			_HW_3D_IN_ Map_flag flags
		) override {
		_HW_3D_STD_ tuple<Result, Mapped_rect> res;

		auto&[r, rect] = res;
		r = static_cast<Result>(this->_handle->Map(value_ptr(rect), Map_flag::mask_type(flags)));

		return res;
	}

	Result
		unmap(
		) override {
		return static_cast<Result>(this->_handle->Unmap());
	}

	virtual ~_TSurface() {}
};

//
//
template <bool own>
class _Surface : public _TSurface<ISurface, IDXGISurface, own> {
public:
	explicit _Surface(IDXGISurface* handle)
		: _TSurface<ISurface, IDXGISurface, own>(handle) {

	}

	IDXGISurface* get() override {
		return this->_handle;
	}

	const IDXGISurface* get() const override {
		return this->_handle;
	}

	~_Surface() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TKeyed_mutex : public _TDevice_subobject<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IKeyed_mutex, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIKeyedMutex, Ty>);
public:
	explicit _TKeyed_mutex(Ty* handle)
		: _TDevice_subobject<Interface, Ty, own>(handle) {

	}

	Result
		acquire_sync(
			_HW_3D_IN_ UINT64 key,
			_HW_3D_IN_ DWORD milliseconds
		) override {
		return static_cast<Result>(this->_handle->AcquireSync(key, milliseconds));
	}

	Result
		release_sync(
			_HW_3D_IN_ UINT64 key
		) override {
		return static_cast<Result>(this->_handle->ReleaseSync(key));
	}

	virtual ~_TKeyed_mutex() {}
};

//
//
template <bool own>
class _Keyed_mutex : public _TKeyed_mutex<IKeyed_mutex, IDXGIKeyedMutex, own> {
public:
	explicit _Keyed_mutex(IDXGIKeyedMutex* handle)
		: _TKeyed_mutex<IKeyed_mutex, IDXGIKeyedMutex, own>(handle) {

	}

	IDXGIKeyedMutex* get() override {
		return this->_handle;
	}

	const IDXGIKeyedMutex* get() const override {
		return this->_handle;
	}

	~_Keyed_mutex() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TInfo_queue : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IInfo_queue, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIInfoQueue, Ty>);
public:
	explicit _TInfo_queue(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	Result
		add_application_message(
			_HW_3D_IN_ Info_queue_message_severity severity,
			_HW_3D_IN_ const _HW_3D_STD_ string& description
		) override {
		return static_cast<Result>(this->_handle->AddApplicationMessage(DXGI_INFO_QUEUE_MESSAGE_SEVERITY(severity), description.c_str()));
	}

	Result
		add_message(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_message_category category,
			_HW_3D_IN_ Info_queue_message_severity severity,
			_HW_3D_IN_ DXGI_INFO_QUEUE_MESSAGE_ID id,
			_HW_3D_IN_ const _HW_3D_STD_ string& description
		) override {
		return static_cast<Result>(this->_handle->AddMessage(producer, DXGI_INFO_QUEUE_MESSAGE_CATEGORY(category), DXGI_INFO_QUEUE_MESSAGE_SEVERITY(severity), id, description.c_str()));
	}

	Result
		add_retrieval_filter_entries(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_filter& filter
		) override {
		return static_cast<Result>(this->_handle->AddRetrievalFilterEntries(producer, value_ptr(filter)));
	}

	Result
		add_storage_filter_entries(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_filter& filter
		) override {
		return static_cast<Result>(this->_handle->AddStorageFilterEntries(producer, value_ptr(filter)));
	}

	void
		clear_retrieval_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		this->_handle->ClearRetrievalFilter(producer);
	}

	void
		clear_stroage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		this->_handle->ClearStorageFilter(producer);
	}

	void
		clear_stored_messages(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		this->_handle->ClearStoredMessages(producer);
	}

	BOOL
		get_break_on_category(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_message_category category
		) override {
		return this->_handle->GetBreakOnCategory(producer, DXGI_INFO_QUEUE_MESSAGE_CATEGORY(category));
	}

	BOOL
		get_break_on_id(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ DXGI_INFO_QUEUE_MESSAGE_ID id
		) override {
		return this->_handle->GetBreakOnID(producer, id);
	}

	BOOL
		get_break_on_severity(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_message_severity severity
		) override {
		return this->_handle->GetBreakOnSeverity(producer, DXGI_INFO_QUEUE_MESSAGE_SEVERITY(severity));
	}

	_HW_3D_STD_ tuple<Result, Info_queue_message>
		get_message(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ UINT64 message_index
		) override {
		_HW_3D_STD_ tuple<Result, Info_queue_message> res;

		auto&[r, msg] = res;

		SIZE_T size = 0;
		this->_handle->GetMessage(producer, message_index, nullptr, &size);

		assert(size == sizeof(Info_queue_message));
		r = static_cast<Result>(this->_handle->GetMessage(producer, message_index, value_ptr(msg), &size));

		return res;
	}

	UINT64
		get_message_count_limit(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		return this->_handle->GetMessageCountLimit(producer);
	}

	BOOL
		get_mute_debug_output(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		return this->_handle->GetMuteDebugOutput(producer);
	}

	UINT64
		get_num_messages_allowed_by_storage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		return this->_handle->GetNumMessagesAllowedByStorageFilter(producer);
	}

	UINT64
		get_num_message_denied_by_storage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		return this->_handle->GetNumMessagesDeniedByStorageFilter(producer);
	}

	UINT64
		get_num_message_discarded_by_message_count_limit(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		return this->_handle->GetNumMessagesDiscardedByMessageCountLimit(producer);
	}

	UINT64
		get_num_stored_messages(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		return this->_handle->GetNumStoredMessages(producer);
	}

	UINT64
		get_num_stored_messages_allowed_by_retrieval_filters(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		return this->_handle->GetNumStoredMessagesAllowedByRetrievalFilters(producer);
	}

	_HW_3D_STD_ tuple<Result, Info_queue_filter>
		get_retrieval_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		_HW_3D_STD_ tuple<Result, Info_queue_filter> res;

		auto&[r, filter] = res;

		SIZE_T size = 0;
		this->_handle->GetRetrievalFilter(producer, nullptr, &size);

		assert(size == sizeof(Info_queue_filter));
		r = static_cast<Result>(this->_handle->GetRetrievalFilter(producer, value_ptr(filter), &size));

		return res;
	}

	UINT
		get_retrieval_filter_stack_size(
			_HW_3D_IN_ DXGI_DEBUG_ID produer
		) override {
		return this->_handle->GetRetrievalFilterStackSize(produer);
	}

	_HW_3D_STD_ tuple<Result, Info_queue_filter>
		get_storage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		_HW_3D_STD_ tuple<Result, Info_queue_filter> res;

		auto&[r, filter] = res;

		SIZE_T size = 0;
		this->_handle->GetStorageFilter(producer, nullptr, &size);

		assert(size == sizeof(Info_queue_filter));
		r = static_cast<Result>(this->_handle->GetStorageFilter(producer, value_ptr(filter), &size));

		return res;
	}

	UINT
		get_storage_filter_stack_size(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		return this->_handle->GetStorageFilterStackSize(producer);
	}

	void
		pop_retrieval_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		this->_handle->PopRetrievalFilter(producer);
	}

	void
		pop_storage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		this->_handle->PopStorageFilter(producer);
	}

	Result
		push_copy_of_retrieval_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID produer
		) override {
		return static_cast<Result>(this->_handle->PushCopyOfRetrievalFilter(produer));
	}

	Result
		push_copy_of_storage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		return static_cast<Result>(this->_handle->PushCopyOfStorageFilter(producer));
	}

	Result
		push_deny_all_retrieval_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		return static_cast<Result>(this->_handle->PushDenyAllRetrievalFilter(producer));
	}

	Result
		push_deny_all_storage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		return static_cast<Result>(this->_handle->PushDenyAllStorageFilter(producer));
	}

	Result
		push_empty_retrieval_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		return static_cast<Result>(this->_handle->PushEmptyRetrievalFilter(producer));
	}

	Result
		push_empty_storage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer
		) override {
		return static_cast<Result>(this->_handle->PushEmptyStorageFilter(producer));
	}

	Result
		push_retrieval_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_filter& filter
		) override {
		return static_cast<Result>(this->_handle->PushRetrievalFilter(producer, value_ptr(filter)));
	}

	Result
		push_storage_filter(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_filter& filter
		) override {
		return static_cast<Result>(this->_handle->PushStorageFilter(producer, value_ptr(filter)));
	}

	Result
		set_break_on_category(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_message_category category,
			_HW_3D_IN_ BOOL enable
		) override {
		return static_cast<Result>(this->_handle->SetBreakOnCategory(producer, DXGI_INFO_QUEUE_MESSAGE_CATEGORY(category), enable));
	}

	Result
		set_break_on_id(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ DXGI_INFO_QUEUE_MESSAGE_ID id,
			_HW_3D_IN_ BOOL enable
		) override {
		return static_cast<Result>(this->_handle->SetBreakOnID(producer, id, enable));
	}

	Result
		set_break_on_severity(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ Info_queue_message_severity severity,
			_HW_3D_IN_ BOOL enable
		) override {
		return static_cast<Result>(this->_handle->SetBreakOnSeverity(producer, DXGI_INFO_QUEUE_MESSAGE_SEVERITY(severity), enable));
	}

	Result
		set_message_count_limit(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ UINT64 message_count_limit
		) override {
		return static_cast<Result>(this->_handle->SetMessageCountLimit(producer, message_count_limit));
	}

	void
		set_mute_debug_output(
			_HW_3D_IN_ DXGI_DEBUG_ID producer,
			_HW_3D_IN_ BOOL mute
		) override {
		this->_handle->SetMuteDebugOutput(producer, mute);
	}

	virtual ~_TInfo_queue() {}
};

//
//
template <bool own>
class _Info_queue : public _TInfo_queue<IInfo_queue, IDXGIInfoQueue, own> {
public:
	explicit _Info_queue(IDXGIInfoQueue* handle)
		: _TInfo_queue<IInfo_queue, IDXGIInfoQueue, own>(handle) {

	}

	IDXGIInfoQueue* get() override {
		return this->_handle;
	}

	const IDXGIInfoQueue* get() const override {
		return this->_handle;
	}

	~_Info_queue() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TSwap_chain : public _TDevice_subobject<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ISwap_chain, Interface> && _HW_3D_STD_ is_base_of_v<IDXGISwapChain, Ty>);
public:
	explicit _TSwap_chain(Ty* handle)
		: _TDevice_subobject<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, void*>
		get_buffer(
			_HW_3D_IN_ UINT buffer,
			_HW_3D_IN_ REFIID riid
		) override {
		_HW_3D_STD_ tuple<Result, void*> res;

		auto&[r, surf] = res;
		r = static_cast<Result>(this->_handle->GetBuffer(buffer, riid, &surf));

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IOutput>>
		get_containing_output(
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IOutput>> res;

		auto&[r, out] = res;

		IDXGIOutput* p_out = nullptr;
		r = static_cast<Result>(this->_handle->GetContainingOutput(&p_out));

		out = _HW_3D_STD_ make_unique<_Output<true>>(p_out);

		return res;
	}

	_HW_3D_STD_ tuple<Result, Swap_chain_desc>
		get_desc(
		) override {
		_HW_3D_STD_ tuple<Result, Swap_chain_desc> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->GetDesc(value_ptr(desc)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, Frame_statistics>
		get_frame_statistics(
		) override {
		_HW_3D_STD_ tuple<Result, Frame_statistics> res;

		auto&[r, statistics] = res;
		r = static_cast<Result>(this->_handle->GetFrameStatistics(value_ptr(statistics)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, BOOL, _HW_3D_STD_ unique_ptr<IOutput>>
		get_fullscreen_state(
		) override {
		_HW_3D_STD_ tuple<Result, BOOL, _HW_3D_STD_ unique_ptr<IOutput>> res;

		auto&[r, is_full, out] = res;

		IDXGIOutput* p_out = nullptr;
		r = static_cast<Result>(this->_handle->GetFullscreenState(&is_full, &p_out));

		out = _HW_3D_STD_ make_unique<_Output<true>>(p_out);

		return res;
	}

	_HW_3D_STD_ tuple<Result, UINT>
		get_last_present_count(
		) override {
		_HW_3D_STD_ tuple<Result, UINT> res;

		auto&[r, count] = res;
		r = static_cast<Result>(this->_handle->GetLastPresentCount(&count));

		return res;
	}

	Result
		present(
			_HW_3D_IN_ UINT interval,
			_HW_3D_IN_ Present_mode flags
		) override {
		return static_cast<Result>(this->_handle->Present(interval, Present_mode::mask_type(flags)));
	}

	Result
		resize_buffers(
			_HW_3D_IN_ UINT buffer_count,
			_HW_3D_IN_ UINT width,
			_HW_3D_IN_ UINT height,
			_HW_3D_IN_ Format format,
			_HW_3D_IN_ Swap_chain_flag flags
		) override {
		return static_cast<Result>(this->_handle->ResizeBuffers(buffer_count, width, height, DXGI_FORMAT(format), Swap_chain_flag::mask_type(flags)));
	}

	Result
		resize_target(
			_HW_3D_IN_ const Mode_desc& parameters
		) override {
		return static_cast<Result>(this->_handle->ResizeTarget(value_ptr(parameters)));
	}

	Result
		set_fullscreen_state(
			_HW_3D_IN_ BOOL fullscreen,
			_HW_3D_IN_ IOutput* target
		) override {
		return static_cast<Result>(this->_handle->SetFullscreenState(fullscreen, value_ptr(target)));
	}

	virtual ~_TSwap_chain() {}
};

//
//
template <bool own>
class _Swap_chain : public _TSwap_chain<ISwap_chain, IDXGISwapChain, own> {
public:
	explicit _Swap_chain(IDXGISwapChain* handle)
		: _TSwap_chain<ISwap_chain, IDXGISwapChain, own>(handle) {

	}

	IDXGISwapChain* get() override {
		return this->_handle;
	}

	const IDXGISwapChain* get() const override {
		return this->_handle;
	}

	~_Swap_chain() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice : public _TObject<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIDevice, Ty>);
public:
	explicit _TDevice(Ty* handle)
		: _TObject<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISurface>>>
		create_surface(
			_HW_3D_IN_ const Surface_desc& desc,
			_HW_3D_IN_ UINT num_surfaces,
			_HW_3D_IN_ Usage usage,
			_HW_3D_IN_ const Shared_resource* p_shared_resource
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISurface>>> res;

		auto&[r, surfs] = res;

		_HW_3D_STD_ vector<IDXGISurface*> p_surf(num_surfaces, nullptr);
		r = static_cast<Result>(this->_handle->CreateSurface(value_ptr(desc), num_surfaces, DXGI_USAGE(usage), value_ptr(p_shared_resource), p_surf.data()));

		_HW_3D_STD_ for_each(p_surf.begin(), p_surf.end(), [&surfs](auto ptr) {surfs.emplace_back(_HW_3D_STD_ make_unique<_Surface<true>>(ptr)); });

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter>>
		get_adapter(
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter>> res;

		auto&[r, adap] = res;

		IDXGIAdapter* p_adap = nullptr;
		r = static_cast<Result>(this->_handle->GetAdapter(&p_adap));

		adap = _HW_3D_STD_ make_unique<_Adapter<true>>(p_adap);

		return res;
	}

	_HW_3D_STD_ tuple<Result, INT>
		get_gpu_thread_priority(
		) override {
		_HW_3D_STD_ tuple<Result, INT> res;

		auto&[r, priority] = res;
		r = static_cast<Result>(this->_handle->GetGPUThreadPriority(&priority));

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<Residency>>
		query_resource_residency(
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBase*>& resources
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<Residency>> res;

		auto&[r, residency] = res;

		residency.resize(resources.size());
		auto resource_handles = values_ptr(resources);

		r = static_cast<Result>(this->_handle->QueryResourceResidency(resource_handles.data(), (DXGI_RESIDENCY*)(residency.data()), UINT(resources.size())));

		return res;
	}

	Result
		set_gpu_thread_priority(
			_HW_3D_IN_ INT priority
		) override {
		return static_cast<Result>(this->_handle->SetGPUThreadPriority(priority));
	}

	virtual ~_TDevice() {}
};

//
//
template <bool own>
class _Device : public _TDevice<IDevice, IDXGIDevice, own> {
public:
	explicit _Device(IDXGIDevice* handle)
		: _TDevice<IDevice, IDXGIDevice, own>(handle) {

	}

	IDXGIDevice* get() override {
		return this->_handle;
	}

	const IDXGIDevice* get() const override {
		return this->_handle;
	}

	~_Device() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TFactory : public _TObject<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IFactory, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIFactory, Ty>);
public:
	explicit _TFactory(Ty* handle)
		: _TObject<Interface, Ty, own>(handle) {

	}


	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter>>
		create_software_adapter(
			_HW_3D_IN_ HMODULE mod
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter>> res;

		auto&[r, adap] = res;

		IDXGIAdapter* p_adap = nullptr;

		r = static_cast<Result>(this->_handle->CreateSoftwareAdapter(mod, &p_adap));
		adap = _HW_3D_STD_ make_unique<_Adapter<true>>(p_adap);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISwap_chain>>
		create_swap_chain(
			_HW_3D_IN_ IBase* device,
			_HW_3D_IN_ Swap_chain_desc& desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISwap_chain>> res;

		auto&[r, sc] = res;

		IDXGISwapChain* p_sc = nullptr;
		r = static_cast<Result>(this->_handle->CreateSwapChain(value_ptr(device), value_ptr(desc), &p_sc));

		sc = _HW_3D_STD_ make_unique<_Swap_chain<true>>(p_sc);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter>>
		enum_adapters(
			_HW_3D_IN_ UINT adapter
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter>> res;

		auto&[r, adap] = res;

		IDXGIAdapter * p_adap = nullptr;
		r = static_cast<Result>(this->_handle->EnumAdapters(adapter, &p_adap));

		adap = _HW_3D_STD_ make_unique<_Adapter<true>>(p_adap);

		return res;
	}

	_HW_3D_STD_ tuple<Result, HWND>
		get_window_association(
		) override {
		_HW_3D_STD_ tuple<Result, HWND> res;

		auto&[r, hwnd] = res;
		r = static_cast<Result>(this->_handle->GetWindowAssociation(&hwnd));

		return res;
	}

	Result
		make_window_association(
			_HW_3D_IN_ HWND window_handle,
			_HW_3D_IN_ UINT flags
		) override {
		return static_cast<Result>(this->_handle->MakeWindowAssociation(window_handle, flags));
	}

	virtual ~_TFactory() {}
};

//
//
template <bool own>
class _Factory : public _TFactory<IFactory, IDXGIFactory, own> {
public:
	explicit _Factory(IDXGIFactory* handle)
		: _TFactory<IFactory, IDXGIFactory, own>(handle) {

	}

	IDXGIFactory* get() override {
		return this->_handle;
	}

	const IDXGIFactory* get() const override {
		return this->_handle;
	}

	~_Factory() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TSwap_chain_media : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ISwap_chain_media, Interface> && _HW_3D_STD_ is_base_of_v<IDXGISwapChainMedia, Ty>);
public:
	explicit _TSwap_chain_media(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, UINT, UINT>
		check_present_duration_support(
			_HW_3D_IN_ UINT desired_present_duration
		) override {
		_HW_3D_STD_ tuple<Result, UINT, UINT> res;

		auto&[r, smaller, larger] = res;
		r = static_cast<Result>(this->_handle->CheckPresentDurationSupport(desired_present_duration, &smaller, &larger));

		return res;
	}

	_HW_3D_STD_ tuple<Result, Frame_statistics_media>
		get_frame_statistics_media(
		) override {
		_HW_3D_STD_ tuple<Result, Frame_statistics_media> res;

		auto&[r, media] = res;
		r = static_cast<Result>(this->_handle->GetFrameStatisticsMedia(value_ptr(media)));

		return res;
	}

	Result
		set_present_duration(
			_HW_3D_IN_ UINT duration
		) override {
		return static_cast<Result>(this->_handle->SetPresentDuration(duration));
	}

	virtual ~_TSwap_chain_media() {}
};

//
//
template <bool own>
class _Swap_chain_media : public _TSwap_chain_media<ISwap_chain_media, IDXGISwapChainMedia, own> {
public:
	explicit _Swap_chain_media(IDXGISwapChainMedia* handle)
		: _TSwap_chain_media<ISwap_chain_media, IDXGISwapChainMedia, own>(handle) {

	}

	IDXGISwapChainMedia* get() override {
		return this->_handle;
	}

	const IDXGISwapChainMedia* get() const override {
		return this->_handle;
	}

	~_Swap_chain_media() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TAdapter1 : public _TAdapter<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IAdapter1, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIAdapter1, Ty>);
public:
	explicit _TAdapter1(Ty* handle)
		: _TAdapter<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, Adapter_desc1>
		get_desc1(
		) override {
		_HW_3D_STD_ tuple<Result, Adapter_desc1> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->GetDesc1(value_ptr(desc)));

		return res;
	}

	virtual ~_TAdapter1() {}
};

//
//
template <bool own>
class _Adapter1 : public _TAdapter1<IAdapter1, IDXGIAdapter1, own> {
public:
	explicit _Adapter1(IDXGIAdapter1* handle)
		: _TAdapter1<IAdapter1, IDXGIAdapter1, own>(handle) {

	}

	IDXGIAdapter1* get() override {
		return this->_handle;
	}

	const IDXGIAdapter1* get() const override {
		return this->_handle;
	}

	~_Adapter1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TAdapter2 : public _TAdapter1<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IAdapter2, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIAdapter2, Ty>);
public:
	explicit _TAdapter2(Ty* handle)
		: _TAdapter1<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, Adapter_desc2>
		get_desc2(
		) override {
		_HW_3D_STD_ tuple<Result, Adapter_desc2> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->GetDesc2(value_ptr(desc)));

		return res;
	}

	virtual ~_TAdapter2() {}
};

//
//
template <bool own>
class _Adapter2 : public _TAdapter2<IAdapter2, IDXGIAdapter2, own> {
public:
	explicit _Adapter2(IDXGIAdapter2* handle)
		: _TAdapter2<IAdapter2, IDXGIAdapter2, own>(handle) {

	}

	IDXGIAdapter2* get() override {
		return this->_handle;
	}

	const IDXGIAdapter2* get() const override {
		return this->_handle;
	}

	~_Adapter2() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TAdapter3 : public _TAdapter2<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IAdapter3, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIAdapter3, Ty>);
public:
	explicit _TAdapter3(Ty* handle)
		: _TAdapter2<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, Query_video_memory_info>
		query_video_memory_info(
			_HW_3D_IN_ UINT node_index,
			_HW_3D_IN_ Memory_segment_group group
		) override {
		_HW_3D_STD_ tuple<Result, Query_video_memory_info> res;

		auto&[r, info] = res;
		r = static_cast<Result>(this->_handle->QueryVideoMemoryInfo(node_index, DXGI_MEMORY_SEGMENT_GROUP(group), value_ptr(info)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, DWORD>
		register_hardware_content_protection_teardown_status_event(
			_HW_3D_IN_ HANDLE h_event
		) override {
		_HW_3D_STD_ tuple<Result, DWORD> res;

		auto&[r, cookie] = res;
		r = static_cast<Result>(this->_handle->RegisterHardwareContentProtectionTeardownStatusEvent(h_event, &cookie));

		return res;
	}

	_HW_3D_STD_ tuple<Result, DWORD>
		register_video_memory_budget_change_notification_event(
			_HW_3D_IN_ HANDLE h_event
		) override {
		_HW_3D_STD_ tuple<Result, DWORD> res;

		auto&[r, cookie] = res;
		r = static_cast<Result>(this->_handle->RegisterVideoMemoryBudgetChangeNotificationEvent(h_event, &cookie));

		return res;
	}

	Result
		set_video_memory_reservation(
			_HW_3D_IN_ UINT node_index,
			_HW_3D_IN_ Memory_segment_group group,
			_HW_3D_IN_ UINT64 reservation
		) override {
		return static_cast<Result>(this->_handle->SetVideoMemoryReservation(node_index, DXGI_MEMORY_SEGMENT_GROUP(group), reservation));
	}

	void
		unregister_hardware_content_protection_teardown_status(
			_HW_3D_IN_ DWORD cookie
		) override {
		this->_handle->UnregisterHardwareContentProtectionTeardownStatus(cookie);
	}

	void
		unregister_video_memory_budget_change_notification(
			_HW_3D_IN_ DWORD cookie
		) override {
		this->_handle->UnregisterVideoMemoryBudgetChangeNotification(cookie);
	}

	virtual ~_TAdapter3() {}
};

//
//
template <bool own>
class _Adapter3 : public _TAdapter3<IAdapter3, IDXGIAdapter3, own> {
public:
	explicit _Adapter3(IDXGIAdapter3* handle)
		: _TAdapter3<IAdapter3, IDXGIAdapter3, own>(handle) {

	}

	IDXGIAdapter3* get() override {
		return this->_handle;
	}

	const IDXGIAdapter3* get() const override {
		return this->_handle;
	}

	~_Adapter3() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TAdapter4 : public _TAdapter3<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IAdapter4, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIAdapter4, Ty>);
public:
	explicit _TAdapter4(Ty* handle)
		: _TAdapter3<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, Adapter_desc3>
		get_desc3(
		) override {
		_HW_3D_STD_ tuple<Result, Adapter_desc3> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->GetDesc3(value_ptr(desc)));

		return res;
	}


	virtual ~_TAdapter4() {}
};

//
//
template <bool own>
class _Adapter4 : public _TAdapter4<IAdapter4, IDXGIAdapter4, own> {
public:
	explicit _Adapter4(IDXGIAdapter4* handle)
		: _TAdapter4<IAdapter4, IDXGIAdapter4, own>(handle) {

	}

	IDXGIAdapter4* get() override {
		return this->_handle;
	}

	const IDXGIAdapter4* get() const override {
		return this->_handle;
	}

	~_Adapter4() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDebug1 : public _TDebug<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDebug1, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIDebug1, Ty>);
public:
	explicit _TDebug1(Ty* handle)
		: _TDebug<Interface, Ty, own>(handle) {

	}

	void
		disable_leak_tracking_for_thread(
		) override {
		this->_handle->DisableLeakTrackingForThread();
	}

	void
		enabled_leak_tracking_for_thread(
		) override {
		this->_handle->EnableLeakTrackingForThread();
	}

	BOOL
		is_leak_tracking_enabled_for_thread(
		) override {
		return this->_handle->IsLeakTrackingEnabledForThread();
	}

	virtual ~_TDebug1() {}
};

//
//
template <bool own>
class _Debug1 : public _TDebug1<IDebug1, IDXGIDebug1, own> {
public:
	explicit _Debug1(IDXGIDebug1* handle)
		: _TDebug1<IDebug1, IDXGIDebug1, own>(handle) {

	}

	IDXGIDebug1* get() override {
		return this->_handle;
	}

	const IDXGIDebug1* get() const override {
		return this->_handle;
	}

	~_Debug1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice1 : public _TDevice<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice1, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIDevice1, Ty>);
public:
	explicit _TDevice1(Ty* handle)
		: _TDevice<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, UINT>
		get_maximum_frame_latency(
		) override {
		_HW_3D_STD_ tuple<Result, UINT> res;

		auto&[r, max_latency] = res;
		r = static_cast<Result>(this->_handle->GetMaximumFrameLatency(&max_latency));

		return res;
	}

	Result
		set_maximum_frame_latency(
			_HW_3D_IN_ UINT max_latency
		) override {
		return static_cast<Result>(this->_handle->SetMaximumFrameLatency(max_latency));
	}

	virtual ~_TDevice1() {}
};

//
//
template <bool own>
class _Device1 : public _TDevice1<IDevice1, IDXGIDevice1, own> {
public:
	explicit _Device1(IDXGIDevice1* handle)
		: _TDevice1<IDevice1, IDXGIDevice1, own>(handle) {

	}

	IDXGIDevice1* get() override {
		return this->_handle;
	}

	const IDXGIDevice1* get() const override {
		return this->_handle;
	}

	~_Device1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice2 : public _TDevice1<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice2, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIDevice2, Ty>);
public:
	explicit _TDevice2(Ty* handle)
		: _TDevice1<Interface, Ty, own>(handle) {

	}

	Result
		enqueue_set_event(
			_HW_3D_IN_ HANDLE h_event
		) override {
		return static_cast<Result>(this->_handle->EnqueueSetEvent(h_event));
	}

	Result
		offer_resources(
			_HW_3D_IN_ const _HW_3D_STD_ vector<IResource*>&  resources,
			_HW_3D_IN_ Offer_resource_priority priority
		) override {
		auto resource_handles = values_ptr(resources);
		return static_cast<Result>(this->_handle->OfferResources(UINT(resources.size()), resource_handles.data(), DXGI_OFFER_RESOURCE_PRIORITY(priority)));
	}

	_HW_3D_STD_ tuple<Result, BOOL>
		reclaim_resources(
			_HW_3D_IN_ const _HW_3D_STD_ vector<IResource*>& resources
		) override {
		_HW_3D_STD_ tuple<Result, BOOL> res;

		auto&[r, discarded] = res;

		auto resource_handles = values_ptr(resources);
		r = static_cast<Result>(this->_handle->ReclaimResources(UINT(resources.size()), resource_handles.data(), &discarded));

		return res;
	}

	virtual ~_TDevice2() {}
};

//
//
template <bool own>
class _Device2 : public _TDevice2<IDevice2, IDXGIDevice2, own> {
public:
	explicit _Device2(IDXGIDevice2* handle)
		: _TDevice2<IDevice2, IDXGIDevice2, own>(handle) {

	}

	IDXGIDevice2* get() override {
		return this->_handle;
	}

	const IDXGIDevice2* get() const override {
		return this->_handle;
	}

	~_Device2() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice3 : public _TDevice2<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice3, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIDevice3, Ty>);
public:
	explicit _TDevice3(Ty* handle)
		: _TDevice2<Interface, Ty, own>(handle) {

	}

	void
		trim(
		) override {
		this->_handle->Trim();
	}

	virtual ~_TDevice3() {}
};

//
//
template <bool own>
class _Device3 : public _TDevice3<IDevice3, IDXGIDevice3, own> {
public:
	explicit _Device3(IDXGIDevice3* handle)
		: _TDevice3<IDevice3, IDXGIDevice3, own>(handle) {

	}

	IDXGIDevice3* get() override {
		return this->_handle;
	}

	const IDXGIDevice3* get() const override {
		return this->_handle;
	}

	~_Device3() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice4 : public _TDevice3<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice4, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIDevice4, Ty>);
public:
	explicit _TDevice4(Ty* handle)
		: _TDevice3<Interface, Ty, own>(handle) {

	}

	Result
		offer_resource1(
			_HW_3D_IN_ const _HW_3D_STD_ vector<IResource*>& resources,
			_HW_3D_IN_ Offer_resource_priority priority,
			_HW_3D_IN_ Offer_resource_flag flags
		) override {
		auto resource_handles = values_ptr(resources);
		return static_cast<Result>(this->_handle->OfferResources1(UINT(resources.size()), resource_handles.data(), DXGI_OFFER_RESOURCE_PRIORITY(priority), Offer_resource_flag::mask_type(flags)));
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<Reclaim_resource_results>>
		reclaim_resources1(
			_HW_3D_IN_ const _HW_3D_STD_ vector<IResource*>& resources
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<Reclaim_resource_results>> res;

		auto&[r, rs] = res;

		auto resource_handles = values_ptr(resources);
		rs.resize(resources.size());
		r = static_cast<Result>(this->_handle->ReclaimResources1(UINT(resources.size()), resource_handles.data(), (DXGI_RECLAIM_RESOURCE_RESULTS*)(rs.data())));

		return res;
	}

	virtual ~_TDevice4() {}
};

//
//
template <bool own>
class _Device4 : public _TDevice4<IDevice4, IDXGIDevice4, own> {
public:
	explicit _Device4(IDXGIDevice4* handle)
		: _TDevice4<IDevice4, IDXGIDevice4, own>(handle) {

	}

	IDXGIDevice4* get() override {
		return this->_handle;
	}

	const IDXGIDevice4* get() const override {
		return this->_handle;
	}

	~_Device4() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TOutput1 : public _TOutput<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IOutput1, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIOutput1, Ty>);
public:
	explicit _TOutput1(Ty* handle)
		: _TOutput<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IOutput_duplication>>
		duplicate_output(
			_HW_3D_IN_ IBase* device
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IOutput_duplication>> res;

		auto&[r, od] = res;

		IDXGIOutputDuplication* p_od = nullptr;
		r = static_cast<Result>(this->_handle->DuplicateOutput(value_ptr(device), &p_od));

		od = _HW_3D_STD_ make_unique<_Output_duplication<true>>(p_od);

		return res;
	}

	_HW_3D_STD_ tuple<Result, Mode_desc1>
		find_closest_matching_mode1(
			_HW_3D_IN_ const Mode_desc1& mode_to_match,
			_HW_3D_IN_ IBase* concerned_device
		) override {
		_HW_3D_STD_ tuple<Result, Mode_desc1> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->FindClosestMatchingMode1(value_ptr(mode_to_match), value_ptr(desc), value_ptr(concerned_device)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<Mode_desc1>>
		get_display_mode_list1(
			_HW_3D_IN_ Format enum_format,
			_HW_3D_IN_ Display_mode flags
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ vector<Mode_desc1>> res;

		auto&[r, descs] = res;

		UINT size = 0;
		this->_handle->GetDisplayModeList1(DXGI_FORMAT(enum_format), Display_mode::mask_type(flags), &size, nullptr);

		descs.resize(size);
		r = static_cast<Result>(this->_handle->GetDisplayModeList1(DXGI_FORMAT(enum_format), Display_mode::mask_type(flags), &size, reinterpret_cast<DXGI_MODE_DESC1*>(descs.data())));

		return res;
	}

	Result
		get_display_surface_data1(
			_HW_3D_IN_ IResource* dest
		) override {
		return static_cast<Result>(this->_handle->GetDisplaySurfaceData1(value_ptr(dest)));
	}

	virtual ~_TOutput1() {}
};

//
//
template <bool own>
class _Output1 : public _TOutput1<IOutput1, IDXGIOutput1, own> {
public:
	explicit _Output1(IDXGIOutput1* handle)
		: _TOutput1<IOutput1, IDXGIOutput1, own>(handle) {

	}

	IDXGIOutput1* get() override {
		return this->_handle;
	}

	const IDXGIOutput1* get() const override {
		return this->_handle;
	}

	~_Output1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TOutput2 : public _TOutput1<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IOutput2, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIOutput2, Ty>);
public:
	explicit _TOutput2(Ty* handle)
		: _TOutput1<Interface, Ty, own>(handle) {

	}

	BOOL
		supports_overlays(
		) override {
		return this->_handle->SupportsOverlays();
	}

	virtual ~_TOutput2() {}
};

//
//
template <bool own>
class _Output2 : public _TOutput2<IOutput2, IDXGIOutput2, own> {
public:
	explicit _Output2(IDXGIOutput2* handle)
		: _TOutput2<IOutput2, IDXGIOutput2, own>(handle) {
	}

	IDXGIOutput2* get() override {
		return this->_handle;
	}

	const IDXGIOutput2* get() const override {
		return this->_handle;
	}

	~_Output2() final {}
};


//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TOutput3 : public _TOutput2<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IOutput3, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIOutput3, Ty>);
public:
	explicit _TOutput3(Ty* handle)
		: _TOutput2<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, Overlay_support_flag>
		check_overlay_support(
			_HW_3D_IN_ Format enum_format,
			_HW_3D_IN_ IBase* device
		) override {
		_HW_3D_STD_ tuple<Result, Overlay_support_flag> res;

		auto&[r, flags] = res;

		UINT flag = 0;
		r = static_cast<Result>(this->_handle->CheckOverlaySupport(DXGI_FORMAT(enum_format), value_ptr(device), &flag));

		flags = Overlay_support_flag_bit(flag);

		return res;
	}

	virtual ~_TOutput3() {}
};

//
//
template <bool own>
class _Output3 : public _TOutput3<IOutput3, IDXGIOutput3, own> {
public:
	explicit _Output3(IDXGIOutput3* handle)
		: _TOutput3<IOutput3, IDXGIOutput3, own>(handle) {

	}

	IDXGIOutput3* get() override {
		return this->_handle;
	}

	const IDXGIOutput3* get() const override {
		return this->_handle;
	}

	~_Output3() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TOutput4 : public _TOutput3<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IOutput4, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIOutput4, Ty>);
public:
	explicit _TOutput4(Ty* handle)
		: _TOutput3<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, Overlay_color_space_support_flag>
		check_overlay_color_space_support(
			_HW_3D_IN_ Format format,
			_HW_3D_IN_ Color_space_type color_space,
			_HW_3D_IN_ IBase* device
		) override {
		_HW_3D_STD_ tuple<Result, Overlay_color_space_support_flag> res;

		auto&[r, flags] = res;

		UINT flag = 0;
		r = static_cast<Result>(this->_handle->CheckOverlayColorSpaceSupport(DXGI_FORMAT(format), DXGI_COLOR_SPACE_TYPE(color_space), value_ptr(device), &flag));

		flags = Overlay_color_space_support_flag_bit(flag);

		return res;
	}

	virtual ~_TOutput4() {}
};

//
//
template <bool own>
class _Output4 : public _TOutput4<IOutput4, IDXGIOutput4, own> {
public:
	explicit _Output4(IDXGIOutput4* handle)
		: _TOutput4<IOutput4, IDXGIOutput4, own>(handle) {

	}

	IDXGIOutput4* get() override {
		return this->_handle;
	}

	const IDXGIOutput4* get() const override {
		return this->_handle;
	}

	~_Output4() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TOutput5 : public _TOutput4<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IOutput5, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIOutput5, Ty>);
public:
	explicit _TOutput5(Ty* handle)
		: _TOutput4<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IOutput_duplication>>
		duplicate_output1(
			_HW_3D_IN_ IBase* device,
			_HW_3D_IN_ /*unused*/ UINT flags,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Format>& formats
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IOutput_duplication>> res;

		auto&[r, od] = res;

		IDXGIOutputDuplication* p_od = nullptr;
		r = static_cast<Result>(this->_handle->DuplicateOutput1(value_ptr(device), flags, UINT(formats.size()), (DXGI_FORMAT*)(formats.data()), &p_od));

		od = _HW_3D_STD_ make_unique<_Output_duplication<true>>(p_od);

		return res;
	}

	virtual ~_TOutput5() {}
};

//
//
template <bool own>
class _Output5 : public _TOutput5<IOutput5, IDXGIOutput5, own> {
public:
	explicit _Output5(IDXGIOutput5* handle)
		: _TOutput5<IOutput5, IDXGIOutput5, own>(handle) {

	}

	IDXGIOutput5* get() override {
		return this->_handle;
	}

	const IDXGIOutput5* get() const override {
		return this->_handle;
	}

	~_Output5() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TOutput6 : public _TOutput5<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IOutput6, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIOutput6, Ty>);
public:
	explicit _TOutput6(Ty* handle)
		: _TOutput5<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, Output_desc1>
		get_desc1(
		) override {
		_HW_3D_STD_ tuple<Result, Output_desc1> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->GetDesc1(value_ptr(desc)));

		return res;
	}

	virtual ~_TOutput6() {}
};

//
//
template <bool own>
class _Output6 : public _TOutput6<IOutput6, IDXGIOutput6, own> {
public:
	explicit _Output6(IDXGIOutput6* handle)
		: _TOutput6<IOutput6, IDXGIOutput6, own>(handle) {

	}

	IDXGIOutput6* get() override {
		return this->_handle;
	}

	const IDXGIOutput6* get() const override {
		return this->_handle;
	}

	~_Output6() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TSurface1 : public _TSurface<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ISurface1, Interface> && _HW_3D_STD_ is_base_of_v<IDXGISurface1, Ty>);
public:
	explicit _TSurface1(Ty* handle)
		: _TSurface<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, HDC>
		get_dc(
			_HW_3D_IN_ BOOL discard
		) override {
		_HW_3D_STD_ tuple<Result, HDC> res;

		auto&[r, hdc] = res;
		r = static_cast<Result>(this->_handle->GetDC(discard, &hdc));

		return res;
	}

	Result
		release_dc(
			_HW_3D_IN_ RECT* dirty_rect
		) override {
		return static_cast<Result>(this->_handle->ReleaseDC(value_ptr(dirty_rect)));
	}

	virtual ~_TSurface1() {}
};

//
//
template <bool own>
class _Surface1 : public _TSurface1<ISurface1, IDXGISurface1, own> {
public:
	explicit _Surface1(IDXGISurface1* handle)
		: _TSurface1<ISurface1, IDXGISurface1, own>(handle) {

	}

	IDXGISurface1* get() override {
		return this->_handle;
	}

	const IDXGISurface1* get() const override {
		return this->_handle;
	}

	~_Surface1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TSurface2 : public _TSurface1<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ISurface2, Interface> && _HW_3D_STD_ is_base_of_v<IDXGISurface2, Ty>);
public:
	explicit _TSurface2(Ty* handle)
		: _TSurface1<Interface, Ty, own>(handle) {

	}

	Result
		get_resource(
			_HW_3D_IN_ REFIID riid,
			_HW_3D_IN_ void** p_parent_resource,
			_HW_3D_IN_ UINT* p_subresource_index
		) override {
		return static_cast<Result>(this->_handle->GetResource(riid, p_parent_resource, p_subresource_index));
	}

	virtual ~_TSurface2() {}
};

//
//
template <bool own>
class _Surface2 : public _TSurface2<ISurface2, IDXGISurface2, own> {
public:
	explicit _Surface2(IDXGISurface2* handle)
		: _TSurface2<ISurface2, IDXGISurface2, own>(handle) {

	}

	IDXGISurface2* get() override {
		return this->_handle;
	}

	const IDXGISurface2* get() const override {
		return this->_handle;
	}

	~_Surface2() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TResource1 : public _TResource<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IResource1, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIResource1, Ty>);
public:
	explicit _TResource1(Ty* handle)
		: _TResource<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, HANDLE>
		create_shared_handle(
			_HW_3D_IN_ const SECURITY_ATTRIBUTES& attributes,
			_HW_3D_IN_ DWORD access,
			_HW_3D_IN_ const _HW_3D_STD_ wstring& name
		) override {
		_HW_3D_STD_ tuple<Result, HANDLE> res;

		auto&[r, h] = res;
		r = static_cast<Result>(this->_handle->CreateSharedHandle(value_ptr(attributes), access, name.c_str(), &h));

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISurface2>>
		create_subresource_surface(
			_HW_3D_IN_ UINT index
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISurface2>> res;

		auto&[r, surf] = res;

		IDXGISurface2* p_surf = nullptr;
		r = static_cast<Result>(this->_handle->CreateSubresourceSurface(index, &p_surf));

		surf = _HW_3D_STD_ make_unique<_Surface2<true>>(p_surf);

		return res;
	}

	virtual ~_TResource1() {}
};

//
//
template <bool own>
class _Resource1 : public _TResource1<IResource1, IDXGIResource1, own> {
public:
	explicit _Resource1(IDXGIResource1* handle)
		: _TResource1<IResource1, IDXGIResource1, own>(handle) {

	}

	IDXGIResource1* get() override {
		return this->_handle;
	}

	const IDXGIResource1* get() const override {
		return this->_handle;
	}

	~_Resource1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TSwap_chain1 : public _TSwap_chain<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ISwap_chain1, Interface> && _HW_3D_STD_ is_base_of_v<IDXGISwapChain1, Ty>);
public:
	explicit _TSwap_chain1(Ty* handle)
		: _TSwap_chain<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, Rgba>
		get_background_color(
		) override {
		_HW_3D_STD_ tuple<Result, Rgba> res;

		auto&[r, color] = res;
		r = static_cast<Result>(this->_handle->GetBackgroundColor(value_ptr(color)));

		return res;
	}

	Result
		get_core_window(
			_HW_3D_IN_ REFIID refiid,
			_HW_3D_OUT_ void** unk
		) override {
		return static_cast<Result>(this->_handle->GetCoreWindow(refiid, unk));
	}

	_HW_3D_STD_ tuple<Result, Swap_chain_desc1>
		get_desc1(
		) override {
		_HW_3D_STD_ tuple<Result, Swap_chain_desc1> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->GetDesc1(value_ptr(desc)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, Swap_chain_fullscreen_desc>
		get_fullscreeen_desc(
		) override {
		_HW_3D_STD_ tuple<Result, Swap_chain_fullscreen_desc> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->GetFullscreenDesc(value_ptr(desc)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, HWND>
		get_hwnd(
		) override {
		_HW_3D_STD_ tuple<Result, HWND> res;

		auto&[r, hwnd] = res;
		r = static_cast<Result>(this->_handle->GetHwnd(&hwnd));

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IOutput>>
		get_restrict_to_output(
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IOutput>> res;

		auto&[r, out] = res;

		IDXGIOutput* p_out = nullptr;
		r = static_cast<Result>(this->_handle->GetRestrictToOutput(&p_out));

		out = _HW_3D_STD_ make_unique<_Output<true>>(p_out);

		return res;
	}

	_HW_3D_STD_ tuple<Result, Mode_rotation>
		get_rotation(
		) override {
		_HW_3D_STD_ tuple<Result, Mode_rotation> res;

		auto&[r, rotation] = res;
		r = static_cast<Result>(this->_handle->GetRotation((DXGI_MODE_ROTATION*)(&rotation)));

		return res;
	}

	BOOL
		is_temporary_mono_supported(
		) override {
		return this->_handle->IsTemporaryMonoSupported();
	}

	Result
		present1(
			_HW_3D_IN_ UINT sync_interval,
			_HW_3D_IN_ Present_mode flags,
			_HW_3D_IN_ const Present_parameters& parameters
		) override {
		return static_cast<Result>(this->_handle->Present1(sync_interval, Present_mode::mask_type(flags), value_ptr(parameters)));
	}

	Result
		set_background_color(
			_HW_3D_IN_ const Rgba& color
		) override {
		return static_cast<Result>(this->_handle->SetBackgroundColor(value_ptr(color)));
	}

	Result
		set_rotation(
			_HW_3D_IN_ Mode_rotation rotation
		) override {
		return static_cast<Result>(this->_handle->SetRotation(DXGI_MODE_ROTATION(rotation)));
	}

	virtual ~_TSwap_chain1() {}
};

//
//
template <bool own>
class _Swap_chain1 : public _TSwap_chain1<ISwap_chain1, IDXGISwapChain1, own> {
public:
	explicit _Swap_chain1(IDXGISwapChain1* handle)
		: _TSwap_chain1<ISwap_chain1, IDXGISwapChain1, own>(handle) {

	}

	IDXGISwapChain1* get() override {
		return this->_handle;
	}

	const IDXGISwapChain1* get() const override {
		return this->_handle;
	}

	~_Swap_chain1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TSwap_chain2 : public _TSwap_chain1<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ISwap_chain2, Interface> && _HW_3D_STD_ is_base_of_v<IDXGISwapChain2, Ty>);
public:
	explicit _TSwap_chain2(Ty* handle)
		: _TSwap_chain1<Interface, Ty, own>(handle) {

	}

	HANDLE
		get_frame_latency_waitable_object(
		) override {
		return this->_handle->GetFrameLatencyWaitableObject();
	}

	_HW_3D_STD_ tuple<Result, DXGI_MATRIX_3X2_F>
		get_matrix_transform(
		) override {
		_HW_3D_STD_ tuple<Result, DXGI_MATRIX_3X2_F> res;

		auto&[r, matrix] = res;
		r = static_cast<Result>(this->_handle->GetMatrixTransform(&matrix));

		return res;
	}

	_HW_3D_STD_ tuple<Result, UINT>
		get_maximum_frame_latency(
		) override {
		_HW_3D_STD_ tuple<Result, UINT> res;

		auto&[r, latency] = res;
		r = static_cast<Result>(this->_handle->GetMaximumFrameLatency(&latency));

		return res;
	}

	_HW_3D_STD_ tuple<Result, UINT, UINT>
		get_source_size(
		) override {
		_HW_3D_STD_ tuple<Result, UINT, UINT> res;

		auto&[r, w, h] = res;
		r = static_cast<Result>(this->_handle->GetSourceSize(&w, &h));

		return res;
	}

	Result
		set_matrix_transform(
			_HW_3D_IN_ const DXGI_MATRIX_3X2_F& matrix
		) override {
		return static_cast<Result>(this->_handle->SetMatrixTransform(value_ptr(matrix)));
	}

	Result
		set_maximum_frame_latency(
			_HW_3D_IN_ UINT max_latency
		) override {
		return static_cast<Result>(this->_handle->SetMaximumFrameLatency(max_latency));
	}

	Result
		set_source_size(
			_HW_3D_IN_ UINT width,
			_HW_3D_IN_ UINT height
		) override {
		return static_cast<Result>(this->_handle->SetSourceSize(width, height));
	}

	virtual ~_TSwap_chain2() {}
};

//
//
template <bool own>
class _Swap_chain2 : public _TSwap_chain2<ISwap_chain2, IDXGISwapChain2, own> {
public:
	explicit _Swap_chain2(IDXGISwapChain2* handle)
		: _TSwap_chain2<ISwap_chain2, IDXGISwapChain2, own>(handle) {

	}

	IDXGISwapChain2* get() override {
		return this->_handle;
	}

	const IDXGISwapChain2* get() const override {
		return this->_handle;
	}

	~_Swap_chain2() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TSwap_chain3 : public _TSwap_chain2<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ISwap_chain3, Interface> && _HW_3D_STD_ is_base_of_v<IDXGISwapChain3, Ty>);
public:
	explicit _TSwap_chain3(Ty* handle)
		: _TSwap_chain2<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, Swap_chain_color_space_support_flag>
		check_color_space_support(
			_HW_3D_IN_ Color_space_type color_space
		) override {
		_HW_3D_STD_ tuple<Result, Swap_chain_color_space_support_flag> res;

		auto&[r, flags] = res;

		UINT flag = 0;
		r = static_cast<Result>(this->_handle->CheckColorSpaceSupport(DXGI_COLOR_SPACE_TYPE(color_space), &flag));

		flags = Swap_chain_color_space_support_flag_bit(flag);

		return res;
	}

	UINT
		get_current_back_buffer_index(
		) override {
		return this->_handle->GetCurrentBackBufferIndex();
	}

	Result
		resize_buffers1(
			_HW_3D_IN_ UINT width,
			_HW_3D_IN_ UINT height,
			_HW_3D_IN_ Format format,
			_HW_3D_IN_ Swap_chain_flag flags,
			_HW_3D_IN_ const _HW_3D_STD_ vector<UINT>& masks,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBase*>& present_queue
		) override {
		assert(masks.size() == present_queue.size());

		auto queue_handles = values_ptr(present_queue);

		return static_cast<Result>(this->_handle->ResizeBuffers1(
			UINT(masks.size()),
			width,
			height,
			DXGI_FORMAT(format),
			Swap_chain_flag::mask_type(flags),
			masks.data(),
			queue_handles.data()
		));
	}

	Result
		set_color_space1(
			_HW_3D_IN_ Color_space_type color_space
		) override {
		return static_cast<Result>(this->_handle->SetColorSpace1(DXGI_COLOR_SPACE_TYPE(color_space)));
	}

	virtual ~_TSwap_chain3() {}
};

//
//
template <bool own>
class _Swap_chain3 : public _TSwap_chain3<ISwap_chain3, IDXGISwapChain3, own> {
public:
	explicit _Swap_chain3(IDXGISwapChain3* handle)
		: _TSwap_chain3<ISwap_chain3, IDXGISwapChain3, own>(handle) {

	}

	IDXGISwapChain3* get() override {
		return this->_handle;
	}

	const IDXGISwapChain3* get() const override {
		return this->_handle;
	}

	~_Swap_chain3() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TSwap_chain4 : public _TSwap_chain3<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ISwap_chain4, Interface> && _HW_3D_STD_ is_base_of_v<IDXGISwapChain4, Ty>);
public:
	explicit _TSwap_chain4(Ty* handle)
		: _TSwap_chain3<Interface, Ty, own>(handle) {

	}

	Result
		set_hdr_meta_data(
			_HW_3D_IN_ Hdr_metadata_type type,
			_HW_3D_IN_ UINT size,
			_HW_3D_IN_ void* meta_data
		) override {
		return static_cast<Result>(this->_handle->SetHDRMetaData(DXGI_HDR_METADATA_TYPE(type), size, value_ptr(meta_data)));
	}

	virtual ~_TSwap_chain4() {}
};

//
//
template <bool own>
class _Swap_chain4 : public _TSwap_chain4<ISwap_chain4, IDXGISwapChain4, own> {
public:
	explicit _Swap_chain4(IDXGISwapChain4* handle)
		: _TSwap_chain4<ISwap_chain4, IDXGISwapChain4, own>(handle) {

	}

	IDXGISwapChain4* get() override {
		return this->_handle;
	}

	const IDXGISwapChain4* get() const override {
		return this->_handle;
	}

	~_Swap_chain4() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TFactory1 : public _TFactory<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IFactory1, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIFactory1, Ty>);
public:
	explicit _TFactory1(Ty* handle)
		: _TFactory<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter1>>
		enum_adapters1(
			_HW_3D_IN_ UINT adapter
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter1>> res;

		auto&[r, adap] = res;

		IDXGIAdapter1* p_adap = nullptr;
		r = static_cast<Result>(this->_handle->EnumAdapters1(adapter, &p_adap));

		adap = _HW_3D_STD_ make_unique<_Adapter1<true>>(p_adap);

		return res;
	}

	BOOL
		is_current(
		) override {
		return this->_handle->IsCurrent();
	}

	virtual ~_TFactory1() {}
};

//
//
template <bool own>
class _Factory1 : public _TFactory1<IFactory1, IDXGIFactory1, own> {
public:
	explicit _Factory1(IDXGIFactory1* handle)
		: _TFactory1<IFactory1, IDXGIFactory1, own>(handle) {
	}

	IDXGIFactory1* get() override {
		return this->_handle;
	}

	const IDXGIFactory1* get() const override {
		return this->_handle;
	}

	~_Factory1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TFactory2 : public _TFactory1<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IFactory2, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIFactory2, Ty>);
public:
	explicit _TFactory2(Ty* handle)
		: _TFactory1<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISwap_chain1>>
		create_swap_chain_for_composition(
			_HW_3D_IN_ IBase* device,
			_HW_3D_IN_ const Swap_chain_desc1& desc,
			_HW_3D_IN_ IOutput* restrict_to_output
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISwap_chain1>> res;

		auto&[r, swapchain] = res;

		IDXGISwapChain1* p_swapchain = nullptr;
		r = static_cast<Result>(this->_handle->CreateSwapChainForComposition(value_ptr(device), value_ptr(desc), value_ptr(restrict_to_output), &p_swapchain));

		swapchain = _HW_3D_STD_ make_unique<_Swap_chain1<true>>(p_swapchain);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISwap_chain1>>
		create_swap_chain_for_core_window(
			_HW_3D_IN_ IBase* device,
			_HW_3D_IN_ IBase* window,
			_HW_3D_IN_ const Swap_chain_desc1& desc,
			_HW_3D_IN_ IOutput* restrict_to_output
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISwap_chain1>> res;

		auto&[r, swapchain] = res;

		IDXGISwapChain1* p_swapchain = nullptr;
		r = static_cast<Result>(this->_handle->CreateSwapChainForCoreWindow(value_ptr(device), value_ptr(window), value_ptr(desc), value_ptr(restrict_to_output), &p_swapchain));

		swapchain = _HW_3D_STD_ make_unique<_Swap_chain1<true>>(p_swapchain);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISwap_chain1>>
		create_swap_chain_for_hwnd(
			_HW_3D_IN_ IBase* device,
			_HW_3D_IN_ HWND hwnd,
			_HW_3D_IN_ const Swap_chain_desc1& desc,
			_HW_3D_IN_ const Swap_chain_fullscreen_desc* full_screen_desc,
			_HW_3D_IN_ IOutput* restrict_to_output
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISwap_chain1>> res;

		auto&[r, swapchain] = res;

		IDXGISwapChain1* p_swapchain = nullptr;
		r = static_cast<Result>(this->_handle->CreateSwapChainForHwnd(value_ptr(device), hwnd, value_ptr(desc), value_ptr(full_screen_desc), value_ptr(restrict_to_output), &p_swapchain));

		swapchain = _HW_3D_STD_ make_unique<_Swap_chain1<true>>(p_swapchain);

		return res;
	}

	_HW_3D_STD_ tuple<Result, LUID>
		get_shared_resource_adapter_luid(
			_HW_3D_IN_ HANDLE resource
		) override {
		_HW_3D_STD_ tuple<Result, LUID> res;

		auto&[r, uid] = res;
		r = static_cast<Result>(this->_handle->GetSharedResourceAdapterLuid(resource, &uid));

		return  res;
	}

	BOOL
		is_windowed_stereo_enabled(
		) override {
		return this->_handle->IsWindowedStereoEnabled();
	}

	_HW_3D_STD_ tuple<Result, DWORD>
		register_occlusion_status_event(
			_HW_3D_IN_ HANDLE h_event
		) override {
		_HW_3D_STD_ tuple<Result, DWORD> res;

		auto&[r, cookie] = res;
		r = static_cast<Result>(this->_handle->RegisterOcclusionStatusEvent(h_event, &cookie));

		return res;
	}

	_HW_3D_STD_ tuple<Result, DWORD>
		register_occlusion_status_window(
			_HW_3D_IN_ HWND window_handle,
			_HW_3D_IN_ UINT msg
		) override {
		_HW_3D_STD_ tuple<Result, DWORD> res;

		auto&[r, cookie] = res;
		r = static_cast<Result>(this->_handle->RegisterOcclusionStatusWindow(window_handle, msg, &cookie));

		return res;
	}

	_HW_3D_STD_ tuple<Result, DWORD>
		register_stereo_status_event(
			_HW_3D_IN_ HANDLE h_event
		) override {
		_HW_3D_STD_ tuple<Result, DWORD> res;

		auto&[r, cookie] = res;
		r = static_cast<Result>(this->_handle->RegisterStereoStatusEvent(h_event, &cookie));

		return res;
	}

	_HW_3D_STD_ tuple<Result, DWORD>
		register_stereo_status_window(
			_HW_3D_IN_ HWND window_handle,
			_HW_3D_IN_ UINT msg
		) override {
		_HW_3D_STD_ tuple<Result, DWORD> res;

		auto&[r, cookie] = res;
		r = static_cast<Result>(this->_handle->RegisterStereoStatusWindow(window_handle, msg, &cookie));

		return res;
	}

	void
		unregister_occlusion_status(
			_HW_3D_IN_ DWORD cookie
		) override {
		this->_handle->UnregisterOcclusionStatus(cookie);
	}

	void
		unregister_stereo_stauts(
			_HW_3D_IN_ DWORD cookie
		) override {
		this->_handle->UnregisterStereoStatus(cookie);
	}

	virtual ~_TFactory2() {}
};

//
//
template <bool own>
class _Factory2 : public _TFactory2<IFactory2, IDXGIFactory2, own> {
public:
	explicit _Factory2(IDXGIFactory2* handle)
		: _TFactory2<IFactory2, IDXGIFactory2, own>(handle) {

	}

	IDXGIFactory2* get() override {
		return this->_handle;
	}

	const IDXGIFactory2* get() const override {
		return this->_handle;
	}

	~_Factory2() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TFactory3 : public _TFactory2<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IFactory3, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIFactory3, Ty>);
public:
	explicit _TFactory3(Ty* handle)
		: _TFactory2<Interface, Ty, own>(handle) {

	}

	UINT
		get_creation_flags(
		) override {
		return this->_handle->GetCreationFlags();
	}

	virtual ~_TFactory3() {}
};

//
//
template <bool own>
class _Factory3 : public _TFactory3<IFactory3, IDXGIFactory3, own> {
public:
	explicit _Factory3(IDXGIFactory3* handle)
		: _TFactory3<IFactory3, IDXGIFactory3, own>(handle) {

	}

	IDXGIFactory3* get() override {
		return this->_handle;
	}

	const IDXGIFactory3* get() const override {
		return this->_handle;
	}

	~_Factory3() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TFactory4 : public _TFactory3<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IFactory4, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIFactory4, Ty>);
public:
	explicit _TFactory4(Ty* handle)
		: _TFactory3<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter>>
		enum_adapter_by_luid(
			_HW_3D_IN_ LUID adapter_luid,
			_HW_3D_IN_ REFIID riid
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter>> res;

		auto&[r, adap] = res;

		IDXGIAdapter* p_adap = nullptr;
		r = static_cast<Result>(this->_handle->EnumAdapterByLuid(adapter_luid, riid, (void**)&p_adap));

		adap = _HW_3D_STD_ make_unique<_Adapter<true>>(p_adap);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter>>
		enum_warp_adapter(
			_HW_3D_IN_ REFIID riid
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IAdapter>> res;

		auto&[r, adap] = res;

		IDXGIAdapter* p_adap = nullptr;
		r = static_cast<Result>(this->_handle->EnumWarpAdapter(riid, (void**)&p_adap));

		adap = _HW_3D_STD_ make_unique<_Adapter<true>>(p_adap);

		return res;
	}

	virtual ~_TFactory4() {}
};

//
//
template <bool own>
class _Factory4 : public _TFactory4<IFactory4, IDXGIFactory4, own> {
public:
	explicit _Factory4(IDXGIFactory4* handle)
		: _TFactory4<IFactory4, IDXGIFactory4, own>(handle) {

	}

	IDXGIFactory4* get() override {
		return this->_handle;
	}

	const IDXGIFactory4* get() const override {
		return this->_handle;
	}

	~_Factory4() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TFactory5 : public _TFactory4<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IFactory5, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIFactory5, Ty>);
public:
	explicit _TFactory5(Ty* handle)
		: _TFactory4<Interface, Ty, own>(handle) {

	}

	Result
		check_feature_support(
			_HW_3D_IN_ Feature feature,
			_HW_3D_IN_ void* feature_support_data,
			_HW_3D_IN_ UINT feature_support_data_size
		) override {
		return static_cast<Result>(this->_handle->CheckFeatureSupport(DXGI_FEATURE(feature), feature_support_data, feature_support_data_size));
	}

	virtual ~_TFactory5() {}
};

//
//
template <bool own>
class _Factory5 : public _TFactory5<IFactory5, IDXGIFactory5, own> {
public:
	explicit _Factory5(IDXGIFactory5* handle)
		: _TFactory5<IFactory5, IDXGIFactory5, own>(handle) {
	}

	IDXGIFactory5* get() override {
		return this->_handle;
	}

	const IDXGIFactory5* get() const override {
		return this->_handle;
	}

	~_Factory5() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TFactory_media : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IFactory_media, Interface> && _HW_3D_STD_ is_base_of_v<IDXGIFactoryMedia, Ty>);
public:
	explicit _TFactory_media(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDecode_swap_chain>>
		create_decode_swap_chain_for_composition_surface_handle(
			_HW_3D_IN_ IBase* device,
			_HW_3D_IN_ HANDLE surface,
			_HW_3D_IN_ Decode_swap_chain_desc& desc,
			_HW_3D_IN_ IResource* decode_buffers,
			_HW_3D_IN_ IOutput* restrict_to_output
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDecode_swap_chain>> res;

		auto&[r, dsc] = res;

		IDXGIDecodeSwapChain* p_dsc = nullptr;
		r = static_cast<Result>(this->_handle->CreateDecodeSwapChainForCompositionSurfaceHandle(value_ptr(device), surface, value_ptr(desc), value_ptr(decode_buffers), value_ptr(restrict_to_output), &p_dsc));

		dsc = _HW_3D_STD_ make_unique<_Decode_swap_chain<true>>(p_dsc);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISwap_chain1>>
		create_swap_chain_for_composition_surface_handle(
			_HW_3D_IN_ IBase* device,
			_HW_3D_IN_ HANDLE surface,
			_HW_3D_IN_ const Swap_chain_desc1& desc,
			_HW_3D_IN_ IOutput* restrict_to_output
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISwap_chain1>> res;

		auto&[r, swapchain] = res;

		IDXGISwapChain1* p_swapchain = nullptr;
		r = static_cast<Result>(this->_handle->CreateSwapChainForCompositionSurfaceHandle(value_ptr(device), surface, value_ptr(desc), value_ptr(restrict_to_output), &p_swapchain));

		swapchain = _HW_3D_STD_ make_unique<_Swap_chain1<true>>(p_swapchain);

		return res;
	}

	virtual ~_TFactory_media() {}
};

//
//
template <bool own>
class _Factory_media : public _TFactory_media<IFactory_media, IDXGIFactoryMedia, own> {
public:
	explicit _Factory_media(IDXGIFactoryMedia* handle)
		: _TFactory_media<IFactory_media, IDXGIFactoryMedia, own>(handle) {

	}

	IDXGIFactoryMedia* get() override {
		return this->_handle;
	}

	const IDXGIFactoryMedia* get() const override {
		return this->_handle;
	}

	~_Factory_media() final {}
};

_HW_3D_CLOSE_DXGI_NAMESPACE_

_HW_3D_OPEN_D3D_NAMESPACE_

//--forword declaration--
template <bool own> class _Device;
template <bool own> class _Device_context;
template <bool own> class _Class_linkage;


//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice_child : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice_child, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11DeviceChild, Ty>);
public:
	explicit _TDevice_child(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ unique_ptr<IDevice>
		get_device(
		) override {
		ID3D11Device* device;
		this->_handle->GetDevice(&device);
		return _HW_3D_STD_ make_unique<_Device<true>>(device);
	}

	Result
		get_private_data(
			_HW_3D_IN_ REFGUID guid,
			_HW_3D_IN_OUT_ Uint* size,
			_HW_3D_OUT_ void* data
		) override {
		return static_cast<Result>(this->_handle->GetPrivateData(guid, size, data));
	}

	Result
		set_private_data(
			_HW_3D_IN_ REFGUID guid,
			_HW_3D_IN_ Uint size,
			_HW_3D_IN_ const void* data
		) override {
		return static_cast<Result>(this->_handle->SetPrivateData(guid, size, data));
	}

	Result
		set_private_data_interface(
			_HW_3D_IN_ REFGUID guid,
			_HW_3D_IN_ const IBase* data
		) override {
		return static_cast<Result>(this->_handle->SetPrivateDataInterface(guid, value_ptr(data)));
	}

	virtual ~_TDevice_child() {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TAsynchronous : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IAsynchronous, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Asynchronous, Ty>);
public:
	explicit _TAsynchronous(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	Uint
		get_data_size(
		) override {
		return this->_handle->GetDataSize();
	}

	virtual ~_TAsynchronous() {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TBlend_state : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IBlend_state, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11BlendState, Ty>);
public:
	explicit _TBlend_state(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	Blend_desc
		get_desc(
		) override {
		Blend_desc desc;
		this->_handle->GetDesc(value_ptr(desc));
		return desc;
	}

	virtual ~_TBlend_state() {}
};

//
//
template <bool own>
class _Blend_state : public _TBlend_state<IBlend_state, ID3D11BlendState, own> {
public:
	explicit _Blend_state(ID3D11BlendState* handle)
		: _TBlend_state<IBlend_state, ID3D11BlendState, own>(handle) {

	}

	ID3D11BlendState* get() override {
		return this->_handle;
	}

	const ID3D11BlendState* get() const override {
		return this->_handle;
	}

	~_Blend_state() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TBlend_state1 : public _TBlend_state<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IBlend_state1, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11BlendState1, Ty>);
public:
	explicit _TBlend_state1(Ty* handle)
		: _TBlend_state<Interface, Ty, own>(handle) {

	}

	Blend_desc1
		get_desc1(
		) override {
		Blend_desc1 desc;
		this->_handle->GetDesc1(value_ptr(desc));
		return desc;
	}

	virtual ~_TBlend_state1() {}
};

//
//
template <bool own>
class _Blend_state1 : public _TBlend_state1<IBlend_state1, ID3D11BlendState1, own> {
public:
	explicit _Blend_state1(ID3D11BlendState1* handle)
		: _TBlend_state1<IBlend_state1, ID3D11BlendState1, own>(handle) {

	}

	ID3D11BlendState1* get() override {
		return this->_handle;
	}

	const ID3D11BlendState1* get() const override {
		return this->_handle;
	}

	~_Blend_state1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TCommand_list : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ICommand_list, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11CommandList, Ty>);
public:
	explicit _TCommand_list(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	Uint
		get_context_flags(
		) override {
		return this->_handle->GetContextFlags();
	}

	virtual ~_TCommand_list() {}
};

//
//
template <bool own>
class _Command_list : public _TCommand_list<ICommand_list, ID3D11CommandList, own> {
public:
	explicit _Command_list(ID3D11CommandList* handle)
		: _TCommand_list<ICommand_list, ID3D11CommandList, own>(handle) {

	}

	ID3D11CommandList* get() override {
		return this->_handle;
	}

	const ID3D11CommandList* get() const override {
		return this->_handle;
	}

	~_Command_list() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TCounter : public _TAsynchronous<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ICounter, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Counter, Ty>);
public:
	explicit _TCounter(Ty* handle)
		: _TAsynchronous<Interface, Ty, own>(handle) {

	}

	Counter_desc
		get_desc(
		) override {
		Counter_desc desc;
		this->_handle->GetDesc(value_ptr(desc));

		return desc;
	}

	virtual ~_TCounter() {}
};

//
//
template <bool own>
class _Counter : public _TCounter<ICounter, ID3D11Counter, own> {
public:
	explicit _Counter(ID3D11Counter* handle)
		: _TCounter<ICounter, ID3D11Counter, own>(handle) {

	}

	ID3D11Counter* get() override {
		return this->_handle;
	}

	const ID3D11Counter* get() const override {
		return this->_handle;
	}

	~_Counter() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDepth_stencil_state : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDepth_stencil_state, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11DepthStencilState, Ty>);
public:
	explicit _TDepth_stencil_state(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	Depth_stencil_desc
		get_desc(
		) override {
		Depth_stencil_desc desc;
		this->_handle->GetDesc(value_ptr(desc));

		return desc;
	}

	virtual ~_TDepth_stencil_state() {}
};

//
//
template <bool own>
class _Depth_stencil_state : public _TDepth_stencil_state<IDepth_stencil_state, ID3D11DepthStencilState, own> {
public:
	explicit _Depth_stencil_state(ID3D11DepthStencilState* handle)
		: _TDepth_stencil_state<IDepth_stencil_state, ID3D11DepthStencilState, own>(handle) {

	}

	ID3D11DepthStencilState* get() override {
		return this->_handle;
	}

	const ID3D11DepthStencilState* get() const override {
		return this->_handle;
	}

	~_Depth_stencil_state() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice_context_state : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice_context_state, Interface> && _HW_3D_STD_ is_base_of_v<ID3DDeviceContextState, Ty>);
public:
	explicit _TDevice_context_state(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	virtual ~_TDevice_context_state() {}
};

//
//
template <bool own>
class _Device_context_state : public _TDevice_context_state<IDevice_context_state, ID3DDeviceContextState, own> {
public:
	explicit _Device_context_state(ID3DDeviceContextState* handle)
		: _TDevice_context_state<IDevice_context_state, ID3DDeviceContextState, own>(handle) {

	}

	ID3DDeviceContextState* get() override {
		return this->_handle;
	}

	const ID3DDeviceContextState* get() const override {
		return this->_handle;
	}

	~_Device_context_state() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TFence : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IFence, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Fence, Ty>);
public:
	explicit _TFence(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, HANDLE>
		create_shared_handle(
			_HW_3D_IN_ const SECURITY_ATTRIBUTES* attributes,
			_HW_3D_IN_ DWORD access,
			_HW_3D_IN_ const _HW_3D_STD_ wstring& name
		) override {
		_HW_3D_STD_ tuple<Result, HANDLE> res;

		auto&[r, h] = res;
		r = static_cast<Result>(this->_handle->CreateSharedHandle(attributes, access, name.c_str(), &h));

		return res;
	}

	Uint64
		get_complete_value(
		) override {
		return this->_handle->GetCompletedValue();
	}

	Result
		set_event_on_completion(
			_HW_3D_IN_ Uint64 value,
			_HW_3D_IN_ HANDLE h_event
		) override {
		return static_cast<Result>(this->_handle->SetEventOnCompletion(value, h_event));
	}

	virtual ~_TFence() {}
};

//
//
template <bool own>
class _Fence : public _TFence<IFence, ID3D11Fence, own> {
public:
	explicit _Fence(ID3D11Fence* handle)
		: _TFence<IFence, ID3D11Fence, own>(handle) {

	}

	ID3D11Fence* get() override {
		return this->_handle;
	}

	const ID3D11Fence* get() const override {
		return this->_handle;
	}

	~_Fence() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TInput_layout : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IInput_layout, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11InputLayout, Ty>);
public:
	explicit _TInput_layout(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	virtual ~_TInput_layout() {}
};

//
//
template <bool own>
class _Input_layout : public _TInput_layout<IInput_layout, ID3D11InputLayout, own> {
public:
	explicit _Input_layout(ID3D11InputLayout* handle)
		: _TInput_layout<IInput_layout, ID3D11InputLayout, own>(handle) {

	}

	ID3D11InputLayout* get() override {
		return this->_handle;
	}

	const ID3D11InputLayout* get() const override {
		return this->_handle;
	}

	~_Input_layout() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TMultithread : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IMultithread, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Multithread, Ty>);
public:
	explicit _TMultithread(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	void
		enter(
		) override {
		this->_handle->Enter();
	}

	Bool
		get_multithread_protected(
		) override {
		return this->_handle->GetMultithreadProtected();
	}

	void
		leave(
		) override {
		this->_handle->Leave();
	}

	Bool
		set_multithrewad_protected(
			_HW_3D_IN_ Bool protect
		) override {
		return this->_handle->SetMultithreadProtected(protect);
	}

	virtual ~_TMultithread() {}
};

//
//
template <bool own>
class _Multithread : public _TMultithread<IMultithread, ID3D11Multithread, own> {
public:
	explicit _Multithread(ID3D11Multithread* handle)
		: _TMultithread<IMultithread, ID3D11Multithread, own>(handle) {

	}

	ID3D11Multithread* get() override {
		return this->_handle;
	}

	const ID3D11Multithread* get() const override {
		return this->_handle;
	}

	~_Multithread() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TQuery : public _TAsynchronous<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IQuery, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Query, Ty>);
public:
	explicit _TQuery(Ty* handle)
		: _TAsynchronous<Interface, Ty, own>(handle) {

	}

	Query_desc
		get_desc(
		) override {
		Query_desc desc;
		this->_handle->GetDesc(value_ptr(desc));

		return desc;
	}

	virtual ~_TQuery() {}
};

//
//
template <bool own>
class _Query : public _TQuery<IQuery, ID3D11Query, own> {
public:
	explicit _Query(ID3D11Query* handle)
		: _TQuery<IQuery, ID3D11Query, own>(handle) {

	}

	ID3D11Query* get() override {
		return this->_handle;
	}

	const ID3D11Query* get() const override {
		return this->_handle;
	}

	~_Query() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TQuery1 : public _TQuery<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IQuery1, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Query1, Ty>);
public:
	explicit _TQuery1(Ty* handle)
		: _TQuery<Interface, Ty, own>(handle) {

	}

	Query_desc1
		get_desc1(
		) override {
		Query_desc1 desc;
		this->_handle->GetDesc1(value_ptr(desc));

		return desc;
	}

	virtual ~_TQuery1() {}
};

//
//
template <bool own>
class _Query1 : public _TQuery1<IQuery1, ID3D11Query1, own> {
public:
	explicit _Query1(ID3D11Query1* handle)
		: _TQuery1<IQuery1, ID3D11Query1, own>(handle) {

	}

	ID3D11Query1* get() override {
		return this->_handle;
	}

	const ID3D11Query1* get() const override {
		return this->_handle;
	}

	~_Query1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TPredicate : public _TQuery<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IPredicate, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Predicate, Ty>);
public:
	explicit _TPredicate(Ty* handle)
		: _TQuery<Interface, Ty, own>(handle) {

	}

	virtual ~_TPredicate() {}
};

//
//
template <bool own>
class _Predicate : public _TPredicate<IPredicate, ID3D11Predicate, own> {
public:
	explicit _Predicate(ID3D11Predicate* handle)
		: _TPredicate<IPredicate, ID3D11Predicate, own>(handle) {

	}

	ID3D11Predicate* get() override {
		return this->_handle;
	}

	const ID3D11Predicate* get() const override {
		return this->_handle;
	}

	~_Predicate() final {}
};

//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TRasterizer_state : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IRasterizer_state, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11RasterizerState, Ty>);
public:
	explicit _TRasterizer_state(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	Rasterizer_desc
		get_desc(
		) override {
		Rasterizer_desc desc;
		this->_handle->GetDesc(value_ptr(desc));

		return desc;
	}

	virtual ~_TRasterizer_state() {}
};

//
//
template <bool own>
class _Rasterizer_state : public _TRasterizer_state<IRasterizer_state, ID3D11RasterizerState, own> {
public:
	explicit _Rasterizer_state(ID3D11RasterizerState* handle)
		: _TRasterizer_state<IRasterizer_state, ID3D11RasterizerState, own>(handle) {

	}

	ID3D11RasterizerState* get() override {
		return this->_handle;
	}

	const ID3D11RasterizerState* get() const override {
		return this->_handle;
	}

	~_Rasterizer_state() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TRasterizer_state1 : public _TRasterizer_state<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IRasterizer_state1, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11RasterizerState1, Ty>);
public:
	explicit _TRasterizer_state1(Ty* handle)
		: _TRasterizer_state<Interface, Ty, own>(handle) {

	}

	Rasterizer_desc1
		get_desc1(
		) override {
		Rasterizer_desc1 desc;
		this->_handle->GetDesc1(value_ptr(desc));
		return desc;
	}

	virtual ~_TRasterizer_state1() {}
};

//
//
template <bool own>
class _Rasterizer_state1 : public _TRasterizer_state1<IRasterizer_state1, ID3D11RasterizerState1, own> {
public:
	explicit _Rasterizer_state1(ID3D11RasterizerState1* handle)
		: _TRasterizer_state1<IRasterizer_state1, ID3D11RasterizerState1, own>(handle) {

	}

	ID3D11RasterizerState1* get() override {
		return this->_handle;
	}

	const ID3D11RasterizerState1* get() const override {
		return this->_handle;
	}

	~_Rasterizer_state1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TRasterizer_state2 : public _TRasterizer_state1<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IRasterizer_state2, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11RasterizerState2, Ty>);
public:
	explicit _TRasterizer_state2(Ty* handle)
		: _TRasterizer_state1<Interface, Ty, own>(handle) {

	}

	Rasterizer_desc2
		get_desc2(
		) override {
		Rasterizer_desc2 desc;
		this->_handle->GetDesc2(value_ptr(desc));

		return desc;
	}

	virtual ~_TRasterizer_state2() {}
};

//
//
template <bool own>
class _Rasterizer_state2 : public _TRasterizer_state2<IRasterizer_state2, ID3D11RasterizerState2, own> {
public:
	explicit _Rasterizer_state2(ID3D11RasterizerState2* handle)
		: _TRasterizer_state2<IRasterizer_state2, ID3D11RasterizerState2, own>(handle) {

	}

	ID3D11RasterizerState2* get() override {
		return this->_handle;
	}

	const ID3D11RasterizerState2* get() const override {
		return this->_handle;
	}

	~_Rasterizer_state2() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TSampler_state : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ISampler_state, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11SamplerState, Ty>);
public:
	explicit _TSampler_state(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	Sampler_desc
		get_desc(
		) override {
		Sampler_desc desc;
		this->_handle->GetDesc(value_ptr(desc));

		return desc;
	}

	virtual ~_TSampler_state() {}
};

//
//
template <bool own>
class _Sampler_state : public _TSampler_state<ISampler_state, ID3D11SamplerState, own> {
public:
	explicit _Sampler_state(ID3D11SamplerState* handle)
		: _TSampler_state<ISampler_state, ID3D11SamplerState, own>(handle) {

	}

	ID3D11SamplerState* get() override {
		return this->_handle;
	}

	const ID3D11SamplerState* get() const override {
		return this->_handle;
	}

	~_Sampler_state() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TResource : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IResource, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Resource, Ty>);
public:
	explicit _TResource(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	_HW_3D_DXGI_ Resource_priority
		get_eviction_priority(
		) override {
		return static_cast<_HW_3D_DXGI_ Resource_priority>(this->_handle->GetEvictionPriority());
	}

	Resource_dimension
		get_type(
		) override {
		Resource_dimension dim;
		this->_handle->GetType((D3D11_RESOURCE_DIMENSION *)(&dim));

		return dim;
	}

	void
		set_eviction_priority(
			_HW_3D_IN_ _HW_3D_DXGI_ Resource_priority priority
		) override {
		this->_handle->SetEvictionPriority(Uint(priority));
	}

	virtual ~_TResource() {}
};

//
//
template <bool own>
class _Resource : public _TResource<IResource, ID3D11Resource, own> {
public:
	explicit _Resource(ID3D11Resource* handle)
		: _TResource<IResource, ID3D11Resource, own>(handle) {

	}

	ID3D11Resource* get() override {
		return this->_handle;
	}

	const ID3D11Resource* get() const override {
		return this->_handle;
	}

	~_Resource() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TBuffer : public _TResource<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IBuffer, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Buffer, Ty>);
public:
	explicit _TBuffer(Ty* handle)
		: _TResource<Interface, Ty, own>(handle) {

	}

	Buffer_desc
		get_desc(
		) override {
		Buffer_desc desc;
		this->_handle->GetDesc(value_ptr(desc));

		return desc;
	}

	virtual ~_TBuffer() {}
};

//
//
template <bool own>
class _Buffer : public _TBuffer<IBuffer, ID3D11Buffer, own> {
public:
	explicit _Buffer(ID3D11Buffer* handle)
		: _TBuffer<IBuffer, ID3D11Buffer, own>(handle) {

	}

	ID3D11Buffer* get() override {
		return this->_handle;
	}

	const ID3D11Buffer* get() const override {
		return this->_handle;
	}

	~_Buffer() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TTexture1d : public _TResource<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ITexture1d, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Texture1D, Ty>);
public:
	explicit _TTexture1d(Ty* handle)
		: _TResource<Interface, Ty, own>(handle) {

	}

	Texture1d_desc
		get_desc(
		) override {
		Texture1d_desc desc;
		this->_handle->GetDesc(value_ptr(desc));

		return desc;
	}

	virtual ~_TTexture1d() {}
};

//
//
template <bool own>
class _Texture1d : public _TTexture1d<ITexture1d, ID3D11Texture1D, own> {
public:
	explicit _Texture1d(ID3D11Texture1D* handle)
		: _TTexture1d<ITexture1d, ID3D11Texture1D, own>(handle) {

	}

	ID3D11Texture1D* get() override {
		return this->_handle;
	}

	const ID3D11Texture1D* get() const override {
		return this->_handle;
	}

	~_Texture1d() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TTexture2d : public _TResource<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ITexture2d, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Texture2D, Ty>);
public:
	explicit _TTexture2d(Ty* handle)
		: _TResource<Interface, Ty, own>(handle) {

	}

	Texture2d_desc
		get_desc(
		) override {
		Texture2d_desc desc;
		this->_handle->GetDesc(value_ptr(desc));

		return desc;
	}

	virtual ~_TTexture2d() {}
};

//
//
template <bool own>
class _Texture2d : public _TTexture2d<ITexture2d, ID3D11Texture2D, own> {
public:
	explicit _Texture2d(ID3D11Texture2D* handle)
		: _TTexture2d<ITexture2d, ID3D11Texture2D, own>(handle) {

	}

	ID3D11Texture2D* get() override {
		return this->_handle;
	}

	const ID3D11Texture2D* get() const override {
		return this->_handle;
	}

	~_Texture2d() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TTexture2d1 : public _TTexture2d<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ITexture2d1, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Texture2D1, Ty>);
public:
	explicit _TTexture2d1(Ty* handle)
		: _TTexture2d<Interface, Ty, own>(handle) {

	}

	Texture2d_desc1
		get_desc1(
		) override {
		Texture2d_desc1 desc;
		this->_handle->GetDesc1(value_ptr(desc));

		return desc;
	}

	virtual ~_TTexture2d1() {}
};

//
//
template <bool own>
class _Texture2d1 : public _TTexture2d1<ITexture2d1, ID3D11Texture2D1, own> {
public:
	explicit _Texture2d1(ID3D11Texture2D1* handle)
		: _TTexture2d1<ITexture2d1, ID3D11Texture2D1, own>(handle) {

	}

	ID3D11Texture2D1* get() override {
		return this->_handle;
	}

	const ID3D11Texture2D1* get() const override {
		return this->_handle;
	}

	~_Texture2d1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TTexture3d : public _TResource<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ITexture3d, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Texture3D, Ty>);
public:
	explicit _TTexture3d(Ty* handle)
		: _TResource<Interface, Ty, own>(handle) {

	}

	Texture3d_desc
		get_desc(
		) override {
		Texture3d_desc desc;
		this->_handle->GetDesc(value_ptr(desc));

		return desc;
	}

	virtual ~_TTexture3d() {}
};

//
//
template <bool own>
class _Texture3d : public _TTexture3d<ITexture3d, ID3D11Texture3D, own> {
public:
	explicit _Texture3d(ID3D11Texture3D* handle)
		: _TTexture3d<ITexture3d, ID3D11Texture3D, own>(handle) {

	}

	ID3D11Texture3D* get() override {
		return this->_handle;
	}

	const ID3D11Texture3D* get() const override {
		return this->_handle;
	}

	~_Texture3d() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TTexture3d1 : public _TTexture3d<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ITexture3d1, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Texture3D1, Ty>);
public:
	explicit _TTexture3d1(Ty* handle)
		: _TTexture3d<Interface, Ty, own>(handle) {

	}

	Texture3d_desc1
		get_desc1(
		) override {
		Texture3d_desc1 desc;
		this->_handle->GetDesc1(value_ptr(desc));

		return desc;
	}

	virtual ~_TTexture3d1() {}
};

//
//
template <bool own>
class _Texture3d1 : public _TTexture3d1<ITexture3d1, ID3D11Texture3D1, own> {
public:
	explicit _Texture3d1(ID3D11Texture3D1* handle)
		: _TTexture3d1<ITexture3d1, ID3D11Texture3D1, own>(handle) {

	}

	ID3D11Texture3D1* get() override {
		return this->_handle;
	}

	const ID3D11Texture3D1* get() const override {
		return this->_handle;
	}

	~_Texture3d1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TView : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IView, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11View, Ty>);
public:
	explicit _TView(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ unique_ptr<IResource>
		get_resource(
		) override {
		ID3D11Resource* p_resource;
		this->_handle->GetResource(&p_resource);

		return _HW_3D_STD_ make_unique<_Resource<true>>(p_resource);
	}

	virtual ~_TView() {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDepth_stencil_view : public _TView<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDepth_stencil_view, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11DepthStencilView, Ty>);
public:
	explicit _TDepth_stencil_view(Ty* handle)
		: _TView<Interface, Ty, own>(handle) {

	}

	Depth_stencil_view_desc
		get_desc(
		) override {
		Depth_stencil_view_desc desc;
		this->_handle->GetDesc(value_ptr(desc));

		return desc;
	}

	virtual ~_TDepth_stencil_view() {}
};

//
//
template <bool own>
class _Depth_stencil_view : public _TDepth_stencil_view<IDepth_stencil_view, ID3D11DepthStencilView, own> {
public:
	explicit _Depth_stencil_view(ID3D11DepthStencilView* handle)
		: _TDepth_stencil_view<IDepth_stencil_view, ID3D11DepthStencilView, own>(handle) {

	}

	ID3D11DepthStencilView* get() override {
		return this->_handle;
	}

	const ID3D11DepthStencilView* get() const override {
		return this->_handle;
	}

	~_Depth_stencil_view() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TRender_target_view : public _TView<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IRender_target_view, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11RenderTargetView, Ty>);
public:
	explicit _TRender_target_view(Ty* handle)
		: _TView<Interface, Ty, own>(handle) {

	}

	Render_target_view_desc
		get_desc(
		) override {
		Render_target_view_desc desc;
		this->_handle->GetDesc(value_ptr(desc));

		return desc;
	}

	virtual ~_TRender_target_view() {}
};

//
//
template <bool own>
class _Render_target_view : public _TRender_target_view<IRender_target_view, ID3D11RenderTargetView, own> {
public:
	explicit _Render_target_view(ID3D11RenderTargetView* handle)
		: _TRender_target_view<IRender_target_view, ID3D11RenderTargetView, own>(handle) {

	}

	ID3D11RenderTargetView* get() override {
		return this->_handle;
	}

	const ID3D11RenderTargetView* get() const override {
		return this->_handle;
	}

	~_Render_target_view() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TRender_target_view1 : public _TRender_target_view<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IRender_target_view1, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11RenderTargetView1, Ty>);
public:
	explicit _TRender_target_view1(Ty* handle)
		: _TRender_target_view<Interface, Ty, own>(handle) {
	}

	Render_target_view_desc1
		get_desc1(
		) override {
		Render_target_view_desc1 desc;
		this->_handle->GetDesc1(value_ptr(desc));

		return desc;
	}

	virtual ~_TRender_target_view1() {}
};

//
//
template <bool own>
class _Render_target_view1 : public _TRender_target_view1<IRender_target_view1, ID3D11RenderTargetView1, own> {
public:
	explicit _Render_target_view1(ID3D11RenderTargetView1* handle)
		: _TRender_target_view1<IRender_target_view1, ID3D11RenderTargetView1, own>(handle) {

	}

	ID3D11RenderTargetView1* get() override {
		return this->_handle;
	}

	const ID3D11RenderTargetView1* get() const override {
		return this->_handle;
	}

	~_Render_target_view1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TShader_resource_view : public _TView<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IShader_resource_view, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11ShaderResourceView, Ty>);
public:
	explicit _TShader_resource_view(Ty* handle)
		: _TView<Interface, Ty, own>(handle) {

	}

	Shader_resource_view_desc
		get_desc(
		) override {
		Shader_resource_view_desc desc;
		this->_handle->GetDesc(value_ptr(desc));

		return desc;
	}

	virtual ~_TShader_resource_view() {}
};

//
//
template <bool own>
class _Shader_resource_view : public _TShader_resource_view<IShader_resource_view, ID3D11ShaderResourceView, own> {
public:
	explicit _Shader_resource_view(ID3D11ShaderResourceView* handle)
		: _TShader_resource_view<IShader_resource_view, ID3D11ShaderResourceView, own>(handle) {

	}

	ID3D11ShaderResourceView* get() override {
		return this->_handle;
	}

	const ID3D11ShaderResourceView* get() const override {
		return this->_handle;
	}

	~_Shader_resource_view() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TShader_resource_view1 : public _TShader_resource_view<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IShader_resource_view1, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11ShaderResourceView1, Ty>);
public:
	explicit _TShader_resource_view1(Ty* handle)
		: _TShader_resource_view<Interface, Ty, own>(handle) {
	}

	Shader_resource_view_desc1
		get_desc1(
		) override {
		Shader_resource_view_desc1 desc;
		this->_handle->GetDesc1(value_ptr(desc));

		return desc;
	}

	virtual ~_TShader_resource_view1() {}
};

//
//
template <bool own>
class _Shader_resource_view1 : public _TShader_resource_view1<IShader_resource_view1, ID3D11ShaderResourceView1, own> {
public:
	explicit _Shader_resource_view1(ID3D11ShaderResourceView1* handle)
		: _TShader_resource_view1<IShader_resource_view1, ID3D11ShaderResourceView1, own>(handle) {

	}

	ID3D11ShaderResourceView1* get() override {
		return this->_handle;
	}

	const ID3D11ShaderResourceView1* get() const override {
		return this->_handle;
	}

	~_Shader_resource_view1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TUnordered_access_view : public _TView<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IUnordered_access_view, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11UnorderedAccessView, Ty>);
public:
	explicit _TUnordered_access_view(Ty* handle)
		: _TView<Interface, Ty, own>(handle) {

	}

	Unordered_access_view_desc
		get_desc(
		) override {
		Unordered_access_view_desc desc;
		this->_handle->GetDesc(value_ptr(desc));

		return desc;
	}

	virtual ~_TUnordered_access_view() {}
};

//
//
template <bool own>
class _Unordered_access_view : public _TUnordered_access_view<IUnordered_access_view, ID3D11UnorderedAccessView, own> {
public:
	explicit _Unordered_access_view(ID3D11UnorderedAccessView* handle)
		: _TUnordered_access_view<IUnordered_access_view, ID3D11UnorderedAccessView, own>(handle) {

	}

	ID3D11UnorderedAccessView* get() override {
		return this->_handle;
	}

	const ID3D11UnorderedAccessView* get() const override {
		return this->_handle;
	}

	~_Unordered_access_view() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TUnordered_access_view1 : public _TUnordered_access_view<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IUnordered_access_view1, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11UnorderedAccessView1, Ty>);
public:
	explicit _TUnordered_access_view1(Ty* handle)
		: _TUnordered_access_view<Interface, Ty, own>(handle) {
	}

	Unordered_access_view_desc1
		get_desc1(
		) override {
		Unordered_access_view_desc1 desc;
		this->_handle->GetDesc1(value_ptr(desc));

		return desc;
	}

	virtual ~_TUnordered_access_view1() {}
};

//
//
template <bool own>
class _Unordered_access_view1 : public _TUnordered_access_view1<IUnordered_access_view1, ID3D11UnorderedAccessView1, own> {
public:
	explicit _Unordered_access_view1(ID3D11UnorderedAccessView1* handle)
		: _TUnordered_access_view1<IUnordered_access_view1, ID3D11UnorderedAccessView1, own>(handle) {

	}

	ID3D11UnorderedAccessView1* get() override {
		return this->_handle;
	}

	const ID3D11UnorderedAccessView1* get() const override {
		return this->_handle;
	}

	~_Unordered_access_view1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TClass_instance : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IClass_instance, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11ClassInstance, Ty>);
public:
	explicit  _TClass_instance(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ unique_ptr<IClass_linkage>
		get_class_linkage(
		) override {
		ID3D11ClassLinkage* cl = nullptr;
		this->_handle->GetClassLinkage(&cl);

		return _HW_3D_STD_ make_unique<_Class_linkage<true>>(cl);
	}

	Class_instance_desc
		get_desc(
		) override {
		Class_instance_desc desc;
		this->_handle->GetDesc(value_ptr(desc));

		return desc;
	}

	_HW_3D_STD_ string
		get_instance_name(
		) override {
		_HW_3D_STD_ string name;

		Size_t length = 0;
		this->_handle->GetInstanceName(nullptr, &length);

		name.resize(length);
		this->_handle->GetInstanceName(name.data(), &length);

		return name;
	}

	_HW_3D_STD_ string
		get_type_name(
		) override {
		_HW_3D_STD_ string name;

		Size_t length = 0;
		this->_handle->GetTypeName(nullptr, &length);

		name.resize(length);
		this->_handle->GetTypeName(name.data(), &length);

		return name;
	}

	virtual ~_TClass_instance() {}
};

//
//
template <bool own>
class _Class_instance : public _TClass_instance<IClass_instance, ID3D11ClassInstance, own> {
public:
	explicit _Class_instance(ID3D11ClassInstance* handle)
		: _TClass_instance<IClass_instance, ID3D11ClassInstance, own>(handle) {

	}

	ID3D11ClassInstance* get() override {
		return this->_handle;
	}

	const ID3D11ClassInstance* get() const override {
		return this->_handle;
	}

	~_Class_instance() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TClass_linkage : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IClass_linkage, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11ClassLinkage, Ty>);
public:
	explicit _TClass_linkage(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IClass_instance>>
		create_class_instance(
			_HW_3D_IN_ const _HW_3D_STD_ string& type_name,
			_HW_3D_IN_ Uint constant_buffer_offset,
			_HW_3D_IN_ Uint constant_vector_offset,
			_HW_3D_IN_ Uint texture_offset,
			_HW_3D_IN_ Uint sampler_offset
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IClass_instance>> res;

		auto&[r, ci] = res;

		ID3D11ClassInstance* p_ci = nullptr;
		r = static_cast<Result>(this->_handle->CreateClassInstance(type_name.c_str(), constant_buffer_offset, constant_vector_offset, texture_offset, sampler_offset, &p_ci));

		ci = _HW_3D_STD_ make_unique<_Class_instance<true>>(p_ci);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IClass_instance>>
		get_class_instance(
			_HW_3D_IN_ const _HW_3D_STD_ string& name,
			_HW_3D_IN_ Uint index
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IClass_instance>> res;

		auto&[r, ci] = res;

		ID3D11ClassInstance* p_ci = nullptr;
		r = static_cast<Result>(this->_handle->GetClassInstance(name.c_str(), index, &p_ci));

		ci = _HW_3D_STD_ make_unique<_Class_instance<true>>(p_ci);

		return res;
	}

	virtual ~_TClass_linkage() {}
};

//
//
template <bool own>
class _Class_linkage : public _TClass_linkage<IClass_linkage, ID3D11ClassLinkage, own> {
public:
	explicit _Class_linkage(ID3D11ClassLinkage* handle)
		: _TClass_linkage<IClass_linkage, ID3D11ClassLinkage, own>(handle) {

	}

	ID3D11ClassLinkage* get() override {
		return this->_handle;
	}

	const ID3D11ClassLinkage* get() const override {
		return this->_handle;
	}

	~_Class_linkage() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TCompute_shader : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ICompute_shader, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11ComputeShader, Ty>);
public:
	explicit _TCompute_shader(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	virtual ~_TCompute_shader() {}
};

//
//
template <bool own>
class _Compute_shader : public _TCompute_shader<ICompute_shader, ID3D11ComputeShader, own> {
public:
	explicit _Compute_shader(ID3D11ComputeShader* handle)
		: _TCompute_shader<ICompute_shader, ID3D11ComputeShader, own>(handle) {

	}

	ID3D11ComputeShader* get() override {
		return this->_handle;
	}

	const ID3D11ComputeShader* get() const override {
		return this->_handle;
	}

	~_Compute_shader() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDomain_shader : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDomain_shader, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11DomainShader, Ty>);
public:
	explicit _TDomain_shader(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	virtual ~_TDomain_shader() {}
};

//
//
template <bool own>
class _Domain_shader : public _TDomain_shader<IDomain_shader, ID3D11DomainShader, own> {
public:
	explicit _Domain_shader(ID3D11DomainShader* handle)
		: _TDomain_shader<IDomain_shader, ID3D11DomainShader, own>(handle) {

	}

	ID3D11DomainShader* get() override {
		return this->_handle;
	}

	const ID3D11DomainShader* get() const override {
		return this->_handle;
	}

	~_Domain_shader() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TGeometry_shader : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IGeometry_shader, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11GeometryShader, Ty>);
public:
	explicit _TGeometry_shader(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	virtual ~_TGeometry_shader() {}
};

//
//
template <bool own>
class _Geometry_shader : public _TGeometry_shader<IGeometry_shader, ID3D11GeometryShader, own> {
public:
	explicit _Geometry_shader(ID3D11GeometryShader* handle)
		: _TGeometry_shader<IGeometry_shader, ID3D11GeometryShader, own>(handle) {

	}

	ID3D11GeometryShader* get() override {
		return this->_handle;
	}

	const ID3D11GeometryShader* get() const override {
		return this->_handle;
	}

	~_Geometry_shader() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _THull_shader : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IHull_shader, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11HullShader, Ty>);
public:
	explicit _THull_shader(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	virtual ~_THull_shader() {}
};

//
//
template <bool own>
class _Hull_shader : public _THull_shader<IHull_shader, ID3D11HullShader, own> {
public:
	explicit _Hull_shader(ID3D11HullShader* handle)
		: _THull_shader<IHull_shader, ID3D11HullShader, own>(handle) {

	}

	ID3D11HullShader* get() override {
		return this->_handle;
	}

	const ID3D11HullShader* get() const override {
		return this->_handle;
	}

	~_Hull_shader() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TPixel_shader : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IPixel_shader, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11PixelShader, Ty>);
public:
	explicit _TPixel_shader(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	virtual ~_TPixel_shader() {}
};

//
//
template <bool own>
class _Pixel_shader : public _TPixel_shader<IPixel_shader, ID3D11PixelShader, own> {
public:
	explicit _Pixel_shader(ID3D11PixelShader* handle)
		: _TPixel_shader<IPixel_shader, ID3D11PixelShader, own>(handle) {

	}

	ID3D11PixelShader* get() override {
		return this->_handle;
	}

	const ID3D11PixelShader* get() const override {
		return this->_handle;
	}

	~_Pixel_shader() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TVertex_shader : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IVertex_shader, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11VertexShader, Ty>);
public:
	explicit _TVertex_shader(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	virtual ~_TVertex_shader() {}
};

//
//
template <bool own>
class _Vertex_shader : public _TVertex_shader<IVertex_shader, ID3D11VertexShader, own> {
public:
	explicit _Vertex_shader(ID3D11VertexShader* handle)
		: _TVertex_shader<IVertex_shader, ID3D11VertexShader, own>(handle) {

	}

	ID3D11VertexShader* get() override {
		return this->_handle;
	}

	const ID3D11VertexShader* get() const override {
		return this->_handle;
	}

	~_Vertex_shader() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TLinking_node : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ILinking_node, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11LinkingNode, Ty>);
public:
	explicit _TLinking_node(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	virtual ~_TLinking_node() {}
};

//
//
template <bool own>
class _Linking_node : public _TLinking_node<ILinking_node, ID3D11LinkingNode, own> {
public:
	explicit _Linking_node(ID3D11LinkingNode* handle)
		: _TLinking_node<ILinking_node, ID3D11LinkingNode, own>(handle) {

	}

	ID3D11LinkingNode* get() override {
		return this->_handle;
	}

	const ID3D11LinkingNode* get() const override {
		return this->_handle;
	}

	~_Linking_node() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TModule_instance : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IModule_instance, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11ModuleInstance, Ty>);
public:
	explicit _TModule_instance(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	Result
		bind_constant_buffer(
			_HW_3D_IN_ Uint src_slot,
			_HW_3D_IN_ Uint dst_slot,
			_HW_3D_IN_ Uint dst_offset
		) override {
		return static_cast<Result>(this->_handle->BindConstantBuffer(src_slot, dst_slot, dst_offset));
	}

	Result
		bind_constant_buffer_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name,
			_HW_3D_IN_ Uint dst_slot,
			_HW_3D_IN_ Uint dst_offset
		) override {
		return static_cast<Result>(this->_handle->BindConstantBufferByName(name.c_str(), dst_slot, dst_offset));
	}

	Result
		bind_resource(
			_HW_3D_IN_ Uint src_slot,
			_HW_3D_IN_ Uint dst_slot,
			_HW_3D_IN_ Uint count
		) override {
		return static_cast<Result>(this->_handle->BindResource(src_slot, dst_slot, count));
	}

	Result
		bind_resource_as_unordered_access_view(
			_HW_3D_IN_ Uint src_srv_slot,
			_HW_3D_IN_ Uint dst_uav_slot,
			_HW_3D_IN_ Uint count
		) override {
		return static_cast<Result>(this->_handle->BindResourceAsUnorderedAccessView(src_srv_slot, dst_uav_slot, count));
	}

	Result
		bind_resource_as_unordered_access_view_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name,
			_HW_3D_IN_ Uint dst_uav_slot,
			_HW_3D_IN_ Uint count
		) override {
		return static_cast<Result>(this->_handle->BindResourceAsUnorderedAccessViewByName(name.c_str(), dst_uav_slot, count));
	}

	Result
		bind_resource_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name,
			_HW_3D_IN_ Uint dst_slot,
			_HW_3D_IN_ Uint count
		) override {
		return static_cast<Result>(this->_handle->BindResourceByName(name.c_str(), dst_slot, count));
	}

	Result
		bind_sampler(
			_HW_3D_IN_ Uint src_slot,
			_HW_3D_IN_ Uint dst_slot,
			_HW_3D_IN_ Uint count
		) override {
		return static_cast<Result>(this->_handle->BindSampler(src_slot, dst_slot, count));
	}

	Result
		bind_sampler_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name,
			_HW_3D_IN_ Uint dst_slot,
			_HW_3D_IN_ Uint count
		) override {
		return static_cast<Result>(this->_handle->BindSamplerByName(name.c_str(), dst_slot, count));
	}

	Result
		bind_unordered_access_view(
			_HW_3D_IN_ Uint src_slot,
			_HW_3D_IN_ Uint dst_slot,
			_HW_3D_IN_ Uint count
		) override {
		return static_cast<Result>(this->_handle->BindUnorderedAccessView(src_slot, dst_slot, count));
	}

	Result
		bind_unordered_access_view_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name,
			_HW_3D_IN_ Uint dst_slot,
			_HW_3D_IN_ Uint count
		) override {
		return static_cast<Result>(this->_handle->BindUnorderedAccessViewByName(name.c_str(), dst_slot, count));
	}

	virtual ~_TModule_instance() {}
};

//
//
template <bool own>
class _Module_instance : public _TModule_instance<IModule_instance, ID3D11ModuleInstance, own> {
public:
	explicit _Module_instance(ID3D11ModuleInstance* handle)
		: _TModule_instance<IModule_instance, ID3D11ModuleInstance, own>(handle) {

	}

	ID3D11ModuleInstance* get() override {
		return this->_handle;
	}

	const ID3D11ModuleInstance* get() const override {
		return this->_handle;
	}

	~_Module_instance() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TModule : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IModule, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Module, Ty>);
public:
	explicit _TModule(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IModule_instance>>
		create_instance(
			_HW_3D_IN_ const _HW_3D_STD_ string& name
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IModule_instance>> res;

		auto&[r, mod] = res;

		ID3D11ModuleInstance* p_mod = nullptr;
		r = static_cast<Result>(this->_handle->CreateInstance(name.c_str(), &p_mod));

		mod = _HW_3D_STD_ make_unique<_Module_instance<true>>(p_mod);

		return res;
	}

	virtual ~_TModule() {}
};

//
//
template <bool own>
class _Module : public _TModule<IModule, ID3D11Module, own> {
public:
	explicit _Module(ID3D11Module* handle)
		: _TModule<IModule, ID3D11Module, own>(handle) {

	}

	ID3D11Module* get() override {
		return this->_handle;
	}

	const ID3D11Module* get() const override {
		return this->_handle;
	}

	~_Module() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TBlob : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IBlob, Interface> && _HW_3D_STD_ is_base_of_v<ID3DBlob, Ty>);
public:
	explicit _TBlob(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	LPVOID
		get_buffer_pointer(
		) override {
		return this->_handle->GetBufferPointer();
	}

	Size_t
		get_buffer_size(
		) override {
		return this->_handle->GetBufferSize();
	}

	virtual ~_TBlob() {}
};

//
//
template <bool own>
class _Blob : public _TBlob<IBlob, ID3DBlob, own> {
public:
	explicit _Blob(ID3DBlob* handle)
		: _TBlob<IBlob, ID3DBlob, own>(handle) {

	}

	ID3DBlob* get() override {
		return this->_handle;
	}

	const ID3DBlob* get() const override {
		return this->_handle;
	}

	~_Blob() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TUser_defined_annotation : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IUser_defined_annotation, Interface> && _HW_3D_STD_ is_base_of_v<ID3DUserDefinedAnnotation, Ty>);
public:
	explicit _TUser_defined_annotation(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	Int
		begin_event(
			_HW_3D_IN_ const _HW_3D_STD_ wstring& name
		) override {
		return this->_handle->BeginEvent(name.c_str());
	}

	Int
		end_event(
		) override {
		return this->_handle->EndEvent();
	}

	Bool
		get_status(
		) override {
		return this->_handle->GetStatus();
	}

	void
		set_marker(
			_HW_3D_IN_ const _HW_3D_STD_ wstring& name
		) override {
		this->_handle->SetMarker(name.c_str());
	}

	virtual ~_TUser_defined_annotation() {}
};

//
//
template <bool own>
class _User_defined_annotation : public _TUser_defined_annotation<IUser_defined_annotation, ID3DUserDefinedAnnotation, own> {
public:
	explicit _User_defined_annotation(ID3DUserDefinedAnnotation* handle)
		: _TUser_defined_annotation<IUser_defined_annotation, ID3DUserDefinedAnnotation, own>(handle) {

	}

	ID3DUserDefinedAnnotation* get() override {
		return this->_handle;
	}

	const ID3DUserDefinedAnnotation* get() const override {
		return this->_handle;
	}

	~_User_defined_annotation() final { }
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TLinker : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ILinker, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Linker, Ty>);
public:
	explicit _TLinker(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	Result
		add_clip_plane_from_cbuffer(
			_HW_3D_IN_ Uint slot,
			_HW_3D_IN_ Uint entry
		) override {
		return static_cast<Result>(this->_handle->AddClipPlaneFromCBuffer(slot, entry));
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBlob>, _HW_3D_STD_ unique_ptr<IBlob>>
		link(
			_HW_3D_IN_ IModule_instance* entry,
			_HW_3D_IN_ const _HW_3D_STD_ string& entry_name,
			_HW_3D_IN_ const _HW_3D_STD_ string& target_name,
			_HW_3D_IN_ /*unused*/ Uint flags
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBlob>, _HW_3D_STD_ unique_ptr<IBlob>> res;

		auto&[r, sha, err] = res;

		ID3DBlob* p_sha = nullptr;
		ID3DBlob* p_err = nullptr;
		r = static_cast<Result>(this->_handle->Link(value_ptr(entry), entry_name.c_str(), target_name.c_str(), flags, &p_sha, &p_err));

		sha = _HW_3D_STD_ make_unique<_Blob<true>>(p_sha);
		err = _HW_3D_STD_ make_unique<_Blob<true>>(p_err);

		return res;
	}

	Result
		use_library(
			_HW_3D_IN_ IModule_instance* lib
		) override {
		return static_cast<Result>(this->_handle->UseLibrary(value_ptr(lib)));
	}

	virtual ~_TLinker() {}
};

//
//
template <bool own>
class _Linker : public _TLinker<ILinker, ID3D11Linker, own> {
public:
	explicit _Linker(ID3D11Linker* handle)
		: _TLinker<ILinker, ID3D11Linker, own>(handle) {

	}

	ID3D11Linker* get() override {
		return this->_handle;
	}

	const ID3D11Linker* get() const override {
		return this->_handle;
	}

	~_Linker() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TLibrary_reflection : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ILibrary_reflection, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11LibraryReflection, Ty>);
public:
	explicit _TLibrary_reflection(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, Library_desc>
		get_desc(
		) override {
		_HW_3D_STD_ tuple<Result, Library_desc> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->GetDesc(value_ptr(desc)));

		return res;
	}

	_HW_3D_STD_ unique_ptr<IFunction_reflection>
		get_function_by_index(
			_HW_3D_IN_ Int function_index
		) override {
		return nullptr;
	}

	virtual ~_TLibrary_reflection() {}
};

//
//
template <bool own>
class _Library_reflection : public _TLibrary_reflection<ILibrary_reflection, ID3D11LibraryReflection, own> {
public:
	explicit _Library_reflection(ID3D11LibraryReflection* handle)
		: _TLibrary_reflection<ILibrary_reflection, ID3D11LibraryReflection, own>(handle) {

	}

	ID3D11LibraryReflection* get() override {
		return this->_handle;
	}

	const ID3D11LibraryReflection* get() const override {
		return this->_handle;
	}

	~_Library_reflection() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TShader_reflection : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IShader_reflection, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11ShaderReflection, Ty>);
public:
	explicit _TShader_reflection(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	Uint
		get_bitwise_instruction_count(
		) override {
		return this->_handle->GetBitwiseInstructionCount();
	}

	_HW_3D_STD_ unique_ptr<IShader_reflection_constant_buffer>
		get_constant_buffer_by_index(
			_HW_3D_IN_ Uint index
		) override {
		return nullptr;
	}

	_HW_3D_STD_ unique_ptr<IShader_reflection_constant_buffer>
		get_constant_buffer_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name
		) override {
		return nullptr;
	}

	Uint
		get_conversion_instruction_count(
		) override {
		return this->_handle->GetConversionInstructionCount();
	}

	_HW_3D_STD_ tuple<Result, Shader_desc>
		get_desc(
		) override {
		_HW_3D_STD_ tuple<Result, Shader_desc> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->GetDesc(value_ptr(desc)));

		return res;
	}

	Primitive
		get_gs_input_primitive(
		) override {
		return static_cast<Primitive>(this->_handle->GetGSInputPrimitive());
	}

	_HW_3D_STD_ tuple<Result, Signature_parameter_desc>
		get_input_parameter_desc(
			_HW_3D_IN_ Uint parameter_index
		) override {
		_HW_3D_STD_ tuple<Result, Signature_parameter_desc> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->GetInputParameterDesc(parameter_index, value_ptr(desc)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, Feature_level>
		get_min_feature_level(
		) override {
		_HW_3D_STD_ tuple<Result, Feature_level> res;

		auto&[r, lev] = res;
		r = static_cast<Result>(this->_handle->GetMinFeatureLevel((D3D_FEATURE_LEVEL *)&lev));

		return res;
	}

	Uint
		get_movc_instruction_count(
		) override {
		return this->_handle->GetMovcInstructionCount();
	}

	Uint
		get_mov_instruction_count(
		) override {
		return this->_handle->GetMovInstructionCount();
	}

	Uint
		get_num_interface_slots(
		) override {
		return this->_handle->GetNumInterfaceSlots();
	}

	_HW_3D_STD_ tuple<Result, Signature_parameter_desc>
		get_output_paramter_desc(
			_HW_3D_IN_ Uint parameter_index
		) override {
		_HW_3D_STD_ tuple<Result, Signature_parameter_desc> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->GetOutputParameterDesc(parameter_index, value_ptr(desc)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, Signature_parameter_desc>
		get_patch_constant_parameter_desc(
			_HW_3D_IN_ Uint parameter_index
		) override {
		_HW_3D_STD_ tuple<Result, Signature_parameter_desc> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->GetPatchConstantParameterDesc(parameter_index, value_ptr(desc)));

		return res;
	}

	Shader_require
		get_requires_flags(
		) override {
		return Shader_require_bit(this->_handle->GetRequiresFlags());
	}

	_HW_3D_STD_ tuple<Result, Shader_input_bind_desc>
		get_resource_binding_desc(
			_HW_3D_IN_ Uint resource_index
		) override {
		_HW_3D_STD_ tuple<Result, Shader_input_bind_desc> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->GetResourceBindingDesc(resource_index, value_ptr(desc)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, Shader_input_bind_desc>
		get_resource_binding_desc_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name
		) override {
		_HW_3D_STD_ tuple<Result, Shader_input_bind_desc> res;

		auto&[r, desc] = res;
		r = static_cast<Result>(this->_handle->GetResourceBindingDescByName(name.c_str(), value_ptr(desc)));

		return res;
	}

	_HW_3D_STD_ tuple<Uint, _HW_3D_STD_ array<Uint, 3>>
		get_thread_group_size(
		) override {
		_HW_3D_STD_ tuple<Uint, _HW_3D_STD_ array<Uint, 3>> res;

		auto&[t, xyz] = res;
		t = this->_handle->GetThreadGroupSize(xyz.data(), xyz.data() + 1, xyz.data() + 2);

		return res;
	}

	_HW_3D_STD_ unique_ptr<IShader_reflection_variable>
		get_variable_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ string& name
		) override {
		return nullptr;
	}

	Bool
		is_sampler_frequency_shader(
		) override {
		return this->_handle->IsSampleFrequencyShader();
	}

	virtual ~_TShader_reflection() {}
};

//
//
template <bool own>
class _Shader_reflection : public _TShader_reflection<IShader_reflection, ID3D11ShaderReflection, own> {
public:
	explicit _Shader_reflection(ID3D11ShaderReflection* handle)
		: _TShader_reflection<IShader_reflection, ID3D11ShaderReflection, own>(handle) {

	}

	ID3D11ShaderReflection* get() override {
		return this->_handle;
	}

	const ID3D11ShaderReflection* get() const override {
		return this->_handle;
	}

	~_Shader_reflection() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TShader_trace : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IShader_trace, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11ShaderTrace, Ty>);
public:
	explicit _TShader_trace(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, Trace_value>
		get_initial_register_contents(
			_HW_3D_IN_ Trace_register& reg
		) override {
		_HW_3D_STD_ tuple<Result, Trace_value> res;

		auto&[r, val] = res;
		r = static_cast<Result>(this->_handle->GetInitialRegisterContents(value_ptr(reg), value_ptr(val)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, Trace_register, Trace_value>
		get_read_register(
			_HW_3D_IN_ Uint step_index,
			_HW_3D_IN_ Uint read_register_index
		) override {
		_HW_3D_STD_ tuple<Result, Trace_register, Trace_value> res;

		auto&[r, reg, val] = res;
		r = static_cast<Result>(this->_handle->GetReadRegister(step_index, read_register_index, value_ptr(reg), value_ptr(val)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, Trace_step>
		get_step(
			_HW_3D_IN_ Uint step_index
		) override {
		_HW_3D_STD_ tuple<Result, Trace_step> res;

		auto&[r, step] = res;
		r = static_cast<Result>(this->_handle->GetStep(step_index, value_ptr(step)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, Trace_stats>
		get_trace_stats(
		) override {
		_HW_3D_STD_ tuple<Result, Trace_stats> res;

		auto&[r, stat] = res;
		r = static_cast<Result>(this->_handle->GetTraceStats(value_ptr(stat)));

		return res;
	}

	_HW_3D_STD_ tuple<Result, Trace_register, Trace_value>
		get_written_register(
			_HW_3D_IN_ Uint step_index,
			_HW_3D_IN_ Uint written_register_index
		) override {
		_HW_3D_STD_ tuple<Result, Trace_register, Trace_value> res;

		auto&[r, reg, val] = res;
		r = static_cast<Result>(this->_handle->GetWrittenRegister(step_index, written_register_index, value_ptr(reg), value_ptr(val)));

		return res;
	}

	Result
		ps_select_stamp(
			_HW_3D_IN_ Uint sample_index
		) override {
		return static_cast<Result>(this->_handle->PSSelectStamp(sample_index));
	}

	void
		reset_trace(
		) override {
		this->_handle->ResetTrace();
	}

	_HW_3D_STD_ tuple<Result, Uint64>
		trace_ready(
		) override {
		_HW_3D_STD_ tuple<Result, Uint64> res;

		auto&[r, cnt] = res;
		r = static_cast<Result>(this->_handle->TraceReady(&cnt));

		return res;
	}

	virtual ~_TShader_trace() {}
};

//
//
template <bool own>
class _Shader_trace : public _TShader_trace<IShader_trace, ID3D11ShaderTrace, own> {
public:
	explicit _Shader_trace(ID3D11ShaderTrace* handle)
		: _TShader_trace<IShader_trace, ID3D11ShaderTrace, own>(handle) {

	}

	ID3D11ShaderTrace* get() override {
		return this->_handle;
	}

	const ID3D11ShaderTrace* get() const override {
		return this->_handle;
	}

	~_Shader_trace() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TShader_trace_factory : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IShader_trace_factory, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11ShaderTraceFactory, Ty>);
public:
	explicit _TShader_trace_factory(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IShader_trace>>
		create_shader_trace(
			_HW_3D_IN_ IBase* shader,
			_HW_3D_IN_ Shader_trace_desc& desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IShader_trace>> res;

		auto&[r, trace] = res;

		ID3D11ShaderTrace* p_trace = nullptr;
		r = static_cast<Result>(this->_handle->CreateShaderTrace(value_ptr(shader), value_ptr(desc), &p_trace));

		trace = _HW_3D_STD_ make_unique<_Shader_trace<true>>(p_trace);

		return res;
	}

	virtual ~_TShader_trace_factory() {}
};

//
//
template <bool own>
class _Shader_trace_factory : public _TShader_trace_factory<IShader_trace_factory, ID3D11ShaderTraceFactory, own> {
public:
	explicit _Shader_trace_factory(ID3D11ShaderTraceFactory* handle)
		: _TShader_trace_factory<IShader_trace_factory, ID3D11ShaderTraceFactory, own>(handle) {

	}

	ID3D11ShaderTraceFactory* get() override {
		return this->_handle;
	}

	const ID3D11ShaderTraceFactory* get() const override {
		return this->_handle;
	}

	~_Shader_trace_factory() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TFunction_linking_graph : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IFunction_linking_graph, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11FunctionLinkingGraph, Ty>);
public:
	explicit _TFunction_linking_graph(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ILinking_node>>
		call_function(
			_HW_3D_IN_ const _HW_3D_STD_ string& module_instance_namespace,
			_HW_3D_IN_ IModule* module_with_function_protoype,
			_HW_3D_IN_ const _HW_3D_STD_ string& function_name
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ILinking_node>> res;

		auto&[r, node] = res;

		ID3D11LinkingNode* p_node = nullptr;
		r = static_cast<Result>(this->_handle->CallFunction(module_instance_namespace.c_str(), value_ptr(module_with_function_protoype), function_name.c_str(), &p_node));

		node = _HW_3D_STD_ make_unique<_Linking_node<true>>(p_node);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IModule_instance>, _HW_3D_STD_ unique_ptr<IBlob>>
		create_module_instance(
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IModule_instance>, _HW_3D_STD_ unique_ptr<IBlob>> res;

		auto&[r, mod, blob] = res;

		ID3D11ModuleInstance* p_mod = nullptr;
		ID3DBlob* p_blob = nullptr;
		r = static_cast<Result>(this->_handle->CreateModuleInstance(&p_mod, &p_blob));

		mod = _HW_3D_STD_ make_unique<_Module_instance<true>>(p_mod);
		blob = _HW_3D_STD_ make_unique<_Blob<true>>(p_blob);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBlob>>
		generate_hlsl(
			_HW_3D_IN_ /*unused*/ Uint flags
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBlob>> res;

		auto&[r, buf] = res;

		ID3DBlob* p_buf = nullptr;
		r = static_cast<Result>(this->_handle->GenerateHlsl(flags, &p_buf));

		buf = _HW_3D_STD_ make_unique<_Blob<true>>(p_buf);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBlob>>
		get_last_error(
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBlob>> res;

		auto&[r, err] = res;

		ID3DBlob* p_err = nullptr;
		r = static_cast<Result>(this->_handle->GetLastError(&p_err));

		err = _HW_3D_STD_ make_unique<_Blob<true>>(p_err);

		return res;
	}

	Result
		pass_value(
			_HW_3D_IN_ ILinking_node* src,
			_HW_3D_IN_ Int src_parameter_index,
			_HW_3D_IN_ ILinking_node* dst,
			_HW_3D_IN_ Int dst_parameter_index
		) override {
		return static_cast<Result>(this->_handle->PassValue(value_ptr(src), src_parameter_index, value_ptr(dst), dst_parameter_index));
	}

	Result
		pass_value_with_swizzle(
			_HW_3D_IN_ ILinking_node* src,
			_HW_3D_IN_ Int src_parameter_index,
			_HW_3D_IN_ const _HW_3D_STD_ string& src_swizzle,
			_HW_3D_IN_ ILinking_node* dst,
			_HW_3D_IN_ Int dst_parameter_index,
			_HW_3D_IN_ const _HW_3D_STD_ string& dst_swizzle
		) override {
		return static_cast<Result>(this->_handle->PassValueWithSwizzle(value_ptr(src), src_parameter_index, src_swizzle.c_str(), value_ptr(dst), dst_parameter_index, dst_swizzle.c_str()));
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ILinking_node>>
		set_input_signature(
			_HW_3D_IN_ const _HW_3D_STD_ vector<Parameter_desc>& parameters
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ILinking_node>> res;

		auto&[r, node] = res;

		ID3D11LinkingNode* p_node = nullptr;
		r = static_cast<Result>(this->_handle->SetInputSignature((const D3D11_PARAMETER_DESC*)(parameters.data()), UINT(parameters.size()), &p_node));

		node = _HW_3D_STD_ make_unique<_Linking_node<true>>(p_node);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ILinking_node>>
		set_output_signature(
			_HW_3D_IN_ const _HW_3D_STD_ vector<Parameter_desc>& parameters
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ILinking_node>> res;

		auto&[r, node] = res;

		ID3D11LinkingNode* p_node = nullptr;
		r = static_cast<Result>(this->_handle->SetOutputSignature((const D3D11_PARAMETER_DESC*)(parameters.data()), UINT(parameters.size()), &p_node));

		node = _HW_3D_STD_ make_unique<_Linking_node<true>>(p_node);

		return res;
	}

	virtual ~_TFunction_linking_graph() {}
};

//
//
template <bool own>
class _Function_linking_graph : public _TFunction_linking_graph<IFunction_linking_graph, ID3D11FunctionLinkingGraph, own> {
public:
	_Function_linking_graph(ID3D11FunctionLinkingGraph* handle)
		: _TFunction_linking_graph<IFunction_linking_graph, ID3D11FunctionLinkingGraph, own>(handle) {

	}

	ID3D11FunctionLinkingGraph* get() override {
		return this->_handle;
	}

	const ID3D11FunctionLinkingGraph* get() const override {
		return this->_handle;
	}

	~_Function_linking_graph() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Device, Ty>);
public:
	explicit _TDevice(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, Counter_type, Uint>
		check_counter(
			_HW_3D_IN_ const Counter_desc& desc,
			_HW_3D_OUT_ _HW_3D_STD_ string* p_name,
			_HW_3D_OUT_ _HW_3D_STD_ string* p_units,
			_HW_3D_OUT_ _HW_3D_STD_ string* p_description
		) override {
		_HW_3D_STD_ tuple<Result, Counter_type, Uint> res;

		auto&[r, type, cnt] = res;

		Uint n_size = 0;
		Uint u_size = 0;
		Uint d_size = 0;
		this->_handle->CheckCounter(value_ptr(desc), (D3D11_COUNTER_TYPE*)&type, &cnt, nullptr, &n_size, nullptr, &u_size, nullptr, &d_size);

		auto str_ptr = [](_HW_3D_STD_ string* ptr, Uint size) -> LPSTR {
			if (ptr == nullptr || size == 0) return nullptr;
			else {
				ptr->resize(size);
				return ptr->data();
			}
		};

		r = static_cast<Result>(this->_handle->CheckCounter(value_ptr(desc), (D3D11_COUNTER_TYPE*)&type, &cnt, str_ptr(p_name, n_size), nullptr, str_ptr(p_units, u_size), nullptr, str_ptr(p_description, d_size), nullptr));

		return res;
	}

	Counter_info
		check_counter_info(
		) override {
		Counter_info info;
		this->_handle->CheckCounterInfo(value_ptr(info));
		return info;
	}

	Result
		check_feature_support(
			_HW_3D_IN_ Feature feature,
			_HW_3D_OUT_ void * p_data,
			_HW_3D_IN_ Uint data_size
		) override {
		return static_cast<Result>(this->_handle->CheckFeatureSupport(D3D11_FEATURE(feature), p_data, data_size));
	}

	_HW_3D_STD_ tuple<Result, Format_support>
		check_format_support(
			_HW_3D_IN_ _HW_3D_DXGI_ Format format
		) override {
		_HW_3D_STD_ tuple<Result, Format_support> res;

		auto&[r, flags] = res;

		UINT flag = 0;
		r = static_cast<Result>(this->_handle->CheckFormatSupport(DXGI_FORMAT(format), &flag));

		flags = Format_support_bit(flag);

		return res;
	}

	_HW_3D_STD_ tuple<Result, Uint>
		check_multisample_quality_levels(
			_HW_3D_IN_ _HW_3D_DXGI_ Format format,
			_HW_3D_IN_ Uint sample_count
		) override {
		_HW_3D_STD_ tuple<Result, Uint> res;

		auto&[r, nlev] = res;
		r = static_cast<Result>(this->_handle->CheckMultisampleQualityLevels(DXGI_FORMAT(format), sample_count, &nlev));

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBlend_state>>
		create_blend_state(
			_HW_3D_IN_ const Blend_desc& desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBlend_state>> res;

		auto&[r, bs] = res;

		ID3D11BlendState* p_bs = nullptr;
		r = static_cast<Result>(this->_handle->CreateBlendState(value_ptr(desc), &p_bs));

		bs = _HW_3D_STD_ make_unique<_Blend_state<true>>(p_bs);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBuffer>>
		create_buffer(
			_HW_3D_IN_ const Buffer_desc& desc,
			_HW_3D_IN_ const Subresource_data* p_data
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBuffer>> res;

		auto&[r, buf] = res;

		ID3D11Buffer* p_buf = nullptr;
		r = static_cast<Result>(this->_handle->CreateBuffer(value_ptr(desc), value_ptr(p_data), &p_buf));

		buf = _HW_3D_STD_ make_unique<_Buffer<true>>(p_buf);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IClass_linkage>>
		create_class_linkage(
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IClass_linkage>> res;

		auto&[r, cl] = res;

		ID3D11ClassLinkage* p_cl = nullptr;
		r = static_cast<Result>(this->_handle->CreateClassLinkage(&p_cl));

		cl = _HW_3D_STD_ make_unique<_Class_linkage<true>>(p_cl);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ICompute_shader>>
		create_compute_shader(
			_HW_3D_IN_ const void* shader_byte_code,
			_HW_3D_IN_ Size_t code_length,
			_HW_3D_IN_ IClass_linkage* p_linage
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ICompute_shader>> res;

		auto&[r, cs] = res;

		ID3D11ComputeShader* p_cs = nullptr;
		r = static_cast<Result>(this->_handle->CreateComputeShader(shader_byte_code, code_length, value_ptr(p_linage), &p_cs));

		cs = _HW_3D_STD_ make_unique<_Compute_shader<true>>(p_cs);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ICounter>>
		create_counter(
			_HW_3D_IN_ const Counter_desc& desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ICounter>> res;

		auto&[r, counter] = res;

		ID3D11Counter* p_counter = nullptr;
		r = static_cast<Result>(this->_handle->CreateCounter(value_ptr(desc), &p_counter));

		counter = _HW_3D_STD_ make_unique<_Counter<true>>(p_counter);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDevice_context>>
		create_deferred_context(
			/*unused*/ Uint flags = 0
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDevice_context>> res;

		auto&[r, dc] = res;

		ID3D11DeviceContext* p_dc = nullptr;
		r = static_cast<Result>(this->_handle->CreateDeferredContext(flags, &p_dc));

		dc = _HW_3D_STD_ make_unique<_Device_context<true>>(p_dc);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDepth_stencil_state>>
		create_depth_stencil_state(
			_HW_3D_IN_ const Depth_stencil_desc& desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDepth_stencil_state>> res;

		auto&[r, dss] = res;

		ID3D11DepthStencilState* p_dss = nullptr;
		r = static_cast<Result>(this->_handle->CreateDepthStencilState(value_ptr(desc), &p_dss));

		dss = _HW_3D_STD_ make_unique<_Depth_stencil_state<true>>(p_dss);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDepth_stencil_view>>
		create_depth_stencil_view(
			_HW_3D_IN_ IResource* p_resource,
			_HW_3D_IN_ const Depth_stencil_view_desc* p_desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDepth_stencil_view>> res;

		auto&[r, dsv] = res;

		ID3D11DepthStencilView* p_dsv = nullptr;
		r = static_cast<Result>(this->_handle->CreateDepthStencilView(value_ptr(p_resource), value_ptr(p_desc), &p_dsv));

		dsv = _HW_3D_STD_ make_unique<_Depth_stencil_view<true>>(p_dsv);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDomain_shader>>
		create_domain_shader(
			_HW_3D_IN_ const void* shader_byte_code,
			_HW_3D_IN_ Size_t code_length,
			_HW_3D_IN_ IClass_linkage* p_linage
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDomain_shader>> res;

		auto&[r, ds] = res;

		ID3D11DomainShader* p_ds = nullptr;
		r = static_cast<Result>(this->_handle->CreateDomainShader(shader_byte_code, code_length, value_ptr(p_linage), &p_ds));

		ds = _HW_3D_STD_ make_unique<_Domain_shader<true>>(p_ds);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IGeometry_shader>>
		create_geometry_shader(
			_HW_3D_IN_ const void* shader_byte_code,
			_HW_3D_IN_ Size_t code_length,
			_HW_3D_IN_ IClass_linkage* p_linage
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IGeometry_shader>> res;

		auto&[r, gs] = res;

		ID3D11GeometryShader* p_gs = nullptr;
		r = static_cast<Result>(this->_handle->CreateGeometryShader(shader_byte_code, code_length, value_ptr(p_linage), &p_gs));

		gs = _HW_3D_STD_ make_unique<_Geometry_shader<true>>(p_gs);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IGeometry_shader>>
		create_geometry_shader_with_stream_output(
			_HW_3D_IN_ const void* shader_byte_code,
			_HW_3D_IN_ Size_t code_length,
			_HW_3D_IN_ const _HW_3D_STD_ vector<So_declaration_entry>& entrys,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& buffer_strides,
			_HW_3D_IN_ Uint rasteried_stream,
			_HW_3D_IN_ IClass_linkage* p_linage
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IGeometry_shader>> res;

		auto&[r, gs] = res;

		ID3D11GeometryShader* p_gs = nullptr;
		r = static_cast<Result>(this->_handle->CreateGeometryShaderWithStreamOutput(
			shader_byte_code,
			code_length,
			(D3D11_SO_DECLARATION_ENTRY *)entrys.data(),
			Uint(entrys.size()),
			buffer_strides.data(),
			Uint(buffer_strides.size()),
			rasteried_stream,
			value_ptr(p_linage),
			&p_gs));

		gs = _HW_3D_STD_ make_unique<_Geometry_shader<true>>(p_gs);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IHull_shader>>
		create_hull_shader(
			_HW_3D_IN_ const void* shader_byte_code,
			_HW_3D_IN_ Size_t code_length,
			_HW_3D_IN_ IClass_linkage* p_linage
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IHull_shader>> res;

		auto&[r, hs] = res;

		ID3D11HullShader *p_hs = nullptr;
		r = static_cast<Result>(this->_handle->CreateHullShader(shader_byte_code, code_length, value_ptr(p_linage), &p_hs));

		hs = _HW_3D_STD_ make_unique<_Hull_shader<true>>(p_hs);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IInput_layout>>
		create_input_layout(
			_HW_3D_IN_ const  _HW_3D_STD_ vector<Input_element_desc>& descs,
			_HW_3D_IN_ const void* shader_byte_code,
			_HW_3D_IN_ Size_t code_length
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IInput_layout>> res;

		auto&[r, il] = res;

		ID3D11InputLayout* p_il = nullptr;
		r = static_cast<Result>(this->_handle->CreateInputLayout((const D3D11_INPUT_ELEMENT_DESC *)descs.data(), Uint(descs.size()), shader_byte_code, code_length, &p_il));

		il = _HW_3D_STD_ make_unique<_Input_layout<true>>(p_il);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IPixel_shader>>
		create_pixel_shader(
			_HW_3D_IN_ const void* shader_byte_code,
			_HW_3D_IN_ Size_t code_length,
			_HW_3D_IN_ IClass_linkage* p_linage
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IPixel_shader>> res;

		auto&[r, ps] = res;

		ID3D11PixelShader* p_ps = nullptr;
		r = static_cast<Result>(this->_handle->CreatePixelShader(shader_byte_code, code_length, value_ptr(p_linage), &p_ps));

		ps = _HW_3D_STD_ make_unique<_Pixel_shader<true>>(p_ps);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IPredicate>>
		create_perdicate(
			_HW_3D_IN_ const Query_desc& desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IPredicate>> res;

		auto&[r, p] = res;

		ID3D11Predicate* p_p = nullptr;
		r = static_cast<Result>(this->_handle->CreatePredicate(value_ptr(desc), &p_p));

		p = _HW_3D_STD_ make_unique<_Predicate<true>>(p_p);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IQuery>>
		create_query(
			_HW_3D_IN_ const Query_desc& desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IQuery>> res;

		auto&[r, q] = res;

		ID3D11Query* p_q = nullptr;
		r = static_cast<Result>(this->_handle->CreateQuery(value_ptr(desc), &p_q));

		q = _HW_3D_STD_ make_unique<_Query<true>>(p_q);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IRasterizer_state>>
		create_rasterizer_state(
			_HW_3D_IN_ const Rasterizer_desc& desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IRasterizer_state>> res;

		auto&[r, rs] = res;

		ID3D11RasterizerState* p_rs = nullptr;
		r = static_cast<Result>(this->_handle->CreateRasterizerState(value_ptr(desc), &p_rs));

		rs = _HW_3D_STD_ make_unique<_Rasterizer_state<true>>(p_rs);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IRender_target_view>>
		create_render_target_view(
			_HW_3D_IN_ IResource* p_resource,
			_HW_3D_IN_ const Render_target_view_desc* p_desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IRender_target_view>> res;

		auto&[r, rtv] = res;

		ID3D11RenderTargetView* p_rtv = nullptr;
		r = static_cast<Result>(this->_handle->CreateRenderTargetView(value_ptr(p_resource), value_ptr(p_desc), &p_rtv));

		rtv = _HW_3D_STD_ make_unique<_Render_target_view<true>>(p_rtv);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISampler_state>>
		create_sampler_state(
			_HW_3D_IN_ const Sampler_desc& desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ISampler_state>> res;

		auto&[r, ss] = res;

		ID3D11SamplerState* p_ss = nullptr;
		r = static_cast<Result>(this->_handle->CreateSamplerState(value_ptr(desc), &p_ss));

		ss = _HW_3D_STD_ make_unique<_Sampler_state<true>>(p_ss);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IShader_resource_view>>
		create_shader_resource_view(
			_HW_3D_IN_ IResource* p_resource,
			_HW_3D_IN_ const Shader_resource_view_desc* p_desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IShader_resource_view>> res;

		auto&[r, srv] = res;

		ID3D11ShaderResourceView* p_srv = nullptr;
		r = static_cast<Result>(this->_handle->CreateShaderResourceView(value_ptr(p_resource), value_ptr(p_desc), &p_srv));

		srv = _HW_3D_STD_ make_unique<_Shader_resource_view<true>>(p_srv);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ITexture1d>>
		create_texture_1d(
			_HW_3D_IN_ const Texture1d_desc& desc,
			_HW_3D_IN_ const Subresource_data* p_data
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ITexture1d>> res;

		auto&[r, t1d] = res;

		ID3D11Texture1D* p_t1d = nullptr;
		r = static_cast<Result>(this->_handle->CreateTexture1D(value_ptr(desc), value_ptr(p_data), &p_t1d));

		t1d = _HW_3D_STD_ make_unique<_Texture1d<true>>(p_t1d);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ITexture2d>>
		create_texture_2d(
			_HW_3D_IN_ const Texture2d_desc& desc,
			_HW_3D_IN_ const Subresource_data* p_data
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ITexture2d>> res;

		auto&[r, t2d] = res;

		ID3D11Texture2D* p_t2d = nullptr;
		r = static_cast<Result>(this->_handle->CreateTexture2D(value_ptr(desc), value_ptr(p_data), &p_t2d));

		t2d = _HW_3D_STD_ make_unique<_Texture2d<true>>(p_t2d);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ITexture3d>>
		create_texture_3d(
			_HW_3D_IN_ const Texture3d_desc& desc,
			_HW_3D_IN_ const Subresource_data* p_data
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ITexture3d>> res;

		auto&[r, t3d] = res;

		ID3D11Texture3D* p_t3d = nullptr;
		r = static_cast<Result>(this->_handle->CreateTexture3D(value_ptr(desc), value_ptr(p_data), &p_t3d));

		t3d = _HW_3D_STD_ make_unique<_Texture3d<true>>(p_t3d);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IUnordered_access_view>>
		create_unordered_access_view(
			_HW_3D_IN_ IResource* p_resouce,
			_HW_3D_IN_ const Unordered_access_view_desc* p_desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IUnordered_access_view>> res;

		auto&[r, uav] = res;

		ID3D11UnorderedAccessView* p_uav = nullptr;
		r = static_cast<Result>(this->_handle->CreateUnorderedAccessView(value_ptr(p_resouce), value_ptr(p_desc), &p_uav));

		uav = _HW_3D_STD_ make_unique<_Unordered_access_view<true>>(p_uav);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IVertex_shader>>
		create_vertex_shader(
			_HW_3D_IN_ const void* shader_byte_code,
			_HW_3D_IN_ Size_t code_length,
			_HW_3D_IN_ IClass_linkage* p_linage
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IVertex_shader>> res;

		auto&[r, vs] = res;

		ID3D11VertexShader* p_vs = nullptr;
		r = static_cast<Result>(this->_handle->CreateVertexShader(shader_byte_code, code_length, value_ptr(p_linage), &p_vs));

		vs = _HW_3D_STD_ make_unique<_Vertex_shader<true>>(p_vs);

		return res;
	}

	Create_device_flag
		get_creation_falgs(
		) override {
		return Create_device_flag_bit(this->_handle->GetCreationFlags());
	}

	Result
		get_device_removed_reason(
		) override {
		return static_cast<Result>(this->_handle->GetDeviceRemovedReason());
	}

	Raise_flag
		get_exception_mode(
		) override {
		return Raise_flag_bit(this->_handle->GetExceptionMode());
	}

	Feature_level
		get_feature_level(
		) override {
		return (Feature_level)this->_handle->GetFeatureLevel();
	}

	_HW_3D_STD_ unique_ptr<IDevice_context>
		get_immediate_context(
		) override {
		ID3D11DeviceContext* p_dc = nullptr;
		this->_handle->GetImmediateContext(&p_dc);

		return _HW_3D_STD_ make_unique<_Device_context<true>>(p_dc);
	}

	Result
		get_private_data(
			_HW_3D_IN_ REFGUID guid,
			_HW_3D_IN_OUT_ Uint* p_size,
			_HW_3D_OUT_ void * p_data
		) override {
		return static_cast<Result>(this->_handle->GetPrivateData(guid, p_size, p_data));
	}

	_HW_3D_STD_ tuple<Result, void*>
		open_shared_resource(
			_HW_3D_IN_ HANDLE h_resource,
			_HW_3D_IN_ REFIID returned_interface
		) override {
		_HW_3D_STD_ tuple<Result, void*> res;

		auto&[r, re] = res;
		r = static_cast<Result>(this->_handle->OpenSharedResource(h_resource, returned_interface, &re));

		return res;
	}

	Result
		set_exception_mode(
			_HW_3D_IN_ Raise_flag flags
		) override {
		return static_cast<Result>(this->_handle->SetExceptionMode(Raise_flag::mask_type(flags)));
	}

	Result
		set_private_data(
			_HW_3D_IN_ REFGUID guid,
			_HW_3D_IN_ Uint size,
			_HW_3D_IN_ const void* p_data
		) override {
		return static_cast<Result>(this->_handle->SetPrivateData(guid, size, p_data));
	}

	Result
		set_private_data_interface(
			_HW_3D_IN_ REFGUID guid,
			_HW_3D_IN_ const IBase* p_data
		) override {
		return static_cast<Result>(this->_handle->SetPrivateDataInterface(guid, value_ptr(p_data)));
	}

	virtual ~_TDevice() {}
};

//
//
template <bool own>
class _Device : public _TDevice<IDevice, ID3D11Device, own> {
public:
	explicit _Device(ID3D11Device* handle)
		: _TDevice<IDevice, ID3D11Device, own>(handle) {

	}

	ID3D11Device* get() override {
		return this->_handle;
	}

	const ID3D11Device* get() const override {
		return this->_handle;
	}

	~_Device() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice_context : public _TDevice_child<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice_context, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11DeviceContext, Ty>);
public:
	explicit _TDevice_context(Ty* handle)
		: _TDevice_child<Interface, Ty, own>(handle) {

	}

	void
		begin(
			_HW_3D_IN_ IAsynchronous* async
		) override {
		this->_handle->Begin(value_ptr(async));
	}

	void
		clear_depth_stencil_view(
			_HW_3D_IN_ IDepth_stencil_view* view,
			_HW_3D_IN_ Clear_flag flags,
			_HW_3D_IN_ Float depth,
			_HW_3D_IN_ Uint8 stencil
		) override {
		this->_handle->ClearDepthStencilView(value_ptr(view), Clear_flag::mask_type(flags), depth, stencil);
	}

	void
		clear_render_target_view(
			_HW_3D_IN_ IRender_target_view*  view,
			_HW_3D_IN_ const _HW_3D_STD_ array<Float, 4>& color
		) override {
		this->_handle->ClearRenderTargetView(value_ptr(view), color.data());
	}

	void
		clear_state(
		) override {
		this->_handle->ClearState();
	}

	void
		clear_unordered_access_view_float(
			_HW_3D_IN_ IUnordered_access_view* view,
			_HW_3D_IN_ const _HW_3D_STD_ array<Float, 4>& val
		) override {
		this->_handle->ClearUnorderedAccessViewFloat(value_ptr(view), val.data());
	}

	void
		clear_unordered_access_view_uint(
			_HW_3D_IN_ IUnordered_access_view* view,
			_HW_3D_IN_ const _HW_3D_STD_ array<Uint, 4>& val
		) override {
		this->_handle->ClearUnorderedAccessViewUint(value_ptr(view), val.data());
	}

	void
		copy_resource(
			_HW_3D_IN_ IResource* dst,
			_HW_3D_IN_ IResource* src
		) override {
		this->_handle->CopyResource(value_ptr(dst), value_ptr(src));
	}

	void
		copy_structure_count(
			_HW_3D_IN_ IBuffer* dst,
			_HW_3D_IN_ Uint aligned_offset,
			_HW_3D_IN_ IUnordered_access_view* src
		) override {
		this->_handle->CopyStructureCount(value_ptr(dst), aligned_offset, value_ptr(src));
	}

	void
		copy_subresource_region(
			_HW_3D_IN_ IResource* dst,
			_HW_3D_IN_ Uint dst_subresource,
			_HW_3D_IN_ _HW_3D_STD_ array<Uint, 3> offset,
			_HW_3D_IN_ IResource* src,
			_HW_3D_IN_ Uint src_subresource,
			_HW_3D_IN_ const Box* range
		) override {
		this->_handle->CopySubresourceRegion(value_ptr(dst), dst_subresource, offset[0], offset[1], offset[2], value_ptr(src), src_subresource, value_ptr(range));
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>
		cs_get_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>> res;

		_HW_3D_STD_ vector<ID3D11Buffer*> bufs(num_buffers, nullptr);
		this->_handle->CSGetConstantBuffers(start_slot, num_buffers, bufs.data());

		_HW_3D_STD_ for_each(bufs.begin(), bufs.end(), [&res](auto ptr) {res.emplace_back(_HW_3D_STD_ make_unique<_Buffer<true>>(ptr)); });

		return res;
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>>
		cs_get_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_samplers
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>> res;

		_HW_3D_STD_ vector<ID3D11SamplerState*> samplers(num_samplers, nullptr);
		this->_handle->CSGetSamplers(start_slot, num_samplers, samplers.data());

		_HW_3D_STD_ for_each(samplers.begin(), samplers.end(), [&res](auto ptr) { res.emplace_back(_HW_3D_STD_ make_unique<_Sampler_state<true>>(ptr)); });

		return res;
	}

	_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<ICompute_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>>
		cs_get_shader(
		) override {
		_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<ICompute_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>> res;

		auto&[cs, cis] = res;

		ID3D11ComputeShader* p_cs = nullptr;
		Uint num = 0;
		this->_handle->CSGetShader(&p_cs, nullptr, &num);

		_HW_3D_STD_ vector<ID3D11ClassInstance*> p_cis(num, nullptr);
		this->_handle->CSGetShader(&p_cs, p_cis.data(), &num);

		cs = _HW_3D_STD_ make_unique<_Compute_shader<true>>(p_cs);
		_HW_3D_STD_ for_each(p_cis.begin(), p_cis.end(), [&cis](auto ptr) { cis.emplace_back(_HW_3D_STD_ make_unique<_Class_instance<true>>(ptr)); });

		return res;
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>>
		cs_get_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_views
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>> res;

		_HW_3D_STD_ vector<ID3D11ShaderResourceView*> views(num_views, nullptr);
		this->_handle->CSGetShaderResources(start_slot, num_views, views.data());

		_HW_3D_STD_ for_each(views.begin(), views.end(), [&res](auto ptr) {res.emplace_back(_HW_3D_STD_ make_unique<_Shader_resource_view<true>>(ptr)); });

		return res;
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IUnordered_access_view>>
		cs_get_unordered_access_views(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_uavs
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IUnordered_access_view>> res;

		_HW_3D_STD_ vector<ID3D11UnorderedAccessView*> views(num_uavs, nullptr);
		this->_handle->CSGetUnorderedAccessViews(start_slot, num_uavs, views.data());

		_HW_3D_STD_ for_each(views.begin(), views.end(), [&res](auto ptr) {res.emplace_back(_HW_3D_STD_ make_unique<_Unordered_access_view<true>>(ptr)); });

		return res;
	}

	void
		cs_set_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& constant_buffers
		) override {
		auto buffers = values_ptr(constant_buffers);
		this->_handle->CSSetConstantBuffers(start_slot, Uint(buffers.size()), buffers.data());
	}

	void
		cs_set_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<ISampler_state*>& samplers
		) override {
		auto ss = values_ptr(samplers);
		this->_handle->CSSetSamplers(start_slot, Uint(ss.size()), ss.data());
	}

	void
		cs_set_shader(
			_HW_3D_IN_ ICompute_shader* shader,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IClass_instance*>& instances
		) override {
		auto cis = values_ptr(instances);
		this->_handle->CSSetShader(value_ptr(shader), cis.data(), Uint(cis.size()));
	}

	void
		cs_set_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IShader_resource_view*>& views
		) override {
		auto srvs = values_ptr(views);
		this->_handle->CSSetShaderResources(start_slot, Uint(srvs.size()), srvs.data());
	}

	void
		cs_set_unordered_access_views(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IUnordered_access_view*>& views,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& initial_counts
		) override {
		assert(views.size() == initial_counts.size());
		auto uavs = values_ptr(views);
		this->_handle->CSSetUnorderedAccessViews(start_slot, Uint(uavs.size()), uavs.data(), initial_counts.data());
	}

	void
		dispatch(
			_HW_3D_IN_ _HW_3D_STD_ array<Uint, 3> size
		) override {
		this->_handle->Dispatch(size[0], size[1], size[2]);
	}

	void
		dispatch_indirect(
			_HW_3D_IN_ IBuffer* buffer,
			_HW_3D_IN_ Uint offset
		) override {
		this->_handle->DispatchIndirect(value_ptr(buffer), offset);
	}

	void
		draw(
			_HW_3D_IN_ Uint count,
			_HW_3D_IN_ Uint first
		) override {
		this->_handle->Draw(count, first);
	}

	void
		draw_auto(
		) override {
		this->_handle->DrawAuto();
	}

	void
		draw_indexed(
			_HW_3D_IN_ Uint count,
			_HW_3D_IN_ Uint first,
			_HW_3D_IN_ Int base_vertex
		) override {
		this->_handle->DrawIndexed(count, first, base_vertex);
	}

	void
		draw_indexed_instanced(
			_HW_3D_IN_ Uint count,
			_HW_3D_IN_ Uint instance_count,
			_HW_3D_IN_ Uint first,
			_HW_3D_IN_ Int base_vertex,
			_HW_3D_IN_ Uint first_isntance
		) override {
		this->_handle->DrawIndexedInstanced(count, instance_count, first, base_vertex, first_isntance);
	}

	void
		draw_indexed_instanced_indirect(
			_HW_3D_IN_ IBuffer* buffer,
			_HW_3D_IN_ Uint offset
		) override {
		this->_handle->DrawIndexedInstancedIndirect(value_ptr(buffer), offset);
	}

	void
		draw_instanced(
			_HW_3D_IN_ Uint count,
			_HW_3D_IN_ Uint instance_count,
			_HW_3D_IN_ Uint first,
			_HW_3D_IN_ Uint first_instance
		) override {
		this->_handle->DrawInstanced(count, instance_count, first, first_instance);
	}

	void
		draw_instanced_indirect(
			_HW_3D_IN_ IBuffer* buffer,
			_HW_3D_IN_ Uint offset
		) override {
		this->_handle->DrawInstancedIndirect(value_ptr(buffer), offset);
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>
		ds_get_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>> res;

		_HW_3D_STD_ vector<ID3D11Buffer*> bufs(num_buffers, nullptr);
		this->_handle->DSGetConstantBuffers(start_slot, num_buffers, bufs.data());

		_HW_3D_STD_ for_each(bufs.begin(), bufs.end(), [&res](auto ptr) {res.emplace_back(_HW_3D_STD_ make_unique<_Buffer<true>>(ptr)); });

		return res;
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>>
		ds_get_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_samplers
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>> res;

		_HW_3D_STD_ vector<ID3D11SamplerState*> samplers(num_samplers, nullptr);
		this->_handle->DSGetSamplers(start_slot, num_samplers, samplers.data());

		_HW_3D_STD_ for_each(samplers.begin(), samplers.end(), [&res](auto ptr) { res.emplace_back(_HW_3D_STD_ make_unique<_Sampler_state<true>>(ptr)); });

		return res;
	}

	_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IDomain_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>>
		ds_get_shader(
		) override {
		_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IDomain_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>> res;

		auto&[ds, cis] = res;

		ID3D11DomainShader* p_ds = nullptr;
		Uint num = 0;
		this->_handle->DSGetShader(&p_ds, nullptr, &num);

		_HW_3D_STD_ vector<ID3D11ClassInstance*> p_cis(num, nullptr);
		this->_handle->DSGetShader(&p_ds, p_cis.data(), &num);

		ds = _HW_3D_STD_ make_unique<_Domain_shader<true>>(p_ds);
		_HW_3D_STD_ for_each(p_cis.begin(), p_cis.end(), [&cis](auto ptr) { cis.emplace_back(_HW_3D_STD_ make_unique<_Class_instance<true>>(ptr)); });

		return res;
	}


	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>>
		ds_get_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_views
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>> res;

		_HW_3D_STD_ vector<ID3D11ShaderResourceView*> views(num_views, nullptr);
		this->_handle->DSGetShaderResources(start_slot, num_views, views.data());

		_HW_3D_STD_ for_each(views.begin(), views.end(), [&res](auto ptr) {res.emplace_back(_HW_3D_STD_ make_unique<_Shader_resource_view<true>>(ptr)); });

		return res;
	}

	void
		ds_set_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& constant_buffers
		) override {
		auto buffers = values_ptr(constant_buffers);
		this->_handle->DSSetConstantBuffers(start_slot, Uint(buffers.size()), buffers.data());
	}

	void
		ds_set_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<ISampler_state*>& samplers
		) override {
		auto ss = values_ptr(samplers);
		this->_handle->DSSetSamplers(start_slot, Uint(ss.size()), ss.data());
	}

	void
		ds_set_shader(
			_HW_3D_IN_ IDomain_shader* shader,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IClass_instance*>& instances
		) override {
		auto cis = values_ptr(instances);
		this->_handle->DSSetShader(value_ptr(shader), cis.data(), Uint(cis.size()));
	}

	void
		ds_set_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IShader_resource_view*>& views
		) override {
		auto srvs = values_ptr(views);
		this->_handle->DSSetShaderResources(start_slot, Uint(srvs.size()), srvs.data());
	}

	void
		end(
			_HW_3D_IN_ IAsynchronous* async
		) override {
		this->_handle->End(value_ptr(async));
	}

	void
		execute_command_list(
			_HW_3D_IN_ ICommand_list *command_list,
			_HW_3D_IN_ Bool restore_context_state
		) override {
		this->_handle->ExecuteCommandList(value_ptr(command_list), restore_context_state);
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ICommand_list>>
		finish_command_list(
			_HW_3D_IN_ Bool restore_deferred_context_state
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ICommand_list>> res;

		auto&[r, cl] = res;

		ID3D11CommandList* p_cl = nullptr;
		r = static_cast<Result>(this->_handle->FinishCommandList(restore_deferred_context_state, &p_cl));

		cl = _HW_3D_STD_ make_unique<_Command_list<true>>(p_cl);

		return res;
	}

	void
		flush(
		) override {
		this->_handle->Flush();
	}

	void
		generate_mips(
			_HW_3D_IN_ IShader_resource_view* view
		) override {
		this->_handle->GenerateMips(value_ptr(view));
	}

	/*unused*/ Uint
		get_context_flags(
		) override {
		return this->_handle->GetContextFlags();
	}

	Result
		get_data(
			_HW_3D_IN_ IAsynchronous* aysnc,
			_HW_3D_OUT_ void* data,
			_HW_3D_IN_ Uint size,
			_HW_3D_IN_ Async_get_data_flag flags
		) override {
		return static_cast<Result>(this->_handle->GetData(value_ptr(aysnc), data, size, Async_get_data_flag::mask_type(flags)));
	}

	_HW_3D_STD_ tuple<Bool, _HW_3D_STD_ unique_ptr<IPredicate>>
		get_predication(
		) override {
		_HW_3D_STD_ tuple<Bool, _HW_3D_STD_ unique_ptr<IPredicate>> res;

		auto&[val, pred] = res;

		ID3D11Predicate* p_pred = nullptr;
		this->_handle->GetPredication(&p_pred, &val);

		pred = _HW_3D_STD_ make_unique<_Predicate<true>>(p_pred);

		return res;
	}

	Float
		get_resource_min_lod(
			_HW_3D_IN_ IResource* resource
		) override {
		return this->_handle->GetResourceMinLOD(value_ptr(resource));
	}

	Device_context_type
		get_type(
		) override {
		return (Device_context_type)(this->_handle->GetType());
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>
		gs_get_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		)  override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>> res;

		_HW_3D_STD_ vector<ID3D11Buffer*> bufs(num_buffers, nullptr);
		this->_handle->GSGetConstantBuffers(start_slot, num_buffers, bufs.data());

		_HW_3D_STD_ for_each(bufs.begin(), bufs.end(), [&res](auto ptr) {res.emplace_back(_HW_3D_STD_ make_unique<_Buffer<true>>(ptr)); });

		return res;
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>>
		gs_get_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_samplers
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>> res;

		_HW_3D_STD_ vector<ID3D11SamplerState*> samplers(num_samplers, nullptr);
		this->_handle->GSGetSamplers(start_slot, num_samplers, samplers.data());

		_HW_3D_STD_ for_each(samplers.begin(), samplers.end(), [&res](auto ptr) { res.emplace_back(_HW_3D_STD_ make_unique<_Sampler_state<true>>(ptr)); });

		return res;
	}

	_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IGeometry_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>>
		gs_get_shader(
		) override {
		_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IGeometry_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>> res;

		auto&[gs, cis] = res;

		ID3D11GeometryShader* p_gs = nullptr;
		Uint num = 0;
		this->_handle->GSGetShader(&p_gs, nullptr, &num);

		_HW_3D_STD_ vector<ID3D11ClassInstance*> p_cis(num, nullptr);
		this->_handle->GSGetShader(&p_gs, p_cis.data(), &num);

		gs = _HW_3D_STD_ make_unique<_Geometry_shader<true>>(p_gs);
		_HW_3D_STD_ for_each(p_cis.begin(), p_cis.end(), [&cis](auto ptr) { cis.emplace_back(_HW_3D_STD_ make_unique<_Class_instance<true>>(ptr)); });

		return res;
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>>
		gs_get_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_views
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>> res;

		_HW_3D_STD_ vector<ID3D11ShaderResourceView*> views(num_views, nullptr);
		this->_handle->GSGetShaderResources(start_slot, num_views, views.data());

		_HW_3D_STD_ for_each(views.begin(), views.end(), [&res](auto ptr) {res.emplace_back(_HW_3D_STD_ make_unique<_Shader_resource_view<true>>(ptr)); });

		return res;
	}

	void
		gs_set_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& constant_buffers
		) override {
		auto buffers = values_ptr(constant_buffers);
		this->_handle->GSSetConstantBuffers(start_slot, Uint(buffers.size()), buffers.data());
	}

	void
		gs_set_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<ISampler_state*>& samplers
		) override {
		auto ss = values_ptr(samplers);
		this->_handle->GSSetSamplers(start_slot, Uint(ss.size()), ss.data());
	}

	void
		gs_set_shader(
			_HW_3D_IN_ IGeometry_shader* shader,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IClass_instance*>& instances
		) override {
		auto cis = values_ptr(instances);
		this->_handle->GSSetShader(value_ptr(shader), cis.data(), Uint(cis.size()));
	}

	void
		gs_set_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IShader_resource_view*>& views
		) override {
		auto srvs = values_ptr(views);
		this->_handle->GSSetShaderResources(start_slot, Uint(srvs.size()), srvs.data());
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>
		hs_get_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>> res;

		_HW_3D_STD_ vector<ID3D11Buffer*> bufs(num_buffers, nullptr);
		this->_handle->HSGetConstantBuffers(start_slot, num_buffers, bufs.data());

		_HW_3D_STD_ for_each(bufs.begin(), bufs.end(), [&res](auto ptr) {res.emplace_back(_HW_3D_STD_ make_unique<_Buffer<true>>(ptr)); });

		return res;
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>>
		hs_get_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_samplers
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>> res;

		_HW_3D_STD_ vector<ID3D11SamplerState*> samplers(num_samplers, nullptr);
		this->_handle->HSGetSamplers(start_slot, num_samplers, samplers.data());

		_HW_3D_STD_ for_each(samplers.begin(), samplers.end(), [&res](auto ptr) { res.emplace_back(_HW_3D_STD_ make_unique<_Sampler_state<true>>(ptr)); });

		return res;
	}

	_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IHull_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>>
		hs_get_shader(
		) override {
		_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IHull_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>> res;

		auto&[hs, cis] = res;

		ID3D11HullShader* p_hs = nullptr;
		Uint num = 0;
		this->_handle->HSGetShader(&p_hs, nullptr, &num);

		_HW_3D_STD_ vector<ID3D11ClassInstance*> p_cis(num, nullptr);
		this->_handle->HSGetShader(&p_hs, p_cis.data(), &num);

		hs = _HW_3D_STD_ make_unique<_Hull_shader<true>>(p_hs);
		_HW_3D_STD_ for_each(p_cis.begin(), p_cis.end(), [&cis](auto ptr) { cis.emplace_back(_HW_3D_STD_ make_unique<_Class_instance<true>>(ptr)); });

		return res;
	}


	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>>
		hs_get_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_views
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>> res;

		_HW_3D_STD_ vector<ID3D11ShaderResourceView*> views(num_views, nullptr);
		this->_handle->HSGetShaderResources(start_slot, num_views, views.data());

		_HW_3D_STD_ for_each(views.begin(), views.end(), [&res](auto ptr) {res.emplace_back(_HW_3D_STD_ make_unique<_Shader_resource_view<true>>(ptr)); });

		return res;
	}

	void
		hs_set_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& constant_buffers
		) override {
		auto buffers = values_ptr(constant_buffers);
		this->_handle->HSSetConstantBuffers(start_slot, Uint(buffers.size()), buffers.data());
	}

	void
		hs_set_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<ISampler_state*>& samplers
		) override {
		auto ss = values_ptr(samplers);
		this->_handle->HSSetSamplers(start_slot, Uint(ss.size()), ss.data());
	}

	void
		hs_set_shader(
			_HW_3D_IN_ IHull_shader* shader,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IClass_instance*>& instances
		) override {
		auto cis = values_ptr(instances);
		this->_handle->HSSetShader(value_ptr(shader), cis.data(), Uint(cis.size()));
	}

	void
		hs_set_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IShader_resource_view*>& views
		) override {
		auto srvs = values_ptr(views);
		this->_handle->HSSetShaderResources(start_slot, Uint(srvs.size()), srvs.data());
	}


	_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IBuffer>, _HW_3D_DXGI_ Format, Uint>
		ia_get_index_buffer(
		) override {
		_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IBuffer>, _HW_3D_DXGI_ Format, Uint> res;

		auto&[buf, format, offset] = res;

		ID3D11Buffer* p_buf = nullptr;
		this->_handle->IAGetIndexBuffer(&p_buf, (DXGI_FORMAT*)&format, &offset);

		buf = _HW_3D_STD_ make_unique<_Buffer<true>>(p_buf);

		return res;
	}

	_HW_3D_STD_ unique_ptr<IInput_layout>
		ia_get_input_layout(
		) override {
		ID3D11InputLayout* p_il = nullptr;
		this->_handle->IAGetInputLayout(&p_il);

		return _HW_3D_STD_ make_unique<_Input_layout<true>>(p_il);
	}

	Primitive_topology
		ia_get_primitive_topology(
		) override {
		Primitive_topology res;
		this->_handle->IAGetPrimitiveTopology((D3D11_PRIMITIVE_TOPOLOGY *)&res);

		return res;
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IBuffer>, Uint, Uint>>
		ia_get_vertex_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IBuffer>, Uint, Uint>> res;

		_HW_3D_STD_ vector<ID3D11Buffer*> buf(num_buffers, nullptr);
		_HW_3D_STD_ vector<Uint> stride(num_buffers, 0);
		_HW_3D_STD_ vector<Uint> offset(num_buffers, 0);
		this->_handle->IAGetVertexBuffers(start_slot, num_buffers, buf.data(), stride.data(), offset.data());

		for (uint32_t i = 0; i != num_buffers; i++)
			res.emplace_back(_HW_3D_STD_ make_unique<_Buffer<true>>(buf[i]), stride[i], offset[i]);

		return res;
	}

	void
		ia_set_index_buffer(
			_HW_3D_IN_ IBuffer* index_buffer,
			_HW_3D_IN_ _HW_3D_DXGI_ Format format,
			_HW_3D_IN_ Uint offset
		) override {
		this->_handle->IASetIndexBuffer(value_ptr(index_buffer), (DXGI_FORMAT)format, offset);
	}

	void
		ia_set_input_layout(
			_HW_3D_IN_ IInput_layout* layout
		) override {
		this->_handle->IASetInputLayout(value_ptr(layout));
	}

	void
		ia_set_primitive_topology(
			_HW_3D_IN_ Primitive_topology topology
		) override {
		this->_handle->IASetPrimitiveTopology((D3D11_PRIMITIVE_TOPOLOGY)topology);
	}

	void
		ia_set_vertex_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*> buffers,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint> strides,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint> offsets
		) override {
		auto buf = values_ptr(buffers);
		this->_handle->IASetVertexBuffers(start_slot, Uint(buf.size()), buf.data(), strides.data(), offsets.data());
	}

	_HW_3D_STD_ tuple<Result, Mapped_subresource>
		map(
			_HW_3D_IN_ IResource* resource,
			_HW_3D_IN_ Uint subresource,
			_HW_3D_IN_ Map type,
			_HW_3D_IN_ Map_flag flags
		) override {
		_HW_3D_STD_ tuple<Result, Mapped_subresource> res;

		auto&[r, ms] = res;
		r = static_cast<Result>(this->_handle->Map(value_ptr(resource), subresource, (D3D11_MAP)type, Map_flag::mask_type(flags), value_ptr(ms)));

		return res;
	}

	_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IBlend_state>, _HW_3D_STD_ array<Float, 4>, Uint>
		om_get_blend_state(
		) override {
		_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IBlend_state>, _HW_3D_STD_ array<Float, 4>, Uint> res;

		auto&[bs, color, mask] = res;

		ID3D11BlendState* p_bs = nullptr;
		this->_handle->OMGetBlendState(&p_bs, color.data(), &mask);

		bs = _HW_3D_STD_ make_unique<_Blend_state<true>>(p_bs);

		return res;
	}

	_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IDepth_stencil_state>, Uint>
		om_get_depth_stencil_state(
		) override {
		_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IDepth_stencil_state>, Uint> res;

		auto&[ds, ref] = res;

		ID3D11DepthStencilState* p_ds = nullptr;
		this->_handle->OMGetDepthStencilState(&p_ds, &ref);

		ds = _HW_3D_STD_ make_unique<_Depth_stencil_state<true>>(p_ds);

		return res;
	}

	_HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IRender_target_view>>, _HW_3D_STD_ unique_ptr<IDepth_stencil_view>>
		om_get_render_targets(
			Uint num_views
		) override {
		_HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IRender_target_view>>, _HW_3D_STD_ unique_ptr<IDepth_stencil_view>> res;

		auto&[rtvs, dsv] = res;
		_HW_3D_STD_ vector<ID3D11RenderTargetView*> p_rtvs(num_views, nullptr);
		ID3D11DepthStencilView* p_dsv = nullptr;

		this->_handle->OMGetRenderTargets(num_views, p_rtvs.data(), &p_dsv);

		dsv = _HW_3D_STD_ make_unique<_Depth_stencil_view<true>>(p_dsv);
		_HW_3D_STD_ for_each(p_rtvs.begin(), p_rtvs.end(), [&rtvs](auto ptr) {rtvs.emplace_back(_HW_3D_STD_ make_unique<_Render_target_view<true>>(ptr)); });

		return res;
	}

	_HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IRender_target_view>>, _HW_3D_STD_ unique_ptr<IDepth_stencil_view>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IUnordered_access_view>>>
		om_get_render_targets_and_unordered_access_views(
			_HW_3D_IN_ Uint num_rtvs,
			_HW_3D_IN_ Uint uav_start_slot,
			_HW_3D_IN_ Uint num_uavs
		) override {
		_HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IRender_target_view>>, _HW_3D_STD_ unique_ptr<IDepth_stencil_view>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IUnordered_access_view>>> res;

		auto&[rtvs, dsv, uavs] = res;
		_HW_3D_STD_ vector<ID3D11RenderTargetView*> raw_rtvs(num_rtvs, nullptr);
		ID3D11DepthStencilView* raw_dsv = nullptr;
		_HW_3D_STD_ vector<ID3D11UnorderedAccessView*> raw_uavs(num_uavs, nullptr);

		this->_handle->OMGetRenderTargetsAndUnorderedAccessViews(num_rtvs, raw_rtvs.data(), &raw_dsv, uav_start_slot, num_uavs, raw_uavs.data());

		dsv = _HW_3D_STD_ make_unique<_Depth_stencil_view<true>>(raw_dsv);
		_HW_3D_STD_ for_each(raw_rtvs.begin(), raw_rtvs.end(), [&rtvs](auto ptr) {rtvs.emplace_back(_HW_3D_STD_ make_unique<_Render_target_view<true>>(ptr)); });
		_HW_3D_STD_ for_each(raw_uavs.begin(), raw_uavs.end(), [&uavs](auto ptr) {uavs.emplace_back(_HW_3D_STD_ make_unique<_Unordered_access_view<true>>(ptr)); });

		return res;
	}

	void
		om_set_blend_state(
			_HW_3D_IN_ IBlend_state* state,
			_HW_3D_IN_ const _HW_3D_STD_ array<Float, 4>& blend_color,
			_HW_3D_IN_ Uint sample_mask
		) override {
		this->_handle->OMSetBlendState(value_ptr(state), blend_color.data(), sample_mask);
	}

	void
		om_set_depth_stencil_state(
			_HW_3D_IN_ IDepth_stencil_state* state,
			_HW_3D_IN_ Uint stencil_ref
		) override {
		this->_handle->OMSetDepthStencilState(value_ptr(state), stencil_ref);
	}

	void
		om_set_render_targets(
			_HW_3D_IN_ const _HW_3D_STD_ vector<IRender_target_view*>& rtvs,
			_HW_3D_IN_ IDepth_stencil_view* dsv
		) override {
		auto raw_rtvs = values_ptr(rtvs);
		this->_handle->OMSetRenderTargets(Uint(raw_rtvs.size()), raw_rtvs.data(), value_ptr(dsv));
	}

	void
		om_set_render_targets_and_unordered_access_views(
			_HW_3D_IN_ const _HW_3D_STD_ vector<IRender_target_view*>& rtvs,
			_HW_3D_IN_ IDepth_stencil_view* dsv,
			_HW_3D_IN_ Uint uav_start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IUnordered_access_view*>& uavs,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& uav_init_count
		) override {
		auto raw_rtvs = values_ptr(rtvs);
		auto raw_uavs = values_ptr(uavs);

		this->_handle->OMSetRenderTargetsAndUnorderedAccessViews(
			Uint(raw_rtvs.size()),
			raw_rtvs.data(),
			value_ptr(dsv),
			uav_start_slot,
			Uint(raw_uavs.size()),
			raw_uavs.data(),
			uav_init_count.data()
		);
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>
		ps_get_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>> res;

		_HW_3D_STD_ vector<ID3D11Buffer*> bufs(num_buffers, nullptr);
		this->_handle->PSGetConstantBuffers(start_slot, num_buffers, bufs.data());

		_HW_3D_STD_ for_each(bufs.begin(), bufs.end(), [&res](auto ptr) {res.emplace_back(_HW_3D_STD_ make_unique<_Buffer<true>>(ptr)); });

		return res;
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>>
		ps_get_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_samplers
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>> res;

		_HW_3D_STD_ vector<ID3D11SamplerState*> samplers(num_samplers, nullptr);
		this->_handle->PSGetSamplers(start_slot, num_samplers, samplers.data());

		_HW_3D_STD_ for_each(samplers.begin(), samplers.end(), [&res](auto ptr) { res.emplace_back(_HW_3D_STD_ make_unique<_Sampler_state<true>>(ptr)); });

		return res;
	}

	_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IPixel_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>>
		ps_get_shader(
		) override {
		_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IPixel_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>> res;

		auto&[ps, cis] = res;
		ID3D11PixelShader* p_ps = nullptr;
		Uint num = 0;
		this->_handle->PSGetShader(&p_ps, nullptr, &num);

		_HW_3D_STD_ vector<ID3D11ClassInstance*> p_cis(num, nullptr);
		this->_handle->PSGetShader(&p_ps, p_cis.data(), &num);

		ps = _HW_3D_STD_ make_unique<_Pixel_shader<true>>(p_ps);
		_HW_3D_STD_ for_each(p_cis.begin(), p_cis.end(), [&cis](auto ptr) { cis.emplace_back(_HW_3D_STD_ make_unique<_Class_instance<true>>(ptr)); });

		return res;
	}


	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>>
		ps_get_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_views
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>> res;

		_HW_3D_STD_ vector<ID3D11ShaderResourceView*> views(num_views, nullptr);
		this->_handle->PSGetShaderResources(start_slot, num_views, views.data());

		_HW_3D_STD_ for_each(views.begin(), views.end(), [&res](auto ptr) {res.emplace_back(_HW_3D_STD_ make_unique<_Shader_resource_view<true>>(ptr)); });

		return res;
	}

	void
		ps_set_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& constant_buffers
		)  override {
		auto buffers = values_ptr(constant_buffers);
		this->_handle->PSSetConstantBuffers(start_slot, Uint(buffers.size()), buffers.data());
	}


	void
		ps_set_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<ISampler_state*>& samplers
		) override {
		auto ss = values_ptr(samplers);
		this->_handle->PSSetSamplers(start_slot, Uint(ss.size()), ss.data());
	}

	void
		ps_set_shader(
			_HW_3D_IN_ IPixel_shader* shader,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IClass_instance*>& instances
		) override {
		auto cis = values_ptr(instances);
		this->_handle->PSSetShader(value_ptr(shader), cis.data(), Uint(cis.size()));
	}

	void
		ps_set_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IShader_resource_view*>& views
		) override {
		auto srvs = values_ptr(views);
		this->_handle->CSSetShaderResources(start_slot, Uint(srvs.size()), srvs.data());
	}

	void
		resolve_subresource(
			_HW_3D_IN_ IResource* dst,
			_HW_3D_IN_ Uint dst_subresource,
			_HW_3D_IN_ IResource* src,
			_HW_3D_IN_ Uint src_subresource,
			_HW_3D_IN_ _HW_3D_DXGI_ Format format
		) override {
		this->_handle->ResolveSubresource(
			value_ptr(dst),
			dst_subresource,
			value_ptr(src),
			src_subresource,
			(DXGI_FORMAT)format
		);
	}

	_HW_3D_STD_ vector<Rect>
		rs_get_scissor_rects(
		) override {
		_HW_3D_STD_ vector<Rect> res;

		Uint num_rect = 0;
		this->_handle->RSGetScissorRects(&num_rect, nullptr);

		res.resize(num_rect);
		this->_handle->RSGetScissorRects(&num_rect, (D3D11_RECT *)(res.data()));

		return res;
	}

	_HW_3D_STD_ unique_ptr<IRasterizer_state>
		rs_get_state(
		) override {
		ID3D11RasterizerState* rs = nullptr;
		this->_handle->RSGetState(&rs);

		return _HW_3D_STD_ make_unique<_Rasterizer_state<true>>(rs);
	}

	_HW_3D_STD_ vector<Viewport>
		rs_get_viewports(
		) override {
		_HW_3D_STD_ vector<Viewport> res;

		Uint num_vp = 0;
		this->_handle->RSGetViewports(&num_vp, nullptr);

		res.resize(num_vp);
		this->_handle->RSGetViewports(&num_vp, (D3D11_VIEWPORT *)(res.data()));

		return res;
	}

	void
		rs_set_scissor_rects(
			_HW_3D_IN_ const _HW_3D_STD_ vector<Rect>& rects
		) override {
		this->_handle->RSSetScissorRects(Uint(rects.size()), (const D3D11_RECT *)(rects.size()));
	}

	void
		rs_set_state(
			_HW_3D_IN_ IRasterizer_state* state
		) override {
		this->_handle->RSSetState(value_ptr(state));
	}

	void
		rs_set_viewports(
			_HW_3D_IN_ const _HW_3D_STD_ vector<Viewport>& viewports
		) override {
		this->_handle->RSSetViewports(Uint(viewports.size()), (const D3D11_VIEWPORT *)(viewports.data()));
	}

	void
		set_predication(
			_HW_3D_IN_ IPredicate* predicate,
			_HW_3D_IN_ Bool value
		) override {
		this->_handle->SetPredication(value_ptr(predicate), value);
	}

	void
		set_resource_min_lod(
			_HW_3D_IN_ IResource* resource,
			_HW_3D_IN_ Float min_lod
		) override {
		this->_handle->SetResourceMinLOD(value_ptr(resource), min_lod);
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>
		so_get_targets(
			_HW_3D_IN_ Uint num_buffers
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>> res;

		_HW_3D_STD_ vector<ID3D11Buffer*> raw_bufs(num_buffers, nullptr);

		this->_handle->SOGetTargets(num_buffers, raw_bufs.data());

		_HW_3D_STD_ for_each(raw_bufs.begin(), raw_bufs.end(), [&res](auto ptr) {res.emplace_back(_HW_3D_STD_ make_unique<_Buffer<true>>(ptr)); });

		return res;
	}

	void
		so_set_targets(
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& buffers,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& offset
		) override {
		assert(buffers.size() == offset.size());

		auto raw_bufs = values_ptr(buffers);

		this->_handle->SOSetTargets(Uint(buffers.size()), raw_bufs.data(), offset.data());
	}

	void
		unmap(
			_HW_3D_IN_ IResource* resource,
			_HW_3D_IN_ Uint subresouce
		) override {
		this->_handle->Unmap(value_ptr(resource), subresouce);
	}

	void
		update_subresource(
			_HW_3D_IN_ IResource* dst,
			_HW_3D_IN_ Uint subresource,
			_HW_3D_IN_ const Box* box,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ Uint src_row_pitch,
			_HW_3D_IN_ Uint src_depth_pitch
		) override {
		this->_handle->UpdateSubresource(
			value_ptr(dst),
			subresource,
			value_ptr(box),
			data,
			src_row_pitch,
			src_depth_pitch
		);
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>
		vs_get_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		)  override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>> res;

		_HW_3D_STD_ vector<ID3D11Buffer*> bufs(num_buffers, nullptr);
		this->_handle->VSGetConstantBuffers(start_slot, num_buffers, bufs.data());

		_HW_3D_STD_ for_each(bufs.begin(), bufs.end(), [&res](auto ptr) {res.emplace_back(_HW_3D_STD_ make_unique<_Buffer<true>>(ptr)); });

		return res;
	}

	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>>
		vs_get_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_samplers
		) override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<ISampler_state>> res;

		_HW_3D_STD_ vector<ID3D11SamplerState*> samplers(num_samplers, nullptr);
		this->_handle->VSGetSamplers(start_slot, num_samplers, samplers.data());

		_HW_3D_STD_ for_each(samplers.begin(), samplers.end(), [&res](auto ptr) { res.emplace_back(_HW_3D_STD_ make_unique<_Sampler_state<true>>(ptr)); });

		return res;
	}

	_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IVertex_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>>
		vs_get_shader(
		) override {
		_HW_3D_STD_ tuple<_HW_3D_STD_ unique_ptr<IVertex_shader>, _HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IClass_instance>>> res;

		auto&[vs, cis] = res;

		ID3D11VertexShader* p_vs = nullptr;
		Uint num = 0;
		this->_handle->VSGetShader(&p_vs, nullptr, &num);

		_HW_3D_STD_ vector<ID3D11ClassInstance*> p_cis(num, nullptr);
		this->_handle->VSGetShader(&p_vs, p_cis.data(), &num);

		vs = _HW_3D_STD_ make_unique<_Vertex_shader<true>>(p_vs);
		_HW_3D_STD_ for_each(p_cis.begin(), p_cis.end(), [&cis](auto ptr) { cis.emplace_back(_HW_3D_STD_ make_unique<_Class_instance<true>>(ptr)); });

		return res;
	}


	_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>>
		vs_get_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_views
		)  override {
		_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IShader_resource_view>> res;

		_HW_3D_STD_ vector<ID3D11ShaderResourceView*> views(num_views, nullptr);
		this->_handle->VSGetShaderResources(start_slot, num_views, views.data());

		_HW_3D_STD_ for_each(views.begin(), views.end(), [&res](auto ptr) {res.emplace_back(_HW_3D_STD_ make_unique<_Shader_resource_view<true>>(ptr)); });

		return res;
	}

	void
		vs_set_constant_buffers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& constant_buffers
		) override {
		auto buffers = values_ptr(constant_buffers);
		this->_handle->VSSetConstantBuffers(start_slot, Uint(buffers.size()), buffers.data());
	}

	void
		vs_set_samplers(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<ISampler_state*>& samplers
		) override {
		auto ss = values_ptr(samplers);
		this->_handle->VSSetSamplers(start_slot, Uint(ss.size()), ss.data());
	}

	void
		vs_set_shader(
			_HW_3D_IN_ IVertex_shader* shader,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IClass_instance*>& instances
		) override {
		auto cis = values_ptr(instances);
		this->_handle->VSSetShader(value_ptr(shader), cis.data(), Uint(cis.size()));
	}

	void
		vs_set_shader_resources(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IShader_resource_view*>& views
		) override {
		auto srvs = values_ptr(views);
		this->_handle->VSSetShaderResources(start_slot, Uint(srvs.size()), srvs.data());
	}

	virtual ~_TDevice_context() {}
};

//
//
template <bool own>
class _Device_context : public _TDevice_context<IDevice_context, ID3D11DeviceContext, own> {
public:
	explicit _Device_context(ID3D11DeviceContext* handle)
		: _TDevice_context<IDevice_context, ID3D11DeviceContext, own>(handle) {

	}

	ID3D11DeviceContext* get() override {
		return this->_handle;
	}

	const ID3D11DeviceContext* get() const override {
		return this->_handle;
	}

	virtual ~_Device_context() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice_context1 : public _TDevice_context<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice_context1, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11DeviceContext1, Ty>);
public:
	explicit _TDevice_context1(Ty* handle)
		: _TDevice_context<Interface, Ty, own>(handle) {

	}

	void
		clear_view(
			_HW_3D_IN_ IView* view,
			_HW_3D_IN_ const _HW_3D_STD_ array<Float, 4>& color,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Rect>& rects
		) override {
		this->_handle->ClearView(value_ptr(view), color.data(), (const D3D11_RECT*)(rects.data()), Uint(rects.size()));
	}

	void
		copy_subresource_region1(
			_HW_3D_IN_ IResource* dst,
			_HW_3D_IN_ Uint dst_subresource,
			_HW_3D_IN_ _HW_3D_STD_ array<Uint, 3> offset,
			_HW_3D_IN_ IResource* src,
			_HW_3D_IN_ Uint src_subresource,
			_HW_3D_IN_ const Box* box,
			_HW_3D_IN_ Copy_flag flags
		) override {
		this->_handle->CopySubresourceRegion1(
			value_ptr(dst),
			dst_subresource,
			offset[0],
			offset[1],
			offset[2],
			value_ptr(src),
			src_subresource,
			value_ptr(box),
			Copy_flag::mask_type(flags)
		);
	}

	_HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>>
		cs_get_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) override {
		_HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>> res;

		auto&[buffers, first, n_bufs] = res;

		first.resize(num_buffers);
		n_bufs.resize(num_buffers);
		_HW_3D_STD_ vector<ID3D11Buffer*> raw_buffers(num_buffers, nullptr);
		this->_handle->CSGetConstantBuffers1(start_slot, num_buffers, raw_buffers.data(), first.data(), n_bufs.data());

		_HW_3D_STD_ for_each(raw_buffers.begin(), raw_buffers.end(), [&buffers](auto ptr) {buffers.emplace_back(_HW_3D_STD_ make_unique<_Buffer<true>>(ptr)); });

		return res;
	}

	void
		cs_set_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& buffers,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& first_constant,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& num_constant
		) override {
		auto raw_buffers = values_ptr(buffers);
		this->_handle->CSSetConstantBuffers1(start_slot, Uint(raw_buffers.size()), raw_buffers.data(), first_constant.data(), num_constant.data());
	}

	void
		discard_resource(
			_HW_3D_IN_ IResource* resource
		) override {
		this->_handle->DiscardResource(value_ptr(resource));
	}

	void
		discard_view(
			_HW_3D_IN_ IView* view
		) override {
		this->_handle->DiscardView(value_ptr(view));
	}

	void
		discard_view1(
			_HW_3D_IN_ IView* view,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Rect>& rects
		) override {
		this->_handle->DiscardView1(value_ptr(view), (const D3D11_RECT*)(rects.data()), Uint(rects.size()));
	}

	_HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>>
		ds_get_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) override {
		_HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>> res;

		auto&[buffers, first, n_bufs] = res;

		first.resize(num_buffers);
		n_bufs.resize(num_buffers);
		_HW_3D_STD_ vector<ID3D11Buffer*> raw_buffers(num_buffers, nullptr);
		this->_handle->DSGetConstantBuffers1(start_slot, num_buffers, raw_buffers.data(), first.data(), n_bufs.data());

		_HW_3D_STD_ for_each(raw_buffers.begin(), raw_buffers.end(), [&buffers](auto ptr) {buffers.emplace_back(_HW_3D_STD_ make_unique<_Buffer<true>>(ptr)); });

		return res;
	}

	void
		ds_set_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& buffers,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& first_constant,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& num_constant
		) override {
		auto raw_buffers = values_ptr(buffers);
		this->_handle->DSSetConstantBuffers1(start_slot, Uint(raw_buffers.size()), raw_buffers.data(), first_constant.data(), num_constant.data());
	}

	_HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>>
		gs_get_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) override {
		_HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>> res;

		auto&[buffers, first, n_bufs] = res;

		first.resize(num_buffers);
		n_bufs.resize(num_buffers);
		_HW_3D_STD_ vector<ID3D11Buffer*> raw_buffers(num_buffers, nullptr);
		this->_handle->GSGetConstantBuffers1(start_slot, num_buffers, raw_buffers.data(), first.data(), n_bufs.data());

		_HW_3D_STD_ for_each(raw_buffers.begin(), raw_buffers.end(), [&buffers](auto ptr) {buffers.emplace_back(_HW_3D_STD_ make_unique<_Buffer<true>>(ptr)); });

		return res;
	}

	void
		gs_set_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& buffers,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& first_constant,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& num_constant
		) override {
		auto raw_buffers = values_ptr(buffers);
		this->_handle->GSSetConstantBuffers1(start_slot, Uint(raw_buffers.size()), raw_buffers.data(), first_constant.data(), num_constant.data());
	}

	_HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>>
		hs_get_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) override {
		_HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>> res;

		auto&[buffers, first, n_bufs] = res;

		first.resize(num_buffers);
		n_bufs.resize(num_buffers);
		_HW_3D_STD_ vector<ID3D11Buffer*> raw_buffers(num_buffers, nullptr);
		this->_handle->HSGetConstantBuffers1(start_slot, num_buffers, raw_buffers.data(), first.data(), n_bufs.data());

		_HW_3D_STD_ for_each(raw_buffers.begin(), raw_buffers.end(), [&buffers](auto ptr) {buffers.emplace_back(_HW_3D_STD_ make_unique<_Buffer<true>>(ptr)); });

		return res;
	}

	void
		hs_set_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& buffers,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& first_constant,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& num_constant
		) override {
		auto raw_buffers = values_ptr(buffers);
		this->_handle->HSSetConstantBuffers1(start_slot, Uint(raw_buffers.size()), raw_buffers.data(), first_constant.data(), num_constant.data());
	}

	_HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>>
		ps_get_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) override {
		_HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>> res;

		auto&[buffers, first, n_bufs] = res;

		first.resize(num_buffers);
		n_bufs.resize(num_buffers);
		_HW_3D_STD_ vector<ID3D11Buffer*> raw_buffers(num_buffers, nullptr);
		this->_handle->PSGetConstantBuffers1(start_slot, num_buffers, raw_buffers.data(), first.data(), n_bufs.data());

		_HW_3D_STD_ for_each(raw_buffers.begin(), raw_buffers.end(), [&buffers](auto ptr) {buffers.emplace_back(_HW_3D_STD_ make_unique<_Buffer<true>>(ptr)); });

		return res;
	}

	void
		ps_set_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& buffers,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& first_constant,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& num_constant
		) override {
		auto raw_buffers = values_ptr(buffers);
		this->_handle->PSSetConstantBuffers1(start_slot, Uint(raw_buffers.size()), raw_buffers.data(), first_constant.data(), num_constant.data());
	}

	_HW_3D_STD_ unique_ptr<IDevice_context_state>
		swap_device_context_state(
			_HW_3D_IN_ IDevice_context_state* state
		) override {
		ID3DDeviceContextState* pre = nullptr;
		this->_handle->SwapDeviceContextState(value_ptr(state), &pre);

		return _HW_3D_STD_ make_unique<_Device_context_state<true>>(pre);
	}

	void
		update_subresource1(
			_HW_3D_IN_ IResource* dst,
			_HW_3D_IN_ Uint dst_subresource,
			_HW_3D_IN_ const Box* box,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ Uint src_row_pitch,
			_HW_3D_IN_ Uint src_depth_pitch,
			_HW_3D_IN_ Copy_flag flags
		) override {
		this->_handle->UpdateSubresource1(
			value_ptr(dst),
			dst_subresource,
			value_ptr(box),
			data,
			src_row_pitch,
			src_depth_pitch,
			Copy_flag::mask_type(flags)
		);
	}

	_HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>>
		vs_get_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ Uint num_buffers
		) override {
		_HW_3D_STD_ tuple<_HW_3D_STD_ vector<_HW_3D_STD_ unique_ptr<IBuffer>>, _HW_3D_STD_ vector<Uint>, _HW_3D_STD_ vector<Uint>> res;

		auto&[buffers, first, n_bufs] = res;

		first.resize(num_buffers);
		n_bufs.resize(num_buffers);
		_HW_3D_STD_ vector<ID3D11Buffer*> raw_buffers(num_buffers, nullptr);
		this->_handle->VSGetConstantBuffers1(start_slot, num_buffers, raw_buffers.data(), first.data(), n_bufs.data());

		_HW_3D_STD_ for_each(raw_buffers.begin(), raw_buffers.end(), [&buffers](auto ptr) {buffers.emplace_back(_HW_3D_STD_ make_unique<_Buffer<true>>(ptr)); });

		return res;
	}

	void
		vs_set_constant_buffers1(
			_HW_3D_IN_ Uint start_slot,
			_HW_3D_IN_ const _HW_3D_STD_ vector<IBuffer*>& buffers,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& first_constant,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& num_constant
		) override {
		auto raw_buffers = values_ptr(buffers);
		this->_handle->VSSetConstantBuffers1(start_slot, Uint(raw_buffers.size()), raw_buffers.data(), first_constant.data(), num_constant.data());
	}

	virtual ~_TDevice_context1() {}
};

//
//
template <bool own>
class _Device_context1 : public _TDevice_context1<IDevice_context1, ID3D11DeviceContext1, own> {
public:
	explicit _Device_context1(ID3D11DeviceContext1* handle)
		: _TDevice_context1<IDevice_context1, ID3D11DeviceContext1, own>(handle) {

	}

	ID3D11DeviceContext1* get() override {
		return this->_handle;
	}

	const ID3D11DeviceContext1* get() const override {
		return this->_handle;
	}

	~_Device_context1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice_context2 : public _TDevice_context1<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice_context2, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11DeviceContext2, Ty>);
public:
	explicit _TDevice_context2(Ty* handle)
		: _TDevice_context1<Interface, Ty, own>(handle) {

	}

	void
		update_tiles(
			_HW_3D_IN_ IResource* dst,
			_HW_3D_IN_ const Tiled_resource_coordinate& resource_coordinate,
			_HW_3D_IN_ const Tile_region_size& size,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ Tile_copy_flag flags
		) override {
		this->_handle->UpdateTiles(value_ptr(dst), value_ptr(resource_coordinate), value_ptr(size), data, Tile_copy_flag::mask_type(flags));
	}

	void
		begin_event_int(
			_HW_3D_IN_ const _HW_3D_STD_ wstring& label,
			_HW_3D_IN_ Int data
		) override {
		this->_handle->BeginEventInt(label.c_str(), data);
	}

	Result
		copy_tile_mapping(
			_HW_3D_IN_ IResource* dst,
			_HW_3D_IN_ const Tiled_resource_coordinate& dst_coord,
			_HW_3D_IN_ IResource* src,
			_HW_3D_IN_ const Tiled_resource_coordinate& src_coord,
			_HW_3D_IN_ const Tile_region_size& size,
			_HW_3D_IN_ Tile_mapping_flag flags
		) override {
		return static_cast<Result>(this->_handle->CopyTileMappings(
			value_ptr(dst),
			value_ptr(dst_coord),
			value_ptr(src),
			value_ptr(src_coord),
			value_ptr(size),
			Tile_mapping_flag::mask_type(flags)
		));
	}

	void
		copy_tiles(
			_HW_3D_IN_ IResource* resouce,
			_HW_3D_IN_ const Tiled_resource_coordinate& region_coord,
			_HW_3D_IN_ const Tile_region_size& size,
			_HW_3D_IN_ IBuffer* buffer,
			_HW_3D_IN_ Uint64 offset,
			_HW_3D_IN_ Tile_copy_flag flags
		) override {
		this->_handle->CopyTiles(
			value_ptr(resouce),
			value_ptr(region_coord),
			value_ptr(size),
			value_ptr(buffer),
			offset,
			Tile_copy_flag::mask_type(flags)
		);
	}

	void
		end_event(
		) override {
		this->_handle->EndEvent();
	}

	Bool
		is_annotation_enabled(
		) override {
		return this->_handle->IsAnnotationEnabled();
	}

	Result
		resize_tile_pool(
			_HW_3D_IN_ IBuffer* pool,
			_HW_3D_IN_ Uint64 size
		) override {
		return static_cast<Result>(this->_handle->ResizeTilePool(value_ptr(pool), size));
	}

	void
		set_marker_int(
			_HW_3D_IN_ const _HW_3D_STD_ wstring& label,
			_HW_3D_IN_ Int data
		) override {
		this->_handle->SetMarkerInt(label.c_str(), data);
	}

	void
		tiled_resource_barrier(
			_HW_3D_IN_ IDevice_child* before,
			_HW_3D_IN_ IDevice_child* after
		) override {
		this->_handle->TiledResourceBarrier(value_ptr(before), value_ptr(after));
	}

	Result
		update_tile_mappings(
			_HW_3D_IN_ IResource* reource,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Tiled_resource_coordinate>& coords,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Tile_region_size>& sizes,
			_HW_3D_IN_ IBuffer* pool,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Tile_range_flag>& range_flags,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& range_offset,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Uint>& tile_counts,
			_HW_3D_IN_ Tile_mapping_flag flags
		) override {
		return static_cast<Result>(this->_handle->UpdateTileMappings(
			value_ptr(reource),
			Uint(coords.size()),
			(const D3D11_TILED_RESOURCE_COORDINATE *)(coords.data()),
			(const D3D11_TILE_REGION_SIZE *)(sizes.data()),
			value_ptr(pool),
			Uint(range_flags.size()),
			(const Uint*)(range_flags.data()),
			range_offset.data(),
			tile_counts.data(),
			Tile_mapping_flag::mask_type(flags)
		));
	}

	virtual ~_TDevice_context2() {}
};

//
//
template <bool own>
class _Device_context2 : public _TDevice_context2<IDevice_context2, ID3D11DeviceContext2, own> {
public:
	explicit _Device_context2(ID3D11DeviceContext2* handle)
		: _TDevice_context2<IDevice_context2, ID3D11DeviceContext2, own>(handle) {

	}

	ID3D11DeviceContext2* get() override {
		return this->_handle;
	}

	const ID3D11DeviceContext2* get() const override {
		return this->_handle;
	}

	~_Device_context2() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice_context3 : public _TDevice_context2<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice_context3, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11DeviceContext3, Ty>);
public:
	explicit _TDevice_context3(Ty* handle)
		: _TDevice_context2<Interface, Ty, own>(handle) {

	}

	void
		flush1(
			_HW_3D_IN_ Context_type type,
			_HW_3D_IN_ HANDLE h_event
		) override {
		this->_handle->Flush1((D3D11_CONTEXT_TYPE)(type), h_event);
	}

	Bool
		get_hardware_protection_state(
		) override {
		Bool protection_enable{ False };
		this->_handle->GetHardwareProtectionState(&protection_enable);

		return protection_enable;
	}

	void
		set_hardware_protection_state(
			Bool enabled
		) override {
		this->_handle->SetHardwareProtectionState(enabled);
	}

	virtual ~_TDevice_context3() {}
};

//
//
template <bool own>
class _Device_context3 : public _TDevice_context3<IDevice_context3, ID3D11DeviceContext3, own> {
public:
	explicit _Device_context3(ID3D11DeviceContext3* handle)
		: _TDevice_context3<IDevice_context3, ID3D11DeviceContext3, own>(handle) {

	}

	ID3D11DeviceContext3* get() override {
		return this->_handle;
	}

	const ID3D11DeviceContext3* get() const override {
		return this->_handle;
	}

	~_Device_context3() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice_context4 : public _TDevice_context3<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice_context4, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11DeviceContext4, Ty>);
public:
	explicit _TDevice_context4(Ty* handle)
		: _TDevice_context3<Interface, Ty, own>(handle) {

	}

	Result
		signal(
			_HW_3D_IN_ IFence* fence,
			Uint64 value
		) override {
		return static_cast<Result>(this->_handle->Signal(value_ptr(fence), value));
	}

	Result
		wait(
			_HW_3D_IN_ IFence* fence,
			Uint64 value
		) override {
		return static_cast<Result>(this->_handle->Wait(value_ptr(fence), value));
	}

	virtual ~_TDevice_context4() {}
};

//
//
template <bool own>
class _Device_context4 : public _TDevice_context4<IDevice_context4, ID3D11DeviceContext4, own> {
public:
	explicit _Device_context4(ID3D11DeviceContext4* handle)
		: _TDevice_context4<IDevice_context4, ID3D11DeviceContext4, own>(handle) {

	}

	ID3D11DeviceContext4* get() override {
		return this->_handle;
	}

	const ID3D11DeviceContext4* get() const override {
		return this->_handle;
	}

	~_Device_context4() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice1 : public _TDevice<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice1, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Device1, Ty>);
public:
	explicit _TDevice1(Ty* handle)
		: _TDevice<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBlend_state1>>
		create_blend_state1(
			_HW_3D_IN_ const Blend_desc1& desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IBlend_state1>> res;

		auto&[r, bs] = res;

		ID3D11BlendState1* raw_bs = nullptr;
		r = static_cast<Result>(this->_handle->CreateBlendState1(value_ptr(desc), &raw_bs));

		bs = _HW_3D_STD_ make_unique<_Blend_state1<true>>(raw_bs);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDevice_context1>>
		create_deferred_context1(
			/*unused*/ Uint flags
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDevice_context1>> res;

		auto&[r, dc1] = res;

		ID3D11DeviceContext1* raw_dc1 = nullptr;
		r = static_cast<Result>(this->_handle->CreateDeferredContext1(flags, &raw_dc1));

		dc1 = _HW_3D_STD_ make_unique<_Device_context1<true>>(raw_dc1);

		return res;
	}

	_HW_3D_STD_ tuple<Result, Feature_level, _HW_3D_STD_ unique_ptr<IDevice_context_state>>
		create_device_context_state(
			_HW_3D_IN_ Create_device_context_state_flag flags,
			_HW_3D_IN_ const _HW_3D_STD_ vector<Feature_level>& feature_levels,
			_HW_3D_IN_ Uint sdk_version,
			_HW_3D_IN_ REFIID enumlated_interface
		) override {
		_HW_3D_STD_ tuple<Result, Feature_level, _HW_3D_STD_ unique_ptr<IDevice_context_state>> res;

		auto&[r, flev, dcs] = res;

		ID3DDeviceContextState* raw_dcs = nullptr;
		r = static_cast<Result>(this->_handle->CreateDeviceContextState(
			Create_device_context_state_flag::mask_type(flags),
			(const D3D_FEATURE_LEVEL *)(feature_levels.data()),
			Uint(feature_levels.size()),
			sdk_version,
			enumlated_interface,
			(D3D_FEATURE_LEVEL *)&flev,
			&raw_dcs
		));

		dcs = _HW_3D_STD_ make_unique<_Device_context_state<true>>(raw_dcs);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IRasterizer_state1>>
		create_rasterizer_state1(
			_HW_3D_IN_ const Rasterizer_desc1& desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IRasterizer_state1>> res;

		auto&[r, rs1] = res;

		ID3D11RasterizerState1* raw_rs1 = nullptr;
		r = static_cast<Result>(this->_handle->CreateRasterizerState1(value_ptr(desc), &raw_rs1));

		rs1 = _HW_3D_STD_ make_unique<_Rasterizer_state1<true>>(raw_rs1);

		return res;
	}

	_HW_3D_STD_ unique_ptr<IDevice_context1>
		get_immediate_context1(
		) override {
		ID3D11DeviceContext1* p_ic1 = nullptr;
		this->_handle->GetImmediateContext1(&p_ic1);

		return _HW_3D_STD_ make_unique<_Device_context1<true>>(p_ic1);
	}

	_HW_3D_STD_ tuple<Result, void*>
		open_shared_resource1(
			_HW_3D_IN_ HANDLE h_resource,
			_HW_3D_IN_ REFIID returned_interface
		) override {
		_HW_3D_STD_ tuple<Result, void*> res;

		auto&[r, p_resource] = res;
		r = static_cast<Result>(this->_handle->OpenSharedResource1(h_resource, returned_interface, &p_resource));

		return res;
	}

	_HW_3D_STD_ tuple<Result, void*>
		open_shared_resource_by_name(
			_HW_3D_IN_ const _HW_3D_STD_ wstring& name,
			_HW_3D_IN_ DWORD desired_access,
			_HW_3D_IN_ REFIID returned_interface
		) override {
		_HW_3D_STD_ tuple<Result, void*> res;

		auto&[r, p_resource] = res;
		r = static_cast<Result>(this->_handle->OpenSharedResourceByName(name.c_str(), desired_access, returned_interface, &p_resource));

		return res;
	}

	virtual ~_TDevice1() {}
};

//
//
template <bool own>
class _Device1 : public _TDevice1<IDevice1, ID3D11Device1, own> {
public:
	explicit _Device1(ID3D11Device1* handle)
		: _TDevice1<IDevice1, ID3D11Device1, own>(handle) {

	}

	ID3D11Device1* get() override {
		return this->_handle;
	}

	const ID3D11Device1* get() const override {
		return this->_handle;
	}

	~_Device1() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice2 : public _TDevice1<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice2, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Device2, Ty>);
public:
	explicit _TDevice2(Ty* handle)
		: _TDevice1<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, Uint>
		check_multisample_quality_levels1(
			_HW_3D_IN_ _HW_3D_DXGI_ Format format,
			_HW_3D_IN_ Uint sample_count,
			_HW_3D_IN_ Check_multisample_quality_levels_flag flags
		) override {
		_HW_3D_STD_ tuple<Result, Uint> res;

		auto&[r, num] = res;

		r = static_cast<Result>(this->_handle->CheckMultisampleQualityLevels1((DXGI_FORMAT)format, sample_count, Check_multisample_quality_levels_flag::mask_type(flags), &num));

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDevice_context2>>
		create_deferred_context2(
			/*unused */ Uint flags
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDevice_context2>> res;

		auto&[r, dc2] = res;

		ID3D11DeviceContext2* raw_dc2 = nullptr;
		r = static_cast<Result>(this->_handle->CreateDeferredContext2(flags, &raw_dc2));

		dc2 = _HW_3D_STD_ make_unique<_Device_context2<true>>(raw_dc2);

		return res;
	}

	_HW_3D_STD_ unique_ptr<IDevice_context2>
		get_immediate_context2(
		) override {
		ID3D11DeviceContext2* raw_dc2 = nullptr;
		this->_handle->GetImmediateContext2(&raw_dc2);

		return _HW_3D_STD_ make_unique<_Device_context2<true>>(raw_dc2);
	}

	Subresource_tiling
		get_resource_tiling(
			_HW_3D_IN_ IResource* resource,
			_HW_3D_OUT_ Uint* num_tiles,
			_HW_3D_OUT_ Packed_mip_desc* packed_mip_desc,
			_HW_3D_OUT_ Tile_shape* shape_for_non_packed_mips,
			_HW_3D_IN_OUT_ Uint* num_subresource_tilings,
			_HW_3D_IN_ Uint first_subresource_tilling
		) override {
		Subresource_tiling res;

		this->_handle->GetResourceTiling(
			value_ptr(resource),
			num_tiles,
			value_ptr(packed_mip_desc),
			value_ptr(shape_for_non_packed_mips),
			num_subresource_tilings,
			first_subresource_tilling,
			value_ptr(res)
		);

		return res;
	}

	virtual ~_TDevice2() {}
};

//
//
template <bool own>
class _Device2 : public _TDevice2<IDevice2, ID3D11Device2, own> {
public:
	explicit _Device2(ID3D11Device2* handle)
		: _TDevice2<IDevice2, ID3D11Device2, own>(handle) {

	}

	ID3D11Device2* get() override {
		return this->_handle;
	}

	const ID3D11Device2* get() const override {
		return this->_handle;
	}

	~_Device2() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice3 : public _TDevice2<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice3, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Device3, Ty>);
public:
	explicit _TDevice3(Ty* handle)
		: _TDevice2<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDevice_context3>>
		create_deferred_context3(
			/*unused*/ Uint flags = 0
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IDevice_context3>> res;

		auto&[r, dc3] = res;

		ID3D11DeviceContext3* raw_dc3 = nullptr;
		r = static_cast<Result>(this->_handle->CreateDeferredContext3(flags, &raw_dc3));

		dc3 = _HW_3D_STD_ make_unique<_Device_context3<true>>(raw_dc3);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IQuery1>>
		create_query1(
			_HW_3D_IN_ const Query_desc1& desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IQuery1>> res;

		auto&[r, q] = res;

		ID3D11Query1* p_q = nullptr;
		r = static_cast<Result>(this->_handle->CreateQuery1(value_ptr(desc), &p_q));

		q = _HW_3D_STD_ make_unique<_Query1<true>>(p_q);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IRasterizer_state2>>
		create_rasterizer_state2(
			_HW_3D_IN_ const Rasterizer_desc2& desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IRasterizer_state2>> res;

		auto&[r, rs2] = res;

		ID3D11RasterizerState2* raw_rs2 = nullptr;
		r = static_cast<Result>(this->_handle->CreateRasterizerState2(value_ptr(desc), &raw_rs2));

		rs2 = _HW_3D_STD_ make_unique<_Rasterizer_state2<true>>(raw_rs2);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IRender_target_view1>>
		create_render_target_view1(
			_HW_3D_IN_ IResource* resource,
			_HW_3D_IN_ const Render_target_view_desc1& desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IRender_target_view1>> res;

		auto&[r, rtv] = res;

		ID3D11RenderTargetView1* p_rtv = nullptr;
		r = static_cast<Result>(this->_handle->CreateRenderTargetView1(value_ptr(resource), value_ptr(desc), &p_rtv));

		rtv = _HW_3D_STD_ make_unique<_Render_target_view1<true>>(p_rtv);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IShader_resource_view1>>
		create_shader_resource_view1(
			_HW_3D_IN_ IResource* resource,
			_HW_3D_IN_ const Shader_resource_view_desc1& desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IShader_resource_view1>> res;

		auto&[r, srv] = res;

		ID3D11ShaderResourceView1* p_srv = nullptr;
		r = static_cast<Result>(this->_handle->CreateShaderResourceView1(value_ptr(resource), value_ptr(desc), &p_srv));

		srv = _HW_3D_STD_ make_unique<_Shader_resource_view1<true>>(p_srv);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ITexture2d1>>
		create_texture_2d1(
			_HW_3D_IN_ const Texture2d_desc1& desc,
			_HW_3D_IN_ const Subresource_data* data
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ITexture2d1>> res;

		auto&[r, t2d] = res;

		ID3D11Texture2D1* p_t2d = nullptr;
		r = static_cast<Result>(this->_handle->CreateTexture2D1(value_ptr(desc), value_ptr(data), &p_t2d));

		t2d = _HW_3D_STD_ make_unique<_Texture2d1<true>>(p_t2d);

		return res;
	}


	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ITexture3d1>>
		create_texture_3d1(
			_HW_3D_IN_ const Texture3d_desc1& desc,
			_HW_3D_IN_ const Subresource_data* data
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<ITexture3d1>> res;

		auto&[r, t3d] = res;

		ID3D11Texture3D1* p_t3d = nullptr;
		r = static_cast<Result>(this->_handle->CreateTexture3D1(value_ptr(desc), value_ptr(data), &p_t3d));

		t3d = _HW_3D_STD_ make_unique<_Texture3d1<true>>(p_t3d);

		return res;
	}


	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IUnordered_access_view1>>
		create_unordered_access_view1(
			_HW_3D_IN_ IResource* resouce,
			_HW_3D_IN_ const Unordered_access_view_desc1& desc
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IUnordered_access_view1>> res;

		auto&[r, uav] = res;

		ID3D11UnorderedAccessView1* p_uav = nullptr;
		r = static_cast<Result>(this->_handle->CreateUnorderedAccessView1(value_ptr(resouce), value_ptr(desc), &p_uav));

		uav = _HW_3D_STD_ make_unique<_Unordered_access_view1<true>>(p_uav);

		return res;
	}


	_HW_3D_STD_ unique_ptr<IDevice_context3>
		get_immediate_context3(
		) override {
		ID3D11DeviceContext3* raw_dc3 = nullptr;
		this->_handle->GetImmediateContext3(&raw_dc3);

		return _HW_3D_STD_ make_unique<_Device_context3<true>>(raw_dc3);
	}


	void
		read_from_subresource(
			_HW_3D_OUT_ void* data,
			_HW_3D_IN_ Uint row_pitch,
			_HW_3D_IN_ Uint depth_pitch,
			_HW_3D_IN_ IResource* resouce,
			_HW_3D_IN_ Uint sub_resource,
			_HW_3D_IN_ const Box* box
		) override {
		this->_handle->ReadFromSubresource(
			data,
			row_pitch,
			depth_pitch,
			value_ptr(resouce),
			sub_resource,
			value_ptr(box)
		);
	}

	void
		write_to_subresource(
			_HW_3D_IN_ IResource* resouce,
			_HW_3D_IN_ Uint subresource,
			_HW_3D_IN_ const Box* box,
			_HW_3D_IN_ const void* data,
			_HW_3D_IN_ Uint row_pitch,
			_HW_3D_IN_ Uint depth_pitch
		) override {
		this->_handle->WriteToSubresource(
			value_ptr(resouce),
			subresource,
			value_ptr(box),
			data,
			row_pitch,
			depth_pitch
		);
	}

	virtual ~_TDevice3() {}
};

//
//
template <bool own>
class _Device3 : public _TDevice3<IDevice3, ID3D11Device3, own> {
public:
	explicit _Device3(ID3D11Device3* handle)
		: _TDevice3<IDevice3, ID3D11Device3, own>(handle) {

	}

	ID3D11Device3* get() override {
		return this->_handle;
	}

	const ID3D11Device3* get() const override {
		return this->_handle;
	}

	~_Device3() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice4 : public _TDevice3<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice4, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Device4, Ty>);
public:
	explicit _TDevice4(Ty* handle)
		: _TDevice3<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, DWORD>
		register_device_removed_event(
			_HW_3D_IN_ HANDLE h_event
		) override {
		_HW_3D_STD_ tuple<Result, DWORD> res;

		auto&[r, cookie] = res;
		r = static_cast<Result>(this->_handle->RegisterDeviceRemovedEvent(h_event, &cookie));

		return res;
	}

	void
		unregister_device_removed(
			_HW_3D_IN_ DWORD cookie
		) override {
		this->_handle->UnregisterDeviceRemoved(cookie);
	}

	virtual ~_TDevice4() {}
};

//
//
template <bool own>
class _Device4 : public _TDevice4<IDevice4, ID3D11Device4, own> {
public:
	explicit _Device4(ID3D11Device4* handle)
		: _TDevice4<IDevice4, ID3D11Device4, own>(handle) {

	}

	ID3D11Device4* get() override {
		return this->_handle;
	}

	const ID3D11Device4* get() const override {
		return this->_handle;
	}

	~_Device4() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDevice5 : public _TDevice4<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDevice5, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Device5, Ty>);
public:
	explicit _TDevice5(Ty* handle)
		: _TDevice4<Interface, Ty, own>(handle) {

	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IFence>>
		create_fence(
			_HW_3D_IN_ Uint64 value,
			_HW_3D_IN_ Fence_flag flags,
			_HW_3D_IN_ REFIID riid
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IFence>> res;

		auto&[r, fence] = res;

		ID3D11Fence* raw_fence = nullptr;
		r = static_cast<Result>(this->_handle->CreateFence(value, (D3D11_FENCE_FLAG)(Fence_flag::mask_type(flags)), riid, (void**)&raw_fence));

		fence = _HW_3D_STD_ make_unique<_Fence<true>>(raw_fence);

		return res;
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IFence>>
		open_shared_fence(
			_HW_3D_IN_ HANDLE fence,
			_HW_3D_IN_ REFIID returned_interface
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<IFence>> res;

		auto&[r, f] = res;

		ID3D11Fence* raw_fence = nullptr;
		r = static_cast<Result>(this->_handle->OpenSharedFence(fence, returned_interface, (void**)&raw_fence));

		f = _HW_3D_STD_ make_unique<_Fence<true>>(raw_fence);

		return res;
	}


	virtual ~_TDevice5() {}
};

//
//
template <bool own>
class _Device5 : public _TDevice5<IDevice5, ID3D11Device5, own> {
public:
	explicit _Device5(ID3D11Device5* handle)
		: _TDevice5<IDevice5, ID3D11Device5, own>(handle) {

	}

	ID3D11Device5* get() override {
		return this->_handle;
	}

	const ID3D11Device5* get() const override {
		return this->_handle;
	}

	~_Device5() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TDebug : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IDebug, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11Debug, Ty>);
public:
	explicit _TDebug(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	Debug_feature_mask
		get_feature_mask(
		) override {
		return Debug_feature_mask_bit(this->_handle->GetFeatureMask());
	}

	Uint
		get_present_per_render_op_delay(
		) override {
		return this->_handle->GetPresentPerRenderOpDelay();
	}

	_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<_HW_3D_DXGI_ ISwap_chain>>
		get_swap_chain(
		) override {
		_HW_3D_STD_ tuple<Result, _HW_3D_STD_ unique_ptr<_HW_3D_DXGI_ ISwap_chain>> res;

		auto&[r, sc] = res;

		IDXGISwapChain* raw_sc = nullptr;
		r = static_cast<Result>(this->_handle->GetSwapChain(&raw_sc));

		sc = _HW_3D_STD_ make_unique<_HW_3D_DXGI_ _Swap_chain<true>>(raw_sc);

		return res;
	}

	Result
		report_live_device_objects(
			_HW_3D_IN_ Rldo_flag flags
		) override {
		return static_cast<Result>(this->_handle->ReportLiveDeviceObjects((D3D11_RLDO_FLAGS)(Rldo_flag::mask_type(flags))));
	}


	Result
		set_feature_mask(
			_HW_3D_IN_ Debug_feature_mask mask
		) override {
		return static_cast<Result>(this->_handle->SetFeatureMask(Debug_feature_mask::mask_type(mask)));
	}

	Result
		set_persent_per_render_op_delay(
			_HW_3D_IN_ Uint millisecnds  //not safe
		) override {
		return static_cast<Result>(this->_handle->SetPresentPerRenderOpDelay(millisecnds));
	}

	Result
		set_swap_chain(
			_HW_3D_IN_ _HW_3D_DXGI_ ISwap_chain* swap_chain
		) override {
		return static_cast<Result>(this->_handle->SetSwapChain(value_ptr(swap_chain)));
	}

	Result
		validate_context(
			_HW_3D_IN_ IDevice_context* context
		) override {
		return static_cast<Result>(this->_handle->ValidateContext(value_ptr(context)));
	}

	Result
		validate_context_for_dispatch(
			_HW_3D_IN_ IDevice_context* context
		) override {
		return static_cast<Result>(this->_handle->ValidateContextForDispatch(value_ptr(context)));
	}

	virtual ~_TDebug() {}
};

//
//
template <bool own>
class _Debug : public _TDebug<IDebug, ID3D11Debug, own> {
public:
	explicit _Debug(ID3D11Debug* handle)
		: _TDebug<IDebug, ID3D11Debug, own>(handle) {

	}

	ID3D11Debug* get() override {
		return this->_handle;
	}

	const ID3D11Debug* get() const override {
		return this->_handle;
	}

	~_Debug() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TInfo_queue : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IInfo_queue, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11InfoQueue, Ty>);
public:
	explicit _TInfo_queue(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	Result
		add_application_message(
			_HW_3D_IN_ Message_severity severty,
			_HW_3D_IN_ const _HW_3D_STD_ string& description
		) override {
		return static_cast<Result>(this->_handle->AddApplicationMessage((D3D11_MESSAGE_SEVERITY)severty, description.c_str()));
	}

	Result
		add_message(
			_HW_3D_IN_ Message_category category,
			_HW_3D_IN_ Message_severity severiry,
			_HW_3D_IN_ Message_id id,
			_HW_3D_IN_ const _HW_3D_STD_ string& description
		) override {
		return static_cast<Result>(this->_handle->AddMessage(
			(D3D11_MESSAGE_CATEGORY)category,
			(D3D11_MESSAGE_SEVERITY)severiry,
			(D3D11_MESSAGE_ID)id,
			description.c_str()
		));
	}

	Result
		add_retrieval_filter_entries(
			_HW_3D_IN_ Info_queue_filter& filter
		) override {
		return static_cast<Result>(this->_handle->AddRetrievalFilterEntries(value_ptr(filter)));
	}

	Result
		add_storage_filter_entries(
			_HW_3D_IN_ Info_queue_filter& filter
		) override {
		return static_cast<Result>(this->_handle->AddStorageFilterEntries(value_ptr(filter)));
	}

	void
		clear_retrieval_filter(
		) override {
		this->_handle->ClearRetrievalFilter();
	}

	void
		clear_storage_filter(
		) override {
		this->_handle->ClearStorageFilter();
	}

	void
		clear_storage_messages(
		) override {
		this->_handle->ClearStoredMessages();
	}

	Bool
		get_break_on_category(
			_HW_3D_IN_ Message_category category
		) override {
		return this->_handle->GetBreakOnCategory((D3D11_MESSAGE_CATEGORY)category);
	}

	Bool
		get_break_on_id(
			_HW_3D_IN_ Message_id id
		) override {
		return this->_handle->GetBreakOnID((D3D11_MESSAGE_ID)id);
	}

	Bool
		get_break_on_severity(
			_HW_3D_IN_ Message_severity severity
		) override {
		return this->_handle->GetBreakOnSeverity((D3D11_MESSAGE_SEVERITY)severity);
	}

	_HW_3D_STD_ tuple<Result, Message>
		get_message(
			_HW_3D_IN_ Uint64 index,
			_HW_3D_IN_ Size_t *length
		) override {
		_HW_3D_STD_ tuple<Result, Message> res;

		auto&[r, msg] = res;

		r = static_cast<Result>(this->_handle->GetMessage(index, value_ptr(msg), length));

		return res;
	}

	Uint64
		get_message_count_limit(
		) override {
		return this->_handle->GetMessageCountLimit();
	}

	Bool
		get_mute_debug_output(
		) override {
		return this->_handle->GetMuteDebugOutput();
	}

	Uint64
		get_num_messages_allowed_by_storage_filter(
		) override {
		return this->_handle->GetNumMessagesAllowedByStorageFilter();
	}

	Uint64
		get_num_messages_denied_by_storage_filter(
		) override {
		return this->_handle->GetNumMessagesDeniedByStorageFilter();
	}

	Uint64
		get_num_messages_discarded_by_message_count_limit(
		) override {
		return this->_handle->GetNumMessagesDiscardedByMessageCountLimit();
	}

	Uint64
		get_num_stored_messages(
		) override {
		return this->_handle->GetNumStoredMessages();
	}

	Uint64
		get_num_stored_messages_allowed_by_retrieval_filter(
		) override {
		return this->_handle->GetNumStoredMessagesAllowedByRetrievalFilter();
	}

	_HW_3D_STD_ tuple<Result, Info_queue_filter>
		get_retrieval_filter(
			_HW_3D_IN_OUT_ Size_t *length
		) override {
		_HW_3D_STD_ tuple<Result, Info_queue_filter> res;

		auto&[r, filter] = res;
		r = static_cast<Result>(this->_handle->GetRetrievalFilter(value_ptr(filter), length));

		return res;
	}

	Uint
		get_retrieval_filter_stack_size(
		) override {
		return this->_handle->GetRetrievalFilterStackSize();
	}

	_HW_3D_STD_ tuple<Result, Info_queue_filter>
		get_storage_filter(
			_HW_3D_IN_OUT_ Size_t* length
		) override {
		_HW_3D_STD_ tuple<Result, Info_queue_filter> res;

		auto&[r, filter] = res;
		r = static_cast<Result>(this->_handle->GetStorageFilter(value_ptr(filter), length));

		return res;
	}

	Uint
		get_storage_filter_stack_size(
		) override {
		return this->_handle->GetStorageFilterStackSize();
	}

	void
		pop_retrieval_filter(
		) override {
		this->_handle->PopRetrievalFilter();
	}

	void
		pop_storage_filter(
		) override {
		this->_handle->PopStorageFilter();
	}

	Result
		push_copy_of_retrieval_filter(
		) override {
		return static_cast<Result>(this->_handle->PushCopyOfRetrievalFilter());
	}

	Result
		push_copy_of_storage_filter(
		) override {
		return static_cast<Result>(this->_handle->PushCopyOfStorageFilter());
	}

	Result
		push_empty_retrieval_filter(
		) override {
		return static_cast<Result>(this->_handle->PushEmptyRetrievalFilter());
	}

	Result
		push_empty_storage_filter(
		) override {
		return static_cast<Result>(this->_handle->PushEmptyStorageFilter());
	}

	Result
		push_retrieval_filter(
			_HW_3D_IN_ Info_queue_filter& filter
		) override {
		return static_cast<Result>(this->_handle->PushRetrievalFilter(value_ptr(filter)));
	}

	Result
		push_storage_filter(
			_HW_3D_IN_ Info_queue_filter& filter
		) override {
		return static_cast<Result>(this->_handle->PushStorageFilter(value_ptr(filter)));
	}

	Result
		set_break_on_category(
			_HW_3D_IN_ Message_category category,
			_HW_3D_IN_ Bool enable
		) override {
		return static_cast<Result>(this->_handle->SetBreakOnCategory((D3D11_MESSAGE_CATEGORY)category, enable));
	}

	Result
		set_break_on_id(
			_HW_3D_IN_ Message_id id,
			_HW_3D_IN_ Bool enable
		) override {
		return static_cast<Result>(this->_handle->SetBreakOnID((D3D11_MESSAGE_ID)id, enable));
	}

	Result
		set_bread_on_severity(
			_HW_3D_IN_ Message_severity severity,
			_HW_3D_IN_ Bool enable
		) override {
		return static_cast<Result>(this->_handle->SetBreakOnSeverity((D3D11_MESSAGE_SEVERITY)severity, enable));
	}

	Result
		set_message_count_limit(
			_HW_3D_IN_ Uint64 message_count_limit
		) override {
		return static_cast<Result>(this->_handle->SetMessageCountLimit(message_count_limit));
	}

	void
		set_mute_debug_output(
			_HW_3D_IN_ Bool mute
		) override {
		this->_handle->SetMuteDebugOutput(mute);
	}


	virtual ~_TInfo_queue() {}
};

//
//
template <bool own>
class _Info_queue : public _TInfo_queue<IInfo_queue, ID3D11InfoQueue, own> {
public:
	explicit _Info_queue(ID3D11InfoQueue* handle)
		: _TInfo_queue<IInfo_queue, ID3D11InfoQueue, own>(handle) {

	}

	ID3D11InfoQueue* get() override {
		return this->_handle;
	}

	const ID3D11InfoQueue* get() const override {
		return this->_handle;
	}

	~_Info_queue() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TRef_default_tracking_options : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IRef_default_tracking_options, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11RefDefaultTrackingOptions, Ty>);
public:
	explicit _TRef_default_tracking_options(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	Result
		set_tracking_options(
			_HW_3D_IN_ Shader_tracking_resource_type type,
			_HW_3D_IN_ Shader_tracking_option options
		) override {
		return static_cast<Result>(this->_handle->SetTrackingOptions((Uint)type, Shader_tracking_option::mask_type(options)));
	}


	virtual ~_TRef_default_tracking_options() {}
};

//
//
template <bool own>
class _Ref_default_tracking_options : public _TRef_default_tracking_options<IRef_default_tracking_options, ID3D11RefDefaultTrackingOptions, own> {
public:
	explicit _Ref_default_tracking_options(ID3D11RefDefaultTrackingOptions* handle)
		: _TRef_default_tracking_options<IRef_default_tracking_options, ID3D11RefDefaultTrackingOptions, own>(handle) {

	}

	ID3D11RefDefaultTrackingOptions* get() override {
		return this->_handle;
	}

	const ID3D11RefDefaultTrackingOptions* get() const override {
		return this->_handle;
	}

	~_Ref_default_tracking_options() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TRef_tracking_options : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<IRef_tracking_options, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11RefTrackingOptions, Ty>);
public:
	explicit _TRef_tracking_options(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	Result
		set_tracking_options(
			_HW_3D_IN_ Shader_tracking_option options
		) override {
		return static_cast<Result>(this->_handle->SetTrackingOptions(Shader_tracking_option::mask_type(options)));
	}

	virtual ~_TRef_tracking_options() {}
};

//
//
template <bool own>
class _Ref_tracking_options : public _TRef_tracking_options<IRef_tracking_options, ID3D11RefTrackingOptions, own> {
public:
	explicit _Ref_tracking_options(ID3D11RefTrackingOptions* handle)
		: _TRef_tracking_options<IRef_tracking_options, ID3D11RefTrackingOptions, own>(handle) {

	}

	ID3D11RefTrackingOptions* get() override {
		return this->_handle;
	}

	const ID3D11RefTrackingOptions* get() const override {
		return this->_handle;
	}

	~_Ref_tracking_options() final {}
};

//
//
template <typename Interface, typename Ty, bool own>
class _HW_3D_NO_VTABLE_ _TTracing_device : public _TBase<Interface, Ty, own> {
	static_assert(_HW_3D_STD_ is_base_of_v<ITracing_device, Interface> && _HW_3D_STD_ is_base_of_v<ID3D11TracingDevice, Ty>);
public:
	explicit _TTracing_device(Ty* handle)
		: _TBase<Interface, Ty, own>(handle) {

	}

	Result
		set_shader_tracking_options(
			_HW_3D_IN_ IBase* shader,
			_HW_3D_IN_ Shader_tracking_option options
		) override {
		return static_cast<Result>(this->_handle->SetShaderTrackingOptions(value_ptr(shader), Shader_tracking_option::mask_type(options)));
	}

	Result
		set_shader_tracking_options_by_type(
			_HW_3D_IN_ Shader_tracking_resource_type type,
			_HW_3D_IN_ Shader_tracking_option options
		) override {
		return static_cast<Result>(this->_handle->SetShaderTrackingOptionsByType((Uint)type, Shader_tracking_option::mask_type(options)));
	}

	virtual ~_TTracing_device() {}
};

template <bool own>
class _Tracing_device : public _TTracing_device<ITracing_device, ID3D11TracingDevice, own> {
public:
	explicit _Tracing_device(ID3D11TracingDevice* handle)
		: _TTracing_device<ITracing_device, ID3D11TracingDevice, own>(handle) {

	}

	ID3D11TracingDevice* get() override {
		return this->_handle;
	}

	const ID3D11TracingDevice* get() const override {
		return this->_handle;
	}

	~_Tracing_device() final {}
};

_HW_3D_CLOSE_D3D_NAMESPACE_

_HW_3D_CLOSE_HW_NAMESPACE_