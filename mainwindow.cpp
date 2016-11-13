/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "MainWindow.h"
#include <QLabel>
#include <QTextEdit>
#include <iostream>

using namespace std;

MainWindow::MainWindow()
{
    resize(QGuiApplication::primaryScreen()->availableSize());
    createWidgets();
    createActions();
    showFullScreen();
}

//***************************************************** UI
//********************************************************

void MainWindow::resizeEvent(QResizeEvent *evt)
{
    QPixmap bkgnd(QApplication::applicationDirPath() + "/files/background.png");//Load pic
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);//set scale of pic to match the window
    QPalette p = palette(); //copy current, not create new
    p.setBrush(QPalette::Background, bkgnd);//set the pic to the background
    setPalette(p);//show the background pic

    QMainWindow::resizeEvent(evt); //call base implementation
}

void MainWindow::setFont(QLabel* label, int size)
{
    QFont font = _indice1->font();
    font.setPointSize(size);
    font.setBold(true);
    label->setFont(font);

    QPalette palette = label->palette();
    palette.setColor(label->backgroundRole(), QColor(226, 167, 82, 255));
    palette.setColor(label->foregroundRole(), QColor(226, 167, 82, 255));
    label->setPalette(palette);
}

QString getButtonStyleSheet()
{
    return "QPushButton "
           "{"
           "border: 1px solid #005A83;"
           "font: bold 32px;"
           "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
           "stop: 0 #E2A752, stop: 0.9 #E2A752,"
           "stop: 0.9 #E2A752, stop: 1.0 #787878);"
           "min-height: 100px;"
           "min-width: 150px;"
           "max-height: 100px;"
           "max-width: 150px;"
           "padding: 6px;"
           "}"
           "QPushButton:pressed "
           "{"
           "border: 1px solid #005A83;"
           "background-color: rgb(226, 167, 82);"
           "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
           "stop: 0 #FFFFFF, stop: 0.9 #FFFFFF,"
           "stop: 0.9 #FFFFFF, stop: 1.0 #787878);"
           "}";
}

QString getButtonQuestionStyleSheet()
{
    return "QPushButton "
           "{"
           "border: 1px solid #005A83;"
           "font: bold 20px;"
           "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
           "stop: 0 #E2A752, stop: 0.9 #E2A752,"
           "stop: 0.9 #E2A752, stop: 1.0 #787878);"
           "min-height: 300px;"
           "min-width: 350px;"
           "max-height: 300px;"
           "max-width: 350px;"
           "padding: 6px;"
           "}"
           "QPushButton:pressed "
           "{"
           "border: 1px solid #005A83;"
           "background-color: rgb(226, 167, 82);"
           "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
           "stop: 0 #FFFFFF, stop: 0.9 #FFFFFF,"
           "stop: 0.9 #FFFFFF, stop: 1.0 #787878);"
           "}";
}

QString getButtonQuestionLoseStyleSheet()
{

    return "QPushButton "
           "{"
           "border: 1px solid #005A83;"
           "font: bold 20px;"
           "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
           "stop: 0 #FF4500, stop: 0.9 #FF4500,"
           "stop: 0.9 #FF4500, stop: 1.0 #787878);"
           "min-height: 300px;"
           "min-width: 350px;"
           "max-height: 300px;"
           "max-width: 350px;"
           "padding: 6px;"
           "}"
           "QPushButton:pressed "
           "{"
           "border: 1px solid #005A83;"
           "background-color: rgb(226, 167, 82);"
           "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
           "stop: 0 #FF4500, stop: 0.9 #FF4500,"
           "stop: 0.9 #FF4500, stop: 1.0 #787878);"
           "}";

}

//************************************************* CREATE
//********************************************************

