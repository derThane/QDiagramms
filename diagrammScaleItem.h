#ifndef DIAGRAMMSCALEITEM_H
#define DIAGRAMMSCALEITEM_H

#include <QGraphicsItemGroup>
#include <QPair>
#include <QRectF>

/*
* Die Klasse DiagrammScaleItem stellt neben der Graphischen Visualisierung der Skala auch Funktionen zur verfügung, Eigenschaften,
* wie den Startpunkt der Skala, Länger der Skala usw. zu betrachten. Sie erbt wie von QGraphicsItemGroup.
*
* The class DiagrammScaleItem provides a graphic visualisation of the scale and functions to access certain parameter of the scale
*/
class DiagrammScaleItem : public QGraphicsItemGroup {

public :
        /*
        * _scaleInterval gibt das Interval an das auf der Skala angezeigt wird
        * _scaleLength gibt die Länge der Skala in Pixel an
        * _scaleType legt den SkalenType fest ( 0 = normale IntervalSkala, 1 = ZeitSkala )
        *
        */
        DiagrammScaleItem(QPair<int, int>_scaleInterval, int _scaleLength, int _scaleType);
        ~DiagrammScaleItem();

        /*
        * Diese Funktion realisiert die Umrechnung eines Wertes in den dazu gehörigen Pixel auf der Skala.
        *
        * This method provides functionality to map a value to the corresponding pixel.
        */
        int mapValueToPixel(double _value);

        /*
        * Diese Funktion realisiert die Umrechung eines Pixel in den dazugeörigen Wert.
        *
        * This method provides functionality to map a pixel to a corresponding value.
        */
        double mapPixelToValue(int _pixel);

        /*
        * Getter Methode die die Länge der Skala liefert.
        *
        * Getter method wich returns the length of the scale.
        */
        int getScaleLength(){return scaleLength;}

        /*
        * Getter Methode die den Typ der Skala liefert.
        *
        * Getter method wich returns the type of the scale.
        */
        int getScaleType(){return scaleType;}

        /*
        * Getter Methode die das Minimum der Skala zurück gibt.
        *
        * Getter method wich returns the minimum of the scale.
        */
        int getMinValue(){return minValue;}

        /*
        * Getter Methode die das Maximum der Skala zurück gibt.
        *
        * Getter method wich returns the maximum of the scale.
        */
        int getMaxValue(){return maxValue;}

        /*
        * Diese Funktion gibt das Verhältnis zwischen Pixel und Werten zurück
        *
        * This method return the ratio of pixel to value.
        */
        float getPixelToValueRatio(){return pixelToValueRatio;}

private :

        int scaleLength;
        int scaleType;

        int minValue;
        int maxValue;
        float pixelToValueRatio;

        QPair<int,int> scaleInterval;

protected :


};

#endif // DIAGRAMMSCALEITEM_H
