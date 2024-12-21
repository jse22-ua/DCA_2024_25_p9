#include <iostream>

using namespace std;

int main(){
    cout << "¡Bienvenido a tu diario personal!" << endl;
    cout << "¿Qué deseas hacer?" << endl;
    cout << "1. Escribir un nuevo día" << endl;
    cout << "2. Leer un día" << endl;
    cout << "3. Salir" << endl;

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