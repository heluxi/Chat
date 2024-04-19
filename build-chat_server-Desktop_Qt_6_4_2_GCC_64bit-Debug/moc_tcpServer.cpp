/****************************************************************************
** Meta object code from reading C++ file 'tcpServer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MyChat/chat_server/tcpServer.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpServer.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_TcpMsgSever_t {
    uint offsetsAndSizes[2];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_TcpMsgSever_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_TcpMsgSever_t qt_meta_stringdata_TcpMsgSever = {
    {
        QT_MOC_LITERAL(0, 11)   // "TcpMsgSever"
    },
    "TcpMsgSever"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_TcpMsgSever[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject TcpMsgSever::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TcpMsgSever.offsetsAndSizes,
    qt_meta_data_TcpMsgSever,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_TcpMsgSever_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TcpMsgSever, std::true_type>
    >,
    nullptr
} };

void TcpMsgSever::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *TcpMsgSever::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpMsgSever::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpMsgSever.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TcpMsgSever::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_stringdata_TcpFileSever_t {
    uint offsetsAndSizes[20];
    char stringdata0[13];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[3];
    char stringdata4[5];
    char stringdata5[18];
    char stringdata6[17];
    char stringdata7[13];
    char stringdata8[16];
    char stringdata9[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_TcpFileSever_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_TcpFileSever_t qt_meta_stringdata_TcpFileSever = {
    {
        QT_MOC_LITERAL(0, 12),  // "TcpFileSever"
        QT_MOC_LITERAL(13, 18),  // "signalRecvFinished"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 2),  // "id"
        QT_MOC_LITERAL(36, 4),  // "json"
        QT_MOC_LITERAL(41, 17),  // "signalMsgToClient"
        QT_MOC_LITERAL(59, 16),  // "sltNewConnection"
        QT_MOC_LITERAL(76, 12),  // "sltConnected"
        QT_MOC_LITERAL(89, 15),  // "sltDisConnected"
        QT_MOC_LITERAL(105, 21)   // "sltClientDownloadFile"
    },
    "TcpFileSever",
    "signalRecvFinished",
    "",
    "id",
    "json",
    "signalMsgToClient",
    "sltNewConnection",
    "sltConnected",
    "sltDisConnected",
    "sltClientDownloadFile"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_TcpFileSever[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   50,    2, 0x06,    1 /* Public */,
       5,    3,   55,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   62,    2, 0x08,    8 /* Private */,
       7,    0,   63,    2, 0x08,    9 /* Private */,
       8,    0,   64,    2, 0x08,   10 /* Private */,
       9,    1,   65,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QJsonValue,    3,    4,
    QMetaType::Void, QMetaType::UChar, QMetaType::Int, QMetaType::QJsonValue,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonValue,    4,

       0        // eod
};

Q_CONSTINIT const QMetaObject TcpFileSever::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TcpFileSever.offsetsAndSizes,
    qt_meta_data_TcpFileSever,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_TcpFileSever_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TcpFileSever, std::true_type>,
        // method 'signalRecvFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>,
        // method 'signalMsgToClient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const quint8 &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>,
        // method 'sltNewConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sltConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sltDisConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sltClientDownloadFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>
    >,
    nullptr
} };

void TcpFileSever::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpFileSever *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalRecvFinished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[2]))); break;
        case 1: _t->signalMsgToClient((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[3]))); break;
        case 2: _t->sltNewConnection(); break;
        case 3: _t->sltConnected(); break;
        case 4: _t->sltDisConnected(); break;
        case 5: _t->sltClientDownloadFile((*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpFileSever::*)(int , const QJsonValue & );
            if (_t _q_method = &TcpFileSever::signalRecvFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpFileSever::*)(const quint8 & , const int & , const QJsonValue & );
            if (_t _q_method = &TcpFileSever::signalMsgToClient; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *TcpFileSever::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpFileSever::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpFileSever.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TcpFileSever::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void TcpFileSever::signalRecvFinished(int _t1, const QJsonValue & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpFileSever::signalMsgToClient(const quint8 & _t1, const int & _t2, const QJsonValue & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
