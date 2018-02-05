
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Eletra.h"
#include "Validaciones.h"

Eletra* eletra_new(char* letra,char* nombre,int vocal,int consonante)
{
        Eletra* this = malloc(sizeof(Eletra));

        if(this != NULL)
        {

                eletra_setLetra(this,letra);
                eletra_setNombre(this,nombre);
                eletra_setVocal(this,vocal);
                eletra_setConsonante(this,consonante);
        }
        return this;
}

void eletra_delete(Eletra* this)
{
        free(this);
}

int eletra_setLetra(Eletra* this,char* letra)
{
        this -> letra = letra[0];
        return 0;
}

int eletra_setNombre(Eletra* this,char* nombre)
{
        strcpy(this->nombre,nombre);
        return 0;
}

int eletra_setVocal(Eletra* this,int vocal)
{
        this->vocal = vocal;
        return 0;
}

int eletra_setConsonante(Eletra* this,int consonante)
{
        this->consonante = consonante;
        return 0;
}

int eletra_setCantidad(Eletra* this,int cantidad)
{
    this->cantidad = cantidad;
    return 0;
}

char eletra_getLetra(Eletra* this)
{
        return this->letra;
}

char* eletra_getNombre(Eletra* this)
{
        return this->nombre;
}

int eletra_getVocal(Eletra* this)
{
        return this->vocal;
}

int eletra_getConsonante(Eletra* this)
{
        return this->consonante;
}

int eletra_getCantidad(Eletra* this)
{
        return this->cantidad;
}


//Eletra* eletra_findByLetra(ArrayList* pArray,char* letra)
//{
//
//        int i;
//        Eletra* aux;
//        Eletra* retorno=NULL;
//        for(i=0;i<al_len(pArray);i++)
//        {
//                aux = al_get(pArray,i);
//                if(strcmp(letra, eletra_getLetra(aux)) == 0)
//                {
//                        retorno = aux;
//                        break;
//                }
//        }
//        return retorno;
//}

