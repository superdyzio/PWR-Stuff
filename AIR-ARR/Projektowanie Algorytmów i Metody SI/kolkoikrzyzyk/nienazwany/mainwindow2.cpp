#include "mainwindow.h"

MainWindow::MainWindow2(QWidget *parent) : QMainWindow(parent) {
    setMouseTracking(1);
    resize(600,600);
    lab = "Podaj rozmiar:";
}

MainWindow2::~MainWindow2() {}

