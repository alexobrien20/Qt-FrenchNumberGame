/****************************************************************************
** Meta object code from reading C++ file 'tcpclient.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../FrenchNumberGame/tcpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpClient_t {
    const uint offsetsAndSize[40];
    char stringdata0[310];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TcpClient_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TcpClient_t qt_meta_stringdata_TcpClient = {
    {
QT_MOC_LITERAL(0, 9), // "TcpClient"
QT_MOC_LITERAL(10, 17), // "ClientErrorSignal"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 21), // "ClientConnectedSignal"
QT_MOC_LITERAL(51, 11), // "GameStarted"
QT_MOC_LITERAL(63, 11), // "GameUpdated"
QT_MOC_LITERAL(75, 9), // "GameEnded"
QT_MOC_LITERAL(85, 15), // "GameScoreUpdate"
QT_MOC_LITERAL(101, 18), // "ClientDisconnected"
QT_MOC_LITERAL(120, 13), // "NewUserJoined"
QT_MOC_LITERAL(134, 16), // "UserStateChanged"
QT_MOC_LITERAL(151, 23), // "OtherClientDisconnected"
QT_MOC_LITERAL(175, 28), // "ClientScoreboardStateChanged"
QT_MOC_LITERAL(204, 16), // "RequestNewAnswer"
QT_MOC_LITERAL(221, 12), // "SendUsername"
QT_MOC_LITERAL(234, 11), // "CloseClient"
QT_MOC_LITERAL(246, 14), // "SendUserStatus"
QT_MOC_LITERAL(261, 15), // "ClientConnected"
QT_MOC_LITERAL(277, 15), // "MessageRecieved"
QT_MOC_LITERAL(293, 16) // "HandleDisconnect"

    },
    "TcpClient\0ClientErrorSignal\0\0"
    "ClientConnectedSignal\0GameStarted\0"
    "GameUpdated\0GameEnded\0GameScoreUpdate\0"
    "ClientDisconnected\0NewUserJoined\0"
    "UserStateChanged\0OtherClientDisconnected\0"
    "ClientScoreboardStateChanged\0"
    "RequestNewAnswer\0SendUsername\0CloseClient\0"
    "SendUserStatus\0ClientConnected\0"
    "MessageRecieved\0HandleDisconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpClient[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  122,    2, 0x06,    1 /* Public */,
       3,    0,  125,    2, 0x06,    3 /* Public */,
       4,    1,  126,    2, 0x06,    4 /* Public */,
       5,    1,  129,    2, 0x06,    6 /* Public */,
       6,    2,  132,    2, 0x06,    8 /* Public */,
       7,    3,  137,    2, 0x06,   11 /* Public */,
       8,    0,  144,    2, 0x06,   15 /* Public */,
       9,    3,  145,    2, 0x06,   16 /* Public */,
      10,    1,  152,    2, 0x06,   20 /* Public */,
      11,    1,  155,    2, 0x06,   22 /* Public */,
      12,    1,  158,    2, 0x06,   24 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    1,  161,    2, 0x0a,   26 /* Public */,
      14,    1,  164,    2, 0x0a,   28 /* Public */,
      15,    0,  167,    2, 0x0a,   30 /* Public */,
      16,    1,  168,    2, 0x0a,   31 /* Public */,
      17,    0,  171,    2, 0x08,   33 /* Private */,
      18,    0,  172,    2, 0x08,   34 /* Private */,
      19,    0,  173,    2, 0x08,   35 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Bool,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ClientErrorSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->ClientConnectedSignal(); break;
        case 2: _t->GameStarted((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->GameUpdated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->GameEnded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->GameScoreUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 6: _t->ClientDisconnected(); break;
        case 7: _t->NewUserJoined((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 8: _t->UserStateChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->OtherClientDisconnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->ClientScoreboardStateChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->RequestNewAnswer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->SendUsername((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->CloseClient(); break;
        case 14: _t->SendUserStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->ClientConnected(); break;
        case 16: _t->MessageRecieved(); break;
        case 17: _t->HandleDisconnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::ClientErrorSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::ClientConnectedSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::GameStarted)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::GameUpdated)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::GameEnded)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(int , QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::GameScoreUpdate)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::ClientDisconnected)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(QString , bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::NewUserJoined)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::UserStateChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::OtherClientDisconnected)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::ClientScoreboardStateChanged)) {
                *result = 10;
                return;
            }
        }
    }
}

const QMetaObject TcpClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TcpClient.offsetsAndSize,
    qt_meta_data_TcpClient,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TcpClient_t
, QtPrivate::TypeAndForceComplete<TcpClient, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void TcpClient::ClientErrorSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpClient::ClientConnectedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TcpClient::GameStarted(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TcpClient::GameUpdated(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TcpClient::GameEnded(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TcpClient::GameScoreUpdate(int _t1, QString _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TcpClient::ClientDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void TcpClient::NewUserJoined(QString _t1, bool _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void TcpClient::UserStateChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void TcpClient::OtherClientDisconnected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void TcpClient::ClientScoreboardStateChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
