#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QDebug>
MainWindow::MainWindow(int x,int y,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    label.setParent(this);
    label.setFixedSize(x,y);
    label.move(0,0);
    movie.setFileName(":/image/gif1920.gif");
    label.setMovie(&movie);
    movie.start();
}
void MainWindow::suspend()
{
    if(movie.state()==0)
    {
        this->show();
        movie.start();
    }
    else if(movie.state()==2)
    {
        this->close();
        movie.stop();
    }
}
MainWindow::~MainWindow()
{
}
