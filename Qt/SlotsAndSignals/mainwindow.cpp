#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sig = new Stopwatch(this);
    timer = new QTimer(this);
 //   h = 0;
    min = 0;
    sec = 0;
    ms = 0;
    circles = 0;

    ui->pB_cirle->setEnabled(false);

    connect(ui->pB_start, &QPushButton::clicked, this, &MainWindow::ReceiveStartStop);
    connect(ui->pB_erase, &QPushButton::clicked, this, &MainWindow::on_pB_erase_clicked);
    connect(timer, &QTimer::timeout, this, &MainWindow::ShowTime);
    timer->start(1);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowTime()
{
    if(sig->isCounting()){
        ms++;
        if (ms >= 1000){
            ms = 0;
            sec++;
        }
        if (sec >= 60){
            sec = 0;
            min++;
        }

        if(ms < 10){
            ui->lab_millisec->setText("0" + QString::number(ms/10));
        } else {
            ui->lab_millisec->setText(QString::number(ms/10));
        }
        if(sec < 10){
            ui->lab_seconds->setText("0" + QString::number(sec));
        } else {
            ui->lab_seconds->setText(QString::number(sec));
        }
        if(min < 10){
            ui->lab_minutes->setText("0" + QString::number(min));
        } else {
            ui->lab_minutes->setText(QString::number(min));
        }
    }
}


void MainWindow::ReceiveStartStop()
{
    sig->setCounter(!sig->isCounting());
    if(sig->counter == true){

        qDebug() << sig->isCounting();

        ui->pB_start->setText("Стоп");
        timer->start(1);
        if(min || sec != 0){
            sig->SendRestart();
        } else{
           sig->SendStart();
        }
    } else {

        qDebug() << sig->isCounting();

        ui->pB_start->setText("Старт");
        timer->stop();
        sig->SendStop();

    }
}


void MainWindow::on_pB_erase_clicked()
{
//    h = 0;
    min = 0;
    sec = 0;
    ms = 0;
    circles = 0;
    ui->pB_start->setText("Старт");
    ui->lab_millisec->setText("00");
    ui->lab_seconds->setText("00");
    ui->lab_minutes->setText("00");
    ui->pB_cirle->setEnabled(false);
    sig->SendErase();
}


void MainWindow::on_pB_start_clicked()
{
    ui->pB_cirle->setEnabled(!ui->pB_cirle->isEnabled());
}


void MainWindow::on_pB_cirle_clicked()
{
    circles++;
    ui->tB_circleTime->append(QString("круг %1 время: %2:%3.%4").arg(circles).arg(min).arg(sec).arg(ms/10));
}

