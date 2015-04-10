#ifndef STARLIGHTEXCEPTION_HPP
#define STARLIGHTEXCEPTION_HPP
#include <exception>
#include <string>


class StarlightException : public std::exception
{

private :

    std::string errorMsg;

public:

    /**
     * Construit une nouvelle erreur inhérente au jeu.
     *
     * @param errorMsg Message expliquant l'erreur.
     */
    StarlightException(std::string);

    /**
     * Permet d'obtenir le message d'erreur de l'exception.
     *
     * @return Le message d'erreur de l'exception.
     */
    std::string getMessage() const;
};

#endif // STARLIGHTEXCEPTION_HPP
