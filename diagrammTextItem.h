#ifndef DIAGRAMMTEXTITEM_H
#define DIAGRAMMTEXTITEM_H

#include <QGraphicsTextItem>
#include <QRectF>

#include "iostream"

class DiagrammTextItem : public QGraphicsTextItem {

    Q_OBJECT

public :

        DiagrammTextItem();
        ~DiagrammTextItem();

        QRectF boundingRect ();

        void setText(const QString & text);

private :

        QRectF boundingRect;

};


#endif // DIAGRAMMTEXTITEM_H
