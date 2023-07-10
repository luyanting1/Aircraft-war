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
#include <app/app.h>
//#include <QMediaPlayer>
//#include <QMediaPlaylist>
#include <QApplication>
#include "view/view.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap welcome("://images/background1.png");
    QSplashScreen splash(welcome);
    splash.resize(welcome.size());
    splash.show();
    a.processEvents();
    QTimer::singleShot(1000, &splash, SLOT(close()));
    //std::shared_ptr<QGraphicsView> game_interface = make_shared<QGraphicsView>();
    QGraphicsView* view = new QGraphicsView;
    //std::shared_ptr<QWidget> splash_game_interface = static_pointer_cast<QWidget>(game_interface);
    splash.finish(view); //splash_game_interface.get());
    view->setWindowTitle(QObject::tr("Thunder Plane"));
    //game_interface->setWindowTitle(QObject::tr("Thunder Plane"));
    app ThunderPlane_app;
    ThunderPlane_app.run(view);
    return a.exec();
}
