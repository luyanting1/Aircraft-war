QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    common/Object.cpp \
    common/common.cpp \
    main.cpp \
    mainwindow.cpp \
    app/app.cpp \
    model/model.cpp \
    view/sink/viewpropertysink.cpp \
    view/view.cpp \
    viewmodel/command/allbulletmovecommand.cpp \
    viewmodel/command/bossgeneratecommand.cpp \
    viewmodel/command/enemybulletshootcommand.cpp \
    viewmodel/command/enemygeneratecommand.cpp \
    viewmodel/command/enemymovecommand.cpp \
    viewmodel/command/gamepausecommand.cpp \
    viewmodel/command/gameresetcommand.cpp \
    viewmodel/command/playerbulletshootcommand.cpp \
    viewmodel/command/playergeneratecommand.cpp \
    viewmodel/command/playermovecommand.cpp \
    viewmodel/command/skillusecommand.cpp \
    viewmodel/sink/viewmodelsink.cpp \
    viewmodel/viewmodel.cpp \
    base/Bullet.cpp \
    base/EnemyPlane.cpp \
    base/MyPlane.cpp \
    base/Plane.cpp

HEADERS += \
    base/init.h \
    common/Object.h \
    common/common.h \
    mainwindow.h \
    app/app.h \
    model/model.h \
    view/sink/viewpropertysink.h \
    view/view.h \
    viewmodel/command/allbulletmovecommand.h \
    viewmodel/command/bossgeneratecommand.h \
    viewmodel/command/enemybulletshootcommand.h \
    viewmodel/command/enemygeneratecommand.h \
    viewmodel/command/enemymovecommand.h \
    viewmodel/command/gamepausecommand.h \
    viewmodel/command/gameresetcommand.h \
    viewmodel/command/playerbulletshootcommand.h \
    viewmodel/command/playergeneratecommand.h \
    viewmodel/command/playermovecommand.h \
    viewmodel/command/skillusecommand.h \
    viewmodel/sink/viewmodelsink.h \
    viewmodel/viewmodel.h \
    common/etlbase.h \
    base/Bullet.h \
    base/EnemyPlane.h \
    base/MyPlane.h \
    base/Plane.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    AW_MVVM_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
