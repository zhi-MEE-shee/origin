#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QTimer>
//#include <QTime>
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

public slots:
    void ShowTime();
    void ReceiveStartStop();
    void on_pB_erase_clicked();

private slots:
    void on_pB_start_clicked();

    void on_pB_cirle_clicked();

private:
    Ui::MainWindow *ui;
    Stopwatch *sig;
    QTimer *timer;

    int h, min, sec, ms;
    int circles;
};
#endif // MAINWINDOW_H
