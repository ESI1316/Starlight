#include "model/starlightexception.hpp"

StarlightException::StarlightException(std::string errorMsg)
    :std::exception(), errorMsg{errorMsg} {}

std::string StarlightException::getMessage() const
{
    return this->errorMsg;
}
