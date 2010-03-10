#include "diagramm.h"

Diagramm :: Diagramm(QSet<DiagrammDataModel*>* functions, QWidget *parent) : QWidget(parent)
{
    mainScene = new DiagrammScene(functions, this);
    mainView = new DiagrammView(mainScene, this);

    setMouseTracking(true);
}

Diagramm :: ~Diagramm() {
    delete mainScene;
    delete mainView;

}

void Diagramm :: showEvent(QShowEvent * event) {
    setMinimumWidth(500);
    setMinimumHeight(500);
}


void Diagramm :: resizeEvent (QResizeEvent * event ) {
    mainView->resize(width(), height());
    mainView->fitInView(mainScene->sceneRect().x(),mainScene->sceneRect().y(),mainScene->sceneRect().width(), mainScene->sceneRect().height());
}

