/****************************************************************************
** Meta object code from reading C++ file 'agdiagramscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "agdiagramscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'agdiagramscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AgDiagramScene_t {
    QByteArrayData data[17];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AgDiagramScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AgDiagramScene_t qt_meta_stringdata_AgDiagramScene = {
    {
QT_MOC_LITERAL(0, 0, 14), // "AgDiagramScene"
QT_MOC_LITERAL(1, 15, 12), // "itemInserted"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 14), // "AgDiagramItem*"
QT_MOC_LITERAL(4, 44, 4), // "item"
QT_MOC_LITERAL(5, 49, 12), // "textInserted"
QT_MOC_LITERAL(6, 62, 18), // "QGraphicsTextItem*"
QT_MOC_LITERAL(7, 81, 12), // "itemSelected"
QT_MOC_LITERAL(8, 94, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(9, 109, 12), // "mouseClicked"
QT_MOC_LITERAL(10, 122, 5), // "point"
QT_MOC_LITERAL(11, 128, 15), // "notationChanged"
QT_MOC_LITERAL(12, 144, 27), // "AgDiagramNotation::Notation"
QT_MOC_LITERAL(13, 172, 8), // "notation"
QT_MOC_LITERAL(14, 181, 7), // "setMode"
QT_MOC_LITERAL(15, 189, 4), // "Mode"
QT_MOC_LITERAL(16, 194, 4) // "mode"

    },
    "AgDiagramScene\0itemInserted\0\0"
    "AgDiagramItem*\0item\0textInserted\0"
    "QGraphicsTextItem*\0itemSelected\0"
    "QGraphicsItem*\0mouseClicked\0point\0"
    "notationChanged\0AgDiagramNotation::Notation\0"
    "notation\0setMode\0Mode\0mode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AgDiagramScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,
       7,    1,   50,    2, 0x06 /* Public */,
       9,    1,   53,    2, 0x06 /* Public */,
      11,    1,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, 0x80000000 | 8,    4,
    QMetaType::Void, QMetaType::QPointF,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void AgDiagramScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AgDiagramScene *_t = static_cast<AgDiagramScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->itemInserted((*reinterpret_cast< AgDiagramItem*(*)>(_a[1]))); break;
        case 1: _t->textInserted((*reinterpret_cast< QGraphicsTextItem*(*)>(_a[1]))); break;
        case 2: _t->itemSelected((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 3: _t->mouseClicked((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 4: _t->notationChanged((*reinterpret_cast< AgDiagramNotation::Notation(*)>(_a[1]))); break;
        case 5: _t->setMode((*reinterpret_cast< Mode(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsTextItem* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AgDiagramScene::*_t)(AgDiagramItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AgDiagramScene::itemInserted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AgDiagramScene::*_t)(QGraphicsTextItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AgDiagramScene::textInserted)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AgDiagramScene::*_t)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AgDiagramScene::itemSelected)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (AgDiagramScene::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AgDiagramScene::mouseClicked)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (AgDiagramScene::*_t)(AgDiagramNotation::Notation );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AgDiagramScene::notationChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject AgDiagramScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_AgDiagramScene.data,
      qt_meta_data_AgDiagramScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AgDiagramScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AgDiagramScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AgDiagramScene.stringdata0))
        return static_cast<void*>(const_cast< AgDiagramScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int AgDiagramScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void AgDiagramScene::itemInserted(AgDiagramItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AgDiagramScene::textInserted(QGraphicsTextItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AgDiagramScene::itemSelected(QGraphicsItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AgDiagramScene::mouseClicked(QPointF _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AgDiagramScene::notationChanged(AgDiagramNotation::Notation _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
