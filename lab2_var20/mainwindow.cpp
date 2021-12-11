#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
//#include <stdio.h>
//#include <QtGlobal>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->create, SIGNAL(clicked(bool)), this, SLOT (createRecording()));
    connect(ui->save, SIGNAL(clicked(bool)), this, SLOT (saveRecording()));
    connect(ui->clear, SIGNAL(clicked(bool)), this, SLOT (clearRecording()));
    connect(ui->table, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(showRecording()));
    connect(ui->table, SIGNAL(cellClicked(int, int)), this, SLOT (changeTable()));
    connect(ui->random, SIGNAL(clicked(bool)), this, SLOT (randomRecordings()));
    ui->table->resizeColumnsToContents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

static int randomBetween(int low, int high)
{
    return (rand() % ((high + 1) - low) + low);
}

void MainWindow::randomRecordings()
{
    if (lastScienceIndex >= 20)
    {
        qDebug() << "error";
        return;
    }
    else
    {
        qDebug() << "10 random recordings";
    }

    for(int j = 0; j<10; j++)
    {

        Science curScience;

        int areaForRandom = randomBetween(0, 4);
        curScience.setArea((Area)areaForRandom);

        curScience.setName(recordingForRandom[j]);

        int yearForRandom = randomBetween(1900, 2021);
        curScience.setYear(yearForRandom);

        doRows(curScience, enumToString((Area)areaForRandom), recordingForRandom[j], yearForRandom);
    }
}

void MainWindow::createRecording()
{
    if(!indexSave)
    {
        if (lastScienceIndex == 20)
        {
            qDebug() << "error";
            return;
        }
        else
        {
            qDebug() << "create recording";
        }
    }

    Science curScience;
    curScience.setArea((Area)ui->AreaBox->currentIndex());
    curScience.setName(ui->NameLine->text());
    curScience.setYear(ui->YearBox->value());

    doRows(curScience, ui->AreaBox->currentText(), ui->NameLine->text(), ui->YearBox->value());
}

void MainWindow::saveRecording()
{
    qDebug() << "save recording";

    shiftRecording();

    indexSave = 1;

    createRecording();

    indexSave = 0;
}

void MainWindow::showRecording()
{
    qDebug() << "read only";

}

void MainWindow::clearRecording()
{
    qDebug() << "clear recording";

    if(!lastScienceIndex)
    {
        return;
    }

    shiftRecording();
}

void MainWindow::changeTable()
{
    qDebug() << "show recording";

    int index = ui->table->currentRow();

    ui->AreaBox->setCurrentIndex(invention[index].getArea());
    ui->NameLine->setText(invention[index].getName());
    ui->YearBox->setValue(invention[index].getYear());

}

void MainWindow::doRows(Science curScience, QString areaForRow, QString nameForRow, int yearForRow)
{
    int indexAdd = 0;

    while ((indexAdd < lastScienceIndex) && (curScience >= invention[indexAdd]))
    {
        indexAdd++;
    }


    for (int i = lastScienceIndex; i >= indexAdd; i--)
    {
        invention[i + 1] = invention[i];

    }

    lastScienceIndex++;

    invention[indexAdd] = curScience;

    ui->table->insertRow(indexAdd);

    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText(areaForRow);
    ui->table->setItem(indexAdd, 0, item);
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem* item1 = new QTableWidgetItem;
    item1->setText(nameForRow);
    ui->table->setItem(indexAdd, 1, item1);
    item1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem* item2 = new QTableWidgetItem;
    char strYear[10];
    _itoa_s(yearForRow, strYear, 10);
    item2->setText(strYear);
    ui->table->setItem(indexAdd, 2, item2);
    item2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    ui->table->setCurrentCell(indexAdd,0);

    ui->table->resizeColumnsToContents();

}

void MainWindow::shiftRecording()
{
    int index = ui->table->currentRow();

    ui->table->removeRow(index);

    for (int i = index; i < lastScienceIndex; ++i)
    {
        invention[i] = invention[i+1];
    }

    lastScienceIndex--;
}

QString MainWindow::enumToString(Area area)
{
    if (area == Area::Math)
    {
        return "Математика";
    }

    if (area == Area::Biology)
    {
        return "Биология";
    }

    if (area == Area::Electronics)
    {
        return "Электроника и ВТ";
    }

    if (area == Area::Physics)
    {
        return "Физика";
    }

    if (area == Area::Chemistry)
    {
        return "Химия";
    }

}


