#include "model/exception/starlightexception.hpp"

StarlightException::StarlightException(std::string errorMsg)
    :std::exception(), errorMsg{errorMsg} {}
