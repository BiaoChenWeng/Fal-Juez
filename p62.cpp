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



bool valido( vector<int >&abrigo,vector<int>& dia, int k, vector<int>& usado, vector<int>& sol,int i) {
    if (k != 0 && sol[k] == sol[k - 1])
        return false;
    else if (abrigo[i] < dia[k])
        return false;
    else {
        return usado[i] <= k / 3 + 2;
    }


}

void permutacion(vector<int>&abrigo,vector<int>& dia,int k,vector<int>&usado,vector<int>&sol,int& contador) {

    for (int i = 0; i < abrigo.size(); i++) {
        sol[k] = i;
        usado[i]++;
        if (valido(abrigo,dia,k,usado,sol,i)) {
            if (k + 1 == dia.size()) {
                if(sol[0]!= sol[k])
                    contador++;
               
            }
            else {
                permutacion(abrigo, dia, k+1, usado, sol, contador);
            }

        }
        usado[i]--;

    }



}


void rellenar(tColor &a) {
    cin >> a.num_total;
    a.num_usado = 0;


}





void rellenar(vector<int>&v) {
    for (int& k : v)
        cin >> k;

}


bool resuelveCaso() {
    int a, n;
    cin >> n;
    cin >> a;
    if (n == 0 )
        return false;
    int contador=0;
    vector<int>dia(n);
    vector<int>abrigo(a);
    vector<int >abrigo_usado(a,0);
    vector<int>sol(n);
    rellenar(dia);
    rellenar(abrigo);


    permutacion(abrigo,dia,0,abrigo_usado,sol,contador);
    if (contador == 0)
        cout << "Lo puedes comprar\n";

    else {
        cout << contador << endl;
    }

    return true;
}
