#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"

int parser_PerritoFromText(FILE* pFile, LinkedList* pArrayListPerritos);
int parser_PerritoFromBinary(FILE* pFile, LinkedList* pArrayListPerritos);
int parser_HogarFromText(FILE* pFile, LinkedList* pArrayListHogares);
int parser_PerritoHogarFromText(FILE* pFile, LinkedList*  pArrayListPerritosHogares);

#endif /* PARSER_H_ */
