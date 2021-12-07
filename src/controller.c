#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "perritos.h"
#include "UTN.h"

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

	if(pArrayListPerritos!=NULL)
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

	return retorno;
}
