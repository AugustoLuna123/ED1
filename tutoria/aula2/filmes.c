#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TAM 50

typedef struct {
    char nome[265];
    char genero[265];
    int codigo;
} Filme;

typedef struct {
    Filme *filmes;
    int qtd_filmes;
} Locadora;

// O(1)
Locadora criaLocadora(Locadora *locadora) {
    locadora->filmes = (Filme *)malloc(MAX_TAM * sizeof(Filme));
    locadora->qtd_filmes = 0;
    return *locadora;
}

// O(1)
bool adicionaFilme(Locadora *locadora, Filme filme) {
    if (locadora->qtd_filmes >= MAX_TAM) {
        return false;
    }
    locadora->filmes[locadora->qtd_filmes] = filme;
    locadora->qtd_filmes++;
    return true;
}

// O(n)
bool removeFilme(Locadora *locadora, Filme filme) {
    for (int i = 0; i < locadora->qtd_filmes; i++) {
        if (strcmp(locadora->filmes[i].nome, filme.nome) == 0 && locadora->filmes[i].codigo == filme.codigo) {
            for (int j = i; j < locadora->qtd_filmes - 1; j++) {
                locadora->filmes[j] = locadora->filmes[j + 1];
            }
            locadora->qtd_filmes--;
            return true;
        }
    }
    return false;
}

// O(n)
bool pesquisaFilme(Locadora locadora, Filme *filme, int pos) {
    if (pos >= locadora.qtd_filmes) {
        return false;
    }
    if (strcmp(locadora.filmes[pos].nome, filme->nome) == 0 || locadora.filmes[pos].codigo == filme->codigo) {
        *filme = locadora.filmes[pos];
        return true;
    }
    return pesquisaFilme(locadora, filme, pos + 1);
}

// O(n)
void listaFilmes(Locadora locadora) {
    for (int i = 0; i < locadora.qtd_filmes; i++) {
        printf("Nome: %s, Genero: %s, Codigo: %d\n", locadora.filmes[i].nome, locadora.filmes[i].genero, locadora.filmes[i].codigo);
    }
}

int main() {
    Locadora locadora;
    locadora = criaLocadora(&locadora);

    Filme filme1 = {"Filme1", "Aventura", 1};
    Filme filme2 = {"Filme2", "Comedia", 2};
    Filme filme3 = {"Filme3", "Drama", 3};

    adicionaFilme(&locadora, filme1);
    adicionaFilme(&locadora, filme2);
    adicionaFilme(&locadora, filme3);

    listaFilmes(locadora);

    Filme pesquisa = {"Filme2", "", 0};
    if (pesquisaFilme(locadora, &pesquisa, 0)) {
        printf("Filme encontrado: Nome: %s, Genero: %s, Codigo: %d\n", pesquisa.nome, pesquisa.genero, pesquisa.codigo);
    } else {
        printf("Filme não encontrado\n");
    }

    removeFilme(&locadora, filme2);

    listaFilmes(locadora);

    free(locadora.filmes);
    return 0;
}
