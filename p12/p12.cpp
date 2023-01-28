#include <iostream>
#include <fstream>
#include <vector>
/*
el programa tiene coste 2 O(n) + 2 O(k) haciendo que tenga O(n)
tiene algunos coste lineal , pero se simplifica al final.
*/


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
    if (entrada == -1)
        return false;

    
    vector<int >etapa(entrada);
    
    for (int& h : etapa)
        cin >> h;

    cin >> entrada;
    vector<int> pregunta(entrada);
    
    for (int& k : pregunta) {
        cin >> k;
    }
    vector<long long int> suma(etapa.size() + 1);
    suma[suma.size() - 1] = 0;
    for (int i = etapa.size() - 1; i >= 0; i--) {
        suma[i] = etapa[i] + suma[i + 1];

    }

    for (int i = 0; i < pregunta.size(); i++) {

        cout  << suma[pregunta[i] - 1] <<"\n";
    }

    cout << "---\n";

    return true;
}
