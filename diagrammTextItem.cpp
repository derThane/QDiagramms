#include "diagrammTextItem.h"

DiagrammTextItem :: DiagrammTextItem() : QGraphicsTextItem()
{

}

DiagrammTextItem :: ~DiagrammTextItem() {

}

void DiagrammTextItem::setText(const QString & text){
    setPlainText(text);
}

QRectF DiagrammTextItem :: boundingRect(){

    std::cout << " Yeah " << std::endl;
    return QRectF();
}
