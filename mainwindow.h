#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMovie>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int x,int y,QWidget *parent = 0);
    //void mousePressEvent(QMouseEvent * event);
    ~MainWindow();
    QLabel label;
    QMovie movie;
signals:
    //void quit();//当当前窗口关闭时发射
public slots:
    void suspend();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
