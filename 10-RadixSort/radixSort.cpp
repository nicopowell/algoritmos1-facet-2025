#include <iostream>
#include <math.h>
#include "fila.h"
using namespace std;

void radixSort(int *V, int n, int k){
    Fila filas[10];
    int digito, l;
    for (int i = 0; i <= 9; i++)
    {
        filas[i] = filaVacia();
    }

    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            digito = (V[j]/((int)pow(10, i-1))) % 10;
            filas[digito] = enfila(filas[digito], V[j]);
        }
        l = 0;
        for (int j = 0; j <= 9; j++)
        {
            while (!esFilaVacia(filas[j]))
            {
                V[l] = frente(filas[j]);
                filas[j] = defila(filas[j]);
                l++;
            }
        }
    }    
}

void mostrarArreglo(int V[], int n){
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << " " << V[i] << " ";
    }
    cout << "]\n";
}

int main()
{
    int claves[] = {679, 345, 78, 126, 209, 508, 295, 63, 195, 230, 19, 721, 147, 345, 410};

    mostrarArreglo(claves, 15);
    
    radixSort(claves, 15, 3);
    
    mostrarArreglo(claves, 15);

    return 0;
}