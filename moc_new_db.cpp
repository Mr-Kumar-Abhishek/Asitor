/****************************************************************************
** Meta object code from reading C++ file 'new_db.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "new_db.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'new_db.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_new_db[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      20,    7,    7,    7, 0x08,
      30,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_new_db[] = {
    "new_db\0\0on_browse()\0on_okay()\0on_cancel()\0"
};

void new_db::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        new_db *_t = static_cast<new_db *>(_o);
        switch (_id) {
        case 0: _t->on_browse(); break;
        case 1: _t->on_okay(); break;
        case 2: _t->on_cancel(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData new_db::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject new_db::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_new_db,
      qt_meta_data_new_db, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &new_db::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *new_db::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *new_db::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_new_db))
        return static_cast<void*>(const_cast< new_db*>(this));
    return QWidget::qt_metacast(_clname);
}

int new_db::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
