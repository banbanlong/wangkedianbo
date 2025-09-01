/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<edoyunvideo.h>)
#  include <edoyunvideo.h>
#endif
#if __has_include(<enetwork.h>)
#  include <enetwork.h>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_Edoyun()
{
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<ENetwork>("Edoyun", 1);
    qmlRegisterTypesAndRevisions<EdoyunVideo>("Edoyun", 1);
    QT_WARNING_POP
    qmlRegisterModule("Edoyun", 1, 0);
}

static const QQmlModuleRegistration edoyunRegistration("Edoyun", qml_register_types_Edoyun);
