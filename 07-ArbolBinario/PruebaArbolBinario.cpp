#include <iostream>
using namespace std;

#include "arbolBinario.h"

int main() {
    cout << "=== TEST ARBOL BINARIO ===\n";

    // Crear árbol
    AB izq = armarAB(aBVacio(), 'B', aBVacio());
    AB der = armarAB(aBVacio(), 'C', aBVacio());
    AB raizAB = armarAB(izq, 'A', der);

    cout << "\n[1] Mostrar árbol en forma estructurada:\n";
    mostrarArbol(raizAB);

    cout << "\n[2] Recorridos clásicos:\n";
    cout << "Preorden: "; preOrden(raizAB); cout << endl;
    cout << "Inorden:  "; enOrden(raizAB);  cout << endl;
    cout << "Postorden:"; posOrden(raizAB); cout << endl;

    cout << "\n[3] Accesos básicos:\n";
    cout << "Raíz del árbol: " << raiz(raizAB) << endl;
    cout << "Raíz del izquierdo: " << raiz(izquierdo(raizAB)) << endl;
    cout << "Raíz del derecho: " << raiz(derecho(raizAB)) << endl;

    cout << "\n[4] Pertenece:\n";
    cout << "¿Contiene 'A'? " << boolalpha << pertenece(raizAB, 'A') << endl;
    cout << "¿Contiene 'B'? " << boolalpha << pertenece(raizAB, 'B') << endl;
    cout << "¿Contiene 'Z'? " << boolalpha << pertenece(raizAB, 'Z') << endl;

    cout << "\n[5] Árbol vacío:\n";
    AB vacio = aBVacio();
    cout << "¿Vacio está vacío? " << esABVacio(vacio) << endl;
    cout << "¿raiz(vacio)? " << raiz(vacio) << endl;

    cout << "\n=== TEST ÁRBOL GRANDE ===\n";

    // Subárbol izquierdo
    AB nodoC = armarAB(aBVacio(), 'C', aBVacio());
    AB nodoE = armarAB(aBVacio(), 'E', aBVacio());
    AB nodoD = armarAB(nodoC, 'D', nodoE);
    AB nodoA = armarAB(aBVacio(), 'A', aBVacio());
    AB nodoB = armarAB(nodoA, 'B', nodoD);

    // Subárbol derecho
    AB nodoH = armarAB(aBVacio(), 'H', aBVacio());
    AB nodoI = armarAB(nodoH, 'I', aBVacio());
    AB nodoG = armarAB(aBVacio(), 'G', nodoI);

    // Raíz
    AB arbolGrande = armarAB(nodoB, 'F', nodoG);

    cout << "\n[1] Mostrar árbol grande:\n";
    mostrarArbol(arbolGrande);

    cout << "\n[2] Recorridos:\n";
    cout << "Preorden: "; preOrden(arbolGrande); cout << endl;
    cout << "Inorden:  "; enOrden(arbolGrande);  cout << endl;
    cout << "Postorden:"; posOrden(arbolGrande); cout << endl;

    cout << "\n[3] Prueba de pertenece:\n";
    cout << "¿Contiene 'E'? " << pertenece(arbolGrande, 'E') << endl;
    cout << "¿Contiene 'Z'? " << pertenece(arbolGrande, 'Z') << endl;

    cout << "\n[4] Accesos:\n";
    cout << "Raíz: " << raiz(arbolGrande) << endl;
    cout << "Izquierdo de raíz: " << raiz(izquierdo(arbolGrande)) << endl;
    cout << "Derecho de raíz: " << raiz(derecho(arbolGrande)) << endl;

    destruirArbol(raizAB);
    destruirArbol(arbolGrande);

    cout << "\n=== FIN DE TEST ===\n";
    return 0;
}