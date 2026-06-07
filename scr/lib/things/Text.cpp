#include "Text.h"

Sound sText::sound;
int sText::refCount = 0;

//
void sText::set(const char* t, int sx, int sy, int xs, float waittime, int isize, std::string filepath){
    th = t;
    x = sx;
    y = sy;
    chrn = xs;
    tim.start();
    for (int i =0;i < 256;i++)now[i] = '@';
    all_n = false;
    go = true;
    nchrn = 0;
    pr = -1;
    nwait = waittime;
    wait = nwait;
    last = tim.get_time();
    size = isize;
    tpr = 0;
    sound = LoadSound(filepath.c_str());
}

void sText::next(){
    if (pr == (th.size() - 1)){
        go = false;
    }
    if ((last + wait < tim.get_time()) and go){
        pr ++;
        if (th[pr] == '#'){
            wait = nwait + 0.5;
        }
        else{
            if (nchrn > chrn){
                now[tpr] = '/';
                nchrn = 0;
                tpr ++;
            }
            if (th[pr] == '/'){
                pr ++;
                if (th[pr] == 'W')now[tpr] = '#';
                if (th[pr] == 'R')now[tpr] = '$';
                if (th[pr] == 'Y')now[tpr] = '%';
                if (th[pr] == 'G')now[tpr] = '^';
                if (th[pr] == 'B')now[tpr] = '&';
                if (th[pr] == '~'){now[tpr] = '/';nchrn = 0;}
                tpr ++;
            }
            else{
                now[tpr] = th[pr];
                tpr ++;
                nchrn += 1;
                if (th[pr] == ' '){
                    wait = 0.0f;
                }
                else {
                    PlaySound(sound);
                    wait = nwait;
                    
                }
            }
        }
        last = tim.get_time();
    }
}

void sText::all_next(){
    if (not all_n){
        do{
            pr ++;
            if (th[pr] == '#'){
                continue;
            }
            if (nchrn > chrn){
                now[tpr] = '/';
                nchrn = 0;
                tpr ++;
            }
            if (th[pr] == '/'){
                pr ++;
                if (th[pr] == 'W')now[tpr] = '#';
                if (th[pr] == 'R')now[tpr] = '$';
                if (th[pr] == 'Y')now[tpr] = '%';
                if (th[pr] == 'G')now[tpr] = '^';
                if (th[pr] == 'B')now[tpr] = '&';
                if (th[pr] == '~')now[tpr] = '/';
                tpr ++;
                pr ++;
            }
            else{
                now[tpr] = th[pr];
                nchrn += 1;
            }
        }while(not (pr == th.size()));
    }
    all_n = true;
} 

void sText::draw(){
    int dpr = 0;
    int nx = x;
    int ny = y;
    char* in;
    while(now[dpr] != "@"){
        if (now[dpr] == "#"){nc = 0;dpr ++; continue;}
        if (now[dpr] == "$"){nc = 1;dpr ++; continue;}
        if (now[dpr] == "%"){nc = 2;dpr ++; continue;}
        if (now[dpr] == "^"){nc = 3;dpr ++; continue;}
        if (now[dpr] == "&"){nc = 4;dpr ++; continue;}
        if (now[dpr] == "/"){ny += size;nx = x;dpr ++; continue;}
        DrawText(now[dpr].c_str(), nx, ny, size, color[nc]);
        nx += size / 1.5;
        dpr ++;
    }
}

bool sText::isfin(){
    return not go;
}

void sText::del(){printf("sText::del() called\n");}
/*
sText::sText() {
    if (refCount == 0) {
        sound = LoadSound("res/fx/nsay.wav");
        printf("Sound loaded (global)\n");
    }
    refCount ++;
    printf("Sound refCount: %d\n", refCount);
}

sText::~sText() {
    refCount --;
    printf("Sound refCount: %d\n", refCount);
    if (refCount == 0) {
        UnloadSound(sound);
        printf("Sound unloaded (global)\n");
    }
}
*/