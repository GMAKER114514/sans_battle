#include "5.h"

void r5::draw(){
    GB.draw_gbs();
}

int r5::update(){
    if(not inited){
        GB.init();
        inited = not inited;
    }
    GB.update_gbs();
    if (frame >= 1){GB.create_gb({340, 240}, 0);frame = 0;return 5;}
    frame ++;
    return 5;
}