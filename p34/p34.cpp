
#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;

bool resuelveCaso();
int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    std::ofstream out("datos.out");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    system("PAUSE");
#endif
    return 0;
}


long long int eliminar_final(long long int num,long long int resultado, long long int pot){
    if (num == 0) {
        return resultado;
    }
    else {
        if (num % 2 == 0) {
            return eliminar_final(num / 10, resultado, pot);
        }
        else {
            return eliminar_final(num / 10, resultado + ((num % 10) * pot),pot*10);
        }
    }
}


long long int eliminar_no_final(long long int num) {
    if (num == 0) {
        return 0;
    }
    else {
        if (num % 2 == 0) {
            return eliminar_no_final(num / 10);
        }
        else {
            return eliminar_no_final(num / 10) * 10 + (num % 10);
        }
    }
}



bool resuelveCaso() {
    long long int entrada;
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;

    cout << eliminar_no_final(entrada)<<" " << eliminar_final(entrada,0,1) << endl;

    return true;
}

/*
Eliminar los d´ıgitos pares de un n´umero
Para que los ni˜nos de su clase aprendan a manejar los n´umeros enteros, la profesora ha ideado un
juego. Ella dice un n´umero y los alumnos deben transformarlo seg´un la regla que toque ese d´ıa. Hoy
debemos decir el n´umero que resulta de eliminar los d´ıgitos pares dejando solo los impares. El d´ıgito 0
se considera que es par.
Requisitos de implementaci´on.
Debe realizarse una funci´on recursiva final y otra recursiva no final.
La implementaci´on debe realizarse utilizando una funci´on recursiva que reciba el n´umero y devuelva
el n´umero calculado como resultado de la funci´on (no como par´ametro). La entrada y salida de datos
debe realizarse en la funci´on resuelveCaso. No se pueden utilizar estructuras auxiliares (vectores...).
Entrada
La entrada consta de una serie de casos de prueba. Cada caso se escribe en una l´ınea y consiste en
un n´umero entero positivo mayor que cero n tal que 0 ≤ n ≤ 2
63 − 1.
Salida
Para cada caso de prueba se muestra en una l´ınea el n´umero obtenido con la funci´on recursiva final
y el n´umero obtenido con la funci´on recursiva no final.
Entrada de ejemplo
273645
4327
3
555
0
98543
34
500
400
Salida de ejemplo
735 735
37 37
3 3
555 555
0 0
953 953
3 3
5 5
0 0


*/