#include "../include/producto.h"

// Define el tipo TProducto como un puntero a rep_producto
struct rep_producto {
    int id;
    char nombre[MAX_NOMBRE_PRODUCTO];
    TFecha fechaIng;
    int precio;
};

// Función que crea un elemento de tipo TProducto con los valores pasados como
// parámetro 
TProducto crearTProducto(int id, const char nombre[MAX_NOMBRE_PRODUCTO], int precio, TFecha fechaIngreso){
    TProducto nuevoproducto = NULL;
    
    nuevoproducto = new rep_producto;
    
    nuevoproducto->id = id;
    strcpy(nuevoproducto->nombre,nombre);
    nuevoproducto->precio = precio;
    nuevoproducto->fechaIng = fechaIngreso;
    
    return nuevoproducto;
}

// Función que retorna el id del producto
int idTProducto(TProducto producto){
    return producto->id;
}

// Función que retorna el precio del producto
int precioTProducto(TProducto producto){
    return producto->precio;
}

// Función que imprime la información de un producto en el siguiente formato:
// Producto: <Id>
// <NombreProducto>
// Precio: <precio>
// Ingresado el: <Fecha>
void imprimirTProducto(TProducto producto){
    printf("Producto: %d\n", producto->id);
    printf("%s\n", producto->nombre);
    printf("Precio: %d\n", producto->precio);
    printf("Ingresado el: ");
    imprimirTFecha(producto->fechaIng);
}

// Función que libera la memoria asociada a un producto
void liberarTProducto(TProducto &producto){
    liberarTFecha(producto->fechaIng);
    delete producto;
    producto = NULL;
}


