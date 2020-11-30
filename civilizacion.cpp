#include "civilizacion.h"

Civilizacion::Civilizacion(){}

Civilizacion::Civilizacion(const string &nombre, int &ubicacionEnX, int ubicacionEnY, float puntuacion)
{
    this->nombre = nombre;
    this->ubicacionEnX = ubicacionEnX;
    this->ubicacionEnY = ubicacionEnY;
    this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &c)
{
    nombre = c;
}

void Civilizacion::setUbicacionEnX(const int &c)
{
    ubicacionEnX = c;
}

void Civilizacion::setUbicacionEnY(const int &c)
{
    ubicacionEnY = c;
}

void Civilizacion::setPuntuacion(const float &c)
{
    puntuacion = c;
}

string Civilizacion::getNombre()
{
    return nombre;
}

int Civilizacion::getUbicacionEnX()
{
    return ubicacionEnX;
}

int Civilizacion::getUbicacionEnY() 
{
    return ubicacionEnY;
}

float Civilizacion::getPuntuacion()
{
    return puntuacion;
}

void Civilizacion::agregarFinal(const Aldeano &a)
{
    aldeanos.push_back(a);
}

void Civilizacion::agregarInicio(const Aldeano &a)
{
    aldeanos.push_front(a);
}

void Civilizacion::imprimir()
{
    cout << left;
    cout << setw(19) << "Nombre";
    cout << setw(20) << "Edad";
    cout << setw(15) << "Genero";
    cout << setw(16) << "Salud";
    cout << endl;

    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout << *it << endl;
    }
}

size_t Civilizacion::size()
{
    return aldeanos.size();
}

void Civilizacion::eliminarNombre(const string &nombre)
{
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;

        if(nombre == a.getNombre()){
            aldeanos.erase(it);
            break;
        }
    }
}

bool comparador(const Aldeano &a)
{
    return a.getEdad() >= 60;
}

void Civilizacion::eliminarEdad()
{
    aldeanos.remove_if(comparador);
}

void Civilizacion::eliminarSalud(float salud)
{
    aldeanos.remove_if([salud](const Aldeano &a){ return a.getSalud() < salud;});
}

void Civilizacion::ordenarNombre()
{
    aldeanos.sort();
}

void Civilizacion::ordenarEdad()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getEdad() > a2.getEdad();});
}

void Civilizacion::ordenarSalud()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud() > a2.getSalud();});
}

Aldeano* Civilizacion::buscar(const Aldeano &a)
{
    list<Aldeano>::iterator it = find(aldeanos.begin(), aldeanos.end(), a);

    if(it == aldeanos.end()){
        return nullptr;
    }
    else{
        return &(*it);
    }
}

void Civilizacion::respaldarAldeanos()
{
    ofstream archivoAldeanos(getNombre() + ".txt", ios::out);
    
    if(archivoAldeanos.is_open()){

        for (auto it = aldeanos.begin(); it != aldeanos.end(); ++it){
            Aldeano &aldeano = *it; 
            archivoAldeanos << aldeano.getNombre() << endl;
            archivoAldeanos << aldeano.getEdad() << endl;
            archivoAldeanos << aldeano.getGenero() << endl;
            archivoAldeanos << aldeano.getSalud() << endl;
        }
    }
    archivoAldeanos.close();
}

void Civilizacion::recuperarAldeanos()
{
    ifstream archivoAldeanos(getNombre() + ".txt", ios::in);
        string tempString;
        int tempInt;
        float tempFloat;
        Aldeano aldeano;

        while(true){
            getline(archivoAldeanos, tempString); 
            if(archivoAldeanos.eof()){
                break;
            }
            aldeano.setNombre(tempString);

            getline(archivoAldeanos, tempString); 
            tempInt = stoi(tempString);
            aldeano.setEdad(tempInt);

            getline(archivoAldeanos, tempString);
            aldeano.setGenero(tempString);

            getline(archivoAldeanos, tempString); 
            tempFloat = stof(tempString);               
            aldeano.setSalud(tempFloat);

            agregarFinal(aldeano);

        }
    archivoAldeanos.close();
}