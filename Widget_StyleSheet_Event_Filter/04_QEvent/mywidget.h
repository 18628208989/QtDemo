#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

protected:
    //键盘按下事件
    void keyPressEvent(QKeyEvent *event);
    //计时器事件
    void timerEvent(QTimerEvent *event);

    void mousePressEvent(QMouseEvent *event);
    //关闭事件
    void closeEvent(QCloseEvent *event);

    //重写event事件
    bool event(QEvent *event);

    //事件过滤器
    bool eventFilter(QObject *obj, QEvent *e);
private:
    Ui::MyWidget *ui;

    int timerID;
    int timerID_2;
};

#endif // MYWIDGET_H
