
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


int suma(const vector<int>& v,int i,int target,tMatriz &a) {
    if (target == 0) {
        return 1;
    }
    
    else if(i==0 && target>0) {
        return 0;
    }
    else {
        if (a[i - 1][target] == -1)
            a[i - 1][target] = suma(v, i - 1, target, a);
        if (target - v[i - 1] >= 0 ) {
            if(a[i - 1][target - v[i - 1]] == -1)
                a[i - 1][target - v[i - 1]] = suma(v, i - 1, target - v[i - 1], a);
            return a[i][target] = a[i - 1][target] + a[i - 1][target - v[i - 1]];
        }
        else {
            return a[i][target] = a[i - 1][target];
        }

       

    }

}

bool resuelveCaso() {
    int entrada;
    int target;
    cin >> entrada;
    cin >> target;
    if (!std::cin)  // fin de la entrada
        return false;
    tMatriz a(entrada+1,vector<int>(target+1,-1));
    vector<int >v(entrada);

    for (int& k : v)
        cin >> k;



    cout << suma(v,entrada, target,a)<<endl;
    return true;
}

/*

Calcula el n´umero de formas de obtener un
valor con unos ciertos n´umeros realizando solo
sumas
Nos dan un vector de n´umeros enteros positivos todos ellos diferentes y un valor entero S. Nos piden
el n´umero de formas distintas que hay de obtener la cantidad S utilizando ´unicamente sumas y los valores
del vector. S´olo se puede utilizar cada valor una vez.
Requisitos de implementaci´on.
Definir la estrategia recursiva que se va a utilizar.
Utilizar una matriz como par´ametro acumulador para evitar repetir llamadas recursivas.
Entrada
La entrada consiste en una serie de casos de prueba. Cada caso se define en dos l´ıneas. En la primera
aparece el n´umero de elementos del vector y la cantidad S que se quiere obtener. En la segunda l´ınea
aparecen los valores del vector separados por un blanco.
Salida
Para cada caso de prueba se escribe en una l´ınea el n´umero de formas de obtener la cantidad S.
Entrada de ejemplo
3 4
1 2 3
4 3
2 1 3 4
5 6
4 2 3 5 1
5 10
4 2 6 3 5
Salida de ejemplo
1
2
3
2
Autor: Isabel Pita.
1
*/