/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_comb;
    QComboBox *combinations;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_form;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spin_n;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spin_m;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_2;
    QPushButton *calculate;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_ans;
    QLineEdit *answer;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(354, 297);
        MainWindow->setCursor(QCursor(Qt::PointingHandCursor));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_8 = new QVBoxLayout(centralWidget);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_comb = new QLabel(centralWidget);
        label_comb->setObjectName(QString::fromUtf8("label_comb"));

        verticalLayout->addWidget(label_comb);

        combinations = new QComboBox(centralWidget);
        combinations->addItem(QString());
        combinations->addItem(QString());
        combinations->addItem(QString());
        combinations->setObjectName(QString::fromUtf8("combinations"));

        verticalLayout->addWidget(combinations);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_form = new QLabel(centralWidget);
        label_form->setObjectName(QString::fromUtf8("label_form"));

        verticalLayout_2->addWidget(label_form);


        verticalLayout_4->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spin_n = new QSpinBox(centralWidget);
        spin_n->setObjectName(QString::fromUtf8("spin_n"));
        spin_n->setMinimum(1);
        spin_n->setMaximum(150);

        horizontalLayout->addWidget(spin_n);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spin_m = new QSpinBox(centralWidget);
        spin_m->setObjectName(QString::fromUtf8("spin_m"));
        spin_m->setMinimum(1);
        spin_m->setMaximum(150);

        horizontalLayout_2->addWidget(spin_m);


        verticalLayout_5->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_5);


        verticalLayout_7->addLayout(horizontalLayout_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        calculate = new QPushButton(centralWidget);
        calculate->setObjectName(QString::fromUtf8("calculate"));

        verticalLayout_6->addWidget(calculate);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_ans = new QLabel(centralWidget);
        label_ans->setObjectName(QString::fromUtf8("label_ans"));

        verticalLayout_3->addWidget(label_ans);

        answer = new QLineEdit(centralWidget);
        answer->setObjectName(QString::fromUtf8("answer"));
        answer->setReadOnly(true);

        verticalLayout_3->addWidget(answer);


        verticalLayout_6->addLayout(verticalLayout_3);


        verticalLayout_7->addLayout(verticalLayout_6);


        verticalLayout_8->addLayout(verticalLayout_7);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 354, 20));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_comb->setText(QCoreApplication::translate("MainWindow", "\320\222\320\260\321\200\320\270\320\260\320\275\321\202 \320\272\320\276\320\274\320\261\320\270\320\275\320\260\321\206\320\270\320\270", nullptr));
        combinations->setItemText(0, QCoreApplication::translate("MainWindow", "\320\241\320\276\321\207\320\265\321\202\320\260\320\275\320\270\321\217 \320\261\320\265\320\267 \320\277\320\276\320\262\321\202\320\276\321\200\320\265\320\275\320\270\320\271", nullptr));
        combinations->setItemText(1, QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\321\217 \321\201 \320\277\320\276\320\262\321\202\320\276\321\200\320\265\320\275\320\270\321\217\320\274\320\270", nullptr));
        combinations->setItemText(2, QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\321\217 \320\261\320\265\320\267 \320\277\320\276\320\262\321\202\320\276\321\200\320\265\320\275\320\270\320\271", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\321\203\320\273\320\260", nullptr));
        label_form->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "n", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "m", nullptr));
        calculate->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", nullptr));
        label_ans->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\264\320\273\321\217 \320\262\321\213\321\207\320\270\321\201\320\273\320\265\320\275\320\270\321\217 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\260 \320\272\320\276\320\274\320\261\320\270\320\275\320\260\321\206\320\270\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
