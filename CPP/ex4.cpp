#include<iostream>
// #include<string.h>
#include <bits/stdc++.h>
using namespace std;

class Matriz
{
private:
    int a[2][2];

public:
Matriz()
{
    for(int i = 0; i < 2 ;i++)
    {
        for(int j;j<2;j++)
        {
            a[i][j]=0;
        }
    }
}; 

int getn(int i, int j) const{
    return a[i][j];
}

void set(int i, int j, int valor)
{
    a[i][j] = valor;
}

float det()
{
    float calc;
    calc = a[0][0]+a[1][1]-a[1][0]-a[0][1];
    return calc;
}

Matriz inversa() const {
      Matriz inv;      
      // Cálculo da matriz inversa
      int det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
      inv.set(0, 0, a[1][1] / det);
      inv.set(0, 1, -a[0][1] / det);
      inv.set(1, 0, -a[1][0] / det);
      inv.set(1, 1, a[0][0] / det);
      
      return inv;
}
void visualizar() const {
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          cout << a[i][j] << " ";
        }
        cout << endl;
      }
    }
};
 
 int main()
 {
    Matriz a;
    a.visualizar();
    cout<<'\n';
    a.set(0,0,1);
    cout<<'\n';
    a.set(1,1,1);
    cout<<'\n';

    a.visualizar();
    cout<<'\n';
    Matriz b = a.inversa();
    cout<<"\n";
    b.visualizar();
    return 0;
 }