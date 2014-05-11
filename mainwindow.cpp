#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <dialog.h> // incluimos el dialogo que sera para la grafica
#include <QString>
#include <QStringList>
#include <QtWidgets>
#include <QtCore>
#include <QtGui>
#include <math.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

double r[100];
std::string c;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //aca se construye todo
    d=new Dialog(this);
    ui->txtSemilla2->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::cargardatos()
{
    Qfile file("Archivo.txt");
    if (!file.open(QIODevice::ReadOnly|QIODevice::Text))
        return;
    QTextStream in(&file);
    int row=0;
    while(!in.atEnd())
    {
        nn.model->setItem(row,0,new QStandardItem(in.readLine()));
        nn.model->setItem(row,1,new QStandardItem(in.readLine()));
        nn.model->setItem(row,2,new QStandardItem(in.readLine()));
        nn.model->setItem(row,3,new QStandardItem(in.readLine()));
        row++;
    }
}
*/
void MainWindow::on_btnGenerar_clicked()
{
    int operacion;
    operacion=0;
    //coge el indice de acuerdo al combobox
    operacion=ui->cbogeneradores->currentIndex();
    switch(operacion)
    {
    case 0:
        generador_cuadmedios();
    break;
    case 1:
        generador_prod_medios();
    break;
    case 2:
        generador_multi_constante();
    break;
    case 3:
        generador_lineal();
    break;
    case 4:
        generador_cong_multi();
    break;
    case 5:
        generador_cong_aditivo();
    break;
    case 6:
        generador_cong_cuadratico();
    break;
    case 7:
        generador_blum_blum();
    break;
   }
}

/* cargar datos a la grila
float num;
num=0.89;
ui->tableWidget->setItem(1,0,new QTableWidgetItem(QString::number(num)));
//tableWidget->setRowCount(n); // para saber cantidad de filas
*/
void MainWindow::on_txtcantidad_textChanged(const QString &arg1)
{
    //insertamos filas a la grilla
    int n;
    n=ui->txtcantidad->text().toInt();
    ui->tableWidget->setRowCount(0);//limpiamos la grilla
    for (int i=0; i<n;++i)
    {
        const int ultima_fila=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(ultima_fila);
    }
}

void MainWindow::generador()
{
    double num;
    int n;
    n=ui->txtcantidad->text().toInt();
    srand48(time(NULL));
    for (int i=0; i<n;++i)
    {
        num=drand48()*(0.001-0.999)+0.99;
        r[i]=num;
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(num)));
    }
}

void MainWindow::generador_cuadmedios()
{
    int semilla,p1,p2,x,nd,nx,j,nc,z,num,n;
    double f;
    std::string a;
    semilla=ui->txtSemilla->text().toInt();
    if(semilla<=1000)
    {
        QMessageBox::information(this,"Validacion","La Semilla debe ser de mayor a 3 digitos");
    }
    n=ui->txtcantidad->text().toInt();

    num=semilla;
    nx=1;
    while(num/10>0)
    {
        num=num/10;
        nx++;
    }

    x=pow(semilla,2);

    j=0;
    nd=nx;
    int i=0;

    while (j<n and x>=1000)
    {
        x=pow(semilla,2);
        std::string cadena = "";
        cadena = static_cast<std::ostringstream*>(&(std::ostringstream() << semilla))->str(); //convierte de entero a string
       // nd=cadena.size();
        num=semilla;
            nd=1;
            while(num/10>0)
            {
                num=num/10;
                nd++;
            }
            std::string cadena1 = "";
            cadena1 = static_cast<std::ostringstream*>(&(std::ostringstream() << x))->str();
            //nc=cadena1.size();
            num=x;
            nc=1;
            while(num/10>0)
            {
                num=num/10;
                nc++;
            }
            p1=(nc-nx)/2;
            p2=p1+nx-1;
            for(int i=p1;i<=p2;i++)
            {
                a=a+cadena1[i];
            }
        std::stringstream aleatoreo;
        aleatoreo << "0." << a; //concatenando  entre strings
        aleatoreo >>f; //convercio de string a Float  ,  f es una variable de tipo float
        std::istringstream(a)>>z; //convertir de string a int
        num=z;
        nd=1;
        while(num/10>0)
        {
            num=num/10;
            nd++;
        }
        semilla=z;
        r[j]=f;
        //if (r[j]==r[j-1])
        ui->tableWidget->setItem(j,0,new QTableWidgetItem(QString::number(f)));
        j++;
        //i++;
        a="";
    }

}

