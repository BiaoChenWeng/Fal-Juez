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

int sol(const vector<int >& v) {
    int longitud=1;
    int contador_creciente=0;
    int longitud_max=1;
    if (v.size() <= 0) {
        longitud_max = v.size();
    }
    else {
        for (int i = 0; i < v.size() - 1; i++) {

            longitud++;
            if (v[i] < v[i + 1]) {
                contador_creciente++;
                if (contador_creciente == 2) {
                    longitud = 2;
                    contador_creciente--;
                }
            }
            else {
                contador_creciente = 0;
            }
            if (longitud_max < longitud)
                longitud_max = longitud;
        }


    }
        

    return longitud_max;
}


// configuración, y escribiendo la respuesta

void resuelveCaso() {

    int entrada;
    cin >> entrada;
    
    vector <int >v(entrada);

    for (int& k : v)
        cin >> k;

    cout << sol(v) << endl;


}

/*
1. (3.5 puntos) Dado una secuencia de n enteros (n ≥ 0) se desea encontrar la longitud del segmento
m´as largo que no contiene ning´un subsegmento estrictamente creciente de tres elementos.

Entrada
La entrada comienza con una l´ınea que contiene el n´umero de casos de prueba. Cada caso de prueba
contendr´a el valor del n´umero de elementos n y a continuaci´on los elementos de la secuencia.
Salida
Por cada caso de prueba el programa escribir´a una l´ınea con la longitud del segmento m´as largo
solicitado en el enunciado.
Entrada de ejemplo
5
8
1 2 3 1 2 0 4 5
2
2 -1
5
1 1 1 2 2
6
0 4 1 2 -3 7
1
7
Salida de ejemplo
6
2
5
6
1
*/