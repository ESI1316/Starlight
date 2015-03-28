#ifndef STARLIGHTEXCEPTION_HPP
#define STARLIGHTEXCEPTION_HPP
#include <exception>
#include <string>


class StarlightException : public std::exception
{

private :

    std::string error;

public:

    /**
     * Construit une nouvelle erreur inhérente au jeu.
     *
     * @param error Message expliquant l'erreur.
     */
    StarlightException(std::string);
};

#endif // STARLIGHTEXCEPTION_HPP
