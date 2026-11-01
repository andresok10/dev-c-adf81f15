// entrada y salida de datos
#include <iostream>    // input y output     entrada y salida de datos
using namespace std;
int mainx1(){
    //std::cout << "/* message */" << std::endl;
    cout << " message " << endl;   // endl es para dar salto de linea
    return 0;
};
//####################
int mainx2(){
    int numero = 15;
    cout<<numero;
    return 0;
};

int mainx3(){
    int numero;
    cout<<"digite un numero: ";
    cin>>numero;
    cout<<"el numero que ingreso es :"<<numero;
    return 0;
};
//  tipos de datos
// int- almacena enteros (números enteros), sin decimales, como 123 o -123
// double- almacena números de coma flotante, con decimales, como 19.99 o -19.99
// char- almacena caracteres individuales, como 'a' o 'B'. Los valores de char están entre comillas simples
// string- almacena texto, como "Hello World". Los valores de cadena están entre comillas dobles
// bool- almacena valores con dos estados: verdadero o falso

// int myNum = 5;               // Integer (whole number without decimals)
// double myFloatNum = 5.99;    // Floating point number (with decimals)
// char myLetter = 'D';         // Character
// string myText = "Hello";     // String (text)
// bool myBoolean = true;       // Boolean (true or false)
//########################################################
//    matematicas
int mainx4(){
    int n1,n2,suma=0;
    //int n1,n2;
    //string suma;
    cout<<"digite numero 1: ";cin>>n1;
    cout<<"digite numero 2: ";cin>>n2;
    suma=n1+n2;
    cout<<"la suma es :"<<suma;
    return 0;
};

int main(){
    float precio,iva,preciofinal;
    //float precio,iva;
    //double preciofinal;
    cout<<"digite precio del producto: ";
    cin>>precio;
    iva=precio*0.12;
    preciofinal=precio+iva;
    cout<<"el precio + iva es :"<<preciofinal;
    return 0;
};