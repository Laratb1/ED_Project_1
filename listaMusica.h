#ifndef LISTAMUSICA_H_
#define LISTAMUSICA_H_

//#include "usuario.h"

typedef struct listMusica ListMusica;
typedef struct celMusica CelMusica;

ListMusica *inicializaListMusica(void); //ok 

void insereMusicaNaLista(ListMusica *listMusicas, FILE *playlist); //ok

void destroiListMusica(ListMusica *listMusica);

//void alteraPlaylist(Usuario *usuario, ListMusica *musicas);

void criaArquivoListMusica(ListMusica *musicas);

#endif