#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

typedef struct celAimgos CelAmigos;

struct celAmigos{
    Usuario *usuario;
    CelAmigos *prox;
};

struct listAmigos{
    CelAmigos *prim;
    CelAmigos *ult;
};
