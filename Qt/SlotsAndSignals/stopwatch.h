#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QString>
//#include <QTime>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    bool counter;
    int h, min, sec, ms;
    int circles;
    int fullTile;
    int prevTime;
    QTimer *timer;

    explicit Stopwatch(QObject *parent = nullptr);
    ~Stopwatch();

    bool isCounting();
    void setCounter(bool new_counter);
    QString getTime();

public slots:
    void SendStart();
    void SendRestart();
    void SendStop();
    void SendErase();
    void TimeDiff();


signals:
    void sig_RestartWatch();
    void sig_StartWatch();
    void sig_StopWatch();
    void sig_Erase();

private:
  //  QTime *time;

};

#endif // STOPWATCH_H
