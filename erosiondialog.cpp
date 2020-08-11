#include "erosiondialog.h"

ErosionDialog::ErosionDialog(QImage inputImage)
{
    srcImage = inputImage;

    Erosion(srcImage, dstImage);

    iniUI();

    srcImageLabel->setPixmap(QPixmap::fromImage(srcImage));
    dstImageLabel->setPixmap(QPixmap::fromImage(dstImage));

}

void ErosionDialog::iniUI()
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

    dstLabel = new QLabel(tr("Erosion"));
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

void ErosionDialog::setImage(QImage image, QLabel *label)
{
    QPixmap pix;
    pix.fromImage(image);
    label->setPixmap(pix);
}
/*
*Summary: Erosion operation implemented by minimal description algorithm
*Parameters:
*    QImage &src_image : input original image
*    QImage &dst_image : output eroded image
*Describtion:
*    Detect all pixels corresponding to the positions of 1 in the structure element template in turn,
*    take out the minimum value min, and set the pixel value at the position of the current structure element to min.
*/

void ErosionDialog::Erosion(QImage &src_image, QImage &dst_image)
{
    dst_image = src_image;
    int kernel[5][5] = {
        { 0,0,1,0,0 },
        { 0,1,1,1,0 },
        { 1,1,1,1,1 },
        { 0,1,1,1,0 },
        { 0,0,1,0,0 } };
    int sizeKernel = 5;
    QColor color;
    QColor Rcolor;

    for (int y = sizeKernel / 2; y < src_image.height() - sizeKernel / 2; y++)
    {
        for (int x = sizeKernel / 2; x < src_image.width() - sizeKernel / 2; x++)
        {
            int kr = 255;
            int kg = 255;
            int kb = 255;
            Rcolor = QColor(src_image.pixel(x, y));
            for (int j = -sizeKernel / 2; j <= sizeKernel / 2; j++)
            {
                for (int i = -sizeKernel / 2; i <= sizeKernel / 2; i++)
                {
                    color = QColor(src_image.pixel(x + i, y + j));
                    while (color.red() < kr && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kr = color.red();
                    }
                    while (color.green() < kg && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kg = color.green();
                    }
                    while (color.blue() < kb && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kb = color.blue();
                    }
                }
            }
            dst_image.setPixel(x, y, qRgb(kr, kg, kb));
        }
    }
}