void MainWindow::generador_prod_medios()
{
    int semilla1,semilla2,p1,p2,n,y,nx,ny,j,z,num1,num2,num,yx,zz;
    double f;
    std::string a;
    semilla1=ui->txtSemilla->text().toInt();
    num1=semilla1;
            nx=1;

            while(num1/10>0)
            {
                num1=num1/10;
                nx++;
            }
            zz=nx;
    semilla2=ui->txtSemilla2->text().toInt();
    num2=semilla2;
            ny=1;
            while(num2/10>0)
            {
                num2=num2/10;
                ny++;
            }

    n=ui->txtcantidad->text().toInt();
    y=semilla1*semilla2;

    j=0;
    while (j<n and y>=1000 and nx>=4 and ny>=4)
        {
            y=semilla1*semilla2;

            num1=semilla1;
            nx=1;
            while(num1/10>0)
            {
                num1=num1/10;
                nx++;
            }

            num2=semilla2;
            ny=1;
            while(num2/10>0)
            {
                num2=num2/10;
                ny++;
            }

            std::string cadena1 = "";
            cadena1 = static_cast<std::ostringstream*>(&(std::ostringstream() << semilla1))->str();	//convierte de entero a string
            std::string cadena2 = "";
            cadena2 = static_cast<std::ostringstream*>(&(std::ostringstream() << semilla2))->str();	//convierte de entero a string
            std::string cadena3 = "";
            cadena3 = static_cast<std::ostringstream*>(&(std::ostringstream() << y))->str();
            //nc=cadena1.size();

            num=y;
            yx=1;
            while(num/10>0)
            {
                num=num/10;
                yx++;
            }
            p1=(yx-zz)/2;
            p2=p1+zz-1;

            for(int i=p1;i<=p2;i++)
            {
                a=a+cadena3[i];
            }

            std::stringstream aleatoreo;
            aleatoreo << "0." << a; //concatenando  entre strings
            aleatoreo >>f; //convercio de string a Float  ,  f es una variable de tipo float
            std::istringstream(a)>>z; //convertir de string a int

           semilla1=semilla2;
           semilla2=z;
           num1=semilla1;
            nx=1;
            while(num1/10>0)
            {
                num1=num1/10;
                nx++;
            }

            num2=semilla2;
            ny=1;
            while(num2/10>0)
            {
                num2=num2/10;
                ny++;
            }

           r[j]=f;
           ui->tableWidget->setItem(j,0,new QTableWidgetItem(QString::number(f)));
           j++;
           a="";
        }

}

