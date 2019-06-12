#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //修改label的颜色
    //ui->label->setStyleSheet("QLabel{color:red;}");
    //通过RGB调整颜色
    //修改背景色，当与全局修改同时存在时，这个是特例
    ui->label->setStyleSheet("QLabel{color:rgb(0, 255, 255);"
                             "background-color:blue;"

                             //平铺
                             //"background-image:url(:/new/prefix1/屏幕快照 2019-06-10 上午1.00.38.png);"

                             //自动适应,向中心裁剪
                             "border-image:url(:/new/prefix1/屏幕快照 2019-06-10 上午1.00.38.png) 10 10 10 10 stretch stretch;"
                             "}");

    //修改当前窗口中所有label的样式
    this->setStyleSheet("QLabel{color:rgb(0, 255, 255);"
                        "background-color:red;"
                        "}");

    //设置伪状态，
    ui->pushButton->setStyleSheet(
                                  //button的边距2px的颜色为green
                                  //"QPushButton{"
                                  //"border: 2px outset green"
                                  //"}"

                                  "QPushButton{"
                                  "border-image:url(:/new/prefix1/屏幕快照 2019-06-10 下午4.44.00.png);"
                                  "}"

                                  //鼠标指向时更换显示的图片
                                  "QPushButton:hover{"
                                  "border-image:url(:/new/prefix1/屏幕快照 2019-06-10 上午1.00.38.png);"
                                  "}"

                                  //鼠标按下时更换显示的图片
                                  "QPushButton:pressed{"
                                  "border-image:url(:/new/prefix1/屏幕快照 2019-06-10 下午5.01.55.png);"
                                  "}"
                                 );


}

Widget::~Widget()
{
    delete ui;
}
