#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "stopwatch.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sig = new Stopwatch(this);

    ui->pB_cirle->setEnabled(false);
    ui->pB_start->setCheckable(true);


    connect(sig, &Stopwatch::sig_UpdateTime, this, &MainWindow::ReceiveStartStop);
    connect(this, &MainWindow::sig_circleTime, sig, &Stopwatch::receiveTime);
    connect(this, &MainWindow::sig_clearTime, sig, &Stopwatch::receiveEraseTime);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete sig;
}

void MainWindow::ReceiveStartStop(QString str){
    ui->lB_Time->setText(str);
}


void MainWindow::on_pB_start_clicked(){
    if(ui->pB_start->isChecked()){
        sig->SendStart();
        ui->pB_start->setText("Стоп");
        ui->pB_cirle->setEnabled(true);
    } else {
        sig->SendStop();
        ui->pB_start->setText("Старт");
        ui->pB_cirle->setEnabled(false);
    }
}


void MainWindow::on_pB_erase_clicked()
{
    ui->lB_Time->setText("00:00.0");
    emit sig_clearTime();
}


void MainWindow::on_pB_cirle_clicked()
{
    emit sig_circleTime();
    QString str = sig->circleTimeStr;
    ui->tB_circleTime->append(str);
}

