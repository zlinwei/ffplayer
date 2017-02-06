#ifndef VIDEOENC_H
#define VIDEOENC_H

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

class videoenc : public QObject
{
    Q_OBJECT
public:
    explicit videoenc(QObject *parent = 0);

signals:

public slots:
};

#endif // VIDEOENC_H
