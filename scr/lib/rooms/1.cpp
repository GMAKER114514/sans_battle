#include "1.h"

void r1::init(){
    printf("------------------------[room1]---------------------\n");
    music = LoadMusicStream("res/mus/mus_story.ogg");
    PlayMusicStream(music);
    img[0] = LoadImage("res/img/spr_introimage/spr_introimage_0.png");
    img[1] = LoadImage("res/img/spr_introimage/spr_introimage_1.png");
    img[2] = LoadImage("res/img/spr_introimage/spr_introimage_2.png");
    img[3] = LoadImage("res/img/spr_introimage/spr_introimage_3.png");
    img[4] = LoadImage("res/img/spr_introimage/spr_introimage_4.png");
    img[5] = LoadImage("res/img/spr_introimage/spr_introimage_5.png");
    img[6] = LoadImage("res/img/spr_introimage/spr_introimage_6.png");
    img[7] = LoadImage("res/img/spr_introimage/spr_introimage_7.png");
    img[8] = LoadImage("res/img/spr_introimage/spr_introimage_8.png");
    img[9] = LoadImage("res/img/spr_introimage/spr_introimage_9.png");
    img[10] = LoadImage("res/img/spr_introimage/spr_introlast.png");

    for (int i = 0;i < 11;i ++){
        ImageResizeNN(&img[i], img[i].width * 2, img[i].height * 2);
        pngs[i] = LoadTextureFromImage(img[i]);
        UnloadImage(img[i]);
    }

    text[0] = "/WLong ago,# two races /~ruled over Earth:#/~HUMANS and MONSTERS.##";
    text[1] = "/WOne day, #war broke/~out bettwen the two /~races.##";
    text[2] = "/WAfter a long battle,##/~the humans were/~victorious.##";
    text[3] = "/WThey sealed the monsters/~underground with a magic/~spell.##";
    text[4] = "/WMany years later#.#.#.##";
    text[5] = "/W      MT. EBOTT/~         201X#########";
    text[6] = "/WLegends say that those/~who climb the mountain/~never return.######";
    text[7] = "/W######";
    text[8] = "/W######";
    text[9] = "/W######";
    text[10] = "/W############";
    reset();
}

int r1::update(){
    if (inted){
        r1::init();
        inted = false;
        printf(">>>[room1]:inited!\n");
    }
    else UpdateMusicStream(music);
    if (IsKeyPressed(KEY_Z)){
        imgnum = 10;
        if (w == 5){
            w = 3;
            return 1;
        }
        if (w == 2){
            w = 3;
            return 1;
        }
        if (w == 1){
            w = 3;
            return 1;
        }
    }
    switch (w)
    {
    case 4:
        w = 0;
        imgnum ++;
        break;
    case 0:
        alpha = 0.0f;
        w = 1;
        txt.set(text[imgnum].c_str(), 120, 300, 30, 0.05f, 25, "res/fx/nsay.wav");
        break;
    case 1:
        if (alpha >= 1.0f){
            w = 2;
            break;
        }
        alpha += 0.1f;
        break;
    case 2:
        if (imgnum == 10){
            if (txt.isfin()){
                w = 5;
                break;
            }
            txt.next();
        }
        if (txt.isfin()){
            w = 3;
            break;
        }
        txt.next();
        break;
    case 3:
        if (alpha <= 0.0f){
            w = 4;
            break;
        }
        alpha -= 0.1f;
        break;

    case 5:
        if (not (y >= 478))
            y += 2;
        else if (y == 478){
            y = 480;
            txt.set(text[imgnum].c_str(), 100, 400, 30, 0.05f, 25, "res/fx/nsay.wav");
        }else{
            if (txt.isfin()){
                w = 3;
                break;
            }
            txt.next();
        }
        break;
    
    default:
        break;
    }
    if (imgnum > 10){
        for(int i = 0; i < 11; i++)
        UnloadTexture(pngs[i]);
        txt.del();
        UnloadMusicStream(music);
        inted = true;
        return 2;
    }
    return 1;

}

void r1::draw(){
    if (not (imgnum == 10))
        DrawTexture(pngs[imgnum], 0, 0, Fade(WHITE, alpha));
    else
        DrawTextureRec(pngs[10], {0.0f, float(480.0f - y), 640.0f, 220.0f}, {0, 60}, Fade(WHITE, alpha));
    txt.draw();
}