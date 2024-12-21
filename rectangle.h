#include <iostream>

class Rectangle
{
    private:
        int width_=0;
        int height_=0;
    public:
        Rectangle(int width, int height);
        void setvalue(int width,int height);
        int area()
        {
            return width_*height_;
        }
        int perimeter()
        {
            return 2*(width_+height_);
        }
};