#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;

bool resuelveCaso();
struct tColor {
    int num_usado;
    int num_total;
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

bool esValida(string a, string b, vector<tColor>&lista,int i) {
    return !(a == b && a == "verde")&& (lista[0].num_usado >= lista[2].num_usado ) && lista[i].num_usado <= lista[i].num_total;
}


void permutacion(int k, vector<string>& sol, vector<string >& color, vector<tColor>&lista,bool& valido) {


    for (int i = 0; i < color.size(); i++) {
        sol[k] = color[i];
        lista[i].num_usado++;
        if (esValida(sol[k], sol[k - 1],lista,i)) {
            
            if (k == sol.size() - 1) {
                if (lista[1].num_usado > lista[0].num_usado + lista[2].num_usado) {
                    valido = true;
                    for (int j = 0; j < sol.size(); j++) {
                        cout << sol[j] << " ";
                    }
                    cout << endl;
                }
                
            }
            else {
                permutacion(k + 1, sol, color,lista,valido);
            }
            
        }
        lista[i].num_usado--;
    }
}


void rellenar(tColor &a) {
    cin >> a.num_total;
    a.num_usado = 0;


}


bool resuelveCaso() {
    vector<tColor>lista(3);
    int entrada,rojo,verde,azul;
    cin >> entrada;
    for (int i = 0; i < lista.size(); i++)
        rellenar(lista[i]);
    bool valido = false;
    if (entrada == 0 && lista[0].num_total == 0 && lista[1].num_total == 0 && lista[2].num_total == 0)
        return false;

    vector<string >color(3);
    vector<string >sol(entrada);
    
    


    color[0] = "azul";
    color[2] = "verde";
    color[1] = "rojo";
    // escribir sol
    sol[0] = color[1];
    lista[1].num_usado++;
    if (lista[1].num_total != 0) {
        if (sol.size() == 1) {
            valido = true;
            cout << sol[0] << endl;
        }
        else {

            permutacion(1, sol, color, lista, valido);

        }
    }
    if (!valido)
        cout << "SIN SOLUCION\n";


    cout << endl;
    return true;
}
