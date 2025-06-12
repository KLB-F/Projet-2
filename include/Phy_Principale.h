#ifndef PHY_PRINCIPALE_H
#define PHY_PRINCIPALE_H

#include <bits/stdc++.h>

using namespace std;

class Phy_Principale
{
    public:
        Phy_Principale(int Xmatrice, int Ymatrice, double dt, double dist_case, double celerite);
        virtual ~Phy_Principale();
        vector<vector<double>> get_matrice();
        void UDP_PROPDONDE(bool anti_derive);

    protected:
        int x_matrice; int y_matrice;
        vector<vector<double>> matrice;
        vector<vector<double>> matricePREC;
        vector<vector<double>> matricePREC2;
        double dt; double dist; double c; double f;

    private:
};

#endif // PHY_PRINCIPALE_H
