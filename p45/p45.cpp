
#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;
using player = pair<string, int>;

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

player ganador(const vector<player>&v,int ini,int fin) {
    if (ini + 1 == fin) {
        return v[ini];
    }
    else if (ini + 2 == fin) {
        if (v[ini].second < v[ini + 1].second) {
            return make_pair(v[ini+1].first, v[ini+1].second+v[ini].second/2);
        }
        else {
            return make_pair(v[ini].first, v[ini].second + v[ini + 1].second / 2);
        }

    }
    else {
        int m = (ini + fin) / 2;
        player uno = ganador(v, ini, m);
        player dos = ganador(v, m, fin);

        if (uno.second < dos.second) {
            return make_pair(dos.first, dos.second + uno.second / 2);

        }
        else {
            return make_pair(uno.first, uno.second + dos.second / 2);
        }
    }
}


bool resuelveCaso() {
    int entrada;
    
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;
    
    vector<player>v(entrada);
    for (int i = 0; i < entrada; i++) {
        cin >> v[i].first;
        cin >> v[i].second;
    }
    player ganador_final = ganador(v, 0, v.size());
    cout << ganador_final.first << " " << ganador_final.second << endl;

    return true;
}

