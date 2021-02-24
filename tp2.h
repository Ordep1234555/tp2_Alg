//https://stackoverflow.com/questions/23588439/prims-algorithm-c
# define INF 0x3f3f3f3f
using namespace std;

class Ciclovia{
    int N;
    int *VT;
    list<pair<pair<int,int>, pair<int, int>> > *Trajetos;
    int *QuantTrechos;
    int CustoMinimo;
    int AtratividadeAgregada;
    list<pair<int, pair<int, int>> > Selecionados;
  public:
    Ciclovia(int N); //Construtor
    void NovoVT(int numero, int valor); //Novo valor turistico 
    void NovoTRECHO(int inicial, int final, int custo);
    void MST(); //Arvore geradora minima
    void Imprime();
 };

Ciclovia::Ciclovia(int N){
    this -> N = N;
    VT= new int [N];
    QuantTrechos = new int [N];
    CustoMinimo = 0;
    AtratividadeAgregada = 0;
    Trajetos = new list<pair<pair<int,int>, pair<int, int>> > [N];
}

void Ciclovia::NovoVT(int numero, int valor){
    VT[numero] = valor;
}
    
void Ciclovia::NovoTRECHO(int inicial, int final, int custo){
    int Atratividade;
    Atratividade = VT[inicial] + VT[final];
    Trajetos[inicial].push_back(make_pair(make_pair(inicial,final), make_pair(custo, Atratividade)));
    Trajetos[final].push_back(make_pair(make_pair(final,inicial), make_pair(custo, Atratividade)));
}
    
void Ciclovia::MST(){
    int src = 0, final, menorCusto, melhorAtratividade,aux;
    bool encontrado = true;
    bool Incluidos[N];
    list<pair<pair<int, int>,pair<int,int>>>::iterator i;
    
    for(aux=0; aux<N; aux++){             
        Incluidos[aux] = false;       
        QuantTrechos[aux] = 0;  
    }
    Incluidos[src] = true;
    while (encontrado)
    {
        encontrado = true;
        for(aux=0;aux<N;aux++)
        {
            if(Incluidos[aux]==true)
            {
                for (i= Trajetos[aux].begin(); i!= Trajetos[aux].end(); i++)
                {
                    if (Incluidos[(*i).first.first] == false && (*i).second.first <= menorCusto)
                    {
                        if((*i).second.first < menorCusto){
                            melhorAtratividade = (*i).second.second;
                            menorCusto=(*i).second.first;
                            src = (*i).first.first;
                            final = (*i).first.second;
                            encontrado = true;
                        }
                        if((*i).second.first == menorCusto && (*i).second.second < melhorAtratividade)
                        {
                            melhorAtratividade = (*i).second.second;
                            menorCusto=(*i).second.first;
                            src = (*i).first.first;
                            final = (*i).first.second;
                            encontrado = true;
                        }
                    }
                }
                if(encontrado){
                    Selecionados.push_back(make_pair(menorCusto,make_pair(src,final)));
                    QuantTrechos[final]++;
                    QuantTrechos[src]++;
                    AtratividadeAgregada+= melhorAtratividade;
                    CustoMinimo+= menorCusto;
                    Incluidos[final] = true;
                }
            }
        }    
    }
}
    
void Ciclovia::Imprime(){
    
    cout << endl << CustoMinimo << " " << AtratividadeAgregada << endl;   
    
    for (int aux=0; aux<N; aux++){
        cout << QuantTrechos[aux] << " ";
    }
    cout<<endl;
    
    list<pair<int,pair<int,int>>>::iterator i;
    for(i= Selecionados.begin(); i != Selecionados.end(); i++){
        cout << (*i).second.second << " " << (*i).second.first << " " << (*i).first << endl;
    }
    
}
