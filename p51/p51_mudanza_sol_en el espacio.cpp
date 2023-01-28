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

bool contar(const vector<int>& v, int dia, int peso) {
    int contar=1;
    int i = 0;
    int suma = 0;
    while (i < v.size()) {
        if (suma + v[i] <= peso) {
            suma += v[i];
        }
        else {
            contar ++;
            suma = v[i];
        }
        
        
        i++;
    }
    return contar <= dia;

}


int peso(int ini,int fin,const vector<int>&v,int dia) {
    if (ini == fin) {
        return ini;
    }
    else {
        int m = (ini + fin) / 2;
        if (contar(v, dia, m)) {
            return peso(ini, m, v, dia);
        }
        else {
            return peso(m+1, fin, v, dia);
        }


    }


}




bool resuelveCaso() {

    int entrada,viaje;
    cin >> entrada;
    cin >> viaje;
    if (entrada==0 && viaje==0)
        return false;

    
    vector<int>v(entrada);

    for (int& k : v)
        cin >> k;
    int max=v[0];
    int suma_total=0;


    for (int i = 0; i < v.size(); i++) {
        suma_total += v[i];
        if (v[i] > max)
            max = v[i];
    }
    cout << peso(max, suma_total, v, viaje)<<endl;
    // escribir sol

    return true;
}
/*
Doc ha recibido ya las piezas de arte para la exposici´on, pero a´un la
tiene a medio montar. Su principal problema es que indic´o a los artistas
que le enviaran a su casa las obras y ahora tiene que trasladarlas al lugar
de la exposici´on.
En teor´ıa, esa labor de mudanza es f´acil: se alquila un cami´on, se
carga y se llevan. En la pr´actica, sin embargo, la situaci´on es un poco
m´as dif´ıcil. Aunque las obras son peque˜nas (en un ´unico cami´on entrar´ıan
todas), pesan mucho. Eso significa que debe tener cuidado a la hora de
escoger el cami´on que alquile y fijarse en cu´al es el peso m´aximo que es
capaz de transportar.
La tarea se complica un poco porque:
• El precio del alquiler del cami´on es proporcional a la carga m´axima que soporta, por lo que quiere
ajustarla al m´ınimo.
• Teniendo en cuenta el tiempo de que dispone Doc para realizar la mudanza, tiene limitado el
n´umero de viajes que puede hacer con el cami´on.
• Para evitar tener que mover mucho las obras dentro de casa de Doc, las piezas las cargar´a en el
cami´on en el mismo orden en el que est´an colocadas en el pasillo de la entrada.
Tenemos que ayudar a Doc a elegir el cami´on que debe alquilar.
Entrada
La entrada estar´a compuesta de varios casos de prueba.
Cada caso de prueba ocupa dos l´ıneas. La primera tiene el n´umero de obras de arte que se agolpan
en el pasillo de Doc (como mucho 10.000) y el n´umero m´aximo de viajes que Doc tiene tiempo de hacer
con el cami´on. Ambos n´umeros son mayores que cero.
La segunda l´ınea contiene los pesos de las distintas obras que hay que transportar en el orden en el
que deben ser trasladadas. Se garantiza que la suma de los pesos de todas las obras es inferior a 109
.
La entrada termina con una l´ınea con dos ceros que no debe procesarse.
Salida
Por cada caso de prueba se escribir´a una ´unica l´ınea con el tope de carga m´as peque˜no que debe tener
el cami´on alquilado para poder hacer la mudanza de todas las obras sin pasarse del n´umero de viajes
m´aximo establecido ni superar la carga m´axima del cami´on.
Entrada de ejemplo
3 1
3 4 5
3 2
3 4 5
3 2
3 5 4
3 3
3 4 5
0 0
1
Salida de ejemplo
12
7
8
5

*/