#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "D:\ter_ver\lab1\ap-master\ap.hpp"
#include <qpixmap.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("form1.png");
    ui->label_form->setPixmap(pix);

    connect(ui->calculate, SIGNAL (clicked(bool)), this, SLOT(calculate()));
    connect(ui->combinations, SIGNAL (currentIndexChanged(int)), this, SLOT (formula()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculate()
{
    ap_int<256> n = ui->spin_n->value();
    ap_int<256> m = ui->spin_m->value();
    ap_int<256> answer;

    Comb type = (Comb)ui->combinations->currentIndex();


    if(type == 0)
    {
        answer = combOut(n, m);
    }
    else if (type == 1)
    {
        answer = placeWith(n, m);
    }
    else
    {
        answer = placeOut(n, m);
    }

    QString str;

    if(answer != 0)
    {
        std::string str;
        str = std::string(answer);
        QString qstr = QString::fromStdString(str);
        ui->answer->setText(qstr);
    }
    else
    {
        ui->answer->setText("invalid input data");
    }

}

ap_int<256> fact(ap_int<256> a)
{
    ap_int<256> answer = 1;
    for(int i=1; i<=a; i++)
    {
        answer *= i;
    }
    return answer;
}

ap_int<256> MainWindow::placeWith(ap_int<256> n, ap_int<256> m)
{
    ap_int<256> answer = 1;
    for(int i=1; i<m; i++)
    {
        answer *= n;
    }
    return answer;
}

ap_int<256> MainWindow::placeOut(ap_int<256> n, ap_int<256> m)
{
    if(m<=n)
    {
        return fact(n)/fact(n-m);
    }

    return 0;
}

ap_int<256> MainWindow::combOut(ap_int<256> n, ap_int<256> m)
{
    if(m<=n)
    {
        ap_int<256> a = n-m;
        ap_int<256> answer1;
        ap_int<256> answer2;
        answer1 = fact(n);
        answer2 = fact(m)*fact(a);
        answer1 = answer1/answer2;
        return answer1;
    }

    return 0;
}

void MainWindow::formula()
{
    Comb type = (Comb)ui->combinations->currentIndex();

    if(type == 0)
    {
        QPixmap pix1("form1.png");
        ui->label_form->setPixmap(pix1);
    }
    else if (type == 1)
    {
        QPixmap pix2("form2.png");
        ui->label_form->setPixmap(pix2);
    }
    else
    {
        QPixmap pix3("form3.png");
        ui->label_form->setPixmap(pix3);
    }
}






