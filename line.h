#ifndef LINE_H
#define LINE_H

#include "shape.h"

class Line : virtual public Shape
{
public:
    Line(void);
    void showShape(QPainter &painter,bool isDraw) override;
    QString nameOfClass() override;
};

#endif // LINE_H
