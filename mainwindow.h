#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class Dialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //objeto constructor
    //MainWindow *m;
    Dialog *d; //d es la variable para mi dialog

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void generador();
    void generador_cuadmedios();
    void generador_prod_medios();
    void generador_multi_constante();
    void generador_lineal();
    void generador_cong_multi();
    void generador_cong_aditivo();
    void generador_cong_cuadratico();
    void generador_blum_blum();

    
private slots:
    void on_btnGenerar_clicked();

    void on_btnAplicarPrueba_clicked();

    void on_txtcantidad_textChanged(const QString &arg1);

    void on_btnAplicarMedias_clicked();

    void on_btnPrueba_arrabaj_media_clicked();

    void on_btn_importar_datos_clicked();

    void on_btn_vergrafica_clicked();

    void on_btn_chicuadrada_clicked();

    void on_cbogeneradores_currentIndexChanged(int index);

    void on_btn_PruebaVarianza_clicked();

    void on_btnPrueba_Poker_clicked();

    void on_btnPrueba_Series_clicked();

    void on_btnPrueba_Huecos_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
