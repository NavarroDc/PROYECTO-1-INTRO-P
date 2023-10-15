// David Navarro Camacho-305490874
// Introducción a la programación
// Proyecto 1: Cuenta Vocales
// Prof:Klever Picado Rivera

#include <iostream>
#include <limits>
#include <string>
#include <algorithm>

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

    // Todas las frases agregadas.
    string fraseDeUsuarioTotal;
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
        if(opcionErronea) {
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

                    bool continuarAgregando = true;
                    do {
                        string fraseUsuario;
                        cout <<" "<<endl;
                        cout <<"Escriba una frase que tenga menos de 100 caracteres"<<endl;
                        cin.ignore();
                        std::getline(std::cin, fraseUsuario);
                        cout <<" "<<endl;
                        cout <<"¿Desea regresar al menú principal? (S/N)"<<endl;
                        string respuestaUsuario = "";
                        cin>>respuestaUsuario;
                        // Preguntar si se desea regresar al menu principal.
                        if (respuestaUsuario == "S" || respuestaUsuario == "s" ){
                            continuarAgregando = false;
                        }
                        fraseDeUsuarioTotal.append(fraseUsuario);

                    } while (continuarAgregando);
                    cout << "La frase total registradsa es: " << fraseDeUsuarioTotal << endl;
                    break;
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

