#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>

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

bool valido(const vector<vector<int>>& datos,vector<bool>&cogido,int elegido,int k,int &superticion,int total_puesto,int &suma_actual,int &max,const vector<int>&pred) {
    if (cogido[elegido]) {
        return false;
    }
    if (datos[k][elegido]<0) {
        return false;
    }
    
    if ( (float)(superticion)/ total_puesto> (float)1/3) {
        return false;
    }
    if (pred[k+1] + suma_actual < max) {
        return false;
    }

    return true;
}


//ramas los habitantes
//altura los asientos que existen
void invitar(const vector<vector<int>>&datos,int k,const int& pos_hada,vector<bool>&cogido,vector<int>&sol,const vector<int>&pred,int &max,int &suma_actual,int& permutacion,int& superticion) {

    for (int i = 0; i < cogido.size(); i++) {// elegir la persona que
        sol[k] = i;
        suma_actual += datos[k][i];
       
        if (k == i) {
            superticion++;
        }
        if (valido(datos,cogido,i,k,superticion,sol.size(), suma_actual, max, pred)) {
            cogido[i] = true;
            
            
            if (k == sol.size() - 1) {// todos los asiento rellenados
                if (cogido[pos_hada]) {
                    
                    if (suma_actual>max) {
                        max = suma_actual;
                        permutacion = 1;// diferente forma de elegir los invitados

                    }
                    else if(suma_actual==max) {
                        permutacion++;
                    }
                        
                }
                
            }
            else {
                invitar(datos, k+1, pos_hada, cogido, sol,  pred, max, suma_actual, permutacion,superticion);
            }
         
            cogido[i] = false;
        }
        suma_actual -= datos[k][i];
        
        if (k == i) {
            superticion--;
        }
    }

}



bool resuelveCaso() {
    
    int entrada;
    cin >> entrada;
    if (entrada==0)
        return false;

    int num_invitados;
    int num_hada;
    cin >> num_invitados;
    cin >>num_hada;
    vector<vector<int>>v(num_invitados, vector<int>(entrada));
    vector<bool>cogido(entrada, false);// miramos si se repite invitado
    vector<int>sol(num_invitados);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++)
            cin >> v[i][j];
    }
    
    vector<int>pred(num_invitados+1);// elegirmos el habitante que más disfrute el asiento
    pred[num_invitados] = 0;
    
    for (int i = v.size()-1; i >=0; i--) {
        pred[i] = v[i][v[i].size()-1];
        for (int j = v[i].size() - 2; j >=0; j--) {
            if (pred[i] < v[i][j]) {
                pred[i] = v[i][j];
            }
        }
        pred[i]+=pred[i+1];
    }
    int max = -1;
    int suma_actual = 0;
    int permutacion = -1;
    int num_superticion = 0;
    invitar(v,0,num_hada,cogido,sol,pred,max,suma_actual,permutacion,num_superticion);
    
    if (max==-1 && permutacion==-1) {
        cout << "No\n";
    }
    else {
       cout << max << " " << permutacion << endl;
    }

    
    return true;
}

