#ifndef LISTAMUSICA_H_
#define LISTAMUSICA_H_

#include "usuario.h"

typedef struct listMusica ListMusica;

void inicializaListMusica(Usuario *usuario, char *fp);

void destroiListMusica(ListMusica *playlist);

void alteraPlaylist(Usuario *usuario, ListMusica *musicas);

void criaArquivoListMusica(ListMusica *musicas);

#endif