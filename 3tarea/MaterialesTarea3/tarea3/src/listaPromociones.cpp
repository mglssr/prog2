#include "../include/listaPromociones.h"

struct rep_listaPromociones {
  TListaPromociones sig;
  TPromocion promociones;
};

TListaPromociones crearTListaPromocionesVacia() { return NULL; }

void agregarPromocionTListaPromociones(TListaPromociones &listaPromociones, TPromocion promocion) {
    if (listaPromociones == NULL || compararTFechas(fechaInicioTPromocion(listaPromociones->promociones), fechaInicioTPromocion(promocion)) == 1) {
        TListaPromociones nueva = new rep_listaPromociones;
        nueva->promociones = promocion;
        nueva->sig = listaPromociones;  // Conecta el nuevo nodo al inicio
        listaPromociones = nueva;
    }
    else {
        TListaPromociones nueva = new rep_listaPromociones;
        nueva->promociones = promocion;
        TListaPromociones aux = listaPromociones;
        while (aux->sig != NULL && compararTFechas(fechaInicioTPromocion(aux->sig->promociones), fechaInicioTPromocion(promocion)) == -1) {
            aux = aux->sig;
        }
        nueva->sig = aux->sig;
        aux->sig = nueva;
    } 
}

// void agregarPromocionTListaPromociones(TListaPromociones &listaPromociones, TPromocion promocion) {
//     if (listaPromociones == NULL || compararTFechas(fechaInicioTPromocion(listaPromociones->promociones), fechaInicioTPromocion(promocion))== 1){
//         TListaPromociones nueva = new rep_listaPromociones;
//         nueva->promociones = promocion;
//         nueva->sig = NULL;
//         nueva->sig = listaPromociones;
//         listaPromociones = nueva;

//     }
//     else{
//         TListaPromociones nueva = new rep_listaPromociones;
//         nueva->promociones = promocion;
//         nueva->sig = NULL;
//         TListaPromociones aux = listaPromociones;
//         while(aux->sig != NULL && compararTFechas(fechaInicioTPromocion(aux->sig->promociones), fechaInicioTPromocion(promocion)) == -1){
//             aux = aux->sig;
//         }
//         nueva->sig = aux->sig;
//         aux->sig = nueva;
//     } 
// }

void imprimirTListaPromociones(TListaPromociones listaPromociones) {
    TListaPromociones aux = listaPromociones;
    while (aux != NULL)
    {
        imprimirTPromocion(aux->promociones);
        aux = aux->sig;
    }
}

void liberarTListaPromociones(TListaPromociones &listaPromociones, bool liberarPromociones) {
    TListaPromociones aux = listaPromociones;
    if (aux != NULL){

        listaPromociones = listaPromociones->sig;
        liberarTPromocion(aux->promociones);
        delete aux;
        if (liberarPromociones){
            while (listaPromociones != NULL)
            {
                aux = listaPromociones;
                listaPromociones = listaPromociones->sig;
                liberarTPromocion(aux->promociones);
                delete aux;
            }
        }
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

TPromocion obtenerPromocionTListaPromociones(TListaPromociones listaPromociones, int idPromocion) {                              
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

TListaPromociones obtenerPromocionesFinalizadas(TListaPromociones &listaPromociones,TFecha fecha) {
    TListaPromociones finalizadas = NULL;

    if (listaPromociones != NULL) {
        TListaPromociones aux = listaPromociones;
        TListaPromociones finfin = NULL;
        TListaPromociones prev = NULL;

        while (aux != NULL) {
            if (compararTFechas(fecha, fechaFinTPromocion(aux->promociones)) >= 0) {
                TListaPromociones nodo = new rep_listaPromociones;
                nodo->promociones = aux->promociones;
                nodo->sig = NULL;

                if (finalizadas == NULL) {
                    finalizadas = nodo;
                    finfin = finalizadas;
                } else {
                    finfin->sig = nodo;
                    finfin = finfin->sig;
                }

                if (prev == NULL) {listaPromociones = aux->sig;} 
                else {prev->sig = aux->sig;}

                TListaPromociones aBorrar = aux;
                aux = aux->sig;
                delete aBorrar;
            } else {
                prev = aux;
                aux = aux->sig;
            }
        }
    }

    return finalizadas;
}

TListaPromociones obtenerPromocionesActivas(TListaPromociones &listaPromociones,TFecha fecha) {
    TListaPromociones activas = NULL;
    if (listaPromociones != NULL) {
        
        TListaPromociones ActAux = NULL;
        TListaPromociones aux = listaPromociones;
        TListaPromociones prev = NULL;

        while (aux != NULL) {
            if (((compararTFechas(fecha, fechaInicioTPromocion(aux->promociones))) >= 0) || 
                ((compararTFechas(fecha, fechaFinTPromocion(aux->promociones)) <= 0) &&
                (compararTFechas(fecha, fechaFinTPromocion(aux->promociones)) >= 0))){ 
                
                TListaPromociones nodo = new rep_listaPromociones;
                nodo->promociones = aux->promociones;
                nodo->sig = NULL;

                if (activas == NULL) {
                    activas = nodo;
                    ActAux = activas;
                } else {
                    ActAux->sig = nodo;
                    ActAux = ActAux->sig;
                }

                if (prev == NULL) {listaPromociones = aux->sig;}
                else {prev->sig = aux->sig;}

                TListaPromociones aBorrar = aux;
                aux = aux->sig;
                delete aBorrar;
            
            } else {
                prev = aux;
                aux = aux->sig;
            }
        }
    }

    return activas;
}

bool esCompatibleTListaPromociones(TListaPromociones listaPromociones,TPromocion promocion) {
    TListaPromociones aux = listaPromociones;
    if (listaPromociones != NULL){
        while (aux != NULL && sonPromocionesCompatibles(aux->promociones, promocion)){aux = aux->sig;}
    }
    return aux == NULL;
}

TListaPromociones unirListaPromociones(TListaPromociones listaPromociones1, TListaPromociones listaPromociones2) {
    TListaPromociones nueva = NULL;
    TListaPromociones fin = nueva;
    while (listaPromociones1 != NULL){

        agregarPromocionTListaPromociones(fin, listaPromociones1->promociones);
        fin = fin->sig;
        listaPromociones1 = listaPromociones1->sig;
    }
    
    // while (listaPromociones1 != NULL && listaPromociones2 != NULL){
    //     TListaPromociones nodo = NULL;
    //     if(idTPromocion(listaPromociones1->promociones) < idTPromocion(listaPromociones2->promociones)){
    //         TListaPromociones nodo = new rep_listaPromociones;
    //         nodo->promociones = listaPromociones1->promociones;
    //         listaPromociones1 = listaPromociones1->sig;
    //         nodo->sig = NULL;
    //     }else {
    //         TListaPromociones nodo = new rep_listaPromociones;
    //         nodo->promociones = listaPromociones2->promociones;
    //         listaPromociones2 = listaPromociones2->sig;
    //         nodo->sig = NULL;
    //     }
        

    //     if (nueva == NULL) {
    //         nueva = nodo;
    //         fin = nueva;
    //     } else {
    //         fin->sig = nodo;
    //         fin = fin->sig;
    //     }
    // }
    return nueva;
}
