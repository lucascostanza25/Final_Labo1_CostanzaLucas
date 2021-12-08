#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "perritos.h"
#include "hogares.h"
#include "perritosConHogares.h"

int parser_PerritoFromText(FILE* pFile, LinkedList* pArrayListPerritos)
{
	int retorno=-1;
	char bufferDatos[5][1028];
	int cantidadDatos;
	sPerrito* auxPerrito;

	if(pFile!=NULL && pArrayListPerritos!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferDatos[0], bufferDatos[1], bufferDatos[2], bufferDatos[3], bufferDatos[4]);
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

int parser_HogarFromText(FILE* pFile, LinkedList* pArrayListHogares)
{
	int retorno=-1;
	char bufferDatos[2][1028];
	int cantidadDatos;
	sHogar* auxHogar;

	if(pFile!=NULL && pArrayListHogares!=NULL)
	{
		fscanf(pFile, "%[^,],%[^\n]\n", bufferDatos[0], bufferDatos[1]);
		while(!feof(pFile))
		{
			cantidadDatos=fscanf(pFile, "%[^,],%[^\n]\n", bufferDatos[0], bufferDatos[1]);
			if(cantidadDatos==2)
			{
				auxHogar=hogar_newParametros(bufferDatos[0], bufferDatos[1]);
				if(auxHogar!=NULL)
				{
					ll_add(pArrayListHogares, auxHogar);
					retorno=0;
				}
			}
		}
	}

	return retorno;
}

int parser_PerritoHogarFromText(FILE* pFile, LinkedList*  pArrayListPerritosHogares)
{
	int retorno=-1;
	char bufferDatos[6][1028];
	int cantidadDatos;
	sPerritoConHogar* auxPerritoHogar;

	if(pFile!=NULL && pArrayListPerritosHogares!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferDatos[0], bufferDatos[1], bufferDatos[2], bufferDatos[3], bufferDatos[4], bufferDatos[5]);
		while(!feof(pFile))
		{
			cantidadDatos=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferDatos[0], bufferDatos[1], bufferDatos[2], bufferDatos[3], bufferDatos[4], bufferDatos[5]);
			if(cantidadDatos==6)
			{
				auxPerritoHogar=perritoHogar_newParametros(bufferDatos[0], bufferDatos[1], bufferDatos[2], bufferDatos[3], bufferDatos[4], bufferDatos[5]);
				if(auxPerritoHogar!=NULL)
				{
					ll_add(pArrayListPerritosHogares, auxPerritoHogar);
					retorno=0;
				}
			}
		}
	}

	return retorno;
}
