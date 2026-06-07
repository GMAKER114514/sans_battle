#pragma once
#include "raylib.h"
#include "gaster_blaster.h"

class r5{
private:
    gb GB;
    int frame;
    bool inited = false;
public:
    int update();
    void draw();
};