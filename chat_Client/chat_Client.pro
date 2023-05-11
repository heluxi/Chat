QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatlist.cpp \
    dlg_forget.cpp \
    dlg_regiseter.cpp \
    frienddlg.cpp \
    main.cpp \
    mainwindow.cpp \
    page_login.cpp \
    setnetdialog.cpp \
    sql_manage.cpp \
    tcp_manage.cpp

HEADERS += \
    chatlist.h \
    dlg_forget.h \
    dlg_regiseter.h \
    frienddlg.h \
    mainwindow.h \
    page_login.h \
    setnetdialog.h \
    sql_manage.h \
    tcp_manage.h \
    type.h

FORMS += \
    chatlist.ui \
    dlg_forget.ui \
    dlg_regiseter.ui \
    frienddlg.ui \
    mainwindow.ui \
    page_login.ui \
    setnetdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    icon \
    login.jpg \
    register.jpg \
    res/pic/3.1 设置.png \
    res/pic/Chat.png \
    res/pic/ic_add_2.png \
    res/pic/减号.png \
    res/pic/删除2.png \
    res/pic/卡通头像.png \
    res/pic/图片.png \
    res/pic/天猫.png \
    res/pic/截图.png \
    res/pic/搜索.png \
    res/pic/放大.png \
    res/pic/文件夹.png \
    res/pic/用户.png \
    res/pic/表情.png \
    res/pic/解除固定,图钉.png
