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

bool contar(const vector<int>& v, int parada, int x) {
    int suma = 0;
    int contador = 0;
    for (int i = 0; i < v.size(); i++) {
        if (suma + v[i] > x) {
            contador++;
            suma = v[i];
        }
        else {
            suma += v[i];
        }


    }

    return contador <= parada;
}


int sol(int ini, int fin, const vector<int>& v, int parada) {
    if (ini == fin) {
        return ini;
    }
    else {
        int m = (fin+ini) / 2;
        
        if (contar(v, parada, m)) {
            return sol(ini, m, v, parada);
        }
        else {
            return sol(m+1, fin, v, parada);
        }
    }
}


bool resuelveCaso() {

    int entrada,descanso;
    cin >> entrada;
    cin >> descanso;
    if (entrada==0 && descanso==0)
        return false;

    vector<int>v(entrada);
    for (int& k : v)
        cin >> k;
    int max = v[0];
    int suma=0;
    for (int i = 0; i < v.size(); i++) {
        suma += v[i];
        if (v[i] > max) {
            max = v[i];
        }
    }

    cout << sol(max, suma, v, descanso)<<endl;


    // escribir sol

    return true;
}
/*
* Viajando con el abuelo
En unos d´ıas comienzan por fin mis vacaciones. Cargar´e las
maletas en el coche y emprender´e un largo viaje para alejarme de
la ciudad e irme al pueblo. Bueno, antes de coger la carretera pasar´e
a buscar a mi abuelo, que se viene conmigo para pasar unos d´ıas
con los pocos amigos de juventud que le quedan vivos.
Aunque me encanta viajar con ´el escuchando todas las historias
que me cuenta tiene una peque˜na pega. El aguante de su vejiga ya
no es el que era y tengo que parar m´as veces de las que parar´ıa si
fuera yo solo. A ´el le preocupa tambi´en bastante el asunto y quiere
saber de antemano cu´anto tiempo tendr´a que esperar como mucho
entre parada y parada, para ver si se viene conmigo o se coge el autob´us.
Yo tengo claro el n´umero m´aximo de descansos que estoy dispuesto a hacer y tengo una estimaci´on
de lo que se tarda en ir desde cada ´area de descanso de la ruta a la siguiente. Ahora tengo que planificar
las paradas para minimizar lo que tiene que aguantarse el abuelo.
Entrada
La entrada est´a compuesta de distintos casos de prueba cada uno ocupando dos l´ıneas.
La primera l´ınea de cada caso contiene dos n´umeros: la cantidad n de tramos en los que est´a dividido
el viaje (1 ≤ n ≤ 100.000) y el n´umero m´aximo de paradas p que estoy dispuesto a hacer antes de llegar
al destino (0 ≤ p ≤ 10.000). La segunda l´ınea contiene n n´umeros con el tiempo necesario para recorrer
cada tramo (un n´umero entre 1 y 10.000).
El primer tramo es el que va desde la casa del abuelo a la primera ´area de descanso, y el ´ultimo el
que va desde la ´ultima ´area de descanso hasta el lugar de destino.
La entrada termina con una linea con dos ceros que no debe ser procesada.
Salida
Por cada caso de prueba se escribir´a una ´unica l´ınea con el tiempo m´aximo que estar´a el abuelo
aguantando, teniendo en cuenta que como mucho haremos p paradas. No quiero hacer sufrir al abuelo
(ni que termine mont´andome un espect´aculo en el coche) por lo que ese tiempo debe ser lo menor posible.
Ten en cuenta que lo ´ultimo que hace el abuelo antes de salir de casa y lo primero que hace al llegar
al destino es ir al ba˜no.
Entrada de ejemplo
2 1
6 4
3 0
3 6 5
3 1
3 6 5
0 0
Salida de ejemplo
6
14
9
Nota
1
Este ejercicio debe verse en el contexto de la asignatura de Fundamentos de Algoritmia (FAL), FDIUCM 2021/2022 (prof. Marco Antonio G´omez Mart´ın). Por tanto no vale cualquier soluci´on, sino s´olo
aquellas que utilicen los conceptos de FAL. Es muy posible que se den aclaraciones adicionales en clase
a este respecto.
2


*/