QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cube.cpp \
    cuberesize.cpp \
    dot.cpp \
    ellipse.cpp \
    line.cpp \
    lineellipse.cpp \
    main.cpp \
    rect.cpp \
    shape.cpp \
    shapeobjecteditor.cpp \
    tabletcoord.cpp

HEADERS += \
    cube.h \
    cuberesize.h \
    dot.h \
    ellipse.h \
    line.h \
    lineellipse.h \
    lineellipse.h \
    rect.h \
    rectangle.h \
    shape.h \
    shapeobjecteditor.h \
    tabletcoord.h

FORMS += \
    cuberesize.ui \
    shapeobjecteditor.ui \
    tabletcoord.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourse.qrc
