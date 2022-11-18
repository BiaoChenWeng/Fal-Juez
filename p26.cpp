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

int sol(const vector<bool>& v, int longitud) {
    int distancia=v.size()+1;
    int i, j;
    int contador_true=0;
    i = 0;
    while (i<v.size() && !v[i]) {
        i++;
    }

    if (i < v.size()) {
        j = i;
        contador_true++;
        if (contador_true == longitud)
            distancia = 1;
        i++;
    }


    while (i < v.size() ) {
        if (v[i]) {
            contador_true++;
            if (contador_true == longitud) {
                if(distancia > i - j + 1)
                    distancia = i - j + 1;
                contador_true--;
                j++ ;
                while (!v[j])
                    j++;
            }
        }

        i++;
    }
    return distancia;
}


bool resuelveCaso() {

    int entrada;
    cin >> entrada;
    if (entrada ==-1l)
        return false;
    vector <bool> v(entrada);
    int longitud;

    for (int i = 0; i < v.size(); i++) {
        cin >> longitud;
        if (longitud == 0) {
            v[i] = false;
        }
        else {
            v[i] = true;
        }
    }

    cin >> longitud;
    // escribir sol

    cout << sol(v, longitud) << endl;

    return true;
}
/*
Estructuras de Datos y Algoritmos
Grados en Ingeniería Informática
Examen Primer Cuatrimestre, 15 de enero de 2019. Grupos B y D
1. (4 puntos) Se desea desarrollar un algoritmo iterativo que, dado un entero positivo K y un vector
bool a[N], determine el tamaño del tramo más corto de a que contiene exactamente K valores
a true. En caso de que dicho tramo no exista, el algoritmo deberá devolver N+1.
Por ejemplo, para el vector
false false true false false true false true
el resultado para K=1 será 1, para K=2 será 3, para K=3 será 6, y para K>3 será 9 (ya que no
existe ningún tramo que contenga más de 3 valores a true).
Se pide:
(a) (1 punto) Especificar el algoritmo, y determinar el invariante y la función de cota
(b) (2,5 puntos) Diseñar justificadamente el algoritmo, e implementarlo.
(c) (0,5 puntos) Determinar justificadamente el orden de complejidad del algoritmo
La implementación deberá ir acompañada de un programa de prueba, que lea desde la entrada
estandar casos de prueba, los ejecute, e imprima por la salida estándar el resultado. Cada caso
de prueba será una línea que: (i) comenzará con un entero que indicará el tamaño N del vector
(dicho tamaño nunca excederá los 100 elementos); (ii) a continuación enumerará los valores del
vector (false se representará por 0, y true por 1); y (iii) por último, indicará el valor de K.
La salida será el valor devuelto por el algoritmo. El final de los casos de prueba se indicará
mediante una línea que contiene -1 como único valor. A continuación se muestra un ejemplo de
entrada / salida:
Entrada Salida
8 0 0 1 0 0 1 0 1 2
4 1 0 1 0 1
4 1 0 1 0 2
1 1 1
4 1 0 1 0 3
0 1
-1
3
1
3
1
5
1
*/