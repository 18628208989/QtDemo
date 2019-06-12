#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>
#include <QPixmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPicture picture;
    QPainter p;
    p.begin(&picture);

    p.drawPixmap(0, 0, 80, 80, QPixmap("/Users/zhangboqiang/QtCode/date03/image/face.png"));
    p.drawLine(50, 50, 150, 50);

    p.end();

    //保存，二进制文件
    picture.save("/Users/zhangboqiang/QtCode/date03/picture.png");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{

#if 0
    QPicture pic;
    //将保存的图片文件重新加载
    pic.load("/Users/zhangboqiang/QtCode/date03/picture.png");

    QPainter p(this);
    p.drawPicture(0, 0, pic);
#endif

    //QPixmap与QImage的转换
    QPainter p(this);
    QPixmap pixmap;
    pixmap.load("/Users/zhangboqiang/QtCode/date03/image/face.png");

    //QPixmap -> QImage
    QImage tempImage = pixmap.toImage();
    p.drawImage(0, 0, tempImage);

    QImage image;
    image.load("/Users/zhangboqiang/QtCode/date03/image/face.png");
    //QImage -> QPixmap
    QPixmap tempPixmap = QPixmap::fromImage(image);
    p.drawPixmap(100, 0, tempPixmap);
}
