/****************************************************************************
** Meta object code from reading C++ file 'generaladapter.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Desktop/testovoe/3-List5ElemDeleterVisualisation/ThreeProg/generaladapter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'generaladapter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GeneralAdapter_t {
    const uint offsetsAndSize[12];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_GeneralAdapter_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_GeneralAdapter_t qt_meta_stringdata_GeneralAdapter = {
    {
QT_MOC_LITERAL(0, 14), // "GeneralAdapter"
QT_MOC_LITERAL(15, 11), // "getListHead"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 5), // "List*"
QT_MOC_LITERAL(34, 4), // "head"
QT_MOC_LITERAL(39, 20) // "setNumberOfListElems"

    },
    "GeneralAdapter\0getListHead\0\0List*\0"
    "head\0setNumberOfListElems"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeneralAdapter[] = {

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
       5,    0,   29,    2, 0x0a,    3 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void GeneralAdapter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GeneralAdapter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->getListHead((*reinterpret_cast< std::add_pointer_t<List*>>(_a[1]))); break;
        case 1: _t->setNumberOfListElems(); break;
        default: ;
        }
    }
}

const QMetaObject GeneralAdapter::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_GeneralAdapter.offsetsAndSize,
    qt_meta_data_GeneralAdapter,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_GeneralAdapter_t
, QtPrivate::TypeAndForceComplete<GeneralAdapter, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<List *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *GeneralAdapter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeneralAdapter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GeneralAdapter.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GeneralAdapter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
