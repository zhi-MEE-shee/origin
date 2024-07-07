#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QString>
#include <QTime>

class Stopwatch : public QObject
{
    Q_OBJECT
public:

    QString currentTimeStr;
    QString circleTimeStr;

    explicit Stopwatch(QObject *parent = nullptr);
    ~Stopwatch();

    void getTime();
    void SendStart();
    void SendStop();

public slots:

    void receiveTime();
    void receiveEraseTime();

signals:
    void sig_UpdateTime(QString &currentTimeStr);

private:
    int circleTime;
    int circle;
    QTimer *timer;
    QTime time;
    QTime offTime;


    //    int fullTile;
    //    int prevTime;

};

#endif // STOPWATCH_H
