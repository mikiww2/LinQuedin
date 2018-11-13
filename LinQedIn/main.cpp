
#include <iostream>

#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>

#include "mainWindow.h"

using std::cout;

int main(int argc,char* argv[]) {

    QApplication app(argc,argv);

    MainWindow *w = new MainWindow;
    QRect screenGeometry = QApplication::desktop()->screenGeometry();

    int x = (screenGeometry.width()-w->width()) / 2;
    int y = (screenGeometry.height()-w->height()) / 2;

    w->move(x,y);

    w->show();

    return app.exec();
}
