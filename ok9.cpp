#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;
// qqq   www   eee  02
struct factura{
    long cedula;
    char cliente[20]="";
    char producto[20]="";
    //string cliente;
    //string producto;
    long precio_unitario=0;
    long iva=0;
    long total=precio_unitario*iva;
    //long total=0;
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
//double calcular_iva(double p){
//    double IVA;
//    IVA=p*0.12;
//    return IVA;
//}
//long ce;
int agregar_registro(){
    factura p;   //variables
    long num;
    string clientex,productox;
    cout<<num<<"ingrese cedula"<<endl;
    cin>>p.cedula;
    //getline(cin,p.cedula);
    cout<<clientex<<"ingrese cliente"<<endl;
    cin>>p.cliente;
    cout<<productox<<"ingrese producto"<<endl;
    cin>>p.producto;
    cout<<num<<"ingrese precio"<<endl;
    cin>>p.precio_unitario;
    fstream e("ok.txt");
    if(e.is_open()){
        e.seekp((p.cedula-1)*sizeof(factura));
        //e.write((char*)&p,sizeof(factura));
        e.write((char*)&p,sizeof(factura));
        e.close();
    }
    return 0;
}
//################################################
void mostrar(factura p){
    //factura p;
    cout<<"     cedula: "<<p.cedula<<endl;
    cout<<"     nombre: "<<p.cliente<<endl;
    cout<<"     producto: "<<p.producto<<endl;
    cout<<"     precio: "<<p.precio_unitario<<endl;
    //cout<<"     iva: "<<p.iva<<endl;
    //cout<<"     total: "<<p.total<<endl;
};
//#####################################################
void listar_registros(){
    //fstream e("ok.txt",ios::out | ios::in | ios::binary);  //con fstream  declaramos variable string
    fstream e("ok.txt");
    factura aux;
    if(e.is_open()){
        e.read((char*)&aux,sizeof(factura));
        while (!e.eof()){
            mostrar(aux);
            e.read((char*)&aux,sizeof(factura));
        }
        e.close();
    }
}
//##########################################################  xq le llamo factura ?
factura getfactura(long cedulax){
//int getfactura(long cedulax){
    //fstream e("ok.txt",ios::out | ios::in | ios::binary);
    fstream e("ok.txt");
    factura aux;
    //if(e.is_open()){     //si el archivo existe
    e.seekg((cedulax-1)*sizeof(factura));  // seekg   posicion de lectura y sizeof es el tamaño de la estructura
    e.read((char*)&aux,sizeof(factura));
    e.close();
    //}
    return aux;
    //return 0;
}

int buscar_registro(){
    long numx;
    cout<<numx<<"ingrese cedula"<<endl;
    cin>>numx;
    factura pp=getfactura(numx);
    if (pp.cedula==0){
        cout<<"no existe registro"<<endl;
    }
    else{
        mostrar(pp);
    }
    return 0;
}

//void eliminar_registro(){}
//void modificar_registro(){}
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
