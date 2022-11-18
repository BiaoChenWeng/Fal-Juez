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

vector <int > resolver(const vector<int >& v,int longitud_min) {
    vector<int >sol;
    int longitud=1;
    
    for (int i = 0; i < v.size()-1; i++) {
        if (abs(v[i] - v[i + 1]) < 2) {
            longitud++;
            if (longitud == longitud_min) {
                sol.push_back(i - longitud_min+2);

            }
        }
        else {
            longitud = 1;
        }

    }

    return sol;
}

bool resuelveCaso() {

    int entrada,longitud;
    cin >> entrada;
    cin >> longitud;
    if (longitud==0 && entrada==0)
        return false;

    vector<int >v(entrada);
    vector <int >sol;
    for (int& j : v)
        cin >> j;
    // escribir sol
    sol= resolver(v, longitud);
    cout << sol.size();
    for (int k : sol) {
        cout << " " << k;
    }
    cout << "\n";
    return true;
}

/*
Aterrizaje de emergencia
En la cabina del piloto del Boeing 707 con destino Yakarta una
luz roja se muestra sobre el panel de mandos. El motor derecho ha
explotado y con ´el las posibilidades del avi´on de llegar a su destino.
El piloto y la torre de control del aeropuerto de Yakarta se afanan en
encontrar un lugar donde se pueda aterrizar. El avi´on debe seguir su
rumbo sin desviarse a derecha o izquierda ya que el panel de mandos
est´a da˜nado. Las fotograf´ıas aereas de la zona muestran un par de
claros un poco antes de llegar a una zona con ´arboles. Para poder
aterrizar el avi´on necesita una superficie casi llana de al menos L ≥ 2 metros. La superficie es casi llana
si ning´un punto de ella difiere del siguiente en mas de una unidad.
Debemos buscar todas las superficies que cumplan estas condiciones.
Entrada
La entrada consta de una serie de casos de prueba. Cada caso de prueba tiene dos l´ıneas. En la
primera se indica el n´umero de datos tomados de la imagen a´erea, seguido de la cantidad de valores casi
iguales que necesitan para poder aterrizar (L ≥ 2). En la segunda l´ınea se indican los valores que se han
tomado. La entrada finaliza con dos ceros.
El n´umero de datos de entrada es mayor que cero. Los valores son n´umeros enteros.
Salida
Para cada caso de prueba se escribe en una l´ınea el n´umero de superficies casi llanas que se han
encontrado de una longitud mayor o igual que el valor exigido en la entrada, seguido del comienzo de
cada superficie casi llana mirada desde la parte izquierda del vector y empezando por el valor cero.
Entrada de ejemplo
10 3
5 5 3 4 3 4 7 8 9 3
5 2
5 4 4 5 6
6 3
4 6 8 2 5 9
6 6
3 4 3 2 5 4
0 0
Salida de ejemplo
2 2 6
1 0
0
0
Autor: Isabel Pita

*/