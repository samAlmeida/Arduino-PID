#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    arduino_is_available = false;
    arduino_port_name = "COM3";
    arduino = new QSerialPort;
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                }
            }
        }
    }
    if(arduino_is_available){
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);

    }else{
        QMessageBox::warning(this, "Erro", "Dispositivo não encontrado");
    }


    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot->graph(0)->setBrush(QBrush(QColor(240, 255, 200)));
    ui->customPlot->graph(0)->setAntialiasedFill(false);
    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setPen(QPen(Qt::red));
    ui->customPlot->graph(0)->setChannelFillGraph(ui->customPlot->graph(1));
    ui->customPlot->addGraph();
    ui->customPlot->graph(2)->setPen(QPen(Qt::blue));
    ui->customPlot->graph(2)->setLineStyle(QCPGraph::lsNone);
    ui->customPlot->graph(2)->setScatterStyle(QCPScatterStyle::ssDisc);
    ui->customPlot->addGraph();
    ui->customPlot->graph(3)->setPen(QPen(Qt::red));
    ui->customPlot->graph(3)->setLineStyle(QCPGraph::lsNone);
    ui->customPlot->graph(3)->setScatterStyle(QCPScatterStyle::ssDisc);
    ui->customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->customPlot->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->customPlot->xAxis->setAutoTickStep(false);
    ui->customPlot->xAxis->setTickStep(2);
    ui->customPlot->axisRect()->setupFullAxesBox();
    primeirotempo = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));
    connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalScrollBar_valueChanged(int)));
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(xAxisChanged(QCPRange)));
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    dataTimer.start(0);
    pause = false;
    connect(arduino, SIGNAL(readyRead()), this, SLOT(lerDados()));
    pwm = false;
    nivel = true;
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::realtimeDataSlot(){

if (pause == true){

    key = posScroll;
    }
if (pause == false){
    key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    }


static double lastPointKey = 0;
if (key-lastPointKey > 0.01)
{
  // value0 =qSin(key*1.6+qCos(key*1.7)*2)*10 + qSin(key*1.2+0.56)*20 + 26;
  // value1 = qCos(key); //qSin(key*1.3+qCos(key*1.2)*1.2)*7 + qSin(key*0.9+0.26)*24 + 26;
  ui->customPlot->graph(0)->addData(key, value0);
  ui->customPlot->graph(1)->addData(key, value1);
  ui->customPlot->graph(2)->clearData();
  ui->customPlot->graph(2)->addData(key, value0);
  ui->customPlot->graph(3)->clearData();
  ui->customPlot->graph(3)->addData(key, value1);
  ui->customPlot->graph(0)->rescaleValueAxis();
  ui->customPlot->graph(1)->rescaleValueAxis(true);
  lastPointKey = key;
  ui->horizontalScrollBar->setRange(primeirotempo, key);
  ui->customPlot->axisRect()->setupFullAxesBox(true);
  ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
ui->customPlot->xAxis->setRange(key+0.25, 8, Qt::AlignRight);
ui->customPlot->replot();

static double lastFpsKey;
static int frameCount;
++frameCount;
if (key-lastFpsKey > 2)
{
  ui->statusBar->showMessage(
        QString("%1 FPS, Total Data points: %2")
        .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
        .arg(ui->customPlot->graph(0)->data()->count()+ui->customPlot->graph(1)->data()->count())
        , 0);
  lastFpsKey = key;
  frameCount = 0;

}
}
void MainWindow::xAxisChanged(QCPRange range)
{
  ui->horizontalScrollBar->setValue(qRound(range.center()*100.0)); // adjust position of scroll bar slider
  ui->horizontalScrollBar->setPageStep(qRound(range.size()*100.0)); // adjust size of scroll bar slider
}

void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
    posScroll = value;

    if (qAbs(ui->customPlot->xAxis->range().center()-value/100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
      {
        ui->customPlot->xAxis->setRange(value/100.0, ui->customPlot->xAxis->range().size(), Qt::AlignCenter);
      }
}

void MainWindow::on_Pausar_clicked()
{
    pause = true;
    ui->Continuar->isEnabled();
}

void MainWindow::on_Continuar_clicked()
{
    pause = false;
}

void MainWindow::on_conectar_clicked()
{
    arduino_is_available = false;
    arduino_port_name = "COM3";
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                }
            }
        }
    }
    if(arduino_is_available){
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        ui->desconectar->isEnabled();

    }else{
        QMessageBox::warning(this, "Erro", "Dispositivo não encontrado");
    }
}
void MainWindow::enviarDados(QString dados)
{
    arduino->write(dados.toLatin1());
}
void MainWindow::on_KP_SpinBox_valueChanged(double arg1)
{
    MainWindow::enviarDados(QString("p%1").arg(arg1));

}

void MainWindow::on_KI_SpinBox_valueChanged(double arg1)
{
    float a =  arg1;
      MainWindow::enviarDados(QString("i%1").arg(a));
}

void MainWindow::on_KD_SpinBox_valueChanged(double arg1)
{
    MainWindow::enviarDados(QString("d%1").arg(arg1));
}

void MainWindow::on_Set_Point_verticalSlider_valueChanged(int value)
{
    value1 = value;
    MainWindow::enviarDados(QString("s%1").arg(value));
    ui->SetPoint_lcd->display(value);
}

void MainWindow::on_ativar_clicked()
{
    MainWindow::enviarDados(QString("a"));

}

void MainWindow::on_desativar_clicked()
{
    MainWindow::enviarDados(QString("e"));

}

void MainWindow::on_mv_slider_valueChanged(int value)
{
    MainWindow::enviarDados(QString("m%1").arg(value));

}
void MainWindow::lerDados()
{

   if(nivel){
    QStringList buffer_split = serialBuffer.split("n");
    if(buffer_split.length() < 4){
        serialData = arduino->readAll();
        serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());
        serialData.clear();
    }else{
        serialBuffer = "";
        parsed_data = buffer_split[1];
        temperature_value = (parsed_data.toDouble());
        value0 = temperature_value;
        qDebug() << temperature_value << "\n";
        ui->nivel_lcd->display(temperature_value);
        nivel = false;
        pwm = true;
        return;
    }
 }   if(pwm){
       QStringList buffer_split = serialBuffer.split("p");
       if(buffer_split.length() < 4){
           serialData = arduino->readAll();
           serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());
           serialData.clear();
       }else{
           serialBuffer = "";
           parsed_data = buffer_split[1];
           temperature_value = (parsed_data.toDouble());
           ui->mv_lcd->display(temperature_value);
           qDebug() << temperature_value << "\n";
           nivel = true;
           pwm = false;
           return;
       }
    }


}
