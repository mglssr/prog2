#include "../include/conjuntoProductos.h"


// Definición de tipo TConjuntoProductos como un puntero a rep_conjuntoproductos
// El conjunto es acotado, y la cantidad máxima de elementos define el rango de 
// identificadores que almacena.
// Los identificadores que almacena el conjunto cumplen 0 <= id < cantMax
struct rep_conjuntoProductos{

};

TConjuntoProductos crearTConjuntoProductos(int cantMax){ return NULL; }

void insertarTConjuntoProductos(TConjuntoProductos &conjuntoProductos, int idProducto){}

void imprimirTConjuntoProductos(TConjuntoProductos conjuntoProductos){}

void liberarTConjuntoProductos(TConjuntoProductos &conjuntoProductos){}

bool esVacioTConjuntoProductos(TConjuntoProductos conjuntoProductos){ return false; }

int cantidadTConjuntoProductos(TConjuntoProductos conjuntoProductos){ return 0; }

int cantMaxTConjuntoProductos(TConjuntoProductos conjuntoProductos){ return 0; }

bool perteneceTConjuntoProductos(TConjuntoProductos conjuntoProductos, int idProducto){ return false; }

void borrarDeTConjuntoProductos(TConjuntoProductos &conjuntoProductos, int idProducto){}

TConjuntoProductos unionTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2){ return NULL; }

TConjuntoProductos interseccionTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2){ return NULL; }

TConjuntoProductos diferenciaTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2){ return NULL; }
