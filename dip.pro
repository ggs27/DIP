QT += widgets
requires(qtConfig(filedialog))
qtHaveModule(printsupport): QT += printsupport
QMAKE_CXXFLAGS+= -openmp

HEADERS       = mainwindow.h \
                acedialog.h \
                closedialog.h \
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
                sdfilterdialog.h \
                transform.h
SOURCES       = main.cpp \
                acedialog.cpp \
                closedialog.cpp \
                dilationdialog.cpp \
                embossfilterdialog.cpp \
                erosiondialog.cpp \
                fdfilterdialog.cpp \
                imagepocess.cpp \
                mainwindow.cpp \
                mdichild.cpp \
                opendialog.cpp \
                padding.cpp \
                sdfilterdialog.cpp \
                transform.cpp
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
