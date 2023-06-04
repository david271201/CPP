#include<iostream>
#include<math.h>
#include<string.h>
#include<datetimeapi.h>
#include<stdlib.h>
using namespace std;
bool normalizar(int dia, int mes, int ano);

class Data
{
private:
    int mes, dia, ano;
    int mes_i, dia_i, ano_i;

public:
Data(int dia, int mes, int ano);
void reiniciar();
int adiantar(int dia, int mes, int ano);
void imprimir();
};

Data::Data(int dia= 1, int mes=1, int ano=2000)
{
    if (normalizar(dia,mes,ano))
    {
        this->dia=dia;
        this->mes=mes;
        this->ano=ano;
        this->dia_i=dia;
        this->mes_i=mes;
        this->ano_i=ano;
    }
    else
    {
        cout << "data invalida, digite uma data coerente. \n"<<endl;
        exit(1);
    }
};

void Data::reiniciar()
{   
    dia=dia_i;
    mes=mes_i;
    ano= ano_i;
};

int Data::adiantar(int d, int m, int a)
{
    if (normalizar(d,m,a))
    {
        if (ano>a)
        {
            dia = d;
            mes= m;
            ano = a;
        }
        else
        {
            if(ano == a)
            {
                if (mes>m)
                {
                    dia = d;
                    mes= m;
                    ano = a; 
                }
                else
                {
                    if (mes==m)
                    {
                        if (dia>d)
                        {
                            dia = d;
                            mes= m;
                            ano = a; 
                        }
                    }
                }
            }
        }
    }
    else
    {
        cout << "data invalida, digite uma data coerente. \n"<<endl;
        exit(1);
    }
};

void Data::imprimir()
{
    cout << dia << '/' << mes <<'/'<<ano <<endl;
};

bool normalizar(int d, int m, int a)
{
    if ((a< 1) || (m<1) || (m>12) || (d<1) || (d>31))
    {
        return false;
    }
    else
    {
        if((a%400==0)|| ((a%4==0) && (a%100!=0)))
        {
            if( (m==2)|| (m==4)|| (m==6)|| (m==9)|| (m==11))
                {
                    if (m==2)
                    {
                        if(d>29)
                        {
                            return false;
                        }
                        return true;                        
                    }
                    if(d >30)
                    {
                        return false;
                    }
                    return true;
                }
            return true;    
        }
        else
        {
            if( (m==2)|| (m==4)|| (m==6)|| (m==9)|| (m==11))
                {
                    if (m==2)
                    {
                        if(d>28)
                        {
                            return false;
                        }
                        return true;                        
                    }
                    if(d >30)
                    {
                        return false;
                    }
                    return true;
                }
            return true;    
        }   
    };

};

int main()
{
Data a(42,2,401);
a.imprimir();
a.adiantar(1,1,1);
a.imprimir();
a.reiniciar();
a.imprimir();
return 0;
}