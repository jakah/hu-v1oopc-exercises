
#include "train.hpp"
#include "rectangle.hpp"
/// @file
/// \brief
/// constructs a train
/// \details
/// This constructor creates a train. It makes two wheels, a few rectangles and
/// a line that should look like smoke.
train::train( window & w, int start_x , int start_y, int smoke_bool):
    start_x(start_x),
    start_y(start_y),
    smoke_bool( smoke_bool),
    wheel_left( w, start_x+5, start_y+30, 5),
    wheel_right( w, start_x+20, start_y+30, 5),
    bottom( w, start_x, start_y+20, start_x+30,start_y+25),
    top( w, start_x+10, start_y+10, start_x+29,start_y+20),
    cabin( w, start_x, start_y+5, start_x+10,start_y+20),
    chimney( w, start_x+20, start_y+5, start_x+25,start_y+10),
    smoke( w, start_x+15, start_y, start_x+22, start_y+5),
    w (w)
{}
/// \brief
/// print a train
/// \details
/// This function prints a train. It starts with the weels, then the rectangles
/// and if smoke_bool is 1 then a line will be printed that should look like
/// smoke
void train::print(){
    wheel_left.print();
    wheel_right.print();
    bottom.print();
    cabin.print();
    top.print();
    chimney.print();
    if (smoke_bool == 1){
      smoke.print();
    }
}
