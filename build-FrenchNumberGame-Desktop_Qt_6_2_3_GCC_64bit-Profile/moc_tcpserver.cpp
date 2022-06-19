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
    const uint offsetsAndSize[38];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TcpServer_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TcpServer_t qt_meta_stringdata_TcpServer = {
    {
QT_MOC_LITERAL(0, 9), // "TcpServer"
QT_MOC_LITERAL(10, 20), // "ClientAnswerRecieved"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 18), // "ClientSkipRecieved"
QT_MOC_LITERAL(51, 22), // "HandleClientDisconnect"
QT_MOC_LITERAL(74, 22), // "ClientUsernameRecieved"
QT_MOC_LITERAL(97, 20), // "SendUsernameAndScore"
QT_MOC_LITERAL(118, 18), // "ClientStateChanged"
QT_MOC_LITERAL(137, 21), // "RemoveClientFromTable"
QT_MOC_LITERAL(159, 28), // "ClientScoreboardStateChanged"
QT_MOC_LITERAL(188, 11), // "CloseServer"
QT_MOC_LITERAL(200, 13), // "MessageClient"
QT_MOC_LITERAL(214, 18), // "ServerMessageTypes"
QT_MOC_LITERAL(233, 6), // "UserId"
QT_MOC_LITERAL(240, 15), // "SendNewQuestion"
QT_MOC_LITERAL(256, 17), // "GetClientUsername"
QT_MOC_LITERAL(274, 15), // "ClientConnected"
QT_MOC_LITERAL(290, 11), // "ReadMessage"
QT_MOC_LITERAL(302, 16) // "HandleDisconnect"

    },
    "TcpServer\0ClientAnswerRecieved\0\0"
    "ClientSkipRecieved\0HandleClientDisconnect\0"
    "ClientUsernameRecieved\0SendUsernameAndScore\0"
    "ClientStateChanged\0RemoveClientFromTable\0"
    "ClientScoreboardStateChanged\0CloseServer\0"
    "MessageClient\0ServerMessageTypes\0"
    "UserId\0SendNewQuestion\0GetClientUsername\0"
    "ClientConnected\0ReadMessage\0"
    "HandleDisconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpServer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  110,    2, 0x06,    1 /* Public */,
       3,    1,  115,    2, 0x06,    4 /* Public */,
       4,    1,  118,    2, 0x06,    6 /* Public */,
       5,    2,  121,    2, 0x06,    8 /* Public */,
       6,    3,  126,    2, 0x06,   11 /* Public */,
       7,    1,  133,    2, 0x06,   15 /* Public */,
       8,    1,  136,    2, 0x06,   17 /* Public */,
       9,    1,  139,    2, 0x06,   19 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,  142,    2, 0x0a,   21 /* Public */,
      11,    4,  143,    2, 0x0a,   22 /* Public */,
      11,    3,  152,    2, 0x2a,   27 /* Public | MethodCloned */,
      14,    2,  159,    2, 0x0a,   31 /* Public */,
      15,    3,  164,    2, 0x0a,   34 /* Public */,
      16,    0,  171,    2, 0x08,   38 /* Private */,
      17,    0,  172,    2, 0x08,   39 /* Private */,
      18,    0,  173,    2, 0x08,   40 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Bool,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int, QMetaType::QString, QMetaType::Int,    2,    2,    2,   13,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    2,    2,    2,
    QMetaType::Void,
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
        case 1: _t->ClientSkipRecieved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->HandleClientDisconnect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ClientUsernameRecieved((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->SendUsernameAndScore((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 5: _t->ClientStateChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->RemoveClientFromTable((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->ClientScoreboardStateChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->CloseServer(); break;
        case 9: _t->MessageClient((*reinterpret_cast< ServerMessageTypes(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 10: _t->MessageClient((*reinterpret_cast< ServerMessageTypes(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 11: _t->SendNewQuestion((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->GetClientUsername((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 13: _t->ClientConnected(); break;
        case 14: _t->ReadMessage(); break;
        case 15: _t->HandleDisconnect(); break;
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
        {
            using _t = void (TcpServer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::ClientSkipRecieved)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::HandleClientDisconnect)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::ClientUsernameRecieved)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(QString , int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::SendUsernameAndScore)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::ClientStateChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::RemoveClientFromTable)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (TcpServer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServer::ClientScoreboardStateChanged)) {
                *result = 7;
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
, QtPrivate::TypeAndForceComplete<TcpServer, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ServerMessageTypes, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ServerMessageTypes, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void TcpServer::ClientAnswerRecieved(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpServer::ClientSkipRecieved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpServer::HandleClientDisconnect(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TcpServer::ClientUsernameRecieved(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TcpServer::SendUsernameAndScore(QString _t1, int _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TcpServer::ClientStateChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TcpServer::RemoveClientFromTable(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TcpServer::ClientScoreboardStateChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
