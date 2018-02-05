#include "ArrayList.h"

#ifndef _ELETRA_H
#define _ELETRA_H
typedef struct
{
        char letra;
        char nombre[21];
        int vocal;
        int consonante;
        int cantidad;
}Eletra;
#endif// _ELETRA_H

Eletra* eletra_new(char* letra,char* nombre,int vocal,int consonante);
void eletra_delete(Eletra* this);
int eletra_setLetra(Eletra* this,char* letra);
int eletra_setNombre(Eletra* this,char* nombre);
int eletra_setVocal(Eletra* this,int vocal);
int eletra_setConsonante(Eletra* this,int consonante);
int eletra_setCantidad(Eletra* this,int cantidad);
char eletra_getLetra(Eletra* this);
char* eletra_getNombre(Eletra* this);
int eletra_getVocal(Eletra* this);
int eletra_getConsonante(Eletra* this);
int eletra_getCantidad(Eletra* this);
Eletra* eletra_findByLetra(ArrayList* pArray,char* letra);
Eletra* eletra_findByNombre(ArrayList* pArray,char* nombre);
Eletra* eletra_findByVocal(ArrayList* pArray,int vocal);
Eletra* eletra_findByConsonante(ArrayList* pArray,int consonante);
int eletra_compareByLetra(void* pA ,void* pB);
int eletra_compareByNombre(void* pA ,void* pB);
int eletra_compareByVocal(void* pA ,void* pB);
int eletra_compareByConsonante(void* pA ,void* pB);
int eletra_altas(ArrayList* list);
int eletra_completar(ArrayList *pList);
void eletra_print(ArrayList* this);
int eletra_comprobar(ArrayList *pList,char palabra[]);
int eletra_generarListar(ArrayList *pLista);
ArrayList* eletra_contadorLetrasRepetidas(ArrayList* pList);
ArrayList* eletra_listaRepetidos(ArrayList* listaOriginal);
void eletra_printLetraCantidad(void* pLetra);
ArrayList* listaRepetidasSinRepetidos(ArrayList* listaRepetidos);
int eletra_contains(ArrayList* list,char letra);
