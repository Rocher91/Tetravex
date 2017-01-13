#include <stdio.h>
#include "colores.h"
#include "casilla.h"


void imprimir_norte_casilla(t_casilla cas) {
	
	printf("\\");
	printf_color(cas.n);
	printf("%d",cas.n);
	printf_color(-1);
	printf("/|");
}

void imprimir_centro_casilla(t_casilla cas) {
	
	printf_color(cas.o);
	printf("%d",cas.o);
	printf_color(-1);
	printf("x");
	printf_color(cas.e);
	printf("%d",cas.e);
	printf_color(-1);
	printf("|");
}

void imprimir_sur_casilla(t_casilla cas) {
	
	printf("/"); 
	printf_color(cas.s);
	printf("%d",cas.s); 
	printf_color(-1);
	printf("\\|"); 
}

void intercambiar_casillas(t_casilla *cas1, t_casilla *cas2) {
	
	t_casilla aux;
	
	aux=*cas1;
	*cas1=*cas2;
	*cas2=aux;
}


