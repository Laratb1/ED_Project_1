#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaMusica.h"
#include "listaPlaylist.h"
#include "playlist.h"

typedef struct celPlaylist CelPlaylist;

struct celPlaylist{
    Playlist* playlist;
    CelPlaylist *prox;
};

struct listPlaylist{
    CelPlaylist *prim;
    CelPlaylist *ult;
};

/*void inicializaPlaylist(Usuario *usuario, FILE *fp){
    fp = fopen("Entrada/playlist.txt","r");
    char c = fgetc(fp);
    int i = 0, quant = 0, cont = 0;
    char *aux1, *aux2;

    while (c != EOF){
        while(c != "\n"){
            if (cont == 0){
                for(i = 0; c != ";"; i++){ 
                    aux1[i] = fgetc(fp); 
                    c = aux1[i];
                }
            }
            else if (cont == 1){
                quant = fgetc(fp);
                c = quant;
            }
            else{
                for (int j = 0; j < quant; j++){
                    for(i = 0; c != ";" && c != "\n"; i++){ 
                        aux2[i] = fgetc(fp); 
                        c = aux2[i];
                    }
                    insereListaMusica(inicializaListMusica(aux2));
                }
            }
        }
        cont = 0;
    }
}*/

void destroiListPlaylist(ListPlaylist *playlist){
    CelPlaylist* p = playlist->prim;

    for (p; p != NULL; p = p->prox){
      if(p->playlist != NULL){
        destroiPlaylist(p->playlist);
      }
    }
    free(playlist);
}
