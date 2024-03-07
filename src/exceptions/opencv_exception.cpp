
#include "exceptions/opencv_exception.h"

#include <utility>

OpenCvException::OpenCvException(std::string message) : message(std::move(message)) {}

const char *OpenCvException::what() const noexcept {
	return message.c_str();
}
