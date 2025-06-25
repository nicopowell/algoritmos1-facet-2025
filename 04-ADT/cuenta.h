#include <iostream>
using namespace std;

struct Nodo
{
    float dinero;
    Nodo* siguiente;
} typedef Nodo;

//typedef Nodo* Cuenta;

struct Cuenta {
    Nodo* cabecera;
    int cantidad;
    float saldo;
} typedef Cuenta;

const float indefinido = -9999.99;

Cuenta cuentaVacia()
{
    return {NULL, 0, 0};
}

bool estaVacia(Cuenta C)
{
    return C.cabecera == NULL;
}

void mostrarCuenta(Cuenta C)
{
    while (!estaVacia(C))
    {
        cout << "$" << C.cabecera->dinero;
        C.cabecera = C.cabecera->siguiente;
        if (C.cabecera) cout << " -> ";
    }
    cout << endl;
}

Cuenta depositar(Cuenta C, float dinero)
{
    Nodo* nuevo = new Nodo;
    nuevo->dinero = dinero;
    nuevo->siguiente = C.cabecera;
    C.cabecera = nuevo;
    C.saldo += dinero;
    C.cantidad++;
    return C;
}

float saldo(Cuenta C)
{
    return C.saldo;
}

Cuenta extraer(Cuenta C, float cantidad)
{
    if(!estaVacia(C))
    {
        if(saldo(C) >= cantidad)
        {
            C = depositar(C, -cantidad);
        }
    }
    return C;
}

bool tieneSaldo(Cuenta C)
{
    return C.saldo > 0;
}

float ultima(Cuenta C)
{
    if(estaVacia(C)) return indefinido;
    return C.cabecera->dinero;
}

Cuenta deshacer(Cuenta C)
{
    if(!estaVacia(C))
    {
        Nodo* aux = C.cabecera;
        C.cabecera = C.cabecera->siguiente;
        C.cantidad--;
        C.saldo -= aux->dinero;
        delete aux;
    }
    return C;
}

bool contiene(Cuenta C, float dinero)
{
    while(!estaVacia(C))
    {
        if (C.cabecera->dinero == dinero) return true;
        C.cabecera = C.cabecera->siguiente;
    }
    return false;
}

int cantidad(Cuenta C)
{
    return C.cantidad;
}