#ifndef DIAGRAMMVIEW_H
#define DIAGRAMMVIEW_H

#include <QGraphicsView>

#include "iostream"

class DiagrammView : public QGraphicsView {

    Q_OBJECT

public :

        DiagrammView(QGraphicsScene * scene, QWidget * parent);
        ~DiagrammView();

private :

protected :
};

#endif // DIAGRAMMVIEW_H
