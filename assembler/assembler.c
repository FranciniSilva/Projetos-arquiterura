#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define TAM_MAX_LINHA 80

struct neander {
    int linha;
    int label;
    int instrucao;
    int operando;
    int posmemoria;
};

typedef neander_t struct neander *;

void erro(const char *msg){
    fprintf(stderr, msg);
    exit(EXIT_FAILURE);
}

neander_t lista_criar(){
    neander_t cabeca = malloc( sizeof(struct neander) );
    if( !cabeca ){
        erro("Falta de memoria");
    }
    cabeca->p = NULL;
    return cabeca;
}

neander_t lista_incluir(neander_t neander, int info){
    if(!neander)
        return NULL;
    neander_t no = malloc( sizeof(struct neander) );
    if (!no){
        erro("Falta de memoria");
    }
    no->info = info;
    no->p = NULL;
    neander_t no_atual = neander;
    while(no_atual->p != NULL)
        no_atual = no_atual->p;
    no_atual->p = no;
    return no;
}

void lista_imprimir(neander_t neander){
    if (!neander)
        return;

    lista_t no_atual = nenader->p;
    while(no_atual) {
        printf("%d ", no_atual->info);
        no_atual = no_atual->p;
    }
    printf("\n");
}

void lista_destruir(neander_t neander){
    if(!neander)
        return;
    neander_t no, no_atual = neander->p;
    while(no_atual){
        no = no_atual->p;
        free(no_atual);
        no_atual=no;
    }
    free(neander);
}

void lerLabel(char *linha){
    char *tmp = linha;
    char *al;

    while(linha =! ":")
    al == linha;
    print(al);

    free(*tmp);
    free(*al);
}

void remover_espacos(char *linha) {
    char *tmp = linha;
    while(isspace(*linha)) linha++;
    memmove(tmp, linha, TAM_MAX_LINHA - (linha - tmp));
}

void remover_comentarios(char *linha){
    while (*linha) {
      if (*linha == '#') {
        *linha = '\n';
        *linha = '0';
      }
      linha++;
    }
}

void remove_espacos_iniciais(char *linha) {
    char *tmp = linha;
    while(isspace(*linha)) linha++;
    memmove(tmp, linha, TAM_MAX_LINHA - (linha - tmp));
}

void remover_demais_espacos(char *linha) {
    char buf[TAM_MAX_LINHA];
    char *tmp = linha;
    int i = 0;
    while (*linha) {
        buf[i++]=*linha++;
        while(isspace(*linha)) linha++;
    }
    buf[i]='0';
    memmove(tmp, linha, TAM_MAX_LINHA - (linha - tmp));
}

void limpa_linha(char *linha) {
    char *tmp = linha;
    while (isspace(*linha)) linha++;
    if(*linha=='#')
      *tmp = '\0';
    else
      memmove(tmp, linha, TAM_MAX_LINHA - (linha - tmp));
    for (;*tmp;tmp++)
      if (*tmp=='#') {
        *tmp++ = '\n';
        *tmp = '\0';
      }
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
      fprintf(stderr, "Sintaxe: main <arquivo>\n");
      exit(EXIT_FAILURE);
    }


    FILE *fin = fopen(argv[1], "rt");
    if (!fin) {
        fprintf(stderr, "Arquivo não encontrado: %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }

    char linha[TAM_MAX_LINHA];
    int i = 1;
    while (fgets(linha, TAM_MAX_LINHA, fin)) {
      limpa_linha(linha);
      if (*linha) {
        fprintf(stdout, "%5d: %s",i++,linha);
      }

    }

    fclose(fin);
}
