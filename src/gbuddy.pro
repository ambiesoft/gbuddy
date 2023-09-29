QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../lsMisc/stdQt/ambapp.cpp \
    ../../lsMisc/stdQt/inisettings.cpp \
    ../../lsMisc/stdQt/runguard.cpp \
    ../../lsMisc/stdosd/stdosd.cpp \
    ../../lsMisc/stdQt/stdQt.cpp \
    globals.cpp \
    helper.cpp \
    main.cpp \
    mainwindow.cpp \
    optiondialog.cpp

HEADERS += \
    ../../lsMisc/stdQt/ambapp.h \
    ../../lsMisc/stdQt/inisettings.h \
    ../../lsMisc/stdQt/runguard.h \
    ../../lsMisc/stdosd/stdosd.h \
    ../../lsMisc/stdosd/stdosd_exception.h \
    ../../lsMisc/stdosd/stdosd_literal.h \
    ../../lsMisc/stdQt/stdQt.h \
    consts.h \
    globals.h \
    helper.h \
    mainwindow.h \
    optiondialog.h

FORMS += \
    mainwindow.ui \
    optiondialog.ui

message($$QMAKESPEC)

win32 {
message("win32")
    HEADERS += ../../lsMisc/OpenCommon.h \
            ../../lsMisc/GetLastErrorString.h

    SOURCES += ../../lsMisc/OpenCommon.cpp \
            ../../lsMisc/GetLastErrorString.cpp \
            ../../lsMisc/stdosd/stdosd_win.cpp \
            ../../lsMisc/stdQt/stdQt_win32.cpp

    win32-g++ {
        message("win32-g++")
        LIBS += -lshlwapi -lPsapi
    }
    win32-msvc* {
        message("win32-msvc*")
        LIBS += User32.lib
    }

    # TODO(set icon)
    #RC_ICONS += icon.ico
}
linux {
    message("linux-g++")

    SOURCES += \
        ../../lsMisc/stdQt/stdQt_linux.cpp \
        ../../lsMisc/stdosd/stdosd_linux.cpp \

    # TODO(set icon)
    #RC_ICONS += icon.ico
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
