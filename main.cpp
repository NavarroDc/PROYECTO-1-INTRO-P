//David Navarro Camacho-305490874
//Introducci�n a la programaci�n
//Proyecto 1: Cuenta Vocales
//Prof:Klever Picado Rivera

#include <iostream>
#include <limits>

using namespace std;

int main()
{
    setlocale(LC_ALL,"");

    bool Salir = false;
    int Seleccion;

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
        cin >> Seleccion;







        if(!cin.good())
        {
           cout <<"Error, s�lo puede escribir un n�mero del 1 al 4"<<endl;
           cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(),'\n');

           system("Pause");
           system("CLS");
        }


//ACCIONES SE�N CADA CASO---------------------------------------------------
        else{
            switch(Seleccion)

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






}while(!Salir);







    return 0;
}
