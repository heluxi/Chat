/****************************************************************************
** Meta object code from reading C++ file 'contactwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "midw/contactwidget.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contactwidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_ContactWidget_t {
    uint offsetsAndSizes[32];
    char stringdata0[14];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[6];
    char stringdata5[11];
    char stringdata6[3];
    char stringdata7[24];
    char stringdata8[9];
    char stringdata9[23];
    char stringdata10[18];
    char stringdata11[19];
    char stringdata12[13];
    char stringdata13[15];
    char stringdata14[7];
    char stringdata15[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ContactWidget_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ContactWidget_t qt_meta_stringdata_ContactWidget = {
    {
        QT_MOC_LITERAL(0, 13),  // "ContactWidget"
        QT_MOC_LITERAL(14, 17),  // "signalSendMessage"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 10),  // "openDialog"
        QT_MOC_LITERAL(44, 5),  // "Cell*"
        QT_MOC_LITERAL(50, 10),  // "deleteChat"
        QT_MOC_LITERAL(61, 2),  // "id"
        QT_MOC_LITERAL(64, 23),  // "onFriendDadMenuSelected"
        QT_MOC_LITERAL(88, 8),  // "QAction*"
        QT_MOC_LITERAL(97, 22),  // "onGroupDadMenuSelected"
        QT_MOC_LITERAL(120, 17),  // "onSonMenuSelected"
        QT_MOC_LITERAL(138, 18),  // "onSonDoubleClicked"
        QT_MOC_LITERAL(157, 12),  // "onSwitchPage"
        QT_MOC_LITERAL(170, 14),  // "setPopMenuCell"
        QT_MOC_LITERAL(185, 6),  // "QMenu*"
        QT_MOC_LITERAL(192, 19)   // "sltUpdateFriendList"
    },
    "ContactWidget",
    "signalSendMessage",
    "",
    "openDialog",
    "Cell*",
    "deleteChat",
    "id",
    "onFriendDadMenuSelected",
    "QAction*",
    "onGroupDadMenuSelected",
    "onSonMenuSelected",
    "onSonDoubleClicked",
    "onSwitchPage",
    "setPopMenuCell",
    "QMenu*",
    "sltUpdateFriendList"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ContactWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   74,    2, 0x06,    1 /* Public */,
       3,    1,   79,    2, 0x06,    4 /* Public */,
       5,    1,   82,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,   85,    2, 0x0a,    8 /* Public */,
       9,    1,   88,    2, 0x0a,   10 /* Public */,
      10,    1,   91,    2, 0x0a,   12 /* Public */,
      11,    1,   94,    2, 0x0a,   14 /* Public */,
      12,    1,   97,    2, 0x0a,   16 /* Public */,
      13,    2,  100,    2, 0x0a,   18 /* Public */,
      15,    1,  105,    2, 0x0a,   21 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::QJsonValue,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 14,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject ContactWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ContactWidget.offsetsAndSizes,
    qt_meta_data_ContactWidget,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ContactWidget_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ContactWidget, std::true_type>,
        // method 'signalSendMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const quint8 &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonValue &, std::false_type>,
        // method 'openDialog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Cell *, std::false_type>,
        // method 'deleteChat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onFriendDadMenuSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAction *, std::false_type>,
        // method 'onGroupDadMenuSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAction *, std::false_type>,
        // method 'onSonMenuSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAction *, std::false_type>,
        // method 'onSonDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Cell *, std::false_type>,
        // method 'onSwitchPage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setPopMenuCell'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Cell *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMenu *, std::false_type>,
        // method 'sltUpdateFriendList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void ContactWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ContactWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalSendMessage((*reinterpret_cast< std::add_pointer_t<quint8>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonValue>>(_a[2]))); break;
        case 1: _t->openDialog((*reinterpret_cast< std::add_pointer_t<Cell*>>(_a[1]))); break;
        case 2: _t->deleteChat((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->onFriendDadMenuSelected((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 4: _t->onGroupDadMenuSelected((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 5: _t->onSonMenuSelected((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 6: _t->onSonDoubleClicked((*reinterpret_cast< std::add_pointer_t<Cell*>>(_a[1]))); break;
        case 7: _t->onSwitchPage((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->setPopMenuCell((*reinterpret_cast< std::add_pointer_t<Cell*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QMenu*>>(_a[2]))); break;
        case 9: _t->sltUpdateFriendList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ContactWidget::*)(const quint8 & , const QJsonValue & );
            if (_t _q_method = &ContactWidget::signalSendMessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ContactWidget::*)(Cell * );
            if (_t _q_method = &ContactWidget::openDialog; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ContactWidget::*)(int );
            if (_t _q_method = &ContactWidget::deleteChat; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *ContactWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ContactWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ContactWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ContactWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ContactWidget::signalSendMessage(const quint8 & _t1, const QJsonValue & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ContactWidget::openDialog(Cell * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ContactWidget::deleteChat(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
