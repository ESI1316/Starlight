#include "view/windows/mainmenu.hpp"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QFileDialog>
#include <iostream>
#include <QMessageBox>
#include <QApplication>

MainMenu::MainMenu(QWidget *parent) : QFrame(parent)
{
    QVBoxLayout * lay{new QVBoxLayout};
    QLabel * title{new QLabel{tr("<div><span style=\"color:#ff0000;\">S</span>"
                            "<span style=\"color:#ff4000;\">t</span>"
                            "<span style=\"color:#ff7f00;\">a</span>"
                            "<span style=\"color:#ffff00;\">r</span>"
                            "<span style=\"color:#80ff00;\">l</span>"
                            "<span style=\"color:#00ff00;\">i</span>"
                            "<span style=\"color:#00ffff;\">g</span>"
                            "<span style=\"color:#0080ff;\">h</span>"
                            "<span style=\"color:#0000ff;\">t</span></div>")}};

    QPushButton * openLvlFile{new QPushButton{tr("Ouvrir un fichier de niveau")}};
    QPushButton * gameRules{new QPushButton{tr("Règles du jeu")}};
    QPushButton * quit{new QPushButton{tr("Quitter")}};

    QObject::connect(openLvlFile, SIGNAL(clicked()), this, SLOT(selectNewLevelFile()));
    QObject::connect(gameRules, SIGNAL(clicked()), this, SLOT(displayRules()));
    QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    title->setFont(QFont{"Arial", 100, 75});
    title->setAlignment(Qt::AlignCenter);
    lay->addWidget(title);
    lay->addWidget(openLvlFile);
    lay->addWidget(gameRules);
    lay->addWidget(quit);

    this->setLayout(lay);
}

MainMenu::~MainMenu() {}

void MainMenu::selectNewLevelFile()
{
    QString lvlFile = QFileDialog::getOpenFileName
            (this, tr("Ouvrir un fichier"), tr("./ressources/maps"), "Niveaux (*.lvl *.mapl)");

    if (!lvlFile.isEmpty())
        emit newLevelFileSelected(lvlFile);
}

void MainMenu::displayRules()
{
    QMessageBox msgBox;

    msgBox.setInformativeText(tr("<br><strong>Règles du jeu :</strong></br>"
                                  "<br>Le but du jeu est d'ateindre la cible "
                                 "(carré rose) avec le rayon lumineux émit par "
                                 "la source (carré blanc)."
                                 " Cela en déplaçant et en faisant pivoter les "
                                 "mirroirs (lignes bleu clair) de sorte à dévier "
                                 "le rayon pour l'orienter, le tout en évitant "
                                 "de traverser les bombes (cercles rouges). "
                                 "<br>Petites subtilitées; les lentilles (ellipses"
                                 "bleu foncé) ne peuvent être traversé par le "
                                 "rayon que si ce dernier possède la longueur d'"
                                 "onde adéquate. Pour modifier la longeur d'onde "
                                 "du rayon, il faut le faire traverser un crystal (ellipses vertes), "
                                 "ceci aura ainsi pour effet de réduire ou d'augmenter "
                                 "sa longueur d'onde (Note: la longueur d'onde d'un rayon "
                                 "est distinguable par sa <a href= \"http://www.cnrs.fr/cw"
                                 "/dossiers/doschim/decouv/couleurs/"
                                 "loupe_spect_lum.html\">couleur</a>).</br>"
                                 " </br>""<br><strong>Commandes :</strong></br>"
                                 "<br><u>Allumer/éteindre la source :</u> cliquer dessus.</br>"
                                 "<br><u>Déplacer un miroir :</u> cliquer dessus, ensuite "
                                 "gérer son déplacement avec les touches; q - vers la gauche, "
                                 "d - droite, s - bas, z - haut.</br>"
                                 "<br><u>Faire pivoter un miroir :</u> flèche directionnelle "
                                 "de droite - pivoter horlogiquement, flèche directionnelle "
                                 "de gauche - pivoter antihorlogiquement.</br>"));

    msgBox.exec();
}
