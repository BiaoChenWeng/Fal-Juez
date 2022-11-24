
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
// Introduce más librerías si son necesarias
using namespace std;

struct tGanador {
    bool saltar_partida;
    int jugados;
    
};


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


tGanador jugador(vector<bool>const& v, int ini, int fin, int partido_actual, int p_buscado) {
    tGanador b;
    if (ini +1== fin ) {
        b.jugados = 0;
        b.saltar_partida = false;
        return b;
        
    }
    else if (ini + 2 == fin) {
        if (!v[ini] && !v[ini+1]) {
            
            b.jugados = 0;
            b.saltar_partida = true;
        }
        else if(!v[ini] || !v[ini+1]) {
            b.jugados = 0;
            b.saltar_partida = false;
        }
        else {
            if (p_buscado >= partido_actual)
                b.jugados=1;
            b.saltar_partida = false;
        }
        return b;
    }
    else {
        int m = (ini + fin) / 2;
        tGanador a,c;
        a=jugador(v, ini, m, partido_actual - 1, p_buscado);
        c= jugador(v, m, fin, partido_actual - 1, p_buscado);

        b.saltar_partida = a.saltar_partida && c.saltar_partida;
        b.jugados = a.jugados + c.jugados;
        if (!a.saltar_partida && !c.saltar_partida && p_buscado >= partido_actual) {
            b.jugados++;
        }

        return b;

    }
}

bool resuelveCaso() {
    int entrada,partido;
    cin >> entrada;
    cin >> partido;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<bool >v(entrada);
    string jug;
    
    for (int i = 0; i < v.size(); i++) {
        cin >> jug;
        v[i] = jug != "NP";

    }

    int k = log2(entrada);

    cout << jugador(v, 0, v.size(), k, partido).jugados<<endl;


    return true;
}

