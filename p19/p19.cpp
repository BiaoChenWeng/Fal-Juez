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

void max_ganancia(const vector<int >& v, int tiempo) {
    int ganancia=0;
    int ganancia_max;
    int pos=0;

    for (int i = 0; i < tiempo; i++) {
        ganancia += v[i];
    }
    ganancia_max = ganancia;
    for (int j = tiempo; j < v.size(); j++) {
        ganancia += v[j];
        ganancia -= v[j - tiempo];

        if (ganancia >= ganancia_max) {
            ganancia_max = ganancia;
            pos = j - tiempo+1;
        }
    }

    cout << pos << " " << ganancia_max << endl;
}


void resuelveCaso() {
    int tam;
    cin >> tam;
    int tiempo;
    cin >> tiempo;
    vector<int >v(tam);

    for (int& k:v)
        cin >> k;

    max_ganancia(v, tiempo);


}

/*
Asalto al tren
Uno de los robos m´as famosos de todos los tiempos es sin duda el asalto al tren de Glasgow en
1963. Se trataba de un tren correo que viajaba de Glasgow a Londres. En el segundo vag´on de la parte
delantera llevaba paquetes de gran valor...El atraco se produjo entre las estaciones de .... El asalto estuvo
bien planificado, los ladrones conocian los vagones que deb´ıan asaltar para obtener en mejor bot´ın.
En este problema nos invitan a mejorar la estrateg´ıa utilizada por los ladrones. Nos dan la ganancia
que obtendr´ıamos en cada vag´on del tren y el n´umero de vagones que podemos desvalijar antes de llegar a
la pr´oxima estaci´on. Para minimizar el riesgo los vagones que asaltaremos ser´an consecutivos. Tenemos
que encontrar el vag´on por el que debemos empezar el robo para maximizar nuestra ganancia. Ante la
duda (dos posibilidades iguales) elegiremos los vagones m´as cerca a la cola del tren, para estar lo m´as
alejados posible de los maquinistas.
Requisitos de implementaci´on.
Indicar el coste de la soluci´on obtenida.
La funci´on que resuelve el problema debe recibir los datos en un vector y devolver el vag´on que
debemos asaltar en primer lugar, suponiendo que luego nos desplazaremos hacia la parte posterior del
tren.
Entrada
La entrada comienza con el n´umero de casos de prueba. Cada caso de prueba tiene dos l´ıneas. En la
primera se indica el n´umero de vagones del tren, seguido del n´umero de vagones que tendremos tiempo
de asaltar. En la segunda se indica la ganacia que podemos sacar de cada uno de los vagones. El primer
n´umero indica el vag´on m´as cercano a la cabecera del tren.
El n´umero de vagones que nos dar´a tiempo a asaltar es menor o igual que los vagones totales del
tren. El tren siempre tiene al menos un vag´on.
Salida
Para cada caso de prueba se escriben en una l´ınea el vag´on en el que debemos empezar el asalto
contado desde la cabecera del tren, seguido de la ganancia que esperamos obtener. El primer vag´on es
el cero. En caso de existir dos posibilidades que nos reporten el mismo beneficio, elegiremos la que se
encuentre m´as lejos de la cabecera del tren.
Entrada de ejemplo
4
10 3
3 6 4 7 1 8 7 2 8 3
7 4
1 3 2 2 3 2 1
6 3
2 2 2 2 2 2
4 2
9 8 3 4
Salida de ejemplo
6 17
1 10
3 6
0 17
Autor: Isabel Pita.
1*/