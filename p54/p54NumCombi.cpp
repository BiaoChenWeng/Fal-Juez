
#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;
using tMatriz = vector<vector<int>>;
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


int sol(int a, int b, tMatriz &v) {
    if (a == b || b==0) {
        return v[a][b]=1;
    }
    else if (b + 1 == a|| b==1) {
        return v[a][b]=a;
    }
    else {

        if (v[a - 1][b - 1] == -1) {
            v[a-1][b-1]=sol(a - 1, b - 1, v);
        }
        if (v[a - 1][b] == -1) {
            v[a - 1][b] = sol(a - 1, b, v);
        }

        return v[a][b] = v[a - 1][b - 1] + v[a - 1][b];

    }


}

bool resuelveCaso() {
    int entrada;
    int b;
    cin >> entrada;
    cin >> b;
    if (!std::cin)  // fin de la entrada
        return false;
    tMatriz a(entrada+1,vector<int>(b+1,-1));
    
    cout << sol(entrada, b, a)<<endl;

    return true;
}

