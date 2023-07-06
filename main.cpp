#include "mainwindow.h"
#include <ctime>
#include <vector>
#include <cassert>
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <QSplashScreen>
#include <QUrl>
#include <QGraphicsView>
//#include <QMediaPlayer>
//#include <QMediaPlaylist>
#include <QApplication>
#include "view.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPixmap welcome("://images/background1.png");
    QSplashScreen splash(welcome);
    splash.resize(welcome.size());
    splash.show();
    app.processEvents();
    QTimer::singleShot(1000, &splash, SLOT(close()));
    View *ctrl = new View;
    QGraphicsView *game_interface = new QGraphicsView;
    splash.finish( game_interface);
    game_interface->setWindowTitle(QObject::tr("Thunder Plane"));
    game_interface->setScene(ctrl);
    game_interface->setBackgroundBrush(QBrush(QPixmap("://images/background1.png")));
    game_interface->show();
    return app.exec();
}
