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


void nacimiento( int ini, const vector<long long int>& v) {
    int comienzo, fin;
    long long int calculo;
    cin >> comienzo;
    cin >> fin;
    
    if (comienzo<=fin && comienzo >= ini && fin <= ini+ v.size()+2) {
        calculo = v[fin - ini+1] - v[comienzo - ini];
        cout << calculo << endl;
    }

    

}


bool resuelveCaso() {
    int ini, end, vueltas;
    // leer los datos de la entrada
    
    cin >> ini;
    cin >> end;

    if (ini==0 && end==0)
        return false;

    vector <long int> dato(end - ini+1);
    vector <long long int> dato_sumado(dato.size()+1);
    for (long int& k : dato)
        cin >> k;

    dato_sumado[0] = 0;
    for (int i = 0; i < dato.size();i++) {
        dato_sumado[i+1] = dato[i]+dato_sumado[i];
    }

    cin >> vueltas;

    for (int i = 0; i < vueltas; i++) {
        nacimiento(ini, dato_sumado);
    }
    cout << "---" << endl;
    return true;
}
