
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

bool sol(vector<int >const& v, int valor,int ini,int fin) {
    
    if (ini + 1 == fin)
        return true;

    else if(ini+2==fin) {

        return abs(v[ini] - v[fin - 1])>=valor;
    }
    else {
        int m = (ini + fin) / 2;

        return abs(v[ini] - v[fin - 1])>=valor && sol(v, valor, ini, m) && sol(v, valor, m, fin);
    }
}


bool resuelveCaso() {
    int entrada, valor;
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> valor;

    vector<int>v(entrada);
    for (int& k : v)
        cin >> k;

    if (sol(v, valor, 0, v.size())) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }

    return true;
}

/*
El due˜no del casino est´a muy preocupado por que los jugadores de
ruleta puedan llegar a detectar que el crupier controla el n´umero que
saca en cada tirada. Todas las noches estudia la lista de n´umeros que
han salido ese d´ıa y comprueba que sean suficientemente dispersos.
El due˜no se conforma con que la diferencia entre el primer valor
que se saca y el ´ultimo sea mayor o igual que una cantidad K. Adem´as
comprueba que los datos que salieron en la primera mitad de la noche
y los datos que salieron en la segunda mitad sean tambien suficientemente dispersos, esto es que la diferencia entre el primer valor y
el ´ultimo tanto de la primera mitad como de la segunda sea mayor
que K y adem´as cada una de sus mitades sea tambi´en suficientemente
dispersa.
Estudia ´unicamente secuencias con un n´umero de elementos que sea potencia de dos para poder
dividirlas siempre en dos partes iguales. Considera que un s´olo valor siempre es suficientemente disperso.
Entrada
La entrada consta de una serie de casos de prueba. Cada caso de prueba consta de dos l´ıneas. En la
primera se muestra el n´umero de tiradas que se considera y el valor de dispersi´on que se precisa. En la
segunda se muestran los n´umeros que han salido en cada tirada
El n´umero de valores de cada caso de prueba es una potencia de 2. El valor de dispersi´on es un entero
positivo mayor que cero. Los valores de cada tirada son n´umeros entre 0 <= N <= 1.048.576
Salida
Para cada caso de prueba se escribe en una l´ınea SI si el vector est´a suficientemente disperso y NO
si no lo est´a.
Entrada de ejemplo
4 3
6 1 3 9
4 3
3 10 12 14
8 4
20 2 0 4 14 8 5 10
Salida de ejemplo
SI
NO
SI
*/