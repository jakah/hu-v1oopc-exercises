#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "wall.hpp"
#include "victim.hpp"

int main(){
   window w( vector( 128, 64 ), 2 );
   wall top( w, vector(   0,  0 ), vector( 124,  4 ),1, vector(1,-1) );
   wall right( w, vector( 120,  0 ), vector( 124, 60 ),2, vector(-1,1) );
   wall bottom( w, vector(   0, 60 ), vector( 124, 64 ),3, vector(1,-1) );
   wall left( w, vector(   0,  0 ), vector(   4, 60 ),4, vector(-1,1) );
   ball b( w, vector( 15, 15 ), 9, vector( 5, 2 ) );
   victim v (w,vector(20, 30), vector(40,50));
   drawable * objects[] = { &b, &top, &left, &right, &bottom, &v};

   for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
      wait_ms( 200 );
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

