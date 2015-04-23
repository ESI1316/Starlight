#ifndef LEVELVIEW_HPP
#define LEVELVIEW_HPP

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QString>
#include <string>
#include <vector>

class Level;
class MirrorView;

/*!
 * \brief Cette classe représente le niveau qui va être joué lors d'une partie.
 */
class LevelView : public QGraphicsView
{
    Q_OBJECT

    /*!
     * \brief La scène qui comportera l'ensemble des éléments graphiques de la
     * partie.
     */
    QGraphicsScene * scene;

    /*!
     * \brief Le niveau quel la vue observe.
     */
    Level * level;

    /*!
     * \brief Le chemin du fichier chargé par l'utilisateur.
     */
    std::string displayedLevelFilePath;

    /*!
     * \brief L'ensemble des rayons dessinés.
     */
    std::vector<QGraphicsLineItem *> rays;

    /*!
     * \brief L'ensemble des miroirs dessinés.
     */
    std::vector<MirrorView *> mirrors;

public:

    /*!
     * \brief Permet de créer une vue du niveau.
     *
     * \param parent L'objet graphique parent.
     */
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

private :

    void cleanAll();
};

#endif // LEVELVIEW_HPP
