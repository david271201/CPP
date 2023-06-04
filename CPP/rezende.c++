// Figura 8.31: fig08_31.cpp
// Utilizando strcpy e strncpy.
#include <iostream>
using std::cout;
using std::endl;

#include <cstring> // protótipos para strcpy e strncpy
using std::strcpy;
using std::strncpy;

int main()
{
    char x[] = "Happy Birthday to You"; // o comprimento da string é 21
    char y[25];
    char z[15];

    strcpy(y, x); // copia conteúdo de x para y 18
    cout << "The string in array x is : " << x
         << "\nThe string in array y is : "
         << y
         << '\n';

    // copia os primeiros 14 caracteres de x para z
    strncpy(z, x, 14); // não copia o caractere nulo
    z[14] = '\0';     // acrescenta ‘\0’ ao conteúdo de z

    cout << "The string in array z is : " << z << endl;
    return 0; // indica terminação bem-sucedida
}