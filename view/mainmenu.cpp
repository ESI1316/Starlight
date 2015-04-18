#include "mainmenu.hpp"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QFileDialog>
#include <iostream>

MainMenu::MainMenu(QWidget *parent) : QFrame(parent)
{
    QVBoxLayout * lay{new QVBoxLayout};
    QLabel * title{new QLabel{tr("Starlight")}};
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
            (this, tr("Ouvrir un fichier"), tr("./ressources"), tr("Niveaux (*.lvl *.mapl)"));

    if (!lvlFile.isEmpty())
        emit newLevelFileSelected(lvlFile);
}
