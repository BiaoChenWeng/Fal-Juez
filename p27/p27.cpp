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


int repartir(const vector<int >& v, int longitud) {
    int contador=0;
    int contador_pos_der=0;
    int contador_pos_izq = 0;

    for (int i = 0; i < longitud; i++) {
        if (v[i] > 0 && i < longitud / 2) {
            contador_pos_der++;
        }
        else if (v[i] > 0 && i >= longitud / 2) {
            contador_pos_izq++;
        }
    }

    if (contador_pos_der >= contador_pos_izq)
        contador++;

    for (int i = longitud; i < v.size(); i++) {
        if (v[i - longitud]>0) {
            contador_pos_der--;
        }
        if (v[i] > 0) {
            contador_pos_izq++;
        }
        if (v[i - longitud / 2] > 0) {
            contador_pos_der++;
            contador_pos_izq--;
        }
        if (contador_pos_der >= contador_pos_izq)
            contador++;
    }



    return contador;
}


bool resuelveCaso() {

    int entrada,longitud;
    cin >> entrada;
    cin >> longitud;
    
    if (entrada==0)
        return false;
    vector <int >v(entrada);

    for (int& k : v) {
        cin >> k;
    }

    
    cout << repartir(v, longitud)<<endl;


    // escribir sol

    return true;
}
