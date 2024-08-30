#include "../include/carritoProductos.h"

// Define el tipo TCarritoProductos como un puntero a rep_carrito
struct rep_carritoProductos{
    TProducto producto;
    TCarritoProductos sig;
};

// Función para crear un elemento de tipo TCarritoProductos.
// Devuelve un carrito de productos vacío.
TCarritoProductos crearCarritoProductosVacio(){
    TCarritoProductos nuevocarrito = new rep_carritoProductos;
    nuevocarrito = NULL;
    return nuevocarrito;
}

void insertarProductoCarritoProductos(TCarritoProductos &carritoProductos, TProducto producto){

}

void imprimirCarritoProductos(TCarritoProductos carritoProductos){

}

void liberarCarritoProductos(TCarritoProductos &carritoProductos){

}

bool esVacioCarritoProductos(TCarritoProductos carritoProductos){
    return true;
}

bool existeProductoCarritoProductos(TCarritoProductos carritoProductos, int idProducto){
    return true;
}

TProducto obtenerProductoCarritoProductos(TCarritoProductos carritoProductos, int idProducto){
    return NULL;
}

void removerProductoCarritoProductos(TCarritoProductos &carritoProductos, int idProducto){

}