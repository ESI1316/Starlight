#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMenu>
#include <QMenuBar>
#include <QMainWindow>

class MainMenu;
class LevelView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    MainMenu * mainMenu;
    LevelView * levelView;
    QMenuBar * bar;
    QMenu * menu;

    void setMenuBar();
    void connectAll();

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

    explicit MainWindow(QWidget * = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_HPP
