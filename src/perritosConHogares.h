#ifndef PERRITOSCONHOGARES_H_
#define PERRITOSCONHOGARES_H_
#include "hogares.h"

typedef struct
{
	int idPerrito;
	char nombrePerrito[21];
	float pesoPerrito;
	int edadPerrito;
	char razaPerrito[21];
	//float racionComida;
	int idHogar;
}sPerritoConHogar;

sPerritoConHogar* perritoHogar_new();
sPerritoConHogar* perritoHogar_newParametros(char* idPerroHogar, char* nombrePerroHogar, char* pesoPerroHogar, char* edadPerroHogar, char* razaPerroHogar, char* idHogar);
int perritoHogar_setId(sPerritoConHogar* this, int id);
int perritoHogar_getId(sPerritoConHogar* this, int* id);
int perritoHogar_setNombre(sPerritoConHogar* this, char* nombre);
int perritoHogar_getNombre(sPerritoConHogar* this, char* nombre);
int perritoHogar_setPeso(sPerritoConHogar* this, float peso);
int perritoHogar_getPeso(sPerritoConHogar* this, float* peso);
int perritoHogar_setEdad(sPerritoConHogar* this, int edad);
int perritoHogar_getEdad(sPerritoConHogar* this, int* edad);
int perritoHogar_setRaza(sPerritoConHogar* this, char* raza);
int perritoHogar_getRaza(sPerritoConHogar* this, char* raza);
int perritoHogar_setIdHogar(sPerritoConHogar* this, int idHogar);
int perritoHogar_getIdHogar(sPerritoConHogar* this, int* idHogar);

int perritoHogar_listarUno(sPerritoConHogar* thisPerrito, sHogar* thisHogar);

#endif /* PERRITOSCONHOGARES_H_ */
