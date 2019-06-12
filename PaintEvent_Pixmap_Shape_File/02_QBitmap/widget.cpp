#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    //QPixmap绘图
    p.drawPixmap(0, 0, QPixmap("/Users/zhangboqiang/QtCode/date03/image/face02.png"));
    //QBitmap
    p.drawPixmap(500, 0, QBitmap("/Users/zhangboqiang/QtCode/date03/image/face02.png"));

    QPixmap pixmap;
    pixmap.load("/Users/zhangboqiang/QtCode/date03/image/face.png");
    p.drawPixmap(0, 200, pixmap);

    QBitmap bitmap;
    bitmap.load("/Users/zhangboqiang/QtCode/date03/image/face.png");
    p.drawPixmap(500, 500, bitmap);
}
