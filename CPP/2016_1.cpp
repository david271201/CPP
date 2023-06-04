#include<iostream>
#include<string>

using namespace std;

class ClienteComum : public ClientePreferencial
{
private:
    int tmax;
public:
    ClienteComum(string nome, int tchegada,int tduracao, int tmax) : ClientePreferencial( nome, tchegada,tduracao)    
    {
        this->tmax=tmax;
    }
    
};

class ClientePreferencial 
{
protected:
    string nome;
    int tchegada;
    int tduracao;
public:
    ClientePreferencial(string nome, int tchegada,int tduracao)
    {
        this->nome=nome;
        this->tchegada=tchegada;
        this->tduracao=tduracao;
    }
    
    ClientePreferencial(const ClienteComum &p)
    {
        nome=p.nome;
        tchegada=p.tchegada;
        tduracao=p.tduracao;
    }    
};

class Banco
{
    
}
