#include "../include/clientesSucursalesLDE.h"

struct aux_ClientesSucursal {
	int idSucursal;
	TClientesABB info;
	aux_ClientesSucursal *prev, *sig;
};

typedef struct aux_ClientesSucursal* ClientesSucursal;

struct rep_clientesSucursalesLDE {
	ClientesSucursal head, end;
};

TClientesSucursalesLDE crearTClientesSucursalesLDEVacia(){
	TClientesSucursalesLDE nuevo = new rep_clientesSucursalesLDE;
	nuevo->head = nuevo->end = NULL;
	return nuevo;
}

void insertarClientesABBTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, TClientesABB clientesABB, int idSucursal){
	ClientesSucursal nueva = new aux_ClientesSucursal;
	nueva->idSucursal = idSucursal;
	nueva->info = clientesABB;
	nueva->prev = nueva->sig = NULL;
	
	if (clientesSucursalesLDE->head == NULL){
		clientesSucursalesLDE->head = clientesSucursalesLDE->end = nueva;
	}
	else{	
		float prom = edadPromedioTClientesABB(clientesABB);
		if (prom < edadPromedioTClientesABB(clientesSucursalesLDE->head->info)){
			nueva->sig = clientesSucursalesLDE->head;
			clientesSucursalesLDE->head->prev = nueva;
			clientesSucursalesLDE->head = nueva;
		}
		else{
			ClientesSucursal aux = clientesSucursalesLDE->head;
			while((aux->sig != NULL) && (prom >= edadPromedioTClientesABB(aux->sig->info))){
				aux = aux->sig;
			}
			if (aux->sig != NULL) {
                aux->sig->prev = nueva;
			}
			else{
            	clientesSucursalesLDE->end = nueva;
			}
			nueva->sig = aux->sig;
			aux->sig = nueva;
			nueva->prev = aux;
			
		}
	}
}

void liberarTClientesSucursalesLDE(TClientesSucursalesLDE &clientesSucursalesLDE){
	ClientesSucursal actual;
	actual = clientesSucursalesLDE->head;
	while((actual != NULL) && (clientesSucursalesLDE->head != NULL)){
		ClientesSucursal next;
		next = actual;
		actual = actual->sig;
		liberarTClientesABB(next->info);
		delete(next);
	}
	clientesSucursalesLDE->head = clientesSucursalesLDE->end = NULL;
	delete (clientesSucursalesLDE);
	clientesSucursalesLDE = NULL;
}

void imprimirTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
	printf("clientesSucursalesLDE de grupos:\n");
	ClientesSucursal copia = clientesSucursalesLDE->head;
	while (copia != NULL){
		printf("Grupo con edad promedio %.2f:\n", edadPromedioTClientesABB(copia->info));
		imprimirTClientesABB(copia->info);
		copia = copia->sig;
	}
}

void imprimirInvertidoTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
	printf("clientesSucursalesLDE de grupos:\n");
	ClientesSucursal copia = clientesSucursalesLDE->end;
	while (copia != NULL){
		printf("Grupo con edad promedio %.2f:\n", edadPromedioTClientesABB(copia->info));
		imprimirTClientesABB(copia->info);
		copia = copia->prev;
	}
}

nat cantidadTClientesABBClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
	nat count = 0;
	ClientesSucursal copia = clientesSucursalesLDE->head;
	while (copia != NULL){
		count++;
		copia = copia->sig;
	}
	return count;
}

TClientesABB obtenerPrimeroClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
	return clientesSucursalesLDE->head->info;
}

TClientesABB obtenerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, int n){
	if (clientesSucursalesLDE == NULL || clientesSucursalesLDE->head == NULL){
		return NULL;
	}

	ClientesSucursal copia = clientesSucursalesLDE->head;
	int count = 1;
	
	while ((copia != NULL) && (count < n)){
		copia = copia->sig;
		count++;
	}
	
	if (copia == NULL){
		return NULL;
	}
	return copia->info;
}

TClientesABB removerUltimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
	if (clientesSucursalesLDE == NULL || clientesSucursalesLDE->head == NULL){
		return NULL;
	}
	ClientesSucursal copia = clientesSucursalesLDE->end;
	
	if (clientesSucursalesLDE->end == clientesSucursalesLDE->head){
		clientesSucursalesLDE->end = clientesSucursalesLDE->head = NULL;
	}
	else{
		
		ClientesSucursal previo = clientesSucursalesLDE->end->prev;
		previo->sig = NULL;
		clientesSucursalesLDE->end = previo;
	}
	
	TClientesABB info = copia->info;
	delete(copia);
	return info;
}

TClientesABB removerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, int n){
	ClientesSucursal aux = clientesSucursalesLDE->head;
	
	if (n == 1){
		//ClientesSucursal sig = clientesSucursalesLDE->head;
		clientesSucursalesLDE->head = clientesSucursalesLDE->head->sig;
		TClientesABB info = aux->info;
		delete(aux);
		return info;
	}
	else{
		int count = 1;
		while((aux->sig != NULL) && (count < n)){
			aux = aux->sig;
			count++;
		}
		TClientesABB info = aux->info;
		if(aux->sig != NULL){
			aux->prev->sig = aux->sig;
			aux->sig->prev = aux->prev;
			
		}
		else{
			aux->prev->sig = NULL;
			clientesSucursalesLDE->end = aux->prev;
		}
		delete(aux);
		return info;
	}
	return NULL;
}

TCliente clienteMasRepetido(TClientesSucursalesLDE clientesSucursalesLDE){
	
	return NULL;
}
