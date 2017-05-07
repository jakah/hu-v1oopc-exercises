#include "victim.hpp"
#include "rectangle.hpp"

victim::victim(window & w, vector start, vector end):
        rectangle(w, start, end),
        hit(false)
        {}

void victim::interact( drawable & other ){
   if( this != & other){
      if( overlaps( other )){
        hit = true;
      }
   }
}

void victim::update(){
    if(hit == true){
        *this = victim(w,start+ vector(1,1), end - vector(1,1));
    }
}


