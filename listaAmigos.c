#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "listaAmigos.h"

typedef struct celAmigos CelAmigos;

struct celAmigos{
  Usuario *usuario;
  CelAmigos *prox;
};

struct listAmigos{
  CelAmigos *prim;
  CelAmigos *ult;
};

ListAmigos *inicializaListaAmigo(void){
  ListAmigos *listAmigos = (ListAmigos*) malloc(sizeof(ListAmigos));
  listAmigos->prim = NULL;
  listAmigos->ult = NULL;
  return listAmigos;
}

void insereAmizade(char* amigo1, char* amigo2){
  
}

void destroiListaAmigos(ListAmigos *listAmigos){
  free(listAmigos);
}