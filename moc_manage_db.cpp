/****************************************************************************
** Meta object code from reading C++ file 'manage_db.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "manage_db.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manage_db.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_manage_db[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,   22,   22,   22, 0x08,
      23,   22,   22,   22, 0x08,
      36,   22,   22,   22, 0x08,
      54,   22,   22,   22, 0x08,
      65,   22,   22,   22, 0x08,
      79,   22,   22,   22, 0x08,
      96,   22,   22,   22, 0x08,
     109,   22,   22,   22, 0x08,
     127,   22,   22,   22, 0x08,
     145,   22,   22,   22, 0x08,
     162,   22,   22,   22, 0x08,
     179,   22,   22,   22, 0x08,
     195,   22,   22,   22, 0x08,
     212,   22,   22,   22, 0x08,
     229,   22,   22,   22, 0x08,
     245,   22,   22,   22, 0x08,
     258,   22,   22,   22, 0x08,
     271,   22,   22,   22, 0x08,
     285,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_manage_db[] = {
    "manage_db\0on_new_db()\0\0on_open_db()\0"
    "switchingLayout()\0on_about()\0on_close_db()\0"
    "on_new_student()\0on_license()\0"
    "on_view_student()\0on_edit_student()\0"
    "on_del_student()\0on_add_student()\0"
    "on_add_course()\0on_view_course()\0"
    "on_edit_course()\0on_del_course()\0"
    "on_new_mod()\0on_see_mod()\0on_edit_mod()\0"
    "on_del_mod()\0"
};

void manage_db::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        manage_db *_t = static_cast<manage_db *>(_o);
        switch (_id) {
        case 0: _t->on_new_db(); break;
        case 1: _t->on_open_db(); break;
        case 2: _t->switchingLayout(); break;
        case 3: _t->on_about(); break;
        case 4: _t->on_close_db(); break;
        case 5: _t->on_new_student(); break;
        case 6: _t->on_license(); break;
        case 7: _t->on_view_student(); break;
        case 8: _t->on_edit_student(); break;
        case 9: _t->on_del_student(); break;
        case 10: _t->on_add_student(); break;
        case 11: _t->on_add_course(); break;
        case 12: _t->on_view_course(); break;
        case 13: _t->on_edit_course(); break;
        case 14: _t->on_del_course(); break;
        case 15: _t->on_new_mod(); break;
        case 16: _t->on_see_mod(); break;
        case 17: _t->on_edit_mod(); break;
        case 18: _t->on_del_mod(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData manage_db::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject manage_db::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_manage_db,
      qt_meta_data_manage_db, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &manage_db::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *manage_db::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *manage_db::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_manage_db))
        return static_cast<void*>(const_cast< manage_db*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int manage_db::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
