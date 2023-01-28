#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std::chrono;
// Introduce más librerías si son necesarias
using namespace std;


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


void rellenar(tPrenda& v, int entrada,vector<int>&aux ) {
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


bool valido(const vector<vector<bool> >& cogido,int i,int k,int max,const vector<int>&pred,const int &suma, const vector<int>& bestShoes,int eleccion) {
    //int prueba = eleccion * bestShoes[k / 2] + pred[(k / 2) + 1];
    /*
   
   
    */
    
    if (k % 2 == 0) {
        if (eleccion * bestShoes[k / 2] + pred[(k / 2) + 1] + suma <= max) {
            return false;
        }
    }
    if (suma + pred[((k + 1) / 2)] <= max) {
        return false;
    }
 
  
    return !cogido[k % 2][i];
    
   
    // cuando k sea par dara los trajes, y impar dara los zap
}


void permutacion(const tPrenda &traje,const tPrenda& zap,vector<int>&sol, int k, vector<vector<bool> >&cogido,int& suma, int& max,const vector<int>&pred,const vector<int>&bestShoes) {
    
    for (int i = 0; i < sol.size(); i++) {
        sol[k] = i/2;
        if (k % 2 == 1) {
            suma += traje[k / 2][sol[k - 1]] * zap[k / 2][sol[k]];

        }
        if (valido(cogido, i/2, k,max,pred,suma,bestShoes, traje[k / 2][sol[k]])) {
            cogido[k % 2][i/2] = true;
           
            if (k == sol.size() - 1) {
                if (max < suma)
                    max = suma;
            }
            else {
                permutacion(traje, zap, sol, k + 1, cogido, suma, max,pred,bestShoes);
            }

           

            cogido[k % 2][i/2] = false;
        }
        if (k % 2 == 1) {
            suma -= traje[k / 2][sol[k - 1]] * zap[k / 2][sol[k]];

        }
    }


}

void resuelveCaso() {
    auto start = high_resolution_clock::now();
    tPrenda zapato;
    tPrenda traje;
    int entrada;
    int suma = 0;
    int max=0;
    cin >> entrada;
    vector<int >prediccion(entrada+1);
    vector<int>aux(entrada);
    vector<int>sol(entrada * 2);
    rellenar(traje,entrada, prediccion);
    rellenar(zapato,entrada,aux);
    vector<vector<bool> >cogido(2,vector<bool>(entrada,false));
    for (int i = entrada-1; i>=0; i--) {
        max += traje[i][i] * zapato[i][i];
        suma += prediccion[i] * aux[i];
        prediccion[i] = suma;
    }
    prediccion[prediccion.size() - 1]=0;
    suma = 0;
    if (prediccion.size()>0 && max != prediccion[0]) {
        permutacion(traje, zapato, sol, 0, cogido, suma, max, prediccion,aux);
    }
    
    cout << max<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

   
    cout <<"The time is:" << duration.count() << endl;
}
