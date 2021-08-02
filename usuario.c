#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "listaPlaylist.h"
#include "listaAmigos.h"

struct usuario{ 
  char *nome;
  ListPlaylist *playlist;
  ListAmigos *amigos;
};

Usuario* criaUsuario(char *nome){
  Usuario* usuario = (Usuario*)malloc(sizeof(Usuario));
  usuario->nome = strdup(nome);

  return usuario;
}

void destroiUsuario(Usuario *usuario){
  if (usuario->playlist == NULL && usuario->amigos == NULL){
    free(usuario->nome);
  }
  else if (usuario->playlist == NULL){
    free(usuario->nome);
    destroiListAmigos(usuario->amigos);
  }
  else if (usuario->amigos == NULL){
    free(usuario->nome);
    destroiListPlaylist(usuario->playlist);
  }
  else{
    free(usuario->nome);
    destroiListPlaylist(usuario->playlist);
    destroiListAmigos(usuario->amigos);
  }
    
  free(usuario);
}




   

