#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "listaPlaylist.h"

typedef struct celMusica CelMusica;

struct celMusica{
    char *nome;
    char *cantor;
    CelMusica *prox;
};

struct listMusica{
    CelMusica *prim;
    CelMusica *ult;
};
