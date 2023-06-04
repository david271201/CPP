#include <iostream>
#include <string>
#include <stdbool.h>

using namespace std;

enum modoDeque
{
    frente = 0,
    retaguarda
};

class No
{
public:
    int key;
    No *prox, *prev;

    No(int key) : key(key), prox(nullptr), prev(nullptr) {}
    No(No &no) 
    {
        key = no.key;
        prox = no.prox;
        prev = no.prev;
    }
};

class Deque
{
    int n_el, tam_max;
    No *inicio, *fim;

public:
    Deque(int tam) : n_el(0), tam_max(tam)
    {
        inicio = nullptr;
        fim = nullptr;
    }

    Deque(Deque &d)
    {
        n_el = d.n_el;
        tam_max = d.tam_max;
        inicio = nullptr;
        fim = nullptr;
        No *p = d.inicio;

        while(p){
            No *novo = new No(*p); 
            if(inicio == nullptr){
                inicio = novo;
                fim = novo; 
            }
            else{
                fim->prox = novo;
                novo->prev = fim;
                fim = novo;
            }
            p = p->prox; 
        }
    }

    ~Deque()
    {
        while (inicio)
        {
            No *aux = inicio->prox;
            delete inicio;
            inicio = aux;
        }

        fim = nullptr;
    }

    bool isVazio()
    {
        return (inicio == nullptr && fim == nullptr);
    }

    void insert(int value, modoDeque mode)
    {
        if (n_el == tam_max)
        {
            return;
        }
        No *novo = new No(value);

        if (isVazio())
        {
            inicio = novo;
            fim = novo;
            n_el++;
            return;
        }

        switch (mode)
        {
        case modoDeque::frente:
            fim->prox = novo;
            novo->prev = fim;
            fim = novo;
            break;

        case modoDeque::retaguarda:
            novo->prox = inicio;
            inicio->prev = novo;
            inicio = novo;
            break;
        }
        n_el++;
        return;
    }

    void remove(modoDeque mode)
    {
        if (isVazio())
        {
            return;
        }
        switch (mode)
        {
        case modoDeque::frente:
        {
            No *temp = fim->prev;
            delete fim;
            temp->prox = nullptr;
            fim = temp;
        }
        break;

        case modoDeque::retaguarda:
        {
            No *aux = inicio->prox;
            delete inicio;
            aux->prev = nullptr;
            inicio = aux;
        }
        break;
        }
        n_el--;
        return;
    }

    void imprimir()
    {
        No *printer = fim;

        while(printer){
            cout << printer->key << " ";
            printer = printer->prev;
        }
    }
};


int main()
{
    Deque d(10);

    d.insert(5, modoDeque::frente);
    d.insert(7, modoDeque::frente);
    d.insert(9, modoDeque::frente);

    d.imprimir();

    d.insert(15, retaguarda);

    d.imprimir();

    d.remove(retaguarda);
    d.remove(frente);

    d.imprimir();
}