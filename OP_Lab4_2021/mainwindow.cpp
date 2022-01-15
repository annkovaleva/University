#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTableWidget>
#include <QFileDialog>
#include <QMessageBox>

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

    connect(ui->build, SIGNAL(clicked(bool)), this, SLOT (build()));
    connect(ui->open, SIGNAL(clicked(bool)), this, SLOT (open()));
    connect(ui->savee, SIGNAL(clicked(bool)), this, SLOT (saveBase()));
    connect(ui->savehow, SIGNAL(clicked(bool)), this, SLOT (saveHow()));

    connect(ui->exit, SIGNAL(clicked(bool)), this, SLOT (exit()));

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
    qDebug() << "10 random recordings";


    for(int j = 0; j<10; j++)
    {

        Science curScience;

        counter++;
        curScience.setId(counter);

        int areaForRandom = randomBetween(0, 4);
        curScience.setArea((Area)areaForRandom);

        curScience.setName(recordingForRandom[j]);

        int yearForRandom = randomBetween(1900, 2021);
        curScience.setYear(yearForRandom);

        int index = scienceList.append(curScience);

        doRows(curScience, index);

    }

    changeTable();
}

void MainWindow::createRecording()
{
    qDebug() << "create recording";

    Science curScience;
    counter++;
    curScience.setId(counter);
    curScience.setArea((Area)ui->AreaBox->currentIndex());
    curScience.setName(ui->NameLine->text());
    curScience.setYear(ui->YearBox->value());

    int newIndexRow = scienceList.append(curScience);

    doRows(curScience, newIndexRow);
}

void MainWindow::saveRecording()
{
    int indexRow = ui->table->currentRow();

    if(indexRow!=-1)
    {
        qDebug() << "save recording";

        Science cur;
        scienceList.record(indexRow, cur);
        int id = cur.getId();
        ui->table->removeRow(indexRow);

        Science curScience;
        curScience.setId(id);
        curScience.setArea((Area)ui->AreaBox->currentIndex());
        curScience.setName(ui->NameLine->text());
        curScience.setYear(ui->YearBox->value());

        int index = scienceList.update(curScience);

        doRows(curScience, index);
    }
    else
    {
        qDebug() << "error";
    }

}

void MainWindow::showRecording()
{
    qDebug() << "read only";

}

void MainWindow::clearRecording()
{
    int index1 = ui->table->currentRow();

    if(index1!=-1)
    {
        qDebug() << "clear recording";

        Science cur;
        scienceList.record(index1, cur);
        int id = cur.getId();
        ui->table->removeRow(index1);

        scienceList.remove(id);

        changeTable();

    }
    else
    {
        qDebug() << "error";
        ui->AreaBox->setCurrentIndex(0);
        ui->NameLine->setText("");
        ui->YearBox->setValue(1900);
    }
}

void MainWindow::changeTable()
{
    qDebug() << "show recording";

    int index = ui->table->currentRow();

    if(index!=-1)
    {
        Science curScience;
        scienceList.record(index, curScience);
        ui->AreaBox->setCurrentIndex(curScience.getArea());
        ui->NameLine->setText(curScience.getName());
        ui->YearBox->setValue(curScience.getYear());
    }

}

void MainWindow::doRows(Science curScience, int indexAdd)
{
    ui->table->insertRow(indexAdd);

    QTableWidgetItem* item3 = new QTableWidgetItem;
    char strId[10];
    _itoa_s(curScience.getId(), strId, 10);
    item3->setText(strId);
    ui->table->setItem(indexAdd, 0, item3);
    item3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText(enumToString(curScience.getArea()));
    ui->table->setItem(indexAdd, 1, item);
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem* item1 = new QTableWidgetItem;
    item1->setText(curScience.getName());
    ui->table->setItem(indexAdd, 2, item1);
    item1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    QTableWidgetItem* item2 = new QTableWidgetItem;
    char strYear[10];
    _itoa_s(curScience.getYear(), strYear, 10);
    item2->setText(strYear);
    ui->table->setItem(indexAdd, 3, item2);
    item2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);


    ui->table->setCurrentCell(indexAdd,0);

    ui->table->resizeColumnsToContents();

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

    return "not ok";
}

void MainWindow::build()
{ 
    int numberRow = ui->table->rowCount();

    for(int i = 0; i<numberRow; i++)
    {
        ui->table->removeRow(0);
    }

    scienceList.clear();
}

void MainWindow::open()
{
    scienceList.clear();
    int numberRow = ui->table->rowCount();

    for(int i = 0; i<numberRow; i++)
    {
        ui->table->removeRow(0);
    }

    QString strForSave = QFileDialog::getOpenFileName(this,
                                                      "Открыть файл",
                                                      "",
                                                      "GRASS (*.drugs.txt)");

    Science scienceCur;
    scienceList.load(strForSave);
    scienceList.records();

    QVector <Science> vectorScience;
    vectorScience = scienceList.records();

    for(int i=0; i<scienceList.count(); i++)
    {
        doRows(vectorScience[i], i);
    }

    int indexRows = ui->table->currentRow();

    if(indexRows!=-1)
    {
        changeTable();
    }
}

void MainWindow::saveBase()
{
    QString file = QFileDialog::getSaveFileName(this,
                                                      "Сохранить в новый файл",
                                                      "D:/lab2_var20/",
                                                      "GRASS (*.drugs.txt)");

    scienceList.saveInFile(file, 0, ui->numberRecord->value());
}

void MainWindow::saveHow()
{
    int numberRecords = ui->numberRecord->value();
    QStringList files = QFileDialog::getOpenFileNames(this,
                                                      "Открыть файлы",
                                                      "D:/lab2_var20/",
                                                      "GRASS (*.drugs.txt)");
    int numbers = files.count();
    int startRecordInFile = 0;
    for(int i = 0; i < numbers; i++)
    {
       QString strForSave = files[i];
       scienceList.saveInFile(strForSave, startRecordInFile, numberRecords);
       startRecordInFile=+numberRecords;
    }

}

void MainWindow::exit()
{
    QMessageBox msgBox;
    msgBox.setText("Do you want to save your file?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int trueBut = msgBox.exec();

    if(trueBut==0x00000800)
    {
        saveBase();
    }
}

