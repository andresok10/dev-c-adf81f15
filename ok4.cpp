#include <iostream>
#include <fstream>
using namespace std; 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//--------------- DeclaraciÃ³n de los mÃ©todos de subtareas ------------------------------------
int cargarMenu();
//completar declaracion de las subtareas para cada opcion del menu

//completar declaracion de la subtarea para cargar todos los datos de facturas del fichero binario

//completar declaracion de la subtarea para salvar los datos de las nuevas facturas en el fichero binario

//--------------------- Programa principal --------------------------------------------------
int main(int argc, char** argv) 
{
	int opcion;
	//Completar la declaracion de las variables
	
	do
	{
		opcion = cargarMenu();
		switch(opcion)
		{
			case 1: 
			 cout<< "";
				break;
			case 2:
				//completar algoritmo
				break;
			case 3:
				//completar algoritmo
				break;
			case 4:
				return 0;
		}	
		system("pause");
	}while(true);
	
	return 0;
}
//---------------- ImplementaciÃ³n de los mÃ©todos de subtareas ---------------------------------
int cargarMenu()
{
	int opcion;
	do{
		system("cls");
		cout << "---- Menu Principal ----- \n";
		cout << "\t 1. Registrar los datos de una nueva factura. \n";
		cout << "\t 2. Mostrar los datos de todos las facturas. \n";
		cout << "\t 3. Mostrar el total facturado por un cliente conocida su cedula. \n";
		cout << "\t 4. Salir del programa. \n";
		cout << "Digite la opcion 1-4 deseada: ";
		cin >> opcion;
	}while(opcion < 1 || opcion > 4);
	
	return opcion;
}
