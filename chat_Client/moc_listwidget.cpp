/****************************************************************************
** Meta object code from reading C++ file 'listwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "comapi/listwidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listwidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_ListWidget_t {
    uint offsetsAndSizes[32];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[7];
    char stringdata5[17];
    char stringdata6[4];
    char stringdata7[22];
    char stringdata8[17];
    char stringdata9[5];
    char stringdata10[17];
    char stringdata11[13];
    char stringdata12[4];
    char stringdata13[14];
    char stringdata14[19];
    char stringdata15[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ListWidget_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ListWidget_t qt_meta_stringdata_ListWidget = {
    {
        QT_MOC_LITERAL(0, 10),  // "ListWidget"
        QT_MOC_LITERAL(11, 13),  // "popMenuToShow"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 5),  // "Cell*"
        QT_MOC_LITERAL(32, 6),  // "QMenu*"
        QT_MOC_LITERAL(39, 16),  // "sonDoubleClicked"
        QT_MOC_LITERAL(56, 3),  // "son"
        QT_MOC_LITERAL(60, 21),  // "signalSonRightClicked"
        QT_MOC_LITERAL(82, 16),  // "signalOpenDialog"
        QT_MOC_LITERAL(99, 4),  // "cell"
        QT_MOC_LITERAL(104, 16),  // "onDadOpenChanged"
        QT_MOC_LITERAL(121, 12),  // "CellViewDad*"
        QT_MOC_LITERAL(134, 3),  // "dad"
        QT_MOC_LITERAL(138, 13),  // "onSonSelected"
        QT_MOC_LITERAL(152, 18),  // "onCellRightClicked"
        QT_MOC_LITERAL(171, 16)   // "slt_valueChanged"
    },
    "ListWidget",
    "popMenuToShow",
    "",
    "Cell*",
    "QMenu*",
    "sonDoubleClicked",
    "son",
    "signalSonRightClicked",
    "signalOpenDialog",
    "cell",
    "onDadOpenChanged",
    "CellViewDad*",
    "dad",
    "onSonSelected",
    "onCellRightClicked",
    "slt_valueChanged"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ListWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   62,    2, 0x06,    1 /* Public */,
       5,    1,   67,    2, 0x06,    4 /* Public */,
       7,    0,   70,    2, 0x06,    6 /* Public */,
       8,    1,   71,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    1,   74,    2, 0x0a,    9 /* Public */,
      13,    1,   77,    2, 0x0a,   11 /* Public */,
      14,    1,   80,    2, 0x0a,   13 /* Public */,
      15,    1,   83,    2, 0x0a,   15 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, 0x80000000 | 3,    9,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject ListWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QListWidget::staticMetaObject>(),
    qt_meta_stringdata_ListWidget.offsetsAndSizes,
    qt_meta_data_ListWidget,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ListWidget_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ListWidget, std::true_type>,
        // method 'popMenuToShow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Cell *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMenu *, std::false_type>,
        // method 'sonDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Cell *, std::false_type>,
        // method 'signalSonRightClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalOpenDialog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Cell *, std::false_type>,
        // method 'onDadOpenChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<CellViewDad *, std::false_type>,
        // method 'onSonSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Cell *, std::false_type>,
        // method 'onCellRightClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Cell *, std::false_type>,
        // method 'slt_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void ListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ListWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->popMenuToShow((*reinterpret_cast< std::add_pointer_t<Cell*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QMenu*>>(_a[2]))); break;
        case 1: _t->sonDoubleClicked((*reinterpret_cast< std::add_pointer_t<Cell*>>(_a[1]))); break;
        case 2: _t->signalSonRightClicked(); break;
        case 3: _t->signalOpenDialog((*reinterpret_cast< std::add_pointer_t<Cell*>>(_a[1]))); break;
        case 4: _t->onDadOpenChanged((*reinterpret_cast< std::add_pointer_t<CellViewDad*>>(_a[1]))); break;
        case 5: _t->onSonSelected((*reinterpret_cast< std::add_pointer_t<Cell*>>(_a[1]))); break;
        case 6: _t->onCellRightClicked((*reinterpret_cast< std::add_pointer_t<Cell*>>(_a[1]))); break;
        case 7: _t->slt_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QMenu* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< CellViewDad* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ListWidget::*)(Cell * , QMenu * );
            if (_t _q_method = &ListWidget::popMenuToShow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ListWidget::*)(Cell * );
            if (_t _q_method = &ListWidget::sonDoubleClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ListWidget::*)();
            if (_t _q_method = &ListWidget::signalSonRightClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ListWidget::*)(Cell * );
            if (_t _q_method = &ListWidget::signalOpenDialog; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *ListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ListWidget.stringdata0))
        return static_cast<void*>(this);
    return QListWidget::qt_metacast(_clname);
}

int ListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
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
void ListWidget::popMenuToShow(Cell * _t1, QMenu * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ListWidget::sonDoubleClicked(Cell * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ListWidget::signalSonRightClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ListWidget::signalOpenDialog(Cell * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
namespace {
struct qt_meta_stringdata_FloatingScrollBar_t {
    uint offsetsAndSizes[8];
    char stringdata0[18];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_FloatingScrollBar_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_FloatingScrollBar_t qt_meta_stringdata_FloatingScrollBar = {
    {
        QT_MOC_LITERAL(0, 17),  // "FloatingScrollBar"
        QT_MOC_LITERAL(18, 16),  // "slt_valueChanged"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 16)   // "slt_rangeChanged"
    },
    "FloatingScrollBar",
    "slt_valueChanged",
    "",
    "slt_rangeChanged"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_FloatingScrollBar[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x0a,    1 /* Public */,
       3,    2,   29,    2, 0x0a,    3 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject FloatingScrollBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QScrollBar::staticMetaObject>(),
    qt_meta_stringdata_FloatingScrollBar.offsetsAndSizes,
    qt_meta_data_FloatingScrollBar,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_FloatingScrollBar_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<FloatingScrollBar, std::true_type>,
        // method 'slt_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slt_rangeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void FloatingScrollBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FloatingScrollBar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slt_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->slt_rangeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject *FloatingScrollBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FloatingScrollBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FloatingScrollBar.stringdata0))
        return static_cast<void*>(this);
    return QScrollBar::qt_metacast(_clname);
}

int FloatingScrollBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
