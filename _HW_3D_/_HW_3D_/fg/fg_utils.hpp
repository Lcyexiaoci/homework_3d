#pragma once

#include "fg_fwd.h"

_HW_3D_OPEN_HW_NAMESPACE_
_HW_3D_OPEN_FG_NAMESPACE_

class Ref_count_base {
public:
	Ref_count_base() : _count(0) {}
	
	void incr() { ++_count; }
	void decr() { --_count; }
	uint32_t count() const { return _count; }
	bool valid() const { return _count >= 0; }

private:
	uint32_t _count;
};


_HW_3D_CLOSE_FG_NAMESPACE_
_HW_3D_CLOSE_HW_NAMESPACE_