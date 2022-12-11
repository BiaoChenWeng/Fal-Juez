
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

void escribir(vector<int>& sol) {
    for (int k : sol)
        cout << k << " ";
    cout << endl;
}

bool valido(const vector<string>& jug,const vector<int>& sol ,int pos ) {
    if (pos%2==1 && sol[pos] <= sol[pos - 1]) {
        return false;
    }
    else if (pos % 2 == 1 && jug[sol[pos-1]] == jug[sol[pos]])
        return false;

    else
        return true;
}

void permutacion(const vector<string>& jug,vector<int>& sol,int k,bool & solucion) {

    for (int i = 0; i < jug.size(); i++){
        sol[k] = i;
        if (valido(jug, sol, k)) {

            if (k == sol.size() - 1) {
                escribir(sol);
                solucion = true;

            }
            else {
                permutacion(jug, sol, k + 1,solucion);
            }
        }

    }




}


bool resuelveCaso() {
    int entrada;
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;

    int nino;
    cin >> nino;
    bool solucion = false;
    vector<int>sol(nino * 2);
    vector<string >jug(entrada);

    for (string& k : jug)
        cin >> k;

    permutacion(jug, sol, 0,solucion);
    if (!solucion)
        cout << "SIN SOLUCION\n";
    cout << endl;


    return true;
}

