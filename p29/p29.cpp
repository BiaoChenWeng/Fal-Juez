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

int sol(const vector<int >& v, int tam) {
    int contador_pares=0;
    int longitud_max = 0;
    int j=0;
    int longitud=0;
    int i=0;
    

    for (int i = 0; i < v.size(); i++) {
        if (v[i] % 2 == 0) {
            contador_pares++;
            
            if (contador_pares > tam) {
                longitud = tam -1;
                contador_pares--;
            }
            
        }
        else {
            contador_pares = 0;
        }

        longitud++;
        if (longitud_max < longitud) {
            longitud_max = longitud;
        }
    }


    return longitud_max;
}


// configuración, y escribiendo la respuesta
void resuelveCaso() {

    int entrada,tam;
    cin >> entrada;
    cin >> tam;
    vector <int >v(entrada);

    for (int& k : v)
        cin >> k;

    cout << sol(v, tam) << endl;


}

/*
1. (3.5 puntos) Dado un vector v de enteros positivos y un natural k ≥ 0, se desea encontrar la
longitud del segmento m´as largo que no contenga ning´un subsegmento con (estrictamente) m´as de
k n´umeros pares consecutivos.

Entrada
La entrada comienza con una l´ınea que contiene el n´umero de casos de prueba. Cada caso de prueba
contendr´a el n´umero de elementos, el valor de k y a continuaci´on los elementos de la secuencia.
Salida
Por cada caso de prueba el programa escribir´a una l´ınea con la longitud del segmento m´as largo
solicitado en el enunciado.
Entrada de ejemplo
5
8 4
1 2 6 4 8 10 3 7
8 2
1 2 4 3 9 6 8 7
4 7
2 4 6 8
3 0
2 4 6
3 1
2 4 6
Salida de ejemplo
6
8
4
0
1

*/