void MainWindow::createIndices()
{
    _indice1 = new QLabel(this);
    _indice2 = new QLabel(this);
    _indice3 = new QLabel(this);
    _indice4 = new QLabel(this);
    _indice5 = new QLabel(this);
    _indice6 = new QLabel(this);

    _indice1->setText("");
    _indice2->setText("");
    _indice3->setText("");
    _indice4->setText("");
    _indice5->setText("");
    _indice6->setText("");

    setFont(_indice1, 24);
    setFont(_indice2, 24);
    setFont(_indice3, 24);
    setFont(_indice4, 24);
    setFont(_indice5, 24);
    setFont(_indice6, 24);

    _indice1->setGeometry(183, 470, 500, 100);
    _indice2->setGeometry(183, 545, 500, 100);
    _indice3->setGeometry(183, 615, 500, 100);
    _indice4->setGeometry(183, 685, 500, 100);
    _indice5->setGeometry(183, 755, 500, 100);
    _indice6->setGeometry(183, 825, 500, 100);

    _final = new QLabel(this);
    setFont(_final, 32);
    _final->setGeometry(1000, 860, 500, 300);
    _final->setVisible(false);

}

void MainWindow::createPad()
{
    _pad1 = new QPushButton(this);
    _pad2 = new QPushButton(this);
    _pad3 = new QPushButton(this);
    _pad4 = new QPushButton(this);
    _pad5 = new QPushButton(this);
    _pad6 = new QPushButton(this);

    _pad1->setStyleSheet(getButtonStyleSheet());
    _pad2->setStyleSheet(getButtonStyleSheet());
    _pad3->setStyleSheet(getButtonStyleSheet());
    _pad4->setStyleSheet(getButtonStyleSheet());
    _pad5->setStyleSheet(getButtonStyleSheet());
    _pad6->setStyleSheet(getButtonStyleSheet());

    _pad1->setGeometry(1380, 200, 200, 100);
    _pad2->setGeometry(1550, 200, 200, 100);
    _pad3->setGeometry(1720, 200, 200, 100);
    _pad4->setGeometry(1380, 320, 200, 100);
    _pad5->setGeometry(1550, 320, 200, 100);
    _pad6->setGeometry(1720, 320, 200, 100);

    _pad1->setIcon(QIcon(QApplication::applicationDirPath() + "/files/cle1.png"));
    _pad1->setIconSize(QSize(120, 120));
    _pad2->setIcon(QIcon(QApplication::applicationDirPath() + "/files/cle2.png"));
    _pad2->setIconSize(QSize(120, 120));
    _pad3->setIcon(QIcon(QApplication::applicationDirPath() + "/files/cle3.png"));
    _pad3->setIconSize(QSize(120, 120));
    _pad4->setIcon(QIcon(QApplication::applicationDirPath() + "/files/cle4.png"));
    _pad4->setIconSize(QSize(120, 120));
    _pad5->setIcon(QIcon(QApplication::applicationDirPath() + "/files/cle5.png"));
    _pad5->setIconSize(QSize(120, 120));
    _pad6->setIcon(QIcon(QApplication::applicationDirPath() + "/files/cle6.png"));
    _pad6->setIconSize(QSize(120, 120));

    connect(_pad1, SIGNAL(clicked(bool)), this, SLOT(initQuestion1()));
    connect(_pad2, SIGNAL(clicked(bool)), this, SLOT(initQuestion2()));
    connect(_pad3, SIGNAL(clicked(bool)), this, SLOT(initQuestion3()));
    connect(_pad4, SIGNAL(clicked(bool)), this, SLOT(initQuestion4()));
    connect(_pad5, SIGNAL(clicked(bool)), this, SLOT(initQuestion5()));
    connect(_pad6, SIGNAL(clicked(bool)), this, SLOT(initQuestion6()));
}

