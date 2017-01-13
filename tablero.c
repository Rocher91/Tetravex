#include <stdio.h>
#include <stdlib.h>
#include "azar.h"
#include "tiempo.h"
#include "tablero.h"
#include "casilla.h"

void inicializar_tablero(t_tablero *tablero) {
	
	int f,c; //f=filas	c=columnas
	
	inicializar_azar();
	
	do{
		printf("Tamano tablero entre 2 y 6: ");
		scanf("%d%*c",&tablero->size);
	}while(tablero->size<2 || tablero->size>6);
	
	do{
		printf("\nTipo de tablero ([s]:Simple o [d]:Doble): ");
		scanf("%c%*c",&tablero->tipo);
	}while(tablero->tipo!='s' && tablero->tipo!='d');
	
	tablero->max_f=tablero->size-1;
	
	if(tablero->tipo=='s')		tablero->max_c=tablero->size-1;
	else if(tablero->tipo=='d')	tablero->max_c=tablero->size*2-1;
	
	for(f=0;f<tablero->size;f++)
		for(c=0;c<tablero->size;c++){
			
			tablero->c[f][c].e=numero_al_azar(10);
			tablero->c[f][c].s=numero_al_azar(10);
			if (f==0) tablero->c[f][c].n=numero_al_azar(10);
			else tablero->c[f][c].n=tablero->c[f-1][c].s;
			if (c==0) tablero->c[f][c].o=numero_al_azar(10);
			else tablero->c[f][c].o=tablero->c[f][c-1].e;
			tablero->c[f][c].fo=f;
			tablero->c[f][c].co=c;
		}

	for(f=0;f<tablero->size;f++)
		for(c=0;c<tablero->size;c++)	intercambiar_casillas(&tablero->c[numero_al_azar(tablero->size)][numero_al_azar(tablero->size)],&tablero->c[numero_al_azar(tablero->size)][numero_al_azar(tablero->size)]);
}

void imprimir_tablero(t_tablero tablero) {
	
	int l,c,contorno_tablero,indice_fila=0;
 
	printf("\n");
	for(contorno_tablero=0;contorno_tablero<tablero.size;contorno_tablero++) printf("   %c",'A'+contorno_tablero);

	for(l=0;l<tablero.size*3;l++){	
		
		if(l%3==0){
			printf("\n +");
			for(contorno_tablero=0;contorno_tablero<tablero.size;contorno_tablero++) 	printf("---+");
			printf("\n |");
		}
		else if(l%3==1)	printf("\n%d|",indice_fila++);
		else if(l%3==2)	printf("\n |");

		for(c=0;c<tablero.size;c++){
						
			if(l%3==0)	imprimir_norte_casilla(tablero.c[l/3][c]);
			if(l%3==1)	imprimir_centro_casilla(tablero.c[l/3][c]);
			if(l%3==2)	imprimir_sur_casilla(tablero.c[l/3][c]); 
		}	
	}
	printf("\n +");
	for(contorno_tablero=0;contorno_tablero<tablero.size;contorno_tablero++) 	printf("---+");
}

void realizar_jugada(t_tablero *tablero) {
	
	char col_1,col_2;
	int fil_1,fil_2,c1,c2;
		
	do{
		printf("\nCasillas a intercambiar (ej: [A0B1]): ");
		scanf("%c%d%c%d%*c",&col_1,&fil_1,&col_2,&fil_2);
			
	}while(check_rangos(col_1,col_2,fil_1,fil_2,&*tablero));
	
	c1=(col_1-'A');
	c2=(col_2-'A');
	
	intercambiar_casillas(&tablero->c[fil_1][c1],&tablero->c[fil_2][c2]);	
}

int esta_resuelto(t_tablero tablero) {
	
	int f,c;
	
	for(f=0;f<tablero.size;f++)
		for(c=0;c<tablero.size;c++){

			if (f!=0 && tablero.c[f][c].n!=tablero.c[f-1][c].s)	return 0;
			if (c!=0 && tablero.c[f][c].o!=tablero.c[f][c-1].e)	return 0;
		}
	return 1;	
}

int check_rangos(char columna_1,char columna_2,int fila_1,int fila_2,t_tablero *tablero){
	
	if (columna_1==columna_2 && fila_1==fila_2) return 1; 
	
	else if ((columna_1>('A'+tablero->max_c)) || (columna_1<'A') || (columna_2>('A'+tablero->max_c)) || (columna_1<'A') || (fila_1<0) ||
			(fila_1>tablero->max_f) || (fila_2<0)|| (fila_2>tablero->max_c)) return 1;
	else return 0;
}
