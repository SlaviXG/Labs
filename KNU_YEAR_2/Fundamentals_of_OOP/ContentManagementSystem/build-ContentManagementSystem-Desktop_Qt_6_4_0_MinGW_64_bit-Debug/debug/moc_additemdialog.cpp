/****************************************************************************
** Meta object code from reading C++ file 'additemdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ContentManagementSystem/additemdialog.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'additemdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
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
struct qt_meta_stringdata_AddItemDialog_t {
    uint offsetsAndSizes[16];
    char stringdata0[14];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[14];
    char stringdata5[18];
    char stringdata6[19];
    char stringdata7[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_AddItemDialog_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_AddItemDialog_t qt_meta_stringdata_AddItemDialog = {
    {
        QT_MOC_LITERAL(0, 13),  // "AddItemDialog"
        QT_MOC_LITERAL(14, 13),  // "addDirClicked"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 14),  // "addFileClicked"
        QT_MOC_LITERAL(44, 13),  // "addTxtClicked"
        QT_MOC_LITERAL(58, 17),  // "on_btnDir_clicked"
        QT_MOC_LITERAL(76, 18),  // "on_btnFile_clicked"
        QT_MOC_LITERAL(95, 17)   // "on_btnTxt_clicked"
    },
    "AddItemDialog",
    "addDirClicked",
    "",
    "addFileClicked",
    "addTxtClicked",
    "on_btnDir_clicked",
    "on_btnFile_clicked",
    "on_btnTxt_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_AddItemDialog[] = {

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
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    0,   51,    2, 0x06,    2 /* Public */,
       4,    0,   52,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject AddItemDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_AddItemDialog.offsetsAndSizes,
    qt_meta_data_AddItemDialog,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_AddItemDialog_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AddItemDialog, std::true_type>,
        // method 'addDirClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addFileClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addTxtClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnDir_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnFile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnTxt_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AddItemDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AddItemDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addDirClicked(); break;
        case 1: _t->addFileClicked(); break;
        case 2: _t->addTxtClicked(); break;
        case 3: _t->on_btnDir_clicked(); break;
        case 4: _t->on_btnFile_clicked(); break;
        case 5: _t->on_btnTxt_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AddItemDialog::*)();
            if (_t _q_method = &AddItemDialog::addDirClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AddItemDialog::*)();
            if (_t _q_method = &AddItemDialog::addFileClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AddItemDialog::*)();
            if (_t _q_method = &AddItemDialog::addTxtClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *AddItemDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddItemDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddItemDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AddItemDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void AddItemDialog::addDirClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AddItemDialog::addFileClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AddItemDialog::addTxtClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
