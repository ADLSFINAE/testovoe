/****************************************************************************
** Meta object code from reading C++ file 'numbertoint32algorithm.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Desktop/testovoe/4-IntegerandBinaryValidatorVisualisation/FourProg/logicElems/numbertoint32algorithm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'numbertoint32algorithm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NumberToInt32Algorithm_t {
    const uint offsetsAndSize[8];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_NumberToInt32Algorithm_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_NumberToInt32Algorithm_t qt_meta_stringdata_NumberToInt32Algorithm = {
    {
QT_MOC_LITERAL(0, 22), // "NumberToInt32Algorithm"
QT_MOC_LITERAL(23, 12), // "signalGetAns"
QT_MOC_LITERAL(36, 0), // ""
QT_MOC_LITERAL(37, 10) // "slotGetAns"

    },
    "NumberToInt32Algorithm\0signalGetAns\0"
    "\0slotGetAns"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NumberToInt32Algorithm[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   27,    2, 0x08,    2 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void NumberToInt32Algorithm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NumberToInt32Algorithm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalGetAns(); break;
        case 1: _t->slotGetAns(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NumberToInt32Algorithm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NumberToInt32Algorithm::signalGetAns)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject NumberToInt32Algorithm::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_NumberToInt32Algorithm.offsetsAndSize,
    qt_meta_data_NumberToInt32Algorithm,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_NumberToInt32Algorithm_t
, QtPrivate::TypeAndForceComplete<NumberToInt32Algorithm, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *NumberToInt32Algorithm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NumberToInt32Algorithm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NumberToInt32Algorithm.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NumberToInt32Algorithm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void NumberToInt32Algorithm::signalGetAns()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
