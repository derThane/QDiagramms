#include "diagrammView.h"


DiagrammView :: DiagrammView(QGraphicsScene * scene, QWidget * parent) : QGraphicsView(scene,parent){
    setInteractive(true);
}

DiagrammView :: ~DiagrammView(){

}

