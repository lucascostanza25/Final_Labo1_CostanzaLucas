#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "perritos.h"
#include "UTN.h"
#include "hogares.h"
#include "perritosConHogares.h"

int controller_loadPerritosFromText(char* path, LinkedList* pArrayListPerritos)
{
	int retorno=-1;
	FILE* pFileLectura=fopen(path, "r");

	if(path!=NULL && pArrayListPerritos!=NULL)
	{
		if(pFileLectura!=NULL)
		{
			parser_PerritoFromText(pFileLectura, pArrayListPerritos);
			retorno=0;
		}
		fclose(pFileLectura);
	}

	return retorno;
}

int controller_listPerritos(LinkedList* pArrayListPerritos)
{
	int retorno=-1;
	sPerrito* auxPerrito;

	if(pArrayListPerritos!=NULL)
	{
		printf("%-4s | %-21s | %-4s | %-4s | %-21s \n", "ID", "NOMBRE", "PESO", "EDAD", "RAZA");

		for(int i=0; i<ll_len(pArrayListPerritos); i++)
		{
			auxPerrito=ll_get(pArrayListPerritos, i);
			perrito_listarUno(auxPerrito);
		}

		retorno=0;
	}

	return retorno;
}

int controller_ordenarPerritos(LinkedList* pArrayListPerritos)
{
	int retorno=-1;

	if(pArrayListPerritos!=NULL)
	{
		ll_sort(pArrayListPerritos, perrito_ordenarNombre, 1);
		retorno=0;
	}

	return retorno;
}

int controller_listPerritoPorciones(LinkedList* pArrayListPerritos)
{
	int retorno=-1;
	sPerrito* auxPerrito;

	if(pArrayListPerritos!=NULL)
	{
		printf("%-4s | %-21s | %-4s | %-4s | %-21s | %-4s \n", "ID", "NOMBRE", "PESO", "EDAD", "RAZA", "RACION COMIDA");

		for(int i=0; i<ll_len(pArrayListPerritos); i++)
		{
			auxPerrito=ll_get(pArrayListPerritos, i);
			perrito_listarRaciones(auxPerrito);
		}

		retorno=0;
	}

	return retorno;
}

int controller_saveGalgosFlaquitosAsText(char* path, LinkedList* pArrayListPerritosFiltrados)
{
	int retorno=-1;
	int i;
	FILE* pFileEscritura;
	sPerrito* perritoGuardado;

	if(path!=NULL && pArrayListPerritosFiltrados!=NULL)
	{
		pFileEscritura=fopen(path, "w");
		if(pFileEscritura!=NULL)
		{
			fprintf(pFileEscritura, "id,nombre,peso,edad,raza,racion\n");
			for(i=0; i<ll_len(pArrayListPerritosFiltrados); i++)
			{
				perritoGuardado=ll_get(pArrayListPerritosFiltrados, i);
				fprintf(pFileEscritura, "%d,%s,%f,%d,%s,%f\n", perritoGuardado->idPerrito, perritoGuardado->nombrePerrito, perritoGuardado->pesoPerrito, perritoGuardado->edadPerrito, perritoGuardado->razaPerrito, perritoGuardado->racionComida);
			}
			retorno=0;
			fclose(pFileEscritura);
		}
	}

	return retorno;
}

int controller_loadHogaresFromText(char* path, LinkedList* pArrayListHogares)
{
	int retorno=-1;
	FILE* pFileLectura=fopen(path, "r");

	if(path!=NULL && pArrayListHogares!=NULL)
	{
		if(pFileLectura!=NULL)
		{
			parser_HogarFromText(pFileLectura, pArrayListHogares);
			retorno=0;
		}
		fclose(pFileLectura);
	}

	return retorno;
}

int controller_loadPerritosHogaresFromText(char* path, LinkedList* pArrayListPerritosHogares)
{
	int retorno=-1;
	FILE* pFileLectura=fopen(path, "r");

	if(path!=NULL && pArrayListPerritosHogares!=NULL)
	{
		if(pFileLectura!=NULL)
		{
			parser_PerritoHogarFromText(pFileLectura, pArrayListPerritosHogares);
			retorno=0;
		}
		fclose(pFileLectura);
	}

	return retorno;
}

int controller_listPerritosConHogares(LinkedList* pArrayListHogares, LinkedList* pArrayListPerritosHogares)
{
	int retorno=-1;

	if(pArrayListHogares!=NULL && pArrayListPerritosHogares!=NULL)
	{
		sPerritoConHogar* auxPerritoHogar;
		sHogar* auxHogar;

		printf("%-4s | %-21s | %-4s | %-4s | %-21s | %-4s | %-21s \n", "ID", "NOMBRE", "PESO", "EDAD", "RAZA", "ID HOGAR", "DIRECCION");

		for(int i=0; i<ll_len(pArrayListPerritosHogares); i++)
		{
			auxPerritoHogar=ll_get(pArrayListPerritosHogares, i);
			auxHogar=ll_get(pArrayListHogares, i);
			perritoHogar_listarUno(auxPerritoHogar, auxHogar);
		}

		retorno=0;
	}

	return retorno;
}
