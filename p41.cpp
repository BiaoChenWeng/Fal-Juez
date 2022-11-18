#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;
void resuelveCaso();




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

int sol(vector<int >a, vector<int >b,int ini ,int fin) {
    
    if (ini+1==fin) {
        return ini;
    }
    else {
        int m = (ini + fin - 1) / 2;
        
        if (a[m] + a[ini] == b[m] + b[ini] ) {
            return sol(a, b, m+1, fin);
        }
        else {
            return sol(a, b, ini, m + 1);
        }

    }
}



// configuración, y escribiendo la respuesta
void resuelveCaso() {

    int entrada;
    cin >> entrada;
    vector<int >a(entrada);
    vector<int >b(entrada-1);

    for (int& l : a) {
        cin >> l;
    }
    for (int& l : b) {
        cin >> l;
    }

    cout << a[sol(a, b, 0, a.size()) ] << endl;
    

}
/*
Buscar el elemento perdido
Se tienen dos vectores, a y b, de enteros ordenados y distintos entre s´ı con n y n-1 elementos respectivamente. Los elementos de b son los mismos que tiene a excepto uno que falta. Se pide implementar
un algoritmo recursivo eficiente que encuentre ese valor que falta. Se debe indicar la recurrencia y el
coste asint´otico en el caso peor del algoritmo. (Examen junio 2017)
Requisitos de implementaci´on.
Se debe implementar una funci´on recursiva que reciba los dos vectores y devuelva el valor que falta.
Pueden utilizarse m´as par´ametros de entrada si hacen falta.
Se valorar´a la eficiencia de la soluci´on, el uso eficiente de variables y par´ametros, los comentarios
sobre el algoritmo y sobre su coste.
Entrada
La entrada comienza con el n´umero de casos a tratar. Cada caso consta de 3 l´ıneas, en la primera
se da el n´umero de elementos del primer vector, en la segunda los elementos del primer vector y en la
tercera los elementos del segundo vector.
Los valores de los vectores son n´umeros enteros.
Salida
Para cada caso de prueba se escribe en una l´ınea el n´umero que falta.
Entrada de ejemplo
5
5
10 20 30 40 50
10 30 40 50
5
10 20 30 40 50
10 20 30 40
5
10 20 30 40 50
20 30 40 50
1
6
2
1 8
1
Salida de ejemplo
20
50
10
6
8
1*/