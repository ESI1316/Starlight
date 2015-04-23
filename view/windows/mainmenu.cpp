#include "view/windows/mainmenu.hpp"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QFileDialog>
#include <iostream>
#include <QMessageBox>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QFile>
#include <QTextStream>

#include "view/viewutilities.hpp"

MainMenu::MainMenu(QWidget *parent) : QFrame(parent)
{

    QVBoxLayout * lay{new QVBoxLayout};

    QPushButton * openLvlFile{new QPushButton{tr("Ouvrir un fichier de niveau")}};
    QPushButton * gameRules{new QPushButton{tr("Règles du jeu")}};
    QPushButton * quit{new QPushButton{tr("Quitter")}};

    QObject::connect(openLvlFile, SIGNAL(clicked()), this, SLOT(selectNewLevelFile()));
    QObject::connect(gameRules, SIGNAL(clicked()), this, SLOT(displayRules()));
    QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    lay->addWidget(this->setLogo());
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
    QString * content = viewUtilities::fileToQString(":html/rules");
    QMessageBox::information(this, "rules", *content);
    delete content;
}

QLabel * MainMenu::setLogo()
{
    QString * content = viewUtilities::fileToQString(":html/logo");
    QLabel * title = new QLabel(*content);
    delete content;

    title->setAlignment(Qt::AlignCenter);

    return title;
}
