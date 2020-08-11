QT += widgets
requires(qtConfig(filedialog))
qtHaveModule(printsupport): QT += printsupport
QMAKE_CXXFLAGS+= -openmp

HEADERS       = mainwindow.h \
                acedialog.h \
                blurdialog.h \
                closedialog.h \
                cooldialog.h \
                dilationdialog.h \
                embossfilterdialog.h \
                erosiondialog.h \
                fdfilterdialog.h \
                fftw3.h \
                floatslider.h \
                imageprocess.h \
                mdichild.h \
                opendialog.h \
                padding.h \
                saturationdialog.h \
                sdfilterdialog.h \
                sharpendialog.h \
                transform.h \
                warmdialog.h
SOURCES       = main.cpp \
                acedialog.cpp \
                blurdialog.cpp \
                closedialog.cpp \
                cooldialog.cpp \
                dilationdialog.cpp \
                embossfilterdialog.cpp \
                erosiondialog.cpp \
                fdfilterdialog.cpp \
                imagepocess.cpp \
                mainwindow.cpp \
                mdichild.cpp \
                opendialog.cpp \
                padding.cpp \
                saturationdialog.cpp \
                sdfilterdialog.cpp \
                sharpendialog.cpp \
                transform.cpp \
                warmdialog.cpp
RESOURCES     = \
    dip.qrc

RC_ICONS = $$PWD/images/icon.ico # icon.ico是我的软件图标

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/mainwindows/mdi
INSTALLS += target

win32: LIBS += -L$$PWD/./ -llibfftw3-3 -llibfftw3f-3 -llibfftw3l-3

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

TRANSLATIONS += $$PWD/languages/zh_CN.ts \
               $$PWD/languages/en_US.ts
