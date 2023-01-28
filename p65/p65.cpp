
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


void rellenar(vector<int>&v) {
    for (int& k : v)
        cin >> k;
}

bool valido(vector<bool>& cogido,int elemento,int nino,vector<int>&pred,int& suma,int& max) {
    if (suma + pred[nino+1] < max) {
        return false;
    }
    
    return !cogido[elemento];
}

void permutacion(const int &m,const int &n,const vector<vector<int>>&datos,int k,int &max,int &suma,vector<bool>&cogido, vector<int>&pred,vector<int>&sol) {

    for (int i = 0; i < m; i++) {
        sol[k] = i;
        suma += datos[k][i];
        if (valido(cogido,i,k,pred,suma,max)) {
            cogido[i] = true;
            if (k == n - 1) {
                if (suma > max) {
                    max = suma;
                }
            }
            else {
                permutacion(m, n, datos, k + 1, max, suma, cogido, pred, sol);
            }
            cogido[i] = false;
        }
        suma -= datos[k][i];

    }


}




bool resuelveCaso() {
    int entrada;
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;
    int num_nino;
    cin >> num_nino;
    vector<vector<int>>datos(num_nino,vector<int>(entrada));

    for (int i = 0; i < num_nino; i++)
        rellenar(datos[i]);

    int max=0;
    int suma=0;
    vector<int>pred(num_nino+1);
    vector<bool>cogido(entrada,false);
    vector<int>sol(num_nino);
    pred[num_nino] = 0;
    for (int i = num_nino-1; i >= 0; i--) {
        pred[i] = datos[i][entrada-1];
        for(int j=entrada-1;j>=0;j--){
            if (pred[i] < datos[i][j])
                pred[i] = datos[i][j];

        }
        suma += pred[i];
        pred[i] = suma;
    }
    suma = 0;
    for (int i = 0; i < num_nino; i++) {
        max += datos[i][i];
    }

    permutacion(entrada, num_nino, datos, 0, max, suma, cogido, pred, sol);
    cout << max<<endl;

    return true;
}

