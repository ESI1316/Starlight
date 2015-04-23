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
    QFile file(":rules/other/rules.html");

    if (!file.open(QFile::ReadOnly | QFile::Text))
        QMessageBox::information(this, "rules", "Missing rules file.");
    else
        QMessageBox::information(this, "rules", QTextStream(&file).readAll());

    file.close();
}

QLabel * MainMenu::setLogo()
{
    QFile logo(":logo/other/logo.html");
    QLabel * title;

    if (!logo.open(QFile::ReadOnly | QFile::Text))
        title = new QLabel{tr("Logo file not found")};
    else
        title = new QLabel{QTextStream(&logo).readAll()};

    title->setFont(QFont{"Arial", 100, 75});
    title->setAlignment(Qt::AlignCenter);

    return title;
}
