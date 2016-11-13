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

#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include <QtWidgets>
#include <QKeyEvent>
#include <iostream>
#include <QTimer>

#include "questionwidget.h"
#include "homewidget.h"

QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QMenu;
class QListWidget;
QT_END_NAMESPACE

//! [0]
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    void resizeEvent(QResizeEvent* evt) override;
private slots:
    void home();
    void final();
    void processMessages();
    void processFinal();

    void initQuestion1();
    void initQuestion2();
    void initQuestion3();
    void initQuestion31();
    void initQuestion4();
    void initQuestion41();
    void initQuestion5();
    void initQuestion6();

    void answer1();
    void answer2();
    void answer3();

signals:
    void gotoHome();
    void gotoFinal();

private:
    void createActions();
    void createIndices();
    void createPad();
    void createClock();
    void createWidgets();
    void createQuestion();
    void setFont(QLabel*, int);
    bool setIndice(int);
    void hidePad(int id);
    void initArcheo(int, bool);
    void initFinal(int);
    void isFinish();

    QLabel *_indice1, *_indice2, *_indice3, *_indice4, *_indice5, *_indice6;
    QPushButton *_pad1, *_pad2, *_pad3, *_pad4, *_pad5, *_pad6;
    DigitalClock *_clock;

    QLabel *_questionLabel1, *_questionLabel2, *_questionLabel3;
    QPushButton *_question1, *_question2, *_question3;
    int _correctAnswer, _currentQuestion, _timerID, _finalID, _count;
    QTextEdit *_textEdit;
    QTimer* _timer;
    QLabel* _archeo;

    QLabel* _final;
};
//! [0]

#endif
