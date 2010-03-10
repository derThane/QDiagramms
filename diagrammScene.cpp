#include "diagrammScene.h"

DiagrammScene :: DiagrammScene(QSet<DiagrammDataModel*>* functions, QWidget *parent) : QGraphicsScene(parent),
yAxisSubstituteOffset(10)
{

    timeScale = new DiagrammScaleItem(QPair<int,int>(0,200),200,0);
    addItem(timeScale);

    int i = 0;
    int scaleYLength = 200;
    foreach(DiagrammDataModel* tmpModel, *functions){
        DiagrammChartItem* tmpGroup = new DiagrammChartItem(tmpModel->getName(), tmpModel, timeScale);

        connect(this,SIGNAL(updateTextValue(int)),tmpGroup,SLOT(updateValueText(int)));

        QGraphicsTextItem* tmpText = new QGraphicsTextItem();
        tmpText->rotate(-90);
        tmpText->setFlag(QGraphicsItem::ItemIgnoresTransformations, true);
        tmpGroup->addToGroup(tmpText);

        tmpGroup->translate(i*(scaleYLength + yAxisSubstituteOffset),0);
        addItem(tmpGroup);
        ++i;
    }

    verticalMousePos = new QGraphicsLineItem();
    verticalMousePos->setPen(QPen(Qt::red));
    addItem(verticalMousePos);
}

DiagrammScene :: ~DiagrammScene() {
    delete timeScale;
}

void DiagrammScene :: mouseMoveEvent(QGraphicsSceneMouseEvent * event) {

    int scaleLength = timeScale->getScaleLength();

    if(event->scenePos().x() < scaleLength && event->scenePos().x() > 0) {
        verticalMousePos->setLine(event->scenePos().x(),0,event->scenePos().x(),sceneRect().y());
        emit(updateTextValue(event->scenePos().x()));
    } else if(event->scenePos().x() > scaleLength){
        verticalMousePos->setLine(scaleLength,0,scaleLength,sceneRect().y());
        emit(updateTextValue(scaleLength));
    } else if(event->scenePos().x() < 0){
        verticalMousePos->setLine(0,0,0,sceneRect().y());
        emit(updateTextValue(0));
    }

    update();
}

