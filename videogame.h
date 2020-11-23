#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <fstream>
#include <vector>
#include <algorithm>

#include "civilizacion.h"

class VideoGame{
    private:
    string usuario;
    vector<Civilizacion> civilizaciones;

    public:

    void setUsuario(const string &v);
    string getUsuario();

    size_t size();
    void mostrar();
    void agregar(const Civilizacion &c);
    void insertar(const Civilizacion &c, size_t pos);

    void inicializar(const Civilizacion &c, size_t n);
    Civilizacion front();
    Civilizacion back();
    
    void ordenarNombre();
    void ordenarX();
    void ordenarY();
    void ordenarPuntuacion();

    void eliminar(const Civilizacion &c);

};

#endif //VIDEOGAME_H