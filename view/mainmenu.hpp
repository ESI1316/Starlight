#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

class MainMenu : public QWidget
{
    Q_OBJECT

public:

    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

signals:

    /*!
     * \brief Signale qu'un nouveau fichier a été séléctionné par l'utilisateur.
     *
     * \param newLevelFile Chemin vers le nouveau fichier selectionné.
     */
    void newLevelFileSelected(const QString newLevelFile);

public slots:

    /*!
     * \brief Permet de faire séléctionner un fichier de niveau à l'utilisateur.
     *
     * \param newLevelFile Chemin vers le nouveau fichier sélectionné.
     */
    void selectNewLevelFile();
};

#endif // MAINMENU_H
