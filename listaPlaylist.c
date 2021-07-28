#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaMusica.h"
//#include "playlist.h"

typedef struct celPlaylist CelPlaylist;

struct celPlaylist{
    char *nome;
    ListMusica *musicas;
    CelPlaylist *prox;
};

struct listPlaylist{
    CelPlaylist *prim;
    CelPlaylist *ult;
};
