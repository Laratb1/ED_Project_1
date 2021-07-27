#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "playlist.h"

typedef struct celMusica CelMusica;

struct celMusica{
    char *nome;
    CelMusica *prox;
};

struct listMusica{
    CelMusica *prim;
    CelMusica *ult;
};
