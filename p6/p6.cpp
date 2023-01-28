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

vector<int> lista_nueva(vector<int>& a, vector<int>& b) {
    vector<int>c;
    int i = 0,j=0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            c.push_back(a[i++]);           
        }
        else if (a[i] > b[j]) {
            c.push_back(b[j++]);
            
        }
        else {
            c.push_back(a[i++]);
            c.push_back(b[j++]);
        }

    }

    while (i < a.size())
        c.push_back(a[i++]);
    while (j < b.size())
        c.push_back(b[j++]);
    return c;
}

// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int entrada,entrada2;
    cin >> entrada>>entrada2 ;
    vector<int>a(entrada);
    vector<int>b(entrada2);
    for (int& k : a)
        cin >> k;
    for (int& k : b)
        cin >> k;

    vector <int>c;
    c = lista_nueva(a, b);
    for (int l : c)
        cout << l<<" ";
    cout << endl;
 }
