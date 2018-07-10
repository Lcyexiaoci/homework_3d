#pragma once

#include "fg_fwd.h"
#include "fg_utils.hpp"
#include "../d3d/d3d_wrapper.hpp"

_HW_3D_OPEN_HW_NAMESPACE_
_HW_3D_OPEN_FG_NAMESPACE_

class Frame_graph_resource : public Ref_count_base {
public:
	using Resource_type_t = _HW_3D_D3D_ IResource;
public:
	explicit Frame_graph_resource(
		_HW_3D_IN_ const _HW_3D_STD_ string& name
	)	: _resource_name(name) {
	}

	const _HW_3D_STD_ string& name() const {
		return _resource_name;
	}

	void set_transient(
		_HW_3D_IN_ bool value
	) {
		_transient = value;
	}

	bool is_transient() const {
		return _transient;
	}



private:
	_HW_3D_STD_ string _resource_name;
	bool _transient;
};


_HW_3D_CLOSE_FG_NAMESPACE_
_HW_3D_CLOSE_HW_NAMESPACE_