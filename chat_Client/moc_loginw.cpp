/****************************************************************************
** Meta object code from reading C++ file 'loginw.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "login/loginw.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginw.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_loginw_t {
    uint offsetsAndSizes[46];
    char stringdata0[7];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[11];
    char stringdata5[13];
    char stringdata6[16];
    char stringdata7[22];
    char stringdata8[17];
    char stringdata9[21];
    char stringdata10[8];
    char stringdata11[11];
    char stringdata12[14];
    char stringdata13[14];
    char stringdata14[13];
    char stringdata15[6];
    char stringdata16[12];
    char stringdata17[20];
    char stringdata18[15];
    char stringdata19[12];
    char stringdata20[13];
    char stringdata21[26];
    char stringdata22[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_loginw_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_loginw_t qt_meta_stringdata_loginw = {
    {
        QT_MOC_LITERAL(0, 6),  // "loginw"
        QT_MOC_LITERAL(7, 12),  // "rotateWindow"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 11),  // "closeWindow"
        QT_MOC_LITERAL(33, 10),  // "hideWindow"
        QT_MOC_LITERAL(44, 12),  // "loginSuccess"
        QT_MOC_LITERAL(57, 15),  // "openRegisterWnd"
        QT_MOC_LITERAL(73, 21),  // "openForgetPasswordWnd"
        QT_MOC_LITERAL(95, 16),  // "signalRegisterOK"
        QT_MOC_LITERAL(112, 20),  // "signalForgetPwdReply"
        QT_MOC_LITERAL(133, 7),  // "dataVal"
        QT_MOC_LITERAL(141, 10),  // "changePage"
        QT_MOC_LITERAL(152, 13),  // "showNotifyMsg"
        QT_MOC_LITERAL(166, 13),  // "hideNotifyMsg"
        QT_MOC_LITERAL(180, 12),  // "sltTcpStatus"
        QT_MOC_LITERAL(193, 5),  // "state"
        QT_MOC_LITERAL(199, 11),  // "slotTimeout"
        QT_MOC_LITERAL(211, 19),  // "sltFileRecvFinished"
        QT_MOC_LITERAL(231, 14),  // "checkAutoLogin"
        QT_MOC_LITERAL(246, 11),  // "sltRegister"
        QT_MOC_LITERAL(258, 12),  // "sltChangePwd"
        QT_MOC_LITERAL(271, 25),  // "writeOffLineMsgToDatabase"
        QT_MOC_LITERAL(297, 16)   // "sltGetOffLineMsg"
    },
    "loginw",
    "rotateWindow",
    "",
    "closeWindow",
    "hideWindow",
    "loginSuccess",
    "openRegisterWnd",
    "openForgetPasswordWnd",
    "signalRegisterOK",
    "signalForgetPwdReply",
    "dataVal",
    "changePage",
    "showNotifyMsg",
    "hideNotifyMsg",
    "sltTcpStatus",
    "state",
    "slotTimeout",
    "sltFileRecvFinished",
    "checkAutoLogin",
    "sltRegister",
    "sltChangePwd",
    "writeOffLineMsgToDatabase",
    "sltGetOffLineMsg"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_loginw[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  128,    2, 0x06,    1 /* Public */,
       3,    0,  129,    2, 0x06,    2 /* Public */,
       4,    0,  130,    2, 0x06,    3 /* Public */,
       5,    0,  131,    2, 0x06,    4 /* Public */,
       6,    0,  132,    2, 0x06,    5 /* Public */,
       7,    0,  133,    2, 0x06,    6 /* Public */,
       8,    1,  134,    2, 0x06,    7 /* Public */,
       9,    1,  137,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,  140,    2, 0x0a,   11 /* Public */,
      12,    1,  141,    2, 0x0a,   12 /* Public */,
      13,    0,  144,    2, 0x0a,   14 /* Public */,
      14,    1,  145,    2, 0x0a,   15 /* Public */,
      16,    0,  148,    2, 0x0a,   17 /* Public */,
      17,    3,  149,    2, 0x0a,   18 /* Public */,
      18,    0,  156,    2, 0x0a,   22 /* Public */,
      19,    1,  157,    2, 0x0a,   23 /* Public */,
      20,    1,  160,    2, 0x0a,   25 /* Public */,
      21,    1,  163,    2, 0x0a,   27 /* Public */,
      22,    0,  166,    2, 0x0a,   29 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonValue,    2,
    QMetaType::Void, QMetaType::QJsonValue,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonValue,    2,
    QMetaType::Void, QMetaType::QJsonValue,    2,
    QMetaType::Void, QMetaType::QJsonValue,    2,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject loginw::staticMetaObject = { {
    QMetaObject::SuperData::link<QStackedWidget::staticMetaObject>(),
    qt_meta_stringdata_loginw.offsetsAndSizes,
    qt_meta_data_loginw,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_loginw_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<loginw, std::true_type>,
        // method 'rotateWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'closeWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'hideWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loginSuccess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openRegisterWnd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openForgetPasswordWnd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalRegisterOK'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>,
        // method 'signalForgetPwdReply'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>,
        // method 'changePage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showNotifyMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'hideNotifyMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sltTcpStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const quint8 &, std::false_type>,
        // method 'slotTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sltFileRecvFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint8, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'checkAutoLogin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sltRegister'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>,
        // method 'sltChangePwd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>,
        // method 'writeOffLineMsgToDatabase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>,
        // method 'sltGetOffLineMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void loginw::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<loginw *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->rotateWindow(); break;
        case 1: _t->closeWindow(); break;
        case 2: _t->hideWindow(); break;
        case 3: _t->loginSuccess(); break;
        case 4: _t->openRegisterWnd(); break;
        case 5: _t->openForgetPasswordWnd(); break;
        case 6: _t->signalRegisterOK((*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[1]))); break;
        case 7: _t->signalForgetPwdReply((*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[1]))); break;
        case 8: _t->changePage(); break;
        case 9: _t->showNotifyMsg((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->hideNotifyMsg(); break;
        case 11: _t->sltTcpStatus((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1]))); break;
        case 12: _t->slotTimeout(); break;
        case 13: _t->sltFileRecvFinished((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 14: _t->checkAutoLogin(); break;
        case 15: _t->sltRegister((*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[1]))); break;
        case 16: _t->sltChangePwd((*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[1]))); break;
        case 17: _t->writeOffLineMsgToDatabase((*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[1]))); break;
        case 18: _t->sltGetOffLineMsg(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (loginw::*)();
            if (_t _q_method = &loginw::rotateWindow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (loginw::*)();
            if (_t _q_method = &loginw::closeWindow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (loginw::*)();
            if (_t _q_method = &loginw::hideWindow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (loginw::*)();
            if (_t _q_method = &loginw::loginSuccess; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (loginw::*)();
            if (_t _q_method = &loginw::openRegisterWnd; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (loginw::*)();
            if (_t _q_method = &loginw::openForgetPasswordWnd; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (loginw::*)(const QJsonValue & );
            if (_t _q_method = &loginw::signalRegisterOK; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (loginw::*)(const QJsonValue & );
            if (_t _q_method = &loginw::signalForgetPwdReply; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject *loginw::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *loginw::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_loginw.stringdata0))
        return static_cast<void*>(this);
    return QStackedWidget::qt_metacast(_clname);
}

int loginw::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStackedWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void loginw::rotateWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void loginw::closeWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void loginw::hideWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void loginw::loginSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void loginw::openRegisterWnd()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void loginw::openForgetPasswordWnd()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void loginw::signalRegisterOK(const QJsonValue & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void loginw::signalForgetPwdReply(const QJsonValue & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
