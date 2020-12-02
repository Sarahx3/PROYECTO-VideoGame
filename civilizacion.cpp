#include "civilizacion.h"

using namespace std;

Civilizacion::Civilizacion(){}

Civilizacion::Civilizacion(const string &nombre,
                 double ubicacionX,
                 double ubicacionY,
                 float puntuacion){
    this->nombre = nombre;
    this->ubicacionX = ubicacionX;
    this->ubicacionY = ubicacionY;
    this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &v){
    nombre = v;
}
void Civilizacion::setUbicacionX(double v){
    ubicacionX = v;
}
void Civilizacion::setUbicacionY(double v){
    ubicacionY = v;
}
void Civilizacion::setPuntuacion(float v){
    puntuacion = v;
}

string Civilizacion::getNombre(){
    return nombre;
}
double Civilizacion::getUbicacionX(){
    return ubicacionX;
}
double Civilizacion::getUbicacionY(){
    return ubicacionY;
}
float Civilizacion::getPuntuacion(){
    return puntuacion;
}

void Civilizacion::agregarInicio(const Aldeano &a){
    aldeanos.push_front(a);
    puntuacion+=100;
}

void Civilizacion::agregarFinal(const Aldeano &a){
    aldeanos.push_back(a);
    puntuacion+=100;
}

void Civilizacion::mostrarAldeanos(){
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout  << *it << endl;
    }
}