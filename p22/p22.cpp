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

void resolver(const vector<int> & v) {
    int longitud=0;
    int longitud_max=0;
    int pos=1;
    int valor_max=v[0];

    for (int i = 1; i < v.size() ; i++) {
        if (valor_max >= v[i]) {
            longitud++;
            if (longitud >= longitud_max) {
                pos = i -longitud+ 1;
                longitud_max = longitud;
            }
                


        }
        else {
            valor_max = v[i];
            longitud = 0;
            if (longitud_max == 0) {
                pos = i + 1;
            }
        }
    }

    cout << longitud_max << " " << pos << endl;
}

bool resuelveCaso() {

    int entrada;
    cin >> entrada;
    if (entrada==0)
        return false;
    vector<int >v(entrada);
    for (int& k : v) {
        cin >> k;
    }

    resolver(v);


    // escribir sol

    return true;
}
/*
¿Cuanto tiempo llevas sin batir tu mejor
marca?
En la escuela de atletismo llevan un registro de las marcas de cada
participante en las pruebas que van realizando. Para seleccionar los
pr´oximos participantes en las competiciones mundiales, quieren saber
para cada uno de ellos cu´antas pruebas consecutivas ha estado como
m´aximo sin conseguir mejorar su marca personal y cuando comenz´o
la ´ultima de sus malas rachas.
Requisitos de implementaci´on.
El orden de complejidad del algoritmo debe ser lineal respecto al
n´umero de marcas de cada participante.
Entrada
La entrada consta de una serie de casos de prueba. Cada caso de prueba comienza con el n´umero
de marcas que se tienen del atleta. En la l´ınea siguiente se muestran los datos de las marcas ordenadas
seg´un se fueron tomando en las pruebas. El final de datos se marca con el valor 0.
El n´umero de marcas de los atletas es mayor que cero. Cada marca es un n´umero entero mayor que
cero y menor que 1.000.
Salida
Por cada caso de prueba el programa escribir´a una l´ınea con el m´aximo de pruebas en que el atleta
no ha mejorado su mejor marca hasta ese momento, seguido del comienzo del ´ultimo periodo m´aximo de
pruebas en que no mejor´o su marca. La primera marca tomada es en la prueba n´umero cero.
Entrada de ejemplo
4
7 5 4 3
10
5 7 10 7 8 12 9 11 15 20
9
4 8 6 2 8 6 10 9 9
4
5 5 5 5
3
2 3 6
0
Salida de ejemplo
3 1
2 6
4 2
3 1
0 3
Autor: Isabel Pita

*/