#ifndef LEVELVIEW_HPP
#define LEVELVIEW_HPP

#include <QFrame>

#include "model/elements/level.hpp"

class LevelView : public QFrame
{
    Q_OBJECT

    std::string displayedLevelFilePath;
    Level * level {nullptr};

    //std::vector<?> raysViews;

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

    /*!
     * \brief Permet d'afficher une fenêtre de dialogue affichant le message entré en
     * paramètre et demande à l'utilisateur s'il désire quitter le jeu.
     */
    void displayEndOfGame();
};

#endif // LEVELVIEW_HPP
