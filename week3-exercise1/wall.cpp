#include "wall.hpp"

wall::wall(window& w, const vector& start, const vector& end, const int& update_interval):
    rectangle(w, start, end),
    filled(true),
    update_interval(update_interval),
    box(w, start, end)

{
}

void wall::draw()
{
    if(filled == true) {
        for(int y = start.y; y < end.y; y++) {
            for(int x = start.x; x < end.x; x++) {
                w.draw(vector(x, y));
            }
        }
    }
    box.draw();
}

void wall::update(){
    update_count++;
    if ((update_count % update_interval) == 0){
        if (filled == true){
            filled = false;
        }
        else if (filled == false){
            filled = true;
        }
    }
}
