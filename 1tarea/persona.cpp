#include "../include/persona.h"

struct rep_persona {

    int ced;
    char nom[MAX_NOMBRE];
    char ape[MAX_APELLIDO];
    TFecha fech_nac;

};

TPersona crearTPersona(int cedula, const char nombre[MAX_NOMBRE], char apellido[MAX_APELLIDO], TFecha fecha){
    TPersona nuevaPersona = NULL;

    nuevaPersona = new rep_persona;
    nuevaPersona->ced = cedula;
    strcpy(nuevaPersona->nom, nombre);
    strcpy(nuevaPersona->ape, apellido);
    nuevaPersona->fech_nac = fecha;

    return nuevaPersona;
}

void nombrePersona(TPersona persona, char nombre[MAX_NOMBRE]){

    strcpy(nombre, persona->nom);

}

void apellidoPersona(TPersona persona, char apellido[MAX_APELLIDO]){

    strcpy(apellido, persona->ape);

}

void liberarTPersona(TPersona &persona){

    liberarTFecha(persona->fech_nac);
    delete persona;
    persona = NULL;

}

int cedulaTPersona(TPersona persona){
    int cedula = 0;

    cedula = persona->ced;

	return cedula;
}

TFecha fechaNacimientoTPersona(TPersona persona){
    TFecha fecha = NULL;

    fecha = persona->fech_nac;

	return fecha;
}

void imprimirTPersona(TPersona persona){

    printf("Persona %s %s\n", persona->nom, persona->ape);
    printf("Cedula: %d\n", persona->ced);
    printf("Fecha de nacimiento: ");
    imprimirTFecha(persona->fech_nac);
}

bool esMasJoven(TPersona persona1, TPersona persona2){
    bool masJoven = false;

    masJoven = (compararTFechas(persona1->fech_nac, persona2->fech_nac) == 1);

	return masJoven;
}
