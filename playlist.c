#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "playlist.h"
#include "listaPlaylist.h"
#include "listaAmigos.h"

struct playlist{
  char *nome;
  ListMusica *musicas;
};

Playlist* criaPlaylist(char* nome){
  Playlist* playlist = (Playlist*)malloc(sizeof(Playlist));
  playlist->nome = strdup(nome);

  return playlist;
}

char* retornaNomePlaylist(Playlist* playlist){
  return playlist->nome;
}

ListMusica* retornaListMusica(Playlist* playlist){
  return playlist->musicas;
}

void destroiPlaylist(Playlist* playlist){
  if (playlist->musicas != NULL){
    destroiListMusica(playlist->musicas);
  }
  free(playlist->nome);
  free(playlist);
}