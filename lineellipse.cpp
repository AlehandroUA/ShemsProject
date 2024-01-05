#include "lineellipse.h"

QString Lineellipse::nameOfClass(){
    return "Line wth ellipses";
}

void Lineellipse::showShape(QPainter &painter,bool isDraw){
    if(isDraw){
        _position = 0;
        _pointBegin[_position]=_begin;
        _pointEnd[_position]=_end;

        _position++;
        _pointBegin[_position] =_begin;
        _pointEnd[_position] = QPoint(_begin.x()+_resizeCircle,_begin.y()+_resizeCircle);

        _position++;
        _pointBegin[_position]=_end;
        _pointEnd[_position]=QPoint(_end.x()+_resizeCircle,_end.y()+_resizeCircle);
    }

    for(int i=0;i<_totalShapes;i++){
        if(i == 0){
            Line::setCord(_pointBegin[i],_pointEnd[i]);
            Line::showShape(painter,isDraw);
        }else{
            Ellipse::setCord(_pointBegin[i],_pointEnd[i]);
            Ellipse::showShape(painter,isDraw);
        }
    }

}

