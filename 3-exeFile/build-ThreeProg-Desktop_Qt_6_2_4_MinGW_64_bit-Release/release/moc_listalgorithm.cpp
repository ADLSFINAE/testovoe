/****************************************************************************
** Meta object code from reading C++ file 'listalgorithm.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Desktop/testovoe/3-List5ElemDeleterVisualisation/ThreeProg/logicElems/listalgorithm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listalgorithm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ListAlgorithm_t {
    const uint offsetsAndSize[12];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ListAlgorithm_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ListAlgorithm_t qt_meta_stringdata_ListAlgorithm = {
    {
QT_MOC_LITERAL(0, 13), // "ListAlgorithm"
QT_MOC_LITERAL(14, 19), // "signalToRedrawItems"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 5), // "List*"
QT_MOC_LITERAL(41, 4), // "head"
QT_MOC_LITERAL(46, 16) // "deleteEveryFifth"

    },
    "ListAlgorithm\0signalToRedrawItems\0\0"
    "List*\0head\0deleteEveryFifth"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ListAlgorithm[] = {

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
       1,    1,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   29,    2, 0x0a,    3 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void ListAlgorithm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ListAlgorithm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalToRedrawItems((*reinterpret_cast< std::add_pointer_t<List*>>(_a[1]))); break;
        case 1: _t->deleteEveryFifth((*reinterpret_cast< std::add_pointer_t<List*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ListAlgorithm::*)(List * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ListAlgorithm::signalToRedrawItems)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ListAlgorithm::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ListAlgorithm.offsetsAndSize,
    qt_meta_data_ListAlgorithm,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ListAlgorithm_t
, QtPrivate::TypeAndForceComplete<ListAlgorithm, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<List *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<List *, std::false_type>


>,
    nullptr
} };


const QMetaObject *ListAlgorithm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListAlgorithm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ListAlgorithm.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ListAlgorithm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ListAlgorithm::signalToRedrawItems(List * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
