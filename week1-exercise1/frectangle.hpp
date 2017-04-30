#ifndef FRECTANGLE_HPP
#define FRECTANGLE_HPP

#include "window.hpp"

/// @file

/// \brief
/// filled rectangle
/// \details
/// This class creates a filled rectangle.
/// The x and y coordinates of the left corner (start_x and start_y) and of the
/// right corner (end_x and end_y) are stored as integers.
class frectangle {
private:
   int start_x, start_y, end_x , end_y;
   window &w;
public:
   /// \brief
   /// constructs a rectangle
   /// \details
   /// This constructor initializes a filled rectangle form two given points on
   /// the screen
   frectangle( window &w, int start_x, int start_y, int end_x, int end_y);

   /// \brief
   /// print the filled rectangle
   void print();
};

#endif
