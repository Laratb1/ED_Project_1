#ifndef LISTAPLAYLIST_H_
#define LISTAPLAYLIST_H_
#include <stdio.h>
#include "listaUsuario.h"

typedef struct listPlaylist ListPlaylist;

void inicializaPlaylist(Usuario *usuario, FILE *fp);

void destroiListPlaylist(ListPlaylist *playlist);

void criaListPlaylistPorCantor(ListUsuario *usuario);

void criaArquivoPlayEDRefatorada(ListUsuario *usuario);

void criaArquivoPlayEDPorGosto(ListUsuario *usuario);

void mergePlaylistAmigos(ListUsuario *usuario);

void 

#endif