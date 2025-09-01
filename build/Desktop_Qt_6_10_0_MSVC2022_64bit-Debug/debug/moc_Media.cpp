/****************************************************************************
** Meta object code from reading C++ file 'Media.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../core/Media.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Media.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN8VlcMediaE_t {};
} // unnamed namespace

template <> constexpr inline auto VlcMedia::qt_create_metaobjectdata<qt_meta_tag_ZN8VlcMediaE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VlcMedia",
        "metaChanged",
        "",
        "Vlc::Meta",
        "meta",
        "subitemAdded",
        "libvlc_media_t*",
        "subitem",
        "durationChanged",
        "duration",
        "parsedChanged",
        "status",
        "freed",
        "media",
        "stateChanged",
        "Vlc::State",
        "state"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'metaChanged'
        QtMocHelpers::SignalData<void(const Vlc::Meta &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'subitemAdded'
        QtMocHelpers::SignalData<void(libvlc_media_t *)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Signal 'durationChanged'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
        // Signal 'parsedChanged'
        QtMocHelpers::SignalData<void(int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 11 },
        }}),
        // Signal 'parsedChanged'
        QtMocHelpers::SignalData<void(bool)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 11 },
        }}),
        // Signal 'freed'
        QtMocHelpers::SignalData<void(libvlc_media_t *)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 13 },
        }}),
        // Signal 'stateChanged'
        QtMocHelpers::SignalData<void(const Vlc::State &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 15, 16 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<VlcMedia, qt_meta_tag_ZN8VlcMediaE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject VlcMedia::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8VlcMediaE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8VlcMediaE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8VlcMediaE_t>.metaTypes,
    nullptr
} };

void VlcMedia::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VlcMedia *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->metaChanged((*reinterpret_cast< std::add_pointer_t<Vlc::Meta>>(_a[1]))); break;
        case 1: _t->subitemAdded((*reinterpret_cast< std::add_pointer_t<libvlc_media_t*>>(_a[1]))); break;
        case 2: _t->durationChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->parsedChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->parsedChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->freed((*reinterpret_cast< std::add_pointer_t<libvlc_media_t*>>(_a[1]))); break;
        case 6: _t->stateChanged((*reinterpret_cast< std::add_pointer_t<Vlc::State>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (VlcMedia::*)(const Vlc::Meta & )>(_a, &VlcMedia::metaChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMedia::*)(libvlc_media_t * )>(_a, &VlcMedia::subitemAdded, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMedia::*)(int )>(_a, &VlcMedia::durationChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMedia::*)(int )>(_a, &VlcMedia::parsedChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMedia::*)(bool )>(_a, &VlcMedia::parsedChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMedia::*)(libvlc_media_t * )>(_a, &VlcMedia::freed, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMedia::*)(const Vlc::State & )>(_a, &VlcMedia::stateChanged, 6))
            return;
    }
}

const QMetaObject *VlcMedia::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VlcMedia::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8VlcMediaE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VlcMedia::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void VlcMedia::metaChanged(const Vlc::Meta & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void VlcMedia::subitemAdded(libvlc_media_t * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void VlcMedia::durationChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void VlcMedia::parsedChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void VlcMedia::parsedChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void VlcMedia::freed(libvlc_media_t * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void VlcMedia::stateChanged(const Vlc::State & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}
QT_WARNING_POP
