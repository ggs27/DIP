#ifndef SHARPENDIALOG_H
#define SHARPENDIALOG_H
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

class SharpenDialog : public QDialog
{
    Q_OBJECT
public:
    SharpenDialog(QImage inputImage);
    ~SharpenDialog()
    {

    }
    QImage getImage() {return dstImage;}
private:
    void Sharpen(QImage &src_image, QImage &dst_image);
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
#endif // SHARPENDIALOG_H
