#ifndef TABLETCOORD_H
#define TABLETCOORD_H

#include <QDialog>
#include <QTableWidgetItem>
#include <QFile>

namespace Ui {
class tabletCoord;
}

class tabletCoord : public QDialog
{
    Q_OBJECT

public:
    explicit tabletCoord(QWidget *parent = nullptr);
    ~tabletCoord();
public slots:
    void widgetOpen();

    void shapeTableGetter(QString nameShape,QPoint begin, QPoint end);
    void widgetClose();
private:
    int counter = 0;
    Ui::tabletCoord *ui;
    QTableWidgetItem *item;
    void tabletWidgetDisplay();
};

#endif // TABLETCOORD_H
