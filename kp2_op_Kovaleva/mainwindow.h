#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int number1 = 0;
    int number2 = 0;
    QString numbers[1000];

private slots:
    void oneInOne();
    void twoInTwo();
    void allInOne();
    void allInTwo();
};

#endif // MAINWINDOW_H
