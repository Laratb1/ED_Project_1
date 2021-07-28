#ifndef USUARIO_H_
#define USUARIO_H_

#include "listAmigos.h"
#include "listaPlaylist.h"
#include "listaMusica.h"

typedef struct usuario Usuario;

void criaUsuario(char *nome, ListAmigos *amigos, ListMusica *musicas);

void destroiUsuario(Usuario *usuario);

char *retornaNomeUsuario(Usuario *usuario);

ListAmigos *retornaAmigosUsuario(Usuario *usuario);

ListMusica *retornaPlaylistUsuario(Usuario *usuario);

#endif