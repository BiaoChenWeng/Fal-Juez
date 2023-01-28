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

int jug(int n) {
    if (n < 10) {
        if (n % 2 == 0)
            return n+1;
        else {
            return n-1;
        }
    }

    else {
        if (n % 2 == 0) {
            return jug(n / 10) * 10 + n % 10 + 1;
        }
        else {
            return jug(n / 10) * 10 + n % 10 - 1;
        }
    }
}

// configuración, y escribiendo la respuesta

void resuelveCaso() {

    int entrada;
    cin >> entrada;

    
    
    cout << jug(entrada);

    cout << "\n";

}

