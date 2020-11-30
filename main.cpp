#include <iostream>
#include "videogame.h"

using namespace std;

int main() {
    VideoGame vg;
    string nombre;
    size_t op;
    int ubicacionEnX, ubicacionEnY;
    char subMenu;
    float puntuacion;

    do{

        cout << "+------------------------------------+" << endl;
        cout << "|         MENU CIVILIZACIONES        |" << endl;
        cout << "+------------------------------------+" << endl;
        cout << "Usuario: " << vg.getUsuario() << endl;
        cout << "______________________________________________" << endl;
        cout << "1.- Nombre de usuario          " << endl;
        cout << "2.- Agregar Civilizacion       " << endl;
        cout << "3.- Insertar                   " << endl;
        cout << "4.- Inicializar                " << endl;
        cout << "5.- Primera Civilizacion       " << endl;
        cout << "6.- Ultima Civilizacion        " << endl;
        cout << "7.- Ordenar por Nombre         " << endl;
        cout << "8.- Ordenar por Ubicacion en X " << endl;
        cout << "9.- Ordenar por Ubicacion en Y " << endl;
        cout << "10.- Ordenar por Puntuacion    " << endl;
        cout << "11.- Eliminar                  " << endl;
        cout << "12.- Buscar                    " << endl;
        cout << "13.- Modificar                 " << endl;
        cout << "14.- Mostrar                   " << endl;
        cout << "15.- Buscar y Modificar        " << endl;
        cout << "16.- Respaldar Registros       " << endl;
        cout << "17.- Recuperar Registros       " << endl;
        cout << "0.- Salir                      " << endl;
        cout << "Opcion: ";
        cin >> op;

        if(op != 0) {
            vg.limpiarPantalla();
        }

        cout << endl << endl;

        if(op == 1){
            cout << "Nombre de Usuario: ";
            getline(cin ,nombre);
            vg.setUsuario(nombre);
        }

        else if(op == 2){
            Civilizacion c;
            cin >> c;
            vg.agregarCivilizacion(c);
        }

        else if(op == 3){
            size_t pos;
            Civilizacion c;
            cin >> c;
            cout << "Dime la posicion: ";
            cin >> pos;

            if(pos >= vg.size()){
                cout << "Posicion invalida..." << endl;
            }
            else{
                vg.insertar(c, pos);
            }
        }

        else if(op == 4){
            size_t pos;
            Civilizacion c;
            cin >> c;
            cout << "Dime la cantidad: ";
            cin >> pos;
            vg.inicializar(c, pos);
        }

        else if(op == 5){
            vg.primeraCivilizacion();
        }

        else if(op == 6){
            vg.ultimaCivilizacion();
        }

        else if(op == 7){
            vg.ordenarNombre();
        }

        else if(op == 8){
            vg.ordenarUbicacionX();
        }

        else if(op == 9){
            vg.ordenarUbicacionY();
        }

        else if(op == 10){
            vg.ordenarPuntuacion();
        }

        else if(op == 11){
            Civilizacion c;
            cin >> c;
            vg.eliminar(c);
        }

        else if(op == 12){
            Civilizacion c;
            cin >> c;
            Civilizacion *ptr = vg.buscar(c);
            
            if(ptr == nullptr){
                cout << "No existe tal dato..." << endl;
            }
            else{
                cout << *ptr << endl;
            }
        }

        else if(op == 13){
            Civilizacion c;
            cin >> c;
            Civilizacion *ptr = vg.buscar(c);
            
            if(ptr == nullptr){
                cout << "No existe tal dato..." << endl;
            }
            else{
                cout << *ptr << endl;
                cout << "Que deseas modificar?" << endl;
                cout << "a.- Nombre           " << endl;
                cout << "b.- Ubicacion en X   " << endl;
                cout << "c.- Ubicacion en Y   " << endl;
                cout << "d.- Puntuacion       " << endl;
                cout << "e.- Nada             " << endl; 
                cout << "Opcion: ";
                cin >> subMenu;
                cin.ignore();

                switch (subMenu)
                {
                case 'a':
                    cout << "Nombre: ";
                    getline(cin, nombre);
                    ptr->setNombre(nombre);

                    break;
                case 'b':
                    cout << "Ubicacion en X: ";
                    cin >> ubicacionEnX;
                    ptr->setUbicacionEnX(ubicacionEnX);

                    break;
                case 'c':
                    cout << "Ubicacion en Y: ";
                    cin >> ubicacionEnY;
                    ptr->setUbicacionEnY(ubicacionEnY);

                    break;
                case 'd':
                    cout << "Puntuacion: ";
                    cin >> puntuacion;
                    ptr->setPuntuacion(puntuacion);

                    break;
                case 'e':
                    cout << "Volviendo al menu..." << endl;
                    break;
                
                default:
                    cout << "No existe tal opcion" << endl;
                    break;
                }
                cin.ignore();
            }
        }

        else if(op == 14){
            vg.mostrar();
        }

        else if(op == 15){
            Civilizacion c;
            cin >> c;
            Civilizacion *ptr = vg.buscar(c);
            
            if(ptr == nullptr){
                cout << "No existe tal dato..." << endl;
            }
            else{
                vg.menuAldeanos(*ptr);
            }
        }

        else if(op == 16){
            vg.respaldarCivilizaciones();
        }

        else if(op == 17){
            vg.recuperarCivilizaciones();
        }

        else if(op == 0){
            cout << "Programa finalizado..." << endl;
            cin.get();
        }

        else{
        cout << "Opcion invalida..." << endl;
        }

        cin.ignore();
    }while(op != 0);

    return 0;
}