/****************************************************************************
** Meta object code from reading C++ file 'generaladapter.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Desktop/testovoe/2-MySimpleWordVisualisation/SecondProg/generaladapter.h"
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
    const uint offsetsAndSize[34];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_GeneralAdapter_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_GeneralAdapter_t qt_meta_stringdata_GeneralAdapter = {
    {
QT_MOC_LITERAL(0, 14), // "GeneralAdapter"
QT_MOC_LITERAL(15, 25), // "signalToRedrawTableWidget"
QT_MOC_LITERAL(41, 0), // ""
QT_MOC_LITERAL(42, 13), // "QMap<int,int>"
QT_MOC_LITERAL(56, 5), // "stats"
QT_MOC_LITERAL(62, 13), // "signalSetBold"
QT_MOC_LITERAL(76, 4), // "bold"
QT_MOC_LITERAL(81, 16), // "signalSetCursive"
QT_MOC_LITERAL(98, 7), // "cursive"
QT_MOC_LITERAL(106, 17), // "slotToCallSetBold"
QT_MOC_LITERAL(124, 20), // "slotToCallSetCursive"
QT_MOC_LITERAL(145, 21), // "slotCreateTableWidget"
QT_MOC_LITERAL(167, 31), // "slotForCallBackToStartAlgorithm"
QT_MOC_LITERAL(199, 26), // "slotSetTextFromLoadTxtFile"
QT_MOC_LITERAL(226, 4), // "text"
QT_MOC_LITERAL(231, 27), // "slotSetTextForSaveInTxtFile"
QT_MOC_LITERAL(259, 25) // "slotCleanTextEditFromText"

    },
    "GeneralAdapter\0signalToRedrawTableWidget\0"
    "\0QMap<int,int>\0stats\0signalSetBold\0"
    "bold\0signalSetCursive\0cursive\0"
    "slotToCallSetBold\0slotToCallSetCursive\0"
    "slotCreateTableWidget\0"
    "slotForCallBackToStartAlgorithm\0"
    "slotSetTextFromLoadTxtFile\0text\0"
    "slotSetTextForSaveInTxtFile\0"
    "slotCleanTextEditFromText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeneralAdapter[] = {

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
       1,    1,   74,    2, 0x06,    1 /* Public */,
       5,    1,   77,    2, 0x06,    3 /* Public */,
       7,    1,   80,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   83,    2, 0x0a,    7 /* Public */,
      10,    0,   84,    2, 0x0a,    8 /* Public */,
      11,    0,   85,    2, 0x0a,    9 /* Public */,
      12,    0,   86,    2, 0x0a,   10 /* Public */,
      13,    1,   87,    2, 0x0a,   11 /* Public */,
      15,    0,   90,    2, 0x0a,   13 /* Public */,
      16,    0,   91,    2, 0x0a,   14 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GeneralAdapter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GeneralAdapter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalToRedrawTableWidget((*reinterpret_cast< std::add_pointer_t<QMap<int,int>>>(_a[1]))); break;
        case 1: _t->signalSetBold((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->signalSetCursive((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->slotToCallSetBold(); break;
        case 4: _t->slotToCallSetCursive(); break;
        case 5: _t->slotCreateTableWidget(); break;
        case 6: _t->slotForCallBackToStartAlgorithm(); break;
        case 7: _t->slotSetTextFromLoadTxtFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->slotSetTextForSaveInTxtFile(); break;
        case 9: _t->slotCleanTextEditFromText(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GeneralAdapter::*)(QMap<int,int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GeneralAdapter::signalToRedrawTableWidget)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GeneralAdapter::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GeneralAdapter::signalSetBold)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GeneralAdapter::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GeneralAdapter::signalSetCursive)) {
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
, QtPrivate::TypeAndForceComplete<GeneralAdapter, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMap<int,int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void GeneralAdapter::signalToRedrawTableWidget(QMap<int,int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GeneralAdapter::signalSetBold(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GeneralAdapter::signalSetCursive(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
