#include "Polygon.h"
#include <iostream>

using namespace std;

Polygon::Polygon()
{
    //ctor
}

Polygon::Polygon(int newWidth, int newHeight){
    width = newWidth;
    height = newHeight;

}


void Polygon::setWidth(int newWidth){
    width = newWidth;

}


void Polygon::setHeight(int newHeight){
    height = newHeight;

}


