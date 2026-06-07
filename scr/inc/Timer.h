#pragma once
#include <chrono>

class Timer{
private:
    std::chrono::steady_clock::time_point start_time;
public:
    void start(){
        reset();
    }

    float get_time(){
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration<float>(now - start_time).count();
    }

    void reset(){
        start_time = std::chrono::steady_clock::now();
    }
};