#ifndef PERRITOS_H_
#define PERRITOS_H_
#include "LinkedList.h"

typedef struct
{
	int idPerrito;
	char nombrePerrito[21];
	float pesoPerrito;
	int edadPerrito;
	char razaPerrito[21];
	float racionComida;
}sPerrito;

sPerrito* perrito_New(); //Constructor
sPerrito* perrito_NewParametros(char* idPerrito, char* nombrePerrito, char* pesoPerrito, char* edadPerrito, char* razaPerrito);
int perrito_add(LinkedList* listaPerritos);
int perrito_setId(sPerrito* this, int idPerrito);
int perrito_getId(sPerrito* this, int* idPerrito);
int perrito_setNombre(sPerrito* this, char* nombrePerrito);
int perrito_getNombre(sPerrito* this, char* nombrePerrito);
int perrito_setPeso(sPerrito* this, float pesoPerrito);
int perrito_getPeso(sPerrito* this, float* pesoPerrito);
int perrito_setEdad(sPerrito* this, int edadPerrito);
int perrito_getEdad(sPerrito* this, int* edadPerrito);
int perrito_setRaza(sPerrito* this, char* razaPerrito);
int perrito_getRaza(sPerrito* this, char* razaPerrito);
int perrito_setRacion(sPerrito* this, float racionPerrito);
int perrito_getRacion(sPerrito* this, float* racionPerrito);
void perrito_listarUno(sPerrito* this);
void perrito_listarRaciones(sPerrito* this);
// ----------------------- //
int perrito_ordenarNombre(void* perritoUno, void* perritoDos);
int perrito_laQueMapea(void* perrito);
int perrito_laQueFiltra(void* perrito);

#endif /* PERRITOS_H_ */
