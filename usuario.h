#ifndef USUARIO_H_
#define USUARIO_H_

#include "listaAmigos.h"
#include "listaPlaylist.h"
#include "listaMusica.h"

typedef struct usuario Usuario;

Usuario* criaUsuario(char *nome);

void destroiUsuario(Usuario *usuario);

char *retornaNomeUsuario(Usuario *usuario);

ListAmigos *retornaAmigosUsuario(Usuario *usuario);

ListMusica *retornaPlaylistUsuario(Usuario *usuario);

// ---- PARA TESTE -----

void imprimeUsuario(Usuario* usuario);

#endif