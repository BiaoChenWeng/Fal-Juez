#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;
void resuelveCaso();

void mostrarSol(int max, vector<int >& sol);

struct tDatos {
    vector<vector<bool>>datos;
    vector<int>gusto;
    
    vector<int>cogido;
};


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

bool valido(tDatos& dato,int elec,int dia) {
    if (dato.cogido[elec]!=-3) {
        return false;
    }
    int i = 0;
    
    while (i<dato.datos.size()) {
        if (dato.datos[elec][i]) {
            if (dia - dato.cogido[i] < 3)
                return false;
        }
        i++;
    }
    return true;

}
void elegir_ruta(tDatos& dato, int k,vector<int>&sol,vector<int >&best_sol,int &suma_actual,int& suma_max,int &forma) {
    for (int i = 0; i < dato.datos.size(); i++) {
        sol[k] = i;
        suma_actual += dato.gusto[i];
        if (valido(dato,i,k)) {
            dato.cogido[i] = k;
            if (k== sol.size() - 1 ) {
                if (suma_actual > suma_max) {
                    suma_max = suma_actual;
                    best_sol = sol;
                    forma = 1;
                   // mostrarSol(suma_max, sol);
                }
                else if(suma_actual== suma_max) {
                    forma++;
                    bool cambiar = false;
                    bool fin = false;
                    int m = 0;                   
                    while (!fin && m < sol.size()) {
                        if (best_sol[m] == sol[m]){
                            m++;
                        }
                        else {
                            fin = true;
                            cambiar = (best_sol[m] > sol[m]);
                        }
                    }
                    if (cambiar) 
                        best_sol = sol;                   
                   // mostrarSol(suma_max, sol);
                }
            }
            else {
              
                elegir_ruta(dato, k + 1, sol, best_sol, suma_actual, suma_max,forma);
               
            }
            dato.cogido[i] = -3;
        }
        
        
        suma_actual -= dato.gusto[i];
    }
}

void mostrarSol(int max,vector<int >&sol) {
    cout << max << " ";
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    cout << endl;
}

//
//la matriz te dice que la ruta de la col x se cruza con la ruta de
//fila y si tiene un 1 en v[y][x]

void resuelveCaso() {
    
    
    int rutas;
    int dias;
    cin >> rutas;
    cin >> dias;
    tDatos dato;
    dato.datos.resize(rutas);
    for (int i = 0; i < rutas; i++){
        dato.datos[i].resize(rutas);
    }
    int entrada;

    for (int i = 0; i < rutas; i++) {
        for (int j = 0; j < rutas; j++) {
            cin >> entrada;
            if (entrada == 1) {
                dato.datos[i][j] = true;
            }
            else {
                dato.datos[i][j] = false;
            }
        }
    }
    dato.gusto.resize(rutas);
    dato.cogido.resize(rutas,-3);
    for (int i = 0; i < rutas; i++) {
        cin >> dato.gusto[i];
    }
    
    vector<int>sol(dias);
    vector<int >best_sol(dias, rutas);
    vector<int>ultimo_uso(rutas,-3);
    int forma=0;
    int suma_actual = 0;
    int suma_max = -1;
    
   // vector<vector<int>>mapa(rutas,vector<int>(rutas,-3));


    elegir_ruta(dato, 0, sol, best_sol, suma_actual, suma_max,forma);
    if (suma_max == -1) {
        cout << "IMPOSIBLE\n";
    }
    else {
        mostrarSol(suma_max, best_sol);
        //cout << forma << "\n------------------------------\n";

    }
}
