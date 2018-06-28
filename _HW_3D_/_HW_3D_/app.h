#pragma once

#include "fwd.h"
#include "log.hpp"

_HW_3D_OPEN_HW_NAMESPACE_

class Application {
public:
	virtual bool initialize() = 0;
	virtual void run() = 0;
	virtual void shutdown() = 0;
};

class Application_factory {
public:
	using Key_type = _HW_3D_STD_ string;
	using Value_type = _HW_3D_STD_ function<_HW_3D_STD_ unique_ptr<Application>()>;
	using Application_type = _HW_3D_STD_ unique_ptr<Application>;

	static void register_application(
		_HW_3D_IN_ const Key_type& name,
		_HW_3D_IN_ const Value_type& constructor
	) {
		if (auto iter = _HW_3D_STD_ find(_keys.begin(), _keys.end(), name); iter == _keys.end()) {
			_keys.push_back(name);
			_values.push_back(constructor);
		}
		else {
			_values.at(iter - _keys.begin()) = constructor;
		}
	}

	static Application_type create(const _HW_3D_STD_ string& name) {
		if (auto iter = _HW_3D_STD_ find(_keys.begin(), _keys.end(), name); iter == _keys.end()) {
			throw _HW_3D_STD_ logic_error("try to create an unregister application");
		}
		else {
			return _HW_3D_STD_ invoke(_values.at(iter - _keys.begin()));
		}
	}
private:
	static _HW_3D_STD_ vector<Key_type> _keys;
	static _HW_3D_STD_ vector<Value_type> _values;
};

_HW_3D_INLINE_VARIABLE_ decltype(Application_factory::_keys) Application_factory::_keys;
_HW_3D_INLINE_VARIABLE_ decltype(Application_factory::_values) Application_factory::_values;


#define _HW_3D_REGISTER_DEMO_(Demo_type, name)										\
	_HW_3D_STD_ unique_ptr<Application> Demo_type ##_create() {						\
		return _HW_3D_STD_ make_unique<Demo_type>();								\
	}																				\
	static struct Demo_type ##_create_t{											\
		Demo_type ##_create_t() {													\
			Application_factory::register_application(name, Demo_type ##_create);	\
		}																			\
	} Demo_type ##_v


_HW_3D_CLOSE_HW_NAMESPACE_
