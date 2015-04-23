#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <QWidget>
#include <QLabel>
#include <QFrame>

/*!
 * \brief Cette classe représente le menu principal du jeu permettant de <ul>
 * <li> sélectionner un niveau à jouer, </li>
 * <li> lire les règles du jeu, </li>
 * <li> quitter le jeu. </li>
 * </ul>
 */
class MainMenu : public QFrame
{
    Q_OBJECT

public:

    /*!
     * \brief Permet de créer un menu du jeu.
     */
    explicit MainMenu(QWidget * = 0);
    ~MainMenu();

signals:

    /*!
     * \brief Signale qu'un nouveau fichier a été sélectionné par l'utilisateur.
     *
     * \param newLevelFile Chemin vers le nouveau fichier sélectionné.
     */
    void newLevelFileSelected(const QString);

public slots:

    /*!
     * \brief Permet de faire sélectionner un fichier de niveau par l'utilisateur.
     *
     * \param newLevelFile Chemin vers le nouveau fichier sélectionné.
     */
    void selectNewLevelFile();

    /*!
     * \brief Permet d'afficher une fenêtre de dialogue contenant les règles et
     * les commandes du jeu.
     */
    void displayRules();

private :

    QLabel * setLogo();
};

#endif // MAINMENU_HPP
