#ifndef ALDEANO_H_INCLUDED
#define ALDEANO_H_INCLUDED

#include <iostream>
#include <iomanip>

using namespace std;

class Aldeano 
{
    private:
    string nombre;
    size_t edad;
    string genero;
    float salud;

    public:
    Aldeano() { }
    Aldeano(const string &nombre, size_t edad, string genero, float salud)
    : nombre(nombre), edad(edad), genero(genero), salud(salud) {}

    void setNombre(const string &nombre);
    void setEdad(const size_t &edad);
    void setGenero(const string &genero);
    void setSalud(const float &salud);

    string getNombre() const;
    size_t getEdad() const;
    string getGenero() const;
    float getSalud() const;

    friend ostream& operator<<(ostream &out, const Aldeano &a){
        out << left ; 
        out << setw(20) << a.nombre;
        out << setw(21) << a.edad;
        out << setw(15) << a.genero;
        out << setw(16) << a.salud;
        out << endl;
        return out;
    }

    friend istream& operator>>(istream &in, Aldeano &a){
        
        cout << "Nombre: ";
        getline(cin, a.nombre);
        
        cout << "Edad: ";
        cin >> a.edad;
        cin.ignore();

        cout << "Genero: ";
        getline(cin, a.genero);

        cout << "Salud: ";
        cin >> a.salud;

        return in;
    }

    bool operator==(const Aldeano& a)
    {
        return nombre == a.nombre;
    }

    bool operator==(const Aldeano& a) const
    {
        return nombre == a.nombre;
    }

    bool operator<(const Aldeano& a)
    {
        return nombre < a.nombre;
    }

    bool operator<(const Aldeano& a) const
    {
        return nombre < a.nombre;
    }

};

#endif //ALDEANO_H_INCLUDED