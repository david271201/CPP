#include<iostream>
#include<string.h>

using namespace std;

class Deque
{
private:
    No *inicio, *fim; 

public:
    Deque()
    {
        inicio = NULL;
        fim = NULL;
    }
    ~Deque()
    {
        No *aux = inicio->prox;
        while(inicio)
        {
            delete inicio;
            inicio=aux;
        } 
    }
};

class No
{
public:
    int chave;
    No *prox;
    No(int chave)
    {
        this->chave=chave;
        prox = NULL;
    }
    
    int getchave(int chave)
    {
        return chave;
    }

};

class Fila:public Deque
{

};

class Pilha:public Deque
{

};