Eletra* eletra_findByNombre(ArrayList* pArray,char* nombre)
{

        int i;
        Eletra* aux;
        Eletra* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(nombre,eletra_getNombre(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Eletra* eletra_findByVocal(ArrayList* pArray,int vocal)
{

        int i;
        Eletra* aux;
        Eletra* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(vocal == eletra_getVocal(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Eletra* eletra_findByConsonante(ArrayList* pArray,int consonante)
{

        int i;
        Eletra* aux;
        Eletra* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(consonante == eletra_getConsonante(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

int eletra_compareByLetra(void* pA ,void* pB)
{

        int retorno = 0;

        if(eletra_getLetra(pA) > eletra_getLetra(pB))
                retorno = 1;
        else if(eletra_getLetra(pA) < eletra_getLetra(pB))
                retorno = -1;

        return retorno;
}

int eletra_compareByNombre(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(eletra_getNombre(pA),eletra_getNombre(pB));

        return retorno;
}

int eletra_compareByVocal(void* pA ,void* pB)
{

        int retorno = 0;

        if(eletra_getVocal(pA) > eletra_getVocal(pB))
                retorno = 1;
        else if(eletra_getVocal(pA) < eletra_getVocal(pB))
                retorno = -1;

        return retorno;
}

int eletra_compareByConsonante(void* pA ,void* pB)
{

        int retorno = 0;

        if(eletra_getConsonante(pA) > eletra_getConsonante(pB))
                retorno = 1;
        else if(eletra_getConsonante(pA) < eletra_getConsonante(pB))
                retorno = -1;

        return retorno;
}

int eletra_altas(ArrayList* list)
{
    FILE *pFile;
	Eletra* auxLetra;
	int retorno=-1;

    char var1[50],var2[50],var3[50],var4[50];

    pFile = fopen("datos.csv","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4) >0)
			{
				if(val_validarString(var1)!=-1 && val_validarDescripcion(var2)!=-1 && val_validarInt(var3)!=-1 && val_validarInt(var4) != -1)
				{
					auxLetra=eletra_new(var1, var2, atoi(var3),atoi(var4));
					al_add(list,auxLetra);
					retorno=0;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;

}

int eletra_completar(ArrayList *pList)
{
    int retorno = 0;
    int i;
    Eletra *auxLetra;

    for(i = 0; i < al_len(pList); i++)
    {
        auxLetra = al_get(pList,i);

        if(eletra_getLetra(auxLetra) == 'a' || eletra_getLetra(auxLetra) == 'e' || eletra_getLetra(auxLetra) == 'i' || eletra_getLetra(auxLetra) == 'o' || eletra_getLetra(auxLetra) == 'u')
        {
            eletra_setVocal(auxLetra,1);
        }
        else
        {
            eletra_setConsonante(auxLetra,1);
        }
    }
    return retorno;
}

void eletra_print(ArrayList* this)
{
    int i;
    Eletra *auxletra;

    for(i = 0; i < al_len(this); i++)
    {
        auxletra = al_get(this,i);
        printf("LETRA: %c - NOMBRE: %s- VOCAL: %d - CONSONANTE: %d \n",eletra_getLetra(auxletra),
                            eletra_getNombre(auxletra),eletra_getVocal(auxletra),eletra_getConsonante(auxletra));
    }

}

int eletra_comprobar(ArrayList *pList,char palabra[])
{
    int retorno = -1;
    int i,j,k;
    int tamanioPalabra;
    char auxLetra;
    int contadorUno = 0;
    int contadorDos = 0;
    Eletra *letra;

    tamanioPalabra = strlen(palabra);

    for(i = 0; i < tamanioPalabra; i++)
    {
        auxLetra = palabra[i];
        for(j = 0; j < tamanioPalabra; j++)
        {
            if(auxLetra == palabra[j])
            {
                contadorUno++;
            }
        }
        for( k = 0; k < al_len(pList); k++)
        {
            letra = al_get(pList,k);

            if(eletra_getLetra(letra) == auxLetra)
            {
                contadorDos++;
            }
        }
        if(contadorDos < contadorUno)
        {
            printf("\n\nNo hay letras suficientes!!!");
            break;
        }
    }
     if(contadorUno <= contadorDos)
        {
            printf("\n\nHay letras suficientes!!!");
            retorno = 0;
        }

    return retorno;
}


int eletra_generarListar(ArrayList *pLista)
{
    ArrayList* listaRepetidos;
    ArrayList* ultimaLista;
   char opcion[2];

   char menu[] =
                "\n\t1-Array ordenado descendentemente sólo con las letras repetidas y sus ocurrancias\
                 \n\t2-Array ordenado ascendentemente sin repetidas\
                 \n\t3-Salir\
                 \n\n\tIngrese opcion: ";

    char mensajeErrorMenu[] = "\n\tElija una opcion 1 o 2: ";

    do
    {
        val_getInt(opcion,menu,mensajeErrorMenu,3,2);

        switch(atoi(opcion))
        {
            case 1:
                listaRepetidos = eletra_contadorLetrasRepetidas(pLista);
                al_sort(listaRepetidos,eletra_compareByLetra,0);
                eletra_printLetraCantidad(listaRepetidos);
                break;
            case 2:
                  ultimaLista = eletra_listaRepetidos(listaRepetidos);
                  al_sort(ultimaLista,eletra_compareByLetra,1);
                  eletra_print(ultimaLista);
                break;
            case 3:
                break;
        }

    }while(atoi(opcion) != 3);

    return 0;
}



ArrayList* eletra_contadorLetrasRepetidas(ArrayList* listaOriginal)
{

    Eletra* auxLetra;
    Eletra* auxletraJ;
    int i,j;
    int largoArray = al_len(listaOriginal);
    int contador;
    void* returnAux = NULL;

    for(i = 0; i < largoArray; i++)
    {
        auxLetra = al_get(listaOriginal,i);
        contador = 0;

        for(j = 0; j < largoArray; j++)
        {
            auxletraJ = al_get(listaOriginal,j);

            if(eletra_compareByLetra(auxLetra,auxletraJ) == 0)
            {
                contador++;
            }
        }

        if( contador > 1)
            {
                eletra_setCantidad(auxLetra,contador);
            }
    }
    returnAux = listaOriginal;
    return returnAux;
}

void eletra_printLetraCantidad(void* pLetra)
{
    int i;
    Eletra *auxletra = (Eletra*)pLetra;

    for(i = 0; i < al_len(pLetra); i++)
    {
        auxletra = al_get(pLetra,i);
        printf("LETRA: %c - NOMBRE: %s- VOCAL: %d - CONSONANTE: %d - CANTIDAD: %d \n \n",eletra_getLetra(auxletra),
                            eletra_getNombre(auxletra),eletra_getVocal(auxletra),eletra_getConsonante(auxletra),eletra_getCantidad(auxletra));
    }

}

ArrayList* eletra_listaRepetidos(ArrayList* listaRepetidos)
{
    ArrayList* auxLista = al_newArrayList();
    int i;
    Eletra* letraI;
    char letra;

    al_sort(listaRepetidos,eletra_compareByLetra,0);

    for(i = 0; i < (al_len(listaRepetidos) - 1); i++)
    {
        letraI = al_get(listaRepetidos,i);
        letra = eletra_getLetra(letraI);

        if(eletra_contains(auxLista,letra) != 1)
                {
                    al_add(auxLista,letraI);
                }

    }
    return auxLista;
}

int eletra_contains(ArrayList* list,char letra)
{
    Eletra* auxletra;
    char letraDos;
    int i;
    int retorno = -1;

    for(i = 0; i < al_len(list); i++)
    {
        auxletra = al_get(list,i);
        letraDos = eletra_getLetra(auxletra);

        if(letra == letraDos)
        {
            retorno =1;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}
