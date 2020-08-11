#include "closedialog.h"

CloseDialog::CloseDialog(QImage inputImage)
{
    srcImage = inputImage;

    Closing(srcImage, dstImage);

    iniUI();

    srcImageLabel->setPixmap(QPixmap::fromImage(srcImage));
    dstImageLabel->setPixmap(QPixmap::fromImage(dstImage));

}

void CloseDialog::iniUI()
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

//    srcLabel = new QLabel(tr("Original"));
//    srcLabel->setAlignment(Qt::AlignCenter);

    QHBoxLayout *layout3=new QHBoxLayout;
    layout3->addStretch();
    layout3->addWidget(btnOK);
    layout3->addWidget(btnCancel);
    layout3->addStretch();
    layout3->addWidget(btnClose);


    // main layout
    QVBoxLayout *mainlayout = new QVBoxLayout;
    mainlayout->addLayout(layout1);
    mainlayout->addLayout(layout3);
    setLayout(mainlayout);
}

void CloseDialog::setImage(QImage image, QLabel *label)
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

void CloseDialog::Closing(QImage &src_image, QImage &dst_image)
{
    QImage temp_image =src_image;
    dst_image = src_image;
    int kernel[7][7] = {
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 },
        { 1,1,1,1,1,1,1 } };
    int sizeKernel = 7;
    QColor color;

    /*dilation operation*/
    for (int y = sizeKernel / 2; y < src_image.height() - sizeKernel / 2; y++)
    {
        for (int x = sizeKernel / 2; x < src_image.width() - sizeKernel / 2; x++)
        {
            int kr = 0;
            int kg = 0;
            int kb = 0;
            for (int j = -sizeKernel / 2; j <= sizeKernel / 2; j++)
            {
                for (int i = -sizeKernel / 2; i <= sizeKernel / 2; i++)
                {
                    color = QColor(src_image.pixel(x + i, y + j));
                    while (color.red() > kr && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kr = color.red();
                    }
                    while (color.green() > kg && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kg = color.green();
                    }
                    while (color.blue() > kb && kernel[sizeKernel / 2 + i][sizeKernel / 2 + j])
                    {
                        kb = color.blue();
                    }
                }
            }
            temp_image.setPixel(x, y, qRgb(kr, kg, kb));
        }
    }

    /*erosion operation*/
    for (int y = sizeKernel / 2; y < src_image.height() - sizeKernel / 2; y++)
    {
        for (int x = sizeKernel / 2; x < src_image.width() - sizeKernel / 2; x++)
        {
            int kr = 255;
            int kg = 255;
            int kb = 255;
            for (int j = -sizeKernel / 2; j <= sizeKernel / 2; j++)
            {
                for (int i = -sizeKernel / 2; i <= sizeKernel / 2; i++)
                {
                    color = QColor(temp_image.pixel(x + i, y + j));
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
