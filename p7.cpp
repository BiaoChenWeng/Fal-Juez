#include <vector>
#include <iostream>
#include <fstream>
// Introduce más librerías si son necesarias
using namespace std;


void resuelveCaso();
void ordenar(vector<int>a, vector<int> b);

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



void mejor_venta(const vector <int> v,int comienzo) {
    int max = v[0];

    for (int i = 1; i < v.size(); i++) {
        if (max < v[i]) {
            cout << comienzo + i<<" ";
            max = v[i];
        }
    }

    cout << endl;

}

void resuelveCaso() {
    int comienzo,fin;
    cin >> comienzo;
    cin>> fin;
    vector <int>v(fin - comienzo + 1);

    for (int& k : v)
        cin >> k;

    mejor_venta(v, comienzo);



}
