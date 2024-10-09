#include "../include/listaPromociones.h"

struct rep_listaPromociones {
  TPromocion promociones;
  TListaPromociones sig;
};

TListaPromociones crearTListaPromocionesVacia() { return NULL; }

void agregarPromocionTListaPromociones(TListaPromociones &listaPromociones, TPromocion promocion) {
    TFecha fecIni = fechaInicioTPromocion(promocion);
    TListaPromociones nueva = new rep_listaPromociones;
    nueva->promociones = promocion;
    if (listaPromociones == NULL || compararTFechas(fechaFinTPromocion(listaPromociones->promociones), fecIni)== 1){
        nueva->sig = listaPromociones;
        listaPromociones = nueva;
    }
    else{
        TListaPromociones aux = listaPromociones;
        while(aux->sig != NULL && compararTFechas(fechaFinTPromocion(aux->sig->promociones), fecIni) == -1){
            aux = aux->sig;
        }
        nueva->sig = aux->sig;
        aux->sig = nueva;
    }
}

void imprimirTListaPromociones(TListaPromociones listaPromociones) {
    TListaPromociones aux = listaPromociones;
    while (aux != NULL)
    {
        imprimirTPromocion(aux->promociones);
        aux = aux->sig;
    }
}

void liberarTListaPromociones(TListaPromociones &listaPromociones, bool liberarPromociones) {
    TListaPromociones aux;
    while (listaPromociones != NULL)
    {
        aux = listaPromociones;
        listaPromociones = listaPromociones->sig;
        liberarTPromocion(aux->promociones);
        delete aux;
    }
}

bool esVaciaTListaPromociones(TListaPromociones promociones) { return promociones == NULL; }

bool pertenecePromocionTListaPromociones(TListaPromociones listaPromociones, int idPromocion) {
    TListaPromociones aux = listaPromociones;
    while (aux != NULL && idTPromocion(aux->promociones) != idPromocion)
    {
        aux = aux->sig;
    }
    return aux != NULL;
}

TPromocion obtenerPromocionTListaPromociones(TListaPromociones listaPromociones,
                                             int idPromocion) {
    TPromocion res = NULL;
    TListaPromociones iter = listaPromociones;
    while (iter != NULL && !res) {
        if (idPromocion == idTPromocion(iter->promociones)) {
            res = iter->promociones;
        }
        iter = iter->sig;
    }
    return res;
}


TListaPromociones obtenerPromocionesFinalizadas(TListaPromociones &listaPromociones,
                                                TFecha fecha) {
  return NULL;
}

TListaPromociones obtenerPromocionesActivas(TListaPromociones &listaPromociones,
                                            TFecha fecha) {
  return NULL;
}

bool esCompatibleTListaPromociones(TListaPromociones listaPromociones,
                                   TPromocion promocion) {
  return false;
}

TListaPromociones unirListaPromociones(TListaPromociones listaPromociones1,
                                       TListaPromociones listaPromociones2) {
  return NULL;
}
