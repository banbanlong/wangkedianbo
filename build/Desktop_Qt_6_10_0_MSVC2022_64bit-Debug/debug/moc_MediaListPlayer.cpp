/****************************************************************************
** Meta object code from reading C++ file 'MediaListPlayer.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../core/MediaListPlayer.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MediaListPlayer.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18VlcMediaListPlayerE_t {};
} // unnamed namespace

template <> constexpr inline auto VlcMediaListPlayer::qt_create_metaobjectdata<qt_meta_tag_ZN18VlcMediaListPlayerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VlcMediaListPlayer",
        "played",
        "",
        "nextItemSet",
        "VlcMedia*",
        "media",
        "libvlc_media_t*",
        "stopped",
        "itemAt",
        "index",
        "next",
        "play",
        "previous",
        "stop"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'played'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'nextItemSet'
        QtMocHelpers::SignalData<void(VlcMedia *)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Signal 'nextItemSet'
        QtMocHelpers::SignalData<void(libvlc_media_t *)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 5 },
        }}),
        // Signal 'stopped'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'itemAt'
        QtMocHelpers::SlotData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
        // Slot 'next'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'play'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'previous'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stop'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<VlcMediaListPlayer, qt_meta_tag_ZN18VlcMediaListPlayerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject VlcMediaListPlayer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18VlcMediaListPlayerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18VlcMediaListPlayerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18VlcMediaListPlayerE_t>.metaTypes,
    nullptr
} };

void VlcMediaListPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VlcMediaListPlayer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->played(); break;
        case 1: _t->nextItemSet((*reinterpret_cast< std::add_pointer_t<VlcMedia*>>(_a[1]))); break;
        case 2: _t->nextItemSet((*reinterpret_cast< std::add_pointer_t<libvlc_media_t*>>(_a[1]))); break;
        case 3: _t->stopped(); break;
        case 4: _t->itemAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->next(); break;
        case 6: _t->play(); break;
        case 7: _t->previous(); break;
        case 8: _t->stop(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< VlcMedia* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (VlcMediaListPlayer::*)()>(_a, &VlcMediaListPlayer::played, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaListPlayer::*)(VlcMedia * )>(_a, &VlcMediaListPlayer::nextItemSet, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaListPlayer::*)(libvlc_media_t * )>(_a, &VlcMediaListPlayer::nextItemSet, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaListPlayer::*)()>(_a, &VlcMediaListPlayer::stopped, 3))
            return;
    }
}

const QMetaObject *VlcMediaListPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VlcMediaListPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18VlcMediaListPlayerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VlcMediaListPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void VlcMediaListPlayer::played()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VlcMediaListPlayer::nextItemSet(VlcMedia * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void VlcMediaListPlayer::nextItemSet(libvlc_media_t * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void VlcMediaListPlayer::stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
