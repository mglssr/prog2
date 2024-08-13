#include "../include/persona.h"

// Define la estructura Persona
struct rep_persona {
    /************ Parte 4.1 ************/
    /*Escriba el código a continuación */
    int ced;
    char nom[MAX_NOMBRE];
    char ape[MAX_APELLIDO];
    TFecha fech_nac;
    /****** Fin de parte Parte 4.1 *****/
};

// Función que crea un elemento de tipo TPersona con los valores dados
TPersona crearTPersona(int cedula, const char nombre[MAX_NOMBRE], char apellido[MAX_APELLIDO], TFecha fecha){
    TPersona nuevaPersona = NULL;
    /************ Parte 4.2 ************/
    /*Escriba el código a continuación */
    nuevaPersona = new rep_persona;
    nuevaPersona->ced = cedula;
    strcpy(nuevaPersona->nom, nombre);
    strcpy(nuevaPersona->ape, apellido);
    nuevaPersona->fech_nac = fecha;
    /****** Fin de parte Parte 4.2 *****/
    return nuevaPersona;
}

// Función que retorna el nombre de la persona
void nombrePersona(TPersona persona, char nombre[MAX_NOMBRE]){
    /************ Parte 4.3 ************/
    /*Escriba el código a continuación */
    strcpy(nombre, persona->nom);

    /****** Fin de parte Parte 4.3 *****/
}

// Funcion que retorna el apellido de la persona
void apellidoPersona(TPersona persona, char apellido[MAX_APELLIDO]){
    /************ Parte 4.3 ************/
    /*Escriba el código a continuación */
    strcpy(apellido, persona->ape);
    /****** Fin de parte Parte 4.3 *****/
}

// Función que libera la memoria asignada para una persona
// Debe liberar también la memoria de la fecha asociada
void liberarTPersona(TPersona &persona){
    /************ Parte 4.3 ************/
    /*Escriba el código a continuación */
    liberarTFecha(persona->fech_nac);
    delete persona;
    persona = NULL;
    /****** Fin de parte Parte 4.3 *****/
}

// Función que retorna la cédula de la persona
int cedulaTPersona(TPersona persona){
    int cedula = 0;
	/************ Parte 4.4 ************/
    /*Escriba el código a continuación */
    cedula = persona->ced;
    /****** Fin de parte Parte 4.4 *****/
	return cedula;
}

// Función que retorna la fecha de nacimiento de la persona
TFecha fechaNacimientoTPersona(TPersona persona){
    TFecha fecha = NULL;
	/************ Parte 4.4 ************/
    /*Escriba el código a continuación */
    fecha = persona->fech_nac;
    /****** Fin de parte Parte 4.4 *****/
	return fecha;
}

// Función que imprime la información de la persona en el siguiente formato:
// Persona <nombre> <apellido>
// Cédula: <cedula>
// Fecha de nacimiento: <fecha>
void imprimirTPersona(TPersona persona){
    /************ Parte 4.5 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 4.5 *****/
}

// Función que retorna true si persona1 es mas joven que persona2 y false en caso contrario
bool esMasJoven(TPersona persona1, TPersona persona2){
    bool masJoven = false;
	/************ Parte 4.6 ************/
    /*Escriba el código a continuación */
    masJoven = (compararTFechas(persona1->fech_nac, persona2->fech_nac) == 1);
    /****** Fin de parte Parte 4.6 *****/
	return masJoven;
}
