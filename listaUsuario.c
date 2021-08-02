#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "listaPlaylist.h"
#include "listaAmigos.h"

typedef struct celUsuario CelUsuario;

struct celUsuario{
  Usuario *usuario;
  CelUsuario *prox;
};

struct listUsuario{
  CelUsuario *prim;
  CelUsuario *ult;
};

ListUsuario* inicializaListUsusarios(FILE *fp){
  ListUsuario* lista = (ListUsuario*)malloc(sizeof(ListUsuario));

  fp = fopen("Entrada/amizade.txt", "r");
  char* aux1, *aux2;
  int i = 0;
  CelUsuario* p = lista->prim;

  // // -------- USUARIOS ---------


  //Criando os usuarios - primeira linha do arquivo
  while(fgetc(fp) != "\n"){
      for(i = 0; fgetc(fp) != ";"; i++){
          aux1[i] = fgetc(fp);            
      }
      aux1[i] = "\0";
    insereUsuario(criaUsuario(aux1));
  }

  // -------- LISTA DE AMIGOS ---------

  //Criando as listas de amigos
  for(p; p != NULL; p = p->prox){
      inicializaListAmigos(p->usuario);
  }

  p = lista->prim;

  //Adicionando os amigos na lista de amigos
  while(fgetc(fp) != EOF){
      //Pega o primeiro nome

      for(i = 0; fgetc(fp) != ";"; i++){
          aux1[i] = fgetc(fp);            
      }
      aux1[i] = "\0";

      //Pega o segundo nome
      for(i = 0; fgetc(fp) != "\n"; i++){
          aux2[i] = fgetc(fp);            
      }
      aux2[i] = "\0";

        //Coloca os dois usuários como amigos
      insereAmizade(lista, aux1, aux2);
  }
  fclose(fp);

  return lista;
}

void destroiListUsuario(ListUsuario* lista){
  CelUsuario* p = lista->prim;

  for (p; p != NULL; p = p->prox){
    destroiUsuario(p);
  }

  free(lista);
}