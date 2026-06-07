#include "0.h"
#include "Text.h"
#include "gdata.h"

void r0::init(int type) {
    printf("------------------[room0]-------------------\n");
    soded = false;

    if (type == 1){
        txt.set("###", 0, 0, 25, 0.0f, 10, "res/fx/nsay.wav");
        Data::HP = 94;
        Data::Name = "Chara";
        Data::pHP = 0;
    }
    else txt.set("####", 0, 0, 25, 0.0f, 10, "res/fx/nsay.wav");
    img = LoadImage("res/img/spr_undertaletitle.png");
    ImageResizeNN(&img, 640, 480);
    png = LoadTextureFromImage(img);
    UnloadImage(img);
    if (type == 2)
        s = LoadSound("res/mus/intronoise.wav");
    inted = true;
}

int r0::update(int type) {
    if (not inted)init(type);

    if (type == 1){
        if (txt.isfin()){
            UnloadTexture(png);
            txt.del();
            inted = false;
            return 1;
        }
        txt.next();
        return 0;
    }   
    else if(type == 2){
        if (txt.isfin()){
            UnloadSound(s);
            printf("--------end1----------%d\n", 1);
            UnloadTexture(png);
            printf("--------end2----------%d\n", 1);
            txt.del();
            printf("--------end3----------%d\n", 1);
            inted = false;
            printf("--------end4----------%d\n", 1);
            return 3;
        }if (not soded){
            PlaySound(s);
            soded = true;
        }
        txt.next();
        return 2;
    }
    return -1;
}

void r0::draw() {
    DrawTexture(png, 0, 0, WHITE);
}