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

void resolver(const vector<int> & v,int longitud) {
    int suma_max;
    int suma=0;
    int pos_ini = 0;
    int pos_fin = 0;

    for (int i = 0; i < longitud; i++) {
        suma += v[i];
    }
    suma_max = suma;


    for (int i = longitud; i < v.size(); i++) {
        suma += v[i];
        suma -= v[i - longitud];

        if (suma > suma_max) {
            suma_max = suma;
            pos_ini = i-longitud+1;
            pos_fin = i-longitud+1;
        }
        else if (suma == suma_max) {
            pos_fin = i-longitud+1;
        }
    }
    cout << suma_max << " " << pos_ini << " " << pos_fin << endl;
}

bool resuelveCaso() {

    int entrada,longitud;
    
    cin >> entrada;
    cin >> longitud;
    if (entrada==0)
        return false;
    vector<int >v(entrada);
    for (int& k : v) {
        cin >> k;
    }

    resolver(v,longitud);


    // escribir sol

    return true;
}
