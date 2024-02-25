#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject{parent}
{
    counter = false;
    h = 0;
    min = 0;
    sec = 0;
    ms = 0;
    circles = 0;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Stopwatch::SendStart);
    timer->start(1);
}
Stopwatch::~Stopwatch(){

}

bool Stopwatch::isCounting()
{
    return counter;
}

void Stopwatch::setCounter(bool new_counter)
{
    counter = new_counter;
}

QString Stopwatch::getTime()
{
    ms++;
    if (ms >= 1000){
        ms = 0;
        sec++;
    }
    if (sec >= 60){
        sec = 0;
        min++;
    }
    return QString(QString::number(min) + ":" + QString::number(sec) + "." + QString::number(ms/10));
    //TO DO: как-то вернуть строку
}



void Stopwatch::SendStop()
{
    counter = false;
    emit sig_StopWatch();
}

void Stopwatch::SendStart()
{
   counter = true;
   emit sig_StartWatch();
}

void Stopwatch::SendRestart()
{
    counter = true;
    emit sig_RestartWatch();
}


void Stopwatch::SendErase()
{
    h = 0;
    min = 0;
    sec = 0;
    ms = 0;
    circles = 0;

}

void Stopwatch::TimeDiff()
{
    // fullTile - prevTime
}







