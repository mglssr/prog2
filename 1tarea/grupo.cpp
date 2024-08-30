#include "../include/grupo.h"

struct rep_grupo {

    TPersona personas[MAX_PERSONAS];
    int tope;
};


TGrupo crearTGrupo(){
    TGrupo nuevoGrupo = new rep_grupo;
    nuevoGrupo->tope = 0;
    for (int i = 0; (i <= MAX_PERSONAS); i++)
        nuevoGrupo->personas[i]=NULL;
    return nuevoGrupo;
}

// Función para agregar una persona a un grupo
// Recibe un elemento de tipo TGrupo y un elemento de tipo TPersona y lo agrega al grupo en orden por fecha de nacimiento (de menor a mayor)
// Si dos personas tienen la misma fecha de nacimiento, deben ordenarse por orden de ingreso al grupo, de más nuevo a más antiguo
// Si la cantidad de personas en el grupo es igual a MAX_PERSONAS, la función no tiene efecto
void agregarAGrupo(TGrupo& grupo, TPersona persona){
    int i, j = 0;
    bool masjoven = false;
    if (grupo->tope < MAX_PERSONAS)
    {
        if (grupo->tope == 0){
            grupo->tope++;
            grupo->personas[0] = persona;
        }
        else{
            i = 0;
            while ((!masjoven) && (i < grupo->tope))
            {
                masjoven = esMasJoven(grupo->personas[i], persona);
                i++;
            };
            grupo->tope++;

                for (j = (grupo->tope - 1); (j > i); j--){
                    grupo->personas[j] = grupo->personas[j-1];
                }
            grupo->personas[i] = persona;
        }
    }
}

// Función para imprimir todas las personas de un grupo
// Recibe un elemento de tipo TGrupo e imprime sus personas en orden cronológico
// El formato en el que se debe imprimir el grupo es utilizando de forma secuencial la función imprimirTPersona
// Si el grupo está vacío no imprime nada
void imprimirTGrupo(TGrupo grupo){
    for (int i = 0; (i < grupo->tope); i++){
        imprimirTPersona(grupo->personas[i]);
    }
} 

// Función para liberar un grupo
// Recibe una referencia a un elemento de tipo TGrupo y libera su memoria
// Libera además la memoria de cada una de las personas en el grupo
void liberarTGrupo(TGrupo& grupo){
    for (int i = 0; (i < grupo->tope); i++){
        liberarTPersona(grupo->personas[i]);
    }
    
    delete grupo;
    grupo = NULL;
}

// Función para verificar si un elemento de tipo TPersona existe en un grupo
// Recibe un grupo y la cédula de la persona y regresa un booleano indicando su existencia
bool estaEnGrupo(TGrupo grupo, int cedula){
    bool esta = false;
	/************ Parte 5.3 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 5.3 *****/
	return esta;
}

// Esta función remueve la persona con ci "cedula" del grupo "grupo"
void removerDeGrupo(TGrupo &grupo, int cedula){
    /************ Parte 5.4 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 5.4 *****/   
}

// Función para verificar si hay, al menos, una persona en el grupo que tenga la fecha de nacimiento "fecha"
// Debe implementarse utilizando búsqueda binaria
bool hayPersonasFecha(TGrupo grupo, TFecha fecha){
    bool hay = false;
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 5.5 *****/ 
    return hay;
}

// Imprime en pantalla las personas del grupo que tengan la fecha de nacimiento "fecha" 
void imprimirPersonasFecha(TGrupo grupo, TFecha fecha){
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 5.5 *****/ 
}
