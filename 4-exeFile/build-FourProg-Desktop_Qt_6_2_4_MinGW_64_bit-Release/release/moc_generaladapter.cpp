/****************************************************************************
** Meta object code from reading C++ file 'generaladapter.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Desktop/testovoe/4-IntegerandBinaryValidatorVisualisation/FourProg/generaladapter.h"
#include <QtGui/qtextcursor.h>
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
    const uint offsetsAndSize[14];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_GeneralAdapter_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_GeneralAdapter_t qt_meta_stringdata_GeneralAdapter = {
    {
QT_MOC_LITERAL(0, 14), // "GeneralAdapter"
QT_MOC_LITERAL(15, 12), // "signalLabel1"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 15), // "numberFromInput"
QT_MOC_LITERAL(45, 12), // "signalLabel2"
QT_MOC_LITERAL(58, 12), // "signalLabel3"
QT_MOC_LITERAL(71, 22) // "slotGetNumberFromInput"

    },
    "GeneralAdapter\0signalLabel1\0\0"
    "numberFromInput\0signalLabel2\0signalLabel3\0"
    "slotGetNumberFromInput"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeneralAdapter[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,
       4,    1,   41,    2, 0x06,    3 /* Public */,
       5,    1,   44,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   47,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    3,

       0        // eod
};

void GeneralAdapter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GeneralAdapter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalLabel1((*reinterpret_cast< std::add_pointer_t<quint32>>(_a[1]))); break;
        case 1: _t->signalLabel2((*reinterpret_cast< std::add_pointer_t<quint32>>(_a[1]))); break;
        case 2: _t->signalLabel3((*reinterpret_cast< std::add_pointer_t<quint32>>(_a[1]))); break;
        case 3: _t->slotGetNumberFromInput((*reinterpret_cast< std::add_pointer_t<quint32>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GeneralAdapter::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GeneralAdapter::signalLabel1)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GeneralAdapter::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GeneralAdapter::signalLabel2)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GeneralAdapter::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GeneralAdapter::signalLabel3)) {
                *result = 2;
                return;
            }
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
, QtPrivate::TypeAndForceComplete<GeneralAdapter, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint32, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint32, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint32, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint32, std::false_type>


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
void GeneralAdapter::signalLabel1(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GeneralAdapter::signalLabel2(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GeneralAdapter::signalLabel3(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