void MainWindow::generador_multi_constante()
{
    int semilla1,constante,p1,p2,n,y,nx,ny,j,z,num1,num2,num,yx,zz;
    float f;//r[n+1];
    std::string a;
    semilla1=ui->txtSemilla->text().toInt();
    num1=semilla1;
    nx=1;

    while(num1/10>0)
    {
        num1=num1/10;
        nx++;
    }
    zz=nx;

    constante=ui->txtSemilla2->text().toInt();
    num2=constante;
    ny=1;
    while(num2/10>0)
    {
        num2=num2/10;
        ny++;
    }

    n=ui->txtcantidad->text().toInt();
    y=constante*semilla1;

    j=0;
    //nd=nx;
    while (j<n and y>=1000 and nx>=4 and ny>=4)
    {
        y=constante*semilla1;
        num1=semilla1;
        nx=1;
        while(num1/10>0)
        {
            num1=num1/10;
            nx++;
        }

        std::string cadena1 = "";
        cadena1 = static_cast<std::ostringstream*>(&(std::ostringstream() << semilla1))->str();	//convierte de entero a string

        std::string cadena2 = "";
        cadena2 = static_cast<std::ostringstream*>(&(std::ostringstream() << constante))->str();	//convierte de entero a string

        std::string cadena3 = "";
        cadena3 = static_cast<std::ostringstream*>(&(std::ostringstream() << y))->str();
        //nc=cadena1.size();
        num=y;
        yx=1;
        while(num/10>0)
        {
            num=num/10;
            yx++;
        }

        p1=(yx-zz)/2;
        p2=p1+zz-1;

        for(int i=p1;i<=p2;i++)
        {
            a=a+cadena3[i];
        }

        std::stringstream aleatoreo;
        aleatoreo << "0." << a; //concatenando  entre strings
        aleatoreo >>f; //convercio de string a Float  ,  f es una variable de tipo float
        std::istringstream(a)>>z; //convertir de string a int

       semilla1=z;
       //semilla2=z;

       num1=semilla1;
        nx=1;
        while(num1/10>0)
        {
            num1=num1/10;
            nx++;
        }
    ui->tableWidget->setItem(j,0,new QTableWidgetItem(QString::number(f)));
    j++;
    a="";
    }
}

void MainWindow::generador_lineal()
{
    generador();
}

void MainWindow::generador_cong_multi()
{
    generador();
}

void MainWindow::generador_cong_aditivo()
{
    generador();
}

void MainWindow::generador_cong_cuadratico()
{
    generador();
}

void MainWindow::generador_blum_blum()
{
    generador();
}

void MainWindow::on_btnAplicarPrueba_clicked()
{
    double na,uco,oco,zo,alfa,ztabla,z;
    int i,k=0,s[100],n,co;
    n=ui->txtcantidad->text().toInt();
    //matriz preparada para 64 numeros
    //manipular los limites de la matriz con ncolum,nrow
    for (i=0; i<n;++i)
    {
        //r[k]=ui->tableWidget->item(i,0)->text().toDouble();
        k++;
            //ui->mostrando->setText(QString::number(numero));
    }
    ztabla=1.96;//nivel de confianza de 95%
    na=95;//debe ser ingresado por teclado
    alfa=(100-na)/100;
    for(i=0;i<n-1;++i)
    {
        if(r[i+1]<=r[i])
        {
            s[i]=0;
        }
                else
                {
                    s[i]=1;
                }

                if(i!=0)
                {
                    if(s[i]!=s[i-1])
                    {
                        co++;
                    }
                    else
                    {
                    }
                }
                else
                {
                    co=1;
                }
        }
    ui->lblco->setText(QString::number(co));
    uco=(2*n-1)/3;
    ui->lbluco->setText(QString::number(uco));
    oco=(16*n-29)/90;
    ui->lbloco->setText(QString::number(oco));
    z=(co-uco)/sqrt(oco);
    zo=abs(z);
    ui->lblz->setText(QString::number(zo));

    if (zo>ztabla)
        {
            ui->txtresultado->setText("Se recheza la hipotesis de que todos los valores son independientes");
        }
        else
        {
           ui->txtresultado->setText("No se puede rechazar la hipotesis con una probabilidad del 95%");
        }
}


