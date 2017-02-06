#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T12:26:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ffplayer
TEMPLATE = app

INCLUDEPATH += . /usr/local/include/

SOURCES += main.cpp\
        ffplayer.cpp \
    videodec.cpp \
    videoenc.cpp

HEADERS  += ffplayer.h \
    videodec.h \
    videoenc.h

FORMS    += ffplayer.ui




LIBS += -L/usr/local/lib -L/usr/local/Cellar/x265/2.1/lib -L/usr/local/Cellar/x264/r2708/lib -L/usr/local/Cellar/libvpx/1.6.0/lib -L/usr/local/Cellar/libvidstab/0.98b/lib -L/usr/local/Cellar/speex/1.2rc1/lib -L/usr/local/Cellar/schroedinger/1.0.11/lib -L/usr/local/Cellar/opus/1.1.3/lib -L/usr/local/Cellar/libmodplug/0.8.8.5/lib -L/usr/local/opt/freetype/lib -L/usr/local/Cellar/fontconfig/2.12.1_2/lib -L/usr/local/opt/freetype/lib -L/usr/local/Cellar/libbluray/0.9.3_3/lib -L/usr/local/Cellar/libass/0.13.4/lib -L/usr/local/lib -L/usr/local/Cellar/x265/2.1/lib -L/usr/local/Cellar/x264/r2708/lib -L/usr/local/Cellar/libvpx/1.6.0/lib -L/usr/local/Cellar/libvidstab/0.98b/lib -L/usr/local/Cellar/speex/1.2rc1/lib -L/usr/local/Cellar/schroedinger/1.0.11/lib -L/usr/local/Cellar/opus/1.1.3/lib -L/usr/local/Cellar/libmodplug/0.8.8.5/lib -L/usr/local/opt/freetype/lib -L/usr/local/Cellar/fontconfig/2.12.1_2/lib -L/usr/local/opt/freetype/lib -L/usr/local/Cellar/libbluray/0.9.3_3/lib -L/usr/local/Cellar/libass/0.13.4/lib -L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core -lavformat -framework QuartzCore -framework AppKit -framework OpenGL -framework QuartzCore -framework AppKit -framework OpenGL -framework CoreVideo -framework Foundation -framework AVFoundation -framework CoreMedia -framework CoreFoundation -framework VideoToolbox -framework CoreMedia -framework CoreVideo -framework CoreFoundation -framework AudioToolbox -framework CoreMedia -framework VideoDecodeAcceleration -framework CoreFoundation -framework QuartzCore -liconv -Wl,-framework,CoreFoundation -Wl,-framework,Security -lzmq -lxvidcore -lx265 -lx264 -lwavpack -lvpx -lm -lvpx -lm -lvpx -lm -lvpx -lm -lvorbisenc -lvorbis -logg -lvo-amrwbenc -lvidstab -ltheoraenc -ltheoradec -logg -lspeex -lsoxr -lsnappy -lschroedinger-1.0 -lopus -lopencore-amrwb -lopencore-amrnb -lmp3lame -lmodplug -lgsm -lfreetype -lfontconfig -lfreetype -lbluray -lass -framework CoreGraphics -lm -lbz2 -lz -pthread -framework CoreServices -lavcodec -framework QuartzCore -framework AppKit -framework OpenGL -framework QuartzCore -framework AppKit -framework OpenGL -framework CoreVideo -framework Foundation -framework AVFoundation -framework CoreMedia -framework CoreFoundation -framework VideoToolbox -framework CoreMedia -framework CoreVideo -framework CoreFoundation -framework AudioToolbox -framework CoreMedia -framework VideoDecodeAcceleration -framework CoreFoundation -framework QuartzCore -liconv -Wl,-framework,CoreFoundation -Wl,-framework,Security -lzmq -lxvidcore -lx265 -lx264 -lwavpack -lvpx -lm -lvpx -lm -lvpx -lm -lvpx -lm -lvorbisenc -lvorbis -logg -lvo-amrwbenc -lvidstab -ltheoraenc -ltheoradec -logg -lspeex -lsoxr -lsnappy -lschroedinger-1.0 -lopus -lopencore-amrwb -lopencore-amrnb -lmp3lame -lmodplug -lgsm -lfreetype -lfontconfig -lfreetype -lbluray -lass -framework CoreGraphics -lm -lbz2 -lz -pthread -framework CoreServices -lswresample -lm -lsoxr -lswscale -lm -lavutil -lm
