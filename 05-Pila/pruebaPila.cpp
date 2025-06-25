#include <iostream>
using namespace std;

#include "pila.h"

int main()
{
    cout << "===== INICIANDO PRUEBA DE PILA =====" << endl;

    Pila P = pilaVacia();
    cout << "Creo una pila vacia P y la muestro por pantalla: ";
    mostrarPila(P);
    cout << "Top (indefinido = -9999): " << top(P) << endl;
    cout << "Fondo (indefinido = -9999): " << fondo(P) << endl;
    cout << "Altura (0): " << altura(P) << endl;

    P = pop(P);
    cout << "POP (): ";
    mostrarPila(P);
    
    P = push(P, 1);
    cout << "\nPUSH de 1 (1): ";
    mostrarPila(P);
    
    cout << "Top (1): " << top(P) << endl;
    cout << "Fondo (1): " << fondo(P) << endl;
    cout << "Altura (1): " << altura(P) << endl;

    P = push(P, 2);
    cout << "\nPUSH de 2 (2 -> 1): ";
    mostrarPila(P);

    P = push(P, 3);
    cout << "PUSH de 3 (3 -> 2 -> 1): ";
    mostrarPila(P);

    P = push(P, 4);
    cout << "\nPUSH de 4 (4 -> 3 -> 2 -> 1): ";
    mostrarPila(P);
    cout << "Altura (4): " << altura(P) << endl;
        
    P = pop(P);
    cout << "\nPOP (3 -> 2 -> 1): ";
    mostrarPila(P);
    cout << "Top (3): " << top(P) << endl;
    cout << "Fondo (1): " << fondo(P) << endl;
    cout << "Altura (3): " << altura(P) << endl;
    P = popF(P);
    cout << "POPF (3 -> 2): ";
    mostrarPila(P);

    P = push(P, 4);
    cout << "\nPUSH de 3 (4 -> 3 -> 2): ";
    mostrarPila(P);
    P = push(P, 5);
    cout << "PUSH de 3 (5 -> 4 -> 3 -> 2): ";
    mostrarPila(P);
    P = popN(P, 2);
    cout << "POPN 3 (3 -> 2): ";
    mostrarPila(P);
    cout << "Top (3): " << top(P) << endl;
    cout << "Fondo (2): " << fondo(P) << endl;
    cout << "Altura (2): " << altura(P) << endl;
    
    
    cout << "LIBERANDO MEMORIA";
    while(!esPilaVacia(P))
    {
        P = pop(P);
    }

    return 0;
}