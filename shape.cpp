#include "shape.h"

Shape::Shape(void){
}

void Shape::setCord(QPoint _x1y1, QPoint _x2y2){
    _begin = _x1y1;
    _end = _x2y2;
}
