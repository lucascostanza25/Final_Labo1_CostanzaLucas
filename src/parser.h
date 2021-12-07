#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"

int parser_PerritoFromText(FILE* pFile, LinkedList* pArrayListPerritos);
int parser_PerritoFromBinary(FILE* pFile, LinkedList* pArrayListPerrito);

#endif /* PARSER_H_ */
