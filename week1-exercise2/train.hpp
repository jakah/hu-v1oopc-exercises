#ifndef TRAIN_HPP
#define TRAIN_HPP

#include "window.hpp"
#include "circle.hpp"
#include "line.hpp"
#include "rectangle.hpp"

class train {
    private:
        int start_x;
        int start_y;
        int smoke_bool;
        circle wheel_left, wheel_right;
        rectangle bottom;
        rectangle top;
        rectangle cabin;
        rectangle chimney;
        line smoke;
        window &w;

    public:
        train( window &w, int start_x , int start_y, int smoke_bool );
        void print();
};
#endif
