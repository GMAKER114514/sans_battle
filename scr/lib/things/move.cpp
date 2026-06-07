#include "move.h"
#define DEG2RAD (PI / 180.0f)
Vector2 forward(Vector2 local, int length, int direct) {
    float rad = direct * DEG2RAD;   // 角度转弧度
    float dx = cosf(rad) * length;
    float dy = sinf(rad) * length;
    return (Vector2){ local.x + dx, local.y + dy };
}

Vector2 half_l(Vector2 local, Vector2 direct){
    float x = (0 - local.x + direct.x) / 2 + local.x;
    float y = (0 - local.y + direct.y) / 2 + local.y;
    return {x, y};
}