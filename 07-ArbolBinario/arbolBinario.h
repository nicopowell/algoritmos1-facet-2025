#include <iostream>
using namespace std;

const char indefinido = '#';
typedef char itemAB;

struct NodoAB
{
    itemAB raiz;
    NodoAB* izq;
    NodoAB* der;
} typedef NodoAB;

typedef NodoAB* AB;

// ABVACIO: -> AB
AB aBVacio()
{
    return nullptr;
}

// ARMARAB:  AB X ITEM X AB -> AB	
AB armarAB(AB izq, itemAB x, AB der)
{
    NodoAB* nuevo = new NodoAB;
    nuevo->izq = izq;
    nuevo->raiz = x;
    nuevo->der = der;

    return nuevo;
}


// ESABVACIO: AB -> BOOL
bool esABVacio(AB arbol)
{
    if (arbol) return false;
    return true;
}

// PERTENECE: AB X ITEM -> BOOL
bool pertenece(AB arbol, itemAB item)
{
    if(!esABVacio(arbol))
    {
        if(arbol->raiz == item || pertenece(arbol->izq, item) || pertenece(arbol->der, item)) return true;
    }
    return false;
}

// IZQUIERDO: AB -> AB
AB izquierdo(AB arbol)
{
    return arbol->izq;
}
// RAIZ: AB -> ITEM U {indefinido}
itemAB raiz(AB arbol)
{
    if(!esABVacio(arbol))
    {
        return arbol->raiz;
    }
    return indefinido;
}
// DERECHO: AB -> AB
AB derecho(AB arbol)
{
    return arbol->der;
}

void preOrden(AB A)
{
    if (!esABVacio(A))
    {
        cout << A->raiz << " ";
        preOrden(A->izq);
        preOrden(A->der);
    }
}

void enOrden(AB A)
{
    if (!esABVacio(A))
    {
        preOrden(A->izq);
        cout << A->raiz << " ";
        preOrden(A->der);
    }
}

void posOrden(AB A)
{
    if (!esABVacio(A))
    {
        preOrden(A->izq);
        preOrden(A->der);
        cout << A->raiz << " ";
    }
}

void mostrarArbol(AB arbol, string prefijo = "", bool esUltimo = true, string etiqueta = "")
{
    if (esABVacio(arbol)) return;

    cout << prefijo;
    cout << (esUltimo ? "└── " : "├── ");
    cout << etiqueta << arbol->raiz << endl;

    string nuevoPrefijo = prefijo + (esUltimo ? "    " : "│   ");

    bool tieneIzq = arbol->izq != nullptr;
    bool tieneDer = arbol->der != nullptr;

    if (tieneIzq || tieneDer)
    {
        if (arbol->izq)
            mostrarArbol(arbol->izq, nuevoPrefijo, arbol->der == nullptr, "L: ");
        if (arbol->der)
            mostrarArbol(arbol->der, nuevoPrefijo, true, "R: ");
    }
}

void destruirArbol(AB& arbol)
{
    if (!esABVacio(arbol))
    {
        destruirArbol(arbol->izq);
        destruirArbol(arbol->der);
        delete arbol;
        arbol = nullptr;
    }
}