#ifndef VIDEOGAME_H_INCLUDED
#define VIDEOGAME_H_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "civilizacion.h"

#ifdef _WIN32
#define CLEAN_SCREEN "CLS"
#else
#define CLEAN_SCREEN "CLEAR"
#endif // _WIN32

using namespace std;

class VideoGame
{
    private:
    string usuario;
    vector<Civilizacion> civilizaciones;
    
    public:
    VideoGame();

    void setUsuario(string &u);
    string getUsuario();

    void agregarCivilizacion(const Civilizacion &c);
    void mostrar();

    void primeraCivilizacion();//
    void ultimaCivilizacion();//

    void insertar(const Civilizacion &c, size_t pos);
    size_t size();
    void inicializar(const Civilizacion &c, size_t n);
    void eliminar(const Civilizacion &c);
    void ordenarNombre();
    void ordenarUbicacionX();
    void ordenarUbicacionY();
    void ordenarPuntuacion();
    Civilizacion* buscar(const Civilizacion &c);
    void borrar_ultimo();

    void limpiarPantalla();
    void menuAldeanos(Civilizacion &c);
    Aldeano capturar();

    void respaldarCivilizaciones();
    void recuperarCivilizaciones();

    friend VideoGame& operator<<(VideoGame &l, const Civilizacion &c){
        l.agregarCivilizacion(c);
        return l;
    }

};

#endif //VIDEOGAME_H_INCLUDED