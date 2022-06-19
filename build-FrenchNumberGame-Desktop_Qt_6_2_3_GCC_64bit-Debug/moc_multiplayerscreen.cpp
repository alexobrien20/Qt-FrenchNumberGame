/****************************************************************************
** Meta object code from reading C++ file 'multiplayerscreen.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../FrenchNumberGame/multiplayerscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multiplayerscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MultiPlayerScreen_t {
    const uint offsetsAndSize[34];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MultiPlayerScreen_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MultiPlayerScreen_t qt_meta_stringdata_MultiPlayerScreen = {
    {
QT_MOC_LITERAL(0, 17), // "MultiPlayerScreen"
QT_MOC_LITERAL(18, 23), // "MenuButtonClickedSignal"
QT_MOC_LITERAL(42, 0), // ""
QT_MOC_LITERAL(43, 11), // "GameStarted"
QT_MOC_LITERAL(55, 9), // "GameEnded"
QT_MOC_LITERAL(65, 16), // "ClientSendAnswer"
QT_MOC_LITERAL(82, 24), // "StartServerButtonClicked"
QT_MOC_LITERAL(107, 23), // "JoinServerButtonClicked"
QT_MOC_LITERAL(131, 17), // "MenuButtonClicked"
QT_MOC_LITERAL(149, 15), // "ClientConnected"
QT_MOC_LITERAL(165, 22), // "StartGameButtonClicked"
QT_MOC_LITERAL(188, 12), // "DisplayError"
QT_MOC_LITERAL(201, 15), // "SetUpGameScreen"
QT_MOC_LITERAL(217, 11), // "GameUpdated"
QT_MOC_LITERAL(229, 17), // "SkipButtonClicked"
QT_MOC_LITERAL(247, 18), // "ClearButtonClicked"
QT_MOC_LITERAL(266, 18) // "EnterButtonClicked"

    },
    "MultiPlayerScreen\0MenuButtonClickedSignal\0"
    "\0GameStarted\0GameEnded\0ClientSendAnswer\0"
    "StartServerButtonClicked\0"
    "JoinServerButtonClicked\0MenuButtonClicked\0"
    "ClientConnected\0StartGameButtonClicked\0"
    "DisplayError\0SetUpGameScreen\0GameUpdated\0"
    "SkipButtonClicked\0ClearButtonClicked\0"
    "EnterButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MultiPlayerScreen[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x06,    1 /* Public */,
       3,    1,  105,    2, 0x06,    2 /* Public */,
       4,    1,  108,    2, 0x06,    4 /* Public */,
       5,    1,  111,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,  114,    2, 0x08,    8 /* Private */,
       7,    0,  115,    2, 0x08,    9 /* Private */,
       8,    0,  116,    2, 0x08,   10 /* Private */,
       9,    0,  117,    2, 0x08,   11 /* Private */,
      10,    0,  118,    2, 0x08,   12 /* Private */,
      11,    1,  119,    2, 0x08,   13 /* Private */,
      12,    1,  122,    2, 0x08,   15 /* Private */,
      13,    1,  125,    2, 0x08,   17 /* Private */,
      14,    0,  128,    2, 0x08,   19 /* Private */,
      15,    0,  129,    2, 0x08,   20 /* Private */,
      16,    0,  130,    2, 0x08,   21 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MultiPlayerScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MultiPlayerScreen *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->MenuButtonClickedSignal(); break;
        case 1: _t->GameStarted((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->GameEnded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ClientSendAnswer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->StartServerButtonClicked(); break;
        case 5: _t->JoinServerButtonClicked(); break;
        case 6: _t->MenuButtonClicked(); break;
        case 7: _t->ClientConnected(); break;
        case 8: _t->StartGameButtonClicked(); break;
        case 9: _t->DisplayError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->SetUpGameScreen((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->GameUpdated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->SkipButtonClicked(); break;
        case 13: _t->ClearButtonClicked(); break;
        case 14: _t->EnterButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MultiPlayerScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultiPlayerScreen::MenuButtonClickedSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MultiPlayerScreen::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultiPlayerScreen::GameStarted)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MultiPlayerScreen::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultiPlayerScreen::GameEnded)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MultiPlayerScreen::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultiPlayerScreen::ClientSendAnswer)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject MultiPlayerScreen::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MultiPlayerScreen.offsetsAndSize,
    qt_meta_data_MultiPlayerScreen,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MultiPlayerScreen_t
, QtPrivate::TypeAndForceComplete<MultiPlayerScreen, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MultiPlayerScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MultiPlayerScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MultiPlayerScreen.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MultiPlayerScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void MultiPlayerScreen::MenuButtonClickedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MultiPlayerScreen::GameStarted(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MultiPlayerScreen::GameEnded(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MultiPlayerScreen::ClientSendAnswer(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
