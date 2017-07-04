/****************************************************************************
** Meta object code from reading C++ file 'agdiagramcontroler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "agdiagramcontroler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'agdiagramcontroler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AgDiagramControler_t {
    QByteArrayData data[11];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AgDiagramControler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AgDiagramControler_t qt_meta_stringdata_AgDiagramControler = {
    {
QT_MOC_LITERAL(0, 0, 18), // "AgDiagramControler"
QT_MOC_LITERAL(1, 19, 8), // "onDelete"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "setResized"
QT_MOC_LITERAL(4, 40, 5), // "value"
QT_MOC_LITERAL(5, 46, 10), // "setChanged"
QT_MOC_LITERAL(6, 57, 11), // "setNotation"
QT_MOC_LITERAL(7, 69, 27), // "AgDiagramNotation::Notation"
QT_MOC_LITERAL(8, 97, 8), // "notation"
QT_MOC_LITERAL(9, 106, 10), // "setDeleted"
QT_MOC_LITERAL(10, 117, 2) // "id"

    },
    "AgDiagramControler\0onDelete\0\0setResized\0"
    "value\0setChanged\0setNotation\0"
    "AgDiagramNotation::Notation\0notation\0"
    "setDeleted\0id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AgDiagramControler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   42,    2, 0x0a /* Public */,
       5,    0,   45,    2, 0x0a /* Public */,
       6,    1,   46,    2, 0x0a /* Public */,
       9,    1,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void AgDiagramControler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AgDiagramControler *_t = static_cast<AgDiagramControler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onDelete((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setResized((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setChanged(); break;
        case 3: _t->setNotation((*reinterpret_cast< AgDiagramNotation::Notation(*)>(_a[1]))); break;
        case 4: _t->setDeleted((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AgDiagramControler::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AgDiagramControler::onDelete)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject AgDiagramControler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AgDiagramControler.data,
      qt_meta_data_AgDiagramControler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AgDiagramControler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AgDiagramControler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AgDiagramControler.stringdata0))
        return static_cast<void*>(const_cast< AgDiagramControler*>(this));
    return QObject::qt_metacast(_clname);
}

int AgDiagramControler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void AgDiagramControler::onDelete(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
