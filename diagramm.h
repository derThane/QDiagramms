#ifndef DIAGRAMM_H
#define DIAGRAMM_H

#include <QWidget>
#include <QResizeEvent>
#include <QSet>

#include "iostream"
#include "diagrammScene.h"
#include "diagrammDataModel.h"
#include "diagrammView.h"

/*
* Das Diagramm ist die Oberklasse zur Darstellung und Verwaltung von Datenmengen in Diagrammen. Das Prinzip ist, du gibt mir die * * Daten, ich geb dir ne graphische Visualisierung.
*
* This class is the entry point to show data in a diagramm. Create this class with a set of data and get a visualisation back,
* thats the main principle.
*
* //Todo einen Konstruktor schreiben der das Diagrammwidget mit dem von Kai bereitgetellten Modell intialisiert und es in das diagrammDataModel überträgt.
*/

class Diagramm : public QWidget {

    Q_OBJECT

public :

        /*
        * Der Konstruktor für das Widget. Man kann ein parent Widget angeben. Man muss eine Menge von Datenmodellen eingeben
        * (@diagrammDataModel.h). Hauptfunktion ist die Intialisierung der Scene und des Views. Ausserdem wird das Mousetracking
        * für das Widget aktiviert.
        *
        * The constructor for the Widget. You can specify the parent Widget. You must specify a set of data (@diagrammDataModel.h)
        * Mainpurpose of the constructor is to initialize the scene and the view for the widget. Additionally it enables
        * mousetracking for the widget.
        */
        Diagramm(QSet<DiagrammDataModel*>* functions, QWidget* parent = 0);
        ~Diagramm();

private :

        /*
        * Die Szene welche alle anzuzeigenden Items verwaltet. Für mehr Informationan @diagrammScene.h schauen.
        *
        * The scene used to keep track of all items. Look @diagrammScene.h for more information.
        */
        DiagrammScene* mainScene;

        /*
        * Der View dient zur Visualisierung einer Szene. Für Mehr Informationen @diagrammView.h schauen.
        *
        * The view is used to visualize a scene. Look @diagrammView.h for more information.
        */
        DiagrammView* mainView;

protected :

        /*
        * Das showEvent wird aufgerufen wenn das Widget aktiv wird, sprich gezeigt wird. Diese spezialisierte Methode
        * initialisiert Paramater für das Widget. Spezialisiert von QWidget.
        *
        * The showEvent is called wenn the the Widget is shown. This method initialises some parameters for the widget.
        * Generalized from QWidget.
        */
        void showEvent(QShowEvent * event);

        /*
        * Das resizeEvent wird aufgerufen wenn sich die Geometrie, des Widgets verändert. Dies übernimmt das QT-Framework
        * Aufgabe dieser Methode ist es die Größe und Position der Elemente im Widget anzupassen, so das alle sichtbare Elemente
        * im Widget angezeigt werden. Spezialisiert von QWidget.
        *
        * The resizeEvent is called every time the geometry of the widgets change. Qt keeps track of geometry Change and calls
        * this method. The pourpose of this method is adapting all items of fit in the view. Generalized from QWidget.
        */
        void resizeEvent(QResizeEvent * event);


};

#endif // DIAGRAMM_H
