#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>
#include <list>
#include "aldeano.h"

using namespace std;

class Civilizacion{
private:
    string nombre;
    double ubicacionX;
    double ubicacionY;
    float puntuacion;

    list<Aldeano> aldeanos;

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

    //agregar
    void agregarInicio(const Aldeano &a);
    void agregarFinal(const Aldeano &a);
    void mostrarAldeanos();
    
    //eliminar
    void eliminarNombre(const string &nombre);
    void eliminarSalud(size_t x);
    void eliminarEdad();

    //ordenar
    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();

    Aldeano* buscar(const Aldeano &c);

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

    bool operator==(const Civilizacion& c)
    {
        return nombre == c.nombre;
    }
    bool operator==(const Civilizacion& c) const
    {
        return nombre == c.nombre;
    }

};
#endif