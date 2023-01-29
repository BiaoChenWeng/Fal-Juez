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

int pagina(const vector<int>& v, int pag) {
    int empezar = 0;
    int suma_max = 0;
    int pos_max=0;
    int suma_actual=0;
    for (int i = 0; i < pag; i++) {
        suma_max += v[i];
        if (v[pos_max] <= v[i])
            pos_max = i;
    }
    suma_actual = suma_max;

    for (int i = pag; i < v.size(); i++) {
        suma_actual += v[i] - v[i - pag];
        if (v[pos_max] == v[i]) {         
            if (suma_actual >= suma_max) {
                suma_max=suma_actual;
                empezar = i - pag + 1;
            }          
            pos_max = i;

        }
        else if(v[pos_max]<v[i]) {
            empezar = i - pag+1;
            pos_max = i;        
            suma_max = suma_actual;
        }
        else {            
            if (pos_max > i - pag && suma_actual>=suma_max) {
                suma_max = suma_actual;
                empezar = i - pag + 1;
            }
        }
    }

    return empezar;
}

bool resuelveCaso() {

    int entrada,tiempo;
    cin >> entrada>>tiempo;
    if (entrada==0 && tiempo==0)
        return false;

    vector<int>v(entrada);
    for (int& l : v)
        cin >> l;

    cout << pagina(v, tiempo)<<endl;

    return true;
}
