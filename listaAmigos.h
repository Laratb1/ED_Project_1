#ifndef AMIGOS_H_
#define AMIGOS_H_

typedef struct listAmigos ListAmigos;
typedef struct celAmigos CelAmigos;

ListAmigos *inicializaListaAmigo(void);

void insereAmigoNaLista(ListAmigos *listAmigos, Usuario *usuario); 

void insereAmizade(char* amigo1, char* amigo2);

void destroiListaAmigos(ListAmigos *listAmigos);

#endif