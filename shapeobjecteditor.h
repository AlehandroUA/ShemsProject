#ifndef SHAPEOBJECTEDITOR_H
#define SHAPEOBJECTEDITOR_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QtMath>
#include <QActionGroup>

#include "shape.h"
#include "rect.h"
#include "line.h"
#include "ellipse.h"
#include "dot.h"
#include "lineellipse.h"
#include "cube.h"


QT_BEGIN_NAMESPACE
namespace Ui { class ShapeObjectEditor; }
QT_END_NAMESPACE

class ShapeObjectEditor : public QMainWindow{
    Q_OBJECT

public:
    ~ShapeObjectEditor();
    static ShapeObjectEditor * getInstance(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
    void drawing(QPainter *painter);
    void deleting();

    QPainter *painterForWidget;
    QPoint pressPoint;
    QPoint movePoint;

    bool isDraw = false;
    bool isRel;
    bool isShapeChecked = false;
    bool isDebug = true;

    static const int arraySize = 128;
    int counter = 0;
    Shape *shapeArray[arraySize];

    int cubeLength=40;
    int cubeCoef=0;

private slots:
    void on_actionopenTab_triggered();
    void on_openTableCoord_triggered();

public slots:
    void cubeSizeGetter(int cubeLength,int cubeCoef);

signals:
    void sendShapeTable(QString, QPoint, QPoint);

    void widgetClose();

    void widgetOpenTablet();
    void widgetOpenResize();
private:
    static ShapeObjectEditor* p_instance;
    ShapeObjectEditor(QWidget *parent = nullptr);
    ShapeObjectEditor() {};
    ShapeObjectEditor( const ShapeObjectEditor& );
    ShapeObjectEditor& operator=(const  ShapeObjectEditor& );

    Ui::ShapeObjectEditor *ui;
};
#endif // SHAPEOBJECTEDITOR_H
