
#include "exceptions/sdl_exception.h"

SDLException::SDLException(const std::string &message) : message(message) {}

const char *SDLException::what() const noexcept {
	return message.c_str();
}
