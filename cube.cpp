#include "cube.h"

Cube::Cube(int _lineWidth, int _coefficient)
{
    this->_lineWidth=_lineWidth;
    this->_coefficient=_coefficient;
}

QString Cube::nameOfClass(){
    return "Cube";
}

void Cube::showShape(QPainter &painter, bool isDraw){
    int plus =qMax(_end.x(),_end.y())-qMax(_begin.x(),_begin.y())+_coefficient;
    if(isDraw){
        _position=0;
        _pointBegin[_position] = _begin;
        _pointEnd[_position] = QPoint(_begin.x()+_lineWidth,_begin.y()+_lineWidth);//checked

        _position++;
        _pointBegin[_position] = QPoint(_begin.x()+plus,_begin.y());
        _pointEnd[_position] = QPoint(_begin.x()+plus+_lineWidth,_begin.y()+_lineWidth);

        _position++;
        _pointBegin[_position] = QPoint(_begin.x(),_begin.y()+plus);
        _pointEnd[_position] = QPoint(_begin.x()+_lineWidth,_begin.y()+_lineWidth+plus);

        _position++;
        _pointBegin[_position] = QPoint(_begin.x()+plus,_begin.y()+plus);
        _pointEnd[_position] = QPoint(_begin.x()+_lineWidth+plus,_begin.y()+_lineWidth+plus);

        _position++;
        _pointBegin[_position] = _begin;
            _pointEnd[_position] = QPoint(_begin.x()+plus,_begin.y()+plus);

        _position++;
            _pointBegin[_position] = QPoint(_begin.x()+_lineWidth,_begin.y()+_lineWidth);
            _pointEnd[_position] = QPoint(_begin.x()+plus+_lineWidth,_begin.y()+plus+_lineWidth);
    }

    for(int i=0;i<_totalShapes;i++){
        if(i<_totalShapes-2){
            Line::setCord(_pointBegin[i],_pointEnd[i]);
            Line::showShape(painter,true);
        }else{
            Rect::setCord(_pointBegin[i],_pointEnd[i]);
            Rect::showShape(painter,true);
        }
    }
}
