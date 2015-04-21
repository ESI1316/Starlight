#ifndef LEVELVIEW_HPP
#define LEVELVIEW_HPP

#include <QGraphicsView>
#include <QGraphicsScene>

#include "view/dynamicElements/sourceView.hpp"
#include "view/dynamicElements/mirrorview.hpp"

class Level;
class Point;

class LevelView : public QGraphicsView
{
    Q_OBJECT

    QGraphicsScene * scene;
    std::string displayedLevelFilePath;
    Level * level;
    std::vector<QGraphicsLineItem *> rays;
    std::vector<MirrorView *> mirrors;

    QPointF toQPoint(const Point & point);

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
    void setLevelFilePath(const QString);

    /*!
     * \brief Permet d'afficher le fichier niveau dont la vue courante contient
     * le chemin en attribut.
     */
    void loadLevelFromFile();

    /*!
     * \brief Permet de rafraichir l'affichage lorsque le niveau change d'état.
     */
    void updateDisplay();

    /*!
     * \brief Permet d'afficher une boite de dialogue informant l'utilisateur de
     * la fin du jeu.
     */
    void displayEndOfGame();
};

#endif // LEVELVIEW_HPP
