//
// Created by MrGab on 10/11/2025.
//
#include <iostream>
#include <ostream>
//
// Created by MrGab on 10/11/2025.
//Esta función hace lo siguiente: Encontrar y regresar el menor valor de un conjunto de n números dados.
#include <iostream>
using namespace std;
int menor(int numDatos) {
    int numi, mini;
    //Ver el primer número y usarlo como mínimo
    cout<<"Ingresa el numero 1:";
    cin>>numi;
    mini = numi;
    //Ir leyendo los demás números, e ir comparando cada uno
    for (int i = 2; i <= numDatos; i++) {
        cout << "Ingresa el numero" << i << " : ";
        cin>>mini;
        if (numi < mini) {
            mini = numi;
        }
    }
    return mini;


}
int main() {
    int cantidad;

    cout << "Cuantos numeros vas a ingresar? ";
    cin >> cantidad;

    int resultado = menor(cantidad);
    cout << "El menor numero es: " << resultado << endl;

    return 0;
}