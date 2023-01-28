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


int tachar(vector<int >const& v,int x, int ini, int fin) {
    if (ini == fin)
        return v.size();
    else if (ini + 1 == fin) {
        return ini;
    }

    else {
        int m = (ini + fin-1) / 2;
        if (v[m] < x + m) {
            return tachar(v, x, m+1, fin);
        }
        else  {
            return tachar(v, x, ini, m+1);
        }
        

    }

}

// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int entrada,valor;
    cin >> entrada;
    cin >> valor;

    vector<int >v(entrada);
    for (int& k : v) {
        cin >> k;
    }
    int pos = tachar(v,valor, 0, v.size());

    if (pos+valor!=v[pos]) {
        cout << "No\n";
    }
    else {
        cout << v[pos] << endl;
    }

}
/*
El juego del bongo
En la residencia de mis t´ıos, se ha puesto de moda un nuevo juego
al que llaman el bongo. Cansados de tachar el n´umero que cantaba el
cajero sobre su tarjeta de bingo, los ancianos han optado por tachar
el n´umero del cart´on que coincida con el n´umero cantado por el cajero
mas su posici´on en el cart´on (la primera posici´on del cart´on es la cero).
De esta forma ejercitan su capacidad de c´alculo.
Asi, por ejemplo, si en el cart´on est´an los n´umeros 2 4 7 9 12 15
22 y el n´umero cantado es el 6, al anciano tachar´a el n´umero 9, ya
que su posici´on, la 3, m´as el n´umero cantado coinciden con el valor.
Si no encuentra ning´un n´umero que le coincida no tachar´a ninguno y
esperar´a al siguiente n´umero. Utilizan ´unicamente cartones con los n´umeros ordenados de forma creciente
y para evitar que una persona pueda tachar dos n´umeros en una tirada, los cartones no tienen ninguna
pareja de n´umeros consecutivos.
Hoy he estado jugando con ellos, pero me falta pr´actica y perd´ıa algunos n´umeros. He decidido hacer
un programa que dados los valores del cart´on y el n´umero que canta el cajero me ense˜ne el n´umero que
debo tachar o si no debo hacer nada, para poder estar a su nivel la pr´oxima vez que juegue.
Requisitos de implementaci´on.
Indicar el coste de la soluci´on obtenida.
La funci´on que resuelve el problema debe ser recursiva.
Entrada
La entrada comienza con el n´umero de casos de prueba. Cada caso de prueba tiene dos l´ıneas. En la
primera se indica la cantidad de n´umeros que hay en el cart´on y el n´umero cantado por el cajero. En la
segunda l´ınea se indican los valores del cart´on separados por blancos.
Los cartones tienen al menos un elemento.
Salida
Para cada caso de prueba se escriben en una l´ınea el n´umero que se debe tachar o la palabra NO si
no hay ninguno en su sitio.
Entrada de ejemplo
4
7 8
3 6 8 11 14 17 20
6 2
0 3 5 7 9 11
4 5
0 4 7 12
5 4
1 3 7 9 12
Salida de ejemplo
11
3
7
NO
Autor: Isabel Pita.
1*/