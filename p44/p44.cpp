
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

bool sol(vector<int >const& v,int ini,int fin,int suma) {
    
    if (ini + 1 == fin)
        return true;

    else if(ini+2==fin) {

        return v[ini]<v[fin-1];
    }
    else {
        int m = (ini + fin) / 2;
        int suma2=0;
        for (int i = ini; i < m; i++) {
            suma2 += v[i];
        }
        
        return suma2 < suma-suma2&& sol(v, ini, m, suma2) && sol(v, m, fin, suma-suma2);
    }
}


bool resuelveCaso() {
    int entrada, col;
    bool respuesta=true;
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> col;
    vector<vector<int>>v(entrada,vector<int>(col));
        
    for (int i = 0; i < entrada; i++) {
        for (int j = 0; j < col; j++) {
            cin >> v[i][j];
          
        }

    }
    int c=0;
    int suma;
    while (respuesta && c < entrada) {
        suma = 0;
        for (int m = 0; m < col; m++) {
            suma += v[c][m];
        }
        respuesta = sol(v[c], 0, col, suma);
        c++;
    }

    if (respuesta) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }

    return true;
}

