#include <iostream>
#include "videogame.h"
using namespace std;

int main()
{
    VideoGame game;
    Civilizacion civil;
    cin >> civil;

    game.setUsuario("aide");


    // cout<<endl;
    // cout<< game.getUsuario() << endl;
    // cout<< civil.getNombre() << endl;
    // cout<< civil.getUbicacionX() << endl;
    // cout<< civil.getUbicacionY() << endl;
    // cout<< civil.getPuntuacion() << endl;

    game.agregar(civil);cin.ignore();
    game.mostrar();

    Civilizacion civil1;
    cin >> civil1;

    game.insertar(civil1,1);
    game.mostrar();

    cout<<endl;
    cout<< "primera\n" << game.front();
    cout<< "ultima\n" << game.back();

    // game.inicializar(civil,10);
    // game.mostrar();
    return 0;
}
