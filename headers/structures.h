#pragma once

#define MAX 50 /* Tamanho maximo de uma string */

int login_valido = 0;

/* Estrutura para paises */
typedef struct paises
{
    int id_pais;         /* Identificador do pais */
    char nome_pais[MAX]; /* Nome do pais */
    int medalha_ouro;    /* Numero de medalhas de ouro */
    int medalha_prata;   /* Numero de medalhas de prata */
    int medalha_bronze;  /* Numero de medalhas de bronze */
    int total_medalhas;  /* Total de medalhas */
    int pontuacao;       /* Pontuacao do pais */
};
struct paises pai;

/* Estrutura para esportes */
typedef struct esportes
{
    int id_esporte;             /* Identificador do esporte */
    char nome_modalidades[MAX]; /* Nome da modalidade */
};
struct esportes esp;

/* Estrutura para atletas */
typedef struct atletas
{
    int id_atleta;         /* Identificador do atleta */
    char nome[MAX];        /* Nome do atleta */
    char ultimo_nome[MAX]; /* Ultimo nome do atleta */
    char pais[MAX];        /* País do atleta */
    char modalidade[MAX];  /* Modalidade do atleta */
};
struct atletas atl;

/* Estrutura para usuário */
typedef struct usuario
{
    char usuario[16];   /* Usuário */
    char senha[16];     /* Senha */
    char email[MAX];    /* Email */
    char nome[MAX];     /* Nome */
};
struct usuario usr;