#include <cstdio>
#include "raylib.h"
#include "Timer.h"
#include "1.h"
#include "0.h"
#include "3.h"
#include "5.h"
#include "gdata.h"

using namespace std;

int main(){
    srand((unsigned int)time(NULL));
    InitWindow(640, 480, "SansBattle");
    SetWindowIcon(LoadImage("res/img/sans/spr_sansb_face_0.png"));
    InitAudioDevice();
    SetAudioStreamBufferSizeDefault(8192);
    SetTargetFPS(30);

    Rectangle rect = {400, 300, 150, 80};
    Vector2 origin = {75, 40};
    float rot = 0.1f;

    Timer time;
    time.start();

    r1 room1;
    r0 room0;
    r3 room3;
    r5 room5;

    int current_room = 0;  // 当前实际所在的房间
    int next_room = 0;     // 下一帧要切换到的房间
    int last = 0;
    bool exit = false;
    

    while((!WindowShouldClose())){
        next_room = current_room;
        switch (current_room){
        case 0:
            next_room = room0.update(1);
            break;
        case 1:
            next_room = room1.update();
            break;
        case 2:
            next_room = room0.update(2);
            break;
        case 3:
            next_room = room3.update();
            break;
        case 5:
            next_room = room5.update();
            break;
        default:
            exit = true;
            break;
        }
        if (exit){
            break;
        }
        BeginDrawing();
            ClearBackground(BLACK);
            switch (current_room){
                case 0:
                    room0.draw();
                    break;
                case 1:
                    room1.draw();
                    break;
                case 2:
                    room0.draw();
                    break;
                case 3:
                    room3.draw();
                    break;
                case 5:
                    room5.draw();
                    break;
                default:
                    break;
            }
        EndDrawing();
        current_room = next_room;
    }
    CloseAudioDevice();
    CloseWindow();
    printf("used:%f\n",time.get_time());
    return 0;
}