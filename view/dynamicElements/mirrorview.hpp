#ifndef MIRRORVIEW_HPP
#define MIRRORVIEW_HPP

#include <QGraphicsLineItem>
#include <QKeyEvent>

class Mirror;

/*!
 * \brief Cette classe représente graphiquement un miroir du jeu permettant
 * d'interagir avec lui à l'aide de la souris et du clavier.
 */
class MirrorView : public QGraphicsLineItem
{
    /*!
     * \brief Le miroir que cette vue représente.
     */
    Mirror * mirror;

public:

    /*!
     * \brief Construit une vue de miroir lié à un miroir.
     *
     * \param mirror Le miroir lié à cette vue.
     */
    MirrorView(Mirror * mirror);

    /*!
     * \brief Détruit le miroir.
     */
    ~MirrorView();

protected:

    /*!
     * \brief Permet de faire réagir le miroir à l'action de certaines touches
     * du clavier et de la souris.
     *
     * \param event Une évenement "input user".
     */
    void keyPressEvent(QKeyEvent * event);
};

#endif // MIRRORVIEW_HPP
