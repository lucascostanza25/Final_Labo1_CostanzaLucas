#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "perritos.h"
#include "parser.h"
#include "UTN.h"
#include "hogares.h"
#include "perritosConHogares.h"

sPerritoConHogar* perritoHogar_new()
{
	sPerritoConHogar* this=NULL;
	this=(sPerritoConHogar*)malloc(sizeof(sPerritoConHogar));

	if(this!=NULL)
	{
		this->idPerrito=0;
		strcpy(this->nombrePerrito, " ");
		this->pesoPerrito=0;
		this->edadPerrito=0;
		strcpy(this->razaPerrito, " ");
		this->idPerrito=0;
	}
	return this;
}

sPerritoConHogar* perritoHogar_newParametros(char* idPerroHogar, char* nombrePerroHogar, char* pesoPerroHogar, char* edadPerroHogar, char* razaPerroHogar, char* idHogar)
{
	sPerritoConHogar* auxPerritoHogar=perritoHogar_new();

	if(idPerroHogar!=NULL && nombrePerroHogar!=NULL && pesoPerroHogar!=NULL && edadPerroHogar!=NULL && razaPerroHogar!=NULL && idHogar!=NULL)
	{
		auxPerritoHogar->idPerrito=atoi(idPerroHogar);
		strcpy(auxPerritoHogar->nombrePerrito, nombrePerroHogar);
		auxPerritoHogar->pesoPerrito=atof(pesoPerroHogar);
		auxPerritoHogar->edadPerrito=atoi(edadPerroHogar);
		strcpy(auxPerritoHogar->razaPerrito, razaPerroHogar);
		auxPerritoHogar->idHogar=atoi(idHogar);
	}

	return auxPerritoHogar;
}

int perritoHogar_setId(sPerritoConHogar* this, int id)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->idPerrito=id;
		retorno=0;
	}
	return retorno;
}

int perritoHogar_getId(sPerritoConHogar* this, int* id)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*id=this->idPerrito;
		retorno=0;
	}

	return retorno;
}

int perritoHogar_setNombre(sPerritoConHogar* this, char* nombre)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(this->nombrePerrito, nombre);
		retorno=0;
	}

	return retorno;
}

int perritoHogar_getNombre(sPerritoConHogar* this, char* nombre)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(nombre, this->nombrePerrito);
		retorno=0;
	}

	return retorno;
}

int perritoHogar_setPeso(sPerritoConHogar* this, float peso)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->pesoPerrito=peso;
		retorno=0;
	}

	return retorno;
}

int perritoHogar_getPeso(sPerritoConHogar* this, float* peso)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*peso=this->pesoPerrito;
		retorno=0;
	}

	return retorno;
}

int perritoHogar_setEdad(sPerritoConHogar* this, int edad)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->edadPerrito=edad;
		retorno=0;
	}

	return retorno;
}

int perritoHogar_getEdad(sPerritoConHogar* this, int* edad)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*edad=this->edadPerrito;
		retorno=0;
	}

	return retorno;
}

int perritoHogar_setRaza(sPerritoConHogar* this, char* raza)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(this->razaPerrito, raza);
		retorno=0;
	}

	return retorno;
}

int perritoHogar_getRaza(sPerritoConHogar* this, char* raza)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(raza, this->razaPerrito);
		retorno=0;
	}

	return retorno;
}

int perritoHogar_setIdHogar(sPerritoConHogar* this, int idHogar)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->idHogar=idHogar;
		retorno=0;
	}

	return retorno;
}

int perritoHogar_getIdHogar(sPerritoConHogar* this, int* idHogar)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*idHogar=this->idHogar;
		retorno=0;
	}

	return retorno;
}

int perritoHogar_listarUno(sPerritoConHogar* this, sHogar* thisHogar)
{
	int retorno=-1;
	int auxIdPerrito;
	int auxIdPerritoHogar;
	int	auxIdHogar;
	int auxEdadPerrito;
	char auxNombrePerrito[21];
	char auxRazaPerrito[21];
	float auxPesoPerrito;
	char auxDireccion[31];

	//Perritos
	perritoHogar_getId(this, &auxIdPerrito);
	perritoHogar_getIdHogar(this, &auxIdPerritoHogar);
	perritoHogar_getNombre(this, auxNombrePerrito);
	perritoHogar_getRaza(this, auxRazaPerrito);
	perritoHogar_getPeso(this, &auxPesoPerrito);
	perritoHogar_getEdad(this, &auxEdadPerrito);
	//Hogar
	hogar_getId(thisHogar, &auxIdHogar);
	hogar_getDireccion(thisHogar, auxDireccion);

	if(auxIdPerritoHogar==auxIdHogar)
	{
		printf("%-6d %-23s %-6.2f %-6d %-23s %-6d %-23s\n", auxIdPerrito, auxNombrePerrito, auxPesoPerrito, auxEdadPerrito, auxRazaPerrito, auxIdPerritoHogar, auxDireccion);
	}

	return retorno;
}
