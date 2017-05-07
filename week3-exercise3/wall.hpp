#ifndef WALL_HPP
#define WALL_HPP

#include "window.hpp"
#include "drawable.hpp"
#include "vector.hpp"
#include "rectangle.hpp"

class wall : public rectangle {
private:    
    bool filled;
    int update_interval;
    int update_count;
    rectangle box;
public:
    wall(window & w,const vector &start, const vector &end, const int &update_interval, const vector &bounce );
    void draw() override;
    void update() override;
};

#endif // WALL_HPP
