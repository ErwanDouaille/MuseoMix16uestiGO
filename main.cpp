#include "mainwindow.h"
#include <QApplication>
#include <QtPlugin>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("ErwanDouaille");
    app.setApplicationName("uestiGO");
    MainWindow *mainWin = new MainWindow();
    mainWin->show();
    return app.exec();
}
