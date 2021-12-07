QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    accountbook.cpp \
    counter.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    showresult.cpp \
    storage.cpp \
    takenumber.cpp \
    windows.cpp
    transaction.cpp


HEADERS += \
    account.h \
    accountbook.h \
    counter.h \
    mainmenu.h \
    mainwindow.h \
    showresult.h \
    storage.h \
    takenumber.h \
    windows.h
    transaction.h

FORMS += \
    mainmenu.ui \
    mainwindow.ui \
    showresult.ui \
    storage.ui \
    takenumber.ui \
    windows.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    YHXT.pro.user
