#include <QtGui/QApplication>
#include <QLabel>
#include <QPixmap>
#include <QImage>
#include <QDesktopWidget>
#include "mainwindow.h"
#include "off.h"
#include <windows.h>
//#include <winuser.h>
#include <QDebug>
void taskbar(QLabel &label,int width,int height);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int x=QApplication::desktop()->width(),y=QApplication::desktop()->height();
    MainWindow w(x,y);
    Off off(x,y);
    off.setAttribute(Qt::WA_TranslucentBackground);
    off.setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint|Qt::Tool);//最前端和透明
    w.setFixedSize(x,y);
    w.setAttribute(Qt::WA_TranslucentBackground);
    w.setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint|Qt::Tool);//最前端和透明
    QImage image(":/image/3.png");
    QPixmap pixmap=QPixmap::fromImage(image.scaled(1477/2,1085/2));
    QLabel label;
    label.setFixedSize(1477/2,1085/2);
    label.setPixmap(pixmap);
    label.setAttribute(Qt::WA_TranslucentBackground);
    label.setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowStaysOnBottomHint);
    taskbar(label,x,y);
    label.show();
    off.show();
    w.show();
    QObject::connect(&off,SIGNAL(suspend_movie()),&w,SLOT(suspend()));
    QObject::connect(&off,SIGNAL(quit()),&a,SLOT(quit()));
    return a.exec();
}

void taskbar(QLabel &label,int width,int height)
{
    HWND hWnd = FindWindowA("Shell_TrayWnd",NULL);//函数原型：WINUSERAPI HWND WINAPI FindWindowA(LPCSTR,LPCSTR);
    RECT rccc;
    /*typedef struct tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT,*PRECT,*LPRECT;*/
    GetWindowRect(hWnd,&rccc);//函数原型：WINUSERAPI BOOL WINAPI GetWindowRect(HWND,LPRECT);
    //qDebug()<<"hwnd:"<<hWnd;
    int x=rccc.left;
    int y=rccc.top;
    qDebug()<<"x:"<<x<<"y:"<<y;
    if(x==0&&y==0)
        label.move(width-1477/2,height-1085/2);
    else if(x==0&&y!=0)
        label.move(width-1477/2,y-1085/2);
    else if(x!=0&&y==0)
        label.move(x-1477/2,height-1085/2);
    else
        qDebug()<<"error:"<<"x:"<<x<<",y:"<<y;
}
