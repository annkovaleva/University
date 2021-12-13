#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->oneInListOne, SIGNAL(clicked(bool)), this, SLOT (oneInOne()));
    connect(ui->twoInListTwo, SIGNAL(clicked(bool)), this, SLOT (twoInTwo()));
    connect(ui->allInListOne, SIGNAL(clicked(bool)), this, SLOT (allInOne()));
    connect(ui->allInListTwo, SIGNAL(clicked(bool)), this, SLOT (allInTwo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::oneInOne()
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setText("1");
    ui->listOne->addItem(item);
    number1++;
}

void MainWindow::twoInTwo()
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setText("2");
    ui->listTwo->addItem(item);
    number2++;
}

void MainWindow::allInOne()
{
    int a=0;

    for(int j=0; j<number1; j++)
    {
        QListWidgetItem *item = ui->listOne->item(j);
        numbers[a] = item->text();
        a++;
    }

    for(int j=0; j<number2; j++)
    {
        QListWidgetItem *item = ui->listTwo->item(j);
        numbers[a] = item->text();
        a++;
    }

    for(int i=0; i<number1; i++)
    {
        ui->listOne->takeItem(0);
    }

    for(int i=0; i<number2; i++)
    {
        ui->listTwo->takeItem(0);
    }


    for(int i=0; i<(number1+number2); i++)
    {
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(numbers[i]);
        ui->listOne->addItem(item);
    }

    number1=number1+number2;
    number2=0;
}

void MainWindow::allInTwo()
{
    int a=0;

    for(int j=0; j<number2; j++)
    {
        QListWidgetItem *item = ui->listTwo->item(j);
        numbers[a] = item->text();
        a++;
    }

    for(int j=0; j<number1; j++)
    {
        QListWidgetItem *item = ui->listOne->item(j);
        numbers[a] = item->text();
        a++;
    }

    for(int i=0; i<number1; i++)
    {
        ui->listOne->takeItem(0);
    }

    for(int i=0; i<number2; i++)
    {
        ui->listTwo->takeItem(0);
    }

    for(int i=0; i<(number1+number2); i++)
    {
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(numbers[i]);
        ui->listTwo->addItem(item);
    }

    number2=number1+number2;
    number1=0;
}







