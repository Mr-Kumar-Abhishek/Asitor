/****************************************************************************
** Meta object code from reading C++ file 'asitor.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "asitor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asitor.h' doesn't include <QObject>."
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
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      23,   10,   10,   10, 0x08,
      36,   10,   10,   10, 0x08,
      54,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_manage_db[] = {
    "manage_db\0\0on_new_db()\0on_open_db()\0"
    "switchingLayout()\0on_about()\0"
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
