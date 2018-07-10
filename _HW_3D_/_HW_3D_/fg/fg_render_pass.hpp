#pragma once

#include "fg_fwd.h"
#include "fg_utils.hpp"

_HW_3D_OPEN_HW_NAMESPACE_
_HW_3D_OPEN_FG_NAMESPACE_

class Render_pass : public Ref_count_base {
public:
	explicit Render_pass(const _HW_3D_STD_ string& name) : _pass_name(name) {}

	void set_side_effect(bool value) {
		_side_effect = value;
	}

	bool has_side_effect() const {
		return _side_effect;
	}



	virtual ~Render_pass() {}
private:
	_HW_3D_STD_ string _pass_name;
	bool _side_effect = false;
};

_HW_3D_CLOSE_FG_NAMESPACE_
_HW_3D_CLOSE_HW_NAMESPACE_