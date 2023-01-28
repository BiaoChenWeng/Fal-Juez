#include <vector>
#include <iostream>
#include <fstream>
// Introduce más librerías si son necesarias
using namespace std;

const int VALOR_MIN = 0;
const int VALOR_MAX = 1000;
void suma(int menor, vector<long int> v);
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



// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int tam;
    int valor_menor;
    cin >> tam;

    vector < long int> v(tam);
    
    for (int i = 0; i < tam; i++) {
        cin >> v[i];
        if (i == 0 || valor_menor > v[i])
            valor_menor = v[i];
    }
        
    suma(valor_menor, v);


    
}



void suma(int menor, vector<long int> v) {
    int comp_sumado = 0;
    long long int suma=0;
    for (int i = 0; i < v.size(); i++) {
        if ( v[i] != menor) {
            suma += v[i];
            comp_sumado++;

        }
    }
    cout << suma << " " << comp_sumado << endl;
}
