#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Science.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Science invention[21];
    int lastScienceIndex = 0;
    int indexSave = 0;
    void doRows(Science, QString, QString, int);
    void shiftRecording();
    QString enumToString(Area);

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
};
#endif // MAINWINDOW_H
