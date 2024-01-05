#include "cuberesize.h"
#include "ui_cuberesize.h"

CubeResize::CubeResize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CubeResize){
    ui->setupUi(this);
    setFixedSize(614,357);
    setWindowTitle("Зміна розміру");
}

CubeResize::~CubeResize(){
    delete ui;
}

void CubeResize::widgetClose(){
    close();
}

void CubeResize::widgetOpen(){
    show();
}

void CubeResize::paintEvent(QPaintEvent *event){
    QPainter *painter = new QPainter{this};
    QPoint begin(200,23);
    QPoint end(300,270);
    Cube *cube = new Cube(length,coef);
    cube->setCord(begin,end);
    cube->showShape(*painter,true);
    update();
    delete painter;
}

void CubeResize::on_denyButton_clicked(){
    close();
}

void CubeResize::on_angleSlider_valueChanged(int value){
    coef=value;
    ui->angleText->setText(QString::number(value));
}

void CubeResize::on_lenghtSlider_valueChanged(int value){
    length=value;
    ui->lengthText->setText(QString::number(value));
}

void CubeResize::on_applyButton_clicked(){
    emit sendCubeSize(length,coef);
    close();
}


