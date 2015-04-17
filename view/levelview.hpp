#ifndef LEVELVIEW_HPP
#define LEVELVIEW_HPP

#include <QFrame>

#include "model/elements/level.hpp"

class LevelView : public QFrame
{
    Q_OBJECT

    std::string displayedLevelFilePath;
    Level * level {nullptr};

    /**
     * Permet d'afficher une fenêtre de dialogue affichant le message entré en
     * paramètre et demande à l'utilisateur s'il désire quitter le jeu.
     *
     * @param msg Message informant du type de fin du jeu (la destination est
     * illuminée/une bombe a explosée).
     */
    void displayEndOfGame(std::string msg);

public:

    explicit LevelView(QWidget *parent = 0);
    ~LevelView();

signals:

    /**
     * Signale que le niveau n'est plus affiché.
     */
    void displayingStopped();

public slots:

    /**
     * Permet de changer le fichier de niveau et d'afficher ce niveau.
     *
     * @param levelFile chemin vers le fichier du nouveau niveau à afficher.
     */
    void setLevel(const QString levelFile) const;

    /**
     * Permet d'afficher le fichier niveau dont la vue courante contient le
     * chemin en attribut.
     */
    void loadLevel() const;

    /**
     * Permet d'afficher les rayon du niveau s'il ne sont pas affichés, et de
     * les désafficher s'il le sont.
     */
    void switchRaysDisplay();
};

#endif // LEVELVIEW_HPP
