/****************************************************************************
** Meta object code from reading C++ file 'rotatingstackedwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "login/rotatingstackedwidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rotatingstackedwidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_RotatingStackedWidget_t {
    uint offsetsAndSizes[20];
    char stringdata0[22];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[13];
    char stringdata5[13];
    char stringdata6[19];
    char stringdata7[25];
    char stringdata8[20];
    char stringdata9[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_RotatingStackedWidget_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_RotatingStackedWidget_t qt_meta_stringdata_RotatingStackedWidget = {
    {
        QT_MOC_LITERAL(0, 21),  // "RotatingStackedWidget"
        QT_MOC_LITERAL(22, 14),  // "onRotateWindow"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 16),  // "onRotateFinished"
        QT_MOC_LITERAL(55, 12),  // "onHideWindow"
        QT_MOC_LITERAL(68, 12),  // "sltAutoLogin"
        QT_MOC_LITERAL(81, 18),  // "sltOpenRegisterWnd"
        QT_MOC_LITERAL(100, 24),  // "sltOpenForgetPasswordWnd"
        QT_MOC_LITERAL(125, 19),  // "sltCloseRegisterWnd"
        QT_MOC_LITERAL(145, 19)   // "sltCloseFindwordWnd"
    },
    "RotatingStackedWidget",
    "onRotateWindow",
    "",
    "onRotateFinished",
    "onHideWindow",
    "sltAutoLogin",
    "sltOpenRegisterWnd",
    "sltOpenForgetPasswordWnd",
    "sltCloseRegisterWnd",
    "sltCloseFindwordWnd"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_RotatingStackedWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x0a,    1 /* Public */,
       3,    0,   63,    2, 0x0a,    2 /* Public */,
       4,    0,   64,    2, 0x0a,    3 /* Public */,
       5,    0,   65,    2, 0x0a,    4 /* Public */,
       6,    0,   66,    2, 0x0a,    5 /* Public */,
       7,    0,   67,    2, 0x0a,    6 /* Public */,
       8,    1,   68,    2, 0x0a,    7 /* Public */,
       9,    1,   71,    2, 0x0a,    9 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QPoint,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject RotatingStackedWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QStackedWidget::staticMetaObject>(),
    qt_meta_stringdata_RotatingStackedWidget.offsetsAndSizes,
    qt_meta_data_RotatingStackedWidget,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_RotatingStackedWidget_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RotatingStackedWidget, std::true_type>,
        // method 'onRotateWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRotateFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onHideWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sltAutoLogin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sltOpenRegisterWnd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sltOpenForgetPasswordWnd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sltCloseRegisterWnd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        // method 'sltCloseFindwordWnd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>
    >,
    nullptr
} };

void RotatingStackedWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RotatingStackedWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onRotateWindow(); break;
        case 1: _t->onRotateFinished(); break;
        case 2: _t->onHideWindow(); break;
        case 3: _t->sltAutoLogin(); break;
        case 4: _t->sltOpenRegisterWnd(); break;
        case 5: _t->sltOpenForgetPasswordWnd(); break;
        case 6: _t->sltCloseRegisterWnd((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 7: _t->sltCloseFindwordWnd((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *RotatingStackedWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RotatingStackedWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RotatingStackedWidget.stringdata0))
        return static_cast<void*>(this);
    return QStackedWidget::qt_metacast(_clname);
}

int RotatingStackedWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStackedWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
