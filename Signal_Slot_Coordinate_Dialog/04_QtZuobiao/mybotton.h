#ifndef MYBOTTON_H
#define MYBOTTON_H

#include <QPushButton>

class MyBotton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyBotton(QWidget *parent = nullptr);
    ~MyBotton();
signals:

public slots:
};

#endif // MYBOTTON_H
