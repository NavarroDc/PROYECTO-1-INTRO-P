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
int contadorVocales(string miFrase) {
  int contadorVocales = 0;
  for (int i = 0; i < miFrase.length(); i++) {
    int caracterCode = int(miFrase[i]);
    switch (caracterCode) {
    /* Se está utilizando la table de ASCII code para
    representar las vocales con sus respectivos valores numéricos.
    */
    case 97:  //a
    case 160: //á
    case 65:  //A
    case 181: //Á
    //
    case 101: //e
    case 130: //é
    case 69:  //E
    case 141: //É
    //
    case 105: //i
    case 161: //í
    case 73:  //I
    case 214: //Í
    //
    case 111: //o
    case 162: //ó
    case 79:  //O
    case 224: //Ó
              //
    case 117: //u
    case 163: //ú
    case 124: //ü
    case 85:  //U
    case 233: //Ú
    case 154: /* Ü */ {contadorVocales++;}
    default: {}
    }
  }
  return contadorVocales;
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
    // definir e inicializar contador de frases final
    int contadorFrasesTotal = 0;
    //variable para contar las vocales de todas las frases
    int contadorVocalesGeneral = 0;
    //Variable para guardar la última frase que ingresó el usuario
    string ultimaFraseRegistrada;
    //Variable para verificar si el usuario quiere regresar al menú principal
    string respuestaUsuario;
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

        //validar
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
                        bool fraseInValida = true;
                        do {
                            cout <<" "<<endl;
                            cout <<"Escriba una frase que tenga menos de 100 caracteres "<<endl;
                            cin.ignore();
                            std::getline(std::cin, fraseUsuario);
                            cout <<" "<<endl;
                            // Si la frase es menor o igual a 100 caracteres, deterner el loop
                            if (fraseUsuario.length() <= 100){
                                fraseInValida = false;
                            } else{
                                cout <<" "<<endl;
                                cout <<"Frase supera los 100 caracteres, digitar una frase de nuevo: "<<endl;
                            }

                        } while(fraseInValida); // Preguntar hasta que la frase sea No Inválida = Válida
                        cout <<"¿Desea regresar al menú principal? (S/N)"<<endl;
                        string respuestaUsuario;
                        cin>>respuestaUsuario;

                        // Preguntar hasta que sea una respuesta válida  S o N.
                        // La función compare retorna un entero, 0 cuando son iguales y
                        // diferente de cero cuando no son iguales.
                        while (respuestaUsuario.compare("s") != 0 &&
                               respuestaUsuario.compare("S") != 0 &&
                               respuestaUsuario.compare("N") != 0 &&
                               respuestaUsuario.compare("n") != 0 )
                        {
                            cout << " ";
                            cout << "Error, sólo deber digitar S o N." <<endl;
                            cout <<"¿Desea regresar al menú principal? (S/N)"<<endl;
                            cin>>respuestaUsuario;
                        }

                        // Validar si se desea regresar al menu principal.
                        if (respuestaUsuario.compare("S") == 0 || respuestaUsuario.compare("s") == 0 ){
                            continuarAgregando = false;
                        }
                        // desea seguir agregando
                        if (respuestaUsuario.compare("N") == 0 || respuestaUsuario.compare("n") == 0 ){
                            continuarAgregando = true;
                        }
                        // Agregar la frase registrada a la frase total.
                        fraseDeUsuarioTotal.append(fraseUsuario.append("\n"));
                        //Guarda la última frase del usuario
                        ultimaFraseRegistrada = fraseUsuario;
                        //Agrega un frase cada vez que el usuario ingrese una nueva
                        contadorFrasesTotal++;
                        //Cuenta las vocales de todas las frases ingresadas
                        contadorVocalesGeneral = contadorVocales(fraseDeUsuarioTotal);

                    } while (continuarAgregando); //Agregar frases hasta que el usuario no desee seguir agregando.
                    break;
                }
                case 2:{
                    bool continuar = true;
                    do{
                        //Mostrar Texto: última frase ingresada
                        cout <<"Texto(última frase agregada): "<< ultimaFraseRegistrada << endl;
                        //Cuántas vocales tiene esa última frase
                        int vocalesPorFrase = contadorVocales(ultimaFraseRegistrada);
                        //Mostrar la cantidad de vocales de la última frase
                        cout <<"Total general de vocales:  "<< vocalesPorFrase << endl;
                        //Preguntar si quiere regresar al menu principal
                        cout <<" "<<endl;
                        cout <<"¿Desea regresar al menú principal? (S/N)"<<endl;
                        string respuestaUsuario;
                        cin>>respuestaUsuario;
                        // Preguntar hasta que sea una respuesta válida  S o N.
                        // La función compare retorna un entero, 0 cuando son iguales y
                        // diferente de cero cuando no son iguales.
                        while(respuestaUsuario.compare("s") != 0 &&
                              respuestaUsuario.compare("S") != 0 &&
                              respuestaUsuario.compare("N") != 0 &&
                              respuestaUsuario.compare("n") != 0){
                            //Lo que debe mostrar si la respuesta no es S o N
                            cout << " ";
                            cout << "Error, sólo deber digitar S o N." <<endl;
                            cout <<"¿Desea regresar al menú principal? (S/N)"<<endl;
                            cin>>respuestaUsuario;
                        }
                        // sale del while cuando es una respuesta valida
                        if (respuestaUsuario.compare("S") == 0 || respuestaUsuario.compare("s") == 0 ){
                            continuar = false;
                        }
                    }while (continuar);
                    break; // contiunue ejecutando el caso tres.
                }

                case 3:{
                    bool continuar = true;
                    do {
                        // imprimir los resultados
                        cout << "\n Total de frases analizadas: "
                            << contadorFrasesTotal
                            << "\n Total de vocales contabilizadas:"
                            << contadorVocalesGeneral
                            << endl;

                        cout <<" "<<endl;
                        cout <<"¿Desea regresar al menú principal? (S/N)"<<endl;
                        string respuestaUsuario;
                        cin>>respuestaUsuario;
                        // Preguntar hasta que sea una respuesta válida  S o N.
                        // La función compare retorna un entero, 0 cuando son iguales y
                        // diferente de cero cuando no son iguales.
                        while(respuestaUsuario.compare("s") != 0 &&
                              respuestaUsuario.compare("S") != 0 &&
                              respuestaUsuario.compare("N") != 0 &&
                              respuestaUsuario.compare("n") != 0){
                            //Lo que debe mostrar si la respuesta no es S o N
                            cout << " ";
                            cout << "Error, sólo deber digitar S o N." <<endl;
                            cout <<"¿Desea regresar al menú principal? (S/N)"<<endl;
                            cin>>respuestaUsuario;
                        }
                        // sale del while cuando es una respuesta valida
                        if (respuestaUsuario.compare("S") == 0 || respuestaUsuario.compare("s") == 0 ){
                            continuar = false;
                        }
                    } while (continuar);
                    break;
                }

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

