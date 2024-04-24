using namespace System;


public ref class ExceptionCellAddNET : public System::Exception {
	String^ message;

public:
	ExceptionCellAddNET() :message("Incorrect cell add") {}
	ExceptionCellAddNET(String^ _message) : message(_message) {}

	String^ what() {
		return message;
	}
};

public ref class ExceptionExitNET : public System::Exception {
	String^ message;

public:
	ExceptionExitNET() :message("Not enough coins") {}
	ExceptionExitNET(String^ _message) : message(_message) {}

	String^ what() {
		return message;
	}
};

public ref class ExceptionWinNET : public System::Exception {
	String^ message;

public:
	ExceptionWinNET() :message("You win!!!") {}
	ExceptionWinNET(String^ _message) : message(_message) {}

	String^ what() {
		return message;
	}
};

public ref class ExceptionZeroHPNET : public System::Exception {
	String^ message;

public:
	ExceptionZeroHPNET() :message("Zero HP") {}
	ExceptionZeroHPNET(String^ _message) : message(_message) {}

	String^ what() {
		return message;
	}
};
