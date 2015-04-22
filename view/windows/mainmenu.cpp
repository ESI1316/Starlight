#include "view/windows/mainmenu.hpp"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QFileDialog>
#include <iostream>

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

    QObject::connect(openLvlFile, SIGNAL(clicked()), this, SLOT(selectNewLevelFile()));
    title->setFont(QFont{"Arial", 100, 75});
    title->setAlignment(Qt::AlignCenter);
    lay->addWidget(title);
    lay->addWidget(openLvlFile);

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
