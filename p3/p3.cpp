#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;


struct tEntradas {
    int tam;
    int pos;
};

void resuelveCaso();
bool check(vector<int> v, int pos);

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


void resuelveCaso() {
    tEntradas entrada;
    cin >> entrada.tam;
    cin >> entrada.pos;
    vector <int> v(entrada.tam);

    for (int& k : v)
        std::cin >> k;

    if (check(v, entrada.pos))
        cout << "NO";
    else
        cout << "SI";

    cout << endl;
 
}

bool check(vector<int> v,int pos) {
    int contador = pos + 1;
    int max = v[pos];

    for (int i = 0; i < pos; i++) {
        if (max < v[i])
            max = v[i];
    }

    while (contador < v.size() && max < v[contador])
        contador++;

    return contador < v.size();
}