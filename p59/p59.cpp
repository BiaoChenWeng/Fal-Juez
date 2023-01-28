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


void permutacion(int k, vector<string>& sol, const vector<string >& color) {
    for (int i = 0; i < color.size(); i++) {
        sol[k] = color[i];
        if (k == sol.size() - 1) {
            for (int j = 0; j < sol.size(); j++) {
                cout << sol[j] << " ";
            }
            cout << endl;
        }
        else {
            permutacion(k + 1, sol, color);
        }
    }
}

// tam de etapa =entrada ; tam vector
// tam de rama =  3 de los 3 colores 

bool resuelveCaso() {

    int entrada;
    cin >> entrada;
    if (entrada == 0)
        return false;

    vector<string >color(3);
    vector<string >sol(entrada);
    color[0] = "azul";
    color[2] = "verde";
    color[1] = "rojo";
    // escribir sol
    permutacion(0, sol, color);
    cout << endl;
    return true;
}
