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

int resolver(const vector<int >& v,int tiempo) {

    int suma=0;
    int suma_max ;
    int pos=0;
    for (int i = 0; i < tiempo; i++) {
        suma += v[i];
    }
    suma_max = suma;

    for (int i = tiempo; i < v.size(); i++) {
        suma += v[i];
        suma -= v[i - tiempo];

        if (suma_max <= suma) {
            suma_max = suma;
            pos = i - tiempo + 1;
        }

    }


    return pos;
}

bool resuelveCaso() {

    int entrada,tiempo;
    cin >> entrada;
    cin >> tiempo;
    if (tiempo==0 && entrada==0)
        return false;

    vector<int >v(entrada);

    for (int& j : v)
        cin >> j;
    // escribir sol
    cout << resolver(v, tiempo)<<endl;
    return true;
}



/*
Releyendo un libro. Versi´on 1
Cuando tengo un rato libre me gusta coger un libro y releer alguna
de las partes que m´as me gustaron cuando lo le´ı por primera vez.
Normalmente, mientras voy leyendo doy una puntuaci´on entre 0 y
10 a cada p´agina, de forma que cuando quiero volver a leerlo se que
p´aginas me gustaron m´as. Cero significa que no tengo inter´es en volver
a leer esa p´agina, mientras que un 10 indica que es una de las mejores
partes de la obra. Una vez que empiezo a leer en una p´agina, continuo
con las p´aginas siguientes sin saltarme ninguna.
Para asegurarme de que leo la mejor parte he aprendido a estimar
el n´umero de p´aginas que me dar´a tiempo a leer en el rato que tengo.
Siempre busco que las p´aginas sean lo m´as interesantes posible. El inter´es de varias p´aginas se calcula
como la suma del inter´es de cada p´agina. Si hay varios intervalos igual de interesantes elijo el que est´e
m´as avanzado en el libro. Recuerda que las p´aginas que leo son siempre consecutivas.
Requisitos de implementaci´on.
La funci´on que resuelve el problema debe tener un coste lineal respecto al n´umero de p´aginas del libro.
Puede implementarse m´as de un bucle, siempre que el coste sea lineal respecto al n´umero de p´aginas del
libro.
Entrada
La entrada consta de una serie de casos de prueba. Cada caso de prueba tiene dos l´ıneas. En la
primera se indica el n´umero de p´aginas del libro (1 < n < 200.000), seguido de la cantidad de p´aginas
que me dar´a tiempo a leer (1 < L < n). En la segunda l´ınea se indica la puntuaci´on que he dado a cada
p´agina del libro (0 <= p <= 10). La entrada finaliza con dos ceros.
Salida
Para cada caso de prueba se escribe la p´agina en que debo empezar a leer el libro para que al leer L
p´aginas empezando en ella, lea siempre las p´aginas m´as interesantes. Si existen dos bloques de p´aginas
cuya suma de puntuaciones es igual, elegir´e la que se encuentre m´as avanzada en el libro.
Entrada de ejemplo
6 3
0 5 3 4 1 2
7 2
6 4 5 6 0 0 8
5 4
7 7 7 7 7
6 2
5 6 7 6 7 5
0 0
Salida de ejemplo
1
2
1
3
Autor: Isabel Pita
1

*/