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


void quitarError(vector<int> &v,int error) {
    int bueno=0;
    
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != error) {
            swap(v[bueno],v[i]);
            bueno++;
        }
        

    }

    v.resize(bueno);

}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    
    int tam, error;
    cin >> tam;
    cin >> error;

    vector<int > v(tam);

    for (int& j : v) {
        cin >> j;
    }


    quitarError(v, error);
    cout << v.size()<<'\n';
    for (int k : v) {
        cout << k<<" ";

   }
    cout <<  '\n';
}
