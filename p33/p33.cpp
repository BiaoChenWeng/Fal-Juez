#include <iostream>
#include <fstream>
#include <vector>
#include <string>
// Introduce más librerías si son necesarias
using namespace std;
void resuelveCaso();



int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    std::ofstream out("datos.out");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    system("PAUSE");
#endif
    return 0;
}

int suma_final(int a, int b, int suma,int pot) {
    if (a == 0 && b == 0) {
        return suma;
    }

    else {
        return suma_final(a / 10, b / 10, pot * ((a % 10 + b % 10) % 10) + suma,pot *10);
    }

}


int suma_no_final(int a , int b) {
    if (a==0 && b==0) {
        return 0;
    }
    else {
        return suma_no_final(a / 10, b / 10) * 10 + (a % 10 + b % 10)%10;

    }


}


// configuración, y escribiendo la respuesta

void resuelveCaso() {

    int num_1,num_2;
    cin >> num_1;
    cin >> num_2;
    cout << suma_no_final(num_1, num_2)<<" "<<suma_final(num_1,num_2,0,1);
    
    cout << "\n";

}

/*
Sumar dos n´umeros d´ıgito a d´ıgito
Dados dos n´umeros enteros positivos, nos piden obtener el
n´umero que resulta de sumar, m´odulo 10, los d´ıgitos de igual
peso de los dos n´umeros dados.
El problema debe resolverse dos veces. La primera con una
funci´on recursiva no final y la segunda con una funci´on recursiva
final.
Requisitos de implementaci´on.
Se deben escribir las ecuaciones recursivas que resuelven el
problema en el fichero que se entrega.
Las funciones recursivas deben recibir un n´umero entero, y
devolver como valor de retorno el n´umero obtenido al realizar la
suma. Se pueden utilizar m´as par´ametros por valor si la soluci´on lo requiere.
No se deben utilizar par´ametros por referencia en ninguna de las funciones implementadas. Se puede
devolver m´as de un valor como retorno de la funci´on si la soluci´on lo requiere.
El problema se debe resolver utilizando un n´umero entero. No se puede utilizar el tipo std::string, ni
el tipo std::vector para resolver el ejercicio.
Entrada
La entrada comienza con el n´umero de casos de prueba. Cada caso se escribe en una l´ınea y consiste
en dos n´umeros, 0 <= N1, N2 <= 100.000.000.
Salida
Para cada caso de prueba se muestra en una l´ınea primero el resultado obtenido con la funci´on
recursiva no final y a continuaci´on el resultado de la funci´on recursiva final.
Entrada de ejemplo
5
85643 45397
0 365
999 111
9999 111
88 10000
Salida de ejemplo
20930 20930
365 365
0 0
9000 9000
10088 10088
Autor: Isabel Pita



*/