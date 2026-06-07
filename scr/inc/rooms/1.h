#pragma once
#include "raylib.h"
#include "Text.h"

class r1{
private:
    bool inted = true;
    int y = 0;
    int imgnum = 0;
    int w = 0;  //0,进入   1,开始   2，等待  3，结束   4，下一个  5，滚动
    float alpha = 0.0f;
    std::string text[11];
    Texture2D pngs[11];
    Image img[11];
    sText txt;
    Music music;
    
public:
    void init();
    int update();
    void draw();
    void reset() {
        imgnum = 0;
        w = 0;
        alpha = 0.0f;
        y = 0;
    }
};