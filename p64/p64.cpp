
#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;

bool resuelveCaso();

struct tNino {
    vector<int>interes;
    
};


struct tDatos {
    int intereses;
    vector<int>num_jug;
    vector<string>jug;
    vector<tNino>nino;
};

struct tSol {
    vector<int >sol;
    int satisfacion;
    bool solucion;
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

void rellenar(vector<int>& v) {
    for (int& k : v)
        cin >> k;
}

void escribir(vector<int>& sol) {
    for (int k : sol)
        cout << k << " ";
    cout << endl;
}

bool valido(const tDatos& datos,const  tSol& sol, int pos) {
    
    if (datos.num_jug[sol.sol[pos]] <= 0) {
        return false;
    }
    else if (pos%2==1 && sol.sol[pos] <= sol.sol[pos - 1]) {
        return false;
    }
    else if (pos % 2 == 1 && datos.jug[sol.sol[pos-1]] == datos.jug[sol.sol[pos]])
        return false;
    else if (pos % 2 == 1&&datos.nino[pos/2].interes[sol.sol[pos]]+ datos.nino[pos / 2].interes[sol.sol[pos-1]]<datos.intereses) {
        return false;
    }
    else
        return true;
}

void permutacion(tDatos& datos,tSol& sol,int k) {

    for (int i = 0; i < datos.jug.size(); i++) {
        sol.sol[k] = i;
        
        if (valido(datos, sol, k)) {
            datos.num_jug[i]--;
            if (k == sol.sol.size() - 1) {
                escribir(sol.sol);
                sol.solucion = true;

            }
            else {
                permutacion(datos, sol, k + 1);
            }
            datos.num_jug[i]++;
        }
        
    }




}


bool resuelveCaso() {
    int entrada;
    tDatos datos;
    tSol sol;
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;

    int nino;
    int satisfacion;
    cin >> nino;
    cin >> satisfacion;
    
    sol.solucion = false;
    sol.sol.resize(nino * 2);

    datos.intereses = satisfacion;
    datos.jug.resize(entrada);
    datos.num_jug.resize(entrada);
    datos.nino.resize(nino);
    for (int i = 0; i < datos.nino.size(); i++)
        datos.nino[i].interes.resize(entrada);
    
    rellenar(datos.num_jug);


    for (string& k : datos.jug)
        cin >> k;
    for (int i = 0; i < nino; i++)
        rellenar(datos.nino[i].interes);


    permutacion(datos, sol, 0);
    if (!sol.solucion)
        cout << "SIN SOLUCION\n";
    cout << endl;


    return true;
}

