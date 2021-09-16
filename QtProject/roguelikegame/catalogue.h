#ifndef CATALOGUE_H
#define CATALOGUE_H

#include <QWidget>

class Catalogue : public QWidget
{
    Q_OBJECT
public:
    explicit Catalogue(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // CATALOGUE_H
