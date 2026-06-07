#pragma once
#include "raylib.h"
#include "gdata.h"
#include <cstdlib>

//菜单
class r3{
private:
    int choose; //1, START 2, SETTING 3, RESTART
    bool inited = false;
    Image img;
    Texture png;
    Music mus;
    Sound snd;

public:
    void init();
    int update();
    void draw();
    void del();
};