void MainWindow::createQuestion()
{
    _questionLabel1 = new QLabel(this);
    _questionLabel1->setText("");
    setFont(_questionLabel1, 12);
    _questionLabel1->setGeometry(183, 510, 500, 100);

    _questionLabel2 = new QLabel(this);
    _questionLabel2->setText("");
    setFont(_questionLabel2, 12);
    _questionLabel2->setGeometry(183, 510, 500, 100);

    _questionLabel3 = new QLabel(this);
    _questionLabel3->setText("");
    setFont(_questionLabel3, 12);
    _questionLabel3->setGeometry(183, 510, 500, 100);

    _question1 = new QPushButton("1", this);
    _question2 = new QPushButton("2", this);
    _question3 = new QPushButton("3", this);

    _question1->setStyleSheet(getButtonQuestionStyleSheet());
    _question2->setStyleSheet(getButtonQuestionStyleSheet());
    _question3->setStyleSheet(getButtonQuestionStyleSheet());

    _question1->setGeometry(1000, 700, 200, 100);
    _question2->setGeometry(1170, 700, 200, 100);
    _question3->setGeometry(1340, 700, 200, 100);

    _question1->setVisible(false);
    _question2->setVisible(false);
    _question3->setVisible(false);

    connect(_question1, SIGNAL(clicked(bool)), this, SLOT(answer1()));
    connect(_question2, SIGNAL(clicked(bool)), this, SLOT(answer2()));
    connect(_question3, SIGNAL(clicked(bool)), this, SLOT(answer3()));

    _textEdit = new QTextEdit(this);
    _textEdit->setVisible(false);

    _archeo = new QLabel(this);
    _timer = new QTimer();
}

void MainWindow::createClock()
{
    _clock = new DigitalClock(this);
    _clock->setGeometry(1600, 50, 200, 100);
}

void MainWindow::createWidgets()
{
    createIndices();
    createPad();
    createQuestion();
    createClock();
}

void MainWindow::createActions()
{
    connect(this, SIGNAL(gotoHome()), this, SLOT(home()));
    connect(_clock, &DigitalClock::gotoFinal, this, &MainWindow::final);
    connect(this, SIGNAL(gotoFinal()), this, SLOT(final()));
}

//************************************************ CONTROL
//********************************************************

bool  MainWindow::setIndice(int id)
{
    if(id == 1)
    {
        _indice1->setText("proche");
        return true;
    }
    if(id == 2)
    {
        _indice2->setText("conjugaison");
        return true;
    }
    if(id == 3)
    {
        initQuestion31();
        return false;
    }
    if(id == 31)
    {
        _indice3->setText("antérieur");
        return true;
    }
    if(id == 4)
    {
        initQuestion41();
        return false;
    }
    if(id == 41)
    {
        _indice4->setText("nom et adjectif");
        return true;
    }
    if(id == 5)
    {
        _indice5->setText("avenir");
        return true;
    }
    if(id == 6)
    {
        _indice6->setText("demain");
        return true;
    }
    return false;
}

void MainWindow::hidePad(int id)
{
    if(id == 1)
        _pad1->setVisible(false);
    if(id == 2)
        _pad2->setVisible(false);
    if(id == 3 || id == 31)
        _pad3->setVisible(false);
    if(id == 4 || id == 41)
        _pad4->setVisible(false);
    if(id == 5)
        _pad5->setVisible(false);
    if(id == 6)
        _pad6->setVisible(false);
}

//****************************************************** SLOTS
//************************************************************

void MainWindow::home()
{
    _indice1->setVisible(true);
    _indice2->setVisible(true);
    _indice3->setVisible(true);
    _indice4->setVisible(true);
    _indice5->setVisible(true);
    _indice6->setVisible(true);

    _clock->setVisible(true);

    _questionLabel1->setVisible(false);
    _questionLabel2->setVisible(false);
    _questionLabel3->setVisible(false);

    _question1->setVisible(false);
    _question2->setVisible(false);
    _question3->setVisible(false);

    _final->setVisible(false);

    _textEdit->setVisible(false);
}

