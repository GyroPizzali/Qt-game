#ifndef MYPAGEMAIN_H
#define MYPAGEMAIN_H

#include <QWidget>


class MyPageMain : public QWidget
{
    Q_OBJECT
public:
    explicit MyPageMain(QWidget *parent = nullptr);
private:

protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // MYPAGEMAIN_H
