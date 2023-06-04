#include <iostream>
#include <string>
#include <stdbool.h>

using namespace std;

class circularBuffer{
    int tam, inicio, fim; 
    int *buffer;

    public: 
        circularBuffer(int tam):tam(tam), inicio(0), fim(0){
            buffer = new int[tam];
        }

        ~circularBuffer(){
            delete[] buffer; 
        }

        bool isFull(){
            return (fim == (inicio-1)%tam);
        }

        bool isEmpty(){
            return (inicio == fim);
        }

        void append(int key){
            if(isFull()){
                cout << "buffer cheio" << endl;
                return;
            }

            buffer[fim%tam] = key;

            fim = (fim+1);

            return;
        }

        void remove(){
            if(isEmpty()){
                cout << "buffer vazio" << endl;
                return;
            }
            buffer[inicio] = NULL;
            inicio = (inicio+1)%tam;
        }

        void imprimir(){
            for(int i = inicio; i < fim; i++){
                cout << buffer[i%tam] << " ";
            }
            return;
        }
};

int main(){
    circularBuffer c(3);

    c.append(5);
    c.append(10);
    c.append(15);

    c.imprimir();
}
