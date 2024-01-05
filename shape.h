#ifndef SHAPE_H
#define SHAPE_H

#include <QMainWindow>
#include <QPainter>

class Shape
{
public:
    Shape(void);
    void setCord(QPoint _x1y1, QPoint _x2y2);
    virtual void showShape(QPainter &painter,bool isDraw){};
    virtual QString nameOfClass(){};
protected:
    QPoint _begin;
    QPoint _end;
};

#endif // SHAPE_H
