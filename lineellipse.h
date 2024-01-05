#ifndef LINEELLIPSE_H
#define LINEELLIPSE_H

#include "line.h"
#include "ellipse.h"

class Lineellipse : public Line, public Ellipse
{
public:
    Lineellipse(void){};
    void showShape(QPainter &painter,bool isDraw) override;
    QString nameOfClass() override;
protected:
    int _position;
    int _resizeCircle = 20;
    static const int _totalShapes = 3;
    QPoint _pointBegin[_totalShapes];
    QPoint _pointEnd[_totalShapes];
};

#endif // LINEELLIPSE_H
