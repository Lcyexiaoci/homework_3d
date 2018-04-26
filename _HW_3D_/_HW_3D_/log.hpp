#pragma once

#include "fwd.h"
#include "utils.hpp"

_HW_3D_OPEN_HW_NAMESPACE_

enum class Error_type {
	d3d11,
	alloc,
	logic,
	runtime,
	unknown,
};

//exception for log
class Hw_exception : public _HW_3D_STD_ exception {
private:
	static auto error_type_to_string(Error_type err_t) {
		static _HW_3D_STD_ vector<_HW_3D_STD_ pair<Error_type, _HW_3D_STD_ string>> mapping_to_string = {
			{ Error_type::alloc, "Allocate" },
			{ Error_type::d3d11, "Direct3D 11" },
			{ Error_type::logic, "Logic" },
			{ Error_type::runtime, "Runtime" },
			{ Error_type::unknown, "Unkown" },
		};

		auto iter = _HW_3D_STD_ find_if(
			mapping_to_string.begin(),
			mapping_to_string.end(),
			[err_t](const auto& item) { return item.first == err_t; });

		assert(iter != mapping_to_string.end());
		return iter->second;
	};

public:
	Hw_exception(
		_HW_3D_IN_ Error_type					type,
		_HW_3D_IN_ const _HW_3D_STD_ string&	desc,
		_HW_3D_IN_ const _HW_3D_STD_ string&	file,
		_HW_3D_IN_ int							line) 
		: _type(type)
		, _desc(desc)
		, _file(file)
		, _line(line) {
	}

	const char* what() const override {
		if (_msg.empty()) {
			_msg = _HW_3D_STD_ invoke(
				[this]() {
				_HW_3D_STD_ stringstream ss;
				ss << "<file: " << _file
					<< ", line: " << _line
					<< ", type: " << error_type_to_string(_type)
					<< ">:\t" << _desc;
				return ss.str();
			});
		}
		return _msg.c_str();
	}

	~Hw_exception() noexcept {}
private:
	_HW_3D_STD_ string _desc;
	_HW_3D_STD_ string _file;
	mutable _HW_3D_STD_ string _msg;
	int _line;
	Error_type _type;
};

//log manager, using system time instead program timer
class Log_manager : public _Singleton<Log_manager> {
private:
#pragma warning(push)
#pragma warning(disable : 4996)
	static _HW_3D_STD_ string current_time(const _HW_3D_STD_ string& format = "%F %T") {
		auto cur_time = _HW_3D_STD_ chrono::system_clock::to_time_t(_HW_3D_STD_ chrono::system_clock::now());
		_HW_3D_STD_ stringstream ss;
		ss << _HW_3D_STD_ put_time(_HW_3D_STD_ localtime(&cur_time), format.c_str());
		return ss.str();
	}
#pragma warning(pop)
public:
	Log_manager(const Path& log_file)
		: _log_file(log_file) {
		if (!_log_file.is_open()) {
			throw _HW_3D_STD_ runtime_error("failed to open log file");
		}
	}

	void flush() {
		_log_file.flush();
	}

	void log_exception(const Hw_exception& e) {
		_log_file
			<< current_time() << "\n-\t" << e.what() << "\n";
		flush();
	}

	void log_message(const _HW_3D_STD_ string& msg) {
		_log_file
			<< current_time() << "\n-\t<message>:\t" << msg << "\n";
	}

	~Log_manager() {
		_log_file.close();
	}
private:
	_HW_3D_STD_ ofstream _log_file;
};



_HW_3D_CLOSE_HW_NAMESPACE_