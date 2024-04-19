/****************************************************************************
** Meta object code from reading C++ file 'clientsocket.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MyChat/chat_server/clientsocket.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientsocket.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_tcpSocket_t {
    uint offsetsAndSizes[22];
    char stringdata0[10];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[3];
    char stringdata5[13];
    char stringdata6[11];
    char stringdata7[18];
    char stringdata8[5];
    char stringdata9[11];
    char stringdata10[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_tcpSocket_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_tcpSocket_t qt_meta_stringdata_tcpSocket = {
    {
        QT_MOC_LITERAL(0, 9),  // "tcpSocket"
        QT_MOC_LITERAL(10, 19),  // "sendMessagetoClient"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 4),  // "data"
        QT_MOC_LITERAL(36, 2),  // "ID"
        QT_MOC_LITERAL(39, 12),  // "successLogin"
        QT_MOC_LITERAL(52, 10),  // "sendAllMsg"
        QT_MOC_LITERAL(63, 17),  // "signalMsgToClient"
        QT_MOC_LITERAL(81, 4),  // "type"
        QT_MOC_LITERAL(86, 10),  // "reveicerID"
        QT_MOC_LITERAL(97, 7)   // "dataVal"
    },
    "tcpSocket",
    "sendMessagetoClient",
    "",
    "data",
    "ID",
    "successLogin",
    "sendAllMsg",
    "signalMsgToClient",
    "type",
    "reveicerID",
    "dataVal"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_tcpSocket[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   38,    2, 0x06,    1 /* Public */,
       5,    0,   43,    2, 0x06,    4 /* Public */,
       6,    2,   44,    2, 0x06,    5 /* Public */,
       7,    3,   49,    2, 0x06,    8 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonValue, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonValue, QMetaType::Int,    2,    4,
    QMetaType::Void, QMetaType::UChar, QMetaType::Int, QMetaType::QJsonValue,    8,    9,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject tcpSocket::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_tcpSocket.offsetsAndSizes,
    qt_meta_data_tcpSocket,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_tcpSocket_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<tcpSocket, std::true_type>,
        // method 'sendMessagetoClient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonValue, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'successLogin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendAllMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonValue, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'signalMsgToClient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const quint8 &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>
    >,
    nullptr
} };

void tcpSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<tcpSocket *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendMessagetoClient((*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->successLogin(); break;
        case 2: _t->sendAllMsg((*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->signalMsgToClient((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (tcpSocket::*)(QJsonValue , int );
            if (_t _q_method = &tcpSocket::sendMessagetoClient; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (tcpSocket::*)();
            if (_t _q_method = &tcpSocket::successLogin; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (tcpSocket::*)(QJsonValue , int );
            if (_t _q_method = &tcpSocket::sendAllMsg; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (tcpSocket::*)(const quint8 & , const int & , const QJsonValue & );
            if (_t _q_method = &tcpSocket::signalMsgToClient; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *tcpSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tcpSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tcpSocket.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int tcpSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void tcpSocket::sendMessagetoClient(QJsonValue _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void tcpSocket::successLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void tcpSocket::sendAllMsg(QJsonValue _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void tcpSocket::signalMsgToClient(const quint8 & _t1, const int & _t2, const QJsonValue & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
namespace {
struct qt_meta_stringdata_tcpFileSocket_t {
    uint offsetsAndSizes[34];
    char stringdata0[14];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[19];
    char stringdata5[3];
    char stringdata6[5];
    char stringdata7[18];
    char stringdata8[5];
    char stringdata9[11];
    char stringdata10[8];
    char stringdata11[19];
    char stringdata12[13];
    char stringdata13[29];
    char stringdata14[13];
    char stringdata15[24];
    char stringdata16[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_tcpFileSocket_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_tcpFileSocket_t qt_meta_stringdata_tcpFileSocket = {
    {
        QT_MOC_LITERAL(0, 13),  // "tcpFileSocket"
        QT_MOC_LITERAL(14, 15),  // "signalConnected"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 18),  // "signalDisConnected"
        QT_MOC_LITERAL(50, 18),  // "signalRecvFinished"
        QT_MOC_LITERAL(69, 2),  // "id"
        QT_MOC_LITERAL(72, 4),  // "json"
        QT_MOC_LITERAL(77, 17),  // "signalMsgToClient"
        QT_MOC_LITERAL(95, 4),  // "type"
        QT_MOC_LITERAL(100, 10),  // "reveicerID"
        QT_MOC_LITERAL(111, 7),  // "dataVal"
        QT_MOC_LITERAL(119, 18),  // "signalDownloadFile"
        QT_MOC_LITERAL(138, 12),  // "displayError"
        QT_MOC_LITERAL(151, 28),  // "QAbstractSocket::SocketError"
        QT_MOC_LITERAL(180, 12),  // "sltReadyRead"
        QT_MOC_LITERAL(193, 23),  // "sltUpdateClientProgress"
        QT_MOC_LITERAL(217, 8)   // "numBytes"
    },
    "tcpFileSocket",
    "signalConnected",
    "",
    "signalDisConnected",
    "signalRecvFinished",
    "id",
    "json",
    "signalMsgToClient",
    "type",
    "reveicerID",
    "dataVal",
    "signalDownloadFile",
    "displayError",
    "QAbstractSocket::SocketError",
    "sltReadyRead",
    "sltUpdateClientProgress",
    "numBytes"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_tcpFileSocket[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,
       3,    0,   63,    2, 0x06,    2 /* Public */,
       4,    2,   64,    2, 0x06,    3 /* Public */,
       7,    3,   69,    2, 0x06,    6 /* Public */,
      11,    1,   76,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    1,   79,    2, 0x08,   12 /* Private */,
      14,    0,   82,    2, 0x08,   14 /* Private */,
      15,    1,   83,    2, 0x08,   15 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QJsonValue,    5,    6,
    QMetaType::Void, QMetaType::UChar, QMetaType::Int, QMetaType::QJsonValue,    8,    9,   10,
    QMetaType::Void, QMetaType::QJsonValue,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   16,

       0        // eod
};

Q_CONSTINIT const QMetaObject tcpFileSocket::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_tcpFileSocket.offsetsAndSizes,
    qt_meta_data_tcpFileSocket,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_tcpFileSocket_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<tcpFileSocket, std::true_type>,
        // method 'signalConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalDisConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalRecvFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>,
        // method 'signalMsgToClient'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const quint8 &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>,
        // method 'signalDownloadFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>,
        // method 'displayError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>,
        // method 'sltReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sltUpdateClientProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>
    >,
    nullptr
} };

void tcpFileSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<tcpFileSocket *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalConnected(); break;
        case 1: _t->signalDisConnected(); break;
        case 2: _t->signalRecvFinished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[2]))); break;
        case 3: _t->signalMsgToClient((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[3]))); break;
        case 4: _t->signalDownloadFile((*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[1]))); break;
        case 5: _t->displayError((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 6: _t->sltReadyRead(); break;
        case 7: _t->sltUpdateClientProgress((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (tcpFileSocket::*)();
            if (_t _q_method = &tcpFileSocket::signalConnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (tcpFileSocket::*)();
            if (_t _q_method = &tcpFileSocket::signalDisConnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (tcpFileSocket::*)(int , const QJsonValue & );
            if (_t _q_method = &tcpFileSocket::signalRecvFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (tcpFileSocket::*)(const quint8 & , const int & , const QJsonValue & );
            if (_t _q_method = &tcpFileSocket::signalMsgToClient; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (tcpFileSocket::*)(const QJsonValue & );
            if (_t _q_method = &tcpFileSocket::signalDownloadFile; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *tcpFileSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tcpFileSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tcpFileSocket.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int tcpFileSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void tcpFileSocket::signalConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void tcpFileSocket::signalDisConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void tcpFileSocket::signalRecvFinished(int _t1, const QJsonValue & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void tcpFileSocket::signalMsgToClient(const quint8 & _t1, const int & _t2, const QJsonValue & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void tcpFileSocket::signalDownloadFile(const QJsonValue & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
