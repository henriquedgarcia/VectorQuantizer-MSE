TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp\
    vectorquantizer.cc


INCLUDEPATH += \
    /usr/local/include/opencv

LIBS += \
    -L/usr/local/lib \
    -lopencv_core \
    -lopencv_imgcodecs \
    -lopencv_highgui \

HEADERS += \
    vectorquantizer.h
