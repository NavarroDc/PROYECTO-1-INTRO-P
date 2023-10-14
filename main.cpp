// David Navarro Camacho-305490874
// Introducción a la programación
// Proyecto 1: Cuenta Vocales
// Prof:Klever Picado Rivera

#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

void esperarYLimpiar() {
    system("Pause");
    system("CLS");
}


int main()
{
    // Imprimir tildes

    setlocale(LC_ALL,"");
    //
    bool salir = false;
    int seleccion = 0;
    do {
        cout <<"Cuenta Vocales"<<endl;
        cout <<" "<<endl;
        cout <<"1. Ingresar frase a trabajar"<<endl;
        cout <<"2. Contar vocales"<<endl;
        cout <<"3. Resultados"<<endl;
        cout <<"4. Salir del Programa"<<endl;
        cout <<" "<<endl;
        cout <<"Elija una opción"<<endl;
        cin >> seleccion;

        // validar
        //Condiciones, se ingresa una letra o el número está fuera del rango.
        bool opcionErronea = cin.bad() || !(seleccion >= 1 && seleccion <= 4);
        if(opcionErronea)
        {
           cout <<"Error, sólo puede escribir un número del 1 al 4."<<endl;
           cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(),'\n');

           esperarYLimpiar();
           // regresar al inicio
        }


        //ACCIONES SEGÚN CADA CASO---------------------------------------------------
        else{
            switch(seleccion) {
                case 1:{
                    char frase[100];
                    bool regresarMenu = false;

                    do {
                        cout <<" "<<endl;
                        cout <<"Escriba una frase que tenga menos de 100 caracteres."<<endl;
                        cin.getline(frase,100,'\n');

                        for(int i=0;i<=100;i++){

                        }






                    }while(!regresarMenu);
                }










             case 2:{ cout <<"op 2"<<endl; break;}





             case 3:{ cout <<"op 3"<<endl; break;}





             case 4:{
                 cout <<"Salir del Programa" <<endl;
                 salir = true;
                 break;
            }


             default:{cout <<"Error, sólo puede escribir un número del 1 al 4"<<endl;}
            }
            cout <<" " <<endl;
            esperarYLimpiar();
         }

    }while(!salir);

    return 0;
}
