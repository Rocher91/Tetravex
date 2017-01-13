#include <stdio.h>
#include "tablero.h"

/*
 *
 * El fichero juego.c solo tiene la funcion: int main()
 * Dicha funcion:
 * Declara una variable de tipo t_tablero
 * Inicializa dicho tablero, lo imprime por pantalla, y
 * mientras el tablero no este resuelo: llama a realizar_jugada() e imprime el
 * tablero.
 */

main() {
  t_tablero tablero;


  inicializar_tablero(&tablero);
  imprimir_tablero(tablero);

  while (!esta_resuelto(tablero)) {
    realizar_jugada(&tablero);
    imprimir_tablero(tablero);
  }
  printf("\nPuzzle resuelto!!!\n");
}

