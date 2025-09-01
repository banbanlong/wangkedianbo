/****************************************************************************
** Meta object code from reading C++ file 'edoyunvideo.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../edoyunvideo.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'edoyunvideo.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11EdoyunVideoE_t {};
} // unnamed namespace

template <> constexpr inline auto EdoyunVideo::qt_create_metaobjectdata<qt_meta_tag_ZN11EdoyunVideoE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "EdoyunVideo",
        "QML.Element",
        "auto",
        "volumeChanged",
        "",
        "positionChanged",
        "urlChanged",
        "seekableChanged",
        "autoplayChanged",
        "frameDone",
        "getCurTime",
        "getMaxTime",
        "play",
        "pause",
        "stop",
        "autoplay",
        "volume",
        "position",
        "url",
        "status",
        "seekable"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'volumeChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'positionChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'urlChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'seekableChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'autoplayChanged'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'frameDone'
        QtMocHelpers::SignalData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'getCurTime'
        QtMocHelpers::MethodData<QString()>(10, 4, QMC::AccessPublic, QMetaType::QString),
        // Method 'getMaxTime'
        QtMocHelpers::MethodData<QString()>(11, 4, QMC::AccessPublic, QMetaType::QString),
        // Method 'play'
        QtMocHelpers::MethodData<void()>(12, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'pause'
        QtMocHelpers::MethodData<void()>(13, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'stop'
        QtMocHelpers::MethodData<void()>(14, 4, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'autoplay'
        QtMocHelpers::PropertyData<bool>(15, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'volume'
        QtMocHelpers::PropertyData<int>(16, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'position'
        QtMocHelpers::PropertyData<qreal>(17, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'url'
        QtMocHelpers::PropertyData<QUrl>(18, QMetaType::QUrl, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'status'
        QtMocHelpers::PropertyData<int>(19, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'seekable'
        QtMocHelpers::PropertyData<bool>(20, QMetaType::Bool, QMC::DefaultPropertyFlags, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<EdoyunVideo, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject EdoyunVideo::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11EdoyunVideoE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11EdoyunVideoE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11EdoyunVideoE_t>.metaTypes,
    nullptr
} };

void EdoyunVideo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<EdoyunVideo *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->volumeChanged(); break;
        case 1: _t->positionChanged(); break;
        case 2: _t->urlChanged(); break;
        case 3: _t->seekableChanged(); break;
        case 4: _t->autoplayChanged(); break;
        case 5: _t->frameDone(); break;
        case 6: { QString _r = _t->getCurTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->getMaxTime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->play(); break;
        case 9: _t->pause(); break;
        case 10: _t->stop(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (EdoyunVideo::*)()>(_a, &EdoyunVideo::volumeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (EdoyunVideo::*)()>(_a, &EdoyunVideo::positionChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (EdoyunVideo::*)()>(_a, &EdoyunVideo::urlChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (EdoyunVideo::*)()>(_a, &EdoyunVideo::seekableChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (EdoyunVideo::*)()>(_a, &EdoyunVideo::autoplayChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (EdoyunVideo::*)()>(_a, &EdoyunVideo::frameDone, 5))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->autoplay(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->volume(); break;
        case 2: *reinterpret_cast<qreal*>(_v) = _t->position(); break;
        case 3: *reinterpret_cast<QUrl*>(_v) = _t->url(); break;
        case 4: *reinterpret_cast<int*>(_v) = _t->status(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->seekable(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAutoplay(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setVolume(*reinterpret_cast<int*>(_v)); break;
        case 2: _t->setPosition(*reinterpret_cast<qreal*>(_v)); break;
        case 3: _t->setUrl(*reinterpret_cast<QUrl*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *EdoyunVideo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EdoyunVideo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11EdoyunVideoE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "VlcVideoMemoryStream"))
        return static_cast< VlcVideoMemoryStream*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int EdoyunVideo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void EdoyunVideo::volumeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void EdoyunVideo::positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void EdoyunVideo::urlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void EdoyunVideo::seekableChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void EdoyunVideo::autoplayChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void EdoyunVideo::frameDone()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
