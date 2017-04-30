#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "train.hpp"

/// @file
/// \brief
/// main function
/// \details
/// This is the main function, it creates a window and prints two trains,
/// one with smoke and one without smoke.
int main(int argc, char **argv){
   window w( 128, 64, 2 );

   train trein (w,5,20,0);
   train stoomtrein (w,50,20,1);
   trein.print();
   stoomtrein.print();

   w.mainloop();
}
