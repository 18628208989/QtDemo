#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

protected:
    //鼠标点击事件
    void mousePressEvent(QMouseEvent *ev);
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *ev);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *ev);
    //进入窗口区域
    void enterEvent(QEvent *event);
    //离开窗口区域
    void leaveEvent(QEvent *event);

signals:

public slots:
};

#endif // MYLABEL_H
