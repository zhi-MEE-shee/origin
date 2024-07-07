#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include "stopwatch.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
 //   void ShowTime();
    void sig_circleTime();
    void sig_clearTime();

private slots:
    void ReceiveStartStop(QString str);
    void on_pB_start_clicked();
    void on_pB_cirle_clicked();
    void on_pB_erase_clicked();

private:
    Ui::MainWindow *ui;
    Stopwatch *sig;

};
#endif // MAINWINDOW_H
