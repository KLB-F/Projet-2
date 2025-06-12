#ifndef GTEMPS_H
#define GTEMPS_H
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

class GTemps
{
    public:
        GTemps(int FPSviser, int UpdPSviser);
        virtual ~GTemps();
        bool estTempsRaffraichir();
        bool estTempsUpdPhysique();
        float auto_resetTemps();
        void Upd_temps();

    protected:
        sf::Clock horloge;
        int FPSobj;
        int compteur_FPS;
        int Phy_UdpPS_Obj;
        int compteur_UpdPh;
        sf::Time temps_el;

    private:
};

#endif // GTEMPS_H
