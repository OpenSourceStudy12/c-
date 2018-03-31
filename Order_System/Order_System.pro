TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/src/client.cpp \
    src/src/courier.cpp \
    src/src/dishes.cpp \
    src/src/main.cpp \
    src/src/menu.cpp \
    src/src/order.cpp \
    src/src/person.cpp \
    src/src/shop.cpp \
    src/src/sql_lrh.cpp

DISTFILES += \
    doc/c++外卖点餐系统.docx \
    doc/c++外卖点餐系统.png \
    doc/readme

HEADERS += \
    src/inc/client.h \
    src/inc/courier.h \
    src/inc/dishes.h \
    src/inc/menu.h \
    src/inc/order.h \
    src/inc/person.h \
    src/inc/shop.h \
    src/inc/sql_lrh.h

INCLUDEPATH += \
    src/inc

LIBS += \
    -lmysqlclient
