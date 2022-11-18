
#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;
bool resuelveCaso();
vector<int> resolver(const vector<int>& v, int longitud, int& max);
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


vector<int> resolver(const vector<int>& v, int longitud, int &max) {
    int i = v.size() - 1;
    vector <int > sol;
    int largo=1;
    int max_valor=v[v.size()-1];

    for (int i = v.size() - 1; i > 0; i--) {
        if (v[i] >= max_valor) {
            if (max_valor < v[i])
                max_valor = v[i];
            if (v[i] == v[i - 1]) {
                largo++;

                if (largo >= longitud) {
                    if (largo > max) {
                        max = largo;
                    }
                    if (largo == longitud) {
                        sol.push_back(i + longitud - 2);
                    }


                }
            
            
            
            }
            else {
                largo = 1;
            }
        }
        else {
            largo = 1;
        }

    }

    /*

    while (i>0) {
        if (v[i] == v[i - 1]) {
            
            if (v[i] >= max_valor) {
                if (max_valor < v[i])
                    max_valor = v[i];
                largo++;
                
                if (largo >= longitud) {
                    if (largo > max) {
                    max = largo;
                    }
                    if (largo == longitud) {
                        sol.push_back(i + longitud-2);
                    }
                                        
                    
                }
                
            }
            
        }
        else {
            largo = 1;
        }
        
        i--;
        
        
    }

    */


    return sol;

}


bool resuelveCaso() {
    int entrada;
    int longitud;
    int max_long = 0;
    cin >> entrada;
    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;
    cin >> longitud;
    vector<int >sol;
    vector<int> v(entrada);
    for (int& j : v)
        cin >> j;
    sol = resolver(v,longitud,max_long);

    cout << max_long<<" "<<sol.size();
    for (int k : sol)
        cout << " " << k ;

    cout << "\n";

    return true;
}

/*
La caba˜na del abuelo de Heidi est´a situada en los alpes suizos,
sobre la aldea de Maienfeld. La caba˜na est´a construida en un peque˜no
llano en la ladera de la monta˜na, rodeada en su parte trasera por tres
enormes abetos, y con una preciosa vista sobre el valle desde su parte
delantera.
Heidi est´a buscando un lugar donde construir otra caba˜na en el
camino hasta las cumbres. Para ello necesita localizar terrenos que
tengan una superficie llana suficiente para construir, una vista tan
buena como la de la caba˜na de su abuelo y que est´en cerca del camino.
Hoy ha ido con Pedro a recolectar los datos. Entre todos los valores que han recogido, ahora deben
buscar aquella secuencia que tenga al menos l > 1 valores consecutivos iguales, y que sean mayores o
iguales que todos los valores de su derecha, para que tenga buenas vistas.
Requisitos de implementaci´on.
Implementar una funci´on que reciba en un vector los datos, y devuelva en un vector diferente del de
entrada los puntos donde empiezan los espacios apropiados para construir mirados desde la derecha del
vector. La implementaci´on de la funci´on debe tratar cada dato una ´unica vez.
La funci´on debe devolver tambi´en la longitud de la secuencia mas larga de valores iguales y que
cumpla las condiciones para construir la casa que se haya encontrado.
Entrada
La entrada consta de una serie de casos de prueba. Cada caso de prueba tiene dos l´ıneas. En la
primera se indica el n´umero de datos tomados por Heidi y Pedro seguido de la cantidad de valores
iguales que necesitan para poder construir (l > 1). En la segunda se indican los valores que han tomado.
Salida
Para cada caso de prueba se escribe en una l´ınea la longitud de la secuencia m´as larga, seguido del
n´umero de llanos encontrados, seguido del comienzo de cada llano mirado desde la parte derecha del
vector.
Tal como est´a dados los datos, los llanos que aparecen en el listado de salida est´an dados desde la
derecha del vector, primero las posiciones m´as altas (valores mas bajos).
Entrada de ejemplo
10 3
3 8 8 8 5 5 6 6 6 1
3 3
4 4 4
11 2
9 9 9 2 1 2 2 4 4 1 2
6 3
4 4 8 6 6 2
Salida de ejemplo
3 2 8 3
3 1 2
3 2 8 2
0 0

*/