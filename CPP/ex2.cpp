#include<string.h>
#include<iostream>
#include<math.h>

using namespace std;

class Poligono
{
private:
    int lados;
    float length;    
public:     
    Poligono(int lados, float lenght);
    void soma_ang();
    void perimetro();
    float getlength();
};


Poligono::Poligono(int new_lados = 3, float new_length=1)
{
    lados = new_lados;
    length= new_length;
};

float Poligono :: getlength()
{
    return length;
}
void Poligono::perimetro()
{
    float per;
    per=lados*length;
    cout << "\nO perimetro vale: "<< per <<endl;
};

void Poligono::soma_ang()
{
    int si;
    si=(lados-2)*180;
    cout << "\n A soma dos angulos internos vale: "<< si <<endl;
};

class Triangulo_eq : public Poligono
{   
private:
float size;    
public:
    void area();
    Triangulo_eq( float size=2):Poligono(3, size){
        
    };

};

void Triangulo_eq :: area()
{
    float s;
    s = getlength()*getlength()*pow(3,0.5)/4;
    cout<<"A area vale: " <<s<<endl;
};

class Quadrado :public Poligono
{
private:
    float tam;
public:
    Quadrado(float tam):Poligono(4,tam){};
    void area();    
};

void Quadrado :: area()
{    

    cout<<"a area vale: " << getlength()*getlength();
};

int main()
{
    Triangulo_eq a;
    a.perimetro();
    a.area();
    Quadrado b(1);
    b.perimetro();
    b.area();
    b.soma_ang();
    Poligono c(6,2);
    c.soma_ang();
    c.perimetro();
}
