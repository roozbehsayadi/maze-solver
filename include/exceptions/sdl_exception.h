#ifndef MAZESOLVER_SDL_EXCEPTION_H
#define MAZESOLVER_SDL_EXCEPTION_H

#include <stdexcept>

class SDLException : public std::exception {
public:
	explicit SDLException(std::string );

	SDLException(const SDLException &) = default;

	virtual const char *what() const noexcept override;

private:
	const std::string message;
};

#endif //MAZESOLVER_SDL_EXCEPTION_H
