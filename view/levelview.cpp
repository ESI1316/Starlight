#include "view/levelview.hpp"

#include "model/elements/levelFactory.hpp"

#include <QMessageBox>
#include <QPainter>

LevelView::LevelView(QWidget *parent) : QFrame{parent}, level{nullptr} {}

LevelView::~LevelView()
{
    if (this->level != nullptr)
        delete this->level, this->level = nullptr;
}

void LevelView::setLevelFilePath(const QString levelFile)
{
    this->displayedLevelFilePath = levelFile.toStdString();
    this->loadLevelFromFile();
}

void LevelView::loadLevelFromFile()
{
    if (this->level != nullptr)
        delete this->level, this->level = nullptr;

    this->level = levelFactory::getLevelFromFile(this->displayedLevelFilePath);
    this->level->computeRays();
    this->level->getSource().setOn(true);

    emit displayingStarted();
}

void LevelView::paintEvent(QPaintEvent*)
{
    QPainter * painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing);

    if (this->level != nullptr)
    {
        this->setFixedSize(this->level->getWidth(), this->level->getHeight());
        this->setStyleSheet("background-color:white;"
                            "border-style: outset;"
                            "border-width: 2px;"
                            "border-color: black;");


        for (Ray ray : this->level->getRays())
                painter->drawLine(this->toQPoint(ray.getStart()),
                                       this->toQPoint(ray.getEnd()));
    }

    delete painter;
}

QPointF LevelView::toQPoint(const Point & point)
{
    return QPointF{point.getX(), point.getY()};
}

void LevelView::displayEndOfGame()
{
    QMessageBox msgBox;
    QPushButton *quitB = msgBox.addButton(tr("Retour au menu principal"), QMessageBox::YesRole);

    msgBox.addButton(tr("Recommencer"), QMessageBox::NoRole);
    msgBox.setText(tr("<strong>Fin de partie :<strong>"));
    msgBox.setInformativeText(this->level->getDestination().isLightedUp() ?
                                  tr("<br>Bravo</br> !\nVous avez gagné") :
                                  tr("<br>Perdu</br> !\nUne bombe a explosée"));
    msgBox.setWindowFlags(msgBox.windowFlags() ^ Qt::WindowCloseButtonHint);
    msgBox.exec();

    if(((QPushButton*) msgBox.clickedButton()) == quitB)
        emit displayingStopped();
    else
        this->loadLevelFromFile();
}
