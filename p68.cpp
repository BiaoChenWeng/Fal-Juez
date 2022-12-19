#include <iostream>
#include <fstream>
#include <vector>
//#include <chrono>


// Introduce más librerías si son necesarias
using namespace std;
//using namespace std::chrono;
using tModelo = pair<int, int>;


void resuelveCaso();

using tPrenda = vector<vector<int>>;


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


void rellenar(tPrenda& v, int entrada, vector<int>& aux) {
    v.resize(entrada);

    for (int i = 0; i < entrada; i++) {
        v[i].resize(entrada);
        cin >> v[i][0];
        aux[i] = v[i][0];
        for (int j = 1; j < entrada; j++) {
            cin >> v[i][j];
            if (aux[i] < v[i][j]) {
                aux[i] = v[i][j];
            }

        }
    }



}




bool valido_traje(const vector<bool>& cogido,int& elegido, const int& bestShoes,const int& valor_traje,int& max,int& suma,int& pred) {

    if ((valor_traje * bestShoes) + suma+pred<=max) {
        return false;
    }

    return !cogido[elegido];
}

bool valido_zap(const vector<bool>& cogido,int elegido,int suma, int max,const int& pred) {
    if (suma + pred <= max) {
        return false;
    }

    return !cogido[elegido];
}

void permutacion(const tPrenda& traje, const tPrenda& zap, vector<tModelo>sol , int k, vector<vector<bool> >& cogido, int& suma, int& max,  vector<int>& pred, const vector<int>& bestShoes) {
    for (int i = 0; i < sol.size(); i++) {
        sol[k].first = i;
        if (valido_traje(cogido[0],i,bestShoes[k],traje[k][i],max,suma,pred[k+1])) {
            cogido[0][i] = true;
            for (int j = 0; j < sol.size(); j++) {
                sol[k].second = j;
                suma += traje[k][i] * zap[k][j];

                    //sol[k].first * sol[k].second;
                if (valido_zap(cogido[1],j,suma,max,pred[k+1])) {
                    cogido[1][j] = true;

                    if (k == sol.size() - 1) {
                        max = suma;
                    }
                    else {
                        permutacion(traje, zap, sol, k + 1, cogido, suma, max, pred, bestShoes);
                    }
                    cogido[1][j] = false;
                }
                suma -= traje[k][i] * zap[k][j];
            }
            cogido[0][i] = false;
        }



    }


}

void resuelveCaso() {
    //auto start = high_resolution_clock::now();
    tPrenda zapato;
    tPrenda traje;
    int entrada;
    int suma = 0;
    int max = 0;
    cin >> entrada;
    vector<int >prediccion(entrada + 1);
    vector<int>aux(entrada);
    vector<tModelo>sol(entrada );
    rellenar(traje, entrada, prediccion);
    rellenar(zapato, entrada, aux);
    vector<vector<bool> >cogido(2, vector<bool>(entrada, false));
    for (int i = entrada - 1; i >= 0; i--) {
        max += traje[i][i] * zapato[i][i];
        suma += prediccion[i] * aux[i];
        prediccion[i] = suma;
    }
    prediccion[prediccion.size() - 1] = 0;
    suma = 0;
    if ( max != prediccion[0]) {
        permutacion(traje, zapato, sol, 0, cogido, suma, max, prediccion, aux);
    }

    cout << max << endl;
    //auto stop = high_resolution_clock::now();
    //auto duration = duration_cast<microseconds>(stop - start);


    //cout << "The time is:" << duration.count() << endl;
}
