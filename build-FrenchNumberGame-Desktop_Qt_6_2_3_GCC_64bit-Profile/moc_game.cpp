/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../FrenchNumberGame/game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Game_t {
    const uint offsetsAndSize[22];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Game_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Game_t qt_meta_stringdata_Game = {
    {
QT_MOC_LITERAL(0, 4), // "Game"
QT_MOC_LITERAL(5, 13), // "ClientUpdated"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 16), // "ClientGameUpdate"
QT_MOC_LITERAL(37, 18), // "ServerMessageTypes"
QT_MOC_LITERAL(56, 9), // "GameEnded"
QT_MOC_LITERAL(66, 15), // "GameScoreUpdate"
QT_MOC_LITERAL(82, 9), // "AddClient"
QT_MOC_LITERAL(92, 12), // "ClientUpdate"
QT_MOC_LITERAL(105, 17), // "CheckClientAnswer"
QT_MOC_LITERAL(123, 22) // "HandleClientDisconnect"

    },
    "Game\0ClientUpdated\0\0ClientGameUpdate\0"
    "ServerMessageTypes\0GameEnded\0"
    "GameScoreUpdate\0AddClient\0ClientUpdate\0"
    "CheckClientAnswer\0HandleClientDisconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Game[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,
       3,    4,   71,    2, 0x06,    3 /* Public */,
       3,    3,   80,    2, 0x26,    8 /* Public | MethodCloned */,
       5,    2,   87,    2, 0x06,   12 /* Public */,
       6,    3,   92,    2, 0x06,   15 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    2,   99,    2, 0x08,   19 /* Private */,
       8,    1,  104,    2, 0x08,   22 /* Private */,
       9,    2,  107,    2, 0x08,   24 /* Private */,
      10,    1,  112,    2, 0x08,   27 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int, QMetaType::QString, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Game *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ClientUpdated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->ClientGameUpdate((*reinterpret_cast< ServerMessageTypes(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->ClientGameUpdate((*reinterpret_cast< ServerMessageTypes(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->GameEnded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->GameScoreUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 5: _t->AddClient((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->ClientUpdate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->CheckClientAnswer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->HandleClientDisconnect((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Game::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Game::ClientUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Game::*)(ServerMessageTypes , int , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Game::ClientGameUpdate)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Game::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Game::GameEnded)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Game::*)(int , int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Game::GameScoreUpdate)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject Game::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Game.offsetsAndSize,
    qt_meta_data_Game,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Game_t
, QtPrivate::TypeAndForceComplete<Game, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ServerMessageTypes, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ServerMessageTypes, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Game::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Game.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Game::ClientUpdated(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Game::ClientGameUpdate(ServerMessageTypes _t1, int _t2, QString _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 3
void Game::GameEnded(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Game::GameScoreUpdate(int _t1, int _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
