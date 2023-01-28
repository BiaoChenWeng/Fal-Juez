
#include <iostream>
#include <fstream>
#include <vector>

// Introduce más librerías si son necesarias
using namespace std;

using lli = long long int;
struct tAltura{
    lli menor;
    lli mayor;
    lli medio;
};

struct a {
    bool premio_siempre;
    int max;
    int min;
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




bool check(vector<int>const &v,a mayor, a menor , a medio) {
    if (menor.premio_siempre && medio.premio_siempre) {
        if (v[menor.min] < v[medio.max] && v[medio.max] < v[mayor.max] && menor.min<mayor.max&& mayor.max<medio.max) {
            return false;
        }
        return true;
    }
    else {
        return false;
    }
}


a sol(vector<int>const& v, int ini, int fin) {
    a resultado;
    
    
    resultado.premio_siempre = true;
   
    resultado.max = ini;
    resultado.min = ini;
    int max=v[ini];
    int min=v[ini];
    
    for (int i = ini+1; i < fin; i++) {
        if (v[i] > max) {
            max = v[i];
            resultado.max = i;
        }
        else if (v[i] < min) {
            min = v[i];
            resultado.min = i;
        }
    }
    
    
    if (ini + 1==fin) {
        return resultado;
    }
    else if (ini + 2 == fin) {
        return resultado;
    }
    else {
        a b, c;
        if (resultado.max == ini) {
            b = sol(v, ini + 1, fin);
            b.max = resultado.max;
            return b;
        }
        else if(resultado.max+1==fin) {
            b = sol(v, ini, fin - 1);
            b.max = resultado.max;
            return b;
        }
        else {
            
            b = sol(v, ini, resultado.max);
            c = sol(v, resultado.max+1, fin);

            if (check(v, resultado, b, c)) {
               
                return resultado;
            }
            else {
                resultado.premio_siempre = false;
                return resultado;
            }
     
        }
    }

}




bool resuelveCaso() {
    int entrada;
    //tAltura a;
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<int>v(entrada);

    for (int& k : v)
        cin >> k;
    a resultado = sol(v, 0, v.size());
    //a= elegir(v, 0, v.size());
    if (resultado.premio_siempre) {
        cout << "SIEMPRE PREMIO\n";
    }
    else {
        cout << "ELEGIR OTRA\n";
    }

    return true;
}

/*
El juego de la linterna
Jimmy tiene muchos sobrinos a los que tiene que entretener cada
vez que van a su casa de visita. Hace tiempo que encontr´o la f´ormula
para conseguirlo. En realidad para ´el fue una sorpresa descubrir que
aquel medio juego improvisado que empez´o como una manera de tenerles tranquilos cinco minutos se ha convertido en una tradici´on que
le piden fin de semana tras fin de semana.
El “juego” (por llamarlo de alguna forma) consiste en lo siguiente:
Jimmy deja a todos los sobrinos en la habitaci´on. Mientras ´el espera
en el pasillo, los ni˜nos se colocan al azar uno al lado del otro formando
una hilera de personajitos de distintas edades y alturas. Cuando ya
est´an todos colocados, se apagan las luces y el t´ıo Jimmy entra a
oscuras y se coloca frente a la fila. Y entonces es cuando empieza la parte “divertida” del juego.
Jimmy saca una linterna de su bolsillo e ilumina la cara de uno de sus sobrinos al azar, que da un
paso adelante. Despu´es se desplaza a la derecha salt´andose a un n´umero de sobrinos al azar e ilumina a
otro de los ni˜nos que avanza tambi´en sali´endose de la fila. El proceso lo repite una ´ultima vez, dejando
a tres ni˜nos elegidos aleatoriamente e iluminados por la luz de la “linterna m´agica”.
En ese momento, se da la luz y los tres sobrinos que han sido elegidos son premiados con cualquier
cosa; unas veces son caramelos, otras veces es alguna moneda que los ni˜nos gastar´an en su pr´oxima visita
a la tienda de chucher´ıas. . .
Eso s´ı, el t´ıo Jimmy pone una ´unica condici´on para el premio: cuando los tres sobrinos que han dado
un paso adelante salen de la fila, sus alturas son variopintas. Dependiendo de a qui´en haya elegido, el
primero puede ser el m´as bajito, el m´as alto o el del centro. Los tres ni˜nos pueden, por tanto, quedar
en orden creciente de altura, en orden decreciente o de cualquier otra forma. Pues bien, los ni˜nos se
quedar´an sin premio si el primer sobrino elegido es el m´as bajito de los tres, el segundo es el m´as alto y
el tercero es el mediano.
Albertito, el primo mayor, ha decidido dirigir a todos sus primos y en el momento de colocarse
supervisa si la colocaci´on final puede llevar o no a que el t´ıo Jimmy elija a tres ni˜nos de forma que no
haya premio. Y en ese caso les pide a todos que se recoloquen.
Por ejemplo, si ese d´ıa hay 5 ni˜nos y se colocan aleatoriamente de forma que las alturas quedan
5 1 4 3 2, el t´ıo Jimmy podr´ıa tener la “punter´ıa” de sacar al de altura 1, al de 4 y al de 2 y se
quedar´ıan sin premio. Sin embargo, en una colocaci´on como 5 1 2 3 4 los sobrinos elegidos nunca se
quedar´an sin premio.
Entrada
La entrada estar´a compuesta por distintos casos de prueba, cada uno ocupando dos l´ıneas. La primera
l´ınea contiene un n´umero indicando el n´umero de sobrinos que hay ese d´ıa en casa (como m´ınimo 3 y
hasta 500.000). La segunda l´ınea contendr´a las alturas de cada uno de ellos en la configuraci´on en la que
se han colocado. Las alturas no se repiten, y ser´an n´umeros entre 1 y 109
.
Salida
Para cada caso de prueba se indicar´a el veredicto que debe dar Albertito ante esa colocaci´on. Se
escribir´a SIEMPRE PREMIO si el t´ıo Jimmy nunca podr´a sacar una configuraci´on de sobrinos sin premio,
o ELEGIR OTRA si el t´ıo puede sacar a tres sobrinos de forma que se queden sin premio.
Entrada de ejemplo
5
5 1 4 3 2
5
5 1 2 3 4
1
Salida de ejemplo
ELEGIR OTRA
SIEMPRE PREMIO

*/