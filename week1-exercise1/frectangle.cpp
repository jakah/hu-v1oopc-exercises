#include "frectangle.hpp"
/// @file

/// \brief
/// initializes a filled rectangle
/// \details
/// This constructor generates a filled rectangle by storing the top left
/// corner and the bottom right corner.
frectangle::frectangle(window &w, int start_x, int start_y, int end_x, int end_y):
   start_x(start_x),
   start_y(start_y),
   end_x(end_x),
   end_y(end_y),
   w (w)
{}

/// \brief
/// print a filled rectangle
/// \details
/// Print a filled rectangle to the screen. It loops trough the horizontal lines
/// and for each vertical one it prints it to the screen.
void frectangle::print(){
   for(int y = start_y; y <= end_y; y++){
      for(int x = start_x; x <= end_x; x++ ){
         w.draw(x,y);
      }
   }
}
