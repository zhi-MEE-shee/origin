#include "stopwatch.h"
#include <QTimer>

Stopwatch::Stopwatch(QObject *parent)
    : QObject{parent}
{
    circleTime = 0;
    circle = 1;
    time.setHMS(0, 0, 0, 0);
    offTime.setHMS(0, 0, 0, 0);

    timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, &QTimer::timeout, this, &Stopwatch::getTime);
}
Stopwatch::~Stopwatch(){
    delete timer;
}

void Stopwatch::getTime()
{
   time =time.addMSecs(100);
   currentTimeStr = time.toString("mm:ss.z");
   emit sig_UpdateTime(currentTimeStr);
}

void Stopwatch::receiveTime(){
    circleTime = offTime.secsTo(time);
    circleTimeStr = "Круг " + QString::number(circle) + " , время: " + QString::number(circleTime) + " сек";
    offTime = time;
    ++circle;
}

void Stopwatch::receiveEraseTime()
{
    time.setHMS(0, 0, 0, 0);
    offTime.setHMS(0, 0, 0, 0);
    circle = 1;
}

void Stopwatch::SendStart()
{
   timer->start();
   getTime();
}

void Stopwatch::SendStop()
{
   timer->stop();
}











