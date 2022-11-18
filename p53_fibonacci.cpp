
#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;
using lli = long long int;

struct sol {
    lli n1;
    lli n2;
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

sol fibonachi(lli n) {
    sol a;
    if (n == 0) {
        a.n1 = 0;
        a.n2 = 0;
        return a;
    }
    else if (n == 1) {
        a.n1 = 1;
        a.n2 = 0;
        return a;
    }
    else {
        sol b;
        a= fibonachi(n - 1);
        b.n1 = a.n1 + a.n2;
        b.n2 = a.n1;

        return b;
    }

}


bool resuelveCaso() {
    lli entrada;
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;

    cout << fibonachi(entrada).n1<<endl;

    return true;
}

/*
La sucesi´on de Fibonacci.
La sucesi´on de Fibonacci fue descrita por Leonardo
da Vinci en el siglo XIII. Es famosa por sus numerosas
aplicaciones, y porque aparece en muchas formaciones
de la naturaleza.
La sucesi´on puede definirse de forma recursiva como
sigue:
f ib(n) =



0 n == 0
1 n == 1
f ib(n − 1) + f ib(n − 2) n > 1
Requisitos de implementaci´on.
Realizar una implementaci´on con recursi´on m´ultiple y comprobar que el tiempo de ejecuci´on es
inaceptable para valores de entrada mayores que 50.
Realizar una implementaci´on con recursi´on simple utilizando par´ametros acumuladores. Estudiar el
coste de esta soluci´on.
Entrada
La entrada consta de una serie de casos. Cada caso se escribe en una l´ınea y consiste en un n´umero
N (0 <= N <= 89).
Salida
Para cada valor de entrada mostrar en una l´ınea el elemento de la sucesi´on de Fibonacci en la posici´on
N. La posici´on del primer elemento de la sucesi´on es cero.
Entrada de ejemplo
0
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
1
Salida de ejemplo
0
1
1
2
3
5
8
13
21
34
55
89
144
233
377
610
987
1597
2584
4181
6765
2*/