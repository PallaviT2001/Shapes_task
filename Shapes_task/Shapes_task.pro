TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle

SOURCES += \
        MainWindow.cpp \
        ShapeWidget.cpp \
        main.cpp

HEADERS += \
    MainWindow.h \
    ShapeWidget.h

QT += widgets
