#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class ServerWidget;
}

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServerWidget(QWidget *parent = 0);
    ~ServerWidget();

    void dealMsg(); //槽函数，处理对方发过来的数据

private slots:
    void on_buttonSend_clicked();

private:
    Ui::ServerWidget *ui;

    QUdpSocket *udpSocket;
};

#endif // SERVERWIDGET_H
