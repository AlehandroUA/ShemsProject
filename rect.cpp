#include "rect.h"

Rect::Rect(void){

}

QString Rect::nameOfClass(){
    return "Rectangle";
}

void Rect::showShape(QPainter &painter, bool isDraw){
    QRectF rect(_begin.x(),_begin.y(), (_end.x() - _begin.x()), (_end.y() - _begin.y()));
    if(isDraw){
        painter.setBrush(Qt::transparent);
    }else{
        painter.setBrush(Qt::cyan);
    }
    painter.drawRect(rect);
   }

