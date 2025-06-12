#include "include/fenetre.h"
#include "include/GTemps.h"
#include "include/Phy_Principale.h"

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

int main()
{
    fenetre Fenetre = fenetre();
    Phy_Principale PhPrincipale = Phy_Principale(846, 476, 0.01, 1.d, 34.d); //Paramètres : taille de la matrice, intervalle de temps entre chaque actualisation, célérité

    GTemps chrono = GTemps(30, 100); //A mettre le plus pres possible de la boucle principale

    sf::Clock horl = sf::Clock();
    int compteurFRAME = 0;
    long sommeFRAME = 0;

    while(Fenetre.Fenetre.isOpen()){ //Boucle principale

        Fenetre.boucle();
        if(chrono.estTempsRaffraichir()){ //La classe GTemps sait quand il faut raffraichir soit la physique, soit la partie graphique
            Fenetre.raffraichir(PhPrincipale.get_matrice());
        }
        if(chrono.estTempsUpdPhysique()){
            PhPrincipale.UDP_PROPDONDE(false);
        }
        float a = chrono.auto_resetTemps();
        //if(a != -1.f){ cout << a << endl; } //DEBOGAGE SEULEMENT
        chrono.Upd_temps();

    }
    return 0;
}

