#include "warmdialog.h"

WarmDialog::WarmDialog(QImage inputImage)
{
    srcImage = inputImage;

    Warm(srcImage, dstImage);

    iniUI();

    srcImageLabel->setPixmap(QPixmap::fromImage(srcImage));
    dstImageLabel->setPixmap(QPixmap::fromImage(dstImage));

}

void WarmDialog::iniUI()
{
    // two image labels
    srcImageLabel = new QLabel();
    srcImageLabel->setAlignment(Qt::AlignCenter);
    dstImageLabel = new QLabel();
    dstImageLabel->setAlignment(Qt::AlignCenter);

    // three buttons
    btnOK = new QPushButton(tr("OK"));
    btnCancel = new QPushButton(tr("Cancel"));
    btnClose = new QPushButton(tr("Exit"));

    connect(btnOK, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *layout1 = new QHBoxLayout;
    layout1->addWidget(srcImageLabel);
    layout1->addWidget(dstImageLabel);

    srcLabel = new QLabel(tr("Original"));
    srcLabel->setAlignment(Qt::AlignCenter);

    dstLabel = new QLabel(tr("Warm"));
    dstLabel->setAlignment(Qt::AlignCenter);

    QHBoxLayout *layout2 = new QHBoxLayout;
    layout2->addWidget(srcLabel);
    layout2->addWidget(dstLabel);

    QHBoxLayout *layout3=new QHBoxLayout;
    layout3->addStretch();
    layout3->addWidget(btnOK);
    layout3->addWidget(btnCancel);
    layout3->addStretch();
    layout3->addWidget(btnClose);


    // main layout
    QVBoxLayout *mainlayout = new QVBoxLayout;
    mainlayout->addLayout(layout1);
    mainlayout->addLayout(layout2);
    mainlayout->addLayout(layout3);
    setLayout(mainlayout);
}

void WarmDialog::setImage(QImage image, QLabel *label)
{
    QPixmap pix;
    pix.fromImage(image);
    label->setPixmap(pix);
}
/*
*Summary: Close Operation --> Dilation first and Erosion later
*Parameters:
*    QImage &src_image : input original image
*    QImage &dst_image : output opened image
*Describtion:
*    Connecting adjacent areas and filling crevices,
*    by selecting a structural template, the filled content can have certain geometric characteristics
*/

void WarmDialog::Warm(QImage &src_image, QImage &dst_image)
{
    /*Warm operation*/
    dst_image = src_image;
    QColor oldColor;
    int r,g,b;
    int delta = 50;
    /*Cool operation*/
    for(int x=0; x<dst_image.width(); x++){
        for(int y=0; y<dst_image.height(); y++){
            oldColor = QColor(src_image.pixel(x,y));

            r = oldColor.red()+delta;
            g = oldColor.green()+delta;
            b = oldColor.blue();

            //we check if the new value is between 0 and 255
            r = qBound(0, r, 255);
            g = qBound(0, g, 255);

            dst_image.setPixel(x,y, qRgb(r,g,b));
        }
    }
}
