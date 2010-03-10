#ifndef DIAGRAMMCHARTITEM_H
#define DIAGRAMMCHARTITEM_H

#include <QGraphicsItemGroup>
#include <QBrush>
#include <QPen>

#include "diagrammDataModel.h"
#include "diagrammScaleItem.h"

/*
* Das DiagrammChartItem repräsentiert ein Diagramm als Gegenstand einer Scene. Diese Klasse ist eine Speziallisierung von
* QGraphicsItemGroup. Sie besteht aus einer Y Skala mit Beschriftung, einer X Achse ohne Beschriftung, eines Rastergitters,
* dem Graphen und einem Textfeld das den aktuellen Wert angibt.
*
* The diagrammChartItem represents a diagramm as item in the scene. This class is a generalisation of QGraphicsItemGroup and
* contains the following items : a y scale with notation, a x scale without notation, the graph to visualize the data and a
* textfield indicating the actual value.
*/

class DiagrammChartItem : public QObject, public QGraphicsItemGroup{

    Q_OBJECT

public :

        /*
        * Der Konstruktor benötigt einen Namen, eine DatenModel (@diagrammDataModel.h) und eine globale X-Skala
        * (@diagrammScaleItem.h). Neben der Initialiserung der Variablen übernimmt der Konstruktor auch das Zeichnen
        * aller Elemente des Diagramm Items.
        *
        * The constructor needs a name, a datamodel (@diagrammDataModel.h) and a global scale (@diagrammScaleItem.h). Besides
        * the initialization of the local variables, the constructor paints all elements of the class.
        */
        DiagrammChartItem(QString _name, DiagrammDataModel* _dataModel, DiagrammScaleItem* _timeScale);
        ~DiagrammChartItem();

        /*
        * Getter Methode für den Namen des Diagramms.
        *
        * Getter method to acces the name of the diagram.
        */
        QString getName(){return name;}

private :

        /*
        * Der Name des Diagramms.
        *
        * The name of the diagram.
        */
        QString name;

        /*
        * Das dem Diagramm zugrunde liegende Datenmodel (@diagrammDataModel.h).
        *
        * The databasis for the diagram (@diagrammDataModel.h).
        */
        DiagrammDataModel* dataModel;

        /*
        * Die Zeitskala. Stellt Funktionalitäten zur Bestimmung von Koordinaten usw. bereit (@diagrammScaleItem.h).
        *
        * The timescale. Provides functionality to determinate certain usefull parameters (@diagrammScaleItem.h).
        */
        DiagrammScaleItem* timeScale;

        /*
        * Das QGraphicsTextItem das den aktuell bestimmten wert anzeigt.
        *
        * The QGraphicsTextItem indicating the actual marked value.
        */
        QGraphicsTextItem* valueText;

        /*
        * Dieser QPainterPath repräsentiert den Graph.
        *
        * The QPainterPath represents the actual graph.
        */
        QPainterPath path;

        /*
        * Die Länge der Y-Achse in Pixel.
        *
        * The length of the y scale in pixel.
        */
        int scaleYLength;

        /*
        * Der Startwertpunkt der Y-Achse.
        *
        * The startpoint of the y axis.
        */
        int scaleYMin;

public slots :

        /*
        * Dieser Slot realisiert die "Bewegung" des Werte textes. Bei jedem MouseMoveEvent das die Scene empfängt wird er
        * aufgerufen.
        *
        * This slot implements the "movement" of the QGraphicsTextItem indicating the current marked value. This slot is called
        * every time the MouseMoveEcent is triggerd in the scene.
        */
        void updateValueText(int value);

};

#endif // DIAGRAMMCHARTITEM_H
