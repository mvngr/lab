#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>

class MyScene : public QGraphicsScene
{

public:
    enum SceneMode
    {
        Cursour = 0,
        Line
    };

    MyScene(QObject *parent = nullptr);

    void setMode(const SceneMode mode);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
//    void keyPressEvent(QKeyEvent *event);

private:
    void makeItemsControllable(bool areControllable);
    SceneMode mode_ = Cursour;
    QGraphicsLineItem *currentDrawLine_ = nullptr;
    QPointF startPoint_;
};

#endif // MYSCENE_H
