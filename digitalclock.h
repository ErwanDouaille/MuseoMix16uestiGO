#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include <iostream>
class DigitalClock : public QLCDNumber
{
    Q_OBJECT

public:
    DigitalClock(QWidget *parent = 0);
private:
    int startMilliseconds;
    QTimer* countdown;
    int Minutes;
    int Seconds;
private slots:
    void showTime();
protected slots:
    void timeOut();
signals:

    void gotoFinal();
};

#endif // DIGITALCLOCK_H
