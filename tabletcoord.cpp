#include "tabletcoord.h"
#include "ui_tabletcoord.h"

tabletCoord::tabletCoord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tabletCoord){
    ui->setupUi(this);
    tabletWidgetDisplay();
}

tabletCoord::~tabletCoord(){
    delete ui;
}

void tabletCoord::shapeTableGetter(QString nameShape, QPoint begin, QPoint end){
    QFile fileIn("coord.txt");
    QTextStream in(&fileIn);
    if(!fileIn.exists()){
         fileIn.open(QIODevice::WriteOnly | QIODevice::Text);
    }
    fileIn.open(QIODevice::Append | QIODevice::Text);
    in<<nameShape<<" "<<begin.x()<<" "<<begin.y()<<" "<<end.x()<<" "<<end.y()<<"\n";
    fileIn.close();
    ui->tableWidget->setRowCount(counter+1);

    ui->tableWidget->setItem(counter,0,new QTableWidgetItem(nameShape));
    ui->tableWidget->setItem(counter,1,new QTableWidgetItem(QString::number(begin.x())));
    ui->tableWidget->setItem(counter,2,new QTableWidgetItem(QString::number(begin.y())));
    ui->tableWidget->setItem(counter,3,new QTableWidgetItem(QString::number(end.x())));
    ui->tableWidget->setItem(counter,4,new QTableWidgetItem(QString::number(end.y())));
    counter++;
}

void tabletCoord::widgetClose(){
    close();
}

void tabletCoord::widgetOpen(){
    show();
}

void tabletCoord::tabletWidgetDisplay(){
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(5);
    QStringList headers;
    headers <<"Shape"<<"x1"<<"y1"<<"x2"<<"y2";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
}
