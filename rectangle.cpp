#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle(int width=0, int height=0) 
{ 
    setvalue(width,height);
}
void Rectangle::setvalue(int width, int height)
{
    if(width<0)
        width=0;
    if(height<0)
        height=0;
    width_=width;
    height_=height;
}