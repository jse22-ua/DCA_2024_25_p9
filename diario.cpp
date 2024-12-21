#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

void menu_principal(){
    cout << "¿Qué deseas hacer?" << endl;
    cout << "1. Escribir un nuevo día" << endl;
    cout << "2. Leer un día" << endl;
    cout << "3. Salir" << endl;
}


string obtener_fecha(){
    time_t t = time(0);
    struct tm * now = localtime(&t);
    int year = now->tm_year + 1900;
    int month = now->tm_mon + 1;
    int day = now->tm_mday;

    string fecha = to_string(day) + "-" + to_string(month) + "-" + to_string(year);
    return fecha;
}

bool escribir_dia(){
    string fecha = obtener_fecha();
    cout << fecha << endl;

    ofstream archivo;
    archivo.open("entradas/" + fecha + ".txt");

    if(!archivo.is_open()){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }

    archivo << fecha << endl;
    cout << "Escribe tu día: " << endl;
    cin.ignore();
    while(true){
        string entrada;
        getline(cin, entrada);
        if(entrada.empty()){
            break;
        }
        archivo << entrada << endl;
    }
    cout << "Día guardado correctamente" << endl;
    archivo.close();
    return true;
}

bool leer_dia(){
    string fecha;
    cout << "Ingresa la fecha del día que deseas leer (dd-mm-yyyy): ";
    cin >> fecha;

    if(fecha.size() != 10 || fecha[2] != '-' || fecha[5] != '-'){
        cout << "El formato de la fecha es incorrecto" << endl;
        cout << "El formato que deberia tener es dd-mm-yyyy" << endl;
        return false;
    }
    
    cout << endl;


    ifstream archivo;
    archivo.open("entradas/" + fecha + ".txt");

    if(!archivo.is_open()){
        cout << "La fecha es incorrecta" << endl;
        cout << "No hay registros de ese día" << endl;
        return false;
    }

    string linea;
    while(getline(archivo, linea)){
        cout << linea << endl;
    }

    archivo.close();
    cout << endl;
    return true;
}

void elegir_opcion(){
    int opcion;

    do{
        menu_principal();
        cout << "Elige una opción: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                escribir_dia();
                break;
            case 2:
                leer_dia();
                break;
            case 3:
                cout << "Salir" << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
                break;
        }
    }while(opcion != 3);
}

int main(){

    cout << "¡Bienvenido a tu diario personal!" << endl;
    elegir_opcion();

    return 0;
    
}