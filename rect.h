#ifndef RECT_H
#define RECT_H

#include "shape.h"

class Rect : virtual public  Shape
{
public:
    Rect(void);
    void showShape(QPainter &painter,bool isDraw) override;
    QString nameOfClass() override;
};

#endif // RECT_H
