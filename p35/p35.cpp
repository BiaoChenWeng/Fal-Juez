#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;
void resuelveCaso();

int final(int num,int resultado,int mayor,int pot) {
    if (num == 0) {
        return resultado;

    }
    else {
        if (num % 10 < mayor) {
            return final(num / 10, resultado, mayor, pot);
        }
        else {
            return final(num / 10, resultado + (num % 10) * pot, num % 10, pot * 10);
        }
    }
}


int no_final(int num, int num_mayor) {
    if (num == 0) {
        return 0;
    }

    else {
        if (num % 10 < num_mayor) {
            return no_final(num / 10, num_mayor);
        }
        else {
            return no_final(num / 10, num % 10) * 10 + (num % 10);
        }
    }
}


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

// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int entrada;
    cin >> entrada;

    cout << no_final(entrada, -1)<<" "<<final(entrada,0,-1,1)<<endl;
}
