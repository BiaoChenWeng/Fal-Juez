
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

int buscarIz(const vector<bool >& v, int ini, int fin) {
    if (fin == ini ) {
        return ini;
    }
    if (ini + 1 == fin) {
        if (!v[ini]) {
            return ini + 1;
        }
        else {
            return ini;
        }
    }
    else {
        int media = (fin + ini - 1) / 2;
        if (!v[media] ) {
            return buscarIz(v,  media + 1, fin);
        }
        else {
            return buscarIz(v, ini, media + 1);
        }

    }

}


//          
/*
// buscarIz() ini==fin    return 0          caso vacio
//            ini+1==fin y ini =true        return ini return ini    existe un true en la posicion marcada
              ini+1==fin y ini =false       return fin , significa que no existe ningun true
              ini+1 >fin y v[m]=false       return buscarIz(v,media+1,fin)   descartamos el valor que no interesa
              ini+1 >fin y v[m]=true        return buscarIz(v,ini,media+1)   no descartamos el true encontrado

            
            
T(n)= c0 ini==fin || ini +1==fin  // ini +1 =fin es una constante mayor, pero no modifica el O()
      
      T(n/2)+c2
            

T(n)=T(n/2)+c2= T(n/2^2)+c2+c2= t(n/2^3) + 3c2------
t(n/2^k)+ kc2=-----------=t(1)+ log2n*c2=log2n*c2+ c0 

1=n/2^k => n=2^k =>log2n= k 

coste logaritmico
*/          


bool resuelveCaso() {
    int entrada;
    cin >> entrada;
    int valor;
    if (!std::cin)  // fin de la entrada
        return false;
    
    vector <bool>v(entrada);
    
    for (int i = 0; i < entrada; i++) {
        cin >> valor;
        if (valor == 0) {
            v[i] = false;
        }
        else {
            v[i] = true;
        }
    }

    cout << v.size() - buscarIz(v, 0, v.size())<<endl;


    return true;
}

/*
Contar el n´umero de valores ciertos.
Se tiene un vector de valores booleanos. Los valores false se encuentran todos consecutivos y situados
a la izquierda del vector. Los valores true est´an tambi´en consecutivos en la parte derecha.
Se pide calcular el n´umero de valores true que hay en el vector.
Requisitos de implementaci´on.
Se debe implementar una funci´on que reciba un vector con los datos de entrada y devuelva el n´umero
de valores ciertos que tiene el vector.
Se debe emplear la t´ecnica de divide y vencer´as.
Se pueden a˜nadir m´as par´ametros a la funci´on si se necesitan. Tambi´en se pueden a˜nadir nuevos
valores de retorno de la funci´on.
Entrada
La entrada consta de una serie de casos de prueba. Cada caso se escribe en dos l´ıneas. En la primera
se indica el n´umero de valores del vector. En la segunda se indican los valores. Un cero indicar´a un valor
falso y un uno indicar´a un valor cierto.
El n´umero de valores del vector n cumple que 0 < n <= 100.000
Salida
Para cada caso de prueba se muestra en una l´ınea el n´umero de valores ciertos que tiene el vector.
Entrada de ejemplo
8
0 0 0 1 1 1 1 1
4
1 1 1 1
5
0 0 0 0 0
Salida de ejemplo
5
4
0

1*/