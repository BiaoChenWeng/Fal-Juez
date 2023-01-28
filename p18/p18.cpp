
#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
using namespace std;
bool resuelveCaso();
vector<int> resolver(const vector<int>& v, int longitud, int& max);
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


void suma(const vector <int>& v) {
    int dia = 0;
    int long_min= 0;
    int suma_max = 0;

    int largo=0;
    int suma=0;
    for (int i = 0; i < v.size(); i++) {
        suma += v[i];
        if (suma <= 0) {
            suma = 0;
            largo = 0;
        }
        else {
            largo++;
            if (suma > suma_max) {
                suma_max = suma;               
                
                long_min = largo;
                dia = i - largo+1;
                
            }
            else if (suma == suma_max && largo<long_min) {
                dia = i - largo+1;
                long_min = largo;
            }

        }

    }

    cout << suma_max << " " << dia << " " << long_min << endl;
}

bool resuelveCaso() {
    int entrada;

    cin >> entrada;
    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;
    
    
    vector<int> v(entrada);
    for (int& j : v)
        cin >> j;
  
    suma(v);


    return true;
}
/*
Cenando con los amigos
Cada a˜no nos reunimos los amigos a cenar unos d´ıas antes de
Navidad. El a˜no pasado, como casi todos los anteriores, acabamos
hablando de lo que comer´ıamos durante las fiestas y de lo dif´ıcil que
es mantener el tipo en estos d´ıas. Sin embargo, algunos afirman que
hay otras ´epocas peores en el a˜no, como los cocidos en carnaval, o los
helados en verano. Al final, hicimos una apuesta. Cada uno apuntar´ıa
durante este a˜no los gramos que engordase o adelgazase cada d´ıa.
Esta noche nos vamos a reunir de nuevo para cenar y tenemos que
analizar los datos para ver quien pierde la apuesta y paga la cena.
Para cada secuencia de datos, buscaremos los d´ıas consecutivos en los
que cada uno engordamos m´as, es decir, entre que dos d´ıas la suma de los pesos es m´axima (mayor
que entre otros dos d´ıas cualquiera). Si existen dos secuencias de igual suma, nos quedaremos con la
que tenga menor longitud. Si existen dos secuencias de igual suma e igual longitud nos quedamos con
la que ocurre antes en el a˜no (la primera que aparece). De esta forma veremos en que ´epoca del a˜no
engordamos m´as cada uno. Como todos los amigos somos grandes comedores, nunca hacemos r´egimen
durante muchos d´ıas seguidos, por lo que todos acabamos engordando algo por lo menos un d´ıa al a˜no.
Requisitos de implementaci´on.
Implementar una funci´on que reciba en un vector los datos, encuentre la subsecuencia en la cual la
suma de valores es m´axima y devuelva la suma de esta subsecuencia, su punto de comienzo y su n´umero
de d´ıas. Cada valor del vector debe tratarse una ´unica vez, y no debe utilizarse ning´un vector auxiliar.
Los datos de la secuencia pueden ser positivos o negativos, pero siempre habr´a al menos un valor
positivo. Ten en cuenta que una subsecuencia deja de ser interesante cuando su suma es cero o negativa,
ya que al haber n´umeros positivos en el vector estos ser´an siempre mejores que cualquier valor negativo.
Al tratar cada dato, no importa si el dato es positivo o negativo, sino si la suma acumulada teniendo en
cuenta ese dato es positiva a negativa. Si la suma acumulada es positiva la subsecuencia sigue siendo
interesante, si es cero o negativa debemos cambiar de subsecuencia para no acumular algo negativo.
Entrada
La entrada consta de una serie de casos de prueba. Cada caso de prueba tiene dos l´ıneas. En la
primera se indica el n´umero elementos del vector. En la segunda se indican los valores.
Los valores pueden almacenarse en una variable de tipo int. El tama˜no del vector es mayor a igual
que uno y se garantiza que siempre hay al menos un valor estrictamente positivo.
Salida
Para cada caso de prueba se escribe en una l´ınea la suma de la subsecuencia, el dia en que comienza
y la longitud de la subsecuencia.
1
Entrada de ejemplo
6
-3 2 1 -1 -3 2
6
2 -1 2 -3 1 -1
7
-1 1 -3 4 1 -1 2
1
4
3
-1 1 -1
3
0 2 3
8
2 3 -6 0 3 2 -1 1
Salida de ejemplo
3 1 2
3 0 3
6 3 4
4 0 1
1 1 1
5 1 2
5 0 2

*/
