#include <iostream>
#include <windows.h>
#include <thread>
#include <cmath>

class greavity{
    private:
        float mass,angel,power,time,uper_J,side_J;
        float x=0,y=0;
        void backend();
        float getV(float a,bool h);
        std::thread t;

    public:
        greavity(float mass, float angel, float power);
        void run();
        float* getX();
        float* getY();
};