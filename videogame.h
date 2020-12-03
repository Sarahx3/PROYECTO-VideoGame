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
    size_t total;

    public:
    VideoGame();

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
    Civilizacion* buscar(const Civilizacion &c);
    size_t Total();

    void respaldar();
    void recuperar();

};

#endif //VIDEOGAME_H