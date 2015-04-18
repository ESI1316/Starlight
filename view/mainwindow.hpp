#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "view/levelview.hpp"
#include "view/mainmenu.hpp"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    Ui::MainWindow *ui;
    MainMenu * mainMenu;
    LevelView * levelView;

public slots:

    /*!
     * \brief Permet d'afficher le menu principal du jeu.
     */
    void displayMainMenu();

    /*!
     * \brief Permet d'afficher le niveau.
     */
    void displayLevel();

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_HPP
