#include <iostream>
#include "videogame.h"
using namespace std;

int main()
{
    VideoGame game;
    Civilizacion civil;
    Civilizacion aux;
    Civilizacion aux1;
    string str;
    cin >> civil;
    
    cout<<game.Total()<<endl;
    game.setUsuario("aide");


    // cout<<endl;
    // cout<< game.getUsuario() << endl;
    // cout<< civil.getNombre() << endl;
    // cout<< civil.getUbicacionX() << endl;
    // cout<< civil.getUbicacionY() << endl;
    // cout<< civil.getPuntuacion() << endl;

    game.agregar(civil);cin.ignore();
    cout<<game.Total()<<endl;
    game.mostrar();

    Civilizacion civil1;
    cin >> civil1;

    game.insertar(civil1,1);
    cout<<game.Total()<<endl;
    game.mostrar();

    cout<<endl;
    cout<< "primera\n" << game.front();
    cout<< "ultima\n" << game.back();

    game.ordenarX();
    game.mostrar();
    // game.inicializar(civil,10);
    // game.mostrar();

    cout<<"civilizacion a eliminar: "<<endl;
    cin>> str;cin.ignore();
    aux.setNombre(str);
    game.eliminar(aux);
    cout<<game.Total()<<endl;
    game.mostrar();

    cout<<"civilizacion a buscar: ";
    cin>> aux1; cin.ignore();
    Civilizacion *ptr = game.buscar(aux1);

        if(ptr ==nullptr){
            cout << "no se encontro la civilizacion"<< endl;
        }
        else{
            cout<< *ptr << endl;
        }

    

    return 0;
}
