#ifndef STARLIGHTEXCEPTION_HPP
#define STARLIGHTEXCEPTION_HPP

#include <exception>
#include <string>

/*!
 * \brief Cette classe représente une exception spécifique au jeu Starlight.
 */
class StarlightException : public std::exception
{

private :

    /*!
     * \brief Le message d'erreur de l'exception lancée.
     */
    std::string errorMsg;

public:

    /*!
     * \brief Construit une nouvelle erreur inhérente au jeu.
     *
     * \param errorMsg Message expliquant l'erreur.
     */
    StarlightException(std::string);

    /*!
     * \brief Permet d'obtenir le message d'erreur de l'exception.
     *
     * \return Le message d'erreur de l'exception.
     */
    std::string getMessage() const;

    /*!
     * \brief Permet d'afficher l'erreur en cas d'erreur.
     *
     * \return Le message d'erreur.
     */
    const char * what() const throw();
};


inline std::string StarlightException::getMessage() const
{
    return this->errorMsg;
}

inline const char * StarlightException::what() const throw()
{
    return this->errorMsg.c_str();
}

#endif // STARLIGHTEXCEPTION_HPP
