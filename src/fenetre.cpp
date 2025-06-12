#include "../include/fenetre.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>


#define FEN_LONGUEUR 1244
#define FEN_HAUTEUR 700

#include <bits/stdc++.h>

using namespace std;

fenetre::fenetre()
{

    this->Fenetre = sf::RenderWindow(sf::VideoMode({FEN_LONGUEUR, FEN_HAUTEUR}), "Simulation Onde");

}


fenetre::~fenetre()
{
    //dtor
}

void fenetre::boucle(){ //La fenetre veut-elle se fermé ?

    while(const std::optional evenement = this->Fenetre.pollEvent()){

        if(evenement->is<sf::Event::Closed>()){
            this->Fenetre.close();
        }

    }

}

void fenetre::raffraichir(vector<vector<double>> matrice){ //Permet de raffraichir la fenetre graphiquement

    int X_matrice = matrice.size();
    int Y_matrice = matrice[0].size();

    //On créer une image, que l'on va colorer selon la case correspondante à la matrice, puis on va coller cette case sur une texture
    sf::Image image({X_matrice, Y_matrice}, sf::Color::Black);

    this->Fenetre.clear();

    for(int i = 0; i < X_matrice; i++){
        for(int j = 0; j < Y_matrice; j++){
            image.setPixel( {i, j} ,(sf::Color((int)(std::min(max(matrice[i][j], 0.d), 255.d)), 0, (int)(std::min(min(matrice[i][j], 0.d), 255.d)))));
        }
    }

    sf::Texture texture(image);
    sf::Sprite sprite(texture); sprite.scale({ (float)(FEN_LONGUEUR)/(float)(X_matrice) , (float)(FEN_HAUTEUR)/(float)(Y_matrice)});
    this->Fenetre.draw(sprite);

    this->Fenetre.display();


}
