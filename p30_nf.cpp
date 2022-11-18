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


int sumaDigito(int n) {

    if (n < 10) {
        return n;
    }

    else {
        return sumaDigito(n / 10)+n%10;

    }


}
// configuración, y escribiendo la respuesta

void resuelveCaso() {

    int entrada,valor;
    cin >> entrada;
    cin >> valor;
    vector <int >v(entrada);

    for (int& k : v)
        cin >> k;
    int respuesta=sumaDigito(valor);
    for (int i = 0; i < v.size(); i++) {
        
        if (respuesta == sumaDigito(v[i])) {
            cout << v[i] << " ";
        }

    }
    cout << "\n";

}