void MainWindow::final()
{
    _timer->stop();
    _indice1->setVisible(true);
    _indice2->setVisible(true);
    _indice3->setVisible(true);
    _indice4->setVisible(true);
    _indice5->setVisible(true);
    _indice6->setVisible(true);

    _clock->setVisible(false);

    _questionLabel1->setVisible(false);
    _questionLabel2->setVisible(false);
    _questionLabel3->setVisible(false);

    _pad1->setVisible(false);
    _pad2->setVisible(false);
    _pad3->setVisible(false);
    _pad4->setVisible(false);
    _pad5->setVisible(false);
    _pad6->setVisible(false);

    _question1->setVisible(false);
    _question2->setVisible(false);
    _question3->setVisible(false);

    _final->setVisible(true);
    _textEdit->setVisible(false);
    _archeo->setVisible(false);

    _finalID = 1;
    _timer = new QTimer();
    connect(_timer, SIGNAL(timeout()), this, SLOT(processFinal()));
    _timer->setInterval(500);
    _timer->start();
    _count = 0;
}

void MainWindow::initQuestion1()
{
    _timer->stop();
    emit gotoHome();
    _archeo->setVisible(false);
    setFont(_questionLabel1, 12);
    _questionLabel1->setText("Observez bien les empreintes à vos pieds. Vous pouvez voir des traces ");
    _questionLabel1->setGeometry(650, 450, 2000, 100);
    _questionLabel1->setVisible(true);

    setFont(_questionLabel2, 12);
    _questionLabel2->setText("de pas :");
    _questionLabel2->setGeometry(650, 490, 2000, 100);
    _questionLabel2->setVisible(true);

    _correctAnswer = 3;
    _currentQuestion = 1;
    _question1->setVisible(true);
    _question2->setVisible(true);
    _question3->setVisible(true);

    _question1->setStyleSheet(getButtonQuestionStyleSheet());
    _question2->setStyleSheet(getButtonQuestionStyleSheet());
    _question3->setStyleSheet(getButtonQuestionStyleSheet());

    _question1->setIcon(QIcon());
    _question1->setGeometry(650, 600, 400, 400);
    _question1->setText("d´humains");

    _question2->setIcon(QIcon());
    _question2->setGeometry(1050, 600, 400, 400);
    _question2->setText("d´animaux");

    _question3->setIcon(QIcon());
    _question3->setGeometry(1450, 600, 400, 400);
    _question3->setText("d´humains et d´animaux");
}

void MainWindow::initQuestion2()
{
    _timer->stop();
    emit gotoHome();
    _archeo->setVisible(false);
    setFont(_questionLabel1, 12);
    _questionLabel1->setText("Comparez la maquette devant vous à ces trois photos de chantiers de fouilles.");
    _questionLabel1->setGeometry(650, 450, 2000, 100);
    _questionLabel1->setVisible(true);

    setFont(_questionLabel2, 12);
    _questionLabel2->setText("Selon-vous, laquelle correspond à un site qui ressemble à celui d’Arleux ?");
    _questionLabel2->setGeometry(650, 490, 2000, 100);
    _questionLabel2->setVisible(true);

    _correctAnswer = 3;
    _currentQuestion = 2;
    _question1->setVisible(true);
    _question2->setVisible(true);
    _question3->setVisible(true);

    _question1->setStyleSheet(getButtonQuestionStyleSheet());
    _question2->setStyleSheet(getButtonQuestionStyleSheet());
    _question3->setStyleSheet(getButtonQuestionStyleSheet());

    _question1->setIcon(QIcon(QApplication::applicationDirPath() + "/files/archeo_1.png"));
    _question1->setGeometry(650, 600, 400, 400);
    _question1->setIconSize(QSize(300, 300));
    _question1->setText("");

    _question2->setIcon(QIcon(QApplication::applicationDirPath() + "/files/archeo_2.png"));
    _question2->setGeometry(1050, 600, 400, 400);
    _question2->setIconSize(QSize(300, 300));
    _question2->setText("");

    _question3->setIcon(QIcon(QApplication::applicationDirPath() + "/files/archeo_3.png"));
    _question3->setGeometry(1450, 600, 400, 400);
    _question3->setIconSize(QSize(300, 300));
    _question3->setText("");
}

