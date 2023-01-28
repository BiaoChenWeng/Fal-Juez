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

string decimal_binaria(int n,string resultado) {
    if (n <2) {
        if (n % 2==0) {
            return to_string(0) + resultado;
        }
        else {
            return to_string(1) + resultado;
        }
    }
    else {
        return decimal_binaria(n / 2,  to_string(n % 2)+ resultado);
    }


}

// configuración, y escribiendo la respuesta

void resuelveCaso() {

    int entrada;
    cin >> entrada;



    cout << decimal_binaria(entrada,"");

    cout << "\n";

}

/*
Transformar un n´umero decimal a binario
Con la revoluci´on digital, el sistema de numeraci´on en base
dos o sistema de numeraci´on binario adquiere una gran relevancia
al ser el sistema utilizado por los ordenadores y las redes de comunicaci´on. Todo inform´atico necesita en alg´un momento obtener
la representaci´on binaria de un n´umero.
En este problema desarrollaremos un conversor de n´umeros
expresados en base 10 a n´umeros expresados en base 2.
Requisitos de implementaci´on.
El conversor debe realizarse con una funci´on que dado un n´umero entero devuelva en una cadena de
caracteres de tipo std::string su representaci´on en binario.
Se utilizar´a una funci´on resuelveCaso para leer el dato de entrada, llamar al conversor y escribir la
cadena de salida.
Entrada
La entrada comienza con una l´ınea en que se indica el n´umero de casos de prueba. Cada caso consiste
en un n´umero entero positivo n (0 ≤ N ≤ 2
31 − 1).
Salida
Para cada caso de prueba se muestra en una l´ınea la representaci´on en binario del n´umero.
Entrada de ejemplo
6
3
8
1
24
156
345
Salida de ejemplo
11
1000
1
11000
10011100
101011001
1

*/