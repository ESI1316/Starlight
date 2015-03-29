#include "model/starlightexception.hpp"

StarlightException::StarlightException(std::string error)
    :std::exception(), error{error}
{
}
