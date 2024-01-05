#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"

class Ellipse : virtual public Shape
{
public:
    Ellipse(void){};
    void showShape(QPainter &painter,bool isDraw) override;
    QString nameOfClass() override;
};

#endif // ELLIPSE_H
