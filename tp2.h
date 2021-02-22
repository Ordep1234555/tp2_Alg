//https://stackoverflow.com/questions/23588439/prims-algorithm-c
class Ciclovia{
    int N;
    int *VT;
    int *
    int CustoMinimo;
    int AtratividadeAgregada;
  public:
    Ciclovia(int V); //Construtor
    void NovoVT(int numero, int id);
    void NovoTrecho(int inicial, int final, int custo);
    void MST(); //Arvore geradora minima
    void Imprime();
 };
