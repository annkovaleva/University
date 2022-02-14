#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "D:\ter_ver\lab1\ap-master\ap.hpp"

enum Comb{
    comb_out,
    place_with,
    place_out
};

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
    ap_int<256> placeWith(ap_int<256> n, ap_int<256> m);
    ap_int<256> placeOut(ap_int<256> n, ap_int<256> m);
    ap_int<256> combOut(ap_int<256> n, ap_int<256> m);

public slots:
    void calculate();
    void formula();
};



#endif // MAINWINDOW_H
