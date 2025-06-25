#include <iostream>
using namespace std;

typedef int item;
const item indefinido = -9999;

struct Nodo
{
    item dato;
    Nodo *siguiente;
} typedef Nodo;

struct Pila
{
    Nodo *tope;
    Nodo *fondo;
    int altura;
} typedef Pila;

// PILAVACIA: -> PILA
Pila pilaVacia()
{
    return {nullptr, nullptr, 0};
}

// PUSH: PILA x item -> PILA
Pila push(Pila P, item x)
{
    Nodo *aux = new Nodo;
    aux->dato = x;
    aux->siguiente = P.tope;
    P.tope = aux;
    if (P.fondo == nullptr)
        P.fondo = aux;
    P.altura++;
    return P;
}

// ESPILAVACIA : PILA -> Bool
bool esPilaVacia(Pila P)
{
    return P.tope == nullptr;
}

// POP: PILA -> PILA
Pila pop(Pila P)
{
    if (!esPilaVacia(P))
    {
        Nodo *aux = P.tope;
        if (P.tope->siguiente == nullptr) // Solo un nodo
        {
            P.tope = nullptr;
            P.fondo = nullptr;
        }
        else
        {
            P.tope = P.tope->siguiente;
        }
        delete aux;
        P.altura--;
    }
    return P;
}

Pila popF(Pila P)
{
    if (!esPilaVacia(P))
    {
        if(P.altura == 1) 
        {
            P = pop(P);
        }
        else
        {
            Nodo* anterior = P.tope;
            Nodo* actual = P.tope->siguiente;
            while(actual->siguiente != nullptr)
            {
                anterior = anterior->siguiente;
                actual = actual->siguiente;
            }
            anterior->siguiente = actual->siguiente;
            delete actual;
            P.fondo = anterior;
            P.altura--;
        }
    }
    return P;
}

Pila popN(Pila P, int n)
{
    for (int i = 0; i < n; i++)
    {
        P = pop(P);
    }
    return P;
}

// TOP: PILA -> item ∪ {indefinido}
item top(Pila P)
{
    if (!esPilaVacia(P))
        return P.tope->dato;
    return indefinido;
}

item fondo(Pila P)
{
    if (!esPilaVacia(P))
        return P.fondo->dato;
    return indefinido;
}

// ALTURA: PILA -> entero≥0
int altura(Pila P)
{
    return P.altura;
}

// PUSHF: PILA x ítem -> PILA

void mostrarPila(Pila P)
{
    while (!esPilaVacia(P))
    {
        cout << P.tope->dato;
        P.tope = P.tope->siguiente;
        if (P.tope)
            cout << " -> ";
    }
    cout << endl;
}