void MainWindow::on_btnAplicarMedias_clicked()
{
    double x,LI,LS,c,t,n;
    int i,j;
    n=ui->txtcantidad->text().toInt();
    t=1.96;
    x=0;

    for (i=0; i<n;++i)
    {
        //r[k]=ui->tableWidget->item(i,j)->text().toDouble();
        x=x+r[i];
        //k++;
    }
    //ui->demo->setText(QString::number(c));
    x=x/n;

    ui->lblmedia->setText(QString::number(x));
    LI= (t)*(1/(sqrt(12*n)));
    //ui->prueba->setText(QString::number(LI));
    LI=0.5-LI;
    ui->lbl_li->setText(QString::number(LI));
    LS= (t)*(1/(sqrt(12*n)));
    LS=0.5+LS;
    ui->lbl_ls->setText(QString::number(LS));

//  "X" vendria  a ser  la MEDIA
       if(x>LI)
        {
            if(x<LS)
            {
                ui->textBrowser->setText("No se rechaza el conjunto r(i) ");
            }
            else
           {
           ui->textBrowser->setText("Se rechaza el conjunto r(i) ");
           }

        }
       else

        {
           ui->textBrowser->setText("Se rechaza el conjunto r(i) ");
        }
}

void MainWindow::on_btnPrueba_arrabaj_media_clicked()
{
    int i,n,co,s[100],n1=0,n0=0;
    double na,uco,oco,zo,alfa,ztabla;
    n=ui->txtcantidad->text().toInt();
    //matriz preparada para 64 numeros
    //manipular los limites de la matriz con ncolum,nrow
    ztabla=1.96;//nivel de confianza de 95%
    na=95;//debe ser ingresado por teclado
    alfa=(100-na)/100;

    for(i=0;i<=n-1;i++)
    {
            if(r[i]>0.5)
            {
                s[i]=1;
                n1++;
            }
            else
            {
                s[i]=0;
                n0++;
            }

            if(i!=0)
            {
                if(s[i]!=s[i-1])
                    co++;
            }
            else
            {
                co=1;
            }
    }

    //zo=(co-uco)/oco;
    ui->lblco->setText(QString::number(co));
    uco=(2*n0*n1)+1/2;
    ui->lbluco->setText(QString::number(uco));
    oco=(2*n0*n1*(2*n0*n1-n))/n*n*(n-1);
    ui->lbloco->setText(QString::number(oco));
    //z=(co-uco)/sqrt(oco);
    zo=(co-uco)/oco;
    ui->lblz->setText(QString::number(zo));

    if (zo>ztabla)
        {
            ui->txtresultado->setText("Se recheza la hipotesis de que todos los valores son independientes");
        }
        else
        {
           ui->txtresultado->setText("No se puede rechazar la hipotesis con una probabilidad del 95%");
        }
}

//cargar datos dede un txt
void MainWindow::on_btn_importar_datos_clicked()
{
    int nx,k,n;
    std::string a;
    float f;
    std::ifstream hola("ejemplo.txt");
    hola >> c;
    hola.close();
    //***************************************************************
    std::stringstream aleatoreo;
    aleatoreo <<c; //concatenando  entre ifstream hola("ejemplo.txt");strings
    aleatoreo >> f; //Nunero FLoat
    std::string str (c);
    /*std::cout << "The size of str is " << str.size() << " characters.\n";*/
    nx=str.size();//Hallando la linguitud del array
    n=0;
    k=0;
    for(int i=0;i<=nx-1;i++)
    {
        if(c[i]==',')
        {
            r[k]=f;
            k++;
            //reiniciar
            a="";
            i=i+1;
            a=a+c[i];
            std::stringstream aleatoreo;
            aleatoreo <<a; //concatenando  entre strings
            aleatoreo >> f; //convertiendo a un numero float
            n++;
        }
        else
        {
           a=a+c[i];
           std::stringstream aleatoreo;
                aleatoreo <<a; //concatenando  entre strings
                aleatoreo >> f; //convertiendo a un numero float
        }

        if(i==nx-1)
        {
            r[k]=f;
            k++;
            n++;
        }

    }
    ui->txtcantidad->setText(QString::number(n));
    //PREPARAR GRILLA
    ui->tableWidget->setRowCount(0);//limpiamos la grilla
    for (int i=0; i<n;++i)
    {
        const int ultima_fila=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(ultima_fila);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(r[i])));
    }
    //ui->tableWidget->setItem(1,0,new QTableWidgetItem(QString::fromStdString(a)));
    //n=r.size();
    for (int i=0;i<n;i++)
    {
        //ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(r[i])));
    }
    //ui->txtresultado->setText(QString::fromStdString(cadena3));
}

