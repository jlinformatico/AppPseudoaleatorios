#include "dialog.h"
#include "ui_dialog.h"
#include <mainwindow.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //m=new MainWindow(this);

}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointpen(Qt::black);
    pointpen.setWidth(6);

    painter.drawLine(10,10,100,100);

    painter.setPen(pointpen);
    painter.drawPoint(10,20);
}
