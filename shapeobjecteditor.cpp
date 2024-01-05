#include "shapeobjecteditor.h"
#include "ui_shapeobjecteditor.h"


ShapeObjectEditor::ShapeObjectEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ShapeObjectEditor){
    ui->setupUi(this);
    setMouseTracking(true);

    setFixedSize(1000,500);
    setWindowTitle("Малювалка");

    QActionGroup *alignGroup = new QActionGroup(this);
    alignGroup->addAction(ui->line);
    alignGroup->addAction(ui->dot);
    alignGroup->addAction(ui->ellipse);
    alignGroup->addAction(ui->rectangle);
    alignGroup->addAction(ui->lineCirlcle);
    alignGroup->addAction(ui->cube);
}

ShapeObjectEditor* ShapeObjectEditor::p_instance=nullptr;

ShapeObjectEditor::~ShapeObjectEditor(){
    deleting();
    delete ui;
    p_instance = nullptr;
}

ShapeObjectEditor *ShapeObjectEditor::getInstance(QWidget *parent){
    if(!p_instance){
        p_instance = new ShapeObjectEditor(nullptr);
    }

    return p_instance;
}

void ShapeObjectEditor::cubeSizeGetter(int cubeLength,int cubeCoef){
    this->cubeLength = cubeLength;
    this->cubeCoef = cubeCoef;
}

void ShapeObjectEditor::mouseMoveEvent(QMouseEvent *event){
    if (event->buttons() & Qt::LeftButton && isDraw){
        movePoint = event->pos();
        update();
    }
}

void  ShapeObjectEditor::mousePressEvent(QMouseEvent *event){
    movePoint = pressPoint;

    if (event->button() == Qt::LeftButton){
        isDraw = true;
        isRel = false;
        pressPoint = event->pos();
        update();
    }
}

void ShapeObjectEditor::mouseReleaseEvent(QMouseEvent *event){
    isRel = true;
    isDraw = false;
    isDebug = true;
    update();
}

void ShapeObjectEditor::paintEvent(QPaintEvent *event){
    QPainter *painterForWidget = new QPainter{this};

    if(isDebug && isDraw){
        movePoint = pressPoint;
        isDebug = false;
    }

    if(isShapeChecked){
        drawing(painterForWidget);
    }

    if(ui->line->isChecked()){
            ui->statusbar->showMessage("Обрана лінія");

            if(isDraw){
                shapeArray[counter] = new Line;
                isShapeChecked=true;
            }

    }else if(ui->ellipse->isChecked()){
            ui->statusbar->showMessage("Обран еліпс");

            if(isDraw){
                shapeArray[counter] = new Ellipse;
                isShapeChecked=true;
            }

    }else if(ui->rectangle->isChecked()){
            ui->statusbar->showMessage("Обран прямокутник");

            if(isDraw){
                shapeArray[counter] = new Rect;
                 isShapeChecked=true;
            }

    }else if(ui->dot->isChecked()){
            ui->statusbar->showMessage("Обрана точка");

            if(isDraw){
                shapeArray[counter] = new Dot;
                isShapeChecked=true;
            }

    }else if(ui->lineCirlcle->isChecked()){
            ui->statusbar->showMessage("Обрана ліня з точками");

            if(isDraw){
                shapeArray[counter] = new Lineellipse;
                 isShapeChecked=true;
            }

    }else if(ui->cube->isChecked()){
            ui->statusbar->showMessage("Обран куб");

            if(isDraw){
                shapeArray[counter] = new Cube(cubeLength,cubeCoef);
                isShapeChecked=true;
            }
    }

    if(isRel && isShapeChecked){
        emit sendShapeTable(shapeArray[counter]->nameOfClass(),pressPoint,movePoint);
    }

    if(isRel && counter<arraySize && isShapeChecked){
        counter++;
    }

    if(isDraw && isShapeChecked && counter<arraySize){
        shapeArray[counter]->setCord(pressPoint,movePoint);
        shapeArray[counter]->showShape(*painterForWidget,isDraw);
    }

    isRel=false;
    delete painterForWidget;
    update();
}

void ShapeObjectEditor::drawing(QPainter *painter){
    for(int row = 0;row < counter;row++){
            if(shapeArray[row]){
                shapeArray[row]->showShape(*painter,false);
            }
    }
}
void ShapeObjectEditor::deleting(){
     for(int row = 0;row < arraySize;row++){
            if(shapeArray[row]){
                delete shapeArray[row];
            }
     }
}

void ShapeObjectEditor::on_actionopenTab_triggered(){
    emit widgetOpenResize();
}

void ShapeObjectEditor::on_openTableCoord_triggered(){
    emit widgetOpenTablet();
}

void ShapeObjectEditor::closeEvent(QCloseEvent *event){
    emit widgetClose();
}


