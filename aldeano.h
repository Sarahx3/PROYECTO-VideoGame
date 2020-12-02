#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <iomanip>
using namespace std;

class Aldeano{
    private:
    string nombre;
    size_t edad;
    string genero;
    float salud;

    public:
    Aldeano();
    Aldeano(const string nombre,size_t edad,const string genero, float salud) :
    nombre(nombre), edad(edad),genero(genero),salud(salud){}

    void setNombre(const string &nombre);
    void setEdad(size_t edad);
    void setGenero(const string &genero);
    void setSalud(size_t salud);

    string getNombre() const;
    size_t getEdad() const;
    string getGenero() const;
    float getSalud() const;

    bool operator<(const Aldeano &a) const{
        return nombre < a.getNombre();
    }

    friend ostream& operator<<(ostream &out, const Aldeano &a){
        out << left;
        out << setw(10) << a.nombre;
        out << setw(5) << a.edad;
        out << setw(12) << a.genero;
        out << setw(10) << a.salud;

        return out;
    }
};

#endif 