void MainWindow::initQuestion3()
{
    _timer->stop();
    emit gotoHome();
    _archeo->setVisible(false);
    setFont(_questionLabel1, 12);
    _questionLabel1->setText("On voit des traces de découpe sur ces os de chien.");
    _questionLabel1->setGeometry(650, 450, 2000, 100);
    _questionLabel1->setVisible(true);

    setFont(_questionLabel2, 12);
    _questionLabel2->setText("Les voyez-vous aussi ? A quoi ressemblent-elles ?");
    _questionLabel2->setGeometry(650, 490, 2000, 100);
    _questionLabel2->setVisible(true);

    _correctAnswer = 3;
    _currentQuestion = 3;
    _question1->setVisible(true);
    _question2->setVisible(true);
    _question3->setVisible(true);

    _question1->setStyleSheet(getButtonQuestionStyleSheet());
    _question2->setStyleSheet(getButtonQuestionStyleSheet());
    _question3->setStyleSheet(getButtonQuestionStyleSheet());

    _question1->setIcon(QIcon(QApplication::applicationDirPath() + "/files/os_faux_1.png"));
    _question1->setGeometry(650, 600, 400, 400);
    _question1->setIconSize(QSize(300, 300));
    _question1->setText("");

    _question2->setIcon(QIcon(QApplication::applicationDirPath() + "/files/os_faux_2.png"));
    _question2->setGeometry(1050, 600, 400, 400);
    _question2->setIconSize(QSize(300, 300));
    _question2->setText("");

    _question3->setIcon(QIcon(QApplication::applicationDirPath() + "/files/os_vrai.png"));
    _question3->setGeometry(1450, 600, 400, 400);
    _question3->setIconSize(QSize(300, 300));
    _question3->setText("");
}

void MainWindow::initQuestion31()
{
    _timer->stop();
    emit gotoHome();
    _archeo->setVisible(false);
    setFont(_questionLabel1, 12);
    _questionLabel1->setText("Ces traces sont un indice de :");
    _questionLabel1->setGeometry(650, 450, 2000, 100);
    _questionLabel1->setVisible(true);

    _correctAnswer = 2;
    _currentQuestion = 31;
    _question1->setVisible(true);
    _question2->setVisible(true);
    _question3->setVisible(true);

    _question1->setStyleSheet(getButtonQuestionStyleSheet());
    _question2->setStyleSheet(getButtonQuestionStyleSheet());
    _question3->setStyleSheet(getButtonQuestionStyleSheet());

    _question1->setIcon(QIcon());
    _question1->setGeometry(650, 600, 400, 400);
    _question1->setIconSize(QSize(120, 120));
    _question1->setText("La chasse de ces animaux");

    _question2->setIcon(QIcon());
    _question2->setGeometry(1050, 600, 400, 400);
    _question2->setIconSize(QSize(120, 120));
    _question2->setText("La consommation de ces \n animaux par les humains");

    _question3->setIcon(QIcon());
    _question3->setGeometry(1450, 600, 400, 400);
    _question3->setIconSize(QSize(120, 120));
    _question3->setText(QString("La consommation de ces \n animaux par d’autres animaux"));
}

void MainWindow::initQuestion4()
{
    _timer->stop();
    emit gotoHome();
    _archeo->setVisible(false);
    setFont(_questionLabel1, 12);
    _questionLabel1->setText("Sur le chaudron en alliage cuivreux, vous pouvez voir des :");
    _questionLabel1->setGeometry(650, 450, 2000, 100);
    _questionLabel1->setVisible(true);

    _correctAnswer = 2;
    _currentQuestion = 4;
    _question1->setVisible(true);
    _question2->setVisible(true);
    _question3->setVisible(true);

    _question1->setStyleSheet(getButtonQuestionStyleSheet());
    _question2->setStyleSheet(getButtonQuestionStyleSheet());
    _question3->setStyleSheet(getButtonQuestionStyleSheet());

    _question1->setIcon(QIcon());
    _question1->setGeometry(650, 600, 400, 400);
    _question1->setIconSize(QSize(120, 120));
    _question1->setText("symboles de fleur");

    _question2->setIcon(QIcon());
    _question2->setGeometry(1050, 600, 400, 400);
    _question2->setIconSize(QSize(120, 120));
    _question2->setText("réparations");

    _question3->setIcon(QIcon());
    _question3->setGeometry(1450, 600, 400, 400);
    _question3->setIconSize(QSize(120, 120));
    _question3->setText("empreintes digitales");
}

