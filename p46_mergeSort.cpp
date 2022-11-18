
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


int mergeSort(vector<int>&v,int ini,int fin) {
    if (ini == fin || ini+1==fin) {
        return 0;

    }

    else {
        vector<int >aux;
        int suma = 0;
        int m = (ini + fin) / 2;
        suma+=mergeSort(v, ini, m);
        suma+=mergeSort(v, m, fin);
        int i = ini;
        int j = m;
        while (i < m && j < fin) {
            if (v[i] > v[j]) {
                suma += m - i;
                
                aux.push_back(v[j]);
                j++;
            }
            else {
                aux.push_back(v[i]);
                i++;
                
            }

        }
        if (j < fin) {
            for (int k = j; k < fin; k++) {
                aux.push_back(v[k]);
            }
        }
        else {
            for (int k = i; k < m; k++) {
                aux.push_back(v[k]);
            }
        }

        for (int k = 0; k < aux.size(); k ++) {
            v[ini + k] = aux[k];
        }
        return suma;
    }
}



bool resuelveCaso() {
    int entrada;
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<int>v(entrada);

    for (int& k : v) {
        cin >> k;
    }
    
    cout << mergeSort(v, 0, v.size())<<endl;
    return true;
}

/*
En un lejano lugar del universo, los Cylon han lanzado un ataque imprevisto contra las doce colonias
de Kobol. Todo lo que queda de la humanidad es una nave de combate la Battlestar Galactica junto con
un grupo de naves espaciales civiles. Juntos emprenden un viaje en busca de la decimotercera colonia:
la Tierra, cuya ubicaci´on es desconocida. El comandante Adama dirige la expedici´on desde la nave de
combate y el resto de las naves se sit´uan en l´ınea detr´as de la nave principal. El orden en que lo hacen
es importante para poder defenderse mejor de los continuos ataques de los Cylon.
Despu´es del ´ultimo ataque las naves han quedado desordenadas y es preciso que recuperen el orden
correcto. Sin embargo, el comandante sabe que los Cylon preparan un nuevo ataque para dentro de
T unidades de tiempo. Si intercambiar el lugar de dos naves consecutivas lleva una unidad de tiempo,
calcula si ser´a posible restructurar la fila antes del ataque, en caso contrario, los pilotos Apolo y Starbuck
tendr´an que realizar una salida contra los Cylon para intentar retrasar el ataque.
Requisitos de implementaci´on.
El problema se debe resolver de forma recursiva. Indicar el coste obtenido y la recurrencia .
La funci´on que resuelve el problema debe recibir los datos en un vector y devolver el n´umero de
unidades de tiempo necesarias para reestructurar la fila de naves.
Entrada
La entrada consta de una serie de casos de prueba. Cada caso consta de dos l´ıneas, en la primera
se indica el n´umero de naves que viajan bajo la protecci´on de la Battlestar Galactica. En la segunda
l´ınea se da la posici´on en que ha quedado cada nave despu´es del ataque de los Cylon. Por ejemplo, si
la entrada es 5 2 1 3 4, esto significa que la nave 5 (la que deber´ıa viajar en quinto lugar) est´a ahora
en primera posici´on, la nave que deber´ıa estar en la segunda posici´on esta bien colocada, la nave 1, que
deber´ıa estar en la primera posici´on, ocupa la tercera, y las naves que deber´ıan estar en tercera y cuarta
posici´on, han quedado en las posiciones 4 y 5.
Salida
Para cada caso de prueba se escribe en una l´ınea el n´umero de unidades de tiempo necesarias para
reestructurar la fila.
Entrada de ejemplo
3
3 2 1
6
4 3 2 1 6 5
Salida de ejemplo
3
7

*/