#ifndef SOURCEVIEW_HPP
#define SOURCEVIEW_HPP

#include <QGraphicsRectItem>
#include <QPen>
#include <QBrush>

class Source;

/*!
 * \brief Cette classe permet de représenter graphiquement une source, lui
 * permettant de communiquer les actions utilisateurs.
 */
class SourceView : public QGraphicsRectItem
{
    /*!
     * \brief La source représentée par cette vue.
     */
    Source * source;

    /*!
     * \brief Les paramètres visuels du trait de la source.
     */
    QPen pen;

    /*!
     * \brief Les paramètres visuels du plein de la source.
     */
    QBrush brush;

public:

    /*!
     * \brief Permet de créer une vue liée à une source.
     *
     * \param source La source liée à cette vue.
     */
    SourceView(Source *source);

    ~SourceView();

    /*!
     * \brief Permet de changer l'état de la source.
     */
    void switchSource();

protected:

    /*!
     * \brief Permet de réagir sur le modèle lors d'un "input user".
     *
     * \param event Un évènement "input user".
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SOURCEVIEW_HPP
