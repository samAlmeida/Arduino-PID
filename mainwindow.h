/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia. For licensing terms and
** conditions see http://qt.digia.com/licensing. For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights. These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCore/QtGlobal>
#include <QMainWindow>
#include <QTimer>
#include <QtSerialPort/QSerialPort>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class SettingsDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
   void realtimeDataSlot();
   void lerDados();
   void on_horizontalScrollBar_valueChanged(int value);
   void on_Pausar_clicked();
   void on_Continuar_clicked();
   void on_conectar_clicked();
   void on_KP_SpinBox_valueChanged(double arg1);
   void on_KI_SpinBox_valueChanged(double arg1);
   void on_KD_SpinBox_valueChanged(double arg1);
   void on_Set_Point_verticalSlider_valueChanged(int value);
   void on_ativar_clicked();
   void on_desativar_clicked();
   void on_mv_slider_valueChanged(int value);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QString arduino_port_name;
    bool arduino_is_available;
    QTimer dataTimer;
    bool pause;
    int posScroll;
    double key;
    void xAxisChanged(QCPRange range);
    double primeirotempo;
    void enviarDados(QString dados);
    double value0;
    double value1;
    QByteArray serialData;
    QString serialBuffer;
    QString parsed_data;
    double temperature_value;
    bool pwm;
    bool nivel;


};

#endif // MAINWINDOW_H
