#ifndef DIAGRAMMSCENE_H
#define DIAGRAMMSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <iostream>

#include "cmath"
#include "diagrammDataModel.h"
#include "diagrammScaleItem.h"
#include "diagrammChartItem.h"

/*
* Die Klasse DiagramScene realisiert die Verwaltung der aller Diagramme (@diagrammChartItem), dem Skalen Item
* (@diagrammScaleItem)und sonstigen Items. Diese Klasse ist eine Spezialisierung von QGraphicsScene.
*
* The class diagramScene implements the organisation of the diagrams, the scale and other items. Its derived from QGraphicsScene.
*/

class DiagrammScene : public QGraphicsScene {

    Q_OBJECT

public :

        /*
        * Der Konstruktor der Szene. Er kann ein Parent Widget haben. Er muss mit dem daten Model initialisiert werden.
        * Der Konstruktor übernimmt ausserdem die Initialiserung der Diagramme.
        *
        * The constructor can be initialized with a parent Widget but must be initialized with a set of data Model. With this set
        * the constructor initialisez the diagram items.
        */
        DiagrammScene(QSet<DiagrammDataModel*>* functions, QWidget* parent = 0);
        ~DiagrammScene();

private :

        /*
        * Dieses QGraphicsLineItem dient dazu eine Art Messlatte an die Diagramm anzulegen.
        *
        * This QGraphicsLineItem is used to help indicating the position on the x-axis.
        */
        QGraphicsLineItem* verticalMousePos;

        /*
        * Die X-Achse als Zeitskala (@diagrammScaleItem.h).
        *
        * The x-axis as timescale (@diagrammScaleItem.h).
        */
        DiagrammScaleItem* timeScale;

        /*
        * Offeset Wert der Angibt wiviel freier Platz zwischen den Diagrammen ist.
        *
        * Offeset values which indicate the free space between the diagramms.
        */
        int yAxisSubstituteOffset;

protected :

        /*
        * Diese Methode realisiert die Anpassung der vertikalen "Messstreifens" und leitet alle Diagramme dazu an ihre Werttexte
        * anzupassen.
        *
        * This method implements the vertical line to indicate the values at the current position.
        */
        void mouseMoveEvent(QGraphicsSceneMouseEvent * event);

signals :

        /*
        * Dieses Signal wird emittet, immer dann wenn die Szene eine MouseMoveEvent empfängt. Es verbindet diese Szene mit den
        * einzelnen Diagrammen und sorgt dafür das sie ihre Textuelle Repräsentation des Wertes anpassen.
        *
        * This signal is emitted everytime the class receives a mouseMoveEvent. It connects the scene to the diagramms.
        */
        void updateTextValue(int x);

};

#endif // DIAGRAMMSCENE_H
