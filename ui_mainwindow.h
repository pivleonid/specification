/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QPushButton *pushButtonPath;
    QPushButton *pushButtonLoad;
    QLabel *labelPath;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLineEdit *lineEdit_Razrab;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_Proveril;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QLineEdit *lineEdit_Hkontr;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QLineEdit *lineEdit_Ytverdil;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QLineEdit *lineEdit_FirmaIzgotov;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_9;
    QLineEdit *lineEdit_DecimalNumber;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_10;
    QLineEdit *lineEdit_Naimenovanie1;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_11;
    QLineEdit *lineEdit_Naimenovanie2;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_12;
    QLineEdit *lineEdit_Numeracia;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonStart;
    QSpacerItem *horizontalSpacer;
    QTextBrowser *textBrowser;
    QLabel *label_13;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(717, 443);
        MainWindow->setMinimumSize(QSize(717, 443));
        MainWindow->setMaximumSize(QSize(717, 443));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        labelName = new QLabel(groupBox);
        labelName->setObjectName(QStringLiteral("labelName"));

        gridLayout->addWidget(labelName, 0, 1, 2, 1);

        lineEditName = new QLineEdit(groupBox);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setMaximumSize(QSize(189, 16777215));

        gridLayout->addWidget(lineEditName, 1, 2, 2, 1);

        pushButtonPath = new QPushButton(groupBox);
        pushButtonPath->setObjectName(QStringLiteral("pushButtonPath"));
        pushButtonPath->setMaximumSize(QSize(171, 16777215));

        gridLayout->addWidget(pushButtonPath, 2, 0, 2, 1);

        pushButtonLoad = new QPushButton(groupBox);
        pushButtonLoad->setObjectName(QStringLiteral("pushButtonLoad"));
        pushButtonLoad->setMinimumSize(QSize(171, 0));

        gridLayout->addWidget(pushButtonLoad, 0, 0, 2, 1);

        labelPath = new QLabel(groupBox);
        labelPath->setObjectName(QStringLiteral("labelPath"));

        gridLayout->addWidget(labelPath, 3, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 2);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        lineEdit_Razrab = new QLineEdit(groupBox_2);
        lineEdit_Razrab->setObjectName(QStringLiteral("lineEdit_Razrab"));

        verticalLayout->addWidget(lineEdit_Razrab);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_5->addWidget(label_5);

        lineEdit_Proveril = new QLineEdit(groupBox_2);
        lineEdit_Proveril->setObjectName(QStringLiteral("lineEdit_Proveril"));

        verticalLayout_5->addWidget(lineEdit_Proveril);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_4->addWidget(label_6);

        lineEdit_Hkontr = new QLineEdit(groupBox_2);
        lineEdit_Hkontr->setObjectName(QStringLiteral("lineEdit_Hkontr"));

        verticalLayout_4->addWidget(lineEdit_Hkontr);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_3->addWidget(label_7);

        lineEdit_Ytverdil = new QLineEdit(groupBox_2);
        lineEdit_Ytverdil->setObjectName(QStringLiteral("lineEdit_Ytverdil"));

        verticalLayout_3->addWidget(lineEdit_Ytverdil);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        lineEdit_FirmaIzgotov = new QLineEdit(groupBox_2);
        lineEdit_FirmaIzgotov->setObjectName(QStringLiteral("lineEdit_FirmaIzgotov"));

        verticalLayout_2->addWidget(lineEdit_FirmaIzgotov);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_6->addWidget(label_9);

        lineEdit_DecimalNumber = new QLineEdit(groupBox_2);
        lineEdit_DecimalNumber->setObjectName(QStringLiteral("lineEdit_DecimalNumber"));

        verticalLayout_6->addWidget(lineEdit_DecimalNumber);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_7->addWidget(label_10);

        lineEdit_Naimenovanie1 = new QLineEdit(groupBox_2);
        lineEdit_Naimenovanie1->setObjectName(QStringLiteral("lineEdit_Naimenovanie1"));

        verticalLayout_7->addWidget(lineEdit_Naimenovanie1);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_8->addWidget(label_11);

        lineEdit_Naimenovanie2 = new QLineEdit(groupBox_2);
        lineEdit_Naimenovanie2->setObjectName(QStringLiteral("lineEdit_Naimenovanie2"));

        verticalLayout_8->addWidget(lineEdit_Naimenovanie2);


        horizontalLayout_2->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_9->addWidget(label_12);

        lineEdit_Numeracia = new QLineEdit(groupBox_2);
        lineEdit_Numeracia->setObjectName(QStringLiteral("lineEdit_Numeracia"));

        verticalLayout_9->addWidget(lineEdit_Numeracia);


        horizontalLayout_2->addLayout(verticalLayout_9);


        gridLayout_3->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 1, 0, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButtonStart = new QPushButton(centralWidget);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));

        horizontalLayout_3->addWidget(pushButtonStart);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_2->addWidget(textBrowser, 2, 1, 3, 1);

        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_2->addWidget(label_13, 3, 0, 1, 1);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout_2->addWidget(progressBar, 4, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 717, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\320\265 \321\201\320\277\320\265\321\206\320\270\321\204\320\270\320\272\320\260\321\206\320\270\320\270 v.1.0.0.0", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\204\320\260\320\271\320\273\320\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\263\320\265\320\275\320\265\321\200\320\270\321\200\321\203\320\265\320\274\320\276\320\263\320\276 \321\204\320\260\320\271\320\273\320\260:", Q_NULLPTR));
        labelName->setText(QApplication::translate("MainWindow", "D:/projects/specification/spec/PHASE_FPGA_MAIN_01_REFDES.xlsx", Q_NULLPTR));
        lineEditName->setText(QApplication::translate("MainWindow", "AA", Q_NULLPTR));
        pushButtonPath->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\272 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\275\320\276\320\274\321\203 \321\204\320\260\320\271\320\273\321\203", Q_NULLPTR));
        pushButtonLoad->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", Q_NULLPTR));
        labelPath->setText(QApplication::translate("MainWindow", "D:/projects/specification/spec/", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \321\201\320\277\320\265\321\206\320\270\321\204\320\270\320\272\320\260\321\206\320\270\320\270", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\260\320\273:", Q_NULLPTR));
        lineEdit_Razrab->setText(QApplication::translate("MainWindow", "\320\240\321\213\320\261\320\260\320\272 \320\241.\320\222.", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\320\273:", Q_NULLPTR));
        lineEdit_Proveril->setText(QApplication::translate("MainWindow", "\320\241\320\260\320\273\320\260\320\274\320\260\321\202\320\270\320\275 \320\223.\320\222.", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\320\235.\320\272\320\276\320\275\321\202\321\200.:", Q_NULLPTR));
        lineEdit_Hkontr->setText(QApplication::translate("MainWindow", "\320\222\320\260\320\275\320\264\320\260\320\273 \320\222.\320\241.", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\320\243\321\202\320\262.:", Q_NULLPTR));
        lineEdit_Ytverdil->setText(QApplication::translate("MainWindow", "\320\223\320\260\320\261\321\200\320\270\320\273\320\270\320\260\320\275\320\276\320\262 \320\222.\320\241.", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\320\244\320\270\321\200\320\274\320\260- \320\270\320\267\320\263\320\276\321\202\320\276\320\262\320\270\321\202\320\265\320\273\321\214:", Q_NULLPTR));
        lineEdit_FirmaIzgotov->setText(QApplication::translate("MainWindow", "\320\244\320\223\320\243\320\237 \320\235\320\237\320\237 \"\320\223\320\260\320\274\320\274\320\260\"", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\320\224\320\265\321\206\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200 \320\270\320\267\320\264\320\265\320\273\320\270\321\217:", Q_NULLPTR));
        lineEdit_DecimalNumber->setText(QApplication::translate("MainWindow", "\320\221\320\256\320\233\320\230.48745.005 \320\237\320\255\320\227", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265 1:", Q_NULLPTR));
        lineEdit_Naimenovanie1->setText(QApplication::translate("MainWindow", "\320\237\320\273\320\260\321\202\320\260 \321\202\321\200\320\260\320\272\321\202\320\276\320\262\320\276\320\263\320\276 \321\203\321\201\320\270\320\273\320\270\321\202\320\265\320\273\321\217", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265 2:", Q_NULLPTR));
        lineEdit_Naimenovanie2->setText(QApplication::translate("MainWindow", "\320\241\320\277\320\265\321\206\320\270\321\204\320\270\320\272\320\260\321\206\320\270\321\217", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\320\276 \320\275\321\203\320\274\320\265\321\200\320\260\321\206\320\270\320\270:", Q_NULLPTR));
        lineEdit_Numeracia->setText(QApplication::translate("MainWindow", "20", Q_NULLPTR));
        pushButtonStart->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\206\320\265\321\201\321\201 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217:", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
