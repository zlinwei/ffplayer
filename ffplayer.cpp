#include "ffplayer.h"
#include "ui_ffplayer.h"



using namespace boost;

Ffplayer::Ffplayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ffplayer)
{
    decthread = new QThread(this);
    videodec = new VideoDec();

    videodec->moveToThread(decthread);
    decthread->start();

    connect(this,SIGNAL(init_s()),videodec,SLOT(init()));
    connect(this,SIGNAL(play_s()),videodec,SLOT(play()));


    connect(videodec,SIGNAL(SendImage(QImage)),this,SLOT(receive(QImage)));

    qDebug()<<"初始化完成....";
    ui->setupUi(this);
}

Ffplayer::~Ffplayer()
{
    qDebug()<<"~Ffplayer";
    videodec->loopRun = false;
//    QThread::msleep(3000);
    while(videodec->isRun)
    {
        QThread::msleep(1);
    }
    decthread->exit();

    delete videodec;
    delete decthread;



    delete ui;

}

void Ffplayer::on_testBtn_clicked()
{
    ui->VideoShow->setText("正在初始化.....");
    emit init_s();

}


void Ffplayer::receive(QImage qimage)
{
     QPixmap pix;
     pix = pix.fromImage(qimage);

     ui->VideoShow->setPixmap(pix);
}


