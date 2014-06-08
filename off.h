#ifndef OFF_H
#define OFF_H

#include <QLabel>
#include <QImage>
#include <QPixmap>
class Off : public QLabel
{
    Q_OBJECT
public:
    explicit Off(int width,int height,QWidget *parent = 0);
    void mouseReleaseEvent(QMouseEvent *event);

    void enterEvent ( QEvent * event );
    void leaveEvent(QEvent *event);
    QImage image;
    QPixmap pixmap;
    int width,height;
signals:
    void suspend_movie();
    void quit();
public slots:

};

#endif // OFF_H
