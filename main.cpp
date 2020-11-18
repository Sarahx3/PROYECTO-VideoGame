#include <iostream>
#include "civilizacion.h"
using namespace std;

int main()
{
    Civilizacion civil;
    cin >> civil;

    cout<<endl;
    cout<< civil.getNombre()<<endl;
    cout<<civil.getUbicacionX()<<endl;
    cout<<civil.getUbicacionY()<<endl;
    cout<<civil.getPuntuacion()<<endl;

    return 0;
}
