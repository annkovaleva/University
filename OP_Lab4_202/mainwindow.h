#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Science.h"
#include "science_container.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void doRows(Science, int);

private:
    Ui::MainWindow *ui;
    QString enumToString(Area);
    int counter = 0;

    Science_container scienceList;

    char recordingForRandom[10][40]=
    {
        {"Космический корабль"},
        {"Радио"},
        {"Спирт"},
        {"Атомная бомба"},
        {"Реактивное топливо"},
        {"Процессор"},
        {"Чип"},
        {"Парабола"},
        {"Гипербола"},
        {"Бионический протез"},
    };


private slots:
    void clearRecording();
    void createRecording();
    void saveRecording();
    void showRecording();
    void changeTable();
    void randomRecordings();

    void build();
    void open();
    void saveBase();
    void saveHow();

    void exit();

};
#endif // MAINWINDOW_H
