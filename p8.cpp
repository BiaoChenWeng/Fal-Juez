#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;
void resuelveCaso();
void puerta_xor(const vector<int>& a, const vector<int>& b, vector<int>& c);
void entrada(vector<int>& v);
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

void entrada(vector<int>& v) {
    int entrada;
    cin >> entrada;
    while (entrada != 0) {
        v.push_back(entrada);
        cin >> entrada;
    }
}



void puerta_xor(const vector<int>& a, const vector<int>& b, vector<int>& c) {
    int i = 0;
    int j = 0;
    

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            c.push_back(a[i]);
            i++;
        }
        else if (a[i] > b[j]) {
            c.push_back(b[j]);
            j++;
        }
        else {
            i++;
            j++;
        }
    }

    while (i < a.size()) {
        c.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        c.push_back(b[j]);
        j++;
    }



    
    

}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    
    vector <int>a;
    vector <int>b;
    vector <int>c;
    
    entrada(a);
    entrada(b);

    puerta_xor(a, b, c);

    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}
