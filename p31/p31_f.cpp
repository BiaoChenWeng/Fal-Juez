#include <iostream>
#include <fstream>
#include <vector>
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

int jug(int n,int resultado,int pot) {
    if (n<10) {
        if (n % 2 == 0) {
            return (n  + 1) * pot + resultado;
        }
        else {
            return (n  - 1) * pot + resultado;
        }

    }

    else {
        if (n % 2 == 0) {
            return jug(n / 10, ((n % 10)+1) * pot + resultado, pot * 10);

        }
        else {
            return jug(n / 10, ((n % 10) - 1) * pot + resultado, pot * 10);


        }
    }
}

// configuración, y escribiendo la respuesta

void resuelveCaso() {

    int entrada;
    cin >> entrada;



    cout << jug(entrada,0,1);

    cout << "\n";

}

/*
Jugando con los d´ıgitos de un n´umero
Vamos a modificar los d´ıgitos de un n´umero de la siguiente forma. Si el d´ıgito es impar le restamos
uno y si el d´ıgito es par le sumamos uno.
Requisitos de implementaci´on.
Resolver el problema utilizando primero una funci´on recursiva no final que reciba un n´umero entero
y devuelva el n´umero transformado seg´un se indic´o en el problema.
A continuaci´on resolverlo utilizando una funci´on recursiva final.
Probar ambas soluciones en el juez autom´atico.
Entrada
La entrada comienza con el n´umero de casos de prueba. A continuaci´on cada caso se escribe en una
l´ınea y consiste en un n´umero 0 <= N <= 1.000.000.000.
Salida
Para cada caso de prueba se muestra en una l´ınea el n´umero obtenido sustituyendo cada d´ıgito por
su transformado.
Entrada de ejemplo
7
45637
555
2
90
81
0
11
Salida de ejemplo
54726
444
3
81
90
1
0
*/