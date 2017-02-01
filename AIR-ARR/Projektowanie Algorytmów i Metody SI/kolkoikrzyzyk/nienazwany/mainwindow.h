#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "naglowki.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
    int rozmiar;
    int rzad;
    int licznik;
    int poswietlenia[7][7];
    int piony[7][7];
    Gra gra;
    QMessageBox msg;

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    ~MainWindow();
    int preskaler(int a, int rozmiar);
    void podswietl(int x, int y);
    int skalowanaTab(int x,int y,int skala)
    {
        return poswietlenia[x/skala][y/skala];
    }
    int skalowanaTabPiony(int x, int y, int skala)
    {
        return piony[x/skala][y/skala];
    }

    void podwietlenia_init();
    void piony_init();
};

#endif // MAINWINDOW_H
