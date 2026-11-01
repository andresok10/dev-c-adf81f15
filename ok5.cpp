#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;
// qqq   www   eee  02
struct persona{
    char nombre[20]="";
    char apellido1[20]="";
    char apellido2[20]="";
    long cedula=0;
};
int menu(){
    int x=0;
    cout<<"1 .Agregar"<<endl;
    cout<<"2 .listar"<<endl;
    cout<<"3 .buscar"<<endl;
    //cout<<"4 .eliminar"<<endl;
    cout<<"5 .modificar"<<endl;
    cout<<"6 .salir"<<endl;
    cout<<"opcion   ";
    cin>>x;
    return x;
};
//################################
string getstring(string msg){
    string m;
    cout<<msg<<endl;
    getline(cin,m);
    return m;
}

long getlong(string msg){
    long m;
    cout<<msg<<endl;
    cin>>m;
    return m;
}

persona getpersona(long cedulax){
    //fstream e("ok.txt",ios::out | ios::in | ios::binary);
    fstream e("ok.txt");
    persona aux;
    if(e.is_open()){
        e.seekg((cedulax-1)*sizeof(persona));
        e.read((char*)&aux,sizeof(persona));
        e.close();
    }
    return aux;
}
//################################################
void agregar_registro(){
    persona p;
    cin.ignore();
    //strcpy(p.nombre,"juan");
    strcpy(p.nombre,getstring("imgrese nombre").c_str());
    strcpy(p.apellido1,getstring("imgrese apellido1").c_str());
    strcpy(p.apellido2,getstring("imgrese apellido2").c_str());
    p.cedula=getlong("ingrese # cedula");
    persona aux=getpersona(p.cedula);
    if(aux.cedula!=0){
        cout<<"registro ya existe"<<endl;
    }
    else{
        //fstream e("ok.txt",ios::out | ios::in | ios::binary);
        fstream e("ok.txt");
        if(e.is_open()){
            e.seekp((p.cedula-1)*sizeof(persona));
            e.write((char*)&p,sizeof(persona));
            e.close();
    }
    }
}
//################################################
void mostrar(persona p){
    cout<<"nombre: "<<p.nombre<<endl;
    cout<<"apellido1: "<<p.apellido1<<endl;
    cout<<"apellido2: "<<p.apellido2<<endl;
    cout<<"cedula: "<<p.cedula<<endl;
}
//#####################################################
void listar_registros(){
    //fstream e("ok.txt",ios::out | ios::in | ios::binary);  //con fstream  declaramos variable string
    fstream e("ok.txt");
    persona aux;
    if(e.is_open()){
        e.read((char*)&aux,sizeof(persona));
        while (!e.eof()){
            mostrar(aux);
            e.read((char*)&aux,sizeof(persona));
        }
        e.close();
    }
}
//##########################################################
void buscar_registro(){
    int long ced=getlong("digite # cedula");
    persona aux=getpersona(ced);
    if (aux.cedula==0){
        cout<<"no existe registro"<<endl;
    }
    else{
        mostrar(aux);
        }
}

void eliminar_registro(){

}

void modificar_registro(){
    
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
            break;
        case 3:
            buscar_registro();
            break;
        //case 4:
        //    eliminar_registro();
        //    break;
        //case 4:
        //    modificar_registro();
        //    break;
        
        default:
            break;
        }
    }
    while (x!=5);
    return 0;
};
