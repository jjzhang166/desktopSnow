#include "off.h"
#include <QMouseEvent>
#include <QDebug>
Off::Off(int newwidth,int newheight,QWidget *parent) :
    QLabel(parent)
{
    width=newwidth;
    height=newheight;
    this->setMouseTracking(true);
    image.load(":/image/1.png");
    pixmap=QPixmap::fromImage(image.scaled(80/1366.0*width,80/1366.0*width));
    this->setPixmap(pixmap);
    this->move(width/2-pixmap.width()/2,-70/80.0*pixmap.width());
    //qDebug()<<"width:"<<pixmap.width()<<",height:"<<pixmap.height();
}
void Off::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
        emit suspend_movie();
    else if(event->button()==Qt::RightButton)
        emit quit();
}
void Off::enterEvent(QEvent *event)
{
    this->move(width/2-pixmap.width()/2,-20/80.0*pixmap.width());
}
void Off::leaveEvent(QEvent *event)
{
    this->move(width/2-pixmap.width()/2,-70/80.0*pixmap.width());

}
