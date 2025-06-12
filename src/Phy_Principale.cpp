#include "../include/Phy_Principale.h"

#include <bits/stdc++.h>

using namespace std;

Phy_Principale::Phy_Principale(int Xmatrice, int Ymatrice, double dt, double dist_case, double celerite)
{

    this->dt = dt;
    this->c = celerite;
    this->dist = dist_case;
    this->f = 0.5d;
    this->matrice = vector<vector<double>>(Xmatrice, vector<double>(Ymatrice, 0.d));
    this->matricePREC = vector<vector<double>>(Xmatrice, vector<double>(Ymatrice, 0.d));
    this->matricePREC2 = vector<vector<double>>(Xmatrice, vector<double>(Ymatrice, 0.d));

    this->matrice[300][150] = 1.d;
    this->matricePREC[300][150] = 1.d;

}

vector<vector<double>> Phy_Principale::get_matrice(){

    return this->matrice;

}

void Phy_Principale::UDP_PROPDONDE(bool anti_derive){

    int X_matrice = matrice.size();
    int Y_matrice = matrice[0].size();

    //MILIEU

    double Sprec = 0;
    double S = 0;

    for(int i = 1; i < X_matrice-1; i++){
        for(int j = 1; j < Y_matrice-1; j++){

            Sprec = Sprec + this->matrice[i][j];

            double ds2dx2 = ((this->matrice[i][j+1]+this->matrice[i][j-1]-2*this->matrice[i][j])/(dist*dist)+(this->matrice[i+1][j]+this->matrice[i-1][j]-2*this->matrice[i][j])/(this->dist*this->dist));
            double temp = matrice[i][j];
            this->matrice[i][j] = (this->matrice[i][j] + (this->matrice[i][j]-this->matricePREC[i][j]) + ((0.5d*ds2dx2*this->c*this->c-f*(matricePREC[i][j]-matricePREC2[i][j])/this->dt)*this->dt*this->dt));

            S = S + this->matrice[i][j];

            this->matricePREC[i][j] = temp;
            this->matricePREC2[i][j] = this->matricePREC[i][j];

        }
    }

    //BORD

    for(int i = 0; i < X_matrice; i++){
        this->matrice[i][0] = 0;
        this->matrice[i][Y_matrice-1] = 0;

        S = S + this->matrice[i][0];
        S = S + this->matrice[i][Y_matrice-1];
    }
    for(int j = 0; j < Y_matrice; j++){

        this->matrice[0][j] = 0;
        this->matrice[X_matrice-1][j] = 0;

        S = S + this->matrice[0][j];
        S = S + this->matrice[X_matrice-1][j];

    }

}

Phy_Principale::~Phy_Principale()
{
    //dtor
}
