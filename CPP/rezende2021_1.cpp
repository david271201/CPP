#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <math.h>
#include <cmath>

using namespace std;

enum modoDeque{frente, retaguarda};

class Deque{
    int tamanho;
    int *lista;
    int topo;
    int final;


    public:
    Deque(int ptamanho);
    ~Deque(){
        delete []lista;
    };
    void imprimir();
    void inserir(int valor, modoDeque modo);
    void remover( modoDeque modo);
    Deque(const Deque &p){
        this->tamanho=p.tamanho;
        this->topo=p.topo;
        this->final=p.final;
        this->lista=new int[tamanho];
        for (int i = topo; i <= final; i++)
        {
            this->lista[i]=p.lista[i];
        }
        
    };
};
Deque::Deque(int ptamanho){
    this->tamanho=ptamanho;
    lista=new int[tamanho];
    topo=0;
    final=0;

};
void Deque::inserir(int valor, modoDeque modo){
    if (final==tamanho)
    {
        cout << "Deque cheio!" << endl;
    }
    else if (modo==frente)
    {
        for (int i = 0; i < final+1; i++)
        {
            lista[i+1]=lista[i];
        }
        lista[0]=valor;
        final++;
    }
    else if (modo==retaguarda)
    {
        lista[final+1]=valor;
        final++;
    } 
};

void Deque::remover(modoDeque modo){
    if(topo==final){
        cout << "Deque esta vazio!" << endl;
        return;
    }
    if(modo==retaguarda){
        final--;
    }
    if (modo==frente)
    {
        for (int i = 1; i < final; i++)
        {
            lista[i-1]=lista[i];
        }
        final--;
    }
    
};

void Deque::imprimir(){
     std::cout << "Deque: ";
        for (int i = topo; i <= final; i++) {
            std::cout << lista[i] << " ";
        }
        std::cout << std::endl;
};

class Fila:public Deque{
    public:
    Fila(int t):Deque(t){};
    void inserir(int valor);
    void remover();
};

void Fila::inserir(int valor){
    Deque::inserir(valor, retaguarda);
};

void Fila::remover(){
    Deque::remover(frente);
};


int main()
{
    Deque a(3);
    Fila b(3);

    a.remover(frente);
    a.remover(retaguarda);
    a.inserir(1,frente);
    a.imprimir();
    a.inserir(2,retaguarda);
    a.imprimir();
    a.remover(frente);
    a.remover(retaguarda);

}