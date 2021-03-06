/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <mdiviewchild.h>
#include <mdichild.h>
#include "imageprocess.h"
#include "acedialog.h"
#include "fdfilterdialog.h"
#include "sdfilterdialog.h"
#include "embossfilterdialog.h"
#include "transform.h"
//Morphological processing
#include "erosiondialog.h"
#include "dilationdialog.h"
#include "closedialog.h"
#include "opendialog.h"
//Image style processing
#include "blurdialog.h"
#include "cooldialog.h"
#include "warmdialog.h"
#include "saturationdialog.h"
#include "sharpendialog.h"

//class MdiChild;
//class MdiViewChild;
QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QMdiArea;
class QMdiSubWindow;
class QTranslator;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void newFile();// new Image
    void open();// open Image
    void save();// save Image
    void saveAs();// save Image As a new Image
    void updateRecentFileActions();// update Recent Image Actions
    void openRecentFile();// open Recent Image
#ifndef QT_NO_CLIPBOARD
    void copy();// copy Image
    void paste();// paste Image
#endif
    void about();// software Information
    void updateMenus();// update Menus
    void updateWindowMenu();// update Window Menu
    MdiChild *createMdiChild();//
    void switchLayoutDirection();// switch Layout Direction
    void switchViewMode();// switch View Mode
    void zoomIn();// zoom In
    void zoomOut();// zoom Out
    void normalSize();// normal Size
    void fitToWindow();// fit Image To Window
    void fitToImage(MdiChild *child);// fit To Image
    void createMdiChildView();// create MdiChild View
    void updateMdiChildView();// update MdiChild View
    void closeMdiChildView();// close MdiChild View
    QString getMdiChildViewLabel(QObject *s);// get MdiChild View Label
    QImage getMdiChildViewImage(QImage image, QString str);// get MdiChildView Image
    QString joinFileName(const QString fileName, const QString str);// join File Name
    void convertGrayImage();// convert Image to Gray Image
    void equalizeHistogram();// equalize Histogram
    void adaptiveContrastEnhancement();// adaptiveContrastEnhancement
    void spaceDomainFiltering();// space Domain Filtering
    void frequencyDomainFiltering();// frequency Domain Filtering
    void embossFiltering();// emboss Filtering
    void switchLanguage();// switch Language：cn/en
    void erosionOperation();
    void dilationOperation();
    void OpenOperation();
    void CloseOperation();

    void blurOperation();
    void coolOperation();
    void warmOperation();
    void saturationOperation();
    void sharpenOperation();

private:
    enum { MaxRecentFiles = 5 };

    void createActions();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool openFile(const QString &fileName);
    void initMdiSubWindow(MdiChild *child);
    static bool hasRecentFiles();
    void prependToRecentFiles(const QString &fileName);
    void setRecentFilesVisible(bool visible);
    MdiChild *activeMdiChild() const;
    QMdiSubWindow *findMdiViewChild(MdiChild *owner, const QString &fileName) const;
    void retranslate();

    QMenu *fileMenu;
    QToolBar *fileToolBar;
    QAction *openAct;
    QMenu *recentMenu;
    QAction *layoutAct;
    QAction *exitAct;
    QMenu *editMenu;
    QToolBar *editToolBar;

    QTranslator translator;
    QMenu *helpMenu;
    QMenu *languageMenu;
    QAction *zhCNAct;
    QAction *enUSAct;
    QAction *aboutAct;
    QAction *aboutQtAct;

    QMdiArea *mdiArea;

    QMenu *windowMenu;
    QAction *newAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *recentFileActs[MaxRecentFiles];
    QAction *recentFileSeparator;
    QAction *recentFileSubMenuAct;
#ifndef QT_NO_CLIPBOARD
    QAction *copyAct;
    QAction *pasteAct;
#endif
    QAction *closeAct;
    QAction *closeAllAct;
    QAction *viewModeAct;
    QAction *tileAct;
    QAction *cascadeAct;
    QAction *nextAct;
    QAction *previousAct;
    QAction *windowMenuSeparatorAct;

    QMenu *viewMenu;
    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *normalSizeAct;
    QAction *fitToWindowAct;
    QAction *grayViewAct;
    QAction *spectrumViewAct;
    QMenu *histViewMenu;
    QAction *histViewYAct;
    QAction *histViewRAct;
    QAction *histViewGAct;
    QAction *histViewBAct;
    QMenu *negativeViewMenu;
    QAction *negativeViewAllAct;
    QAction *negativeViewRAct;
    QAction *negativeViewGAct;
    QAction *negativeViewBAct;

    QMenu *pseudoColorViewMenu;
    QAction *pseudoColorJetViewAct;
    QAction *pseudoColorParulaViewAct;
    QAction *pseudoColorHotViewAct;

    QMenu *enhancementMenu;
    QAction *convertGrayImageAct;
    QAction *equalizeHistogramAct;
    QAction *adaptiveContrastEnhancementAct;

    QMenu *filterMenu;
    QAction *timeDomainAct;
    QAction *frequencyDomainAct;
    QAction *embossFilterAct;

    QMenu *morphologyMenu;
    QAction *erodeAct;
    QAction *dilateAct;
    QAction *openningAct;
    QAction *closingAct;

    QMenu *imageStyleMenu;
    QAction *blurAct;
    QAction *coolAct;
    QAction *warmAct;
    QAction *saturationAct;
    QAction *sharpenAct;
};

#endif
