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
                cout << "Leer un día" << endl;
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