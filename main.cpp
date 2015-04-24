#include "main.hpp"

#ifndef RUN_TEST

#include <QApplication>
#include "view/windows/mainwindow.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
#endif

/*! \mainpage
 * ![Starlight](../../ressources/other/icon.png)
 * ##Introduction
 *
 * **Starlight** est un petit jeu en deux dimensions se jouant sur une carte rectangulaire,
 *comportant une source de lumière, émettant un rayon rectiligne.
 *
 *Le but du jeu est d'atteindre une cible avec ledit rayon, en évitant les 
 *obstacles via notamment des miroirs réfléchissant la lumière.;

 *##Rules

 *Starlight est un puzzle à deux dimensions se jouant sur une carte rectangulaire.
 *Le but du jeu est de dévier un rayon lumineux d'une source vers
 *une cible en évitant certains obstacles. Plus particulièrement, on trouve les
 *éléments suivants sur une carte :
 *+ une unique source : cet élément émet un rayon lumineux d'une longueur 
 * d'onde donnée sous un certain angle,
 *+ une unique cible (ou destination ) : cet élément doit être éclairé par un
 *rayon lumineux pour remporter la partie,
 *+ un ensemble de miroirs : un miroir est un objet réfléchissant la lumière
 *d'un seul côté suivant le schéma naturel de la réflexion de la lumière,
 *Plus particulièrement, un rayon incident à un miroir sous un angle \alpha i
 *sera réfléchi sous le même angle \alpha r,
 *+ un ensemble de murs : les murs ne réfléchissent pas la lumière. Tout
 *rayon incident à un mur ne se propage pas, et " s'arrête " donc là où
 *il y est incident,
 *+ un ensemble de lentilles. Les lentilles sont des objets transparents qui
 *ne laissent passer un rayon lumineux que dans un certain intervalle de
 *longueur d'onde [m ,n]. Si un rayon lumineux possède une longueur
 *d'onde ν telle que m <= ν <= n, il traverse la lentille sans subir aucune
 *modification. Sinon, la lentille stoppe le rayon (elle se comporte comme
 *un mur),
 *+ un ensemble de cristaux : un cristal est un élément transparent qui
 *modifie la longueur d'onde d'un rayon, en l'augmentant ou la dimi-
 *nuant. Tout rayon qui traverse un cristal le traverse donc sans subir de
 *modification de trajectoire, mais voit sa longueur d'onde modifiée,
 *+ un ensemble de bombes. Les bombes sont des objets qui, si éclairés,
 *explosent et font automatiquement perdre la partie au joueur,
 *+ un ensemble de rayons initialement émis par la source du jeu. Ceux-ci
 *sont rectilignes et se réfléchissent sur les miroirs. Un rayon est donc un
 *segment de droite. Un rayon possède également une autre caractéristique : sa
 *longueur d'onde. La longueur d'onde d'un rayon permet de déterminer,
 *comme mentionné ci-dessus, si oui ou non un rayon traverse une lentille.
 *Elle est modifiée par un cristal.
 */
