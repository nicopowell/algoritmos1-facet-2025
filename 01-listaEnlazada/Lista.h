#include <iostream>
using namespace std;

typedef int item;

const item indefinido = -99999;

struct Nodo
{
    item dato;
    Nodo *siguiente;
} typedef Nodo;

typedef Nodo *Lista;

Lista crearLista()
{
    return NULL;
}

bool esListaVacia(Lista L)
{
    return L == NULL;
}

void mostrar(Lista L)
{
    while (!esListaVacia(L))
    {
        cout << " " << L->dato << " ";
        L = L->siguiente;
        if (L)
        {
            cout << "->";
        }
    }
}

item primerElemento(Lista L)
{
    if(!esListaVacia(L))
    {
        return L->dato;
    }
    return indefinido;
}

Lista insertar(Lista L, item valor)
{
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = L;
    L = nuevo;
    return L;
}

Lista borrar(Lista L)
{
    if(!esListaVacia(L))
    {
        Nodo* aux = L;
        L = L->siguiente;
        delete aux;
    }
    return L;
}

int longitud(Lista L){
    int contador = 0;
    while(!esListaVacia(L)) {
        L = L->siguiente;
        contador++;
    }
    return contador;
}

bool pertenece(Lista L, item dato)
{
    while(!esListaVacia(L))
    {
        if(L->dato == dato)
        {
            return true;
        }
        L = L->siguiente;
    }
    return false;
}

Lista borrarUltimo(Lista L)
{
    if(esListaVacia(L)){
        return NULL;
    }
    
    if(L->siguiente == NULL){
        delete L;
        return NULL;
    }

    Nodo* actual = L;

    while(actual->siguiente->siguiente != NULL){
        actual = actual->siguiente;
    }

    delete actual->siguiente;
    actual->siguiente = NULL;

    return L;
}

bool iguales(Lista *L1, Lista *L2) {
  if (longitud(*L1) != longitud(*L2)) {
    return false;
  }

  while (!esListaVacia(*L1) && !esListaVacia(*L2)) {
    if (primerElemento(*L1) != primerElemento(*L2)) {
      return false;
    }
    *L1 = borrar(*L1);
    *L2 = borrar(*L2);
  }
  return true;
}