/*
 * hogares.h
 *
 *  Created on: 8 dic. 2021
 *      Author: Lucas
 */

#ifndef HOGARES_H_
#define HOGARES_H_

typedef struct
{
	int id;
	char direccion[31];
}sHogar;

sHogar* hogar_new();
sHogar* hogar_newParametros(char* id, char* direccion);
int hogar_setId(sHogar* this, int idHogar);
int hogar_getId(sHogar* this, int* idHogar);
int hogar_setDireccion(sHogar* this, char* direccionHogar);
int hogar_getDireccion(sHogar* this, char* direccionHogar);
int hogar_ordenarNombre(void* hogarUno, void* hogarDos);

#endif /* HOGARES_H_ */
