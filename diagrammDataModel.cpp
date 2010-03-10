#include "diagrammDataModel.h"

DiagrammDataModel :: DiagrammDataModel(QMap<float,float>* _intervall, QString _name){
    intervalle = new QMap<float,float>(*_intervall);
    modelType = 0;
    name = _name;
}

DiagrammDataModel :: DiagrammDataModel(QVector<float> *_koeffizienten, QString _name){
    koeffizienten = new QVector<float>(*_koeffizienten);
    modelType = 1;
    name = _name;
}

DiagrammDataModel :: ~DiagrammDataModel(){
    delete koeffizienten;
    delete intervalle;

}


int DiagrammDataModel :: getModelType(){
    return modelType;
}

QString DiagrammDataModel :: getName(){
    return name;
}

void DiagrammDataModel :: setModel(QMap<float, float> *_intervalle){
    delete intervalle;
    intervalle = new QMap<float,float>(*_intervalle);
    modelType = 0;
}

void DiagrammDataModel :: setModel(QVector<float> *_koeffizienten){
    delete koeffizienten;
    koeffizienten = new QVector<float>(*_koeffizienten);
    modelType = 1;
}

float DiagrammDataModel :: getValueFor(float _x){

    float returnValue = 0;

    switch(modelType) {

    case 0 : {

            QMap<float,float>::const_iterator it;
            for(it = intervalle->begin(); it != intervalle->end(); ++it){
                if(it.key() > _x){
                    return returnValue;
                }
                returnValue = it.value();
            }
        }
        break;

    case 1 : {
            for(int i = 0; i < koeffizienten->size(); ++i){
                returnValue += koeffizienten->at(i) * pow(_x,i);
            }
        }
        break;
    }

    return returnValue;
}
