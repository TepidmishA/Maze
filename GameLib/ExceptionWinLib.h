#pragma once
#include <exception>
#include <string>

using namespace std;

class ExceptionWin : public exception {
	string message;

public:
	ExceptionWin() :message("You win!!!") {}
	ExceptionWin(const char* const& _message) : message(_message) {}

	const char* what() const noexcept {
		return message.c_str(); // получаем из string строку const char*
	}
};