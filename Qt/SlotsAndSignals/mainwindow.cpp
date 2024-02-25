#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sig = new Stopwatch(this);

    ui->pB_cirle->setEnabled(false);

    connect(ui->pB_start, &QPushButton::clicked, this, &MainWindow::ReceiveStartStop);
    connect(ui->pB_erase, &QPushButton::clicked, this, &MainWindow::on_pB_erase_clicked);
    connect(sig, &Stopwatch::sig_StartWatch, this, &MainWindow::ShowTime);
    connect(ui->pB_cirle, &QPushButton::clicked, sig, &Stopwatch::TimeDiff);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sig;
}

void MainWindow::ShowTime()
{
    if(sig->isCounting()){

        QString time = sig->getTime();
        ui->lab_seconds->setText(time);

//        if(ms < 10){
//            ui->lab_millisec->setText("0" + QString::number(ms/10));
//        } else {
//            ui->lab_millisec->setText(QString::number(ms/10));
//        }
//        if(sec < 10){
//            ui->lab_seconds->setText("0" + QString::number(sec));
//        } else {
//            ui->lab_seconds->setText(QString::number(sec));
//        }
//        if(min < 10){
//            ui->lab_minutes->setText("0" + QString::number(min));
//        } else {
//            ui->lab_minutes->setText(QString::number(min));
//        }
    }
}


void MainWindow::ReceiveStartStop()
{
    sig->setCounter(!sig->isCounting());
    if(sig->counter == true){

        qDebug() << sig->isCounting();

        ui->pB_start->setText("Стоп");
        sig->timer->start(1);
        if(QString(sig->getTime()).isEmpty() ){
            sig->SendRestart();
        } else{
           sig->SendStart();
        }
    } else {

        qDebug() << sig->isCounting();

        ui->pB_start->setText("Старт");
        sig->timer->stop();
        sig->SendStop();

    }
}


void MainWindow::on_pB_erase_clicked()
{
 //   ui->lab_millisec->setText("00");
    ui->lab_seconds->setText("00");
 //   ui->lab_minutes->setText("00");
 //   ui->pB_cirle->setEnabled(false);
    sig->SendErase();
}


void MainWindow::on_pB_start_clicked()
{
    ui->pB_cirle->setEnabled(!ui->pB_cirle->isEnabled());
}


void MainWindow::on_pB_cirle_clicked()
{
    sig->circles++;
  //  ui->tB_circleTime->append(QString("круг %1 время: %2:%3.%4").arg(sig->circles).arg(min).arg(sec).arg(ms/10));
}

