/****************************************************************************
** Meta object code from reading C++ file 'panelwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Desktop/testovoe/2-MySimpleWordVisualisation/SecondProg/widgetElems/panelwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'panelwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PanelWidget_t {
    const uint offsetsAndSize[18];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PanelWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PanelWidget_t qt_meta_stringdata_PanelWidget = {
    {
QT_MOC_LITERAL(0, 11), // "PanelWidget"
QT_MOC_LITERAL(12, 24), // "signalTextLoadToTextEdit"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 4), // "text"
QT_MOC_LITERAL(43, 27), // "signalToGetTextFromTextEdit"
QT_MOC_LITERAL(71, 19), // "signalCleanTextEdit"
QT_MOC_LITERAL(91, 22), // "slotOpenExplorerToLoad"
QT_MOC_LITERAL(114, 22), // "slotOpenExplorerToSave"
QT_MOC_LITERAL(137, 17) // "slotCleanTextEdit"

    },
    "PanelWidget\0signalTextLoadToTextEdit\0"
    "\0text\0signalToGetTextFromTextEdit\0"
    "signalCleanTextEdit\0slotOpenExplorerToLoad\0"
    "slotOpenExplorerToSave\0slotCleanTextEdit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PanelWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       4,    0,   53,    2, 0x06,    3 /* Public */,
       5,    0,   54,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   55,    2, 0x0a,    5 /* Public */,
       7,    0,   56,    2, 0x0a,    6 /* Public */,
       8,    0,   57,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PanelWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PanelWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalTextLoadToTextEdit((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->signalToGetTextFromTextEdit(); break;
        case 2: _t->signalCleanTextEdit(); break;
        case 3: _t->slotOpenExplorerToLoad(); break;
        case 4: _t->slotOpenExplorerToSave(); break;
        case 5: _t->slotCleanTextEdit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PanelWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PanelWidget::signalTextLoadToTextEdit)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PanelWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PanelWidget::signalToGetTextFromTextEdit)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PanelWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PanelWidget::signalCleanTextEdit)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject PanelWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PanelWidget.offsetsAndSize,
    qt_meta_data_PanelWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PanelWidget_t
, QtPrivate::TypeAndForceComplete<PanelWidget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *PanelWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PanelWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PanelWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PanelWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void PanelWidget::signalTextLoadToTextEdit(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PanelWidget::signalToGetTextFromTextEdit()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PanelWidget::signalCleanTextEdit()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
