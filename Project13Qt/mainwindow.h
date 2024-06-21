#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include "DataBase.h"
#include "DrawData.h"
#include "createlineform.h"
#include "createrectangleform.h"
#include "createcircleform.h"
#include "createpolylineform.h"
#include "errorform.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnEnter_clicked();
    void on_btnDraw_clicked();

    void on_btnCreatePolyline_clicked();
    void on_btnCreateCircle_clicked();
    void on_btnCreateRectangle_clicked();
    void on_btnCreateLine_clicked();



public slots:
    void Lineslot(object::ptr obj);
    void Rectangleslot(object::ptr obj);
    void Circleslot(object::ptr obj);
    void Polylineslot(object::ptr obj);

    void LineExitSlot();
    void RectangleExitSlot();
    void CircleExitSlot();
    void PolylineExitSlot();

    void ErrorExitSignal();

private:
    void Draw(DrawData::ptr data);
    void appendInfoToScene(int typeID, int ObjectID, std::string name);

    DataBase::ptr db;

    CreateLineForm* lineForm;
    CreateRectangleForm* rectangleForm;
    CreateCircleForm* circleForm;
    CreatePolylineForm* polylineForm;

    ErrorForm* errorForm;

    Ui::MainWindow *ui;
    QGraphicsScene* objectScene, *textScene;
    QString info;

};
#endif // MAINWINDOW_H
