#include "videodec.h"


VideoDec::VideoDec(QObject *parent) : QObject(parent)
{

}

VideoDec::~VideoDec(){
    qDebug()<<"~VideoDec";

    this->loopRun = false;
//    avcodec_free_context(&pCodecCtx);

    qDebug()<<"pcodec ctx"<<pCodecCtx;
    qDebug()<<"pfomat ctx"<<pFormatCtx;
    qDebug()<<"packet "<<&packet;

    qDebug()<<"close function invoked";

    av_frame_free(&pFrameRGB);
    av_frame_free(&pFrame);
    avcodec_close(pCodecCtx);
    avformat_close_input(&pFormatCtx);
    avformat_free_context(pFormatCtx);
    qDebug()<<"pcodec ctx"<<pCodecCtx;
    qDebug()<<"pfomat ctx"<<pFormatCtx;

}


void VideoDec::init()
{
     qDebug()<<"init";
     qDebug()<<pFormatCtx;

     BUFFSIZE = 0;
     avformat_network_init();
     qDebug()<<"network init";
     avcodec_register_all();
     qDebug()<<"codec register all";
     av_register_all();
     qDebug()<<"register all";
     pFormatCtx = avformat_alloc_context();
     qDebug()<<pFormatCtx;
     qDebug()<<"format alloc context";
     qDebug()<<"pCodeCtx:"<<pCodecCtx;
     pCodecCtx = avcodec_alloc_context3(pCodec);
     qDebug()<<"pCodeCtx:"<<pCodecCtx;
     qDebug()<<"codec alloc context";

     if(avformat_open_input(&pFormatCtx,filename,NULL,NULL)!=0){
         qDebug()<<"OpenFail";
     }
     if(avformat_find_stream_info(pFormatCtx,NULL)<0){
         qDebug()<<"FindFail";
     }
     videoindex = -1;
     for(int i=0;pFormatCtx->nb_streams;i++){
         if(pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO){
             videoindex = i;
             break;
         }
     }

     if(videoindex == -1){
         qDebug()<<"Din't find video stream";
     }
     pCodecCtx = pFormatCtx->streams[videoindex]->codec;
     pCodec = avcodec_find_decoder(pCodecCtx->codec_id);
     qDebug()<<"av codec find";
     if(pCodec == NULL){
         qDebug()<<"codec not find";
     }
     if(avcodec_open2(pCodecCtx,pCodec,NULL)<0){
         qDebug()<<"can't open codec";
     }

     pFrame = av_frame_alloc();
     pFrameRGB = av_frame_alloc();
     qDebug()<<"av frame alloc";
     play();
}

void VideoDec::play()
{
    qDebug()<<"play";
    int got_picture;
    av_new_packet(&packet, pCodecCtx->width*pCodecCtx->height);
    uint8_t *out_buffer;
        out_buffer = new uint8_t[avpicture_get_size(AV_PIX_FMT_RGB32, pCodecCtx->width, pCodecCtx->height)];//分配AVFrame所需内存
        avpicture_fill((AVPicture *)pFrameRGB, out_buffer, AV_PIX_FMT_RGB32, pCodecCtx->width, pCodecCtx->height);//填充AVFrame
        avpicture_fill((AVPicture *)pFrame, out_buffer, AV_PIX_FMT_RGB32, pCodecCtx->width, pCodecCtx->height);//填充AVFrame
        while(loopRun){
            isRun = true;
            QThread::msleep(1);
//            if(BUFFSIZE>51) continue;
            if(av_read_frame(pFormatCtx,&packet)<0) break;
            if(packet.stream_index == videoindex){
                int rec = avcodec_decode_video2(pCodecCtx,pFrame,&got_picture,&packet);
                if(rec>0){
                                SwsContext *convertCtx = sws_getContext(pCodecCtx->width,pCodecCtx->height
                                                                        ,pCodecCtx->pix_fmt,pCodecCtx->width,pCodecCtx->height
                                                                        ,AV_PIX_FMT_RGB32,SWS_BICUBIC,NULL,NULL,NULL);
                                sws_scale(convertCtx,(const uint8_t*  const*)pFrame->data,pFrame->linesize,0
                                          ,pCodecCtx->height,pFrameRGB->data,pFrameRGB->linesize);
                                QImage Img((uchar *)pFrameRGB->data[0],pCodecCtx->width,pCodecCtx->height,QImage::Format_RGB32);
//                                VideoImg.append(Img.copy());
                                BUFFSIZE++;
                                emit SendImage(Img.copy());

                                sws_freeContext(convertCtx);
                }

            }

        }

    isRun = false;
    qDebug()<<"while-loop stoped";
    delete out_buffer;
}


