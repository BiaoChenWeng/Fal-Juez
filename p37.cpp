
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



int buscarIz(const vector<int >&v,int altura,int ini,int fin) {
    if (fin == ini || ini + 1 == fin) {
        return ini;
    }
    else {
        int media = (fin + ini-1) / 2;
        if (v[media] < altura) {
            return buscarIz(v, altura, media + 1, fin);
        }
        else {
            return buscarIz(v, altura, ini, media+1);
        }

    }

}

int buscarDer(const vector<int >& v, int altura, int ini, int fin) {
    if (fin == ini || ini + 1 == fin) {
        return ini;
    }
    else {
        int media = (fin + ini ) / 2;
        if (v[media] > altura) {
            return buscarDer(v, altura, ini, media);
        }
        else {
            return buscarDer(v, altura, media, fin);
        }

    }

}


bool resuelveCaso() {
    int der, izq;
    int entrada,altura;
    cin >> entrada;
    cin >> altura;
    if (!std::cin)  // fin de la entrada
        return false;
    
    vector<int >v(entrada);
    for (int& k : v) {
        cin >> k;
    }
    izq = buscarIz(v,altura,0,v.size());
    der = buscarDer(v, altura, 0, v.size());
    if (izq==v.size() || v[izq]!= altura) {
        cout << "NO EXISTE\n";
    }
    else {
        if (izq == der) {
            cout << izq << endl;
        }
        else {
            cout << izq << " " << der << endl;
        }
    }
    return true;
}

