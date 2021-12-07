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
	LinkedList* pArrayListPerritos=ll_newLinkedList();
	LinkedList* pArrayListPerritosFiltrada;

	do
	{
		utn_getNumero(&menu, "Final Laboratorio 1\n\n"
				"1.Cargar archivo de perritos\n"
				"2.Informar y ordenar\n"
				"3.Calcular porciones de comida\n"
				"4.Listar perritos con su racion de comida\n"
				"0.Salir\n"
				"\nSeleccione una opcion: ", "Error, opcion incorrecta\n", 0, 7, 4);
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
					printf("Primero cargue el archivo de texto o calcule las raciones de comida!\n");
				}
				system("pause");
			break;

			case 5:
				if(flagArchivo==1 && flagRaciones==1)
				{
					pArrayListPerritosFiltrada=ll_filter(pArrayListPerritos, perrito_laQueFiltra);
					if(pArrayListPerritosFiltrada!=NULL)
					{
						printf("Se filtro exitosamente a los perritos!\n");
					}
				}
				else
				{
					printf("Primero cargue el archivo de texto o calcule las raciones de comida!\n");
				}
				system("pause");
			break;

			case 6:
				controller_listPerritoPorciones(pArrayListPerritosFiltrada); //Funcion usada de prueba para testear
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
