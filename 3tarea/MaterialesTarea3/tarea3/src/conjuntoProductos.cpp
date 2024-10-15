#include "../include/conjuntoProductos.h"


// Definición de tipo TConjuntoProductos como un puntero a rep_conjuntoproductos
// El conjunto es acotado, y la cantidad máxima de elementos define el rango de 
// identificadores que almacena.
// Los identificadores que almacena el conjunto cumplen 0 <= id < cantMax
struct rep_conjuntoProductos{
    int tope, cantMax;
    bool* productos;
};

TConjuntoProductos crearTConjuntoProductos(int cantMax){
    TConjuntoProductos nuevoSet = new rep_conjuntoProductos;
    nuevoSet->productos = new bool[cantMax];
    nuevoSet->tope = 0;
    nuevoSet->cantMax = cantMax;
    for (int i = 0; i < cantMax; i++){
        nuevoSet->productos[i] = false;
    }
    return nuevoSet;
}

void insertarTConjuntoProductos(TConjuntoProductos &conjuntoProductos, int idProducto){
    if (idProducto < conjuntoProductos->cantMax && !(conjuntoProductos->productos[idProducto])){
        conjuntoProductos->productos[idProducto] = true;
        conjuntoProductos->tope += 1;
    }
}

void imprimirTConjuntoProductos(TConjuntoProductos conjuntoProductos){
    for (int i = 0; i < conjuntoProductos->cantMax; i++){
        if (conjuntoProductos->productos[i]){
            printf("%d ",i);
        }
    }
    printf("\n");
}
void liberarTConjuntoProductos(TConjuntoProductos &conjuntoProductos){
    delete[] conjuntoProductos->productos;
    delete conjuntoProductos;
    conjuntoProductos = NULL;
}

bool esVacioTConjuntoProductos(TConjuntoProductos conjuntoProductos){ return (conjuntoProductos->tope == 0); }

int cantidadTConjuntoProductos(TConjuntoProductos conjuntoProductos){ return conjuntoProductos->tope; }

int cantMaxTConjuntoProductos(TConjuntoProductos conjuntoProductos){ return conjuntoProductos->cantMax; }

bool perteneceTConjuntoProductos(TConjuntoProductos conjuntoProductos, int idProducto){ 
    if (idProducto < conjuntoProductos->cantMax && (conjuntoProductos->productos[idProducto])){
        return conjuntoProductos->productos[idProducto]; 
    }
    return false;
}

void borrarDeTConjuntoProductos(TConjuntoProductos &conjuntoProductos, int idProducto){
    if (conjuntoProductos->productos[idProducto]){
        conjuntoProductos->productos[idProducto] = false;
        conjuntoProductos->tope -= 1;
    }
}

TConjuntoProductos unionTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2){ 
    TConjuntoProductos joinSet = crearTConjuntoProductos(conjuntoProductos1->cantMax);
    for (int i = 0; i < conjuntoProductos1->cantMax; i++)
    {
        if (perteneceTConjuntoProductos(conjuntoProductos1, i) || perteneceTConjuntoProductos(conjuntoProductos2, i)){
            insertarTConjuntoProductos(joinSet, i);
        }
    }
    return joinSet;
}

TConjuntoProductos interseccionTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2){ 
    TConjuntoProductos joinSet = crearTConjuntoProductos(conjuntoProductos1->cantMax);
    int cantimax;
    if (conjuntoProductos1->cantMax > conjuntoProductos2->cantMax){cantimax = conjuntoProductos1->cantMax; }
    else {cantimax  = conjuntoProductos2->cantMax;}

    for (int i = 0; i < cantimax; i++)
    {
        if (perteneceTConjuntoProductos(conjuntoProductos1, i) && perteneceTConjuntoProductos(conjuntoProductos2, i)){
            insertarTConjuntoProductos(joinSet, i);
        }
    }
    return joinSet;
}

TConjuntoProductos diferenciaTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2){
    TConjuntoProductos joinSet = crearTConjuntoProductos(conjuntoProductos1->cantMax);
    for (int i = 0; i < conjuntoProductos1->cantMax; i++)
    {
        if ((perteneceTConjuntoProductos(conjuntoProductos1, i) && !(perteneceTConjuntoProductos(conjuntoProductos2, i)))){
            insertarTConjuntoProductos(joinSet, i);
        }
    }
    return joinSet;
 }
