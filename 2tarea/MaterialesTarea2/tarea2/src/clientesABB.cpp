#include "../include/clientesABB.h"

struct rep_clientesABB {
    TCliente cliente;
    TClientesABB derecho, izquierdo;
};

TClientesABB crearTClientesABBVacio(){
    return NULL;
}

void insertarTClienteTClientesABB(TClientesABB &clientesABB, TCliente cliente){
    
    if (clientesABB == NULL){
        TClientesABB nuevo = new rep_clientesABB;
        nuevo->cliente = cliente;
        nuevo->derecho = nuevo->izquierdo = NULL;
        clientesABB = nuevo;
    }
    else if(idTCliente(cliente) < idTCliente(clientesABB->cliente)){
        insertarTClienteTClientesABB(clientesABB->izquierdo, cliente);
    }
    else if(idTCliente(cliente) > idTCliente(clientesABB->cliente)){
        insertarTClienteTClientesABB(clientesABB->derecho, cliente);
    }
        //TClientesABB nuevo = new rep_clientesABB;
        //nuevo->cliente = cliente;
}

void imprimirTClientesABB(TClientesABB clientesABB){
    if (clientesABB != NULL){
        imprimirTCliente(clientesABB->cliente);
        imprimirTClientesABB(clientesABB->izquierdo);
        imprimirTClientesABB(clientesABB->derecho);
    }
}

void liberarnodo(TClientesABB nodo){
    liberarTCliente(nodo->cliente);
    delete(nodo);
    nodo = NULL;
}
//hacer una funcion que libere un nodo de forma individual
void liberarTClientesABB(TClientesABB &clientesABB){
    if (clientesABB != NULL){
        liberarTClientesABB(clientesABB->izquierdo);
        liberarTClientesABB(clientesABB->derecho);
        liberarnodo(clientesABB);
    }
    clientesABB = NULL;
}

bool existeTClienteTClientesABB(TClientesABB clientesABB, int idCliente){
    return false;
}

TCliente obtenerTClienteTClientesABB(TClientesABB clientesABB, int idCliente){
    return NULL;
}

nat alturaTClientesABB(TClientesABB clientesABB){
    nat alt_der, alt_izq;
    if (clientesABB == NULL || (clientesABB->derecho == NULL && clientesABB->izquierdo == NULL)){
        return 0;
    }
    alt_der = alturaTClientesABB(clientesABB->derecho);
    alt_izq = alturaTClientesABB(clientesABB->izquierdo);
    if (alt_der < alt_izq){
        return (alt_izq + 1);
    }
    else{
        return (alt_der + 1);
    }
}

TCliente maxIdTClienteTClientesABB(TClientesABB clientesABB){
    return NULL;
}

void removerTClienteTClientesABB(TClientesABB &clientesABB, int idCliente){

}

int cantidadClientesTClientesABB(TClientesABB clientesABB){
    return 0;
}

float edadPromedioTClientesABB(TClientesABB clientesABB){
    return 0.;
}

TCliente obtenerNesimoClienteTClientesABB(TClientesABB clientesABB, int n){
    return NULL;
}

