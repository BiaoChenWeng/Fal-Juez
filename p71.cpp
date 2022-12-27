#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
// Introduce más librerías si son necesarias
using namespace std;

bool resuelveCaso();
//first duracion
// second gustar
class comparador {
public:
    bool operator()(pair<int, int>p1, pair<int, int>p2) {
        return (float)p1.second / p1.first > (float)p2.second / p2.first;
    }

};

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



int calcular_estimacion(int duracion,const vector<pair<int, int>>& canciones,int k,bool& posible) {
    if (duracion == 25) {
        int a = 0;
    }
    int duracion_actual = 0;
    int i = k+1;
    int sastifacion = 0;
    while (i < canciones.size() && duracion_actual + canciones[i].first <= duracion) {
        
        duracion_actual += canciones[i].first;
        sastifacion += canciones[i].second;
        i++;

    }
    if (i < canciones.size() && duracion_actual!= duracion) {
        sastifacion+= (duracion - duracion_actual) * ((float)canciones[i].second / canciones[i].first);
        duracion_actual = duracion;
    }
    if (duracion_actual < duracion) {
        posible = false;
    }
    return sastifacion;
}


void elegirMusica(const vector<pair<int, int>>&canciones,int k,vector<bool>&sol,const pair<int ,int >&duracion_viaje,int& max_sastifacion,int& sastifacion_actual,pair<int,int>& duracion_viaje_actual,bool& sol_encontrado) {
    
    sol[k] = true;
    
    if (canciones[k].first + duracion_viaje_actual.first<= duracion_viaje.first) {
        duracion_viaje_actual.first += canciones[k].first;
        sastifacion_actual += canciones[k].second;
        if (k == sol.size() - 1) {
            if (duracion_viaje_actual.first==duracion_viaje.first && duracion_viaje.second== duracion_viaje_actual.second){
                if (max_sastifacion < sastifacion_actual) {
                    max_sastifacion = sastifacion_actual;
                    sol_encontrado = true;
                   
                }

            }
        
        }
        else {
            elegirMusica(canciones, k + 1, sol, duracion_viaje, max_sastifacion, sastifacion_actual, duracion_viaje_actual,sol_encontrado);
        }
        duracion_viaje_actual.first -= canciones[k].first;
        sastifacion_actual -= canciones[k].second;
    }
    if (k == 1)
        int a = 0;
    if (canciones[k].first + duracion_viaje_actual.second <= duracion_viaje.second) {
        duracion_viaje_actual.second += canciones[k].first;
        sastifacion_actual += canciones[k].second;
        if (k == sol.size() - 1) {
            if (duracion_viaje_actual.first == duracion_viaje.first && duracion_viaje.second == duracion_viaje_actual.second) {
                if (max_sastifacion < sastifacion_actual) {
                    max_sastifacion = sastifacion_actual;
                   
                    sol_encontrado = true;
                }
            }
 
        }
        else {
            elegirMusica(canciones, k + 1, sol, duracion_viaje, max_sastifacion, sastifacion_actual, duracion_viaje_actual, sol_encontrado);
        }
        duracion_viaje_actual.second -= canciones[k].first;
        sastifacion_actual -= canciones[k].second;
    }
    sol[k] = false;

    if (k == sol.size() - 1) {
        if (duracion_viaje_actual.first == duracion_viaje.first && duracion_viaje.second == duracion_viaje_actual.second) {
            if (max_sastifacion < sastifacion_actual) {
                max_sastifacion = sastifacion_actual;
           
                sol_encontrado = true;
            }
        }
    }
    else {
        bool posible=true;
        if (calcular_estimacion(duracion_viaje.first+duracion_viaje.second-(duracion_viaje_actual.first + duracion_viaje_actual.second), canciones, k, posible) + sastifacion_actual> max_sastifacion && posible) {
            elegirMusica(canciones, k + 1, sol, duracion_viaje, max_sastifacion, sastifacion_actual, duracion_viaje_actual,sol_encontrado);
        }

    }


}


bool resuelveCaso() {

    int entrada;
    cin >> entrada;
    if (entrada==0)
        return false;

    pair<int, int> duracion_viaje;
    int max_sastifacion=0;
    cin >> duracion_viaje.first;
    cin >> duracion_viaje.second;
    vector<pair<int, int>>canciones(entrada);
    for (int i = 0; i < entrada; i++) {
        cin >> canciones[i].first;
        cin >> canciones[i].second;
    }

    sort(canciones.begin(), canciones.end(), comparador());
    
    vector<bool> sol(entrada, false);
    
 //   max_sastifacion += inicializar(sol, duracion_viaje.first, canciones);
    max_sastifacion = 0;
    for (int i = 0; i < sol.size(); i++) {
        sol[i] = false;
    }
    int sastifacio_actual=0;
    pair<int, int>duracion_viaje_actual;
    duracion_viaje_actual.first = 0;
    duracion_viaje_actual.second = 0;
    bool encontrado = false;
    elegirMusica(canciones, 0, sol, duracion_viaje, max_sastifacion, sastifacio_actual,duracion_viaje_actual,encontrado);
    if(encontrado)
        cout << max_sastifacion << endl;
    else {
        cout << "Imposible\n";
    }
    return true;
}
