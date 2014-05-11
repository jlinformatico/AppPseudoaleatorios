#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>

namespace Ui {
class Dialog;
}

//class MainWindow;

class Dialog : public QDialog
{
    Q_OBJECT
    //MainWindow *m;
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private:
    Ui::Dialog *ui;

protected:
    void paintEvent(QPaintEvent *e);//creamos el puntero para el QPaint
};

#endif // DIALOG_H
