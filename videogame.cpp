#include "videogame.h"

VideoGame::VideoGame(){}

void VideoGame::setUsuario(string &u){
    usuario = u;
}

string VideoGame::getUsuario(){
    return usuario;
}

void VideoGame::agregarCivilizacion(const Civilizacion &c)
{
    civilizaciones.push_back(c);
}

void VideoGame::mostrar()
{
    cout << left;
    cout << setw(15) << "Nombre";
    cout << setw(21) << "Ubicacion en X";
    cout << setw(19) << "Ubicacion en Y";
    cout << setw(16) << "Puntuacion";
    cout << endl;

    for(size_t i = 0; i < civilizaciones.size(); i++){
        Civilizacion &c = civilizaciones[i];
        cout << c;
    }
}

void VideoGame::primeraCivilizacion(){
    if(civilizaciones.empty()){
                cout << "El vector esta vacio..." << endl;
            }
            else{
                cout << "Frente: "<< civilizaciones.front() << endl;
            }
            cin.get();
}

void VideoGame::ultimaCivilizacion(){
    if(civilizaciones.empty()){
                cout << "El vector esta vacio..." << endl;
            }
            else{
                cout << "Ultimo: " << civilizaciones.back() << endl;
            }
            cin.get();
}

void VideoGame::insertar(const Civilizacion &c, size_t pos)
{
    civilizaciones.insert(civilizaciones.begin()+pos, c);
}

size_t VideoGame::size()
{
    return civilizaciones.size();
}

void VideoGame::inicializar(const Civilizacion &c, size_t n)
{
    civilizaciones = vector<Civilizacion>(n, c);
}

void VideoGame::eliminar(const Civilizacion &c)
{
    //civilizaciones.erase(civilizaciones.begin()+pos);
    civilizaciones.erase(std::remove(civilizaciones.begin(), civilizaciones.end(), c), civilizaciones.end());
}

void VideoGame::ordenarNombre()
{
    sort(civilizaciones.begin(), civilizaciones.end());
}

void VideoGame::ordenarUbicacionX()
{
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [](Civilizacion c1, Civilizacion c2){return c1.getUbicacionEnX() < c2.getUbicacionEnX();});
}

void VideoGame::ordenarUbicacionY()
{
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [](Civilizacion c1, Civilizacion c2){return c1.getUbicacionEnY() < c2.getUbicacionEnY();});
}

void VideoGame::ordenarPuntuacion()
{
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() < c2.getPuntuacion();});
}

Civilizacion* VideoGame::buscar(const Civilizacion &c)
{
    //vector<Civilizacion>::iterator it
    //auto it
    vector<Civilizacion>::iterator it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if(it == civilizaciones.end()){
        return nullptr;
    }
    else{
        return &(*it);
    }
}

void VideoGame::borrar_ultimo()
{
    if(civilizaciones.empty()){
                cout << "El vector esta vacio..." << endl;
            }
            else{
                civilizaciones.pop_back();
            }
}

