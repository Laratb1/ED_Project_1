#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "listaPlaylist.h"
#include "listaMusica.h"
#include "musica.h"

typedef struct celMusica CelMusica;

struct celMusica{
  Musica *musica;
  CelMusica *prox;
};

struct listMusica{
  CelMusica *prim;
  CelMusica *ult;
};

ListMusica *inicializaListMusica(void){
  ListMusica *listMusica = (ListMusica*) malloc(sizeof(ListMusica));

  listMusica->prim = NULL;
  listMusica->ult = NULL;

  return listMusica;
}

/*void insereMusicaNaLista(ListMusica *listMusicas, FILE *playlist){ 
  ListMusica *listMusica = inicializaListMusica();
  char *nome; //*cantor;
  char *cantor = "alguem";
  //fopen("fp", "r");

  while(!feof(playlist)){
    fscanf(playlist, "%s[^\n]", nome);
    printf("%s/ ", nome);
    //scanf("%s - %s[^-]", nome, cantor);
    if(feof(playlist)){
      break;
    }
    CelMusica *musica = inicializaMusica();
    preencheMusica(musica, nome, cantor);
    musica->prox = listMusica->prim; 
    listMusica->prim = musica;
      if(listMusica->ult == NULL){
        listMusica->ult = musica;
      }
        
  }
    
}*/

void destroiListMusica(ListMusica *listMusica){
    CelMusica *p = listMusica->prim;
    CelMusica *t;

    while(p != NULL){
        t = p->prox;
        destroiMusica(p->musica);
        //free(p);
        p = t;
    }
    free(listMusica);
}