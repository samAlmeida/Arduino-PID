/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionClear;
    QAction *actionQuit;
    QWidget *centralWidget;
    QScrollBar *horizontalScrollBar;
    QPushButton *conectar;
    QGroupBox *groupBox_3;
    QSlider *mv_slider;
    QPushButton *ativar;
    QPushButton *desativar;
    QLabel *Descricao_3;
    QPushButton *Pausar;
    QCustomPlot *customPlot;
    QPushButton *desconectar;
    QPushButton *Continuar;
    QGroupBox *groupBox_2;
    QLCDNumber *mv_lcd;
    QLabel *label_10;
    QProgressBar *progressBar;
    QLabel *label_11;
    QLCDNumber *nivel_lcd;
    QLabel *label_12;
    QGroupBox *groupBox;
    QSlider *Set_Point_verticalSlider;
    QLCDNumber *SetPoint_lcd;
    QDoubleSpinBox *KP_SpinBox;
    QDoubleSpinBox *KI_SpinBox;
    QDoubleSpinBox *KD_SpinBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QListWidget *listWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1247, 670);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QStringLiteral("actionAboutQt"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon1);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon2);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon3);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalScrollBar = new QScrollBar(centralWidget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(240, 590, 991, 20));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        conectar = new QPushButton(centralWidget);
        conectar->setObjectName(QStringLiteral("conectar"));
        conectar->setGeometry(QRect(8, 490, 75, 24));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 208, 221, 91));
        QFont font;
        font.setPointSize(10);
        groupBox_3->setFont(font);
        mv_slider = new QSlider(groupBox_3);
        mv_slider->setObjectName(QStringLiteral("mv_slider"));
        mv_slider->setGeometry(QRect(10, 60, 201, 22));
        mv_slider->setMaximum(255);
        mv_slider->setOrientation(Qt::Horizontal);
        ativar = new QPushButton(groupBox_3);
        ativar->setObjectName(QStringLiteral("ativar"));
        ativar->setGeometry(QRect(12, 20, 75, 23));
        desativar = new QPushButton(groupBox_3);
        desativar->setObjectName(QStringLiteral("desativar"));
        desativar->setEnabled(true);
        desativar->setGeometry(QRect(136, 20, 75, 23));
        Descricao_3 = new QLabel(centralWidget);
        Descricao_3->setObjectName(QStringLiteral("Descricao_3"));
        Descricao_3->setGeometry(QRect(100, 488, 91, 20));
        Pausar = new QPushButton(centralWidget);
        Pausar->setObjectName(QStringLiteral("Pausar"));
        Pausar->setGeometry(QRect(10, 460, 75, 23));
        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(240, 18, 991, 571));
        desconectar = new QPushButton(centralWidget);
        desconectar->setObjectName(QStringLiteral("desconectar"));
        desconectar->setEnabled(true);
        desconectar->setGeometry(QRect(159, 490, 75, 24));
        Continuar = new QPushButton(centralWidget);
        Continuar->setObjectName(QStringLiteral("Continuar"));
        Continuar->setEnabled(true);
        Continuar->setGeometry(QRect(160, 452, 75, 23));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 300, 221, 151));
        groupBox_2->setFont(font);
        mv_lcd = new QLCDNumber(groupBox_2);
        mv_lcd->setObjectName(QStringLiteral("mv_lcd"));
        mv_lcd->setGeometry(QRect(90, 11, 121, 51));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(39, 27, 41, 20));
        QFont font1;
        font1.setPointSize(12);
        label_10->setFont(font1);
        progressBar = new QProgressBar(groupBox_2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(110, 70, 111, 23));
        progressBar->setMaximum(255);
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        progressBar->setInvertedAppearance(false);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 72, 101, 21));
        QFont font2;
        font2.setPointSize(8);
        label_11->setFont(font2);
        nivel_lcd = new QLCDNumber(groupBox_2);
        nivel_lcd->setObjectName(QStringLiteral("nivel_lcd"));
        nivel_lcd->setGeometry(QRect(90, 100, 121, 51));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 109, 51, 31));
        label_12->setFont(font1);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 7, 221, 200));
        groupBox->setFont(font);
        Set_Point_verticalSlider = new QSlider(groupBox);
        Set_Point_verticalSlider->setObjectName(QStringLiteral("Set_Point_verticalSlider"));
        Set_Point_verticalSlider->setGeometry(QRect(21, 30, 22, 151));
        Set_Point_verticalSlider->setMaximum(25);
        Set_Point_verticalSlider->setOrientation(Qt::Vertical);
        SetPoint_lcd = new QLCDNumber(groupBox);
        SetPoint_lcd->setObjectName(QStringLiteral("SetPoint_lcd"));
        SetPoint_lcd->setGeometry(QRect(89, 29, 121, 51));
        KP_SpinBox = new QDoubleSpinBox(groupBox);
        KP_SpinBox->setObjectName(QStringLiteral("KP_SpinBox"));
        KP_SpinBox->setGeometry(QRect(120, 89, 91, 30));
        KP_SpinBox->setFont(font1);
        KP_SpinBox->setSingleStep(0.1);
        KI_SpinBox = new QDoubleSpinBox(groupBox);
        KI_SpinBox->setObjectName(QStringLiteral("KI_SpinBox"));
        KI_SpinBox->setGeometry(QRect(120, 125, 91, 31));
        KI_SpinBox->setFont(font1);
        KD_SpinBox = new QDoubleSpinBox(groupBox);
        KD_SpinBox->setObjectName(QStringLiteral("KD_SpinBox"));
        KD_SpinBox->setGeometry(QRect(120, 160, 91, 31));
        KD_SpinBox->setFont(font1);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(87, 94, 31, 20));
        label->setFont(font1);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(87, 131, 30, 21));
        label_2->setFont(font1);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(87, 165, 30, 20));
        label_3->setFont(font1);
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 521, 221, 121));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Controle de n\303\255vel", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", 0));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "About program", 0));
#endif // QT_NO_TOOLTIP
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Alt+A", 0));
        actionAboutQt->setText(QApplication::translate("MainWindow", "About Qt", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "Conectar", 0));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("MainWindow", "Connect to serial port", 0));
