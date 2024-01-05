#include "ellipse.h"

QString Ellipse::nameOfClass(){
    return "Ellipse";
}

void Ellipse::showShape(QPainter &painter,bool isDraw){
    if(isDraw){
        painter.setBrush(Qt::white);
    }else{
         painter.setBrush(Qt::green);
    }
   painter.drawEllipse(_begin, (_end.x() - _begin.x()), (_end.y() - _begin.y()));
}
