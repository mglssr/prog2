#include "../include/historial.h"

struct rep_historial {
    TListaPromociones pasadas, futuras, activas;
    TFecha actual;
};

THistorial crearTHistorial(TFecha fecha) { 
    THistorial nuevo = new rep_historial;
    nuevo->actual = fecha;
    nuevo->activas = NULL;
    nuevo->futuras = NULL;
    nuevo->pasadas = NULL;
    return nuevo;
}

void liberarTHistorial(THistorial &historial) {
    liberarTListaPromociones(historial->activas, true);
    liberarTListaPromociones(historial->futuras, true);
    liberarTListaPromociones(historial->pasadas, true);
    liberarTFecha(historial->actual);
    delete historial;
    historial = NULL;
}
void agregarPromocionTHistorial(THistorial historial, TPromocion promocion) {
    if (compararTFechas(fechaInicioTPromocion(promocion), historial->actual) > 0){
        agregarPromocionTListaPromociones(historial->futuras, promocion);
    }
    else if(compararTFechas(fechaFinTPromocion(promocion), historial->actual) <= 0){
        agregarPromocionTListaPromociones(historial->pasadas, promocion);
    }
    else{
        agregarPromocionTListaPromociones(historial->activas, promocion);
    }
}

void agregarProductoAPromocionTHistorial(THistorial historial, TProducto producto, int idPromo) {
    if (pertenecePromocionTListaPromociones(historial->activas, idPromo)){
        TPromocion promo = obtenerPromocionTListaPromociones(historial->activas, idPromo);
        agregarATPromocion(promo, producto);
    }
    else if (pertenecePromocionTListaPromociones(historial->futuras, idPromo)){
        TPromocion promo = obtenerPromocionTListaPromociones(historial->futuras, idPromo);
        agregarATPromocion(promo, producto);
    }
    else{
        TPromocion promo = obtenerPromocionTListaPromociones(historial->pasadas, idPromo);
        agregarATPromocion(promo, producto);
    }
}

void avanzarAFechaTHistorial(THistorial historial, TFecha fecha) {
    TListaPromociones pasadas, activas;
    liberarTFecha(historial->actual);
    historial->actual = fecha;
    
    TListaPromociones finalAct = obtenerPromocionesFinalizadas(historial->activas, fecha);
    pasadas = unirListaPromociones(finalAct, historial->pasadas);
    liberarTListaPromociones(historial->pasadas, false);
    historial->pasadas = pasadas;
    //liberarTListaPromociones(finalAct, false);
    if (historial->activas){
        TListaPromociones finalFut = obtenerPromocionesFinalizadas(historial->futuras, fecha);
        historial->activas = unirListaPromociones(finalFut, historial->activas);
        //liberarTListaPromociones(finalFut,false);
    }
    TListaPromociones finFut = obtenerPromocionesFinalizadas(historial->futuras, fecha);
    historial->activas = unirListaPromociones(finFut, historial->activas);
    //liberarTListaPromociones(finFut,false);
    TListaPromociones actFut = obtenerPromocionesActivas(historial->futuras, fecha);
    activas = unirListaPromociones(actFut, historial->activas);
    liberarTListaPromociones(historial->activas, false);
    historial->activas = activas;
    liberarTListaPromociones(actFut, false);
}
                                         

void imprimirPromocionesFinalizadosTHistorial(THistorial historial) {
    if (historial != NULL){imprimirTListaPromociones(historial->pasadas);}
}

void imprimirPromocionesActivasTHistorial(THistorial historial) {
    if (historial != NULL){
        imprimirTListaPromociones(historial->activas);
    }
}

void imprimirPromocionesFuturasTHistorial(THistorial historial) {
    if (historial != NULL){
    imprimirTListaPromociones(historial->futuras);
    }
}

bool esCompatiblePromocionTHistorial(THistorial historial, TPromocion promocion) { 
    return esCompatibleTListaPromociones(historial->activas, promocion) && 
            esCompatibleTListaPromociones(historial->futuras, promocion) && 
            esCompatibleTListaPromociones(historial->pasadas, promocion);
}

