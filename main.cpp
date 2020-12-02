#include <iostream>
#include "videogame.h"
using namespace std;

int main()
{
    VideoGame game;
    string op;
    
    while (true){
        cout<<endl;
        cout << "1) Nombre de Usuario" << endl;//
        cout << "2) Agregar Civilizacion" << endl;//
        cout << "3) Insertar Civilizacion" << endl;//no me gusta
        cout << "4) Crear civilizaciones(inicializar)" << endl;//
        cout << "5) Primera Civilizacion" << endl;//
        cout << "6) Ultima Civilizacion" << endl;//
        cout << "7) Ordenar" << endl;//
        cout << "8) Eliminar" << endl;//
        cout << "9) Buscar" << endl;//
        cout << "10) Modificar" << endl;
        cout << "11) Resumen" << endl;//
        cout << "0) Salir" << endl;//
        cout << "Opcion: ";
        getline(cin, op);

        if (op == "1") {//usuario
            string str;
            cout<<"Nombre de Usuario: ";
            getline(cin,str);
            game.setUsuario(str);
        } 

        else if (op == "2") {//agregar
            Civilizacion c;
            cin >> c;
            game.agregar(c);
            cin.ignore();
        }

        else if (op == "3") {//insertar
            Civilizacion c;
            cin >> c;
            size_t pos;
            cout<< "Posicion: ";
            cin >> pos; cin.ignore();
            if( pos >= game.size()){
                cout<<"Posicion no valida"<<endl;
            }
            else{
                game.insertar(c,pos);
            }
        }

        else if (op == "4") {//inicializar
            Civilizacion c;
            cin >> c;

            size_t n;
            cout<< "n: ";
            cin >> n; cin.ignore();

            game.inicializar(c, n);
        }

        else if (op == "5") {//primera
            if(game.Total() > 0){
                cout << "Primera Civilizacion: "<<endl;
                cout << game.front();
            }
            else{
                cout << "Videojuego vacio" << endl;
            }
        }

        else if (op == "6") {//ultima
            if(game.Total() > 0){
                cout << "Ultima Civilizacion: "<<endl;
                cout << game.back();
            }
            else{
                cout << "Videojuego vacio" << endl;
            }
        }

        else if (op == "7") {//ordenar
            string opc;
            while(true){
                cout<< endl;
                cout<< "1) Nombre" << endl;
                cout<< "2) Posicion X" << endl;
                cout<< "3) Posicion Y" << endl;
                cout<< "4) Puntuacion" << endl;
                cout<< "0) Atras" << endl;
                cout << "Ordenar por:  ";
                getline(cin, opc);
                if (opc == "1"){
                    game.ordenarNombre();
                }
                else if(opc == "2"){
                    game.ordenarX();
                }
                else if(opc == "3"){
                    game.ordenarY();
                }
                else if(opc == "4"){
                    game.ordenarPuntuacion();
                }
                else if (opc == "0"){
                    break;
                }
            }
        }

        else if (op == "8") {//eliminar
            string str1;
            Civilizacion aux;

            cout<< "Civilizacion a eliminar: ";
            cin>> str1; cin.ignore();
            aux.setNombre(str1);
            game.eliminar(aux);
        }

        else if (op == "9"){//buscar
            string str2;
            Civilizacion aux;

            cout<< "Civilizacion a buscar: ";
            cin>> str2; cin.ignore();
            aux.setNombre(str2);

            Civilizacion *ptr = game.buscar(aux);
            if(ptr ==nullptr){
                cout << "no se encontro la civilizacion" << endl;
            }
            else{
                cout << endl;
                cout<<"Civilizacion encontrada: " << endl;
                cout<< *ptr << endl;
            }
        }

        else if (op == "10"){//modificar
            string str2;
            Civilizacion aux;

            cout<< "Civilizacion a modificar: ";
            cin>> str2; cin.ignore();
            aux.setNombre(str2);

            Civilizacion *ptr = game.buscar(aux);
            if(ptr ==nullptr){
                cout << "no se encontro la civilizacion" << endl;
            }
            else{
                cout << endl;
                cout<<"Civilizacion encontrada: " << endl;
                cout<< *ptr << endl;
                string mystr; float aux; double aux1;
                string opc;
                while(true){
                    cout<< endl;
                    cout<< "1) Nombre" << endl;
                    cout<< "2) Posicion X" << endl;
                    cout<< "3) Posicion Y" << endl;
                    cout<< "4) Puntuacion" << endl;
                    cout<< "0) Atras" << endl;
                    cout << "Modificar:  ";
                    getline(cin, opc);
                    if (opc == "1"){
                        cout <<"Nombre nuevo: ";
                        getline(cin,mystr);
                        ptr->setNombre(mystr);
                    }
                    else if(opc == "2"){
                        cout <<"Posicion X nueva: ";
                        cin >> aux; cin.ignore();
                        ptr->setUbicacionX(aux);
                    }
                    else if(opc == "3"){
                        cout <<"Posicion Y nueva: ";
                        cin >> aux; cin.ignore();
                        ptr->setUbicacionY(aux);
                    }
                    else if(opc == "4"){
                        cout <<"Puntuacion nueva: ";
                        cin >> aux1; cin.ignore();
                        ptr->setPuntuacion(aux1);
                    }
                    else if (opc == "0"){
                        break;
                    }
                }
            }
        }

        else if(op == "11"){//mostrar
            cout<< endl;
            cout<<"Nombre usuario: "<<game.getUsuario()<<endl;
            game.mostrar();
            cout<<"Total: "<<game.Total()<<endl;
        }

        else if (op == "0"){//salir
            break;
        }
    }

    return 0;
}
