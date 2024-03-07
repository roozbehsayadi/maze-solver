#ifndef MAZESOLVER_OPENCV_EXCEPTION_H
#define MAZESOLVER_OPENCV_EXCEPTION_H

#include <stdexcept>

class OpenCvException : public std::exception {
public:
	explicit OpenCvException(std::string );

	OpenCvException(const OpenCvException &) = default;

	virtual const char *what() const noexcept override;

private:
	const std::string message;
};

#endif //MAZESOLVER_OPENCV_EXCEPTION_H
