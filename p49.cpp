#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;
using c=pair<bool, int>;
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

c caucastico(const vector<int >&v, int ini, int fin) {
    if (ini == fin) {
        return make_pair(true,0);
    }
    
    if (ini + 1 == fin) {
        if(v[ini]%2==0)
            return make_pair(true, 1);
        else {
            return make_pair(true, 0);
        }
    }
    else {
        int m = (fin + ini) / 2;
        c a,b;
        a=caucastico(v, ini, m);
        b=caucastico(v, m, fin);
        if (a.first && b.first && abs(a.second - b.second) <= 2) {
            return make_pair(true, a.second + b.second);
        }
        else {
            return make_pair(false, 0);
        }
    }

}

/*
recurrencia

T(n)= c0    caso base
      2T(n/2) + c1   caso recursivo

T(n)=2T(n/2)+c1=  2(2T(n/2^2)+c1)+c1 =------
=  2^k (T(n/2^k ))  + sumatorio(i=0 ->k ) 2^i-1 * c1 -----

=---= 

n/2^k=1
n=2^k   => log n= k

n*c0+  (n)-1 * c1=> n*c0+ (n-1)c1
O(n)


//
El problema se soluciona igual que el problema del torneo de las canicas,
dado un vector lo dividimos hasta que llegar al caso base, donde miramos si es par o impar
despues comparamos si el numeros de pares entre los dos es menor a 3
si uno de los dos es false , entonces invalidará al resto de los elementos mientra sube
recurrencia no final, ya que usamos el elemento devuelto para calcular la solucion
*/

bool resuelveCaso() {
    c sol;
    int entrada;
    cin >> entrada;
    if (entrada==0)
        return false;

    vector<int >v(entrada);

    for (int& k : v)
        cin >> k;
    // escribir sol

    sol = caucastico(v, 0, v.size());
    if (sol.first) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }

    return true;
}
