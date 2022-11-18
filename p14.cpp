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

int resolver(vector<int >& v) {
    int contador=1;
    int max=1;
    
    sort(v.begin(), v.end());
    int carretera = v[0];
    for (int i = 0; i < v.size()-1; i++) {
        if (v[i] == v[i+1] ) {
            contador++;
            if (contador > max) {
                max = contador;
                if (v[i] != carretera) {
                    carretera = v[i];
                }
            }
        }
        else {
            contador = 1;
        }

    }

    return carretera;
}

bool resuelveCaso() {

    int entrada;
    cin >> entrada;
    if (entrada==-1)
        return false;

    vector<int >v(entrada);

    for (int& o : v)
        cin >> o;

    cout <<resolver(v)<<endl;


    

    return true;
}
