/****************************************************************************
** Meta object code from reading C++ file 'page_login_logining.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "login/page_login_logining.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'page_login_logining.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_Page_Login_Logining_t {
    uint offsetsAndSizes[22];
    char stringdata0[20];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[11];
    char stringdata5[18];
    char stringdata6[13];
    char stringdata7[11];
    char stringdata8[13];
    char stringdata9[11];
    char stringdata10[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Page_Login_Logining_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Page_Login_Logining_t qt_meta_stringdata_Page_Login_Logining = {
    {
        QT_MOC_LITERAL(0, 19),  // "Page_Login_Logining"
        QT_MOC_LITERAL(20, 12),  // "cancelSignal"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 11),  // "closeWindow"
        QT_MOC_LITERAL(46, 10),  // "hideWindow"
        QT_MOC_LITERAL(57, 17),  // "animationFinished"
        QT_MOC_LITERAL(75, 12),  // "changePoints"
        QT_MOC_LITERAL(88, 10),  // "showMainUI"
        QT_MOC_LITERAL(99, 12),  // "loginSuccess"
        QT_MOC_LITERAL(112, 10),  // "updateHead"
        QT_MOC_LITERAL(123, 21)   // "on_btn_cancel_clicked"
    },
    "Page_Login_Logining",
    "cancelSignal",
    "",
    "closeWindow",
    "hideWindow",
    "animationFinished",
    "changePoints",
    "showMainUI",
    "loginSuccess",
    "updateHead",
    "on_btn_cancel_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Page_Login_Logining[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    1 /* Public */,
       3,    0,   69,    2, 0x06,    2 /* Public */,
       4,    0,   70,    2, 0x06,    3 /* Public */,
       5,    0,   71,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   72,    2, 0x0a,    5 /* Public */,
       7,    0,   73,    2, 0x0a,    6 /* Public */,
       8,    0,   74,    2, 0x0a,    7 /* Public */,
       9,    0,   75,    2, 0x0a,    8 /* Public */,
      10,    1,   76,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject Page_Login_Logining::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Page_Login_Logining.offsetsAndSizes,
    qt_meta_data_Page_Login_Logining,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Page_Login_Logining_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Page_Login_Logining, std::true_type>,
        // method 'cancelSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'closeWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'hideWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'animationFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changePoints'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showMainUI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loginSuccess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateHead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_cancel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void Page_Login_Logining::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Page_Login_Logining *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->cancelSignal(); break;
        case 1: _t->closeWindow(); break;
        case 2: _t->hideWindow(); break;
        case 3: _t->animationFinished(); break;
        case 4: _t->changePoints(); break;
        case 5: _t->showMainUI(); break;
        case 6: _t->loginSuccess(); break;
        case 7: _t->updateHead(); break;
        case 8: _t->on_btn_cancel_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Page_Login_Logining::*)();
            if (_t _q_method = &Page_Login_Logining::cancelSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Page_Login_Logining::*)();
            if (_t _q_method = &Page_Login_Logining::closeWindow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Page_Login_Logining::*)();
            if (_t _q_method = &Page_Login_Logining::hideWindow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Page_Login_Logining::*)();
            if (_t _q_method = &Page_Login_Logining::animationFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *Page_Login_Logining::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Page_Login_Logining::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Page_Login_Logining.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Page_Login_Logining::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Page_Login_Logining::cancelSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Page_Login_Logining::closeWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Page_Login_Logining::hideWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Page_Login_Logining::animationFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
