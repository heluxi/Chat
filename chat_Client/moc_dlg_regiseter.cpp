/****************************************************************************
** Meta object code from reading C++ file 'dlg_regiseter.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "login/dlg_regiseter.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlg_regiseter.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_Dlg_regiseter_t {
    uint offsetsAndSizes[26];
    char stringdata0[14];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[9];
    char stringdata5[11];
    char stringdata6[15];
    char stringdata7[8];
    char stringdata8[16];
    char stringdata9[14];
    char stringdata10[29];
    char stringdata11[26];
    char stringdata12[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Dlg_regiseter_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Dlg_regiseter_t qt_meta_stringdata_Dlg_regiseter = {
    {
        QT_MOC_LITERAL(0, 13),  // "Dlg_regiseter"
        QT_MOC_LITERAL(14, 12),  // "userRegister"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 4),  // "name"
        QT_MOC_LITERAL(33, 8),  // "password"
        QT_MOC_LITERAL(42, 10),  // "registerok"
        QT_MOC_LITERAL(53, 14),  // "signalRegister"
        QT_MOC_LITERAL(68, 7),  // "jsonVal"
        QT_MOC_LITERAL(76, 15),  // "returnPageLogin"
        QT_MOC_LITERAL(92, 13),  // "registSuccess"
        QT_MOC_LITERAL(106, 28),  // "on_btn_register_sure_clicked"
        QT_MOC_LITERAL(135, 25),  // "on_btn_reg_cancel_clicked"
        QT_MOC_LITERAL(161, 13)   // "sltRegisterOK"
    },
    "Dlg_regiseter",
    "userRegister",
    "",
    "name",
    "password",
    "registerok",
    "signalRegister",
    "jsonVal",
    "returnPageLogin",
    "registSuccess",
    "on_btn_register_sure_clicked",
    "on_btn_reg_cancel_clicked",
    "sltRegisterOK"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Dlg_regiseter[] = {

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
       1,    2,   62,    2, 0x06,    1 /* Public */,
       5,    0,   67,    2, 0x06,    4 /* Public */,
       6,    1,   68,    2, 0x06,    5 /* Public */,
       8,    0,   71,    2, 0x06,    7 /* Public */,
       9,    0,   72,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,   73,    2, 0x08,    9 /* Private */,
      11,    0,   74,    2, 0x08,   10 /* Private */,
      12,    1,   75,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonValue,    7,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonValue,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject Dlg_regiseter::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Dlg_regiseter.offsetsAndSizes,
    qt_meta_data_Dlg_regiseter,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Dlg_regiseter_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Dlg_regiseter, std::true_type>,
        // method 'userRegister'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'registerok'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalRegister'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>,
        // method 'returnPageLogin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'registSuccess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_register_sure_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_reg_cancel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sltRegisterOK'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>
    >,
    nullptr
} };

void Dlg_regiseter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dlg_regiseter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->userRegister((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->registerok(); break;
        case 2: _t->signalRegister((*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[1]))); break;
        case 3: _t->returnPageLogin(); break;
        case 4: _t->registSuccess(); break;
        case 5: _t->on_btn_register_sure_clicked(); break;
        case 6: _t->on_btn_reg_cancel_clicked(); break;
        case 7: _t->sltRegisterOK((*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Dlg_regiseter::*)(QString , QString );
            if (_t _q_method = &Dlg_regiseter::userRegister; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Dlg_regiseter::*)();
            if (_t _q_method = &Dlg_regiseter::registerok; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Dlg_regiseter::*)(const QJsonValue & );
            if (_t _q_method = &Dlg_regiseter::signalRegister; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Dlg_regiseter::*)();
            if (_t _q_method = &Dlg_regiseter::returnPageLogin; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Dlg_regiseter::*)();
            if (_t _q_method = &Dlg_regiseter::registSuccess; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *Dlg_regiseter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dlg_regiseter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dlg_regiseter.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dlg_regiseter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Dlg_regiseter::userRegister(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dlg_regiseter::registerok()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Dlg_regiseter::signalRegister(const QJsonValue & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Dlg_regiseter::returnPageLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Dlg_regiseter::registSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
