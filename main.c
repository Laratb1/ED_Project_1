#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
//#include "listaPlaylist.h"
//#include "listaAmigos.h"

int main() {
  Usuario *usu;
  
  usu = criaUsuario("Lara");
  destroiUsuario(usu);

  return 0;
}

