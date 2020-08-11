#ifndef BLUR_H
#define BLUR_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QSlider>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include <QImage>
#include <QComboBox>
#include "imageprocess.h"
#include "floatslider.h"
#include <QApplication>
#include <QDesktopWidget>


QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QMenu;
class QMdiArea;
class QMdiSubWindow;
class QSlider;
class QLineEdit;
class QPushButton;
class QGroupBox;
class QBoxLayout;
class QHBoxLayout;
class QVBoxLayout;
class QComboBox;
class QApplication;
class QDesktopWidget;
QT_END_NAMESPACE

class BlurDialog : public QDialog
{
    Q_OBJECT
public:
    BlurDialog(QImage inputImage);
    ~BlurDialog()
    {

    }
    QImage getImage() {return dstImage;}
private:
    void Blur(QImage &src_image, QImage &dst_image);
    void iniUI();
    QImage srcImage;
    QImage dstImage;

    QLabel *srcImageLabel;
    QLabel *dstImageLabel;

    QLabel *srcLabel;
    QLabel *dstLabel;

    QPushButton     *btnOK;
    QPushButton     *btnCancel;
    QPushButton     *btnClose;

private slots:
    void setImage(QImage image, QLabel *label);
};
#endif // BLUR_H
