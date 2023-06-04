//#include <iostream>
//#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

class Ponto
{
private:
    float x,y,z;

public:
    Ponto (float novo_x=0, float novo_y=0, float novo_z=0)
    {
        x=novo_x;
        y=novo_y;
        z=novo_z;
    }

    void visualizar()
    {
        cout << "("<< x <<","<< y <<","<< z<<")";
    }

    float oposto ()
    {
        x=-1*x;
        y=-1*y;
        z=-1*z;
    }    

    float distancia()
    {
        float d;

        d = pow((pow(x,2)+pow(y,2)+pow(z,2)),0.5);
        cout << "A distancia da origem eh: "<<d<<"\n";
    }
};

int main()
{
    Ponto p1;
    Ponto p2(1,2);
    Ponto p3(4,5,6);
    p3.oposto();
    p3.distancia();
    p1.visualizar();
    p2.visualizar();
    p3.visualizar();

}

