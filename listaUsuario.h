#ifndef LISTAUSUARIO_H_
#define LISTAUSUARIO_H_
#include <stdio.h>
#include "usuario.h"

typedef struct listUsuario ListUsuario;

void inicializaListUsusarios(FILE *fp);

void insereUsuario(Usuario *usuario);

void retiraUsuario(char *nome);

void destroiListUsuario(Usuario *usuario);

Usuario *retornaUsuario(Usuario *usuario, char *nome);

Usuario *retornaPrimeiro(Usuario *usuario);

void criaArquivoUsuarios(Usuario *usuario);

#endif