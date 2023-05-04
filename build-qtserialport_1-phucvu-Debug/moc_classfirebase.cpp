/****************************************************************************
** Meta object code from reading C++ file 'classfirebase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qtserialport_1/classfirebase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'classfirebase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_classfirebase_t {
    QByteArrayData data[6];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_classfirebase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_classfirebase_t qt_meta_stringdata_classfirebase = {
    {
QT_MOC_LITERAL(0, 0, 13), // "classfirebase"
QT_MOC_LITERAL(1, 14, 13), // "datamapOutput"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "data"
QT_MOC_LITERAL(4, 34, 11), // "dataChanged"
QT_MOC_LITERAL(5, 46, 21) // "networkReplyReadyRead"

    },
    "classfirebase\0datamapOutput\0\0data\0"
    "dataChanged\0networkReplyReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_classfirebase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariantMap,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void classfirebase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        classfirebase *_t = static_cast<classfirebase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->datamapOutput((*reinterpret_cast< const QVariantMap(*)>(_a[1]))); break;
        case 1: _t->dataChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->networkReplyReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (classfirebase::*_t)(const QVariantMap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&classfirebase::datamapOutput)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (classfirebase::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&classfirebase::dataChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject classfirebase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_classfirebase.data,
      qt_meta_data_classfirebase,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *classfirebase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *classfirebase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_classfirebase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int classfirebase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void classfirebase::datamapOutput(const QVariantMap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void classfirebase::dataChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
