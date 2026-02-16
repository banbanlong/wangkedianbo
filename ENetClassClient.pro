QT += quick qml

DEFINES += _HAS_AUTO_PTR_ETC
DEFINES += NO_FSEEKO
DEFINES += _CRT_SECURE_NO_WARNINGS
DEFINES += _CRT_NONSTDC_NO_DEPRECATE

INCLUDEPATH += $$PWD/vlc/include
INCLUDEPATH += $$PWD/vlc/include/vlc/plugins
INCLUDEPATH += $$PWD/core
INCLUDEPATH += $$PWD/zlib/include
INCLUDEPATH += $$PWD/
INCLUDEPATH += $$PWD/openssl/include

SOURCES += \
        algorithm.cpp \
        core/AbstractVideoFrame.cpp \
        core/AbstractVideoStream.cpp \
        core/Audio.cpp \
        core/Common.cpp \
        core/Enums.cpp \
        core/Equalizer.cpp \
        core/Error.cpp \
        core/Instance.cpp \
        core/Media.cpp \
        core/MediaList.cpp \
        core/MediaListPlayer.cpp \
        core/MediaPlayer.cpp \
        core/MetaManager.cpp \
        core/ModuleDescription.cpp \
        core/RGBVideoFrame.cpp \
        core/TrackModel.cpp \
        core/Video.cpp \
        core/VideoFrame.cpp \
        core/VideoMemoryStream.cpp \
        core/VideoStream.cpp \
        core/YUVVideoFrame.cpp \
        core/asprintf.c \
        core/vasprintf.c \
        edoyunvideo.cpp \
        enetwork.cpp \
        main.cpp


QML_SOURCES = main.qml \
        ESplashScreen.qml \
        ELoginWindow.qml \
        ELoginButton.qml \
        EPlayerWindow.qml \
        ETitlebar.qml \
        EHandset.qml \
        ELessionList.qml \
        ESqlite3.qml


# 后续的qml文件，需要手动添加到此处！！！
resources.files = $${QML_SOURCES}

resources.prefix = /$${TARGET}
RESOURCES += resources \
    res.qrc

TRANSLATIONS += \
    ENetClassClient_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations
CONFIG += qmltypes
QML_IMPORT_NAME=Edoyun
QML_IMPORT_MAJOR_VERSION = 1
QML_IMPORT_MINOR_VERSION = 0
INCLUDEPATH+=/build/Desktop_Qt_6_10_0_MSVC2022_64bit-Debug/
#引入第三方库
win32{
    msvc{
        CONFIG(debug,debug|release){
            # 调试模式
            LIBS += -L$$PWD/vlc/lib -L"C:/Program Files (x86)/Windows Kits/10/Lib/10.0.22000.0/um/x64"
            LIBS += -L$$PWD/openssl/x64/lib -L$$PWD/zlib/lib
            LIBS += -llibvlc -llibvlccore
            LIBS += -llibcrypto_static -llibssl_static -lWS2_32 -lAdvapi32 -lUser32 -lCrypt32
            LIBS += -lzlibstaticd
        } else {
            # 其他模式
            LIBS += -L$$PWD/vlc/lib -L"C:/Program Files (x86)/Windows Kits/10/Lib/10.0.22000.0/um/x64"
            LIBS += -L$$PWD/openssl/x64/lib -L$$PWD/zlib/lib
            LIBS += -llibvlc -llibvlccore
            LIBS += -llibcrypto_static -llibssl_static -lWS2_32 -lAdvapi32 -lUser32 -lCrypt32
            LIBS += -lzlibstatic
        }
    }
}


# 项目文件
DISTFILES += $${QML_SOURCES} \





# C/C++ 的头文件
HEADERS += \
    algorithm.h \
    core/AbstractVideoFrame.h \
    core/AbstractVideoStream.h \
    core/Audio.h \
    core/Common.h \
    core/Enums.h \
    core/Equalizer.h \
    core/Error.h \
    core/Instance.h \
    core/Media.h \
    core/MediaList.h \
    core/MediaListPlayer.h \
    core/MediaPlayer.h \
    core/MetaManager.h \
    core/ModuleDescription.h \
    core/RGBVideoFrame.h \
    core/SharedExportCore.h \
    core/Stats.h \
    core/TrackModel.h \
    core/Video.h \
    core/VideoDelegate.h \
    core/VideoFrame.h \
    core/VideoMemoryStream.h \
    core/VideoStream.h \
    core/YUVVideoFrame.h \
    core/asprintf.h \
    edoyunvideo.h \
    enetwork.h


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