#endif // QT_NO_TOOLTIP
        actionConnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionDisconnect->setText(QApplication::translate("MainWindow", "&Disconnect", 0));
#ifndef QT_NO_TOOLTIP
        actionDisconnect->setToolTip(QApplication::translate("MainWindow", "Disconnect from serial port", 0));
#endif // QT_NO_TOOLTIP
        actionDisconnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0));
        actionConfigure->setText(QApplication::translate("MainWindow", "&Configure", 0));
#ifndef QT_NO_TOOLTIP
        actionConfigure->setToolTip(QApplication::translate("MainWindow", "Configure serial port", 0));
#endif // QT_NO_TOOLTIP
        actionConfigure->setShortcut(QApplication::translate("MainWindow", "Alt+C", 0));
        actionClear->setText(QApplication::translate("MainWindow", "C&lear", 0));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("MainWindow", "Clear data", 0));
#endif // QT_NO_TOOLTIP
        actionClear->setShortcut(QApplication::translate("MainWindow", "Alt+L", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        conectar->setText(QApplication::translate("MainWindow", "Conectar", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Controla manual", 0));
        ativar->setText(QApplication::translate("MainWindow", "Ativar", 0));
        desativar->setText(QApplication::translate("MainWindow", "Desativar", 0));
        Descricao_3->setText(QString());
        Pausar->setText(QApplication::translate("MainWindow", "Pausar", 0));
        desconectar->setText(QApplication::translate("MainWindow", "Desconectar", 0));
        Continuar->setText(QApplication::translate("MainWindow", "Continuar", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Output", 0));
        label_10->setText(QApplication::translate("MainWindow", "MV =", 0));
        label_11->setText(QApplication::translate("MainWindow", "Potencia da bomba:", 0));
        label_12->setText(QApplication::translate("MainWindow", "Nivel =", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Controle automatico", 0));
        label->setText(QApplication::translate("MainWindow", "KP:", 0));
        label_2->setText(QApplication::translate("MainWindow", "KI:", 0));
        label_3->setText(QApplication::translate("MainWindow", "KD:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
