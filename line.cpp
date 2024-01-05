#include "line.h"

Line::Line(void){}

QString Line::nameOfClass(){
    return "Line";
}

void Line::showShape(QPainter &painter,bool isDraw){
    painter.drawLine(_begin.x(),_begin.y(), _end.x(), _end.y());
}
