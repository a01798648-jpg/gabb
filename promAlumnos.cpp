//
// Created by MrGab on 10/11/2025.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    string nombre;
    float cal1, cal2, cal3, promedio;

    // Solicitar el nombre del alumno
    cout << "Introduce el nombre del alumno: ";
    getline(cin, nombre);

    // Tres calificaciones
    cout << "Introduce la primera calificacion: ";
    cin >> cal1;
    cout << "Introduce la segunda calificacion: ";
    cin >> cal2;
    cout << "Introduce la tercera calificacion: ";
    cin >> cal3;

    // Promedio
    promedio = (cal1 + cal2 + cal3) / 3;

    // Resultado
    cout << "El promedio de " << nombre << " es: " << promedio << endl;

    return 0;
}