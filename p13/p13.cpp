#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;
void resuelveCaso();



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

int* interval(const vector<int >& v, int altura) {
    int* a = new int[2];
    a[0] = -1;
    a[1] = -1;
    int long_max = 0;
    int contador=0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > altura) {
            contador++;
            if (contador > long_max) {
                long_max = contador;
                a[1] = i ;
                a[0] = i - contador+1;
                // cout << contador<<endl;
            }

        }
        else {
            
                
            contador = 0;
        }
    }



    return a;
}
 

void resuelveCaso() {
    int altura;
    int entrada;
    int *intervalo;
    cin >> entrada;
    cin >>altura;
    vector<int >v(entrada);
    
    for  (int& k:v)
        cin >> k;

    intervalo = interval(v, altura);

    for (int i = 0; i < 2; i++) {
        cout <<intervalo[i]<<" ";
    }
    cout << "\n";
    delete []intervalo;

}
