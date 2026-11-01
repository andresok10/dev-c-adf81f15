#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;
// qqq   www   eee  02
struct factura{
    long cedula=0;
    //char nombre[50]="";
    //char producto[50]="";
    char nombre;
    char producto;
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
//#################################
factura getpersona(long cedulax){
    //fstream e("ok.txt",ios::out | ios::in | ios::binary);
    fstream e("ok.txt");
    factura aux;
    if(e.is_open()){
        e.seekg((cedulax-1)*sizeof(factura));  // seekg   posicion de lectura
        e.read((char*)&aux,sizeof(factura));
        e.close();
    }
    return aux;
}
//################################

//################################
//long getlong(string msg){
//    long m;
//    cout<<msg<<endl;
//    cin>>m;
//    return m;
//}
double getlong(string msg){
    double m;
    cout<<msg<<endl;
    cin>>m;
    return m;
}

string getstring(string msg){
    string m;
    cout<<msg<<endl;
    //getline(cin,m);
    cin>>m;
    return m;
}

long longx(int msg){
    long m;
    cout<<msg<<endl;
    cin>>m;
    return m;
}
//double calcular_iva(double p){
//    double IVA;
//    IVA=p*0.12;
//    return IVA;
//}

void agregar_registro(){
    factura p;   //variables
    string msg;
    //cin.ignore();
    //strcpy(p.nombre,"juan");
    p.cedula=getlong("ingrese # cedula");
    //strcpy(p.nombre,getstring("imgrese nombre").c_str());
    //strcpy(p.producto,getstring("imgrese producto").c_str());
    p.nombre,getline("imgrese nombre");
    p.producto,string("imgrese producto");
    p.precio_unitario=getlong("ingrese precio");
    //cin>>p.precio_unitario;
    p.iva=getlong("ingrese iva");
    //cin>>p.iva;
    //p.iva=0.19;
    //cin>>p.iva;
    //p.cedula=getlong("ingrese # cedula");
    //p.total=longx(p.total);
    //p.total=precio_unitario*iva;
    //double 
    //p.total=calcular_iva(p.precio_unitario);
    
    //int xx;
    //p.precio_unitario=int("ingrese precio");
    //p.cedula=int("ingrese # cedula");
    //cout <<xx<<" ingrese cedula "<< endl;
    //cin>>x;
    factura aux=getpersona(p.cedula);
    if(aux.cedula!=0){
        cout<<"registro ya existe"<<endl;
    }
    else{
        //fstream e("ok.txt",ios::out | ios::in | ios::binary);
        fstream e("ok.txt");
        if(e.is_open()){
            e.seekp((p.cedula-1)*sizeof(factura));
            e.write((char*)&p,sizeof(factura));
            e.close();
    }
    }
}
//################################################
void mostrar(factura p){
    cout<<"     cedula: "<<p.cedula<<endl;
    cout<<"     nombre: "<<p.nombre<<endl;
    cout<<"     producto: "<<p.producto<<endl;
    cout<<"     precio: "<<p.precio_unitario<<endl;
    cout<<"     iva: "<<p.iva<<endl;
    cout<<"     total: "<<p.total<<endl;
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
//##########################################################
void buscar_registro(){
    int long ced=getlong("digite # cedula");
    factura aux=getpersona(ced);
    if (aux.cedula==0){
        cout<<"no existe registro"<<endl;
    }
    else{
        mostrar(aux);
        }
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
