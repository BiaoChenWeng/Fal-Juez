#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;

bool resuelveCaso();

struct tRendimiento {
    vector<int>dato;
    int mejor_rendido;
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

bool valido(const vector<bool>& cogido , int coger,int mejor_rendimiento,int suma,int min) {
    
    if (mejor_rendimiento + suma > min) {
        return false;
    }
    else {
        return !cogido[coger];
    }
    
}




/*

las ramas que tiene el arbol es el numero de de funcionario que hay, hay justo una cantidad de trabajo 
igual que el numero de funcionario asi que cada uno tendra un trabajo ,

por lo tanto las ramas son los trabajos que hay que es igual a la altura que son el numero de funcionario que hay

buscamos el minimo de tiempo que tarda los funcionarios en terminar el trabajo 



*/


void permutacion(vector<tRendimiento>&dato,vector<int>sol, int k,int& min,int& suma,vector<bool>&cogido) {
    for (int i = 0; i < sol.size(); i++) {
        sol[k] = i;
        
        if (valido(cogido, i,dato[k].mejor_rendido, suma, min)) {
            suma += dato[k].dato[i];
            cogido[i] = true;
            if (k == sol.size() - 1) {
                if (suma < min) {
                    min = suma;
                }
            }
            else {
                permutacion(dato ,sol, k + 1, min, suma,cogido);
            }
            cogido[i] = false;
            suma -= dato[k].dato[i];
        }
        
    }
}



void rellenar(tRendimiento & v) {
    
    cin >> v.mejor_rendido;
    v.dato[0] = v.mejor_rendido;
    for (int i = 1; i < v.dato.size(); i++) {
        cin >> v.dato[i];
        if (v.dato[i] < v.mejor_rendido)
            v.mejor_rendido = v.dato[i];
    }
}

bool resuelveCaso() {

    int entrada;
    cin >> entrada;
    if (entrada==0)
        return false;
    vector<tRendimiento>dato(entrada);
    
    //vector<vector<int>>dato(entrada, vector<int>(entrada));
    vector<int>sol(entrada);
    for (int i = 0; i < entrada; i++) {
        dato[i].dato.resize(entrada);
        rellenar(dato[i]);
    }
    vector<bool> cogido(entrada, false);
    
    int suma = 0;
    int min=0;
    for (int i = entrada-1; i >=0; i--) {
        min += dato[i].dato[i];
        suma += dato[i].mejor_rendido;
        dato[i].mejor_rendido = suma;
    }
    suma = 0;
    permutacion(dato, sol, 0, min, suma, cogido);
    cout << min << endl;


    return true;
}
