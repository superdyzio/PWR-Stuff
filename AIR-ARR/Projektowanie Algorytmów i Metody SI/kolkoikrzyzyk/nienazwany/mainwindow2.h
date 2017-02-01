#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QLabel>
#include <QButtonGroup>
#include "naglowki.h"


class MainWindow2 : public QMainWindow
{
    Q_OBJECT
public:
    int rozmiar;
    int rzad;
    QMessageBox msg;
    QLabel lab;

public:
    explicit MainWindow2(QWidget *parent = 0);
    ~MainWindow2();
} typedef MainWindow2;

#endif // MAINWINDOW2_H
