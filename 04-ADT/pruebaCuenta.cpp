#include <iostream>
#include "cuenta.h"

using namespace std;

float maximoDeposito(Cuenta* C);

int main()
{
    cout << "==== Iniciando programa de prueba ====" << endl;

    cout << "Creo una cuenta C vacia" << endl;
    Cuenta C = cuentaVacia();
    cout << "C esta vacia? (Si): " << (estaVacia(C) ? "Si" : "No") << endl;
    cout << "Muestro C (Se espera vacia): ";
    mostrarCuenta(C);
    cout << "C tiene saldo? (No): " << (tieneSaldo(C) ? "Si" : "No") << endl;
    cout << "Saldo ($0): $" << saldo(C) << endl;
    C = extraer(C, 2.5);
    cout << "Muestro C luego de extraer (Se espera vacia): " << endl;
    cout << "Ultima ($indefinido): $" << ultima(C);
    mostrarCuenta(C);
    cout << "Deshago la ultima transaccion y muestro C (Se espera vacia): ";
    C = deshacer(C);
    mostrarCuenta(C);
    cout << "C contiene 7.5? (No): " << (contiene(C, 7.5) ? "Si" : "No") << endl;
    cout << "Cantidad (0): " << cantidad(C) << endl;

    cout << "\nDeposito $15" << endl;
    C = depositar(C, 15);
    cout << "C esta vacia? (No): " << (estaVacia(C) ? "Si" : "No") << endl;
    cout << "Muestro C (Se espera $15): ";
    mostrarCuenta(C);
    cout << "Saldo ($15): $" << saldo(C) << endl;
    cout << "C tiene saldo? (Si): " << (tieneSaldo(C) ? "Si" : "No") << endl;
    C = extraer(C, 20);
    cout << "Muestro C luego de extraer ($15): ";
    mostrarCuenta(C);
    cout << "Saldo ($15): $" << saldo(C) << endl;
    cout << "Ultima ($15): $" << ultima(C) << endl;
    cout << "Cantidad (1): " << cantidad(C) << endl;

    cout << "\nDeposito $7.5" << endl;
    C = depositar(C, 7.5);
    cout << "C esta vacia? (No): " << (estaVacia(C) ? "Si" : "No") << endl;
    cout << "Muestro C (Se espera $7.5 y $15): ";
    mostrarCuenta(C);
    cout << "Saldo ($22.5): $" << saldo(C) << endl;
    C = extraer(C, 2.5);
    cout << "Muestro C luego de extraer (-$2.5, $7.5, $15): ";
    mostrarCuenta(C);
    cout << "Saldo ($20): $" << saldo(C) << endl;
    cout << "Ultima ($-2.5): $" << ultima(C) << endl;
    cout << "C contiene 7.5? (Si): " << (contiene(C, 7.5) ? "Si" : "No") << endl;
    cout << "C contiene 25? (No): " << (contiene(C, 25) ? "Si" : "No") << endl;
    cout << "Deshago la ultima transaccion y muestro C ($7.5, $15): ";
    C = deshacer(C);
    mostrarCuenta(C);
    cout << "Cantidad (2): " << cantidad(C) << endl;

    cout << "\nDeposito $125" << endl;
    C = depositar(C, 125);
    cout << "Deposito $50" << endl;
    C = depositar(C, 50);
    cout << "Deposito $80" << endl;
    C = depositar(C, 80);
    cout << "Muestro C (Se espera $80, $50, $125, $7.5 y $15): ";
    mostrarCuenta(C);
    cout << "El maximo deposito es ($125): $" << maximoDeposito(&C) << endl;
    cout << "Muestro C luego de usar funcion maximo: ";
    mostrarCuenta(C);

    cout << "\nLIBERO LA LISTA" << endl;
    while (!estaVacia(C))
    {
        C = deshacer(C);
    }
    cout << "Muestro C luego de liberar: ";
    mostrarCuenta(C);
    return 0;
}

float maximoDeposito(Cuenta* C){
    float maximo = indefinido;
    while (!estaVacia(*C))
    {
        if (maximo < ultima(*C)) maximo = ultima(*C);
        *C = deshacer(*C);
    }
    return maximo;
}