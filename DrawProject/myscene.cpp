#include "myscene.h"

#include <QGraphicsSceneMouseEvent>
#include <QDebug>

MyScene::MyScene(QObject *parent) : QGraphicsScene(parent)
{

}

void MyScene::setMode(const SceneMode mode)
{
    mode_ = mode;
    QGraphicsView::DragMode vMode =
            QGraphicsView::NoDrag;
    if(mode == Line)
    {
        makeItemsControllable(false);
        vMode = QGraphicsView::NoDrag;
    }
    else if(mode == Cursour)
    {
        makeItemsControllable(true);
        vMode = QGraphicsView::RubberBandDrag;
    }
    QGraphicsView* mView = views().at(0);
    if(mView)
        mView->setDragMode(vMode);
}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(mode_ == Line)
        startPoint_ = event->scenePos();
    QGraphicsScene::mousePressEvent(event);
}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << event->scenePos();
    if(mode_ == Line)
    {
        if(!currentDrawLine_){
            currentDrawLine_ = new QGraphicsLineItem();
            addItem(currentDrawLine_);
            currentDrawLine_->setPen(QPen(Qt::black, 3, Qt::SolidLine));
            currentDrawLine_->setPos(startPoint_);
        }
        currentDrawLine_->setLine(0,0,
                            event->scenePos().x() - startPoint_.x(),
                            event->scenePos().y() - startPoint_.y());
    }
    else
        QGraphicsScene::mouseMoveEvent(event);
}

void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    currentDrawLine_ = nullptr;
    QGraphicsScene::mouseReleaseEvent(event);
}

void MyScene::makeItemsControllable(bool areControllable)
{
    foreach(QGraphicsItem *item, items())
    {
        item->setFlag(QGraphicsItem::ItemIsSelectable,
                      areControllable);
        item->setFlag(QGraphicsItem::ItemIsMovable,
                      areControllable);
    }
}

