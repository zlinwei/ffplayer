#ifndef FFPLAYER_H
#define FFPLAYER_H

#include <QWidget>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include <QDebug>
#include <QTimer>
#include "videodec.h"
#include <QThread>


namespace Ui {
class Ffplayer;
}

class Ffplayer : public QWidget
{
    Q_OBJECT

public:
    explicit Ffplayer(QWidget *parent = 0);
    ~Ffplayer();
signals:
    void init_s();
    void play_s();

private slots:
    void on_testBtn_clicked();
    void receive(QImage);


private:
    Ui::Ffplayer *ui = NULL;
    VideoDec *videodec = NULL;
    QThread * decthread = NULL;


};

#endif // FFPLAYER_H
