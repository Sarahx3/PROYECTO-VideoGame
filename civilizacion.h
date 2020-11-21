#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>

using namespace std;

class Civilizacion{
private:
    string nombre;
    double ubicacionX;
    double ubicacionY;
    float puntuacion;
public:
    Civilizacion();
    Civilizacion(const string &nombre,
                 double ubicacionX,
                 double ubicacionY,
                 float puntuacion);

    void setNombre(const string &v);
    void setUbicacionX(double v);
    void setUbicacionY(double v);
    void setPuntuacion(float v);

    string getNombre();
    double getUbicacionX();
    double getUbicacionY();
    float getPuntuacion();

    friend ostream& operator <<(ostream &out, const Civilizacion &c){
        out<< left;
        out<<setw(12)<<c.nombre;
        out<<setw(12)<<c.ubicacionX;
        out<<setw(12)<<c.ubicacionY;
        out<<setw(12)<<c.puntuacion;
        cout<<endl;
        return out;
    }

    friend istream& operator >>(istream &in, Civilizacion &c){
        cout<<"Nombre: ";
        getline(cin,c.nombre);
        cout<<"Ubicacion en X: ";
        cin>>c.ubicacionX;
        cout<<"Ubicacion en Y: ";
        cin>>c.ubicacionY;
        cout<<"Puntuacion: ";
        cin>>c.puntuacion;
        return in;
    }

    //pueden faltar operator ==, ojo aqui

};
#endif