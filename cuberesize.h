#ifndef CUBERESIZE_H
#define CUBERESIZE_H

#include <QDialog>
#include "cube.h"

namespace Ui {
class CubeResize;
}

class CubeResize : public QDialog
{
    Q_OBJECT

public:
    explicit CubeResize(QWidget *parent = nullptr);
    ~CubeResize();

public slots:
    void widgetClose();
    void widgetOpen();

protected:
    void paintEvent(QPaintEvent *event) override;

    Cube *cube;
    int counter;
    QPainter *painter;
    bool clicked = false;
    int coef = 10;
    int length = 40;

private slots:
    void on_denyButton_clicked();
    void on_applyButton_clicked();
    void on_angleSlider_valueChanged(int value);
    void on_lenghtSlider_valueChanged(int value);

signals:
    void sendCubeSize(int,int);

private:
    Ui::CubeResize *ui;
};

#endif // CUBERESIZE_H
