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

bool valido(const vector<bool>& cogido , int coger) {
    return !cogido[coger];
}




/*

las ramas que tiene el arbol es el numero de de funcionario que hay, hay justo una cantidad de trabajo 
igual que el numero de funcionario asi que cada uno tendra un trabajo ,

por lo tanto las ramas son los trabajos que hay que es igual a la altura que son el numero de funcionario que hay

buscamos el minimo de tiempo que tarda los funcionarios en terminar el trabajo

podemos saberlo poniendo a cada funcionario un trabajo que no se repita ya y mirando el resultado final
si algun trabajo se repite cortamos la rama 


*/


void permutacion(vector<vector<int>>&dato,vector<int>sol, int k,int& min,int& suma,vector<bool>&cogido) {
    for (int i = 0; i < sol.size(); i++) {
        sol[k] = i;
        suma += dato[k][i];
        if (valido(cogido, i)) {
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
        }
        suma -= dato[k][i];
    }
}



void rellenar(vector<int>& v) {
    for (int& k : v)
        cin >> k;
}

bool resuelveCaso() {

    int entrada;
    cin >> entrada;
    if (entrada==0)
        return false;
    
    vector<vector<int>>dato(entrada, vector<int>(entrada));
    vector<int>sol(entrada);
    for (int i = 0; i < entrada; i++) {
        rellenar(dato[i]);
    }
    vector<bool> cogido(entrada, false);
    // escribir sol
    int suma = 0;
    int min=0;
    for (int i = 0; i < entrada; i++) {
        min += dato[i][i];
    }

    permutacion(dato, sol, 0, min, suma, cogido);
    cout << min << endl;


    return true;
}
