#include <iostream>
#include <string>
#include <cmath>

#define PI 4*atan(1)

using namespace std;

class PoligonoRegular{
int nLados;
float lado;
string nome;
protected:
PoligonoRegular(int pnLados, float pLado, string nome):nome(nome){
if (!setNLados(pnLados))
nLados = 3;
if (!setLado(pLado))
lado = 1;
}
public:
void setNome(string pNome){
nome = pNome;
}
string getNome(){
return nome;
}
bool setNLados(int pnLados){
if (pnLados>=3){
nLados = pnLados;
return true;
}
else
return false;
}
int getNLados(){
return nLados;
}
bool setLado(float pLado){
if (pLado>0){
lado = pLado;
return true;
}
else
return false;
}
float getLado(){
return lado;
}
float somaAngInt(){
return (nLados-2)*PI;
}
float perimetro(){
return lado*nLados;
}
};

class Quadrado:public PoligonoRegular{
public:
Quadrado(float pLado, string pNome):PoligonoRegular(4, pLado, pNome){
}
float area(){
float l = getLado();
return l*l;
}
};

class TrianguloEquilatero:public PoligonoRegular{
public:
TrianguloEquilatero(float pLado, string pNome):PoligonoRegular(3, pLado, pNome){
}
float area(){
float l = getLado();
return l*l*sqrt(3)/4;
}
};


int main(){
//cout << PI << endl;//3.14159

Quadrado qu(7, "qu");
TrianguloEquilatero te(7, "te");
cout << qu.getNome() << " " << qu.somaAngInt() << " " << qu.perimetro() << " " << qu.area() << endl;
cout << te.getNome() << " " << te.somaAngInt() << " " << te.perimetro() << " " << te.area() << endl;
// PoligonoRegular pr(5, 2, "pr"), pr1(3, 20, "pr1");
// cout << pr.getNome() << " " << pr.somaAngInt() << " " << pr.perimetro() << endl;
// cout << pr1.getNome() << " " << pr1.somaAngInt() << " " << pr1.perimetro() << endl;
return 0;
}