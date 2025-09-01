#ifndef EDOYUNVIDEO_H
#define EDOYUNVIDEO_H

#include <QQuickItem>
#include <QSGTexture>
#include <QImage>
#include <QSGNode>
#include <QMutex>
#include "Instance.h"
#include "Video.h"
#include "Audio.h"
#include "Media.h"
#include "VideoMemoryStream.h"

class EdoyunVideo : public QQuickItem,public VlcVideoMemoryStream
{
    Q_OBJECT
    Q_PROPERTY(bool autoplay READ autoplay WRITE setAutoplay NOTIFY autoplayChanged)
    Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(qreal position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(int status READ status CONSTANT)
    Q_PROPERTY(bool seekable READ seekable NOTIFY seekableChanged)
    QML_ELEMENT
signals:
    void volumeChanged();
    void positionChanged();
    void urlChanged();
    void seekableChanged();
    void autoplayChanged();
    void frameDone();
public:
    int volume() const;
    void setVolume(int volume);
    qreal position()const;
    void setPosition(qreal position);
    QUrl url() const;
    void setUrl(const QUrl& url);
    int status() const;
    bool seekable() const;
    bool autoplay() const;
    void setAutoplay(bool autoplay);
public:
    Q_INVOKABLE QString getCurTime();
    Q_INVOKABLE QString getMaxTime();
    Q_INVOKABLE void play();
    Q_INVOKABLE void pause();
    Q_INVOKABLE void stop();
public:
    EdoyunVideo(QQuickItem* parent = nullptr);
    ~EdoyunVideo();
protected://OPENGL需要重载的方法（用于画面显示）
    QSGNode* updatePaintNode(QSGNode*,UpdatePaintNodeData*)override;
    void geometryChange(const QRectF& newGeometry, const QRectF& oldGeometry) override;
    virtual void *lockCallback(void** planes) override;
    virtual void unlockCallback(void* picture,void *const *planes)override;
    virtual void displayCallback(void* picture)override;
    virtual unsigned formatCallback(char* chroma,unsigned* width, unsigned* height,
                                    unsigned* pitches, unsigned* lines)override;
    virtual void formatCleanUpCallback() override;
    virtual void releaseResources() override;
private:
    int m_volume;//音量
    qreal m_position;//播放进度
    QUrl m_url;//播放地址
    int m_status;//播放状态
    bool m_seekable;//能否修改进度
    bool m_autoplay;//是否自动播放
    //vlc相关的参数
    VlcInstance* m_instance;
    VlcVideo* m_video;
    VlcAudio* m_audio;
    VlcMedia* m_media;
    VlcMediaPlayer* m_player;
    //OPENGL渲染
    QSGTexture* m_texture;
    QImage m_frame;
    QMutex m_mutex;
    QByteArray m_buffer;
    bool m_paintDone;
    QSize m_size;
};

#endif // EDOYUNVIDEO_H
