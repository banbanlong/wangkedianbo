/****************************************************************************
** Meta object code from reading C++ file 'MediaList.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../core/MediaList.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MediaList.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12VlcMediaListE_t {};
} // unnamed namespace

template <> constexpr inline auto VlcMediaList::qt_create_metaobjectdata<qt_meta_tag_ZN12VlcMediaListE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VlcMediaList",
        "itemAdded",
        "",
        "libvlc_media_t*",
        "item",
        "index",
        "willAddItem",
        "itemDeleted",
        "willDeleteItem"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'itemAdded'
        QtMocHelpers::SignalData<void(libvlc_media_t *, int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Int, 5 },
        }}),
        // Signal 'willAddItem'
        QtMocHelpers::SignalData<void(libvlc_media_t *, int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Int, 5 },
        }}),
        // Signal 'itemDeleted'
        QtMocHelpers::SignalData<void(libvlc_media_t *, int)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Int, 5 },
        }}),
        // Signal 'willDeleteItem'
        QtMocHelpers::SignalData<void(libvlc_media_t *, int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Int, 5 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<VlcMediaList, qt_meta_tag_ZN12VlcMediaListE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject VlcMediaList::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12VlcMediaListE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12VlcMediaListE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12VlcMediaListE_t>.metaTypes,
    nullptr
} };

void VlcMediaList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VlcMediaList *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->itemAdded((*reinterpret_cast< std::add_pointer_t<libvlc_media_t*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->willAddItem((*reinterpret_cast< std::add_pointer_t<libvlc_media_t*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->itemDeleted((*reinterpret_cast< std::add_pointer_t<libvlc_media_t*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->willDeleteItem((*reinterpret_cast< std::add_pointer_t<libvlc_media_t*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (VlcMediaList::*)(libvlc_media_t * , int )>(_a, &VlcMediaList::itemAdded, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaList::*)(libvlc_media_t * , int )>(_a, &VlcMediaList::willAddItem, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaList::*)(libvlc_media_t * , int )>(_a, &VlcMediaList::itemDeleted, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaList::*)(libvlc_media_t * , int )>(_a, &VlcMediaList::willDeleteItem, 3))
            return;
    }
}

const QMetaObject *VlcMediaList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VlcMediaList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12VlcMediaListE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VlcMediaList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void VlcMediaList::itemAdded(libvlc_media_t * _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void VlcMediaList::willAddItem(libvlc_media_t * _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void VlcMediaList::itemDeleted(libvlc_media_t * _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void VlcMediaList::willDeleteItem(libvlc_media_t * _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}
QT_WARNING_POP
