#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
 
using namespace std;
 
struct PRECIOS
{
    float preciobruto;
    float iva;
    float precioneto;
 
}pan,jamon,queso,*var;
 
void calculo(float *obj)
{
   *var.iva=.16*(*var);
  *var.precioneto=*var.preciobruto+*var.iva;
}
int main()
 
{int x;
 
system("color FC");
do{
    cout<<"-------------------------------------------------"<<endl;
    cout<<"PRECIO DEL PAN"<<endl;
    cin>>pan.preciobruto;
    var=&pan;
    calculo(&pan.preciobruto);
    cout<<"PRECIO DEL JAMON"<<endl;
    cin>>jamon.preciobruto;
    var=&jamon;
    calculo(&jamon.preciobruto);
    cout<<"PRECIO DEL QUESO"<<endl;
    cin>>queso.preciobruto;
    var=&queso;
    calculo(&queso.preciobruto);
 
    cout<<"--0-- INGRESE **CERO** PARA REPETIR"<<endl;
    cin>>x;
}
while(x==0);
}