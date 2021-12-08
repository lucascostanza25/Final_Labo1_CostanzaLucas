#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "perritos.h"

int parser_PerritoFromText(FILE* pFile, LinkedList* pArrayListPerritos)
{
	int retorno=-1;
	char bufferDatos[5][1028];
	int cantidadDatos;
	sPerrito* auxPerrito;

	if(pFile!=NULL && pArrayListPerritos!=NULL)
	{
		cantidadDatos=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferDatos[0], bufferDatos[1], bufferDatos[2], bufferDatos[3], bufferDatos[4]);
		while(!feof(pFile))
		{
			cantidadDatos=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferDatos[0], bufferDatos[1], bufferDatos[2], bufferDatos[3], bufferDatos[4]);
			if(cantidadDatos==5)
			{
				auxPerrito=perrito_NewParametros(bufferDatos[0], bufferDatos[1], bufferDatos[2], bufferDatos[3], bufferDatos[4]);
				if(auxPerrito!=NULL)
				{
					ll_add(pArrayListPerritos, auxPerrito);
					retorno=0;
				}
			}
		}
	}

	return retorno;
}

int parser_PerritoFromBinary(FILE* pFile, LinkedList* pArrayListPerritos)
{
	int retorno=-1;
	sPerrito* auxPerrito;

	if(pFile!=NULL )
	{
		while(!feof(pFile))
		{
			auxPerrito=perrito_New();
			if(fread(auxPerrito, sizeof(sPerrito), 1, pFile)!=0)
			{
				ll_add(pArrayListPerritos, auxPerrito);
				retorno=0;
			}
		}
	}

	return retorno;
}
