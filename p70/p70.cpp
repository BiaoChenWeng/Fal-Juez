
#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
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

//first coste
// second superficie
class comparador {
public: 
    bool operator()(pair<int, int>p1, pair<int, int>p2) {
        return (float)p1.second / p1.first > (float)p2.second / p2.first;
    }

};
int calcular_valor_inicial(const vector<pair<int, int>>& datos, const int k, const int precio_max) {
    int i = k;
    int precio_actual = 0;
    int superficie_max = 0;
    while (i < datos.size() && datos[i].first + precio_actual <= precio_max) {

        superficie_max += datos[i].second;
        precio_actual += datos[i].first;

        i++;
    }
    return superficie_max;
}

int calcular_estimacion(const vector<pair<int, int>>& datos,const int k,const int precio_max) {
    int i = k;
    int precio_actual=0;
    int superficie_max = 0;
    while (i < datos.size() && datos[i].first + precio_actual<=precio_max) {

        superficie_max += datos[i].second;
        precio_actual += datos[i].first;
        
        i++;
    }
    if (i<datos.size() && precio_actual != precio_max) {
        superficie_max += (precio_max-precio_actual) * ((float)datos[i].second / datos[i].first);
    }
    return superficie_max;
}


void navidad(vector<pair<int, int >>& datos, const int& precio_max, int& precio_actual, int& superficie_actual, int k, vector<bool>&sol,int & superficie_max) {

    sol[k] = true;
    if (precio_actual + datos[k].first <= precio_max) {
        precio_actual += datos[k].first;
        superficie_actual += datos[k].second;
        if (k == sol.size() - 1) {
            if (superficie_actual > superficie_max) {
                superficie_max = superficie_actual;
   
            }
        }
        else {
            navidad(datos, precio_max, precio_actual, superficie_actual, k + 1, sol,superficie_max);
        }
        precio_actual -= datos[k].first;
        superficie_actual -= datos[k].second;
    }



    sol[k] = false;
   
    if (k == sol.size() - 1) {
        if (superficie_actual > superficie_max) {
            superficie_max = superficie_actual;
    
       
        }
    }
    else {
        
        if (calcular_estimacion(datos, k + 1, precio_max - precio_actual)+superficie_actual > superficie_max) {
            navidad(datos, precio_max, precio_actual, superficie_actual, k + 1, sol, superficie_max);
        }

    }


}



bool resuelveCaso() {
    int entrada;
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;
    int precio_max;
    cin >> precio_max;
    int max_superficie;
    vector<bool>sol(entrada,false);
    vector<pair<int, int>>datos(entrada);
    for (int i = 0; i < entrada; i++) {
        cin >> datos[i].first;
        cin >> datos[i].second;
    }
    int precio_actual = 0;
    int superficie_actual = 0;
    int superficie_max = 0;
    sort(datos.begin(), datos.end(), comparador());
    superficie_max = calcular_valor_inicial(datos,0,precio_max);
    navidad(datos, precio_max, precio_actual, superficie_actual, 0, sol, superficie_max);
   
    cout << superficie_max<<endl;

    return true;
}