void MainWindow::on_btn_vergrafica_clicked()
{
    //d->exec(); // es para que el dialog se posicione sobre el form maestro
    d->show();//para mostrar el dialog
    //int x;
    //x=ui->txt_X->text().toInt();
    //d->paintEvent(x);
}

void MainWindow::on_btn_chicuadrada_clicked()
{
    QStringList hlabels;
    int n,m,k,j,i;
    double O[1000],xo[1000],na,si,nsi,alfa,ztabla,ei,xo2,ini,fin;
    n=ui->txtcantidad->text().toInt();
    m=sqrt(n);
    ztabla=1.96;//nivel de confianza de 95%
    na=95;//debe ser ingresado por teclado
    alfa=(100-na)/100;
    ei=n/m;
    si=n/100;
    nsi=m;
    ini=0;
    fin=si;
    k=0;
    xo2=0;
    do
    {
        j=0;
        for(i=0;i<n-1;i++)
        {
            if(r[i]>=ini and r[i]<=fin)
            {
                j++;
            }
        }
        O[k]=j;
        xo[k]=(ei-O[k])/ei;
        xo2=xo2+xo[k];
        ini=fin;
        fin=2*si;
        k++;
    }while(k<=m);
    //Preparar grilla
    //ui->tableWidget_2 = new QTableWidget(this);
    ui->tableWidget_2->setRowCount(10);
    ui->tableWidget_2->setColumnCount(4);
                 // almacenamos en variables el nro de filas y columnas
         //rowCount = ui->tableWidget_2->rowCount();
         //colCount = ui->tableWidget_2->columnCount();
         // Texto en la cabecera de la tabla
    hlabels << "Intervalo" << "O[]" << "Ei" << "XO=";
    ui->tableWidget_2->setHorizontalHeaderLabels(hlabels);
        for (int i=0; i<4;++i)
        {
            const int ultima_fila=ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(ultima_fila);
        }
        //resultados del chi-cuadrado
        for(int i=0;i<m;i++)
        {
            ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(QString::number(O[i])));
            ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(QString::number(ei)));
            ui->tableWidget_2->setItem(i,3,new QTableWidgetItem(QString::number(xo[i])));
        }
    if(xo2<ztabla)
         ui->txtresultado_2->setText("No se puede rechazar que todos los valores siguen una distribucion uniforme");
    else
         ui->txtresultado_2->setText("Se rechaza la hipotesis de que todos los valores son uniformes");
}

//manipular controles de los objetos al escoger las opciones del COMBOBOX
void MainWindow::on_cbogeneradores_currentIndexChanged(int index)
{
    int operacion;
    operacion=0;
    //coge el indice de acuerdo al combobox
    operacion=ui->cbogeneradores->currentIndex();
    switch(operacion)
    {
    case 0:
        ui->txtSemilla2->setVisible(false);
    break;
    case 1:
        ui->txtSemilla2->setVisible(true);
        ui->txtSemilla2->setText("2da Semilla");
    break;
    case 2:
        ui->txtSemilla2->setVisible(true);
        ui->txtSemilla2->setText("Constante");
    break;
    case 3:
        ui->txtSemilla2->setVisible(false);
    break;
    case 4:
        ui->txtSemilla2->setVisible(false);
    break;
    case 5:
        ui->txtSemilla2->setVisible(false);
    break;
    case 6:
        ui->txtSemilla2->setVisible(false);
    break;
    case 7:
        ui->txtSemilla2->setVisible(false);
    break;
    }
}

