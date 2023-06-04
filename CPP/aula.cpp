//#include <iostream>
//#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

class Poligono
{
private:
    int lados;
    float tamanho;


public:
    Poligono (int novo_lado=3, float novo_tamanho=3)
    {
        lados=novo_lado;
        tamanho=novo_tamanho;
    }

   void perimetro()
   {
        cout << lados*tamanho;  
   }

 void soma_ang()
   {
        cout<< 180*(lados-2);  
   } 
   
};

int main()
{
    Poligono p1(4,5);
    p1.soma_ang();
}
