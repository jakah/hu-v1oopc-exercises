#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "wall.hpp"

int main(){
   window w( vector( 128, 64 ), 2 );
   wall top( w, vector(   0,  0 ), vector( 124,  4 ),2 );
   wall right( w, vector( 120,  0 ), vector( 124, 60 ),2 );
   wall bottom( w, vector(   0, 60 ), vector( 124, 64 ),2 );
   wall left( w, vector(   0,  0 ), vector(   4, 60 ),2  );
   ball b( w, vector( 50, 20 ),5, vector( 5, 5 ) );
   
   drawable * objects[] = { &b, &top, &left, &right, &bottom };

   for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
      wait_ms( 130);
      for( auto & p : objects ){
          p->update();
      }
      for( auto & p : objects ){
         for( auto & other : objects ){
            p->interact( *other );
         } 
      }
   }
}

