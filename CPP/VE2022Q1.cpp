#include <iostream>
#include <string>

using namespace std;

class No
{
public:
    int key;
    No *next;
    No(int key) : key(key), next(nullptr) {}
    ~No() { next = nullptr; delete next;}
};

class Estrutura
{

protected:
    No *inicio, *fim;

public:
    Estrutura() : inicio(nullptr), fim(nullptr) {}
    ~Estrutura()
    {
        while (inicio)
        {
            No *aux = inicio->next;
            delete inicio;
            inicio = aux;
        }
        fim = nullptr;
    }

    bool isEmpty()
    {
        return (inicio == nullptr && fim == nullptr);
    }

    void append(int value)
    {
        No *novo = new No(value);

        if (isEmpty())
        {
            inicio = novo;
            fim = novo;
            return;
        }

        fim->next = novo;
        fim = novo;
        return;
    }

    void print(){
        No *begin = inicio; 

        while(begin){
            cout << begin->key << " "; 
            begin = begin->next;
        }

        cout << endl;
    }
};

class Pilha : public Estrutura{
    public: 
        Pilha():Estrutura(){}
        void remove(){
            No *begin = inicio, *prev = nullptr;

            while (begin->next){
                prev = begin;
                begin = begin->next;
            }
            prev->next = nullptr;
            delete fim;
            fim = prev; 
        }
};

class Fila : public Estrutura{
    public: 
        Fila():Estrutura(){}
        void remove(){
            No *temp = inicio->next;
            delete inicio; 
            inicio = temp;
        }
};

int main()
{
    Pilha p;
    Fila f;
    p.append(10);
    p.append(15);
    p.append(20);
    f.append(20);
    f.append(25);
    f.append(30);
    p.print();
    f.print();
    p.remove();
    f.remove();
    p.print();
    f.print();
}
