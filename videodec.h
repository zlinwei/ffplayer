#ifndef VIDEODEC_H
#define VIDEODEC_H

extern "C"{
    #include "libavcodec/avcodec.h"
    #include "libavformat/avformat.h"
    #include "libavutil/avutil.h"
    #include "libavutil/mem.h"
    #include "libavutil/fifo.h"
    #include "libswscale/swscale.h"
}
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <QObject>
#include <QImage>
#include <QThread>
#include <QDebug>
#include <QList>

using namespace boost;

class VideoDec : public QObject
{
    Q_OBJECT
public:
    explicit VideoDec(QObject *parent = 0);
    ~VideoDec();

    int videoindex;
    int BUFFSIZE;
    AVFormatContext *pFormatCtx = NULL;
    AVCodecContext *pCodecCtx = NULL;
    AVCodec *pCodec = NULL;
    AVPacket packet;
    AVFrame *pFrame = NULL,*pFrameRGB = NULL;
    char const *filename = "rtmp://...";
    QList<QImage> VideoImg;
    bool loopRun = true;
    bool isRun = false;

signals:
    void SendImage(QImage img);
private slots:
    void init();
    void play();
};

#endif // VIDEODEC_H
