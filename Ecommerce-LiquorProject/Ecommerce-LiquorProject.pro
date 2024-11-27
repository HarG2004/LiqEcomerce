QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    customer.cpp \
    customerlogin.cpp \
    customertable.cpp \
    database.cpp \
    main.cpp \
    mainwindow.cpp \
    managerlogin.cpp \
    order.cpp \
    ordertable.cpp \
    product.cpp \
    productlist.cpp \
    producttable.cpp \
    register.cpp \
    shoppingcart.cpp \
    table.cpp

HEADERS += \
    account.h \
    customer.h \
    customerlogin.h \
    customertable.h \
    database.h \
    mainwindow.h \
    managerlogin.h \
    order.h \
    ordertable.h \
    product.h \
    productlist.h \
    producttable.h \
    register.h \
    shoppingcart.h \
    table.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
