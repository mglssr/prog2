#include "../include/promocion.h"

//  La estructura almacena un id de tipo entero, dos fechas para representar el inicio y el fin 
// de la promocion, así como la información de qué productos forman parte de la promocion.
struct rep_promocion {
    int id;
    TFecha ini, fin;
    TConjuntoProductos productos;
};

TPromocion crearTPromocion(int idProm, TFecha ini, TFecha fin, int cantMax){
    TPromocion promo = new rep_promocion;
    promo->id = idProm;
    promo->ini = ini;
    promo->fin = fin;
    promo->productos = crearTConjuntoProductos(cantMax);
    return promo;
}

void agregarATPromocion(TPromocion &prom, TProducto p){insertarTConjuntoProductos(prom->productos, idTProducto(p));}

void imprimirTPromocion(TPromocion prom){
    printf("Promocion #%d del ", prom->id);
    imprimirTFecha(prom->ini);
    printf(" al ");
    imprimirTFecha(prom->fin);
    printf("\nProductos: ");
    imprimirTConjuntoProductos(prom->productos);
}

void liberarTPromocion(TPromocion &prom){
    liberarTFecha(prom->ini);
    liberarTFecha(prom->fin);
    liberarTConjuntoProductos(prom->productos);
    delete prom;
    prom = NULL;
}

bool perteneceATPromocion(TPromocion prom, TProducto p){return perteneceTConjuntoProductos(prom->productos, idTProducto(p));}

int idTPromocion(TPromocion prom){ return prom->id; }

TFecha fechaInicioTPromocion(TPromocion prom){ return prom->ini; }

TFecha fechaFinTPromocion(TPromocion prom){ return prom->fin; }

bool sonPromocionesCompatibles(TPromocion prom1, TPromocion prom2){
    if (compararTFechas(prom1->fin, prom2->ini) == -1 || compararTFechas(prom2->fin, prom1->ini) == -1){return true;}
    else{
        TConjuntoProductos inter = interseccionTConjuntoProductos(prom1->productos, prom2->productos);
        bool res = esVacioTConjuntoProductos(inter);
        liberarTConjuntoProductos(inter);
        if (res){return true;}
    }
    return false;
 }

