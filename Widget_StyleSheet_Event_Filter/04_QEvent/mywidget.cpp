#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QMessageBox>
#include <QEvent>
#include <QString>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //启动timerEvent
    //以毫秒为单位
    timerID = this->startTimer(1000);

    this->timerID_2 = this->startTimer(500);

    connect(ui->pushButton, &MyButton::clicked,
            []()
            {
                qDebug() << "按钮被按下";
            }
            );

    //安装过滤器
    ui->label_2->installEventFilter(this);
    ui->label_2->setMouseTracking(true);

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << (char)event->key();

    if(event->key() == Qt::Key_A)
    {
        qDebug() << "Qt::Key_A";
    }
}

void MyWidget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == this->timerID)
    {
        static int sec = 0;

        ui->label->setText(QString("<center><h1>timer out: %1</h1></center>").arg(sec++));

        //关闭计时
        if(5 == sec)
        {
            this->killTimer(this->timerID);
        }
    }
    else if(event->timerId() == this->timerID_2)
    {
        static int sec = 0;

        ui->label_2->setText(QString("<center><h1>timer out: %1</h1></center>").arg(sec++));

    }

}

//验证事件被ignore忽略后被传递给父组件
void MyWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "+++++++++++++++++++++++++++";
}

void MyWidget::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::question(this, "question", "是否需要关闭窗口");
    if(ret == QMessageBox::Yes)
    {
        //关闭窗口
        //处理关闭窗口事件，接收事件，事件就不会往下传递
        event->accept();
    }
    else
    {
        //不关闭窗口
        //忽略事件，事件继续传递给父组件
        event->ignore();
    }
}

bool MyWidget::event(QEvent *event)
{
    //事件分发
//    switch (event->type())
//    {
//    case QEvent::Close:
//        closeEvent(event);
//        break;
//    case QEvent::MouseMove:
//        mouseMoveEvent();
//        break;
    /*
     * ……
    */
//    }

    if(event->type() == QEvent::Timer)
    {
        //干掉定时器
        //如果返回true，事件停止传播
        QTimerEvent *env = static_cast<QTimerEvent *>(event);
        timerEvent(env);
        return true;
    }
    else if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *env = static_cast<QKeyEvent *>(event);
        if(env->key() == Qt::Key_B)
        {
            return QWidget::event(event);
        }
        return true;
    }
    else
    {
        return QWidget::event(event);
    }
}

bool MyWidget::eventFilter(QObject *obj, QEvent *e)
{
    if(obj == ui->label_2)
    {
        QMouseEvent *env = static_cast<QMouseEvent *>(e);
        //判断事件
        if(e->type() == QEvent::MouseMove)
        {
            ui->label_2->setText(QString("Mouse move:(%1, %2)").arg(env->x()).arg(env->y()));
            return true;
        }
        else if(e->type() == QEvent::MouseButtonPress)
        {
            ui->label_2->setText(QString("Mouse press:(%1, %2)").arg(env->x()).arg(env->y()));
            return true;
        }
        else if(e->type() == QEvent::MouseButtonRelease)
        {
            ui->label_2->setText(QString("Mouse release:(%1, %2)").arg(env->x()).arg(env->y()));
            return true;
        }
        else
        {
            return QWidget::eventFilter(obj, e);
        }
    }
    else
    {
        return QWidget::eventFilter(obj, e);
    }
}
