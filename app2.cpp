
#include <math.h>   //Librer�a que usar� para redondear numeros  (ceil)
#include <iomanip>  //Librer�a que usar� para hacer precisiones de decimales con setprecision
#include <locale.h> //Librer�a para poder poner "�" y acentos
#include <conio.h>  //Librer�a para poder usar el getch (pausa del sistema)
#include <iostream> //Librer�a principal de entrada y salida de datos
using namespace std;
// FUNCIONES -->
void ImpresionGuia(int cedula, float precioSinIVA, float IVA, float precioTotal)
{
    cout << fixed;
    cout << "\n\t\t\t              LOS DATOS DE SU FACTURA SON:";
    cout << "\n\t\t\t    ===================================================";
    cout << "\n\t\t\t     � C�DULA:                            " << cedula;
    cout << "\n\t\t\t     � MONTO A PAGAR (SIN IVA):           " << setprecision(2) << precioSinIVA;
    cout << "\n\t\t\t     � MONTO DEL IVA [ 12% ]:               " << setprecision(2) << IVA;
    cout << "\n\t\t\t     � MONTO TOTAL A PAGAR                " << setprecision(2) << precioTotal;
    cout << "\n\t\t\t    ===================================================";
}

float CalculoPrecioTotal(float precio, float IVA)
{
    // float precioTotal = 0.0;
    float precioTotal;
    precioTotal = precio + IVA;
    return precioTotal;
}

// FUNCI�N PARA CALCULAR EL IVA (NO VOID)(PAR�METROS)
float CalculoIVA(float precio)
{
    float IVA = 0.0;
    IVA = precio * 0.12;
    return IVA;
}

void IngresoDatos(int &cedula, float &precio)
{
    cout << "  Ingrese su n�mero de c�dula-> ";
    cin >> cedula;

    cout << "\a  ingrese precio -> ";
    cin >> precio;

    system("cls");
    while (cedula <= 0)
    {
        cout << "\a  ERROR: Ingres� una c�dula inv�lida. \n  Por favor vuelva a ingresar su c�dula -> ";
        cin >> cedula;
    }
    system("cls");
}

main()
{
    setlocale(LC_CTYPE, "Spanish"); // Definir el idioma con el que voy a escribir para poder poner "�" y acentos
    // system("color f");				// Cambio de color de las letras del texto en la consola
    cout << fixed; // Para que sirva el setprecision
    // Variables
    int cedula;
    int auxIVA;
    float precio = 0.0, IVA = 0.0, precioTotal = precio;

    cout << "BIENVENIDOS AL SISTEMA DE FACTURACI�N DE 'TuEnv�oExpress C.A'"<<endl;
    //getch();
    //system("cls");
    IngresoDatos(cedula, precio);
    IVA = CalculoIVA(precio);
    precioTotal = CalculoPrecioTotal(precio, IVA);
    cout << "\n\t\t\t Se proceder� a imprimir su gu�a para su encomienda. Pulse una tecla...";
    getch();
    system("cls");

    ImpresionGuia(cedula, precio, IVA, precioTotal);
    getch();
    system("pause");
    return 0;
}
