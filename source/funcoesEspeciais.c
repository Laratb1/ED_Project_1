#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> //Diretorio
#include <sys/stat.h> //Diretorio

#include "funcoesEspeciais.h"

void criaListPlaylistPorCantor(ListUsuario *listaUsuarios){
  CelUsuario *p = retornaPrimeiro(listaUsuarios);
  char* cantor;
  Usuario *usuario;
  ListPlaylist *listPlaylist;
  CelPlaylist *celPlaylist;
  CelPlaylist *t;
  ListMusica *listMusica; 
  CelMusica *celMusica; 
  Musica *musica;

  Playlist* novaPlaylist;
  ListMusica *novaListMusica;

  while(p != NULL){
        usuario = retornaUsuarioCelula(p);
        listPlaylist = retornaListPlaylist(usuario);
        celPlaylist = retornaPrimeiroListPlaylist(listPlaylist);

        while(celPlaylist != NULL){
          listMusica = retornaListMusica(retornaPlaylistaDaCelula(celPlaylist));
          celMusica = retornaPrimeiroListMusica(listMusica);

          while(celMusica != NULL){
            musica = retornaMusicaDaCelula(celMusica);
            
            cantor = strdup(retornaCantorMusica(musica));
            
            novaPlaylist = buscaPlaylist(listPlaylist, cantor);
            
            if(novaPlaylist == NULL){
              novaPlaylist = criaPlaylist(cantor);
              novaListMusica = retornaListMusica(novaPlaylist);

              insereMusicaNaLista(novaListMusica, criaCopiaMusica(musica));
              insereNovaPlaylist(listPlaylist, novaPlaylist);
            }
            else{
              novaListMusica = retornaListMusica(novaPlaylist);
              insereMusicaNaLista(novaListMusica, criaCopiaMusica(musica));
            }

            celMusica = retornaProximaCelMusica(celMusica);
            free(cantor);
          }
          t = retornaProximoListPlaylist(celPlaylist);

          retiraPlaylistDaLista(listPlaylist, celPlaylist);

          celPlaylist = t;
        }
        p = retornaProximo(p);
    }  
}

void criaArquivoPlayEDRefatorada(ListUsuario *listaUsuarios){
  FILE *fp;
  fp = fopen("../Saida/played-refatorada.txt", "w");

  FILE *fd;

  CelUsuario *p = retornaPrimeiro(listaUsuarios);
  char *diretorio = (char*)malloc(100*sizeof(char)), *nomePasta = (char*)malloc(100*sizeof(char));
  Usuario *usuario;
  ListPlaylist *listPlaylist;
  CelPlaylist *celPlaylist;
  ListMusica *listMusica; 
  CelMusica *celMusica; 
  Musica *musica;
  int qtd = 0;

  while(p != NULL){
        usuario = retornaUsuarioCelula(p);
        listPlaylist = retornaListPlaylist(usuario);
        celPlaylist = retornaPrimeiroListPlaylist(listPlaylist);;
        
        strcpy(nomePasta, "../Saida/");
        strcat(nomePasta, retornaNomeUsuario(usuario));
        mkdir(nomePasta, 0777);

        fprintf(fp, "%s;",retornaNomeUsuario(usuario));

        if (qtd == 0){
          while(celPlaylist != NULL){
            celPlaylist = retornaProximoListPlaylist(celPlaylist);
            qtd++;
          }
        }

        celPlaylist = retornaPrimeiroListPlaylist(listPlaylist);

        fprintf(fp, "%d;", qtd);

        while(celPlaylist != NULL){
          listMusica = retornaListMusica(retornaPlaylistaDaCelula(celPlaylist));
          celMusica = retornaPrimeiroListMusica(listMusica);

          
            if (retornaProximoListPlaylist(celPlaylist) != NULL){
              fprintf(fp, "%s.txt;", retornaNomePlaylist(retornaPlaylistaDaCelula(celPlaylist)));
            }
            else{
              if (retornaProximo(p) == NULL){
                fprintf(fp, "%s.txt", retornaNomePlaylist(retornaPlaylistaDaCelula(celPlaylist)));
              }
              else{
                fprintf(fp, "%s.txt\n", retornaNomePlaylist(retornaPlaylistaDaCelula(celPlaylist)));
              }
            }
          
          
          strcpy(diretorio, "../Saida/");
          strcat(diretorio, retornaNomeUsuario(usuario));
          strcat(diretorio, "/");
          strcat(diretorio, retornaNomePlaylist(retornaPlaylistaDaCelula(celPlaylist)));

          fd = fopen(diretorio, "w");

            while(celMusica != NULL){
              musica = retornaMusicaDaCelula(celMusica);
              
              if (retornaProximaCelMusica(celMusica) != NULL){
                fprintf(fd, "%s - %s\n", retornaCantorMusica(musica), retornaNomeMusica(musica));
              }
              else{
                fprintf(fd, "%s - %s", retornaCantorMusica(musica), retornaNomeMusica(musica));
              }

              celMusica = retornaProximaCelMusica(celMusica);
            }

          fclose(fd);
          
          celPlaylist = retornaProximoListPlaylist(celPlaylist);
        }
        p = retornaProximo(p);
        qtd = 0;
    }

  fclose(fp);
  free(diretorio);
  free(nomePasta);
}

