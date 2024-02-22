#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
//#include <QTime>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    bool counter;

    explicit Stopwatch(QObject *parent = nullptr);
    ~Stopwatch();

    bool isCounting();
    void setCounter(bool new_counter);


public slots:
    void SendStart();
    void SendRestart();
    void SendStop();
    void SendErase();

signals:
    void sig_RestartWatch();
    void sig_StartWatch();
    void sig_StopWatch();
    void sig_Erase();

private:
  //  QTime *time;
};

#endif // STOPWATCH_H
