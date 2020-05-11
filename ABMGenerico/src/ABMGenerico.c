/*
 ============================================================================
 Name        : ABMGenerico.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "menusABM.h"
#include "estructGenerica.h"
#include "estructTipo.h"
//#include "dataWarehouse.h" //harcodeo

#define LENG 50 //largo vector generico
#define LENT 4 //largo vector tipo

int main(void) {
	eGenerica listaG[LENG];
	eTipoG listaT[LENT] =  {{1, "AAA"},
							{2, "BBB"},
							{3, "CCC"},
							{4, "DDD"} };

	char continueS = 's';
	char confirm;

	//Ids, crear tantos como estructuras existan:
	int nextIdG = 1000; //arranca en el 1000

	//Flags Alta:
	int flagG = 0; //ponerla en 1 para HARCODEAR

	//Inicializar arrays:
	inicializarG(listaG, LENG);

	/*
	HARCODEAR
	harcodearGenerico(listaG, 13);
	//para harcodear mas estructuras, crear la estructura y crear la funcion de harcodeo para la funcion especifica
	*/

	do
	{
		system("clear");
		switch(menu())
		{
			case 1:
				alta(&nextIdG, &flagG, listaG, LENG, listaT, LENT);
				break;

			case 2:
				baja(flagG, listaG, LENG, listaT, LENT);
				break;

			case 3:
				modificacion(flagG, listaG, LENG, listaT, LENT);
				break;

			case 4:
				//Listas
				break;

			case 5:
				system("clear");
				printf("\n***** Salir *****\n\n ");
				printf("Confirma salida? s/n: ");
				fpurge(stdin);
				scanf("%c", &confirm);
				if(confirm == 's')
				{
					continueS = 'n';
				}
				break;
			default:
				printf("No es una opcion valida.\n");
		}
		pause();


	}while(continueS == 's');


	return EXIT_SUCCESS;
}
