#ifndef FENETRE_H
#define FENETRE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <bits/stdc++.h>

using namespace std;

class fenetre
{
    public:
        fenetre();
        virtual ~fenetre();
        sf::RenderWindow Fenetre;
        void boucle();
        void raffraichir(vector<vector<double>> matrice);

    protected:

    private:
};

#endif // FENETRE_H
