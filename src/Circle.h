
#pragma once

#include "Shape.h"

class Circle : public Shape{

    public:
		Circle(const Mat& img);
        ~Circle();

        Mat Find();
};
