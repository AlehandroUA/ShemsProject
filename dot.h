#ifndef DOT_H
#define DOT_H

#include "shape.h"

class Dot : public Shape
{
public:
    Dot(void);
    void showShape(QPainter &painter,bool isDraw) override;
    QString nameOfClass() override;
};

#endif // DOT_H
