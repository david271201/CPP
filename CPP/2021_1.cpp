#include<stdio.h>
#include<iostream>

using namespace std;

enum modoDeque{frente,retaguarda};

class Deque
{
private:
    int tam_max;
    int topo;
    int final; 
    int *lista;    
public:
    Deque(int tam_max )
    {
       this->tam_max=tam_max;
       lista = new int[tam_max];
       topo = 0;
       final = 0;
    }
    
    ~Deque()
    {
        delete []lista;
    }
    
    Deque(const Deque &p)
    {
        this->topo=p.topo;
        this->final=p.final;
        this->tam_max=p.tam_max;
        
        for(int i; i < tam_max ;i++)
        {
            this->lista[i] = p.lista[i];
        };
    }

    void inserir(int valor, modoDeque modo)
    {
        if (final == tam_max)
        {
            cout << "Lista cheia" << endl;
        }
        if( modo == frente)
        {
            for(int i=0;i<tam_max;i++)
            {
                lista[i+1]=lista[i];
            }
            lista[0]=valor;     
            final++;       
        }
        else
        {
            if (final==0)
            {
                lista[0]=valor;
                final++;
            }
            lista[final+1]=valor;
            final++;
        }
    }
    void deletar(modoDeque modo)
    {
        if(final==0)
        {
            cout<<"lista vazia\n";
        }     
        else if(modo == frente)
        {
            topo++;     
        }
        else
        {
            final--;
        }
    }

    void imprimir()
    {
        for(int i = topo;i<final; i++)
        {
            cout<<lista[i]<<" "<<endl;
        }
    }

    int gettam(int tam_max)
    {
        return tam_max;
    }
};

class Fila :public Deque
{
private:
    int tam;
public:
    
    Fila(int tam):Deque(tam){};

    void  inserir(int valor,modoDeque modo = retaguarda)
    {
        Deque::inserir(valor,modo);
    }
    void deletar(modoDeque modo = frente)
    {
        Deque::deletar(modo);
    }

};

int main()
{
      

}