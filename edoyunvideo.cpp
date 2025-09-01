#include "edoyunvideo.h"
#include "Common.h"
#include "MediaPlayer.h"
#include <QSGSimpleTextureNode>
#include <QSGFlatColorMaterial>

int EdoyunVideo::volume() const
{
    return m_audio->volume();
}

void EdoyunVideo::setVolume(int volume)
{
    m_audio->setVolume(volume);
    emit volumeChanged();
}

qreal EdoyunVideo::position() const
{
    return m_player->position();
}

void EdoyunVideo::setPosition(qreal position)
{
    qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<"position:"<<position;
    qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<"position:"<<m_player->position();
    m_player->setPosition(position);
    qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<"position:"<<m_player->position();
}

QUrl EdoyunVideo::url() const
{
    if(m_media) return QUrl(m_media->currentLocation());
    return QUrl();
}

void EdoyunVideo::setUrl(const QUrl &url)
{
    m_player->stop();
    if(m_media){
        m_media->deleteLater();
    }
    if(url.isLocalFile()){
        m_media = new VlcMedia(url.toLocalFile(),true,m_instance);
    }else{
        m_media = new VlcMedia(url.toString(QUrl::FullyEncoded),false,m_instance);
    }
    //qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<"m_autoplay:"<<m_autoplay;
    //qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<"m_media:"<<m_media;
    //qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<"m_player:"<<m_player;
    //qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<"isLocalFile:"<<url.isLocalFile();
    if(m_autoplay){
        m_player->open(m_media);
    }else{
        m_player->openOnly(m_media);
    }

    setCallbacks(m_player);
}
/*
        Idle, 0
        Opening, 1
        Buffering, 2
        Playing, 3
        Paused, 4
        Stopped, 5
        Ended, 6
        Error 7
*/
int EdoyunVideo::status() const
{
    return m_player->state();
}

bool EdoyunVideo::seekable() const
{
    return m_player->seekable();
}

bool EdoyunVideo::autoplay() const
{
    return m_autoplay;
}

void EdoyunVideo::setAutoplay(bool autoplay)
{
    qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<"m_autoplay:"<<m_autoplay;
    m_autoplay = autoplay;
    qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<"m_autoplay:"<<m_autoplay;
}

QString EdoyunVideo::getCurTime()
{
    qint64 t = m_player->time();
    t/=1000;
    qlonglong sec = t%60;
    t/=60;
    qlonglong min = t%60;
    t/=60;
    qlonglong hour = t;
    return QString("%1:%2:%3").
        arg(hour,2,10,QChar('0')).
        arg(min,2,10,QChar('0')).
        arg(sec,2,10,QChar('0'));
}

QString EdoyunVideo::getMaxTime()
{
    qint64 t = m_player->length();
    t/=1000;
    qlonglong sec = t%60;
    t/=60;
    qlonglong min = t%60;
    t/=60;
    qlonglong hour = t;
    return QString("%1:%2:%3").
        arg(hour,2,10,QChar('0')).
        arg(min,2,10,QChar('0')).
        arg(sec,2,10,QChar('0'));
}

void EdoyunVideo::play()
{
    m_player->play();
    if(m_player->state()!=Vlc::Paused)
        setCallbacks(m_player);
}

void EdoyunVideo::pause()
{
    m_player->pause();
}

void EdoyunVideo::stop()
{
    m_player->stop();
    unsetCallbacks(m_player);
    m_frame = QImage(width(),height(),QImage::Format_RGB32);
    m_frame.fill(QColor(Qt::black));
    update();
}

EdoyunVideo::EdoyunVideo(QQuickItem *parent)
    : QQuickItem(parent)
    , m_volume(50)
    , m_position(0)
    , m_status(0)
    , m_seekable(true)
    , m_autoplay(false)
    , m_instance(nullptr)
    , m_video(nullptr)
    , m_audio(nullptr)
    , m_media(nullptr)
    , m_player(nullptr)
    , m_texture(nullptr)
    , m_frame(width(),height(),QImage::Format_RGB32)
    , m_paintDone(false)
    , m_size(0, 0)
{
    setFlag(ItemHasContents, true);
    m_instance = new VlcInstance(VlcCommon::args(),this);
    m_instance->setUserAgent(qApp->applicationName(),qApp->applicationVersion());
    m_player = new VlcMediaPlayer(m_instance);
    m_audio = new VlcAudio(m_player);
    m_video = new VlcVideo(m_player);

    connect(this,&EdoyunVideo::frameDone,this,&EdoyunVideo::update,Qt::QueuedConnection);
    //connect(m_player,&VlcMediaPlayer::stateChanged,this,&EdoyunVideo::statusChanged);
    connect(m_player,&VlcMediaPlayer::positionChanged,this,&EdoyunVideo::positionChanged);
    connect(m_player,&VlcMediaPlayer::seekableChanged,this,&EdoyunVideo::seekableChanged);

    m_frame.fill(QColor(Qt::black));
}

EdoyunVideo::~EdoyunVideo()
{
    if(m_player){
        m_player->stop();
    }
    if(m_audio){
        delete m_audio;
        m_audio = nullptr;
    }
    if(m_video){
        delete m_video;
        m_video = nullptr;
    }
    if(m_media){
        delete m_media;
        m_media = nullptr;
    }
    if(m_player){
        delete m_player;
        m_player = nullptr;
    }
    if(m_instance){
        delete m_instance;
        m_instance = nullptr;
    }
}

