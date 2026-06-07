#pragma once
#include "raylib.h"
#include "Timer.h"
#include <string>
/*
/W -> WHITE   ;0 ;#
/R -> RED     ;1 ;$
/Y -> YELLOW  ;2 ;%
/G -> GREEN   ;3 ;^
/B -> BLACK   ;4 ;&
/~ -> \n
*/
class sText{
private:
    std::string th = "";
    std::string now[256]; //绘制时使用
    static Sound sound;
    static int refCount;
    int pr = -1; //指向th
    int tpr = 0; //指向now
    int nc = 0; //当前颜色
    float nwait; //默认等待时间
    float wait = 0.1f;
    float last = 0.0f;
    int x;
    int y;
    int chrn = 0;  //每行字数
    int nchrn = 0;
    int size;
    bool go = true;
    bool all_n = false;
    bool isunload = false;
    Color color[5] = {WHITE, RED, YELLOW, GREEN, BLACK};
    Timer tim;
public:
    void set(const char* t, int sx, int sy, int xs, float waittime, int isize, std::string filepath);
    void next();
    void all_next();
    void draw();
    bool isfin();
    void del();
    //sText();
    //~sText();
};