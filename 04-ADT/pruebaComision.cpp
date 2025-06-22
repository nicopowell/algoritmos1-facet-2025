#include <iostream>
#include "comision.h"

using namespace std;

Comision repetidos (Comision* C1, Comision* C2);

int main()
{
    cout << "Creo una comision vacía C" << endl;
    Comision C = comisionVacia();
    cout << "Muestro la comision vacia: ";
    mostrarComision(C);
    cout << "La comision esta vacia? (se espera SI): " << (estaVacia(C) ? "SI" : "NO") << endl;
    cout << "Cantidad de alumnos (Se espera 0): " << cantidad(C) << endl;
    C = bajaAlumno(C, "Alumno");
    cout << "Elimino Alumno de comision vacia: ";
    mostrarComision(C);
    cout << "Muestro el ultimo inscripto (Se espera error): " << ultimoInscripto(C) << endl;
    cout << "Esta Juan? (se espera NO): " << (esta(C, "Juan") ? "SI" : "NO") << endl;

    C = bajaUltimo(C);
    cout << "Elimino ultimo inscripto de comision vacia: ";
    mostrarComision(C);

    cout << "\nAgrego el alumno Nico a la comision C: ";
    C = altaAlumno(C, "Nico");
    mostrarComision(C);
    cout << "La comision esta vacia? (se espera NO): " << (estaVacia(C) ? "SI" : "NO") << endl;
    cout << "Cantidad de alumnos (Se espera 1): " << cantidad(C) << endl;

    cout << "\nAgrego el alumno Pepe, Juan, Maria, Ana a la comision C: ";
    C = altaAlumno(C, "Pepe");
    C = altaAlumno(C, "Juan");
    C = altaAlumno(C, "Maria");
    C = altaAlumno(C, "Ana");
    mostrarComision(C);
    cout << "La comision esta vacia? (se espera NO): " << (estaVacia(C) ? "SI" : "NO") << endl;
    cout << "Cantidad de alumnos (Se espera 5): " << cantidad(C) << endl;
    cout << "Esta Juan? (se espera SI): " << (esta(C, "Juan") ? "SI" : "NO") << endl;

    C = bajaAlumno(C, "Miguel");
    cout << "\nElimino Miguel de comision: ";
    mostrarComision(C);

    C = bajaAlumno(C, "Ana");
    cout << "Elimino Ana de comision: ";
    mostrarComision(C);

    C = bajaAlumno(C, "Pepe");
    cout << "Elimino Pepe de comision: ";
    mostrarComision(C);

    cout << "Cantidad de alumnos (Se espera 3): " << cantidad(C) << endl;

    C = bajaUltimo(C);
    cout << "\nElimino ultimo inscripto de comision: ";
    mostrarComision(C);

    cout << "Muestro el ultimo inscripto (Se espera Juan): " << ultimoInscripto(C) << endl;

    cout << "Creo una comision C1 con Juan, Ana, Miguel, Pepe: ";
    Comision C1 = comisionVacia();
    C1 = altaAlumno(C1, "Juan");
    C1 = altaAlumno(C1, "Ana");
    C1 = altaAlumno(C1, "Miguel");
    C1 = altaAlumno(C1, "Pepe");
    mostrarComision(C1);

    cout << "Creo una comision C2 con Manu, Miguel, Sol, Jose: ";
    Comision C2 = comisionVacia();
    C2 = altaAlumno(C2, "Manu");
    C2 = altaAlumno(C2, "Miguel");
    C2 = altaAlumno(C2, "Sol");
    C2 = altaAlumno(C2, "Jose");
    mostrarComision(C2);

    cout << "\nHay comunes entre C1 y C2? (se espera SI): " << (hayComunes(C1, C2) ? "SI" : "NO") << endl;
    cout << "Hay comunes entre C y C2? (se espera No): " << (hayComunes(C, C2) ? "SI" : "NO") << endl;

    Comision rep = repetidos(&C1, &C2);

    cout << "Creo una comision con los repetidos de C1 y C2: ";
    mostrarComision(rep);

    cout << "Muestro C1 luego de la funcion repetidos: ";
    mostrarComision(C1);

    cout << "Muestro C2 luego de la funcion repetidos: ";
    mostrarComision(C2);

    cout << "\nLibero todas las comisiones";

    while(!estaVacia(C))
    {
        C = bajaUltimo(C);
    }

    while(!estaVacia(C1))
    {
        C1 = bajaUltimo(C1);
    }

    while(!estaVacia(C1))
    {
        C2 = bajaUltimo(C2);
    }

    while(!estaVacia(rep))
    {
        rep = bajaUltimo(rep);
    }
    return 0;
}

Comision repetidos (Comision* C1, Comision* C2)
{
    Comision C = comisionVacia();
    while (!estaVacia(*C1))
    {
        if (esta(*C2, ultimoInscripto(*C1)))
        {
            C = altaAlumno(C, ultimoInscripto(*C1));
        }
        *C1 = bajaUltimo(*C1);
    }
    return C;
}