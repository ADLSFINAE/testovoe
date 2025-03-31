/****************************************************************************
** Meta object code from reading C++ file 'generalwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Desktop/testovoe/4-IntegerandBinaryValidatorVisualisation/FourProg/widgetElems/generalwidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'generalwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GeneralWidget_t {
    const uint offsetsAndSize[12];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_GeneralWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_GeneralWidget_t qt_meta_stringdata_GeneralWidget = {
    {
QT_MOC_LITERAL(0, 13), // "GeneralWidget"
QT_MOC_LITERAL(14, 24), // "slotSetNumberLabelValues"
QT_MOC_LITERAL(39, 0), // ""
QT_MOC_LITERAL(40, 6), // "number"
QT_MOC_LITERAL(47, 21), // "slotSetNumberLabelMin"
QT_MOC_LITERAL(69, 21) // "slotSetNumberLabelMax"

    },
    "GeneralWidget\0slotSetNumberLabelValues\0"
    "\0number\0slotSetNumberLabelMin\0"
    "slotSetNumberLabelMax"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeneralWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x0a,    1 /* Public */,
       4,    1,   35,    2, 0x0a,    3 /* Public */,
       5,    1,   38,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt,    3,

       0        // eod
};

void GeneralWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GeneralWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotSetNumberLabelValues((*reinterpret_cast< std::add_pointer_t<quint32>>(_a[1]))); break;
        case 1: _t->slotSetNumberLabelMin((*reinterpret_cast< std::add_pointer_t<quint32>>(_a[1]))); break;
        case 2: _t->slotSetNumberLabelMax((*reinterpret_cast< std::add_pointer_t<quint32>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GeneralWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GeneralWidget.offsetsAndSize,
    qt_meta_data_GeneralWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_GeneralWidget_t
, QtPrivate::TypeAndForceComplete<GeneralWidget, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint32, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint32, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint32, std::false_type>


>,
    nullptr
} };


const QMetaObject *GeneralWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeneralWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GeneralWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GeneralWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