void criaArquivoPlayEDPorGosto(ListUsuario *listaUsuarios){
  CelUsuario *p = retornaPrimeiro(listaUsuarios);
  CelUsuario *t = retornaProximo(p);
  Usuario *usuario;
  ListPlaylist *listPlaylist;
  CelPlaylist *celPlaylist;
  ListMusica *listMusica; 
  CelMusica *celMusica; 
  Musica *musica;
  
  Usuario *usuario2;
  ListPlaylist *listPlaylist2;
  CelPlaylist *celPlaylist2;
  ListMusica *listMusica2; 
  CelMusica *celMusica2; 
  Musica *musica2;
  CelPlaylist *auxiliar;
  Playlist *playlist2;
  char* nomePlaylist;
  char* nomePlaylist2;
  int qtd = 0;

  FILE *fp;

  fp = fopen("../Saida/similaridades.txt", "w");

  while(p != NULL){
    usuario = retornaUsuarioCelula(p);
    listPlaylist = retornaListPlaylist(usuario);
    celPlaylist = retornaPrimeiroListPlaylist(listPlaylist);

    auxiliar = celPlaylist;

    while(t != NULL){
      usuario2 = retornaUsuarioCelula(t);
      listPlaylist2 = retornaListPlaylist(usuario2);
      celPlaylist2 = retornaPrimeiroListPlaylist(listPlaylist2);
      
      if(buscaAmigoPorNome(retornaListAmigosUsuario(usuario),retornaNomeUsuario(usuario2)) != NULL){
        while(celPlaylist != NULL){
          nomePlaylist = retornaNomePlaylist(retornaPlaylistaDaCelula(celPlaylist));

          if(buscaPlaylist(listPlaylist2, nomePlaylist) != NULL){

            listMusica = retornaListMusica(retornaPlaylistaDaCelula(celPlaylist));
            celMusica = retornaPrimeiroListMusica(listMusica);

            listMusica2 = retornaListMusica(buscaPlaylist(listPlaylist2, nomePlaylist));
            celMusica2 = retornaPrimeiroListMusica(listMusica2);

            while(celMusica != NULL){
              musica = retornaMusicaDaCelula(celMusica);
                if(buscaMusicaPorNome(listMusica2, retornaNomeMusica(musica)) != NULL){
                  qtd++;
                }

              celMusica = retornaProximaCelMusica(celMusica);
            }
          }  

          celPlaylist = retornaProximoListPlaylist(celPlaylist);
        } 
      
        fprintf(fp, "%s;%s;%d\n", retornaNomeUsuario(usuario), retornaNomeUsuario(usuario2), qtd);
      }

    celPlaylist = retornaProximoListPlaylist(auxiliar);
    auxiliar = celPlaylist;
    t = retornaProximo(t);
    qtd = 0;
    }
    
    p = retornaProximo(p);
    if(p != retornaUltimo(listaUsuarios)){
      t = retornaProximo(p);
    }
    else{
      p = NULL;
    }
  }

  fclose(fp);
}

