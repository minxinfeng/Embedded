#-------------------------------------------------
#
# Project created by QtCreator 2013-12-14T19:10:21
#
#-------------------------------------------------

QT       += core gui

TARGET = GPSMapApp
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    	gpsreader.cpp\
	road.cpp \
    	posNode.cpp

HEADERS  += widget.h \
    gpsreader.h\
    road.h \
    posNode.h

FORMS    += widget.ui

OTHER_FILES += \
    graph.txt \
    node.txt \
    start.txt
