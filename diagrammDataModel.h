#ifndef DIAGRAMMDATAMODEL_H
#define DIAGRAMMDATAMODEL_H

#include <QVector>
#include <QMap>
#include <QString>

#include "iostream"
#include "cmath"

/*
* Die Klasse DiagrammDataModel dient dazu ein Datenfundament für das Graphische Darstellung zu liefern. Sie bietet
* Methoden um schnell auf Werte zu greifen zu können.
*
* The class DiagrammDataModel provides a fundament to access the values fast.
*/
class DiagrammDataModel {

public :
        /*
        * Konstruktor um das Model mit einem Polynom zu initialisieren .
        *
        * Float an der Stelle i gibt den Koeffizienten von Grad i an usw.
        * Ein nicht existenter Grad hat den Koeffizienten 0.
        *
        * Constructor to init the model with the given polynom.
        */
        DiagrammDataModel(QVector<float>* _koeffizienten, QString name);

        /*
        * Konstruktor um das Model mit Intervallen zu initialisieren.
        * Dabei gilt im Intervall der entsprechende Wert des Anfangs.
        *
        * Constructor to init the model with the given interval.
        */
        DiagrammDataModel(QMap<float,float>* _intervalle, QString name);


        ~DiagrammDataModel();

        /*
        * Methode um an den zu einem X gehörenden Y Wert zu gelangen.
        *
        * This method returns to a Y value the corresponding X Value.
        */
        float getValueFor(float x);

        /*
        * Getter Methode für den Namen des Models.
        *
        * Getter method to access the name of the model.
        */
        QString getName();

        /*
        * Diese Methode gibt zurück ob es sich um ein Intervall oder Polynom Modell handelt.
        *
        * This method returns the type of the model.
        *
        * Intervall = 0;
        * Polynom = 1;
        */
        int getModelType();

        /*
        * Setter Methode um das Model mit einem Polynom zu setzten.
        *
        * Setter method to set the model with a polynom.
        */
        void setModel(QVector<float>* _koeffizienten);

        /*
        * Setter Methode um das Model mit einem Intervall zu setzten.
        *
        * Setter method to set the model with an interval.
        */
        void setModel(QMap<float,float>* _intervalle);

        /*
        * Setter Methode um den Namen des Models zu setzten.
        *
        * Setter method to set the name of the model.
        */
        void setName(QString _name);

private :

        /*
        * Intervall = 0;
        * Polynom = 1;
        */
        int modelType;

        /*
        * Der Name des Models.
        *
        * The name of the model.
        */
        QString name;

        /*
        * Die Koeffizienten des Models wenn das Model ein Polynom ist.
        *
        * The coefficients of the model if the model is a polynom.
        */
        QVector<float>* koeffizienten;

        /*
        * Das Intervall des Modells wenn das Model mit einem Intevall initialisiert ist.
        *
        * The interval of the model.
        */
        QMap<float,float>* intervalle;

};


#endif // DIAGRAMMDATAMODEL_H
