
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
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

void permutacion(int m, int n,int etapa,vector<char>&v,vector<bool>&dato) {
    for (char i = 'a'; i < 'a' + m; i++) {
        if (!dato[i - 'a']) {
            v[etapa] = i;
            dato[i - 'a'] = true;
            if (n - 1 == etapa) {
                for (int i = 0; i < n; i++) {
                    cout << v[i];
                }
                cout << endl;
            }
            else  {
                permutacion(m, n, etapa + 1, v, dato);
                
            }
            dato[i - 'a'] = false;

        }
        
        
        
      

    }


}


bool resuelveCaso() {
    int entrada,n;
    cin >> entrada;
    cin >> n;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<char>v(n);
    vector<bool>dato(entrada,false);
    

    permutacion(entrada, n, 0, v,dato);
    cout << "\n";

    return true;
}

