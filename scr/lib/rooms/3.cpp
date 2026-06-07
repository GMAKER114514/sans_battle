#include "3.h"

void r3::init(){
    int randomIndex = rand() % 7;
    
    // 构造文件名并加载
    char filename[64];
    sprintf(filename, "res/mus/mus_menu%d.ogg", randomIndex);
    
    choose = 1;
    mus = LoadMusicStream(filename);
    PlayMusicStream(mus);
    snd = LoadSound("res/fx/choose.wav");
    img = LoadImage("res/img/menu.png");
    ImageResizeNN(&img, img.width * 2, img.height * 2);
    png = LoadTextureFromImage(img);
    UnloadImage(img);

    inited = true;
}

int r3::update(){
    if (not inited)init();
    UpdateMusicStream(mus);
    if (IsKeyPressed(KEY_UP)){choose -= 1;PlaySound(snd);}
    if (IsKeyPressed(KEY_DOWN)){choose += 1;PlaySound(snd);}
    if (choose == 4)choose = 1;
    if (choose == 0)choose = 3;
    if (IsKeyPressed(KEY_Z)){
        PlaySound(snd);
        del();
        if (choose == 1)return 5;
        if (choose == 2)return 4;
        if (choose == 3)return 0;
    }
    return 3;
}

void r3::draw(){
    DrawTexture(png, 0, -250, WHITE);
    if (choose == 1){
        DrawText("START", 280, 230, 20, YELLOW);
        DrawText("SETTINGS", 280, 250, 20, WHITE);
        DrawText("RESET", 280, 270, 20, WHITE);
    }
    else if (choose == 2){
        DrawText("START", 280, 230, 20, WHITE);
        DrawText("SETTINGS", 280, 250, 20, YELLOW);
        DrawText("RESET", 280, 270, 20, WHITE);
    }
    else if (choose == 3){
        DrawText("START", 280, 230, 20, WHITE);
        DrawText("SETTINGS", 280, 250, 20, WHITE);
        DrawText("RESET", 280, 270, 20, YELLOW);
    }
    DrawText(Data::Name.c_str(), 5, 450, 10, GRAY);
    if (Data::Name == "Chara")DrawText("Lv.20", 5, 465, 10, GRAY);
    DrawText("Made by KICE", 560, 465, 10, GRAY);
}

void r3::del(){
    UnloadMusicStream(mus);
    UnloadTexture(png);
    UnloadSound(snd);
    inited = false;
}