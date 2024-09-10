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
        clientesABB = new rep_clientesABB;
        clientesABB->cliente = cliente;
        clientesABB->derecho = clientesABB->izquierdo = NULL;
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

//funcion auxiliar
void liberarnodo(TClientesABB &nodo){
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
}

bool existeTClienteTClientesABB(TClientesABB clientesABB, int idCliente){
    if (clientesABB != NULL){
        if (idTCliente(clientesABB->cliente) == idCliente){
            return true;
        }
        else if(idCliente < idTCliente(clientesABB->cliente)){
            return existeTClienteTClientesABB(clientesABB->izquierdo, idCliente);
        }
        else if(idCliente > idTCliente(clientesABB->cliente)){
            return existeTClienteTClientesABB(clientesABB->derecho, idCliente);
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
    if (clientesABB->derecho == NULL){
        return clientesABB->cliente;
    }
    else{
        return(maxIdTClienteTClientesABB(clientesABB->derecho));
    }
}

void removerTClienteTClientesABB(TClientesABB &clientesABB, int idCliente){
    if(idTCliente(clientesABB->cliente) == idCliente){
        liberarTCliente(clientesABB->cliente);
        if (clientesABB->izquierdo == NULL && clientesABB->derecho == NULL){
            delete clientesABB;
            clientesABB = NULL;
        }
        else if (clientesABB->izquierdo == NULL && clientesABB->derecho != NULL){
            TClientesABB aux = clientesABB;
            clientesABB = clientesABB->derecho;
            delete aux;
            aux = NULL;
        }
        else if (clientesABB->derecho == NULL && clientesABB->izquierdo != NULL){
            TClientesABB aux = clientesABB;
            clientesABB = clientesABB->izquierdo;
            delete aux;
            aux = NULL;
        }
        else{
            clientesABB->cliente = copiarTCliente(maxIdTClienteTClientesABB(clientesABB->izquierdo));
            removerTClienteTClientesABB(clientesABB->izquierdo, idTCliente(clientesABB->cliente));
        }
    }
    else if(idCliente < idTCliente(clientesABB->cliente)){
        removerTClienteTClientesABB(clientesABB->izquierdo, idCliente);
    }
    else{
        removerTClienteTClientesABB(clientesABB->derecho, idCliente);
    }

}

int cantidadClientesTClientesABB(TClientesABB clientesABB){
    if (clientesABB == NULL){
        return 0;
    }
    else{
        return (1 + cantidadClientesTClientesABB(clientesABB->izquierdo) + cantidadClientesTClientesABB(clientesABB->derecho));
    }
}

int sumaedades(TClientesABB clientesABB){
    int prom = 0;
    if (clientesABB == NULL){
        return prom;
    }
    else{
        prom = edadTCliente(clientesABB->cliente) + edadPromedioTClientesABB(clientesABB->izquierdo) + edadPromedioTClientesABB(clientesABB->derecho);
        return prom;
    }
}

float edadPromedioTClientesABB(TClientesABB clientesABB){
    if (clientesABB == NULL){
        return 0;
    }
    else{
        int cant = cantidadClientesTClientesABB(clientesABB);
        int sum = sumaedades(clientesABB);
        return (sum / cant); 
    }
    //if (clientesABB == NULL){
    //    return prom;
    //}
    //else{
    //    prom += edadTCliente(clientesABB->cliente) + edadPromedioTClientesABB(clientesABB->izquierdo) + edadPromedioTClientesABB(clientesABB->derecho);
    //    return prom;
    //}
}

TCliente obtenerNesimoClienteTClientesABB(TClientesABB clientesABB, int n){
    return NULL;
}

