#include <iostream>
using namespace std;

typedef int item;
const int indefinido = -9999;

struct Nodo {
    item dato;
    Nodo* sig;
};

struct Fila {
    Nodo* frente;
    Nodo* final;
    int longitud;
};

Fila filaVacia(){
    Fila F;
    F.frente = nullptr;
    F.final = nullptr;
    F.longitud = 0;
    return F;
}

bool esFilaVacia(Fila F){
    return F.longitud == 0;
}

item frente(Fila F){
    if(!F.longitud){
        return indefinido;
    } else {
        return F.frente->dato;
    }
}

Fila enfila(Fila F, item x){
    Nodo* nodo = new Nodo;
    nodo->dato = x;
    nodo->sig = nullptr;

    if(!F.longitud){
        F.frente = nodo;
    } else {
        F.final->sig = nodo;
    }

    F.final = nodo;
    F.longitud++;

    return F;
}

Fila defila(Fila F){
    if(F.longitud){
        Nodo* aux = F.frente;
        if(F.longitud == 1){
            F.final = nullptr;
        }
        F.frente = F.frente->sig;
        delete aux;
        F.longitud--;
    }
    
    return F;
}

void imprimirFila(Fila F) {
    cout << "Fila (longitud=" << F.longitud << "): ";
    Nodo* actual = F.frente;
    while(actual != nullptr) {
        cout << actual->dato << " ";
        actual = actual->sig;
    }
    cout << endl;
}