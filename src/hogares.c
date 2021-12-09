#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "perritos.h"
#include "parser.h"
#include "UTN.h"
#include "perritosConHogares.h"
#include "hogares.h"

sHogar* hogar_new()
{
	sHogar* this=NULL;
	this=(sHogar*)malloc(sizeof(sHogar));

	return this;
}

sHogar* hogar_newParametros(char* id, char* direccion)
{
	sHogar* auxHogar=hogar_new();

	if(id!=NULL && direccion!=NULL)
	{
		auxHogar->id=atoi(id);
		strcpy(auxHogar->direccion, direccion);
	}

	return auxHogar;
}

int hogar_setId(sHogar* this, int idHogar)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->id=idHogar;
		retorno=0;
	}
	return retorno;
}

int hogar_getId(sHogar* this, int* idHogar)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*idHogar=this->id;
		retorno=0;
	}
	return retorno;
}

int hogar_setDireccion(sHogar* this, char* direccionHogar)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(this->direccion, direccionHogar);
		retorno=0;
	}

	return retorno;
}

int hogar_getDireccion(sHogar* this, char* direccionHogar)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(direccionHogar, this->direccion);
		retorno=0;
	}

	return retorno;
}

int hogar_ordenarNombre(void* hogarUno, void* hogarDos)
{
	int retorno=-1;

	if(hogarUno!=NULL && hogarDos!=NULL)
	{
		char nombreHogarUno[31];
		char nombreHogarDos[31];
		hogar_getDireccion(hogarUno, nombreHogarUno);
		hogar_getDireccion(hogarDos, nombreHogarDos);

		retorno=strcmp(nombreHogarUno, nombreHogarDos);
	}

	return retorno;
}