void MainWindow::on_btn_PruebaVarianza_clicked()
{
    int n;
    double x,v,LI,LS,c,t,aux;
    n=ui->txtcantidad->text().toInt();
    //matriz preparada para 64 numeros
    //manipular los limites de la matriz con ncolum,nrow
    x=0;
       for(int i=1;i<=n;i++)
       {
            if(r[i]>=0 && r[i]<1)
            {
               x=x+r[i];

            }
            else
            {
               i--;
            }
       }

       x=x/n;

       v=0;
       aux=0;
       for(int i=1;i<=n;i++)
        {
               aux=aux+((r[i]-x)*(r[i]-x));

        }

       v=aux/(n-1);
       ui->lblmedia_2->setText(QString::number(v));
       t=58.1200541;
       LS= (t)/(12*(n-1));
       ui->lbl_ls_2->setText(QString::number(LS));
       t=23.6543003;
       LI= (t)/(12*(n-1));
        ui->lbl_li_2->setText(QString::number(LI));

       if(v>LI)
        {
            if(v<LS)
            {
                ui->textBrowser_2->setText("No se rechaza el conjunto r(i) con un nivel de aceptación de 1/12");
            }
            else
           {
                ui->textBrowser_2->setText("Se rechaza el conjunto r(i)");
           }
        }
       else
        {
           ui->textBrowser_2->setText("Se rechaza el conjunto r(i)");
        }
}

