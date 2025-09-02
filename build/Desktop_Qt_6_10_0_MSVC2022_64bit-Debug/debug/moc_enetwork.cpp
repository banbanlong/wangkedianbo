/****************************************************************************
** Meta object code from reading C++ file 'enetwork.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../enetwork.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enetwork.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN8ENetworkE_t {};
} // unnamed namespace

template <> constexpr inline auto ENetwork::qt_create_metaobjectdata<qt_meta_tag_ZN8ENetworkE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ENetwork",
        "QML.Element",
        "auto",
        "receive",
        "",
        "cmd",
        "data",
        "error",
        "err",
        "hostChanged",
        "portChanged",
        "connected",
        "onReadyRead",
        "start",
        "send",
        "host",
        "port"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'receive'
        QtMocHelpers::SignalData<void(int, const QJsonObject &)>(3, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 }, { QMetaType::QJsonObject, 6 },
        }}),
        // Signal 'error'
        QtMocHelpers::SignalData<void(int)>(7, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 },
        }}),
        // Signal 'hostChanged'
        QtMocHelpers::SignalData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'portChanged'
        QtMocHelpers::SignalData<void()>(10, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'connected'
        QtMocHelpers::SignalData<void()>(11, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onReadyRead'
        QtMocHelpers::SlotData<void()>(12, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'start'
        QtMocHelpers::MethodData<void()>(13, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'send'
        QtMocHelpers::MethodData<void(int, const QJsonObject &)>(14, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 }, { QMetaType::QJsonObject, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'host'
        QtMocHelpers::PropertyData<QString>(15, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'port'
        QtMocHelpers::PropertyData<int>(16, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<ENetwork, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject ENetwork::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8ENetworkE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8ENetworkE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8ENetworkE_t>.metaTypes,
    nullptr
} };

void ENetwork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ENetwork *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->receive((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 1: _t->error((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->hostChanged(); break;
        case 3: _t->portChanged(); break;
        case 4: _t->connected(); break;
        case 5: _t->onReadyRead(); break;
        case 6: _t->start(); break;
        case 7: _t->send((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ENetwork::*)(int , const QJsonObject & )>(_a, &ENetwork::receive, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ENetwork::*)(int )>(_a, &ENetwork::error, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ENetwork::*)()>(_a, &ENetwork::hostChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ENetwork::*)()>(_a, &ENetwork::portChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ENetwork::*)()>(_a, &ENetwork::connected, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->host(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->port(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setHost(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setPort(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *ENetwork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ENetwork::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8ENetworkE_t>.strings))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int ENetwork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ENetwork::receive(int _t1, const QJsonObject & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void ENetwork::error(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void ENetwork::hostChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ENetwork::portChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ENetwork::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
