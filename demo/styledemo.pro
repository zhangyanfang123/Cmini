#-------------------------------------------------
#
# Project created by QtCreator 2017-02-19T12:55:42
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET              = styledemo
TEMPLATE            = app
MOC_DIR             = temp/moc
RCC_DIR             = temp/rcc
UI_DIR              = temp/ui
OBJECTS_DIR         = temp/obj
DESTDIR             = $$PWD/../bin
win32:RC_FILE       = other/main.rc
PRECOMPILED_HEADER  = head.h

INCLUDEPATH         += $$PWD
CONFIG              += qt warn_off

SOURCES             += main.cpp \
    fun.cpp \
    global.cpp \
    interinst.cpp \
    parser.cpp \
    symtab.cpp \
    var.cpp \
    genir.cpp \
    lex.cpp \
    scanner.cpp
SOURCES             += quicreator.cpp

HEADERS             += head.h \
    error.h \
    fun.h \
    id.h \
    keywords.h \
    num.h \
    operator.h \
    parser.h \
    scanner.h \
    str.h \
    symtab.h \
    token.h \
    tokentype.h \
    fun.h \
    parser.h \
    scanner.h \
    symtab.h \
    interinst.h \
    lex.h \
    var.h \
    char.h \
    genir.h \
    global.h
HEADERS             += quicreator.h

FORMS               += quicreator.ui

RESOURCES           += other/qss.qrc
RESOURCES           += other/main.qrc
