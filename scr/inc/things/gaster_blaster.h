#pragma once
#include "move.h"
#include "raylib.h"
#include <cstdio>
struct gb_state{
    bool live = false;
    Vector2 local;
    Vector2 too;
    int direct;
    int n_drect;
    int state;
    //0~10进入
    //11~20准备开炮
    //21~30开炮
    int state2;
    int mwide;
    int fade;
    bool a;
    bool p = false; //false增加
    bool di;
};

class gb{
private:
    gb_state gbs[400];
    Sound wav1;
    Sound wav2;
    Texture pngs[6];
public:
    int create_gb(Vector2 local, int drtect);
    void init();
    void update_gbs();
    void del_gb(int num);
    void draw_gbs();
    void set_gb(int where, int nnum, int num);
};