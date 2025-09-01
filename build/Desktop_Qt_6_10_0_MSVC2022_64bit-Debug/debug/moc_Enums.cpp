/****************************************************************************
** Meta object code from reading C++ file 'Enums.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../core/Enums.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Enums.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN3VlcE_t {};
} // unnamed namespace

template <> constexpr inline auto Vlc::qt_create_metaobjectdata<qt_meta_tag_ZN3VlcE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Vlc",
        "LogLevel",
        "DebugLevel",
        "NoticeLevel",
        "WarningLevel",
        "ErrorLevel",
        "DisabledLevel",
        "ActionsType",
        "AudioTrack",
        "Subtitles",
        "VideoTrack",
        "Other",
        "AudioChannel",
        "AudioChannelError",
        "Stereo",
        "RStereo",
        "Left",
        "Right",
        "Dolbys",
        "AudioCodec",
        "NoAudio",
        "MPEG2Audio",
        "MP3",
        "MPEG4Audio",
        "Vorbis",
        "Flac",
        "AudioOutput",
        "DefaultAout",
        "Deinterlacing",
        "Disabled",
        "Discard",
        "Blend",
        "Mean",
        "Bob",
        "Linear",
        "X",
        "Yadif",
        "Yadif2x",
        "Phospor",
        "IVTC",
        "FillMode",
        "PreserveAspectFit",
        "PreserveAspectCrop",
        "Stretch",
        "Meta",
        "Title",
        "Artist",
        "Genre",
        "Copyright",
        "Album",
        "TrackNumber",
        "Description",
        "Rating",
        "Date",
        "Setting",
        "URL",
        "Language",
        "NowPlaying",
        "Publisher",
        "EncodedBy",
        "ArtworkURL",
        "TrackID",
        "Mux",
        "TS",
        "PS",
        "MP4",
        "OGG",
        "AVI",
        "PlaybackMode",
        "DefaultPlayback",
        "Loop",
        "Repeat",
        "Ratio",
        "Original",
        "Ignore",
        "R_16_9",
        "R_16_10",
        "R_185_100",
        "R_221_100",
        "R_235_100",
        "R_239_100",
        "R_4_3",
        "R_5_4",
        "R_5_3",
        "R_1_1",
        "Scale",
        "NoScale",
        "S_1_05",
        "S_1_1",
        "S_1_2",
        "S_1_3",
        "S_1_4",
        "S_1_5",
        "S_1_6",
        "S_1_7",
        "S_1_8",
        "S_1_9",
        "S_2_0",
        "State",
        "Idle",
        "Opening",
        "Buffering",
        "Playing",
        "Paused",
        "Stopped",
        "Ended",
        "Error",
        "VideoCodec",
        "NoVideo",
        "MPEG2Video",
        "MPEG4Video",
        "H264",
        "Theora",
        "VideoOutput",
        "DirectX",
        "Direct3D",
        "OpenGL",
        "DefaultVout"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'LogLevel'
        QtMocHelpers::EnumData<LogLevel>(1, 1, QMC::EnumFlags{}).add({
            {    2, LogLevel::DebugLevel },
            {    3, LogLevel::NoticeLevel },
            {    4, LogLevel::WarningLevel },
            {    5, LogLevel::ErrorLevel },
            {    6, LogLevel::DisabledLevel },
        }),
        // enum 'ActionsType'
        QtMocHelpers::EnumData<ActionsType>(7, 7, QMC::EnumFlags{}).add({
            {    8, ActionsType::AudioTrack },
            {    9, ActionsType::Subtitles },
            {   10, ActionsType::VideoTrack },
            {   11, ActionsType::Other },
        }),
        // enum 'AudioChannel'
        QtMocHelpers::EnumData<AudioChannel>(12, 12, QMC::EnumFlags{}).add({
            {   13, AudioChannel::AudioChannelError },
            {   14, AudioChannel::Stereo },
            {   15, AudioChannel::RStereo },
            {   16, AudioChannel::Left },
            {   17, AudioChannel::Right },
            {   18, AudioChannel::Dolbys },
        }),
        // enum 'AudioCodec'
        QtMocHelpers::EnumData<AudioCodec>(19, 19, QMC::EnumFlags{}).add({
            {   20, AudioCodec::NoAudio },
            {   21, AudioCodec::MPEG2Audio },
            {   22, AudioCodec::MP3 },
            {   23, AudioCodec::MPEG4Audio },
            {   24, AudioCodec::Vorbis },
            {   25, AudioCodec::Flac },
        }),
        // enum 'AudioOutput'
        QtMocHelpers::EnumData<AudioOutput>(26, 26, QMC::EnumFlags{}).add({
            {   27, AudioOutput::DefaultAout },
        }),
        // enum 'Deinterlacing'
        QtMocHelpers::EnumData<Deinterlacing>(28, 28, QMC::EnumFlags{}).add({
            {   29, Deinterlacing::Disabled },
            {   30, Deinterlacing::Discard },
            {   31, Deinterlacing::Blend },
            {   32, Deinterlacing::Mean },
            {   33, Deinterlacing::Bob },
            {   34, Deinterlacing::Linear },
            {   35, Deinterlacing::X },
            {   36, Deinterlacing::Yadif },
            {   37, Deinterlacing::Yadif2x },
            {   38, Deinterlacing::Phospor },
            {   39, Deinterlacing::IVTC },
        }),
        // enum 'FillMode'
        QtMocHelpers::EnumData<FillMode>(40, 40, QMC::EnumFlags{}).add({
            {   41, FillMode::PreserveAspectFit },
            {   42, FillMode::PreserveAspectCrop },
            {   43, FillMode::Stretch },
        }),
        // enum 'Meta'
        QtMocHelpers::EnumData<Meta>(44, 44, QMC::EnumFlags{}).add({
            {   45, Meta::Title },
            {   46, Meta::Artist },
            {   47, Meta::Genre },
            {   48, Meta::Copyright },
            {   49, Meta::Album },
            {   50, Meta::TrackNumber },
            {   51, Meta::Description },
            {   52, Meta::Rating },
            {   53, Meta::Date },
            {   54, Meta::Setting },
            {   55, Meta::URL },
            {   56, Meta::Language },
            {   57, Meta::NowPlaying },
            {   58, Meta::Publisher },
            {   59, Meta::EncodedBy },
            {   60, Meta::ArtworkURL },
            {   61, Meta::TrackID },
        }),
        // enum 'Mux'
        QtMocHelpers::EnumData<Mux>(62, 62, QMC::EnumFlags{}).add({
            {   63, Mux::TS },
            {   64, Mux::PS },
            {   65, Mux::MP4 },
            {   66, Mux::OGG },
            {   67, Mux::AVI },
        }),
        // enum 'PlaybackMode'
        QtMocHelpers::EnumData<PlaybackMode>(68, 68, QMC::EnumFlags{}).add({
            {   69, PlaybackMode::DefaultPlayback },
            {   70, PlaybackMode::Loop },
            {   71, PlaybackMode::Repeat },
        }),
        // enum 'Ratio'
        QtMocHelpers::EnumData<Ratio>(72, 72, QMC::EnumFlags{}).add({
            {   73, Ratio::Original },
            {   74, Ratio::Ignore },
            {   75, Ratio::R_16_9 },
            {   76, Ratio::R_16_10 },
            {   77, Ratio::R_185_100 },
            {   78, Ratio::R_221_100 },
            {   79, Ratio::R_235_100 },
            {   80, Ratio::R_239_100 },
            {   81, Ratio::R_4_3 },
            {   82, Ratio::R_5_4 },
            {   83, Ratio::R_5_3 },
            {   84, Ratio::R_1_1 },
        }),
        // enum 'Scale'
        QtMocHelpers::EnumData<Scale>(85, 85, QMC::EnumFlags{}).add({
            {   86, Scale::NoScale },
            {   87, Scale::S_1_05 },
            {   88, Scale::S_1_1 },
            {   89, Scale::S_1_2 },
            {   90, Scale::S_1_3 },
            {   91, Scale::S_1_4 },
            {   92, Scale::S_1_5 },
            {   93, Scale::S_1_6 },
            {   94, Scale::S_1_7 },
            {   95, Scale::S_1_8 },
            {   96, Scale::S_1_9 },
            {   97, Scale::S_2_0 },
        }),
        // enum 'State'
        QtMocHelpers::EnumData<State>(98, 98, QMC::EnumFlags{}).add({
            {   99, State::Idle },
            {  100, State::Opening },
            {  101, State::Buffering },
            {  102, State::Playing },
            {  103, State::Paused },
            {  104, State::Stopped },
            {  105, State::Ended },
            {  106, State::Error },
        }),
        // enum 'VideoCodec'
        QtMocHelpers::EnumData<VideoCodec>(107, 107, QMC::EnumFlags{}).add({
            {  108, VideoCodec::NoVideo },
            {  109, VideoCodec::MPEG2Video },
            {  110, VideoCodec::MPEG4Video },
            {  111, VideoCodec::H264 },
            {  112, VideoCodec::Theora },
        }),
        // enum 'VideoOutput'
        QtMocHelpers::EnumData<VideoOutput>(113, 113, QMC::EnumFlags{}).add({
            {  114, VideoOutput::DirectX },
            {  115, VideoOutput::Direct3D },
            {  116, VideoOutput::OpenGL },
            {  117, VideoOutput::DefaultVout },
        }),
    };
    return QtMocHelpers::metaObjectData<Vlc, qt_meta_tag_ZN3VlcE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Vlc::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN3VlcE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN3VlcE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN3VlcE_t>.metaTypes,
    nullptr
} };

void Vlc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Vlc *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *Vlc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Vlc::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN3VlcE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Vlc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
