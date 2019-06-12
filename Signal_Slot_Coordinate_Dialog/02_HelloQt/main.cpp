#include <QApplication>
#include <QWidget>//窗口控件基类
#include <QPushButton>
int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;
    w.setWindowTitle("测试标题");//设置标题

    QPushButton b;
    b.setText("测试按钮");//给按钮设置内容
    b.setParent(&w);//指定父对象
    b.move(100, 100);//移动坐标

    QPushButton b1(&w);
    b1.setText("abc");

    /*如果不指定父对象，对象和对象（窗口）是没有关系，独立
     * a指定b为他的父对象，a放在b的上面
     * 指定父对象，有两种方式
     * 1.setParent
     * 2.通过构造函数穿参
     * 指定父对象，只需要父对象显示，上面的子对象自动显示
     */
    w.show();
    app.exec();
    return 0;
}
