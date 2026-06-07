#include "gaster_blaster.h"



void gb::init(){
    gb::pngs[0] = LoadTexture("res/img/sans/spr_gasterblaster/spr_gasterblaster_0.png");
    gb::pngs[1] = LoadTexture("res/img/sans/spr_gasterblaster/spr_gasterblaster_1.png");
    gb::pngs[2] = LoadTexture("res/img/sans/spr_gasterblaster/spr_gasterblaster_2.png");
    gb::pngs[3] = LoadTexture("res/img/sans/spr_gasterblaster/spr_gasterblaster_3.png");
    gb::pngs[4] = LoadTexture("res/img/sans/spr_gasterblaster/spr_gasterblaster_4.png");
    gb::pngs[5] = LoadTexture("res/img/sans/spr_gasterblaster/spr_gasterblaster_5.png");
    wav1 = LoadSound("res/fx/mus_sfx_segapower2.wav");
    wav2 = LoadSound("res/fx/mus_sfx_rainbowbeam_1.wav");
    for (int i = 0;i < 400;i ++){
        gbs[i].direct = 0;
        gbs[i].live = false;
        gbs[i].local = {0, 0};
        gbs[i].n_drect = 0;
        gbs[i].state = 0;
        gbs[i].too = {0, 0};
        gbs[i].p = false;
        gbs[i].mwide = 0;
        gbs[i].fade = 0;
    }
}

void gb::del_gb(int num){
    gbs[num].direct = 0;
    gbs[num].live = false;
    gbs[num].local = {0, 0};
    gbs[num].n_drect = 0;
    gbs[num].state = 0;
    gbs[num].too = {0, 0};
    gbs[num].p = false;
}

int gb::create_gb(Vector2 local, int drtect){
    int num = 0;
    for (;gbs[num].live;num ++){}
    printf("[room5]Laod GB,num:%d\n", num);
    gbs[num].direct = drtect;
    gbs[num].live = true;
    gbs[num].local = {0, 0};
    gbs[num].n_drect = 0;
    gbs[num].state = 0;
    gbs[num].too = local;

    

    

    return num;
}

void gb::draw_gbs(){
    for (int i = 0;i < 400;i ++){
        if(gbs[i].live){
            int s = gbs[i].state;
            if (0 <= s and s <= 10){
                int n =0;
                Rectangle sourceRect = { 0, 0, (float)pngs[n].width, (float)pngs[n].height };   // 选取纹理的哪一部分
                Rectangle destRect = { gbs[i].local.x, gbs[i].local.y, (float)pngs[n].width, (float)pngs[n].height }; // 绘制在屏幕上的位置和大小
                Vector2 origin = { 0.0f, 0.0f }; // 设置旋转中心点（本例为图像中心）

                DrawTexturePro(pngs[n], sourceRect, destRect, origin, gbs[i].direct, WHITE);
            }else if(11 <= s and s <= 20){
                int n = gbs[i].state2;
                DrawTexture(pngs[n], gbs[i].local.x, gbs[i].local.y, WHITE);
            }else if(21 <= s and s <= 30){
                int n = s % 10;
                //DrawRectangle(gbs[i].local.x + 13 - gbs[i].mwide / 2, gbs[i].local.y + 50, 20 + gbs[i].mwide, 900, Fade(WHITE, 1 - gbs[i].fade / 100.0f));
                Rectangle rect = {gbs[i].local.x + 13 - gbs[i].mwide / 2, gbs[i].local.y + 50, 20.0f + gbs[i].mwide, 900};
                Vector2 origin = { rect.width, rect.height};
                DrawRectanglePro(rect, origin, gbs[i].direct + 180, Fade(WHITE, 1 - gbs[i].fade / 100.0f));

                Rectangle sourceRect = { 0, 0, (float)pngs[n].width, (float)pngs[n].height };   // 选取纹理的哪一部分
                Rectangle destRect = { gbs[i].local.x, gbs[i].local.y, (float)pngs[n].width, (float)pngs[n].height }; // 绘制在屏幕上的位置和大小
                origin = { 0.0f, 0.0f }; // 设置旋转中心点（本例为图像中心）

                DrawTexturePro(pngs[n], sourceRect, destRect, origin, gbs[i].direct, WHITE);
                //DrawTextureEx(, {gbs[i].local.x, gbs[i].local.y}, gbs[i].direct, 1.0f, WHITE);

                if (n == 4)gbs[i].state += 1;
                else if (n == 5)gbs[i].state -= 1;
            }
        }
    }
}

void gb::update_gbs(){
    for (int i = 0;i < 400;i ++){
        if (gbs[i].live){
            int s = gbs[i].state;
            if ((s / 10) == 0){
                if (s % 10 == 0){
                    PlaySound(wav1);
                    gbs[i].state ++;
                }
                gbs[i].local = half_l(gbs[i].local, gbs[i].too);
                
                if (gbs[i].local.x >= (gbs[i].too.x - 5) and gbs[i].local.y>= (gbs[i].too.y - 5)){
                    gbs[i].state = 11;
                    
                    gbs[i].local.x = gbs[i].too.x;
                    gbs[i].local.y = gbs[i].too.y;

                    gbs[i].state2 = 0;
                }
            }else if((s / 10) == 1){
                if (gbs[i].state2 == 4){
                    gbs[i].state = 24;

                    gbs[i].a = false;
                    gbs[i].mwide = 8;
                    gbs[i].fade = 0;
                    gbs[i].di = false;
                }else{
                    gbs[i].state2 ++;
                }
            }else if((s / 10) == 2){
                if(not gbs[i].p){PlaySound(wav2);gbs[i].p = true;}
                int x = gbs[i].local.x;
                int y = gbs[i].local.y;
                if (x < -100 or x > 740 or y < -100 or y > 580){
                    gbs[i].di = true;
                    if ((not gbs[i].a) and gbs[i].fade > 100)del_gb(i);
                }
                if (not gbs[i].a){
                    if ((gbs[i].di and gbs[i].fade > 100)){gbs[i].a = true;printf("first:%d\n", gbs[i].di);continue;}
                    else if ((gbs[i].fade > 20 and not gbs[i].di)){gbs[i].a = true;printf("second:%d\n", gbs[i].di);continue;}
                    if(gbs[i].di){
                        gbs[i].fade += 5;
                        gbs[i].mwide -= 2;
                    }
                    gbs[i].fade += 5;
                    gbs[i].mwide -= 2;
                }else{
                    if (gbs[i].fade < 0){gbs[i].a = false;continue;}
                    gbs[i].fade -= 5;
                    gbs[i].mwide += 2;
                }
                if (not gbs[i].di)
                gbs[i].local = forward(gbs[i].local, -30, gbs[i].direct + 90);
            }
        }
    }
}