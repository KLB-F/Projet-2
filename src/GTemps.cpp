#include "../include/GTemps.h"
#include <iostream>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

GTemps::GTemps(int FPSviser, int UpdPSviser)
{

    this->horloge = sf::Clock();
    this->FPSobj = FPSviser;
    this->Phy_UdpPS_Obj = UpdPSviser;
    this->compteur_FPS = 0;
    this->compteur_UpdPh = 0;
    this->temps_el = this->horloge.getElapsedTime();

}

GTemps::~GTemps()
{
    //dtor
}

bool GTemps::estTempsRaffraichir(){
    if(this->temps_el.asMilliseconds() >= this->compteur_FPS*1000/this->FPSobj){
        this->compteur_FPS++;
        return true;
    }else{
        return false;
    }
}

bool GTemps::estTempsUpdPhysique(){

    if(this->temps_el.asMilliseconds() >= this->compteur_UpdPh*1000/this->Phy_UdpPS_Obj){
        this->compteur_UpdPh++;
        return true;
    }else{
        return false;
    }

}

float GTemps::auto_resetTemps(){

    if((this->compteur_FPS > this->FPSobj*3) || (this->compteur_UpdPh > this->Phy_UdpPS_Obj*3)){

    float resFPS = 1-(double)(this->temps_el.asMilliseconds()*(FPSobj*0.001d)-this->compteur_FPS)/(double)(this->compteur_FPS);

    this->horloge.restart();
    this->compteur_FPS = 0;
    this->compteur_UpdPh = 0;

    return resFPS;

    }

    return -1.f;

}

void GTemps::Upd_temps(){
    this->temps_el = this->horloge.getElapsedTime();
}

