#include <iostream>
#include <fstream>   //
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;
//Integer (whole number without decimals)
// qqq   www   eee  02
/*struct factura{
    int cedula;
    string cliente;
    string producto;
    double precio_unitario;
    int cantidad;
    double iva;
    double total;
};*/
struct factura{
    //long cedula=0;
    int cedula;
    char cliente[20]="";
    char producto[20]="";
    double precio_unitario=0.00;
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
    int precio;
    double ivax;
    cout<<"ingrese cedula"<<endl;
    cin>>p.cedula;
    cout<<"ingrese cliente"<<endl;
    cin>>p.cliente;
    cout<<"ingrese producto"<<endl;
    cin>>p.producto;
    cout<<"ingrese precio"<<endl;
    cin>>p.precio_unitario;
    cout<<"ingrese cantidad"<<endl;
    cin>>p.cantidad;
    precio=p.precio_unitario*p.cantidad;
    p.iva=0.12;
    ivax=precio*p.iva;
    p.iva=ivax;
    p.total=precio+p.iva;
    fstream e("facturax.txt");
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
    fstream e("facturax.txt");
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
        fstream e("facturax.txt");
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