void MainWindow::initQuestion41()
{
    _timer->stop();
    emit gotoHome();
    _archeo->setVisible(false);
    setFont(_questionLabel1, 12);
    _questionLabel1->setText("En effet, le propriétaire de l’époque a réparé son chaudron, ");
    _questionLabel1->setGeometry(650, 450, 2000, 100);
    _questionLabel1->setVisible(true);

    setFont(_questionLabel2, 12);
    _questionLabel2->setText("probablement parce que :");
    _questionLabel2->setGeometry(650, 490, 2000, 100);
    _questionLabel2->setVisible(true);

    _correctAnswer = 1;
    _currentQuestion = 41;
    _question1->setVisible(true);
    _question2->setVisible(true);
    _question3->setVisible(true);

    _question1->setStyleSheet(getButtonQuestionStyleSheet());
    _question2->setStyleSheet(getButtonQuestionStyleSheet());
    _question3->setStyleSheet(getButtonQuestionStyleSheet());

    _question1->setIcon(QIcon());
    _question1->setGeometry(650, 600, 400, 400);
    _question1->setIconSize(QSize(120, 120));
    _question1->setText("il n’est pas facile de se \n procurer un nouveau chaudron");

    _question2->setIcon(QIcon());
    _question2->setGeometry(1050, 600, 400, 400);
    _question2->setIconSize(QSize(120, 120));
    _question2->setText("c’est plus joli ainsi");

    _question3->setIcon(QIcon());
    _question3->setGeometry(1450, 600, 400, 400);
    _question3->setIconSize(QSize(120, 120));
    _question3->setText("il s’agit d’un \n chaudron sacré");
}

void MainWindow::initQuestion5()
{
    _timer->stop();
    emit gotoHome();
    _archeo->setVisible(false);
    setFont(_questionLabel1, 12);
    _questionLabel1->setText("Déchiffrez le graffiti sur ce bol :");
    _questionLabel1->setGeometry(650, 450, 2000, 100);
    _questionLabel1->setVisible(true);

    _correctAnswer = 3;
    _currentQuestion = 5;
    _question1->setVisible(true);
    _question2->setVisible(true);
    _question3->setVisible(true);

    _question1->setStyleSheet(getButtonQuestionStyleSheet());
    _question2->setStyleSheet(getButtonQuestionStyleSheet());
    _question3->setStyleSheet(getButtonQuestionStyleSheet());

    _question1->setIcon(QIcon());
    _question1->setGeometry(650, 600, 400, 400);
    _question1->setIconSize(QSize(120, 120));
    _question1->setText("Ushild");

    _question2->setIcon(QIcon());
    _question2->setGeometry(1050, 600, 400, 400);
    _question2->setIconSize(QSize(120, 120));
    _question2->setText("Avshilo");

    _question3->setIcon(QIcon());
    _question3->setGeometry(1450, 600, 400, 400);
    _question3->setIconSize(QSize(120, 120));
    _question3->setText("Aughild");
}

void callKeyboard()
{
    //    QProcess::execute("C:/Windows/System32/osk.exe");
    //    QDesktopServices::openUrl(QUrl("C:/Windows/System32/osk.exe"));
    //    system("start C:/Windows/System32/osk.exe");
    //    QProcess::startDetached("C:/Windows/System32/osk.exe");
    QProcess *process = new QProcess();
    QString program = "explorer.exe";
    QString folder = "C:\\Windows\\System32\\osk.exe";
    process->start(program, QStringList() << folder);
}

