#include "starlightexception.hpp"

StarlightException::StarlightException()
    :std::exception(), error{"Erreur non précisée"}
{
}

StarlightException::StarlightException(std::string error)
    :std::exception(), error{error}
{
}

StarlightException::~StarlightException()
{
}

