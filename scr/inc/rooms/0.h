#pragma once
#include "raylib.h"
#include "Text.h"
#include "gdata.h"

class r0{
private:
    bool soded = false;
    bool inted = false;
    Texture2D png;
    Image img;
    Sound s;
    sText txt;
public:
    void init(int type);
    int update(int type);
    void draw();
};