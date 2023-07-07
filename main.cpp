#include "app/app.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    app AW_MVVM_app;
    AW_MVVM_app.run();
    return a.exec();
}
