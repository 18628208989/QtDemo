#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket> //通信套接字

namespace Ui {
class clientWidget;
}

class clientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit clientWidget(QWidget *parent = 0);
    ~clientWidget();

private slots:
    void on_buttonConnect_clicked();

    void on_buttonSend_clicked();

    void on_buttonClose_clicked();

private:
    Ui::clientWidget *ui;

    QTcpSocket *tcpSocket;
};

#endif // CLIENTWIDGET_H
