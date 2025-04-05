#include "greavity.h"
greavity::greavity(float mass, float angel, float power){
    this->mass=mass;
    this->angel=angel;
    this->power=power;
}


void greavity::run(){
    // t=std::thread(&greavity::backend,this);
    this->backend();
}

void greavity::backend(){
    float a=-9.8;//gruthwaja thranaya [adu karanna]
    int i=1;// up velocity eke hema secand ekedima wedi karanna
    float vx=getV(this->angel,true);//velocity for -> side
    float vy=getV(this->angel,false);//velocity for up
    float tmp=vy;
    float total_time=0;

    while (1){
        vy+=a;//change up velocity by gruthwaja tharanaya
        if(vy>=tmp){break;} // when object hit the ground ---{object eke wetanakota eke velocity = mul awasthawe velocity}

        if (vy<=0){//when object is stop in sky
            vy=0;//object not moveing
            a=9.8;//thranaya wedi wenawa
            i=-1;// up velocity eke hema secand ekedima adu karanna
            std::cout<<"----The Peak--------"<<std::endl;
            continue;
        }
        float T=1/(float)vy;// metaryak yanna yana thappara gana
        std::cout<<"Time: "<<T<<std::endl;
        Sleep(T*1000);// Sleep eka ganne mili sec niya X1000
        std::cout<<"y: "<<y<<" x: "<<x<<std::endl;
        total_time+=T;
        x=total_time*vx;// thirasata giya dura gannanya
        y+=i; // obj eka den kochchara udinda thiyenne kiyala balanawa
        // i wela agaya -1 wenawa eka uda nathara unaama
    }
    std::cout<<"----The End--------"<<std::endl;
    std::cout<<"Total time: "<<total_time<<std::endl;
    // t.join();
    // std::cout<<"----Thread End--------"<<std::endl;
}

float greavity::getV(float a,bool h){
    std::cout<<"----getV start--------"<<std::endl;
    if(!h){
        a=90-a;
    }
    a=a*M_PI/180;
    std::cout<<"cos(a):"<<cos(a)<<std::endl;
    float x=2*cos(a)*this->power;
    x=x/this->mass;
    if(x<0){
        std::cout<<"    ; error: negative value is gotted {check math}"<<std::endl;
        t.join();
        exit(0);
    }
    x=std::sqrtf(x);
    std::cout<<"velocity: "<<x<<std::endl;
    std::cout<<"----getV end--------"<<std::endl;
    return x;
}

float* greavity::getX(){
    float* x=&this->x;
    return x;
}

float* greavity::getY(){
    float* y=&this->y;
    return y;
}