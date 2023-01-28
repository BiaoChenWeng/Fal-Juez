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



bool resuelveCaso() {

    int entrada;
    cin >> entrada;
    if (entrada==0)
        return false;
    string buscar;
    cin >> buscar;
    vector<string>v(entrada);
    for (string& k : v)
        cin >> k;
    int i = v.size() - 1;
    while (i >= 0 && v[i] != buscar)
        i--;
    // escribir sol
    if (i >= 0) {
        cout << v.size()-i<<endl;
    }
    else {
        cout << "NUNCA\n";
    }
    return true;
}
