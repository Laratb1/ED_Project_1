#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct playlist Playlist;

Playlist* criaPlaylist(char* nome);

char* retornaNomePlaylist(Playlist* playlist);

ListMusica* retornaListMusica(Playlist* playlist);

void destroiPlaylist(Playlist* playlist);

#endif "PLAYLIST_H"