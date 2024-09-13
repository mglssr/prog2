#include "../include/clientesSucursalesLDE.h"

struct rep_ClientesSucursal {
	int idSucursal;
	TClientesABB info;
	rep_ClientesSucursal *prev, *next;
};

struct rep_clientesSucursalesLDE {
	rep_ClientesSucursal *head, *end;
};

typedef struct rep_ClientesSucursal *ClientesSucursal;
TClientesSucursalesLDE crearTClientesSucursalesLDEVacia(){
	return NULL;
}

void insertarClientesABBTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, TClientesABB clientesABB, int idSucursal){
	if (clientesSucursalesLDE == NULL){
		ClientesSucursal nueva = new rep_ClientesSucursal;
		nueva->idSucursal = idSucursal;
		nueva->idSucursal
	}
}

void liberarTClientesSucursalesLDE(TClientesSucursalesLDE &clientesSucursalesLDE){

}

void imprimirTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){

}

void imprimirInvertidoTClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){

}

nat cantidadTClientesABBClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
	return 0;
}

TClientesABB obtenerPrimeroClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
	return NULL;
}

TClientesABB obtenerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, int n){
	return NULL;
}

TClientesABB removerUltimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE){
	return NULL;
}

TClientesABB removerNesimoClientesSucursalesLDE(TClientesSucursalesLDE clientesSucursalesLDE, int n){
	return NULL;
}

TCliente clienteMasRepetido(TClientesSucursalesLDE clientesSucursalesLDE){
	return NULL;
}
