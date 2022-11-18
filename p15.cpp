
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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

void eliminar(vector<int >& v) {
    int bueno = 1;

    for (int i = 1; i < v.size(); i++) {
        if (v[i ] != v[bueno-1]) {
            swap(v[i], v[bueno]);

            bueno++;
        }


    }

    v.resize(bueno);

}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    int entrada;
    cin >>entrada;
    if (!std::cin)  // fin de la entrada
        return false;

    
    vector<int> v(entrada);

    for (int& k : v) {
        cin >> k;
    }

    sort(v.begin(), v.end());
    eliminar(v);
    for (int k : v) {
        cout << k << " ";

    }
    cout << '\n';

    return true;
}

