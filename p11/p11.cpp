#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>// Introduce más librerías si son necesarias
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

vector<int> resolver(const vector<int >& v, int max) {
    vector<int >aux(max,0);
    vector<int>sol;
    int contador=1;
    for (int i = 0; i < v.size(); i++) {
        aux[v[i] - 1]++;
    }

    for (int i = 0; i < aux.size(); i++) {
        if (contador < aux[i]) {
            contador = aux[i];
            sol.clear();
            sol.push_back(i+1);
            
        }
        else if (contador == aux[i]) {
            sol.push_back(i+1);
        }

    }



    return sol;
}

bool resuelveCaso() {

    int entrada;
    int max;
    cin >> entrada;
    cin >> max;
    if (entrada==-1)
        return false;

    vector<int >v(entrada);
    vector<int >sol;
    for (int& o : v)
        cin >> o;

    
    sol = resolver(v, max);
    for (int i = sol.size() - 1; i >= 0;i--) {
        cout << sol[i] << " ";
    }

    cout << endl;

    return true;
}
