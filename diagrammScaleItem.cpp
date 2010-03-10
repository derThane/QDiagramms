#include "diagrammScaleItem.h"

DiagrammScaleItem :: DiagrammScaleItem(QPair<int,int> _scaleInterval, int _scaleLength, int _scaleType) :
    QGraphicsItemGroup(),
    scaleLength(_scaleLength),
    scaleType(_scaleType),
    scaleInterval(_scaleInterval),
    minValue(_scaleInterval.first),
    maxValue(_scaleInterval.second)
{

    if(_scaleLength == 0){
        scaleLength =  abs(_scaleInterval.second - _scaleInterval.first);
    }

    pixelToValueRatio = (float)abs(_scaleInterval.second - _scaleInterval.first) / (float)scaleLength;

        QGraphicsLineItem* topLine = new QGraphicsLineItem(0,0,scaleLength,0);
        addToGroup(topLine);

        QGraphicsLineItem* btmLine = new QGraphicsLineItem(0,25,scaleLength,25);
        addToGroup(btmLine);

        QGraphicsLineItem* leftLine = new QGraphicsLineItem(0,0,0,25);
        addToGroup(leftLine);

        QGraphicsLineItem* rightLine = new QGraphicsLineItem(scaleLength,0,scaleLength,25);
        addToGroup(rightLine);

        for(int i = 0; i <= topLine->line().x2(); i++){
            if(i % 10 == 0) {
                QGraphicsLineItem* tmpLine = new QGraphicsLineItem(i,2,i,23);
                addToGroup(tmpLine);

                QGraphicsTextItem* tmpText = new QGraphicsTextItem(QString("%1").arg(i * pixelToValueRatio + minValue,0,'g',3));
                tmpText->setFlag(QGraphicsItem::ItemIgnoresTransformations, true);
                tmpText->setX(i);
                tmpText->setY(topLine->line().y2() + 25);
                addToGroup(tmpText);
            } else if (i % 5 == 0) {
                QGraphicsLineItem* tmpLine = new QGraphicsLineItem(i,5,i,20);
                addToGroup(tmpLine);
            } else {
                QGraphicsLineItem* tmpLine = new QGraphicsLineItem(i,10,i,15);
                addToGroup(tmpLine);
            }
        }
}

DiagrammScaleItem :: ~DiagrammScaleItem(){


}


double DiagrammScaleItem :: mapPixelToValue(int _pixel){
    //TODO
    return 0;
}

int DiagrammScaleItem :: mapValueToPixel(double _value){
    //TODO
    return 0;
}