void MainWindow::initQuestion6()
{
    _timer->stop();
    emit gotoHome();
    _archeo->setVisible(false);
    setFont(_questionLabel1, 12);
    _questionLabel1->setText("Ces os présentent un côté plat inhabituel. L’interprétation actuelle veut");
    _questionLabel1->setGeometry(650, 450, 2000, 100);
    _questionLabel1->setVisible(true);

    setFont(_questionLabel2, 12);
    _questionLabel2->setText("qu´il s´agisse de patins à glace. Et vous ? À quoi auriez-vous pensé ?");
    _questionLabel2->setGeometry(650, 490, 2000, 100);
    _questionLabel2->setVisible(true);

    _questionLabel3->setGeometry(1300, 450, 400, 300);
    int w = _questionLabel3->width();
    int h = _questionLabel3->height();
    QPixmap p = QPixmap(QApplication::applicationDirPath() + "/files/patin.jpg");
    _questionLabel3->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
    _questionLabel3->setVisible(true);

    _correctAnswer = 1;
    _currentQuestion = 6;
    callKeyboard();
    _textEdit->setVisible(true);
    _textEdit->setGeometry(650, 800, 600, 120);

    _question1->setIcon(QIcon());
    _question1->setStyleSheet(getButtonStyleSheet());
    _question1->setIconSize(QSize(120, 120));
    _question1->setGeometry(1350, 800, 200, 100);
    _question1->setText("ENTRER");
    _question1->setVisible(true);

}

void MainWindow::answer1()
{
    if(_correctAnswer == 1)
    {
        if(setIndice(_currentQuestion))
        {
            hidePad(_currentQuestion);
            emit gotoHome();
            initArcheo(_currentQuestion, false);
        }
    }
    else
    {
        _question1->setStyleSheet(getButtonQuestionLoseStyleSheet());
    }
}

void MainWindow::answer2()
{
    if(_correctAnswer == 2)
    {
        if(setIndice(_currentQuestion))
        {
            hidePad(_currentQuestion);
            emit gotoHome();
            initArcheo(_currentQuestion, false);
        }
    }
    else
    {
        _question2->setStyleSheet(getButtonQuestionLoseStyleSheet());
    }
}

void MainWindow::answer3()
{
    if(_correctAnswer == 3)
    {
        if(setIndice(_currentQuestion))
        {
            hidePad(_currentQuestion);
            emit gotoHome();
            initArcheo(_currentQuestion, false);
        }
    }
    else
    {
        _question3->setStyleSheet(getButtonQuestionLoseStyleSheet());
    }
}

