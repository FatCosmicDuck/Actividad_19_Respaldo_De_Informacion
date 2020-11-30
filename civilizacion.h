#ifndef CIVILIZACION_H_INCLUDED
#define CIVILIZACION_H_INCLUDED

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <list>

#include "aldeano.h"

using namespace std;

class Civilizacion
{
    private:
    string nombre;
    int ubicacionEnX;
    int ubicacionEnY;
    float puntuacion;
    list<Aldeano> aldeanos;

    public:
    Civilizacion();
    Civilizacion(const string &nombre, int &ubicacionEnX, int ubicacionEnY, float puntuacion);
    
    void setNombre(const string &c);
    void setUbicacionEnX(const int &c);
    void setUbicacionEnY(const int &c);
    void setPuntuacion(const float &c);

    string getNombre();
    int getUbicacionEnX();
    int getUbicacionEnY();
    float getPuntuacion();

    string getNombre() const;
    int getUbicacionEnX() const;
    int getUbicacionEnY() const;
    float getPuntuacion() const;

    void agregarFinal(const Aldeano &a);
    void agregarInicio(const Aldeano &a);

    void imprimir();
    size_t size();

    void eliminarNombre(const string &nombre);
    void eliminarEdad();
    void eliminarSalud(float salud);

    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();

    Aldeano* buscar(const Aldeano &a);

    void respaldarAldeanos();
    void recuperarAldeanos();

    friend ostream& operator<<(ostream &out, const Civilizacion &c){
        out << left ; 
        out << setw(20) << c.nombre;
        out << setw(21) << c.ubicacionEnX;
        out << setw(15) << c.ubicacionEnY;
        out << setw(16) << c.puntuacion;
        out << endl;
        return out;
    }

    friend istream& operator>>(istream &in, Civilizacion &c){
        
        cout << "Nombre: ";
        getline(cin, c.nombre);
        
        cout << "Ubicacion en X: ";
        cin >> c.ubicacionEnX;

        cout << "Ubicacion en Y: ";
        cin >> c.ubicacionEnY;

        cout << "Puntuacion: ";
        cin >> c.puntuacion;

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

    bool operator<(const Civilizacion& c)
    {
        return nombre < c.nombre;
    }

    bool operator<(const Civilizacion& c) const
    {
        return nombre < c.nombre;
    }
};

#endif //CIVILIZACION_H_INCLUDED