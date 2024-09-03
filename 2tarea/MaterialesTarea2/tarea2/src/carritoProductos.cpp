#include "../include/carritoProductos.h"

// Define el tipo TCarritoProductos como un puntero a rep_carrito
struct rep_carritoProductos{
    TProducto producto;
    TCarritoProductos sig;
};

// Función para crear un elemento de tipo TCarritoProductos.
// Devuelve un carrito de productos vacío.
TCarritoProductos crearCarritoProductosVacio(){
    return NULL;
}

// Función para agregar un producto a un carrito de productos.
// Inserta el producto en el carrito, ordenado de menor a mayor por ID producto.
void insertarProductoCarritoProductos(TCarritoProductos &carritoProductos, TProducto producto){
    
    if (carritoProductos == NULL){
        TCarritoProductos nuevo = new rep_carritoProductos;
        nuevo->producto = producto;
        nuevo->sig = NULL;
        carritoProductos = nuevo;
    }
    else{
        TCarritoProductos nuevo = new rep_carritoProductos;
        nuevo->producto = producto;
        nuevo->sig = NULL;
        if (idTProducto(carritoProductos->producto) > idTProducto(producto)){
            nuevo->sig = carritoProductos;
            carritoProductos = nuevo;
        }
        else{
            TCarritoProductos aux = carritoProductos;
            while((aux->sig != NULL) && (idTProducto(aux->sig->producto) < idTProducto(producto))){
                aux = aux->sig;
            }
            nuevo->sig = aux->sig;
            aux->sig = nuevo;
        }
    }
}


void imprimirCarritoProductos(TCarritoProductos carritoProductos){
    while(carritoProductos != NULL){
        imprimirTProducto(carritoProductos->producto);
        carritoProductos = carritoProductos->sig;
    }
}

void liberarCarritoProductos(TCarritoProductos &carritoProductos){
    TCarritoProductos actual, next;
    actual = carritoProductos;
    while((actual != NULL) && (carritoProductos != NULL)){
        next = actual;
        actual = actual->sig;
        liberarTProducto(next->producto);
        delete (next);
    }
    carritoProductos = NULL;

}

// Funcion para verificar si una carrito de productos es vacio, retorna true si y solo si el carrito es vacío
bool esVacioCarritoProductos(TCarritoProductos carritoProductos){
    return (carritoProductos == NULL);
}

// Función para verificar si un producto existe en un carrito de productos.
// Recibe una carrito de productos y un id de producto y regresa un booleano indicando su existencia.
bool existeProductoCarritoProductos(TCarritoProductos carritoProductos, int idProducto){
    bool esta = false;
    while ((esta == false) && (carritoProductos != NULL)){
        
        if (idTProducto(carritoProductos->producto) == idProducto){
            esta = true;
        }
        carritoProductos = carritoProductos->sig;
    }
    return esta;
}

// Función para obtener un producto de un carrito de productos.
// Recibe un carrito y un id de producto y regresa el producto con ese id.
// PRE: El producto debe estar en el carrito.
TProducto obtenerProductoCarritoProductos(TCarritoProductos carritoProductos, int idProducto){
    TProducto prod;
    while (idTProducto(carritoProductos->producto) != idProducto){
        carritoProductos = carritoProductos->sig;
    }
    prod = carritoProductos->producto;
    return prod;
}

// Función para remover un producto de un carrito.
// Recibe un carrito de productos y un id de producto y elimina el producto con ese id.
// También elimina la memoria asociada a dicho producto.
void removerProductoCarritoProductos(TCarritoProductos &carritoProductos, int idProducto){
    TCarritoProductos actual;
    actual = carritoProductos;
    
    if (idTProducto(carritoProductos->producto) == idProducto){
        carritoProductos = carritoProductos->sig;
        liberarTProducto(actual->producto);
        delete (actual);
    }
    else{
        TCarritoProductos prev = actual;
        while ((actual->sig != NULL) && (idTProducto(actual->producto) != idProducto)){
            prev = actual;
            actual = actual->sig;
        }
        
        if (actual->sig != NULL){
            prev->sig = actual->sig;
            liberarTProducto(actual->producto);
            delete(actual);
        }
        else{
            prev->sig = NULL;
            liberarTProducto(actual->producto);
            delete(actual);
        }
    }
    
}