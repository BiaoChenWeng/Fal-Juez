
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
// Introduce más librerías si son necesarias
using namespace std;
using lli = long long int;
struct sol {
    bool tiene_uno;
    lli num;
};
struct trampa {
    int suma;
    int valor;
};

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





sol contar_sin_uno(lli n) {
    sol a;
    if (n < 10) {
        if (n == 0) {
            a.tiene_uno = false;
            a.num = 1;
            return a;
        }
        else if (n == 1) {
            a.tiene_uno = true;
            a.num = 1;
            return a;
        }
        else {
            a.num = n;
            a.tiene_uno = false;
            return a;
        }
    }
    else {
        a = contar_sin_uno(n / 10);
        if (a.tiene_uno) {
            a.num = (a.num * 9);
            return a;
        }
        else if (n%10 <=1) {
            if (n % 10 == 1) {
                a.tiene_uno = true;
            }
            a.num = (a.num * 9) - 8;
            return a;
        }
        else {
            a.num =(a.num * 9) - (9 - (n % 10));
            return a;
        }
    }



}

bool resuelveCaso() {
    lli entrada;
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;

    cout << contar_sin_uno(entrada).num << endl;
    
    return true;
}

