#include<iostream>
#define max 10000
using namespace std;
int fenwickTree[max]={},arreglo[max]={},n,m;
void FT(){
      int j,numero;
      for(int i=1;i<=n;i++){
            numero=arreglo[i];
            fenwickTree[i]+=numero;
            j=i;
            while((j+=j&-j)<=n){
                  fenwickTree[j]+=numero;
            }
      }
}
int consultar (int posicion){
      int sum=fenwickTree[posicion];
      while((posicion-=posicion&-posicion)!=0){
            sum+=fenwickTree[posicion];
      }
      return sum;
}
int suma(int inicio,int final){
      inicio=consultar(inicio-1);
      final=consultar(final);
      return final-inicio;
}
void actualizar (int posicion,int numero){
      int numeroAnterior=arreglo[posicion];
      arreglo[posicion]=numero;
      numero=numero-numeroAnterior;
      while((posicion+=posicion&-posicion)<=n){
            fenwickTree[posicion]+=numero;
      }
}
int main(){
      int inicio,final,nuevoNumero,posicion;
      bool operacion=0;//1 para suma y 0 para actualizacion
      cin>>n;
      for(int i=1;i<=n;i++){
            cin>>arreglo[i];
      }
      FT();
      cin>>m;
      for(int i=0;i<m;i++){
            cin>>operacion;
            if(operacion){
                  cin>>inicio>>final;
                  cout<<suma(inicio,final)<<endl;
            }else{
                  cin>>posicion>>nuevoNumero;
                  actualizar(posicion,nuevoNumero);
            }
      }
      return 0;
}