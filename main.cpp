#include "shapeobjecteditor.h"
#include "tabletcoord.h"
#include "cuberesize.h"

#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    std::unique_ptr<ShapeObjectEditor> shape{ShapeObjectEditor::getInstance()};

    shape->show();

    tabletCoord tableWindow;
    CubeResize cube;

    QObject::connect(shape.get(),&ShapeObjectEditor::widgetOpenTablet,&tableWindow,&tabletCoord::widgetOpen);
    QObject::connect(shape.get(),&ShapeObjectEditor::sendShapeTable,&tableWindow,&tabletCoord::shapeTableGetter);
    QObject::connect(shape.get(),&ShapeObjectEditor::widgetClose,&tableWindow,&tabletCoord::widgetClose);

    QObject::connect(shape.get(),&ShapeObjectEditor::widgetOpenResize,&cube,&CubeResize::widgetOpen);
    QObject::connect(&cube,&CubeResize::sendCubeSize,shape.get(),&ShapeObjectEditor::cubeSizeGetter);
    QObject::connect(shape.get(),&ShapeObjectEditor::widgetClose,&cube,&CubeResize::widgetClose);

    return a.exec();
}
