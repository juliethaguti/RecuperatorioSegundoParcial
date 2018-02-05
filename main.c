#include <stdio.h>
#include <stdlib.h>
#include "Eletra.h"
#include "Validaciones.h"


int main()
{

    ArrayList* pArrayLetras = al_newArrayList();

    char menu[] =
                "\n1-Altas\
                 \n2-Completar\
                 \n3-Comprobar\
                 \n4-Generar y listar\
                 \n5-Salir\
                 \n\nIngrese opcion: ";
        char mensajeErrorMenu[] = "\nSe debe elegir una opcion del 1 al 5";
        char opcion[4];
        char palabra[20];

    do
    {
        val_getInt(opcion,menu,mensajeErrorMenu,3,4);
        switch(atoi(opcion))
        {
        case 1:
            eletra_altas(pArrayLetras);
            eletra_print(pArrayLetras);
            break;
        case 2:
            eletra_completar(pArrayLetras);
            eletra_print(pArrayLetras);
            break;
        case 3:
            val_getString(palabra,"\n\nIngrese una palabra: ","Error",3,20);
            eletra_comprobar(pArrayLetras,palabra);
            break;
        case 4:
            eletra_generarListar(pArrayLetras);
            break;
        case 5:
            break;
        }
    }while(atoi(opcion) != 5);
    return 0;
}
