//https://stackoverflow.com/questions/23588439/prims-algorithm-c
class Ciclovia{
    int N;
    int *VT;
    int *QuantTrechos
    int CustoMinimo;
    int AtratividadeAgregada;
    list<pair<int, pair<int, int>> > *trajetos;
    list<pair<int, pair<int, int>> > Selecionados;    
  public:
    Ciclovia(int N); //Construtor
    void NovoVT(int numero, int id);
    void NovoTrecho(int inicial, int final, int custo);
    void MST(); //Arvore geradora minima
    void Imprime();
 };

Ciclovia::Ciclovia(int N){
    VT= new int [N];
    QuantTrechos = new int [N];
    CustoMinimo = 0;
    AtratividadeAgregada = 0;
    
void Ciclovia::NovoVT(int aux, int id){
    
    
}
    
void Ciclovia::NovoTRECHO(int inicial, int final, int custo){
    
    
    
}
    
void Ciclovia::MST(){
    
}
    
void Ciclovia::Imprime(){
    
    
}
/*Ciclovia::Ciclovia(int v){
    this->V = v;                                                            //  V recebe a quantidade total de vértices
    adjacencias = new std::list<std::pair<int, std::pair<int, int> > >[V];  //  Cria um vetor de lista de adjacências de tamanho V
    valorTuristico = new int[V];                                            //  Cria um vetor de tamanho V para os valores turisticos de cada vertice
    quantidadeArestas = new int[V];                                         //  Cria um vetor de tamanho V para a quantidade de arestas de cada vertice
    custoMinimo = 0;                                                        //  O custo minimo é setado para 0
    atratividadeAgregada = 0;                                               //  A atratividade agregada é setada para 0

}

void Ciclovia::adicionaValorTuristico(int ponto, int valor){
    valorTuristico[ponto] = valor;                                          //  É adicionado no índice de um ponto o seu valor turistico
}

void Ciclovia::adicionaTrecho(int a, int b, int custo){ 
    int atratividade = valorTuristico[a] + valorTuristico[b];                           //  Calcula a atratividade entre o vértice a e b
    adjacencias[a].push_back(std::make_pair(b, std::make_pair(custo, atratividade)));   //  Adiciona a um trecho do vértice a para b, com seu o custo e atratividade
    adjacencias[b].push_back(std::make_pair(a, std::make_pair(custo, atratividade)));   //  Assim como um trecho do vértice b para a
}

void Ciclovia::Prim(){
    bool visitados[V];                                              //  O vetor visitados ira marcar quais vertices já foram visitados ou não
    int origem = 0;                                                 //  A origem começará do vertice 0
    int destino;                                                    //  A variavel destino representa de onde o vertice de origem irá
    bool achou = true;                                              //  Um booleano que indica se um novo vértice foi encontrado
    int menorCusto;                                                 //  Menor custo entre um vertice e outro
    int maiorAtratividade;                                          //  Maior atratividade entre um vertice e outro 
    std::list<std::pair<int, std::pair<int, int> > >::iterator it;  //  Iterador da lista de adjacencias
    
    for(int i=0; i<V; i++){             
        visitados[i] = false;       //  Todos os valores do vetor de visitados recebem false
        quantidadeArestas[i] = 0;   //  E a quantidade de arestas de todos os vertices recebem 0
    }

    visitados[origem] = true;       //  Marca o vertice de origem como visitado

    while(achou){                   //  Enquanto um novo vértice for encontrado
        menorCusto = 1000001;       //  O menor custo e a maior atratividade iniciam a cada loop com esse valores, pois pela especificação do TP 
        maiorAtratividade = -1;     //  não existirão pontos com custo maior que 1000001 e atratividade menor que 0.
        achou = false;              //  Ainda não foram encontrados vértices
    
        //  Percorre todos os vértices
        for(int i=0; i < V; i++){              
            
            //  Encontra um vértice V_i já visitado
            if(visitados[i] == true){      
                
                //  Percorre os vértices ligados ao vértice V_i 
                for(it = adjacencias[i].begin(); it != adjacencias[i].end(); it++){    
                    
                    //  Se encontrar um vértice V_j não visitado ainda e com custo menor ou igual que o menor custo encontrado antes             
                    if(((*it).second.first <= menorCusto)&&((visitados[(*it).first] == false))){    
                        
                        //  Se o custo for menor que o menor custo encontrado antes
                        if((*it).second.first < menorCusto){            
                            menorCusto = (*it).second.first;            //  O menor custo passa a ser o custo de V_j
                            maiorAtratividade = (*it).second.second;    //  A maior atratividade passa a ser a do vértice V_j  
                            origem = i;                                 //  A origem passa a ser o vertice já visitado encontrado, ou seja, V_i
                            destino = (*it).first;                      //  O destino passa a ser o vértice V_j
                            achou = true;                               //  Achou passa a ser true
                        }
                        
                        //  Se o custo for igual ao menor custo encontrado antes e a atratividade for maior que a maior atratividade encontrada antes
                        if(((*it).second.first == menorCusto)&&((*it).second.second > maiorAtratividade)){      
                            menorCusto = (*it).second.first;            //  O menor custo passa a ser o custo de V_j
                            maiorAtratividade = (*it).second.second;    //  A maior atratividade passa a ser a do vertice V_j
                            origem = i;                                 //  A origem passa a ser o vértice já visitado, ou seja, V_i
                            destino = (*it).first;                      //  O destino passa a ser o vertice V_j
                            achou = true;                               //  Achou passa a ser true
                        }
                    }
                } 
            }
        }
        
        //  Após percorrer todos os vértices e se um novo foi encontrado
        if(achou){                                                                                      
            atratividadeAgregada = atratividadeAgregada + maiorAtratividade;            //  A atratividade agregada é incrementada com a maior atratividade obtida
            custoMinimo = custoMinimo + menorCusto;                                     //  O custo mínimo é incrementado com o menor custo obtido
            visitados[destino] = true;                                                  //  O vértice de destino é marcado como visitado
            quantidadeArestas[destino]++;                                               //  O vértice de destino obtido recebe uma aresta a mais
            quantidadeArestas[origem]++;                                                //  E o vértice de origem também

            //  Por fim, os vértices de origem e destino são adicionados na lista de trechos selecionados e o custo também
            trechosSelecionados.push_back(std::make_pair(menorCusto, std::make_pair(destino, origem)));  
        }
    }

}

void Ciclovia::imprime(){
    
    //  Imprime o custo minimo e a atratividade agregada
    std::cout << custoMinimo << " " << atratividadeAgregada << std::endl;       
    
    //  Imprime a quantidade de trechos de cada ponto
    for(int i=0; i<V; i++){
        std::cout << quantidadeArestas[i] << " ";       
    }
    std::cout << std::endl;

    //  Ordena a lista de trechos selecionados do menor para o maior custo
    trechosSelecionados.sort();                           
    
    //  Imprime a lista de trechos selecionados
    std::list<std::pair<int, std::pair<int, int> > >::iterator it;
    for(it = trechosSelecionados.begin(); it != trechosSelecionados.end(); it++){  
            std::cout << (*it).second.second << " " << (*it).second.first << " " << (*it).first << std::endl;
    }   

}*/