void MainWindow::initArcheo(int id, bool value)
{
    QPixmap p;
    if (!value)
    {
        _archeo->setVisible(true);
        _timerID = id;
        if(_timer)
            disconnect(_timer, SIGNAL(timeout()), this, SLOT(processMessages()));
        _timer = new QTimer();

        connect(_timer, SIGNAL(timeout()), this, SLOT(processMessages()));
        _timer->setInterval(3000);
        _timer->start();
        _archeo->setGeometry(1000, 400, 600, 600);
        int w = _archeo->width();
        int h = _archeo->height();
        if(id == 1)
        {
            p = QPixmap(QApplication::applicationDirPath() + "/files/ARCHEO1.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
        }
        if(id == 2)
        {
            //            _archeo->setGeometry(750, 450, 1200, 630);
            //            w = _archeo->width();
            //            h = _archeo->height();
            //            p = QPixmap(QApplication::applicationDirPath() + "/files/legendeQ2.png");
            //            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
            p = QPixmap(QApplication::applicationDirPath() + "/files/ARCHEO2.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
        }
        //        if(id == 21)
        //        {
        //            p = QPixmap(QApplication::applicationDirPath() + "/files/ARCHEO2.png");
        //            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
        //        }
        if(id == 31)
        {
            p = QPixmap(QApplication::applicationDirPath() + "/files/ARCHEO3.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
        }
        if(id == 41)
        {
            p = QPixmap(QApplication::applicationDirPath() + "/files/ARCHEO4.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
        }
        if(id == 5)
        {
            p = QPixmap(QApplication::applicationDirPath() + "/files/ARCHEO5.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
        }
        if(id == 6)
        {
            p = QPixmap(QApplication::applicationDirPath() + "/files/ARCHEO6.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
        }
    }
    else
    {
        _archeo->setVisible(true);
        _timer->stop();
        _archeo->setGeometry(650, 400, 600, 600);
        int w = _archeo->width();
        int h = _archeo->height();
        if(id == 1)
        {
            p = QPixmap(QApplication::applicationDirPath() + "/files/CONS1.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
            isFinish();
        }
        if(id == 2)
        {
            _archeo->setGeometry(780, 435, 1900, 650);
            w = _archeo->width();
            h = _archeo->height();
            p = QPixmap(QApplication::applicationDirPath() + "/files/CONS2.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
            isFinish();
        }
        if(id == 31)
        {
            p = QPixmap(QApplication::applicationDirPath() + "/files/CONS3.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
            isFinish();
        }
        if(id == 41)
        {
            p = QPixmap(QApplication::applicationDirPath() + "/files/CONS4.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
            isFinish();
        }
        if(id == 5)
        {
            p = QPixmap(QApplication::applicationDirPath() + "/files/CONS5.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
            isFinish();
        }
        if(id == 6)
        {
            p = QPixmap(QApplication::applicationDirPath() + "/files/CONS6.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
            isFinish();
        }
    }
}

void MainWindow::processMessages()
{
    //    if(_timerID == 2)
    //        initArcheo(21, false);
    //    else
    initArcheo(_timerID, true);
}

void MainWindow::processFinal()
{
    initFinal(_finalID);
    _finalID = _finalID + 1;
    if(_finalID > 3)
    {
        _finalID = 1;
        _count++;
    }
}

void MainWindow::initFinal(int id)
{
    _archeo->setVisible(true);
    _archeo->setGeometry(1000, 400, 600, 600);
    QPixmap p;

    int w = _archeo->width();
    int h = _archeo->height();
    if (_count < 4)
    {
        if(id == 1)
        {
            p = QPixmap(QApplication::applicationDirPath() + "/files/BRAVO1.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
        }
        if(id == 2)
        {
            p = QPixmap(QApplication::applicationDirPath() + "/files/BRAVO2.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
        }
        if(id == 3)
        {
            p = QPixmap(QApplication::applicationDirPath() + "/files/BRAVO3.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
        }
    }
    else
    {
        if(_timer)
            disconnect(_timer, SIGNAL(timeout()), this, SLOT(processFinal()));
        _timer = new QTimer();
        connect(_timer, SIGNAL(timeout()), this, SLOT(processFinal()));
        _timer->setInterval(5000);
        _timer->start();
        if(id == 1)
        {
            p = QPixmap(QApplication::applicationDirPath() + "/files/BRAVO4.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
        }
        if(id == 2)
        {
            p = QPixmap(QApplication::applicationDirPath() + "/files/BRAVO5.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
        }
        if(id == 3)
        {
            p = QPixmap(QApplication::applicationDirPath() + "/files/BRAVO6.png");
            _archeo->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
        }
    }
}

void MainWindow::isFinish()
{
    if( QString::compare(_indice1->text(), QString("proche")) == 0 &&
            QString::compare(_indice2->text(), QString("conjugaison")) == 0 &&
            QString::compare(_indice3->text(), QString("antérieur")) == 0 &&
            QString::compare(_indice4->text(), QString("nom et adjectif")) == 0 &&
            QString::compare(_indice5->text(), QString("avenir")) == 0 &&
            QString::compare(_indice6->text(), QString("demain")) == 0
            )
    {
        emit gotoFinal();
    }
}

