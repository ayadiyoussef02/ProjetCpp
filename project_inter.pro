#QT       += core gui sql
QT       += core gui sql network multimedia multimediawidgets charts printsupport widgets axcontainer serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    arduino.cpp \
    arduino1.cpp \
    cherch.cpp \
    chercheur.cpp \
    connection.cpp \
    emp.cpp \
    employee.cpp \
    exportexcel.cpp \
    format.cpp \
    formation.cpp \
    lab.cpp \
    labo.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    pub.cpp \
    publication.cpp \
    qrcodegen.cpp \
    stat.cpp \
    stat_combo.cpp \
    temp.cpp

HEADERS += \
    arduino.h \
    arduino1.h \
    cherch.h \
    chercheur.h \
    connection.h \
    emp.h \
    employee.h \
    exportexcel.h \
    format.h \
    formation.h \
    lab.h \
    labo.h \
    mainwindow.h \
    menu.h \
    pub.h \
    publication.h \
    qrcodegen.h \
    stat.h \
    stat_combo.h \
    temp.h \
    webaxwidget.h

FORMS += \
    cherch.ui \
    emp.ui \
    format.ui \
    lab.ui \
    mainwindow.ui \
    menu.ui \
    pub.ui \
    stat.ui \
    stat_combo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    PHOTO.png
