// David Navarro Camacho-305490874
// Introducci�n a la programaci�n
// Proyecto 1: Cuenta Vocales
// Prof:Klever Picado Rivera

#include <iostream>
#include <limits>

using namespace std;

int main()
{
    // Imprimir tildes
    setlocale(LC_ALL,"");
    //
    bool salir = false;
    int seleccion;
    do
    {
        cout <<"Cuenta Vocales"<<endl;
        cout <<" "<<endl;
        cout <<"1. Ingresar frase a trabajar"<<endl;
        cout <<"2. Contar vocales"<<endl;
        cout <<"3. Resultados"<<endl;
        cout <<"4. Salir del Programa"<<endl;
        cout <<" "<<endl;
        cout <<"Elija una opci�n"<<endl;
        cin >> seleccion;
        // validar
        //Condiciones, se ingresa una letra o el n�mero est� fuera del rango.
        if(cin.bad() || !(seleccion >= 1 && seleccion <= 4) )
        {
           cout <<"Error, s�lo puede escribir un n�mero del 1 al 4"<<endl;
           cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(),'\n');
           //system("Pause");
           system("CLS");
           // regresar al inicio
           break;
        }


        //ACCIONES SE�N CADA CASO---------------------------------------------------
        else{
            switch(seleccion)
            {
             case 1:{ cout <<"op 1"<<endl;
             }
             break;
             system("Pause");
             system("CLS");
             case 2:{ cout <<"op 2"<<endl;
             }
             break;
             system("Pause");
             system("CLS");
             case 3:{ cout <<"op 3"<<endl;
             }
             break;
             system("Pause");
             system("CLS");
             case 4:{ cout <<"op 4"<<endl;
             }
             break;
             system("Pause");
             system("CLS");
             default: cout <<"Error, s�lo puede escribir un n�mero del 1 al 4"<<endl;
             system("Pause");
             system("CLS");
            }
            }
}while(!salir);
    return 0;
}
