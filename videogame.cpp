#include "videogame.h"

void VideoGame::setUsuario(const string &v){
    usuario = v;
}

string VideoGame::getUsuario(){
    return usuario;
}

size_t VideoGame::size(){
    return civilizaciones.size();
}

void VideoGame::mostrar(){
    cout<< left;
    cout<< setw(12)<< "Nombre";
    cout<< setw(12)<<"Ubicacion X";
    cout<< setw(12)<<"Ubicacion Y";
    cout<< setw(12)<<"Puntuacion";
    cout<<endl;
    cout<< internal;
    for(size_t i=0;i < civilizaciones.size(); i++){
        Civilizacion &c = civilizaciones[i];
        cout << c;
    }
}

void VideoGame::agregar(const Civilizacion &c){
    civilizaciones.push_back(c);
}

void VideoGame::insertar(const Civilizacion &c, size_t pos){
    civilizaciones.insert(civilizaciones.begin()+pos, c);
}

void VideoGame::inicializar(const Civilizacion &c, size_t n){
    civilizaciones = vector<Civilizacion>(n,c);
}

// void VideoGame::eliminar(const string &v){
//     civilizaciones.erase(v);
// }

Civilizacion VideoGame::front(){
    return civilizaciones.front();
}

Civilizacion VideoGame::back(){
    return civilizaciones.back();
}