void VideoGame::menuAldeanos(Civilizacion &c) 
{
    size_t opSubMenu;

    do{

        cout << "+------------------------------------+" << endl;
        cout << "|            MENU ALDEANOS           |" << endl;
        cout << "+------------------------------------+" << endl;
        cout << "1) Agregar Aldeano                    " << endl;
        cout << "2) Eliminar Aldeano                   " << endl;
        cout << "3) Clasificar Aldeanos                " << endl;
        cout << "4) Buscar Aldeano                     " << endl;
        cout << "5) Modificar Aldeano                  " << endl;
        cout << "6) Mostrar Aldeanos                   " << endl;
        cout << "0) Salir                              " << endl;
        cout << "Opcion: ";
        cin >> opSubMenu;
        cin.ignore();

        if(opSubMenu != 0){
            limpiarPantalla();
        }

        if(opSubMenu == 1){
            string op;
            cout << "1. Agregar el objeto aldeano al inicio" << endl;
            cout << "2. Agregar el objeto aldeano al final " << endl;
            cout << "Opcion: ";
            getline(cin, op);
            if(op == "1"){
                c.agregarInicio(capturar());
                c.setPuntuacion(c.getPuntuacion() + 100);
            }
            else if(op == "2"){
                c.agregarFinal(capturar());
                c.setPuntuacion(c.getPuntuacion() + 100);
            }
        }
        else if(opSubMenu == 2){
            string op;
            cout << "1. Eliminar por nombre         " << endl;
            cout << "2. Eliminar por salud menor a x" << endl;
            cout << "3. Eliminar por edad >= a 60   " << endl;
            cout << "Opcion: ";
            getline(cin, op);
            if(op == "1"){
                string nombre;
                cout << "Nombre: ";
                getline(cin, nombre);

                c.eliminarNombre(nombre);
            }
            else if(op == "2"){
                float salud;
                cout << "Salud: ";
                cin >> salud;
                cin.ignore();
                c.eliminarSalud(salud);
            }
            else if(op == "3"){
                c.eliminarEdad();
            }
        }
        else if(opSubMenu == 3){
            string op;
            cout << "1. Clasificar por nombre " << endl;
            cout << "2. Clasificar por edad   " << endl;
            cout << "3. Clasificar por salud  " << endl;
            cout << "Opcion: ";
            getline(cin, op);

            if(op == "1"){
                c.ordenarNombre();
            }
            else if(op == "2"){
                c.ordenarEdad();
            }
            else if(op == "3"){
                c.ordenarSalud();
            }
        }
        else if(opSubMenu == 4){
            Aldeano a;
            cin >> a;
            Aldeano *ptr = c.buscar(a);
            
            if(ptr == nullptr){
                cout << "No existe tal dato..." << endl;
            }
            else{
                cout << *ptr << endl;
            }
        }
        
        else if(opSubMenu == 5){
            string nombre, genero;
            size_t edad;
            float salud;
            char subMenu;
            Aldeano a;
            cin >> a;
            Aldeano *ptr = c.buscar(a);
            
            if(ptr == nullptr){
                cout << "No existe tal dato..." << endl;
            }
            else{
                cout << *ptr << endl;
                cout << "Que deseas modificar?" << endl;
                cout << "a.- Nombre" << endl;
                cout << "b.- Edad  " << endl;
                cout << "c.- Genero" << endl;
                cout << "d.- Salud " << endl;
                cout << "e.- Nada  " << endl; 
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
                    cout << "Edad: ";
                    cin >> edad;
                    ptr->setEdad(edad);

                    break;
                case 'c':
                    cout << "Genero: ";
                    cin >> genero;
                    ptr->setGenero(genero);

                    break;
                case 'd':
                    cout << "Salud: ";
                    cin >> salud;
                    ptr->setSalud(salud);

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
        else if(opSubMenu == 6){
            c.imprimir();
        }
        else if(opSubMenu == 0){
            break;
        }
    }while(opSubMenu != 0);
}

void VideoGame::limpiarPantalla()
{
    cin.get();
    cout << "Presione entrar para continuar..." << endl;
    system(CLEAN_SCREEN);
}

Aldeano VideoGame::capturar() {
    Aldeano a;
    string tempString;
    size_t tempInt;
    float tempFloat;

    cout << "Nombre: ";
    getline(cin, tempString);
    a.setNombre(tempString);

    cout << "Edad: ";
    cin >> tempInt;
    cin.ignore();
    a.setEdad(tempInt);

    cout << "Genero: ";
    getline(cin, tempString);
    a.setGenero(tempString);

    cout << "Salud: ";
    cin >> tempFloat;
    a.setSalud(tempFloat);

    return a;
}

void VideoGame::respaldarCivilizaciones()
{
    ofstream archivo("civilizaciones.txt", ios::out);

    if(archivo.is_open()){

        for (size_t i = 0; i < civilizaciones.size(); i++){
            Civilizacion &c = civilizaciones[i];
            archivo << c.getNombre() << endl;
            archivo << c.getUbicacionEnX() << endl;
            archivo << c.getUbicacionEnY() << endl;
            archivo << c.getPuntuacion() << endl;
            c.respaldarAldeanos();
        }
    }
    archivo.close();
}

void VideoGame::recuperarCivilizaciones()
{
    ifstream archivo("civilizaciones.txt", ios::out);

    if(archivo.is_open()){
        string tempString;
        int tempInt;
        float tempFloat;

        while(true){
            Civilizacion c;

            getline(archivo, tempString); 
            if(archivo.eof()){
                break;
            }
            c.setNombre(tempString);

            getline(archivo, tempString); 
            tempInt = stoi(tempString);
            c.setUbicacionEnX(tempInt);

            getline(archivo, tempString);
            tempInt = stoi(tempString);
            c.setUbicacionEnY(tempInt);

            getline(archivo, tempString); 
            tempFloat = stof(tempString);               
            c.setPuntuacion(tempFloat);

            c.recuperarAldeanos();
            agregarCivilizacion(c);
        }
    }
    archivo.close();
}