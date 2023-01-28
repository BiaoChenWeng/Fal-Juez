
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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


void ordenar(vector <int>& v, int medio, int grande,int& comienzo_medio,int& comienzo_grande) {

    int i=0;
    
    while (i <= comienzo_grande) {
        if (v[i] < medio) {
            swap(v[i], v[comienzo_medio]);
            i++;
            comienzo_medio++;
        }
        else if (v[i]<grande) {
            i++;
        }
        else {
            swap(v[i], v[comienzo_grande]);
            comienzo_grande--;
        }

    }

}

void imprimir(const vector<int>& v, int comienzo, int fin) {

    if (fin - comienzo > 0) {
        for (int i = comienzo; i < fin; i++) {
            cout << v[i];
            if (i != fin - 1) {
                cout << " ";
            }
        }
    }
    cout << endl;
}

bool resuelveCaso() {
    int entrada;
    cin >> entrada;
    int medio, grande;
    
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int>v(entrada);
    cin >> medio;
    cin >> grande;
    int c_medio = 0, c_grande = v.size() - 1;
    for (int& k : v) {
        cin >> k;
    }
    ordenar(v, medio, grande, c_medio , c_grande );
    
    //cout << c_medio <<" " << c_grande << endl;
    
    sort(v.begin(), v.end());
   // for (int i : v)
      //  cout << i<<endl;

    imprimir(v, 0, c_medio);
    imprimir(v, c_medio, c_grande+1);
    imprimir(v, c_grande+1, v.size());
    cout << "---\n";
    



    return true;
}

/*
Organizando los pedidos
En una empresa de distribuci´on tienen establecidos tres tama˜nos de paquetes en funci´on del peso del
mismo: peque˜nos, medianos y grandes. Dada una lista de paquetes, se quieren reordenar de forma que
se coloquen en primer lugar todos aquellos env´ıos con poco peso, a continuaci´on todos los env´ıos con
peso intermedio y por ´ultimo todos los env´ıos de mucho peso.
Se pide:
1. Especifica una funci´on que reciba un vector con el peso de cada pedido y modifique el vector para
dejar al principio los paquetes con poco peso, a continuaci´on los paquetes con peso intermedio y por
´ultimo los paquetes con mucho peso. La funci´on devolver´a dos ´ındices indicando d´onde empiezan los
paquetes medianos y d´onde empiezan los paquetes grandes.
2. Implementa la funci´on anterior. El coste de la implementaci´on debe ser lineal en el n´umero de
paquetes.
3. Indica un invariante que permita probar la correcci´on del algoritmo implementado y justifica que
el coste del algoritmo es lineal en el n´umero de paquetes.
Entrada
La entrada consta de una serie de casos de prueba. Cada caso de prueba consta de dos l´ıneas. En
la primera se indica el n´umero n de paquetes, el peso a partir del cual se considera un paquete mediano
y el peso a partir del cual se considera un paquete grande. En la siguiente l´ınea se da el peso de cada
paquete.
El n´umero de paquetes es mayor o igual que 0 y menor que 300.000. Los pesos son n´umeros enteros
positivos que cumplen 0 < peso < 1000. Y los pesos a partir de los cuales se consideran los paquetes
mediano y grande cumplen 0 <= med <= gran <= 1000.
Salida
Para cada caso de prueba se escriben 3 l´ıneas. En la primera l´ınea se indican los pesos de los paquetes
peque˜nos, en la siguiente l´ınea los pesos de los paquetes medianos y en la ´ultima l´ınea los pesos de los
paquetes grandes. Si no existe ning´un paquete de un tipo se dejar´a la l´ınea vac´ıa. Cada caso termina
con una l´ınea con tres guiones.
Entrada de ejemplo
6 6 8
4 5 6 7 8 9
5 50 70
10 20 30 80 90
3 50 50
50 50 50
1
Salida de ejemplo
4 5
6 7
8 9
---
10 20 30
80 90
---
50 50 50
---

*/