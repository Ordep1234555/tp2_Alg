#include <cstdio>
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include "tp02.h"

using namespace std;

int main(){

    int N, T, aux, valor, inicial, final, custo;
    string parametros;
    
    cin >> N >> T;
    
    Ciclovia ciclovia(N);
    
    getline(cin, parametros);
    istringstream VT(parametros);
    for(aux =0; VT>>id; aux++){
      ciclovia.NovoVT(aux,id);
    }
    
    for(aux =0; aux<N; aux++){
      getline(cin, parametros)
      istringstream trechos(parametros);
      trechos >> inicial;
      trechos >> final;
      trechos >> custo;
      ciclovia.NovoTRECHO(inicial,final,custo);
    }
    
  ciclovia.MST();
  ciclovia.imprime();
}
