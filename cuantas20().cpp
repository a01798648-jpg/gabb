//
// Created by MrGab on 10/11/2025.
//
#include <iostream>
using namespace std;
//Pide al usuario un número y busca cuantos son positivos, negativos, y ceros
int cuenta20() {
    double numero;
    int posi = 0, nega = 0, ceri=0; //variables que me cuentan mis 3 tipos de datos
    cout << "Hola, este programa pide 20 numeros y se clasifican en neutros, positivos y negativos\n";
    for (int i = 1; i <= 20; i++) { //para hacer un buble en el que pide los número sy clasifica
        cout << "Ingresa el numero "<<i<< ": ";
        cin >> numero; //guardo cada número momentaneamente
        if (numero < 0) {
            nega++; //suma de los negativos
        }
        else if (numero == 0) {
            ceri++;
        }
        else {
            posi++;
        }
    }
    cout << "De los 20 numeros que ingresaste, "
    << ceri << " son ceros, " //imprimo las variables
    << nega<< " son negativos, y "
    <<posi<< " son positivos" << endl;
    return 0;
}
int main() {
    return cuenta20();   // <- punto de entrada
}