/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[34];
    char stringdata0[11];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[5];
    char stringdata5[8];
    char stringdata6[13];
    char stringdata7[11];
    char stringdata8[6];
    char stringdata9[20];
    char stringdata10[30];
    char stringdata11[31];
    char stringdata12[24];
    char stringdata13[19];
    char stringdata14[20];
    char stringdata15[17];
    char stringdata16[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 10),  // "signalFind"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 11),  // "sltTcpReply"
        QT_MOC_LITERAL(35, 4),  // "type"
        QT_MOC_LITERAL(40, 7),  // "dataVal"
        QT_MOC_LITERAL(48, 12),  // "sltTcpStatus"
        QT_MOC_LITERAL(61, 10),  // "sltAddChat"
        QT_MOC_LITERAL(72, 5),  // "Cell*"
        QT_MOC_LITERAL(78, 19),  // "parseAddFriendReply"
        QT_MOC_LITERAL(98, 29),  // "parseAddGroupRequestConfirmed"
        QT_MOC_LITERAL(128, 30),  // "parseAddFriendRequestConfirmed"
        QT_MOC_LITERAL(159, 23),  // "parseFriendMessageReply"
        QT_MOC_LITERAL(183, 18),  // "parseSendFileReply"
        QT_MOC_LITERAL(202, 19),  // "sltFileRecvFinished"
        QT_MOC_LITERAL(222, 16),  // "onleftBtnClicked"
        QT_MOC_LITERAL(239, 4)   // "page"
    },
    "MainWindow",
    "signalFind",
    "",
    "sltTcpReply",
    "type",
    "dataVal",
    "sltTcpStatus",
    "sltAddChat",
    "Cell*",
    "parseAddFriendReply",
    "parseAddGroupRequestConfirmed",
    "parseAddFriendRequestConfirmed",
    "parseFriendMessageReply",
    "parseSendFileReply",
    "sltFileRecvFinished",
    "onleftBtnClicked",
    "page"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    2,   83,    2, 0x08,    3 /* Private */,
       6,    1,   88,    2, 0x08,    6 /* Private */,
       7,    1,   91,    2, 0x08,    8 /* Private */,
       9,    1,   94,    2, 0x08,   10 /* Private */,
      10,    1,   97,    2, 0x08,   12 /* Private */,
      11,    1,  100,    2, 0x08,   14 /* Private */,
      12,    1,  103,    2, 0x08,   16 /* Private */,
      13,    1,  106,    2, 0x08,   18 /* Private */,
      14,    3,  109,    2, 0x08,   20 /* Private */,
      15,    1,  116,    2, 0x08,   24 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::QJsonValue,    4,    5,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, QMetaType::QJsonValue,    5,
    QMetaType::Void, QMetaType::QJsonValue,    5,
    QMetaType::Void, QMetaType::QJsonValue,    5,
    QMetaType::Void, QMetaType::QJsonValue,    5,
    QMetaType::Void, QMetaType::QJsonValue,    5,
    QMetaType::Void, QMetaType::UChar, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'signalFind'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>,
        // method 'sltTcpReply'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonValue, std::false_type>,
        // method 'sltTcpStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        // method 'sltAddChat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Cell *, std::false_type>,
        // method 'parseAddFriendReply'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonValue, std::false_type>,
        // method 'parseAddGroupRequestConfirmed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>,
        // method 'parseAddFriendRequestConfirmed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>,
        // method 'parseFriendMessageReply'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>,
        // method 'parseSendFileReply'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>,
        // method 'sltFileRecvFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onleftBtnClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalFind((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 1: _t->sltTcpReply((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[2]))); break;
        case 2: _t->sltTcpStatus((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1]))); break;
        case 3: _t->sltAddChat((*reinterpret_cast< std::add_pointer_t<Cell*>>(_a[1]))); break;
        case 4: _t->parseAddFriendReply((*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[1]))); break;
        case 5: _t->parseAddGroupRequestConfirmed((*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[1]))); break;
        case 6: _t->parseAddFriendRequestConfirmed((*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[1]))); break;
        case 7: _t->parseFriendMessageReply((*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[1]))); break;
        case 8: _t->parseSendFileReply((*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[1]))); break;
        case 9: _t->sltFileRecvFinished((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 10: _t->onleftBtnClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QJsonObject );
            if (_t _q_method = &MainWindow::signalFind; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signalFind(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
