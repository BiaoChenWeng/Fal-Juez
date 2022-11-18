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

int pos_impar(vector<int >const& v, int ini, int fin) {
    if (ini +1== fin) {
        return v[ini];
    }
    else if(ini+2==fin) {
        if (v[ini] % 2 == 1) {
            return v[ini];
        }
        else {
            return v[ini+1];
        }
    }
    else {
        int m = (ini + fin-1) / 2;

        if (v[m] - v[ini] == (m - ini )* 2) {
            return pos_impar(v, m + 1, fin);
        }
        else {
            return pos_impar(v, ini, m+1);
        }
    }

}



bool resuelveCaso() {

    int entrada;
    cin >> entrada;
    if (entrada==0)
        return false;
    vector<int >v(entrada);

    for (int& k : v) {
        cin >> k;
    }

    cout << pos_impar(v, 0, v.size()) << endl;
    // escribir sol

    return true;
}

/*

Implementa un algoritmo recursivo eficiente que dado un vector de n´umeros enteros positivos y
consecutivos del que se han eliminado todos los elementos impares menos uno, encuentre cu´al es ese
n´umero impar que ha quedado en el vector. Plantea la recurrencia correspondiente al coste de este
algoritmo e indica a qu´e orden de complejidad pertenece la soluci´on a la misma.
Entrada
La entrada consta de una serie de casos de prueba. Cada caso de prueba consta de 2 l´ıneas. En la
primera se indica el n´umero de elementos del vector una vez eliminados los elementos impares. En la
siguiente se indican los elementos del vector. El final de los casos se marca con el valor cero. El vector
tiene al menos un elemento. Se garantiza que siempre existe un elemento impar en el vector.
Salida
Para cada caso de prueba se escribe en una l´ınea el elemento impar del vector.
Entrada de ejemplo
4
6 8 9 10
4
1 2 4 6
4
4 5 6 8
4
4 6 8 9
5
1 2 4 6 8
5
2 3 4 6 8
1
3
2
5 6
2
6 7
0
Salida de ejemplo
9
1
5
9
1
3
3
5
7
*/