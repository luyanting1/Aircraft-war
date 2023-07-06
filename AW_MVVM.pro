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
    main.cpp \
    mainwindow.cpp \
    app/app.cpp \
    viewmodel/command/frameruncommand.cpp \
    viewmodel/command/gamepausecommand.cpp \
    viewmodel/command/gameresetcommand.cpp \
    viewmodel/command/playermovecommand.cpp \
    viewmodel/command/skillusecommand.cpp \
    viewmodel/sink/viewmodelsink.cpp \
    viewmodel/viewmodel.cpp \
    base/Bullet.cpp \
    base/EnemyPlane.cpp \
    base/MyPlane.cpp \
    base/Plane.cpp \
    base/Object.cpp

HEADERS += \
    mainwindow.h \
    app/app.h \
    viewmodel/command/frameruncommand.h \
    viewmodel/command/gamepausecommand.h \
    viewmodel/command/gameresetcommand.h \
    viewmodel/command/playermovecommand.h \
    viewmodel/command/skillusecommand.h \
    viewmodel/sink/viewmodelsink.h \
    viewmodel/viewmodel.h \
    common/etlbase.h \
    common/precomp.h \
    base/Bullet.h \
    base/EnemyPlane.h \
    base/MyPlane.h \
    base/Plane.h \
    base/Object.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    AW_MVVM_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
