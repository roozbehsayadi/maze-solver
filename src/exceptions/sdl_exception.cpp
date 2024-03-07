
#include "exceptions/sdl_exception.h"

#include <utility>

SDLException::SDLException(std::string message) : message(std::move(message)) {}

const char *SDLException::what() const noexcept {
	return message.c_str();
}
