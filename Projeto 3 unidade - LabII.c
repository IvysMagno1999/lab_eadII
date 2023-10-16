//Sistema de Gerenciamento de Amizades

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_USERS 50
#define MAX_NAME_LENGTH 50

// Estrutura para representar o grafo
typedef struct {
    bool adjacencyMatrix[MAX_USERS][MAX_USERS];
    int numUsuarios;
    char nomesUsuarios[MAX_USERS][MAX_NAME_LENGTH];
} Grafo;

// Função para inicializar o grafo
void inicializarGrafo(Grafo *grafo) {
    grafo->numUsuarios = 0;
    for (int i = 0; i < MAX_USERS; i++) {
        for (int j = 0; j < MAX_USERS; j++) {
            grafo->adjacencyMatrix[i][j] = false;
        }
    }
}

// Função para adicionar um usuário ao grafo
void adicionarUsuario(Grafo *grafo, const char *nome) {
    if (grafo->numUsuarios < MAX_USERS) {
        strcpy(grafo->nomesUsuarios[grafo->numUsuarios], nome);
        grafo->numUsuarios++;
    } else {
        printf("O número máximo de usuários foi atingido.\n");
    }
}

// Função para adicionar uma amizade entre dois usuários
void adicionarAmizade(Grafo *grafo, int usuario1, int usuario2) {
    if (usuario1 < grafo->numUsuarios && usuario2 < grafo->numUsuarios) {
        grafo->adjacencyMatrix[usuario1][usuario2] = true;
        grafo->adjacencyMatrix[usuario2][usuario1] = true;
        printf("Amizade entre %s e %s adicionada.\n", grafo->nomesUsuarios[usuario1], grafo->nomesUsuarios[usuario2]);
    } else {
        printf("Usuário(s) inválido(s).\n");
    }
}

// Função para listar os amigos de um usuário
void listarAmigos(Grafo *grafo, int usuario) {
    printf("Amigos de %s:\n", grafo->nomesUsuarios[usuario]);
    for (int i = 0; i < grafo->numUsuarios; i++) {
        if (grafo->adjacencyMatrix[usuario][i]) {
            printf("%s ", grafo->nomesUsuarios[i]);
        }
    }
    printf("\n");
}

int main() {
    Grafo grafoSocial;
    inicializarGrafo(&grafoSocial);

    adicionarUsuario(&grafoSocial, "Ivys");
    adicionarUsuario(&grafoSocial, "Romário");
    adicionarUsuario(&grafoSocial, "Wilhu");

    adicionarAmizade(&grafoSocial, 0, 1);
    adicionarAmizade(&grafoSocial, 1, 2);

    listarAmigos(&grafoSocial, 0);
    listarAmigos(&grafoSocial, 1);
    listarAmigos(&grafoSocial, 2);

    return 0;
}
