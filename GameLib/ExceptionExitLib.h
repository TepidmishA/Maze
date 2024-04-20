#pragma once
#include <exception>
#include <string>

using namespace std;

class ExceptionExit : public exception {
	string message;

public:
	ExceptionExit() :message("Not enough coins") {}
	ExceptionExit(const char* const& _message) : message(_message) {}

	const char* what() const noexcept {
		return message.c_str(); // получаем из string строку const char*
	}
};