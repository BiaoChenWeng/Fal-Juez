#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;
void resuelveCaso();

struct resp {
    bool interesante;
    int suma;
};


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


resp num(int n,resp sol) {
    if (n %10 ==0) {
        sol.interesante = false;
        return sol;
    }
    else {
        if (n < 10) {
            if (sol.interesante)
                sol.interesante = sol.suma % n==0;
            sol.suma = n;
            return sol;
        }
        else {
            resp a;
            sol.interesante = sol.interesante && sol.suma % (n % 10) == 0;
            sol.suma += n % 10;
            sol = num(n / 10, sol);
            sol.interesante = sol.interesante && sol.suma % (n % 10) == 0;
            sol.suma += n % 10;

            return sol;
        }
    }


}

// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int entrada;
    cin >> entrada;
    resp a;
    a.suma = 0;
    a.interesante = true;
    if (num(entrada, a).interesante) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }
}
