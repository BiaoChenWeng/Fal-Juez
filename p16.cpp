
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


void resolver(const vector<int>& v, int& continuo, int& racha,int & ultima) {
    int contador=0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0) {
            contador++;
            if (contador > continuo) {
                continuo = contador;
                racha = 1;
                ultima = v.size() - i-1;
            }
            else if (continuo == contador) {
                racha++;
                ultima = v.size() - i-1;
            }

        }
        else {
            contador = 0;
        }



    }


}

bool resuelveCaso() {
    int entrada;
    int g_continuo = 0;
    int racha = 0;
    
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;
    int ultima_victoria=entrada;
    vector<int >v(entrada);

    for (int& k : v)
        cin >> k;
    resolver(v, g_continuo, racha, ultima_victoria);

    cout << g_continuo << " " << racha << " " << ultima_victoria << endl;

    return true;
}

