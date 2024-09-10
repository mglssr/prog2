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
}

void imprimirTClientesABB(TClientesABB clientesABB){
    if (clientesABB != NULL){
        imprimirTClientesABB(clientesABB->izquierdo);
        imprimirTCliente(clientesABB->cliente);
        imprimirTClientesABB(clientesABB->derecho);
    }
}

void liberarnodo(TClientesABB nodo){
    liberarTCliente(nodo->cliente);
    delete(nodo);
    nodo = NULL;
}

void liberarTClientesABB(TClientesABB &clientesABB){
    if (clientesABB != NULL){
        liberarTClientesABB(clientesABB->izquierdo);
        liberarTClientesABB(clientesABB->derecho);
        liberarnodo(clientesABB);
    }
    clientesABB = NULL;
}

bool existeTClienteTClientesABB(TClientesABB clientesABB, int idCliente){
    if (clientesABB != NULL){
        if (idTCliente(clientesABB->cliente) == idCliente){
            return true;
        }
        else {
            return(existeTClienteTClientesABB(clientesABB->izquierdo, idCliente) || existeTClienteTClientesABB(clientesABB->derecho, idCliente));
        }
    }
    return false;
}

TCliente obtenerTClienteTClientesABB(TClientesABB clientesABB, int idCliente){
    if (clientesABB != NULL){
        if (idTCliente(clientesABB->cliente) == idCliente){
            return clientesABB->cliente;
        }
        else if(idCliente < idTCliente(clientesABB->cliente)){
            return obtenerTClienteTClientesABB(clientesABB->izquierdo, idCliente);
        }
        else{
            return obtenerTClienteTClientesABB(clientesABB->derecho, idCliente);
        }
    }
    return NULL;
}

nat alturaTClientesABB(TClientesABB clientesABB){
    nat alt_der, alt_izq;
    if (clientesABB == NULL){
        return 0;
    }
    else {
        alt_der = alturaTClientesABB(clientesABB->derecho);
        alt_izq = alturaTClientesABB(clientesABB->izquierdo);
        if (alt_der < alt_izq){
            return (alt_izq + 1);
        }
        else{
            return (alt_der + 1);
        }
    }
}

TCliente maxIdTClienteTClientesABB(TClientesABB clientesABB){
    if (clientesABB == NULL){
        return NULL;
    }
    else{
        while(clientesABB->derecho != NULL){
            clientesABB = clientesABB->derecho;
        }
        return clientesABB->cliente;
    }
}

void removerTClienteTClientesABB(TClientesABB &clientesABB, int idCliente){
    TClientesABB aux;
    if (clientesABB != NULL){
        if(idTCliente(clientesABB->cliente) == idCliente){
            if (clientesABB->izquierdo == NULL){
                aux = clientesABB;
                clientesABB = clientesABB->derecho;
                liberarnodo(aux);
            }
            else if (clientesABB->derecho == NULL){
                aux = clientesABB;
                clientesABB = clientesABB->izquierdo;
                liberarnodo(aux);
            }
            else if (clientesABB->izquierdo != NULL && clientesABB->derecho != NULL){
                clientesABB->cliente = maxIdTClienteTClientesABB(clientesABB->izquierdo);
                removerTClienteTClientesABB(clientesABB->izquierdo, idTCliente(clientesABB->cliente));
            }
            else{
                liberarnodo(clientesABB);
            }
        }
        else if(idCliente < idTCliente(clientesABB->cliente)){
            removerTClienteTClientesABB(clientesABB->izquierdo, idCliente);
        }
        else{
            removerTClienteTClientesABB(clientesABB->derecho, idCliente);
        }
    }
}
        //if (idCliente < idTCliente(clientesABB->cliente)){
           // removerTClienteTClientesABB(clientesABB->izquierdo, idCliente);
        //}
        //else if (idCliente > idTCliente(clientesABB->cliente)){
            // removerTClienteTClientesABB(clientesABB->derecho, idCliente);
        // }
        // else{
            // if (clientesABB->derecho == NULL){
                // lientesABB borrarn = clientesABB;
    //             clientesABB = clientesABB->izquierdo;
    //             liberarnodo(borrarn);
    //         }
    //         else if (clientesABB->izquierdo == NULL){
    //             TClientesABB borrarn = clientesABB;
    //             clientesABB = clientesABB->derecho;
    //             liberarnodo(borrarn);
    //         }
    //         else if (clientesABB->derecho != NULL && clientesABB->izquierdo != NULL){
    //             TCliente mayor = maxIdTClienteTClientesABB(clientesABB->izquierdo);
    //             clientesABB->cliente = mayor;
    //             removerTClienteTClientesABB(clientesABB->izquierdo, idTCliente(mayor));
    //         }
    //         else{
    //             liberarnodo(clientesABB);
    //         }
    //     }
    // }


int cantidadClientesTClientesABB(TClientesABB clientesABB){
    return 0;
}

float edadPromedioTClientesABB(TClientesABB clientesABB){
    return 0.;
}

TCliente obtenerNesimoClienteTClientesABB(TClientesABB clientesABB, int n){
    return NULL;
}

