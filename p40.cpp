#include <iostream>
#include <fstream>
#include <vector>

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


char busqueda(const vector<char>&v, char ini, char fin,char prim) {
    if (ini == fin) {
        return ini;
    }
    else if (ini + 1 == fin) {
        return ini;
    }

    else {
        char m = (ini + fin-1) / 2;
        
        if (v[m - prim] + v[ini-prim] == m + ini) {
            return busqueda(v, m + 1, fin,prim);
        }
        else {
            return busqueda(v, ini, m + 1,prim);
        }
    }


}


// configuración, y escribiendo la respuesta
void resuelveCaso() {
    char ini, fin;
    cin >> ini;
    cin >> fin;
    vector<char>v (fin-ini);

    for (char& l : v)
        cin >> l;

    cout << busqueda(v, ini, fin+1,ini)<<endl;
}