QSGNode *EdoyunVideo::updatePaintNode(QSGNode *node, UpdatePaintNodeData *)
{
    QSGGeometryNode* geoNode = dynamic_cast<QSGGeometryNode*>(node);
    QSGGeometry* geometry = NULL;
    int area = (int)(width()*height());
    if(geoNode==nullptr){
        geoNode = new QSGGeometryNode();
        geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(),6);
        geometry->setDrawingMode(QSGGeometry::DrawTriangles);
        geoNode->setGeometry(geometry);
        geoNode->setFlag(QSGGeometryNode::OwnsGeometry);

        QSGSimpleTextureNode* texture = new QSGSimpleTextureNode;
        if(m_texture){
            QSGTexture* tmp = m_texture;
            m_texture = nullptr;
            delete tmp;
        }
        if(m_frame.isNull()){
            m_frame = QImage(width(),height(),QImage::Format_RGB32);
            m_frame.fill(QColor(Qt::black));
        }
        if(m_frame.width()*m_frame.height()!=area){
            m_frame=m_frame.scaled(width(),height());
        }
        m_texture = window()->createTextureFromImage(m_frame);
        if(m_paintDone)m_paintDone=false;
        texture->setTexture(m_texture);
        m_texture->setHorizontalWrapMode(QSGTexture::ClampToEdge);
        m_texture->setVerticalWrapMode(QSGTexture::ClampToEdge);
        texture->setRect(0,0,width(),height());
        texture->setFiltering(QSGTexture::Nearest);
        geoNode->appendChildNode(texture);
        QSGFlatColorMaterial* m = new QSGFlatColorMaterial;
        m->setColor(QColor(Qt::transparent));
        geoNode->setMaterial(m);
    }else{
        geometry = geoNode->geometry();
        geometry->allocate(6);
        QSGSimpleTextureNode* texture = (QSGSimpleTextureNode*)geoNode->childAtIndex(0);
        if(m_texture){
            QSGTexture* tmp = m_texture;
            m_texture = nullptr;
            delete tmp;
        }
        if(m_frame.isNull()){
            m_frame = QImage(width(),height(),QImage::Format_RGB32);
            m_frame.fill(QColor(Qt::black));
        }
        if(m_frame.width()*m_frame.height()!=area){
            m_frame=m_frame.scaled(width(),height());
        }
        m_texture = window()->createTextureFromImage(m_frame);
        if(m_paintDone)m_paintDone=false;
        texture->setTexture(m_texture);
        m_texture->setHorizontalWrapMode(QSGTexture::ClampToEdge);
        m_texture->setVerticalWrapMode(QSGTexture::ClampToEdge);
        texture->setRect(0,0,width(),height());
        texture->setFiltering(QSGTexture::Nearest);
    }
    QSGGeometry::Point2D* points = geometry->vertexDataAsPoint2D();
    float w = (float)width();
    float h = (float)height();
    float pts[6][2]{
        {0,0},{w,0},{w,h},
        {w,h},{0,h},{0,0}
    };
    for(int i=0;i<6;i++)points[i].set(pts[i][0],pts[i][1]);
    return geoNode;
}

void EdoyunVideo::geometryChange(const QRectF &/*newGeometry*/, const QRectF &/*oldGeometry*/)
{
    qreal area = width()*height();
    if(area>0){
        if(m_frame.isNull()==false){
            if(m_frame.width()*m_frame.height()!=int(area)){
                m_frame = m_frame.scaled(width(),height());
            }
        }
    }
}

void *EdoyunVideo::lockCallback(void **planes)
{
    m_mutex.lock();
    *planes = m_buffer.data();
    return 0;
}

void EdoyunVideo::unlockCallback(void */*picture*/, void * const *planes)
{
    unsigned char* data = static_cast<unsigned char*>(*planes);
    if(m_paintDone==false){
        //qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<"width:"<<m_size.width();
        //qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<"height:"<<m_size.height();
        m_frame = QImage(data,m_size.width(),m_size.height(),QImage::Format_RGB32);
        m_paintDone = true;
    }
    m_mutex.unlock();
    //不一定在qml ui线程当中 不能直接调用update()
    emit frameDone();
}

void EdoyunVideo::displayCallback(void */*picture*/)
{}

unsigned int EdoyunVideo::formatCallback(char *chroma,
                                         unsigned int *width, unsigned int *height,
                                         unsigned int *pitches, unsigned int *lines
                                         )
{
    qstrcpy(chroma,"RV32");
    qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<"width:"<<*width;
    qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<"height:"<<*height;
    m_size = QSize(*width,*height);
    qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<"width:"<<m_size.width();
    qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<"height:"<<m_size.height();
    *pitches = (*width)*4;
    *lines = (*height);
    m_buffer.resize((*pitches)*(*lines));
    qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<"buffer size:"<<m_buffer.size();
    return (*pitches)*(*lines);
}

void EdoyunVideo::formatCleanUpCallback()
{
}

void EdoyunVideo::releaseResources()
{
    m_player->stop();
    if(m_texture){
        QSGTexture* temp = m_texture;
        m_texture = nullptr;
        delete temp;
    }
}
