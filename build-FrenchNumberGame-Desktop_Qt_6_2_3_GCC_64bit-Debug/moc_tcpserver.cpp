/****************************************************************************
** Meta object code from reading C++ file 'tcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../FrenchNumberGame/tcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpServer_t {
    const uint offsetsAndSize[16];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TcpServer_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TcpServer_t qt_meta_stringdata_TcpServer = {
    {
QT_MOC_LITERAL(0, 9), // "TcpServer"
QT_MOC_LITERAL(10, 20), // "ClientAnswerRecieved"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 13), // "MessageClient"
QT_MOC_LITERAL(46, 18), // "ServerMessageTypes"
QT_MOC_LITERAL(65, 15), // "SendNewQuestion"
QT_MOC_LITERAL(81, 15), // "ClientConnected"
QT_MOC_LITERAL(97, 11) // "ReadMessage"

    },
    "TcpServer\0ClientAnswerRecieved\0\0"
    "MessageClient\0ServerMessageTypes\0"
    "SendNewQuestion\0ClientConnected\0"
    "ReadMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpServer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   44,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    3,   49,    2, 0x0a,    4 /* Public */,
       5,    2,   56,    2, 0x0a,    8 /* Public */,
       6,    0,   61,    2, 0x08,   11 /* Private */,
       7,    0,   62,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ClientAnswerRecieved((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->MessageClient((*reinterpret_cast< ServerMessageTypes(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->SendNewQuestion((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->ClientConnected(); break;
        case 4: _t->ReadMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpServer::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::ClientAnswerRecieved)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TcpServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TcpServer.offsetsAndSize,
    qt_meta_data_TcpServer,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TcpServer_t
, QtPrivate::TypeAndForceComplete<TcpServer, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ServerMessageTypes, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TcpServer::ClientAnswerRecieved(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
