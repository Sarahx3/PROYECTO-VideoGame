#include "videogame.h"

VideoGame::VideoGame() : total(0){}

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
    cout<<endl;
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
    total++;
}

void VideoGame::insertar(const Civilizacion &c, size_t pos){
    civilizaciones.insert(civilizaciones.begin()+pos, c);
    total++;
}

void VideoGame::inicializar(const Civilizacion &c, size_t n){
    civilizaciones = vector<Civilizacion>(n,c);
    total= n;
}

Civilizacion VideoGame::front(){
    return civilizaciones.front();
}

Civilizacion VideoGame::back(){
    return civilizaciones.back();
}

void VideoGame::ordenarNombre(){
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){
        return c1.getNombre() < c2.getNombre();
    });
}

void VideoGame::ordenarX(){
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){
        return c1.getUbicacionX() < c2.getUbicacionX();
    });
}

void VideoGame::ordenarY(){
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){
        return c1.getUbicacionY() < c2.getUbicacionY();
    });
}

void VideoGame::ordenarPuntuacion(){//descendente
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){
        return c1.getPuntuacion() > c2.getPuntuacion();
    });
}

void VideoGame::eliminar(const Civilizacion &c){
    auto it = find(civilizaciones.begin(), civilizaciones.end(),c);

    if (it == civilizaciones.end()){
        cout<<"civilizacion no valida para eliminar"<<endl;
    }
    else{
        civilizaciones.erase(it);
        total--;
    }
    
}

Civilizacion* VideoGame::buscar(const Civilizacion &c){
    auto it = find(civilizaciones.begin(),civilizaciones.end(),c);

    if(it == civilizaciones.end()){
        return nullptr;
    }
    else{
        return &(*it);
    }
}

size_t VideoGame::Total(){
    return total;
}