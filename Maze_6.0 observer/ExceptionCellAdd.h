#pragma once
#include <exception>
#include <string>

using namespace std;

class ExceptionCellAdd : public exception {
	string message;

public:
	ExceptionCellAdd() :message("Incorrect cell add") {}
	ExceptionCellAdd(const char* const& _message) : message(_message) {}

	const char* what() const noexcept {
		return message.c_str(); // получаем из string строку const char*
	}
};