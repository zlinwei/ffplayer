#include "ffplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ffplayer w;
    w.show();

    return a.exec();
}
