/****************************************************************************
** Meta object code from reading C++ file 'MediaPlayer.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../core/MediaPlayer.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MediaPlayer.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14VlcMediaPlayerE_t {};
} // unnamed namespace

template <> constexpr inline auto VlcMediaPlayer::qt_create_metaobjectdata<qt_meta_tag_ZN14VlcMediaPlayerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VlcMediaPlayer",
        "backward",
        "",
        "buffering",
        "buffer",
        "end",
        "error",
        "forward",
        "lengthChanged",
        "length",
        "mediaChanged",
        "libvlc_media_t*",
        "media",
        "nothingSpecial",
        "opening",
        "pausableChanged",
        "pausable",
        "paused",
        "playing",
        "positionChanged",
        "position",
        "seekableChanged",
        "seekable",
        "snapshotTaken",
        "filename",
        "stopped",
        "timeChanged",
        "time",
        "titleChanged",
        "title",
        "vout",
        "count",
        "stateChanged",
        "setTime",
        "setPosition",
        "pos",
        "setPlaybackRate",
        "rate",
        "play",
        "pause",
        "togglePause",
        "resume",
        "stop"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'backward'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'buffering'
        QtMocHelpers::SignalData<void(float)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 4 },
        }}),
        // Signal 'buffering'
        QtMocHelpers::SignalData<void(int)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
        // Signal 'end'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'error'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'forward'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'lengthChanged'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
        // Signal 'mediaChanged'
        QtMocHelpers::SignalData<void(libvlc_media_t *)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 },
        }}),
        // Signal 'nothingSpecial'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'opening'
        QtMocHelpers::SignalData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'pausableChanged'
        QtMocHelpers::SignalData<void(bool)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 16 },
        }}),
        // Signal 'paused'
        QtMocHelpers::SignalData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'playing'
        QtMocHelpers::SignalData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'positionChanged'
        QtMocHelpers::SignalData<void(float)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 20 },
        }}),
        // Signal 'seekableChanged'
        QtMocHelpers::SignalData<void(bool)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 22 },
        }}),
        // Signal 'snapshotTaken'
        QtMocHelpers::SignalData<void(const QString &)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 24 },
        }}),
        // Signal 'stopped'
        QtMocHelpers::SignalData<void()>(25, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'timeChanged'
        QtMocHelpers::SignalData<void(int)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 27 },
        }}),
        // Signal 'titleChanged'
        QtMocHelpers::SignalData<void(int)>(28, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 29 },
        }}),
        // Signal 'vout'
        QtMocHelpers::SignalData<void(int)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 31 },
        }}),
        // Signal 'stateChanged'
        QtMocHelpers::SignalData<void()>(32, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setTime'
        QtMocHelpers::SlotData<void(int)>(33, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 27 },
        }}),
        // Slot 'setPosition'
        QtMocHelpers::SlotData<void(float)>(34, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 35 },
        }}),
        // Slot 'setPlaybackRate'
        QtMocHelpers::SlotData<void(float)>(36, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Float, 37 },
        }}),
        // Slot 'play'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'pause'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'togglePause'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'resume'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stop'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<VlcMediaPlayer, qt_meta_tag_ZN14VlcMediaPlayerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject VlcMediaPlayer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14VlcMediaPlayerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14VlcMediaPlayerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14VlcMediaPlayerE_t>.metaTypes,
    nullptr
} };

void VlcMediaPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VlcMediaPlayer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->backward(); break;
        case 1: _t->buffering((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 2: _t->buffering((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->end(); break;
        case 4: _t->error(); break;
        case 5: _t->forward(); break;
        case 6: _t->lengthChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->mediaChanged((*reinterpret_cast< std::add_pointer_t<libvlc_media_t*>>(_a[1]))); break;
        case 8: _t->nothingSpecial(); break;
        case 9: _t->opening(); break;
        case 10: _t->pausableChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->paused(); break;
        case 12: _t->playing(); break;
        case 13: _t->positionChanged((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 14: _t->seekableChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 15: _t->snapshotTaken((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->stopped(); break;
        case 17: _t->timeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->titleChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->vout((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->stateChanged(); break;
        case 21: _t->setTime((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->setPosition((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 23: _t->setPlaybackRate((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 24: _t->play(); break;
        case 25: _t->pause(); break;
        case 26: _t->togglePause(); break;
        case 27: _t->resume(); break;
        case 28: _t->stop(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)()>(_a, &VlcMediaPlayer::backward, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)(float )>(_a, &VlcMediaPlayer::buffering, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)(int )>(_a, &VlcMediaPlayer::buffering, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)()>(_a, &VlcMediaPlayer::end, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)()>(_a, &VlcMediaPlayer::error, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)()>(_a, &VlcMediaPlayer::forward, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)(int )>(_a, &VlcMediaPlayer::lengthChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)(libvlc_media_t * )>(_a, &VlcMediaPlayer::mediaChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)()>(_a, &VlcMediaPlayer::nothingSpecial, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)()>(_a, &VlcMediaPlayer::opening, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)(bool )>(_a, &VlcMediaPlayer::pausableChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)()>(_a, &VlcMediaPlayer::paused, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)()>(_a, &VlcMediaPlayer::playing, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)(float )>(_a, &VlcMediaPlayer::positionChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)(bool )>(_a, &VlcMediaPlayer::seekableChanged, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)(const QString & )>(_a, &VlcMediaPlayer::snapshotTaken, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)()>(_a, &VlcMediaPlayer::stopped, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)(int )>(_a, &VlcMediaPlayer::timeChanged, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)(int )>(_a, &VlcMediaPlayer::titleChanged, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)(int )>(_a, &VlcMediaPlayer::vout, 19))
            return;
        if (QtMocHelpers::indexOfMethod<void (VlcMediaPlayer::*)()>(_a, &VlcMediaPlayer::stateChanged, 20))
            return;
    }
}

const QMetaObject *VlcMediaPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VlcMediaPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14VlcMediaPlayerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VlcMediaPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void VlcMediaPlayer::backward()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VlcMediaPlayer::buffering(float _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void VlcMediaPlayer::buffering(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void VlcMediaPlayer::end()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void VlcMediaPlayer::error()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void VlcMediaPlayer::forward()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void VlcMediaPlayer::lengthChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void VlcMediaPlayer::mediaChanged(libvlc_media_t * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void VlcMediaPlayer::nothingSpecial()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void VlcMediaPlayer::opening()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void VlcMediaPlayer::pausableChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1);
}

// SIGNAL 11
void VlcMediaPlayer::paused()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void VlcMediaPlayer::playing()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void VlcMediaPlayer::positionChanged(float _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1);
}

// SIGNAL 14
void VlcMediaPlayer::seekableChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 14, nullptr, _t1);
}

// SIGNAL 15
void VlcMediaPlayer::snapshotTaken(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 15, nullptr, _t1);
}

// SIGNAL 16
void VlcMediaPlayer::stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void VlcMediaPlayer::timeChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 17, nullptr, _t1);
}

// SIGNAL 18
void VlcMediaPlayer::titleChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 18, nullptr, _t1);
}

// SIGNAL 19
void VlcMediaPlayer::vout(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 19, nullptr, _t1);
}

// SIGNAL 20
void VlcMediaPlayer::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}
QT_WARNING_POP
