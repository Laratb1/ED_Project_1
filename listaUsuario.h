#ifndef LISTAUSUARIO_H_
#define LISTAUSUARIO_H_
#include <stdio.h>
#include "usuario.h"

typedef struct listUsuario ListUsuario;

ListUsuario* inicializaListUsusarios(FILE *fp);

void insereUsuario(Usuario *usuario);

void retiraUsuario(char *nome);

void destroiListUsuario(ListUsuario* lista);

Usuario *retornaUsuario(ListUsuario *lista, char *nome);

Usuario *retornaPrimeiro(Usuario *usuario);

void criaArquivoUsuarios(Usuario *usuario);


// ---- PARA TESTE -----

void imprimeListUsuario(ListUsuario* lista);

#endif