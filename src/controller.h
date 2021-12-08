/*
 * controller.h
 *
 *  Created on: 6 dic. 2021
 *      Author: Lucas
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadPerritosFromText(char* path, LinkedList* pArrayListPerritos);

int controller_listPerritos(LinkedList* pArrayListPerritos);

int controller_ordenarPerritos(LinkedList* pArrayListPerritos);

int controller_listPerritoPorciones(LinkedList* pArrayListPerritos);

int controller_saveGalgosFlaquitosAsText(char* path, LinkedList* pArrayListPerritosFiltrados);

#endif /* CONTROLLER_H_ */
