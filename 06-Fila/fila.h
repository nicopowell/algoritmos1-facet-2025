#include <iostream>
using namespace std;

typedef int item;
const int indefinido = -9999;

struct Nodo
{
    item dato;
    Nodo* siguiente;
} typedef Nodo;

struct Fila
{
    Nodo* frente;
    Nodo* final;
    int longitud;
} typedef Fila;

// FILAVACIA: -> FILA
Fila filaVacia()
{
    Fila F;
    F.frente = nullptr;
    F.final = nullptr;
    F.longitud = 0;
    return F;
}

// ESFILAVACIA : FILA -> BOOL
bool esFilaVacia(Fila F)
{
    return F.longitud == 0;
}

// ENFILA: FILA x ITEM -> FILA
Fila enfila(Fila F, item x)
{
    Nodo* nuevo = new Nodo;
    nuevo->dato = x;
    nuevo->siguiente = nullptr;
    if(esFilaVacia(F))
    {
        F.frente = nuevo;
        F.final = nuevo;
    }
    else
    {
        F.final->siguiente = nuevo;
        F.final = nuevo;
    }
    F.longitud++;
    return F;
}

// DEFILA: FILA -> FILA
Fila defila(Fila F)
{
    if (F.longitud != 0)
    {
        Nodo* aux = new Nodo;
        aux = F.frente;
        if(F.longitud == 1)
        {
            F.frente = nullptr;
            F.final = nullptr;
        }
        else
        {
            F.frente = F.frente->siguiente;
        }
        delete aux;
        F.longitud--;
    }
    return F;
}

// FRENTE: FILA -> ITEM ∪ {indefinido}
item frente(Fila F)
{
    if(!esFilaVacia(F)) return F.frente->dato;
    return indefinido;
}

void mostrarFila(Fila F)
{
    while (F.frente != nullptr)
    {
        cout << F.frente->dato;
        F.frente = F.frente->siguiente;
        if(F.frente) cout << " -> ";
    }
    cout << endl;
}