greaterThan(QT_MAJOR_VERSION, 4) {
    QT       += widgets serialport printsupport
} else {
    include($$QTSERIALPORT_PROJECT_ROOT/src/serialport/qt4support/serialport.prf)
}

TARGET = terminal printsupport
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    mainwindow.h \
    qcustomplot.h


FORMS += \
    mainwindow.ui
