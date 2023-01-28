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

// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int entrada;
    cin >> entrada;
    vector<int>v;

    while (entrada != 0) {
        v.push_back(entrada);
        cin >> entrada;
    }
    int max = v[0];
    int rep = 1;
    for (int i = 1; i < v.size(); i++) {
        if (max == v[i])
            rep++;
        else if(v[i]>max) {
            rep = 1;
            max = v[i];
        }
    }

    cout << max << " " << rep << endl;

}
