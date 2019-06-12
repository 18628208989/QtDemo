#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //绘图设备，400*300
    QPixmap pixmap(400, 300);

    QPainter p(&pixmap);

    //填充背景颜色
    //p.fillRect(0, 0, 400, 300 ,QBrush(Qt::white));

    pixmap.fill(Qt::white);

    p.drawPixmap(0, 0, 80, 80, QPixmap("/Users/zhangboqiang/QtCode/date03/image/face.png"));

    //保存图片
    pixmap.save("/Users/zhangboqiang/QtCode/date03/pixmap.jpg");


}

Widget::~Widget()
{
    delete ui;
}
