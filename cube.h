#ifndef CUBE_H
#define CUBE_H

#include "rect.h"
#include "line.h"

class Cube : public Rect, public Line
{
public:
    Cube(int _lineWidth = 40, int _coefficient=0);
    void showShape(QPainter &painter,bool isDraw) override;
    QString nameOfClass() override;
protected:
    static const int _totalShapes = 6;
    int _lineWidth;
    int _coefficient;
    QPoint _pointBegin[_totalShapes];
    QPoint _pointEnd[_totalShapes];
    int _position;
};

#endif // CUBE_H
