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

bool final(int num, int suma,bool estado) {
    if (num % 10 == 0) {
        return false;
    }
    else {
        if (num < 10) {
            return suma % num == 0;
        }
        else {
            return final(num / 10, suma + (num % 10), suma % num == 0);
        }
    }


}

bool no_final(int num, int suma) {
    if (num % 10 == 0) {
        return false;
    }
    else {
        if (num < 10) {
            return suma % num == 0;
        }
        else {
            return (suma % (num % 10) == 0 && no_final(num / 10, suma + (num % 10)));
        }
    }
}

int invertir(int num,int resultado) {
    if (num == 0) {
        return resultado;
    }
    else {
        return invertir(num / 10, resultado * 10 + (num % 10));
    }
}

// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int entrada;
    cin >> entrada;




    if (no_final(entrada, 0)&& no_final(invertir(entrada,0),0) && final(entrada, 0, true) && final(invertir(entrada, 0), 0, true)) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }


    

    
}

/*
Fundamentos de Algoritmia
Grados en Ingeniería Informática
Convocatoria extraordinaria, 7 de septiembre de 2020. Grupos B, D y E
2. (3.5 puntos) Un numero natural se dice interesante cuando no contiene ningún cero, y cuando
cada dígito divide a la suma de todos los dígitos que lo preceden, y también divide a la suma de
todos los dígitos que lo suceden. Debe diseñarse e implementarse un algoritmo recursivo que,
dado un número natural n, devuelva true si n es interesante, y false en caso contrario. Debe
determinarse, asimismo, justificadamente el orden de complejidad del algoritmo.
La implementación deberá ir acompañada de un programa de prueba, que lea desde la entrada
estandar casos de prueba, los ejecute, e imprima por la salida estándar el resultado. La entrada
comenzará con el número de casos de prueba. Cada caso consistirá en una línea con el número
n a analizar. El programa escribirá SI si el número n es interesante, o NO en otro caso.
A continuación se muestra un ejemplo de entrada / salida:
Entrada Salida
3
621348
621356
846213
SI
NO
SI
1
*/