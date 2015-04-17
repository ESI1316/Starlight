#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "view/levelview.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    Ui::MainWindow *ui;
    QFrame * mainMenu;
    LevelView * levelView;

public slots:

    /**
     * Permet d'afficher le menu principal du jeu.
     */
    void displayMainMenu();

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_HPP
