#include <QtGui/QApplication>
#include "diagramm.h"
#include "diagrammDataModel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSet<DiagrammDataModel*>* modelSet= new QSet<DiagrammDataModel*>();

    QVector<float>* kof = new QVector<float>();
    kof->append(200);
    kof->append(-1);
    DiagrammDataModel* model = new DiagrammDataModel(kof, QString("Estimate"));
    modelSet->insert(model);

    QMap<float,float>* inter = new QMap<float,float>();
    inter->insert(0,50);
    inter->insert(100,150);
    model = new DiagrammDataModel(inter, QString("Departure"));
    modelSet->insert(model);

    kof = new QVector<float>();
    kof->append(0);
    kof->append(0.5);
    model = new DiagrammDataModel(kof, QString("Actual"));
    modelSet->insert(model);

    kof = new QVector<float>();
    kof->append(0);
    kof->append(0);
    kof->append(0.01);
    model = new DiagrammDataModel(kof, QString("temp"));
    modelSet->insert(model);

    Diagramm* d = new Diagramm(modelSet);
    d->show();

    return a.exec();
}
