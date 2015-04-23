#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMenu>
#include <QMenuBar>
#include <QMainWindow>

class MainMenu;
class LevelView;

/*!
 * \brief Cette classe est la fenêtre principale du jeu qui englobe toutes les
 * autres vues. Elle permet, notamment, d'avoir un menu.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    /*!
     * \brief Le menu de sélection de niveau du jeu.
     */
    MainMenu * mainMenu;

    /*!
     * \brief La vue de la partie qui est lancée.
     */
    LevelView * levelView;

    /*!
     * \brief La bar de menu du jeu.
     */
    QMenuBar * bar;

    /*!
     * \brief Le menu principal du jeu.
     */
    QMenu * menu;

    /*!
     * \brief Configure la bar de menu.
     */
    void setMenuBar();

    /*!
     * \brief Créer toutes les connections SLOT / SIGNAL.
     */
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

    /*!
     * \brief Créer une fenêtre principale du jeu.
     */
    explicit MainWindow(QWidget * = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_HPP
