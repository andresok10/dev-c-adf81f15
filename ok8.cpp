#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;
//Integer (whole number without decimals)
// qqq   www   eee  02
struct factura{
    //long cedula=0;
    int cedula=0;
    char cliente[20]="";
    char producto[20]="";
    double precio_unitario=0;
    int cantidad=0;
    double iva=0.00;
    double total=0;
};

int menu(){
    int x=0;
    cout<<"1 .registrar"<<endl;
    cout<<"2 .Mostrar_factura"<<endl;
    cout<<"3 .buscar-factura-por-cedula"<<endl;
    cout<<"4 .salir"<<endl;
    cout<<"opcion   ";
    cin>>x;
    return x;
};
//################################
void agregar_registro(){
    factura p;   //variables
    //long num;
    int num,n1,n2;
    double numxx,os;
    string clientex,productox;
    cout<<num<<"ingrese cedula"<<endl;
    cin>>p.cedula;
    //getline(cin,p.cedula);
    cout<<clientex<<"ingrese cliente"<<endl;
    cin>>p.cliente;
    cout<<productox<<"ingrese producto"<<endl;
    cin>>p.producto;
    cout<<numxx<<"ingrese precio"<<endl;
    cin>>p.precio_unitario;
    cout<<num<<"ingrese cantidad"<<endl;
    cin>>p.cantidad;

    num=p.precio_unitario*p.cantidad;
    p.cantidad=num;

    p.iva=0.12;
    //numxx=p.precio_unitario*p.iva;
    numxx=p.cantidad*p.iva;
    p.iva=numxx;
    
    //p.iva;
    //numxx=p.iva;
    //numxx=p.precio_unitario*p.cantidad;
    numxx=p.precio_unitario*p.cantidad;
    //numxx=numxx+p.iva;
    //numxx=p.precio_unitario*p.cantidad+p.iva;
    //numxx=p.iva;
    //numxx=numxx+p.iva;
    p.total=numxx+p.iva;
    //p.total=sum(numxx+p.iva);
    
    fstream e("ok.txt");
    e.seekp((p.cedula-1)*sizeof(factura));
    //e.seekp((p-1)*sizeof(factura));
    e.write((char*)&p,sizeof(factura));
    e.close();
    //return 0;
}
//################################################
void mostrar(factura p){
    //factura p;
    cout<<"     cedula: "<<p.cedula<<endl;
    cout<<"     nombre: "<<p.cliente<<endl;
    cout<<"     producto: "<<p.producto<<endl;
    cout<<"     precio: "<<p.precio_unitario<<endl;
    cout<<"     cantidad: "<<p.cantidad<<endl;
    cout<<"     iva: "<<p.iva<<endl;
    cout<<"     total: "<<p.total<<endl;
};
//#####################################################
void listar_registros(){
    //fstream e("ok.txt",ios::out | ios::in | ios::binary);  //con fstream  declaramos variable string
    fstream e("ok.txt");
    factura aux;
    e.read((char*)&aux,sizeof(factura));
    //mostrar(aux);
    while (!e.eof()){
        //mostrar(aux);
        e.read((char*)&aux,sizeof(factura));
        mostrar(aux);
    }
        e.close();
}
//######################################################
int buscar_registro(){
    factura pp;
    long numx;
    cout<<numx<<"ingrese cedula"<<endl;
    cin>>pp.cedula;
    if (pp.cedula==0){
        cout<<"no existe registro"<<endl;
    }
    else{
        fstream e("ok.txt");
        e.seekg((pp.cedula-1)*sizeof(factura));  // seekg   posicion de lectura y sizeof es el tamaño de la estructura
        //mostrar(pp);
        e.read((char*)&pp,sizeof(factura));   // pp.cedula
        e.close();
        mostrar(pp);
    }
    return 0;
}
//###############################
int main(){
    int x=0;
    do{
        x=menu();
        switch (x)
        {
        case 1:
            agregar_registro();
            break;
        case 2:
            listar_registros();
            //mostrar();
            break;
        case 3:
            buscar_registro();
            break;
        default:
            break;
        }
    }
    while (x!=4);
    return 0;
};
