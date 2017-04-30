// template

#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "frectangle.hpp"

int main(int argc, char **argv){
   window w( 128, 64, 2 );

   frectangle box( w, 0, 0, 30, 30 );
   frectangle box2( w, 80, 20, 100, 50 );
   box.print();
   box2.print();

   w.mainloop();
}
