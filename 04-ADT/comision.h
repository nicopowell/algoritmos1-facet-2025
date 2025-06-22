#include <string>
using namespace std;

const string indefinido = "error";

typedef string Alumno;

struct Nodo
{
    Alumno alumno;
    Nodo* siguiente;
} typedef Nodo;

typedef Nodo *Comision;

Comision comisionVacia()
{
    return NULL;
}

bool estaVacia(Comision C)
{
    return C == NULL;
}

void mostrarComision(Comision C)
{
    cout << "(";
    while (!estaVacia(C))
    {
        cout << C->alumno;
        C = C->siguiente;
        if (C) cout << ", ";
    }
    cout << ")" << endl;
}

Comision altaAlumno(Comision C, Alumno x)
{
    Nodo* nuevo = new Nodo;
    nuevo->alumno = x;
    nuevo->siguiente = C;
    C = nuevo;
    return C;
}

int cantidad(Comision C)
{
    int contador = 0;
    while (!estaVacia(C))
    {
        contador++;
        C = C->siguiente;
    }
    return contador;
}

Comision bajaAlumno(Comision C, Alumno x)
{
    // Comision Vacia
    if (estaVacia(C)) return C;

    // Se elimina el primero
    if (C->alumno == x)
    {
        Nodo* aux = C;
        C = C->siguiente;
        delete aux;
        return C;
    }

    // Se busca en el resto
    Nodo* anterior = C;
    Nodo* actual = C->siguiente;

    while (actual)
    {
        if(actual->alumno == x)
        {
            anterior->siguiente = actual->siguiente;
            delete actual;
            break;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return C;
}

Comision bajaUltimo(Comision C)
{
    if(!estaVacia(C))
    {
        Nodo* aux = C;
        C = C->siguiente;
        delete aux;
    }
    return C;
}

Alumno ultimoInscripto(Comision C)
{
    if(estaVacia(C)) return indefinido;

    return C->alumno;
}

bool esta(Comision C, Alumno x)
{
    while (!estaVacia(C))
    {
        if(C->alumno == x) return true;
        C = C->siguiente;
    }
    return false;
}

bool hayComunes(Comision C1, Comision C2)
{
    Nodo* aux;
    
    while(!estaVacia(C1))
    {
        aux = C2;
        while(!estaVacia(aux))
        {
            if (C1->alumno == aux->alumno) return true;
            aux = aux->siguiente;
        }
        C1 = C1->siguiente;
    }
    return false;
}