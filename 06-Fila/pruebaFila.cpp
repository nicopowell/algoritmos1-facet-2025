#include <iostream>
using namespace std;

#include "fila.h"

int main(){
    cout << "===== PRUEBA DE FILA =====" << endl;

    Fila F = filaVacia();
    cout << "\nCreo una Fila F vacia y la muestro por pantalla: ";
    mostrarFila(F);
    cout << "Frente: " << frente(F) << endl;
    cout << "Defilo de fila vacia: ";
    F = defila(F);
    mostrarFila(F);

    cout << "\nEnfilo 1: ";
    F = enfila(F, 1);
    mostrarFila(F);
    cout << "Frente: " << frente(F) << endl;
    cout << "Defilo: ";
    F = defila(F);
    mostrarFila(F);

    cout << "\nEnfilo 1: ";
    F = enfila(F, 1);
    mostrarFila(F);
    cout << "Enfilo 2: ";
    F = enfila(F, 2);
    mostrarFila(F);
    cout << "Enfilo 3: ";
    F = enfila(F, 3);
    mostrarFila(F);
    cout << "Frente: " << frente(F) << endl;
    cout << "Defilo: ";
    F = defila(F);
    mostrarFila(F);

    cout << "\nLIBERO LA MEMORIA" << endl;
    while(!esFilaVacia(F))
    {
        F = defila(F);
    }
    cout << "Fila liberada: ";
    mostrarFila(F);
    return 0;
}