#include <iostream>

using namespace std;

void menu_principal(){
    cout << "¡Bienvenido a tu diario personal!" << endl;
    cout << "¿Qué deseas hacer?" << endl;
    cout << "1. Escribir un nuevo día" << endl;
    cout << "2. Leer un día" << endl;
    cout << "3. Salir" << endl;
}

void elegir_opcion(){
    cout << "Elige una opción: ";
    int opcion;
    cin >> opcion;

    switch(opcion){
        case 1:
            cout << "Escribir un nuevo día" << endl;
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
}

int main(){

    menu_principal();
    elegir_opcion();

    return 0;
    
}