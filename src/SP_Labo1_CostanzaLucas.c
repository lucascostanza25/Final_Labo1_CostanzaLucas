/*
 ============================================================================
 Name        : SP_Labo1_CostanzaLucas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "perritos.h"
#include "parser.h"
#include "UTN.h"

int main(void) {
	setbuf(stdout, NULL);
	int menu;
	int flagArchivo=0;
	int flagRaciones=0;
	int flagHogares=0;
	LinkedList* pArrayListPerritos=ll_newLinkedList();
	LinkedList* pArrayListPerritosFiltrados=NULL;
	LinkedList* pArrayListPerritosHogares=ll_newLinkedList();
	LinkedList* pArrayListHogares=ll_newLinkedList();

	do
	{
		utn_getNumero(&menu, "Final Laboratorio 1\n\n"
				"1.Cargar archivo de perritos\n"
				"2.Informar y ordenar\n"
				"3.Calcular porciones de comida\n"
				"4.Listar perritos con su racion de comida\n"
				"5.Filtrar galgos flaquitos\n"
				"6.Guardar galgos flaquitos (formato texto)\n"
				"7.Cargar archivos de hogares y perritos con hogares\n"
				"8.Listar perritos con hogares descendente\n"
				"0.Salir\n"
				"\nSeleccione una opcion: ", "Error, opcion incorrecta\n", 0, 10, 4);
		system("cls");
		switch(menu)
		{
			case 1:
				if(!controller_loadPerritosFromText("../perritos.csv", pArrayListPerritos))
				{
					printf("Archivo cargado con exito!\n");
					flagArchivo=1;
				}
				else
				{
					printf("No se pudo cargar el archivo!\n");
				}
				system("pause");
			break;

			case 2:
				if(flagArchivo==1)
				{
					controller_ordenarPerritos(pArrayListPerritos);
					controller_listPerritos(pArrayListPerritos);
				}
				else
				{
					printf("Primero cargue el archivo de texto!\n");
				}
				system("pause");
			break;

			case 3:
				if(flagArchivo==1)
				{
					if(ll_map(pArrayListPerritos, perrito_laQueMapea)!=-1)
					{
						printf("Se calculo correctamente lar porciones de comida!\n");
						flagRaciones=1;
					}
					else
					{
						printf("No se pudo calcular las porciones de comida\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo de texto!\n");
				}
				system("pause");
			break;

			case 4:
				if(flagArchivo==1 && flagRaciones==1)
				{
					controller_listPerritoPorciones(pArrayListPerritos);
				}
				else
				{
					printf("Primero cargue el archivo de texto y calcule las raciones de comida!\n");
				}
				system("pause");
			break;

			case 5:
				if(flagArchivo==1 && flagRaciones==1)
				{
					pArrayListPerritosFiltrados=ll_filter(pArrayListPerritos, perrito_laQueFiltra);
					if(pArrayListPerritosFiltrados!=NULL)
					{
						printf("Se filtro exitosamente a los perritos!\n");
					}
					else
					{
						printf("No se pudo filtrar a los perritos!\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo de texto y calcule las raciones de comida!\n");
				}
				system("pause");
			break;

			case 6:
				if(flagArchivo==1 && flagRaciones==1)
				{
					if(controller_saveGalgosFlaquitosAsText("../galgosFlaquitos.csv", pArrayListPerritosFiltrados)!=-1)
					{
						printf("Se guardo exitosamente los galgos flaquitos!\n");
					}
					else
					{
						printf("No se pudo guardar los galgos flaquitos\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo de texto y calcule las raciones de comida!\n");
				}
				system("pause");
			break;

			case 7:
				if(controller_loadHogaresFromText("../hogares.csv", pArrayListHogares)!=-1 && controller_loadPerritosHogaresFromText("../perritosConHogar.csv", pArrayListPerritosHogares)!=-1)
				{
					printf("Archivos cargados con exito!\n");
					flagHogares=1;
				}
				else
				{
					printf("No se pudo cargar los archivos!\n");
				}
				system("pause");
			break;

			case 8:
				if(flagHogares==1)
				{
					controller_listPerritosConHogares(pArrayListPerritosHogares, pArrayListHogares);
				}
				else
				{
					printf("Primero cargue los archivos de hogares y de perritos con hogares en el apartado 7 del menu!\n");
				}
				system("pause");
			break;

			case 0:
				utn_getNumero(&menu, "Seguro que desea salir del programa? Los cambios no guardados se perderan!\n\n0.Si\n1.No\n\nSeleccione una opcion: ", "Error, opcion incorrecta\n", 0, 1, 4);
			break;
		}
		system("cls");
	}while(menu!=0);
	return EXIT_SUCCESS;
}
