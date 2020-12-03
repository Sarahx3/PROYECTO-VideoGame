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
    cout<<endl;
    cout<< left;
    cout<< setw(10)<< "Nombre";
    cout<< setw(5)<<"Edad";
    cout<< setw(12)<<"Genero";
    cout<< setw(10)<<"Salud";
    cout<<endl;
    cout<< internal;
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout  << *it << endl;
    }
}

void Civilizacion::eliminarNombre(const string &nombre){
    int x = 0;
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;

        if(nombre == a.getNombre()){
            aldeanos.erase(it);
            x = 1;
            break;
        }
    }
    if(x == 0){
        cout<<"aldeano no valido para eliminar"<<endl;
    }
}

void Civilizacion::eliminarSalud(size_t x){
    aldeanos.remove_if([x](const Aldeano &a){ return a.getSalud() < x;});
}

void Civilizacion::eliminarEdad(){
    aldeanos.remove_if([](const Aldeano &a){ return a.getEdad() >= 60;});
}

void Civilizacion::ordenarNombre(){
    aldeanos.sort();
}

void Civilizacion::ordenarEdad(){
    aldeanos.sort([](const Aldeano &a1,const Aldeano &a2){
        return a1.getEdad() > a2.getEdad();
    });
}

void Civilizacion::ordenarSalud(){
    aldeanos.sort([](const Aldeano &a1,const Aldeano &a2){
        return a1.getSalud() > a2.getSalud();
    });
}

Aldeano* Civilizacion::buscar(const Aldeano &c){
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;

        if(c.getNombre() == a.getNombre()){
            return &(*it);
        }
    }
    return nullptr;
}

void Civilizacion::respaldar_aldeanos()
{
    ofstream aldeanos (getNombre() + ".txt", ios::out);
    
    for (auto it = this->aldeanos.begin(); it != this->aldeanos.end(); ++it) {
        Aldeano &aldeano = *it; 
        aldeanos << aldeano.getNombre() << endl;
        aldeanos << aldeano.getEdad()   << endl;
        aldeanos << aldeano.getGenero() << endl;
        aldeanos << aldeano.getSalud()  << endl;
    }
    aldeanos.close();
}

void Civilizacion::recuperar_aldeanos(string civ){
    ifstream archivo (civ);
    if(archivo.is_open()){
        string temp;
        size_t edad;
        float salud;
        string aux;
        Aldeano a;
        while(true){
            getline(archivo,temp);//nombre
            if(archivo.eof()){
                break;
            }
            aux = temp;
            a.setNombre(aux);

            getline(archivo,temp);//edad
            edad =stoi(temp);
            a.setEdad(edad);

            getline(archivo,temp);//genero
            aux = temp;
            a.setGenero(aux);

            getline(archivo,temp);//salud
            salud = stof(temp);
            a.setSalud(salud);

            agregarFinal(a);

        }
    }
    archivo.close();
}