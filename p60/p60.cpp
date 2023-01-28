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

/*
El numero de rama que tiene son los colores con lo que puede estar formado la torre
por otro lado la altura de la torre es el alto del arbol

en este problema se nos pide que el rojo ha de ser el primer elemento,
por lo que eso lo inicializamos fuera de la permutacion
*/


bool esValida(string a, string b) {
    return !(a == b && a == "verde");
}


void permutacion(int k, vector<string>& sol, vector<string >& color) {
    
    
    for (int i = 0; i < color.size(); i++) {
        sol[k] = color[i];
        if (esValida(sol[k],sol[k-1])) {
            if (k == sol.size() - 1) {
                for (int j = 0; j < sol.size(); j++) {
                    cout << sol[j] << " ";
                }
                cout << endl;
            }
            else {
                permutacion(k + 1, sol, color);
            }
        }
        
    }
}


bool resuelveCaso() {

    int entrada;
    cin >> entrada;
    if (entrada == 0)
        return false;

    vector<string >color(3);
    vector<string >sol(entrada);
    color[0] = "azul";
    color[2] = "verde";
    color[1] = "rojo";
    // escribir sol
    sol[0] = color[1];

    if (sol.size() == 1) {
        cout << sol[0]<<endl;
    }
    else {
        permutacion(1, sol, color);
    }

    
    cout << endl;
    return true;
}
