QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatlist.cpp \
    frienddlg.cpp \
    leftw.cpp \
    main.cpp \
    mainwindow.cpp \
#    qnchatmessage.cpp \
    sql_manage.cpp \
    tcp_manage.cpp

HEADERS += \
    chatlist.h \
    frienddlg.h \
    leftw.h \
    mainwindow.h \
#    qnchatmessage.h \
    sql_manage.h \
    tcp_manage.h

FORMS += \
    chatlist.ui \
    frienddlg.ui \
    leftw.ui \
    mainwindow.ui \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include($$PWD/comapi/comapi.pri)
include($$PWD/CutScreen/CutScreen.pri)
include($$PWD/midw/midw.pri)
include($$PWD/rightw/rightw.pri)
include($$PWD/login/login.pri)
include($$PWD/weather/weather.pri)

RESOURCES += \
    res.qrc

DISTFILES += \
    CutScreen/image/control_02.jpg \
    CutScreen/image/control_03.jpg \
    CutScreen/image/control_04.jpg \
    CutScreen/image/control_05.jpg \
    CutScreen/image/control_06.jpg \
    CutScreen/image/control_07.jpg \
    CutScreen/image/control_08.jpg \
    CutScreen/image/control_09.jpg \
    CutScreen/image/control_10.jpg \
    CutScreen/image/control_11.jpg \
    CutScreen/image/control_12.jpg \
    CutScreen/image/control_13.jpg \
    CutScreen/screenimage/ima.jpg \
    CutScreen/screenimage/ima1.jpg \
    CutScreen/screenimage/ima2.jpg \
    CutScreen/screenimage/ima3.jpg \
    CutScreen/screenimage/ima4.jpg \
    CutScreen/screenimage/ima5.jpg \
    icon \
    login.jpg \
    register.jpg \
    res/pic/3.1 设置.png \
    res/pic/Chat.png \
    res/pic/control_01.jpg \
    res/pic/control_02.jpg \
    res/pic/control_03.jpg \
    res/pic/control_04.jpg \
    res/pic/control_05.jpg \
    res/pic/control_06.jpg \
    res/pic/control_07.jpg \
    res/pic/control_08.jpg \
    res/pic/control_09.jpg \
    res/pic/control_10.jpg \
    res/pic/control_11.jpg \
    res/pic/control_12.jpg \
    res/pic/control_13.jpg \
    res/pic/ic_add_2.png \
    res/pic/减号.png \
    res/pic/删除2.png \
    res/pic/卡通头像.png \
    res/pic/图片.png \
    res/pic/天气.svg \
    res/pic/天猫.png \
    res/pic/截图.png \
    res/pic/搜索.png \
    res/pic/放大.png \
    res/pic/文件夹.png \
    res/pic/用户.png \
    res/pic/表情.png \
    res/pic/解除固定,图钉.png
