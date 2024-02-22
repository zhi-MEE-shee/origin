#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject{parent}
{
    counter = false;
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
    counter = false;
  //  emit sig_Erase();
}







