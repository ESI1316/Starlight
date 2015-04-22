#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <QWidget>
#include <QFrame>

class MainMenu : public QFrame
{
    Q_OBJECT

public:

    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

signals:

    /*!
     * \brief Signale qu'un nouveau fichier a été séléctionné par l'utilisateur.
     *
     * \param newLevelFile Chemin vers le nouveau fichier selectionné.
     */
    void newLevelFileSelected(const QString newLevelFile);

public slots:

    /*!
     * \brief Permet de faire séléctionner un fichier de niveau à l'utilisateur.
     *
     * \param newLevelFile Chemin vers le nouveau fichier sélectionné.
     */
    void selectNewLevelFile();

    /*!
     * \brief Permet d'afficher une fenêtre de dialogue contenant les règles et
     * les commandes du jeu.
     */
    void displayRules();
};

#endif // MAINMENU_HPP