void MainWindow::on_btnPrueba_Poker_clicked()
{
    char a[5];
    QStringList hlabels;
    float cat[7];int w[5],k=0,tope=-1,i=0,tux=0,r=0,ceros=0,unos=0,dos=0,tres=0,cuatros=0;
    //AQUI EMPIEZO EL ALGORITMO
    //INICIALIZAR W
    for(int m=0;m<=4;m++)
    {w[m]=0;}
    //INICIALIZAR CAT
    for(int m=0;m<=6;m++)
    {cat[m]=0;}
    int cantidad=0;
    // EMPEZANDO
    while(c[i]=='0'&&c[i+1]=='.'&&k==0)
    {	r=i+2;cantidad++;
        for(int j=0;j<=4;j++)
        {	if(tope==-1)
            {tope++;a[tope]=c[r];}
            else
            {	for(int h=0;h<=tope;h++)
                {	if(c[r]==a[h])
                    {	w[h]=w[h]+1;
                        h=tope+1;
                        tux=1;
                    }
                    else{tux=0;}
                }
                if(tux==0)
                { 	tope++;
                    a[tope]=c[r];
                }
                else{}
            }
            r++;
        }
        for(int j=0;j<=4;j++)
        {	switch(w[j])
            {	case 0:ceros++;break;
                case 1:unos++;break;
                case 2:dos++;break;
                case 3:tres++;break;
                case 4:cuatros++;break;
            }
        }

        if(ceros==5)
        {	cat[0]=cat[0]+1;}
        else
        {	if(unos==1&&ceros==4)
            {cat[1]++;}
            else
            {	if(unos==2&&ceros==3)
                {	cat[2]++;}
                else
                {	if(unos==1&&dos==1&&ceros==3)
                    {	cat[3]++;}
                    else
                    {	if(dos==1&&ceros==4)
                        {cat[4]++;}
                        else
                        {	if(tres==1&&ceros==4)
                            {cat[5]++;}
                            else
                            {	if(cuatros==1&&ceros==4)
                                {cat[6]++;}
                                else{}
                            }
                        }
                    }
                }
            }
        }

        //INICIALIZANDO LAS VARIABLES
        i=i+8;

        if(c[i-1]==',')
        {	ceros=0;unos=0;dos=0;tres=0;cuatros=0;
            for(int m=0;m<=4;m++)
            {w[m]=0;}
            tope=-1;tux=0;
        }
        else
        {	k=1;}

    }

    //CALCULAR LA ESPERANZA Y CHI CUAD.
    double prob[7];
    double esp[7];
    prob[0]=0.3024;
    prob[1]=0.5040;
    prob[2]=0.1080;
    prob[3]=0.0090;
    prob[4]=0.0720;
    prob[5]=0.0045;
    prob[6]=0.0001;

    //Preparar grilla
    //ui->tableWidget_2 = new QTableWidget(this);
    ui->tableWidget_3->setRowCount(7);
    ui->tableWidget_3->setColumnCount(4);
                 // almacenamos en variables el nro de filas y columnas
         //rowCount = ui->tableWidget_2->rowCount();
         //colCount = ui->tableWidget_2->columnCount();
         // Texto en la cabecera de la tabla
    hlabels << "Categorias" << "O[]" << "Ei" << "XO=";
    ui->tableWidget_3->setHorizontalHeaderLabels(hlabels);
    //titulos de las categorias
            ui->tableWidget_3->setItem(0,0,new QTableWidgetItem(QString("Todas Diferentes")));
            ui->tableWidget_3->setItem(1,0,new QTableWidgetItem(QString("Exactamente impar")));
            ui->tableWidget_3->setItem(2,0,new QTableWidgetItem(QString("Dos Pares")));
            ui->tableWidget_3->setItem(3,0,new QTableWidgetItem(QString("Una tercia y un par")));
            ui->tableWidget_3->setItem(4,0,new QTableWidgetItem(QString("Tercia")));
            ui->tableWidget_3->setItem(5,0,new QTableWidgetItem(QString("Poker")));
            ui->tableWidget_3->setItem(6,0,new QTableWidgetItem(QString("Quintilla")));

    for(int m=0;m<=6;m++)
        {
            ui->tableWidget_3->setItem(m,1,new QTableWidgetItem(QString::number(cat[m])));
        }
   //ESCRIBIENDO Ei
    for(int m=0;m<=6;m++)
    {	esp[m]=prob[m]*cantidad;
        ui->tableWidget_3->setItem(m,2,new QTableWidgetItem(QString::number(esp[m])));
    }

    //ESTADISTICO CHI
    double est[7],chicalc=0,y;
    for(int m=0;m<=6;m++)//PARA CALCULAR EL ESTADISTICO CHI CUADRADO
    {	y=esp[m]-cat[m];
        est[m]=(pow(y,2))/esp[m];
        chicalc=chicalc+est[m];
    }

    for(int m=0;m<=6;m++)
    {
       ui->tableWidget_3->setItem(m,3,new QTableWidgetItem(QString::number(est[m])));
    }

    ui->lblmensaje->setText("Considerando aceptacion 95% y grado de libertad 6");
    ui->lblchicalc->setText(QString::number(chicalc));

    double chitabla=12.592;
    ui->lblchitabla->setText(QString::number(chitabla));

    if(chicalc>chitabla)
    {
        ui->txtresultado_3->setText("Se rechaza que los numeros del conjunto r son independientes");
    }
    else
    {
        ui->txtresultado_3->setText("No se puede rechaza que los numeros del conjunto r son independientes");
    }

}

void MainWindow::on_btnPrueba_Series_clicked()
{
    QStringList hlabels;
    //Preparar grilla
    //ui->tableWidget_2 = new QTableWidget(this);
    ui->tableWidget_4->setRowCount(10);
    ui->tableWidget_4->setColumnCount(4);
    hlabels << "Intervalo" << "O[i]" << "E[i]" << "X2O=";
    ui->tableWidget_4->setHorizontalHeaderLabels(hlabels);
}

void MainWindow::on_btnPrueba_Huecos_clicked()
{
    QStringList hlabels;
    //Preparar grilla
    //ui->tableWidget_2 = new QTableWidget(this);
    ui->tableWidget_5->setRowCount(10);
    ui->tableWidget_5->setColumnCount(4);
    hlabels << "Tamaño del Hueco[i]" << "O[i]" << "Ei" << "XO=";
    ui->tableWidget_5->setHorizontalHeaderLabels(hlabels);
}
