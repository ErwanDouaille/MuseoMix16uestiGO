#include "digitalclock.h"

DigitalClock::DigitalClock(QWidget *parent)
    : QLCDNumber(parent)
{
    setSegmentStyle(Filled);
    startMilliseconds = 2700000;
    countdown = new QTimer();
    countdown->setInterval(1000); //One second interval
    countdown->setSingleShot(false); //Multiple shot. This means that the signal timeout will be signed each second
    connect(countdown,SIGNAL(timeout()),this,SLOT(timeOut())); //Connects the timeout signal to my slot timeOut
    connect(countdown, SIGNAL(timeout()), this, SLOT(showTime()));
    countdown->start();
    showTime();

    setWindowTitle(tr("Digital Clock"));
    setPalette(Qt::red);
    resize(150, 60);
}

void  DigitalClock::timeOut()
{
    if (startMilliseconds - 1000 >= 0)
    {
        startMilliseconds = startMilliseconds - 1000;
        //Convert milliseconds to H:M:S
        Minutes = (startMilliseconds % (1000*60*60)) / (1000*60);
        Seconds = ((startMilliseconds % (1000*60*60)) % (1000*60)) / 1000;
        if (startMilliseconds <=0) //If timeout
        {
            Minutes = 0;
            Seconds = 0;
            countdown->stop(); //Stop the timer
            emit gotoFinal();
        }
    }
    else
    {
        Minutes = 0;
        Seconds = 0;
        countdown->stop(); //Stop the timer
        emit gotoFinal();
    }
}

void DigitalClock::showTime()
{
    QTime time = QTime();
    time.setHMS(0,Minutes,Seconds);
    QString text = time.toString("mm:ss");
    display(text);
}