void mergePlaylistAmigos(ListUsuario *listaUsuarios){
  CelUsuario *p = retornaPrimeiro(listaUsuarios);
  CelUsuario *t = retornaProximo(p);

  Usuario *usuario;
  ListPlaylist *listPlaylist;
  CelPlaylist *celPlaylist, *aux;
  ListMusica *listMusica; 
  CelMusica *celMusica; 
  Musica *musica;
  
  Usuario *usuario2;
  ListPlaylist *listPlaylist2;
  CelPlaylist *celPlaylist2;
  ListMusica *listMusica2; 
  CelMusica *celMusica2; 


  CelPlaylist *auxiliar;

  char* nomePlaylist;

  Playlist* novaPlaylist, *novaPlaylist2;
  ListMusica* listMusicaNova, *listMusicaNova2;

  while(p != NULL){
    usuario = retornaUsuarioCelula(p);
    listPlaylist = retornaListPlaylist(usuario);
    celPlaylist = retornaPrimeiroListPlaylist(listPlaylist);
// AQUI
    auxiliar = retornaProximoListPlaylist(celPlaylist);

    while(t != NULL){
      usuario2 = retornaUsuarioCelula(t);
      listPlaylist2 = retornaListPlaylist(usuario2);
      
      if(buscaAmigoPorNome(retornaListAmigosUsuario(usuario),retornaNomeUsuario(usuario2)) != NULL){
        while(celPlaylist != NULL){
          
          nomePlaylist = strdup(retornaNomePlaylist(retornaPlaylistaDaCelula(celPlaylist)));

          if(buscaPlaylist(listPlaylist2, nomePlaylist) != NULL){
            celPlaylist2 = buscaPlaylistERetornaCelula(listPlaylist2, nomePlaylist);

            listMusica = retornaListMusica(retornaPlaylistaDaCelula(celPlaylist));
            celMusica = retornaPrimeiroListMusica(listMusica);

            listMusica2 = retornaListMusica(retornaPlaylistaDaCelula(celPlaylist2));
            celMusica2 = retornaPrimeiroListMusica(listMusica2);

            novaPlaylist = criaPlaylist(nomePlaylist);
            novaPlaylist2 = criaPlaylist(nomePlaylist);

            listMusicaNova = retornaListMusica(novaPlaylist);
            listMusicaNova2 = retornaListMusica(novaPlaylist2);

            while(celMusica != NULL){
              musica = retornaMusicaDaCelula(celMusica);
              insereMusicaNaLista(listMusicaNova, criaCopiaMusica(musica));
              insereMusicaNaLista(listMusicaNova2, criaCopiaMusica(musica));

              celMusica = retornaProximaCelMusica(celMusica);
            }

            while(celMusica2 != NULL){
              musica = retornaMusicaDaCelula(celMusica2);

                if(buscaMusicaPorNome(listMusicaNova, retornaNomeMusica(musica)) == NULL){
                  insereMusicaNaLista(listMusicaNova, criaCopiaMusica(musica));
                  insereMusicaNaLista(listMusicaNova2, criaCopiaMusica(musica));
                }

              celMusica2 = retornaProximaCelMusica(celMusica2);
            }

            aux = retornaProximoListPlaylist(celPlaylist);
            
            retiraPlaylistDaLista(listPlaylist, celPlaylist);
            retiraPlaylistDaLista(listPlaylist2, celPlaylist2); 

            insereNovaPlaylist(listPlaylist, novaPlaylist);
            insereNovaPlaylist(listPlaylist2, novaPlaylist2);

            celPlaylist = aux;
          }  
          else{
            celPlaylist = retornaProximoListPlaylist(celPlaylist);
          }

          free(nomePlaylist);
        } 
      }

    celPlaylist = auxiliar;
    auxiliar = retornaProximoListPlaylist(celPlaylist);
    t = retornaProximo(t);
    }
    
    p = retornaProximo(p);
    if(p != retornaUltimo(listaUsuarios)){
      t = retornaProximo(p);
    }
    else{
      p = NULL;
    }
  }
}