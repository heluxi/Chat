 

RESOURCES += \
    $$PWD/icon.qrc

FORMS += \
    $$PWD/dialog_change_city/dialog_change_city.ui \
    $$PWD/wtheatherdlg.ui

DISTFILES += \
    $$PWD/back.jpg \
    $$PWD/icons/air_quality.png \
    $$PWD/icons/local.png \
    $$PWD/icons/refresh.png \
    $$PWD/icons/weather_icons/baoyu.png \
    $$PWD/icons/weather_icons/bingbao.png \
    $$PWD/icons/weather_icons/daxue.png \
    $$PWD/icons/weather_icons/dayu.png \
    $$PWD/icons/weather_icons/duoyun.png \
    $$PWD/icons/weather_icons/leiyu.png \
    $$PWD/icons/weather_icons/qing.png \
    $$PWD/icons/weather_icons/shachen.png \
    $$PWD/icons/weather_icons/wumai.png \
    $$PWD/icons/weather_icons/xiaoyu.png \
    $$PWD/icons/weather_icons/xuezhuanqing.png \
    $$PWD/icons/weather_icons/yeduoyun.png \
    $$PWD/icons/weather_icons/zhenyu.png \
    $$PWD/icons/weather_icons/zhongyu.png \
    $$PWD/jsonCity/city.json \
    $$PWD/weather_icon.png \
    $$PWD/weather_zh_CN.ts

HEADERS += \
    $$PWD/class_net_thread/net_thread.h \
    $$PWD/class_weather/weather.h \
    $$PWD/define_qlabel/define_qlabel.h \
    $$PWD/dialog_change_city/dialog_change_city.h \
    $$PWD/global.h \
    $$PWD/weather_param/weather_info.h \
    $$PWD/wtheatherdlg.h

SOURCES += \
    $$PWD/class_net_thread/net_thread.cpp \
    $$PWD/class_weather/weather.cpp \
    $$PWD/define_qlabel/define_qlabel.cpp \
    $$PWD/dialog_change_city/dialog_change_city.cpp \
    $$PWD/wtheatherdlg.cpp
