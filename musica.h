#ifndef MUSICA_H_
#define MUSICA_H_

typedef struct musica Musica;

Musica *criaMusica(char *nome, char *cantor);

char *retornaNomeMusica(Musica *musica);

char *retornaCantorMusica(Musica *musica);

void destroiMusica(Musica *musica);

#endif