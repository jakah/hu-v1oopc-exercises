#ifndef VICTIM_HPP
#define VICTIM_HPP

#include "rectangle.hpp"

class victim : public rectangle {
protected:
    bool hit;
public:
    victim(window & w, vector start, vector end);
    void interact( drawable & other ) override;
    void update() override;
};

#endif // VICTIM_HPP
