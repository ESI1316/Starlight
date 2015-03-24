#ifndef STARLIGHTEXCEPTION_HPP
#define STARLIGHTEXCEPTION_HPP
#include <exception>
#include <string>


class StarlightException : public std::exception
{

private :
    std::string error;

public:

    StarlightException();
    StarlightException(std::string);
    ~StarlightException();
};

#endif // STARLIGHTEXCEPTION_HPP
