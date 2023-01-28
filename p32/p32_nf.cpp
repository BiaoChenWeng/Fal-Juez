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

string decimal_binaria(int n) {
    if (n < 2) {
        if (n % 2 == 0) {
            return to_string(0);
        }
        else {
            return to_string(1);
        }
    }

    else {
        if (n % 2 == 0) {
            return  decimal_binaria(n / 2)+ to_string(0)  ;
        }
        else {
            return decimal_binaria(n / 2)+ to_string(1)  ;
        }

    }

}

// configuración, y escribiendo la respuesta

void resuelveCaso() {

    int entrada;
    cin >> entrada;

    
    
    cout << decimal_binaria(entrada);

    cout << "\n";

}

