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
    cin >> entrada ;
    vector<int>v(entrada);
    for (int& k : v)
        cin >> k;
    int rep=1;

    long long int suma_total = 0;
    long long int suma_inferior = v[0];
    int min = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == min) {
            suma_inferior += v[i];
            rep += 1;
        }           
        else if (v[i] > min)
            suma_total += v[i];
        else {
            suma_total += suma_inferior;
            suma_inferior = v[i];
            rep = 1;
            min = v[i];
        }
    }
    cout << suma_total << " "<<v.size()-rep << endl;
}
