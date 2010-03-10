#include "diagrammChartItem.h"

DiagrammChartItem :: DiagrammChartItem(QString _name, DiagrammDataModel* _dataModel, DiagrammScaleItem* _timeScale) : QGraphicsItemGroup(),
name(_name),
dataModel(_dataModel),
timeScale(_timeScale)
{

    valueText = new QGraphicsTextItem();
    valueText->setFlag(QGraphicsItem::ItemIgnoresTransformations, true);
    valueText->setPos(0,0);
    addToGroup(valueText);


    scaleYLength = 200;
    scaleYMin = 0;

    QGraphicsLineItem* xAchse = new QGraphicsLineItem(0,0,0,_timeScale->getScaleLength());
    addToGroup(xAchse);

    QGraphicsLineItem* yAchse = new QGraphicsLineItem(0,0,scaleYLength,0);
    addToGroup(yAchse);

    //TODO Hier vernünftige Werte initialisieren
    /*
    int minYValue = dataModel->getValueFor(timeScale->getMinValue());
    int maxYValue = dataModel->getValueFor(timeScale->getMinValue());

    for(int i = 1; i <= scaleXLength; ++i){
        int tmp = dataModel->getValueFor(i*pixelToValueRatio + timeScale->getMinValue());

        if(tmp < minYValue){
            minYValue = tmp;
        }

        if(tmp > maxYValue){
            maxYValue = tmp;
        }
    }
    */

    int minYValue = 0;
    int maxYValue = scaleYLength;


    float scale;
    if(maxYValue != minYValue){
        scale = scaleYLength / (maxYValue - minYValue);
    } else {
        maxYValue = maxYValue + (scaleYLength / 2);
        if(minYValue > (scaleYLength / 2)){
            maxYValue = maxYValue - (scaleYLength / 2);
        } else {
            minYValue = 0;
        }
        scale = scaleYLength / (maxYValue - minYValue);
    }

    for(int i = xAchse->line().y1(); i < xAchse->line().y2(); i++){
        if((i % 10) == 0){
            QGraphicsLineItem* tmpLine = new QGraphicsLineItem(xAchse->line().x2(), i, yAchse->line().x2(), i);
            tmpLine->setPen(QPen(QBrush(Qt::black),0,Qt::DotLine,Qt::FlatCap,Qt::MiterJoin));
            addToGroup(tmpLine);
        }
    }

    for(int i = yAchse->line().x1(); i < yAchse->line().x2(); i++){
        if((i % 10) == 0){
            QGraphicsLineItem* tmpLine = new QGraphicsLineItem(i, yAchse->line().y2(), i, xAchse->line().y2());
            tmpLine->setPen(QPen(QBrush(Qt::black),0,Qt::DotLine,Qt::FlatCap,Qt::MiterJoin));
            addToGroup(tmpLine);

            QGraphicsTextItem* tmpText = new QGraphicsTextItem(QString("%1").arg(minYValue + (i * scale)));
            tmpText->setFlag(QGraphicsItem::ItemIgnoresTransformations, true);
            tmpText->setX(i + 10);
            tmpText->setY(yAchse->line().x1() - 10);
            addToGroup(tmpText);
        }
    }

    QGraphicsPathItem* graph = new QGraphicsPathItem();

    path.moveTo(dataModel->getValueFor(0),0);

    for(int i = 1; i <=_timeScale->getScaleLength(); ++i){
        if(dataModel->getValueFor(i * _timeScale->getPixelToValueRatio() + _timeScale->getMinValue()) < maxYValue && dataModel->getValueFor(i * _timeScale->getPixelToValueRatio() + _timeScale->getMinValue()) > minYValue){
            path.lineTo(dataModel->getValueFor(i * _timeScale->getPixelToValueRatio() + _timeScale->getMinValue()) - minYValue, i);
        }
    }
    graph->setPath(path);

    //setCosmetic sorgt dafür das Transformationen die stärke nicht beeinflussen
    QPen tmpPen(QBrush(Qt::darkCyan),2,Qt::SolidLine,Qt::FlatCap,Qt::RoundJoin);
    tmpPen.setCosmetic(true);
    graph->setPen(tmpPen);

    QGraphicsTextItem* caption = new QGraphicsTextItem(name);
    caption->setFlag(QGraphicsItem::ItemIgnoresTransformations,true);
    caption->setX(scaleYLength);
    caption->setY(_timeScale->getScaleLength());

    addToGroup(caption);

    addToGroup(graph);
    rotate(270);
}

DiagrammChartItem :: ~DiagrammChartItem(){

}

void DiagrammChartItem :: updateValueText(int value){

    valueText->setPlainText(QString("Y : %1").arg(dataModel->getValueFor(value)));    

    if(dataModel->getValueFor(value) > scaleYLength + scaleYMin){
        valueText->setPos(scaleYLength, value);
    } else if(dataModel->getValueFor(value) < scaleYMin + valueText->boundingRect().height()){
        valueText->setPos(scaleYMin + valueText->boundingRect().height(), value);
        if(valueText->collidesWithPath(path)){
            valueText->setPos(scaleYMin + valueText->boundingRect().height() * 2, value);
        }
    } else {
        valueText->setPos(dataModel->getValueFor(value), value);
    }
}
