#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
//#include "playlist.h"
#include "listAmigos.h"

typedef struct celUsuario CelUsuario;

struct celUsuario{
    Usuario *usuario;
    CelUsuario *prox;
};

struct listUsuario{
    CelUsuario *prim;
    CelUsuario *ult;
};

void inicializaListUsusarios(FILE *fp){

}