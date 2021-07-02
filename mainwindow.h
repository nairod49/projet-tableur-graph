#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QGuiApplication>

#include <QGraphicsScene>
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void change_couleur(QPushButton * boutton , QColor couleur);

    void newFile();

    void graph();

    void about();

    void aboutb();


private slots:


    void on_Buttoncolor1_clicked();

    void on_Buttoncolor2_clicked();

    void on_Buttoncolor3_clicked();

    void on_Buttoncolorfond_clicked();

    void on_Buttoncoloraxe_clicked();

    void on_Combotype_editTextChanged(const QString &arg1);

    void on_Buttonfont_clicked();

    void on_Spinlargeur_valueChanged(int arg1);



    void on_Spinhauteur_valueChanged(int arg1);

    void on_Spinmargex_valueChanged(int arg1);

    void on_Spinmargey_valueChanged(int arg1);

    void on_Spinpasx_valueChanged(int arg1);

    void on_Spinpasy_valueChanged(int arg1);

    void on_checkBoxgrill_stateChanged(int arg1);

private:


    Ui::MainWindow *ui;
    QString  stylegraph;
    QFont police;
    int largeur;
    int hauteur;
    int margex;
    int margey;
    int pasx;
    int pasy;
    bool montrergrill;

    QImage *image;

    QGraphicsScene *  scene;
    QPixmap * _pix;

    QColor  couleur1;
    QColor  couleur2;
    QColor  couleur3;
    QColor  couleurfond;
    QColor  couleuraxe;



};

#endif // MAINWINDOW_H
