#include "starlightexception.hpp"

StarlightException::StarlightException()
    : StarlightException{"Erreur non précisée"}
{
}

StarlightException::StarlightException(std::string error)
    :std::exception(), error{error}
{
}

StarlightException::~StarlightException()
{
}

