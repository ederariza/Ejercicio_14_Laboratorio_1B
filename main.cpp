
/*
Problema 14. Un número palíndromo es igual de derecha a izquierda y de izquierda a derecha,
Ej: 969. escriba un programa que calcule el número palíndromo más grande que se puede obtener
como una multiplicación de números de 3 dígitos.
Ej: una de las posibles respuestas es: 143*777=111111.
Nota: la salida del programa debe ser: 143*777=111111
*/

#include <iostream>
using namespace std;

//Prototipo funcion palindromo
bool numeroPalindromo(int numero);

int main(void){

    int numero_i = 0; //Primer numero de tres cifras
    int numero_j = 0; //Segundo numero de tres cifras
    int numero_mayor = 0; //Numero palindromo mayor
    int numero_palindromo; //Numero palindromo
    int producto_ixj; //Producto de numeros de tres cifras

    //Ciclo for que me pedmite hallar numeros palindromo del producto de numero de tres cifras
    for (int i = 100; i <= 999; i++){

        for (int j = 100; j <= 999; j++){
            producto_ixj = (i * j);

            //Encontramos los numeros palindromos
            if (numeroPalindromo(producto_ixj)){
                    numero_palindromo = producto_ixj;
                    //cout << i << " x " << j << " = " << numero_palindromo << endl;

                    //Hallamos el numero palindromo mas grande
                    if (numero_mayor < numero_palindromo)
                        numero_mayor = numero_palindromo;

                    //Encontramos los numeros del numero palindromo mas grande
                    if (numero_palindromo == 906609)
                        numero_i = i,
                        numero_j = j;
            }
        }
    }

    cout << "El numero palindromo mas grande al multiplicar numeros de tres cifras es: \n" << numero_j << " x " << numero_i << " = " << numero_mayor << endl;

    return 0;

}

//Funcion numero palindromo encuentra numeros palindromos
bool numeroPalindromo(int numero){

        //int numero;
        int digito = 0;
        int residuo = 0;
        bool palindromo;

        //Bloque que descompone el numero hallando sus digitos
        int numero_nuevo = numero;
        while (numero_nuevo > 0){

            if (numero_nuevo % 10 != 0)
                digito += 1,
                residuo = numero_nuevo % 10,
                numero_nuevo = numero_nuevo / 10;

        else
                digito += 1,
                residuo = numero_nuevo % 10,
                numero_nuevo = numero_nuevo / 10;

        }

        //Bloque de intrucciones que halla la mayor potencia de 10 del numero ingresado
        int potencia;
        for (int i = 0; i < digito; i++){

            if (i == 0)
                potencia = 1;

            else
                potencia *= 10;
        }

        //Bloque de instrucciones que pone el numero al reves
        int numero_palindromo = 0;
        numero_nuevo = numero;
        while (numero_nuevo > 0){

            if (numero_nuevo % 10 != 0)
                residuo = numero_nuevo % 10,
                numero_palindromo += residuo * potencia,
                numero_nuevo = numero_nuevo / 10,
                potencia /= 10;

            else
                residuo = numero_nuevo % 10,
                numero_palindromo += residuo * potencia,
                numero_nuevo = numero_nuevo / 10,
                potencia /= 10;

        }

        if (numero_palindromo == numero)
            palindromo = true;

        else
            palindromo = false;

        return palindromo;
    }
