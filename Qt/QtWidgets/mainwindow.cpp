#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rB_lightGrey->setChecked(true);
    ui->rB_lightGrey->setText("светло-серая");
    ui->rB_darkGrey->setText("темно-серая");
    ui->rB_Green->setText("зеленая");

    ui->cB_language->addItem(QString("Русский"));
    ui->cB_language->addItem(QString("Английский"));
    ui->cB_language->addItem(QString("Японский"));

    ui->pB_toggButton->setFlat(true);
    ui->pB_toggButton->setText(QString("Нажать тут"));
    ui->pBar_toggButtonCounter->setMinimum(0);
    ui->pBar_toggButtonCounter->setMaximum(100);
    ui->pBar_toggButtonCounter->setValue(0);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pB_toggButton_clicked()
{
    int val = ui->pBar_toggButtonCounter->value();
    if(val < 100){
        val += 10;
        ui->pBar_toggButtonCounter->setValue(val);
    } else {
        val = 0;
         ui->pBar_toggButtonCounter->setValue(val);
    }
}

