#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setMouseTracking(1);
    resize(600,600);
    rozmiar=6;
    rzad=4;
    licznik = 0;
    gra=Gra(rozmiar,rzad);
    podwietlenia_init();
    piony_init();
}

void MainWindow::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    int szerokosc = 600/rozmiar;
    for (int x = 0; x < 600; x += szerokosc)
        for (int y = 0; y < 600; y += szerokosc) {
            p.setBrush(Qt::white);
            if(skalowanaTab(x,y,szerokosc))
                p.setBrush(Qt::cyan);
            p.drawRect(x,y,szerokosc-5,szerokosc-5);
            if(gra.plansza[y/szerokosc][x/szerokosc]==*GRACZ) {
                p.setBrush(Qt::black);
                p.drawLine(x+10,y+10,x+szerokosc-10,y+szerokosc-10);
                p.drawLine(x+10,y+szerokosc-10,x+szerokosc-10,y+10);
            }
            if(gra.plansza[y/szerokosc][x/szerokosc]=='O') {
                p.setBrush(Qt::red);
                p.drawEllipse(x+2,y+2,szerokosc-10,szerokosc-10);
                p.setBrush(Qt::white);
                p.drawEllipse(x+7,y+7,szerokosc-20,szerokosc-20);
            }
        }
}

void MainWindow::mousePressEvent(QMouseEvent *e) {
    int x = preskaler(e->x(),rozmiar);
    int y = preskaler(e->y(),rozmiar);
    bool koniec = false;
    if (gra.plansza[y][x] == ' ') {
        gra.plansza[y][x]=*GRACZ;
        licznik++;
        if (gra.miejsca_wolne()) {
            setMouseTracking(0);
            gra.ruch(*SI,licznik);
            setMouseTracking(1);
        }
    }
    if (gra.wygrana(*GRACZ,false)) {
        msg.setText("Wygral gracz.");
        msg.exec();
        koniec = true;
    } else {
        if (gra.wygrana(*SI,false)) {
            msg.setText("Wygral komputer.");
            msg.exec();
            koniec = true;
        } else {
            if (gra.remis(false)) {
                msg.setText("Remis");
                msg.exec();
                koniec = true;
            }
        }
    }
    if(koniec) {
        this->close();
        return;
    }
    update();
}
void MainWindow::mouseMoveEvent(QMouseEvent *e) {
    int x = preskaler(e->x(),rozmiar);
    int y = preskaler(e->y(),rozmiar);
    podswietl(x,y);
    update();
}

int MainWindow::preskaler(int a, int rozmiar) {
    bool znaleziono = 0;
    int licznik = 0;
    int szerokosc = 600/rozmiar;
    while(znaleziono == 0 && licznik<rozmiar) {
        if(a >= licznik*szerokosc && a <= (licznik+1)*szerokosc)
            znaleziono=1;
        licznik++;
    }
    return licznik-1;
}

void MainWindow::podswietl(int x, int y) {
    for(int xx=0;xx<7;xx++)
        for(int yy=0;yy<7;yy++)
            poswietlenia[xx][yy]=0;
        poswietlenia[x][y]=1;
}

void MainWindow::podwietlenia_init() {
    for(int xx=0;xx<7;xx++)
        for(int yy=0;yy<7;yy++)
            poswietlenia[xx][yy]=0;
}

void MainWindow::piony_init() {
    for(int xx=0;xx<7;xx++)
        for(int yy=0;yy<7;yy++)
            piony[xx][yy]=0;
}

MainWindow::~MainWindow() {}
