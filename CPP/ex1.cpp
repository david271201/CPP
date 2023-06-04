#include<iostream>
#include<string>
#include<math.h>
#include<stdio.h>
#include<string.h>

using namespace std;

class Ponto
{
private:
    float x;
    float y;
    float z;
public:    
    
    Ponto(float x, float y, float z);
    void visualizar();
    void oposto();
    void distancia();
};

Ponto::Ponto(float novo_x=0,float novo_y=0,float novo_z=0)
{
    x= novo_x;
    y=novo_y;
    z=novo_z;
};

void Ponto::visualizar()
{
    cout << "x = "<<x <<'\n';
    cout << "y = "<<y <<'\n'; 
    cout << "z = "<<z <<'\n'; 
};

void Ponto::distancia()
{
    float r;
    r = x*x + y*y + z*z;
    r=pow(r,0.5);
    cout<<"\na distancia vale: "<< r << endl;
};

void Ponto::oposto()
{
    x*=-1;
    y*=-1;
    z*=-1;
};

int main()
{
    Ponto a;
    a.visualizar();
    a.oposto();
    a.visualizar();
    a.distancia();
}