
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


int menor(vector<int >const& v, int ini, int fin) {
    if (ini == fin) {
        return 0;
    }
    else if (ini + 1 == fin) {
        return ini;
    }
    else {
        int m = (ini + fin-1) / 2;
        if (v[m] < v[m + 1]) {
            return menor(v, ini, m + 1);
        }
        else if(v[m]>v[m+1]) {
            return menor(v, m +1, fin);
        }

    }
}

/*
T(n) c0     caso base
     T(n/2)+c1  cc

T(n)=T(n/2)+c2= T(n/2^2)+c2+c2= t(n/2^3) + 3c2------
t(n/2^k)+ kc2=-----------=t(1)+ log2n*c2=log2n*c2+ c0

1=n/2^k => n=2^k =>log2n= k

coste logaritmico

*/

bool resuelveCaso() {
    int entrada;
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<int >v(entrada);

    for (int& k : v) {
        cin >> k;
    }

    cout << v[menor(v, 0, v.size())] << endl;
    return true;
}

/*
P´erfil de una curva c´oncava
Dados una serie de valores cuyo p´erfil se ajusta al de una curva c´oncava, siendo estrictamente decrecientes hasta un determinado valor a partir del cual son estrictamente crecientes, se pide encontrar el
valor del m´ınimo. Se admiten l´ıneas estrictamente crecientes o estrictamente decrecientes.
Requisitos de implementaci´on.
Indicar la recurrencia utilizada para el c´alculo del coste y el coste de la soluci´on obtenida.
La soluci´on obtenida debe emplear la t´ecnica de divide y vencer´as
La funci´on que resuelve el problema debe recibir los datos en un vector y devolver el valor del m´ınimo.
Entrada
La entrada consta de una serie de casos de prueba. Cada caso de prueba consta de dos l´ıneas, en la
primera se indica el n´umero de elementos del vector y en la segunda los valores del vector separados por
blancos.
El n´umero de elementos del vector es mayor que cero y no hay dos valores consecutivos iguales.
Salida
Para cada caso de prueba se escribe en una l´ınea el m´ınimo de la curva.
Entrada de ejemplo
5
7 5 3 8 9
8
9 8 7 6 5 4 3 2
1
2
2
3 5
10
34 25 12 10 9 8 7 6 5 9
Salida de ejemplo
3
2
2
3
5
Autor: Isabel Pita.
*/