#pragma once
#include <exception>
#include <string>

using namespace std;

class ExceptionZeroHP : public exception {
	string message;

public:
	ExceptionZeroHP() :message("Zero HP") {}
	ExceptionZeroHP(const char* const& _message) : message(_message) {}

	const char* what() const noexcept {
		return message.c_str(); // получаем из string строку const char*
	}
};