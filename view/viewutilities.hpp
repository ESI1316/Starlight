#ifndef VIEWUTILITIES_HPP
#define VIEWUTILITIES_HPP

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QColor>
#include <QPointF>
#include <QRectF>
#include <QString>

class Ellipse;
class Rectangle;
class Point;
class Ray;

/*!
 * Divers fonctions utilitaires nécessaires aux vues.
 */
namespace viewUtilities
{

/*!
 * \brief Permet de transformer un point en QPointF.
 *
 * \return La représentation QPointF du Point passé en paramètre.
 * \see Point
 */
QPointF toQPoint(const Point &);

/*!
 * \brief Permet de transformer un rectangle en QRectF.
 *
 * \return La représentation QRectF du rectangle passé en paramètre.
 * \see Rectangle
 */
QRectF toQRectF(const Rectangle &);

/*!
 * \brief Permet de représenter une ellipse, à partir du rectangle qui lui est
 * circonscrit, en un QRectF.
 *
 * \return Le QRectF circonscrit à l'ellipse.
 * \see Ellipse
 */
QRectF toQRectF(const Ellipse &);

/*!
 * \brief Permet de générer une QGraphicsLine à partir des deux points délimitant
 * un segment de droite.
 *
 * \param start Le point de départ du segment de droite.
 * \param end Le point d'arrivé du segment de droite.
 * \param color La couleur que ce segment doit prendre.
 * \param width L'épaisseur du trait de ce segment de droite.
 *
 * \return Le QGraphicsLineItem représentant ce segment de droite.
 */
QGraphicsLineItem * getLine(const Point &, const Point &, const QColor &, const int);

/*!
 * \brief Permet de générer un QGraphicsRectItem représentant le rectangle
 * passé en paramètre.
 *
 * \param rectangle Le rectangle devant être représenté.
 * \param color La couleur de ce rectangle.
 * \param width L'épaisseur du trait représentant ce rectangle.
 *
 * \return Le QGraphicsRectItem représentant ce rectangle.
 */
QGraphicsRectItem * getRect(const Rectangle &, const QColor &, const int);

/*!
 * \brief Permet de générer un QGraphicsEllipseItem représentant l'ellipse
 * passée en paramètre.
 *
 * \param ellipse Une ellipse devant être représentée.
 * \param color La couleur de cette ellipse.
 * \param width L'épaisseur du trait représentant cette ellipse.
 *
 * \return Le QGraphicsEllipseItem représentant cette ellipse.
 */
QGraphicsEllipseItem * getEllipse(const Ellipse &, const QColor &, const int);

/*!
 * \brief Permet de créé une QColor au format RGB selon la longueur d'onde passée
 * en paramètre. Cette méthode se base sur le spectre lumineux visible en représentant
 * les U.V. comme du noir.
 *
 * \return La QColor représentant la longueur d'onde d'un rayon.
 *
 * \see http://www.physics.sfasu.edu/astro/color/spectra.html
 */
QColor waveLengthToColor(const Ray &, const double = 0.8);

/*!
 * \brief Permet de lire un fichier et de retourner son contenu en tant que
 * QString. En cas de fichier innacessible, un avertissement sera affiché.
 *
 * \param url L'url d'un document à lire.
 *
 * \return Un QString contenant le fichier passé en paramètre.
 */
QString * fileToQString(const QString &);
}

#endif // VIEWUTILITIES_HPP

