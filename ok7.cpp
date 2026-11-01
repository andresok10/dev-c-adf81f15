#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
using namespace std;
int registrar(){
    int a=0;
    string b,c;
    cout<<"ingrese cedula"<<endl;
    cin>>a;
    cout<<"ingrese cliente"<<endl;
    cin>>b;
    cout<<"ingrese producto"<<endl;
    cin>>c;
    cout<<"ingrese precio"<<endl;
    cin>>a;
    //return 0;
    string s;
    ifstream f("ok.txt");
    if ( f.is_open() ) {
        getline( f, s );

    while( !f.eof() ) {
        cout << s << endl;
    getline( f, s );
    }
}
    //else cerr << "Error de apertura del archivo." << endl;
    return 0;
}
struct factura{
    long cedula=0;
    char cliente[20]="";
    char producto[20]="";
    char precio=0;
    
};
void mostrar(factura p){
    cout<<"     cedula: "<<p.cedula<<endl;
    cout<<"     nombre: "<<p.cliente<<endl;
    cout<<"     producto: "<<p.producto<<endl;
    cout<<"     precio: "<<p.precio<<endl;
    //cout<<"     iva: "<<p.iva<<endl;
    //cout<<"     total: "<<p.total<<endl;
}
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
//###############################

int menu(){
    int opcion;
    do{
        cout<<"1 .registrar"<<endl;
        cout<<"2 .Mostrar_factura"<<endl;
        cout<<"3 .buscar-factura-por-cedula"<<endl;
        cout<<"4 .salir"<<endl;
        cout<<"opcion   ";
        cin>>opcion;
    }while (opcion < 1 || opcion > 4);
    return opcion;
};
//################################
int main(){
    int repite=1;
    int opcion=-1;
    do
	{
		opcion = menu();
		switch(opcion)
		{
			case 1: 
				registrar();
				break;
			case 2:
				listar_registros();
				break;
			case 3:
				//completar algoritmo
				break;
			case 4:
				return 0;
		}	
		system("pause");
	}while(repite);
	
	return 0;
}
//##########################################################

//###############################
