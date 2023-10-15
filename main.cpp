// David Navarro Camacho-305490874
// Introducci�n a la programaci�n
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
    /* Se est� utilizando la table de ASCII code para
    representar las vocales con sus respectivos valores num�ricos.
    */
    case 97:  //a
    case 160: //�
    case 65:  //A
    case 181: //�
    //
    case 101: //e
    case 130: //�
    case 69:  //E
    case 141: //�
    //
    case 105: //i
    case 161: //�
    case 73:  //I
    case 214: //�
    //
    case 111: //o
    case 162: //�
    case 79:  //O
    case 224: //�
              //
    case 117: //u
    case 163: //�
    case 124: //�
    case 85:  //U
    case 233: //�
    case 154: /* � */ {contadorVocales++;}
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
    //Variable para guardar la �ltima frase que ingres� el usuario
    string ultimaFraseRegistrada;
    do {
        cout <<"Cuenta Vocales"<<endl;
        cout <<" "<<endl;
        cout <<"1. Ingresar frase a trabajar"<<endl;
        cout <<"2. Contar vocales"<<endl;
        cout <<"3. Resultados"<<endl;
        cout <<"4. Salir del Programa"<<endl;
        cout <<" "<<endl;
        cout <<"Elija una opci�n"<<endl;
        cin >> seleccion;

        //validar
        //Condiciones, se ingresa una letra o el n�mero est� fuera del rango.
        bool opcionErronea = cin.bad() || !(seleccion >= 1 && seleccion <= 4);
        if(opcionErronea) {
           cout <<"Error, s�lo puede escribir un n�mero del 1 al 4."<<endl;
           cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(),'\n');

           esperarYLimpiar();
           // regresar al inicio
        }


        //ACCIONES SEG�N CADA CASO---------------------------------------------------
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
                        cout <<"�Desea regresar al men� principal? (S/N)"<<endl;
                        string respuestaUsuario;
                        cin>>respuestaUsuario;

                        // Preguntar hasta que sea una respuesta v�lida  S o N.
                        // La funci�n compare retorna un entero, 0 cuando son iguales y
                        // diferente de cero cuando no son iguales.
                        while (respuestaUsuario.compare("s") != 0 &&
                               respuestaUsuario.compare("S") != 0 &&
                               respuestaUsuario.compare("N") != 0 &&
                               respuestaUsuario.compare("n") != 0 )
                        {
                            cout << " ";
                            cout << "Error, s�lo deber digitar S o N." <<endl;
                            cout <<"�Desea regresar al men� principal? (S/N)"<<endl;
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
                        //Guarda la �ltima frase del usuario
                        ultimaFraseRegistrada = fraseUsuario;
                        //Agrega un frase cada vez que el usuario ingrese una nueva
                        contadorFrasesTotal++;
                        //Cuenta las vocales de todas las frases ingresadas
                        contadorVocalesGeneral = contadorVocales(fraseDeUsuarioTotal);

                    } while (continuarAgregando); //Agregar frases hasta que el usuario no desee seguir agregando.

                    //muestra frase y el contador en numero (mientras)
                    cout << "La frase total registradsa es: \n "
                        << fraseDeUsuarioTotal
                        << "\n Total de frases analizadas: "
                        << contadorFrasesTotal
                        << "\n Total de vocales contabilizadas:"
                        << contadorVocalesGeneral
                        << endl;
                    break;
                }
                case 2:{ cout <<"op 2"<<endl; break;}
                case 3:{ cout <<"op 3"<<endl; break;}
                case 4:{
                    cout <<"Salir del Programa" <<endl;
                    salir = true;
                    break;
                }
                default:{cout <<"Error, s�lo puede escribir un n�mero del 1 al 4"<<endl;}
            }
            cout <<" " <<endl;
            esperarYLimpiar();
         }
        }while(!salir);
    return 0;
}

