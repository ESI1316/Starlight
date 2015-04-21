#include <QApplication>

#include "view/windows/mainwindow.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}

/*! \mainpage
 * ##Introduction
 * "Starlight est un petit jeu en deux dimensions se jouant sur une carte rectangulaire, 
 *comportant une source de lumière, émettant un rayon recti-ligne. 
 *Le but du jeuest d'atteindre une cible avec ledit rayon, en évitant les 
 *obstacles via notamment des miroirs réfléchissant la lumière."

 *##Rules
 *Starlight est un puzzle à deux dimensions se jouant sur une carte rec-tangulaire. 
 *Le but du jeu est de dévier un rayon lumineux d'une source vers
 *une cible en évitant certains obstacles. Plus particulièrement, on trouve les
 *éléments suivants sur une carte.
 *+ Une unique source : cet élément émet un rayon lumineux d'une lon-
 *gueur d'onde donnée sous un certain angle.
 *+ Une unique cible (ou destination ) : cet élément doit être éclairé par un
 *rayon lumineux pour remporter la partie.
 *+ Un ensemble de miroirs : un miroir est un objet réfléchissant la lumière
 *d'un seul côté suivant le schéma naturel de la réflexion de la lumière.
 *Plus particulièrement, un rayon incident à un miroir sous un angle θi
 *sera réfléchi sous le même angle θr , comme illustré 1 à la Figure 1.
 *+ Un ensemble de murs : les murs ne réfléchissent pas la lumière. Tout
 *rayon incident à un mur ne se propage pas, et " s'arrête " donc là où
 *il y est incident.
 *+ Un ensemble de lentilles. Les lentilles sont des objets transparents qui
 *ne laissent passer un rayon lumineux que dans un certain intervalle de
 *longueur d'onde [m ,n]. Si un rayon lumineux possède une longueur
 *d'onde ν telle que m <= ν <= n, il traverse la lentille sans subir aucune
 *modification. Sinon, la lentille stoppe le rayon (elle se comporte comme
 *un mur).
 *+ Un ensemble de cristaux : un cristal est un élément transparent qui
 *modifie la longueur d'onde d'un rayon, en l'augmentant ou la dimi-
 *nuant. Tout rayon qui traverse un cristal le traverse donc sans subir de
 *modification de trajectoire, mais voit sa longueur d'onde modifiée.
 *+ Un ensemble de bombes. Les bombes sont des objets qui, si éclairés,
 *explosent et font automatiquement perdre la partie au joueur.
 *+ Un ensemble de rayons. Initialement émis par la source du jeu, ils
 *sont rectilignes et se réfléchissent sur les miroirs. Un rayon est donc un
 *segment de droite. Sur la Figure 1, on voit donc deux rayons, le rayon P
 *et le rayon Q. Un rayon possède également une autre caractéristique : sa
 *longueur d'onde. La longueur d'onde d'un rayon permet de déterminer,
 *comme mentionné ci-dessus, si oui ou non un rayon traverse une lentille.
 *Elle est modifiée par un cristal.
 */
