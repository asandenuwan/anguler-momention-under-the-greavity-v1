#include "greavity.h"

int main(){
    greavity g(5.0f, 60.0f, 1000000.0f);
    float* x=g.getX();
    float* y=g.getY();
    g.run();
    
    return 0;
}