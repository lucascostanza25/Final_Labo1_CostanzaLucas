#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perritos.h"
#include "LinkedList.h"
#include "UTN.h"

sPerrito* perrito_New()
{
	sPerrito* this=NULL;
	this=(sPerrito*)malloc(sizeof(sPerrito));

	if(this!=NULL)
	{
		this->idPerrito=0;
		strcpy(this->nombrePerrito, " ");
		this->pesoPerrito=0;
		this->edadPerrito=0;
		strcpy(this->razaPerrito, " ");
	}
	return this;
}
sPerrito* perrito_NewParametros(char* idPerrito, char* nombrePerrito, char* pesoPerrito, char* edadPerrito, char* razaPerrito)
{
	sPerrito* auxPerrito=perrito_New();

	if(idPerrito!=NULL && nombrePerrito!=NULL && pesoPerrito!=NULL && edadPerrito!=NULL && razaPerrito!=NULL)
	{
		auxPerrito->idPerrito=atoi(idPerrito);
		strcpy(auxPerrito->nombrePerrito, nombrePerrito);
		auxPerrito->pesoPerrito=atoi(pesoPerrito);
		auxPerrito->edadPerrito=atoi(edadPerrito);
		strcpy(auxPerrito->razaPerrito, razaPerrito);
	}

	return auxPerrito;
}

void perrito_Delete(sPerrito* auxPerrito)
{
	if(auxPerrito!=NULL)
	{
		free(auxPerrito);
	}
}

int perrito_setId(sPerrito* this, int idPerrito)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->idPerrito=idPerrito;
		retorno=0;
	}
	return retorno;
}

int perrito_getId(sPerrito* this, int* idPerrito)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*idPerrito=this->edadPerrito;
		retorno=0;
	}

	return retorno;
}

int perrito_setNombre(sPerrito* this, char* nombrePerrito)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(this->nombrePerrito, nombrePerrito);
		retorno=0;
	}

	return retorno;
}

int perrito_getNombre(sPerrito* this, char* nombrePerrito)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(nombrePerrito, this->nombrePerrito);
		retorno=0;
	}

	return retorno;
}

int perrito_setPeso(sPerrito* this, float pesoPerrito)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->pesoPerrito=pesoPerrito;
		retorno=0;
	}

	return retorno;
}

int perrito_getPeso(sPerrito* this, float* pesoPerrito)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*pesoPerrito=this->pesoPerrito;
		retorno=0;
	}

	return retorno;
}

int perrito_setEdad(sPerrito* this, int edadPerrito)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->edadPerrito=edadPerrito;
		retorno=0;
	}

	return retorno;
}

int perrito_getEdad(sPerrito* this, int* edadPerrito)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*edadPerrito=this->edadPerrito;
		retorno=0;
	}

	return retorno;
}

int perrito_setRaza(sPerrito* this, char* razaPerrito)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(this->razaPerrito, razaPerrito);
		retorno=0;
	}

	return retorno;
}

int perrito_getRaza(sPerrito* this, char* razaPerrito)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(razaPerrito, this->razaPerrito);
		retorno=0;
	}

	return retorno;
}

int perrito_setRacion(sPerrito* this, float racionPerrito)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->racionComida=racionPerrito;
		retorno=0;
	}

	return retorno;
}

int perrito_getRacion(sPerrito* this, float* racionPerrito)
{
	int retorno=-1;

	if(this!=NULL)
	{
		*racionPerrito=this->racionComida;
		retorno=0;
	}

	return retorno;
}

void perrito_listarUno(sPerrito* this)
{
	int idPerrito;
	char nombrePerrito[21];
	float pesoPerrito;
	int edadPerrito;
	char razaPerrito[21];

	perrito_getId(this, &idPerrito);
	perrito_getNombre(this, nombrePerrito);
	perrito_getPeso(this, &pesoPerrito);
	perrito_getEdad(this, &edadPerrito);
	perrito_getRaza(this, razaPerrito);

	printf("%-6d %-23s %-6.2f %-6d %-23s\n", idPerrito, nombrePerrito, pesoPerrito, edadPerrito, razaPerrito);
}

int perrito_ordenarNombre(void* perritoUno, void* perritoDos) //Revisar
{
	int retorno=0;

	if(perritoUno!=NULL && perritoDos!=NULL)
	{
		char nombrePerritoUno[21];
		char nombrePerritoDos[21];
		perrito_getNombre(perritoUno, nombrePerritoUno);
		perrito_getNombre(perritoDos, nombrePerritoDos);

		retorno=strcmp(nombrePerritoUno, nombrePerritoDos);
	}

	return retorno;
}

int perrito_laQueMapea(void* perrito)
{
	int retorno=-1;
	float cantidadComida=0;
	float pesoPerrito;
	perrito_getPeso(perrito, &pesoPerrito);

	cantidadComida=pesoPerrito*23;
	perrito_setRacion(perrito, cantidadComida);

	return retorno;
}

void perrito_listarRaciones(sPerrito* this)
{
	int idPerrito;
	char nombrePerrito[21];
	float pesoPerrito;
	int edadPerrito;
	char razaPerrito[21];
	float comidaPerrito;

	perrito_getId(this, &idPerrito);
	perrito_getNombre(this, nombrePerrito);
	perrito_getPeso(this, &pesoPerrito);
	perrito_getEdad(this, &edadPerrito);
	perrito_getRaza(this, razaPerrito);
	perrito_getRacion(this, &comidaPerrito);

	printf("%-6d %-23s %-6.2f %-6d %-23s %-6.2f\n", idPerrito, nombrePerrito, pesoPerrito, edadPerrito, razaPerrito, comidaPerrito);
}

int perrito_laQueFiltra(void* perrito)
{
	int retorno=-1;
	char auxRaza[21];
	int auxEdad;
	float auxRacion;
	sPerrito* auxPerritoFiltrado=NULL;

	if(perrito!=NULL)
	{
		perrito_getRaza(perrito, auxRaza);
		perrito_getEdad(perrito, &auxEdad);
		perrito_getRacion(perrito, &auxRacion);

		if(strcmp(auxRaza, "Galgo")==0)
		{
			if(auxEdad>=10)
			{
				if(auxRacion<200)
				{
					retorno=0;
				}
			}
		}
	}

	return retorno;
}
