/****************************************************************************
** Meta object code from reading C++ file 'endscreen.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../FrenchNumberGame/endscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'endscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EndScreen_t {
    const uint offsetsAndSize[30];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_EndScreen_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_EndScreen_t qt_meta_stringdata_EndScreen = {
    {
QT_MOC_LITERAL(0, 9), // "EndScreen"
QT_MOC_LITERAL(10, 17), // "MenuButtonClicked"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 22), // "MultiMenuButtonClicked"
QT_MOC_LITERAL(52, 18), // "AgainButtonClicked"
QT_MOC_LITERAL(71, 23), // "MultiLobbyButtonClicked"
QT_MOC_LITERAL(95, 21), // "MultiPlayAgainClicked"
QT_MOC_LITERAL(117, 18), // "ClientStateChanged"
QT_MOC_LITERAL(136, 22), // "ServerPlayAgainClicked"
QT_MOC_LITERAL(159, 16), // "UpdateScoreboard"
QT_MOC_LITERAL(176, 21), // "UpdateScoreboardState"
QT_MOC_LITERAL(198, 18), // "NotAllPlayersReady"
QT_MOC_LITERAL(217, 22), // "on_AgainButton_clicked"
QT_MOC_LITERAL(240, 21), // "on_MenuButton_clicked"
QT_MOC_LITERAL(262, 22) // "HandleMultiplayerAgain"

    },
    "EndScreen\0MenuButtonClicked\0\0"
    "MultiMenuButtonClicked\0AgainButtonClicked\0"
    "MultiLobbyButtonClicked\0MultiPlayAgainClicked\0"
    "ClientStateChanged\0ServerPlayAgainClicked\0"
    "UpdateScoreboard\0UpdateScoreboardState\0"
    "NotAllPlayersReady\0on_AgainButton_clicked\0"
    "on_MenuButton_clicked\0HandleMultiplayerAgain"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EndScreen[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x06,    1 /* Public */,
       3,    0,   93,    2, 0x06,    2 /* Public */,
       4,    0,   94,    2, 0x06,    3 /* Public */,
       5,    1,   95,    2, 0x06,    4 /* Public */,
       6,    0,   98,    2, 0x06,    6 /* Public */,
       7,    1,   99,    2, 0x06,    7 /* Public */,
       8,    0,  102,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    3,  103,    2, 0x0a,   10 /* Public */,
      10,    1,  110,    2, 0x0a,   14 /* Public */,
      11,    0,  113,    2, 0x0a,   16 /* Public */,
      12,    0,  114,    2, 0x08,   17 /* Private */,
      13,    0,  115,    2, 0x08,   18 /* Private */,
      14,    0,  116,    2, 0x08,   19 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EndScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EndScreen *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->MenuButtonClicked(); break;
        case 1: _t->MultiMenuButtonClicked(); break;
        case 2: _t->AgainButtonClicked(); break;
        case 3: _t->MultiLobbyButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->MultiPlayAgainClicked(); break;
        case 5: _t->ClientStateChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->ServerPlayAgainClicked(); break;
        case 7: _t->UpdateScoreboard((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 8: _t->UpdateScoreboardState((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->NotAllPlayersReady(); break;
        case 10: _t->on_AgainButton_clicked(); break;
        case 11: _t->on_MenuButton_clicked(); break;
        case 12: _t->HandleMultiplayerAgain(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EndScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EndScreen::MenuButtonClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EndScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EndScreen::MultiMenuButtonClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (EndScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EndScreen::AgainButtonClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (EndScreen::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EndScreen::MultiLobbyButtonClicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (EndScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EndScreen::MultiPlayAgainClicked)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (EndScreen::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EndScreen::ClientStateChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (EndScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EndScreen::ServerPlayAgainClicked)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject EndScreen::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_EndScreen.offsetsAndSize,
    qt_meta_data_EndScreen,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_EndScreen_t
, QtPrivate::TypeAndForceComplete<EndScreen, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *EndScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EndScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EndScreen.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int EndScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void EndScreen::MenuButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void EndScreen::MultiMenuButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void EndScreen::AgainButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void EndScreen::MultiLobbyButtonClicked(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void EndScreen::MultiPlayAgainClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void EndScreen::ClientStateChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void EndScreen::ServerPlayAgainClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
