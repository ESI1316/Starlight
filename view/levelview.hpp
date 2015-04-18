#ifndef LEVELVIEW_HPP
#define LEVELVIEW_HPP

#include <QWidget>
#include <QFrame>

#include "model/elements/level.hpp"

class LevelView : public QFrame
{
    Q_OBJECT

    std::string displayedLevelFilePath;
    Level * level {nullptr};

    //std::vector<?> raysViews;

    /*!
     * \brief Permet d'afficher une fenêtre de dialogue affichant le message entré en
     * paramètre et demande à l'utilisateur s'il désire quitter le jeu.
     *
     * \param msg Message informant du type de fin du jeu (la destination est
     * illuminée/une bombe a explosée).
     */
    void displayEndOfGame(std::string msg);

public:

    explicit LevelView(QWidget *parent = 0);
    ~LevelView();

signals:

    /*!
     * \brief Signale que le niveau doit être affiché.
     */
    void displayingStarted();

    /*!
     * \brief Signale que le niveau ne doit plus être affiché.
     */
    void displayingStopped();

public slots:

    /*!
     * \brief Permet de changer le fichier de niveau et d'afficher ce niveau.
     *
     * \param levelFile chemin vers le fichier du nouveau niveau à afficher.
     */
    void setLevelFilePath(const QString levelFile);

    /*!
     * \brief Permet d'afficher le fichier niveau dont la vue courante contient
     * le chemin en attribut.
     */
    void loadLevelFromFile();

    /*!
     * \brief Permet d'afficher les rayon du niveau s'il ne sont pas affichés,
     * et de les désafficher s'il le sont.
     */
    void switchRaysDisplay();
};

#endif // LEVELVIEW_HPP
