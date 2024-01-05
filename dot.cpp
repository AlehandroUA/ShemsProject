#include "dot.h"

Dot::Dot(void)
{

}

QString Dot::nameOfClass(){
    return "Dot";
}

void Dot::showShape(QPainter &painter,bool isDraw){
    painter.setBrush(Qt::black);
    painter.drawEllipse(_begin,10,10);
}
