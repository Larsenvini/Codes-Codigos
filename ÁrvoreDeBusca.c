#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 16 // Máximo de 15 letras + '\0'
#define MAX_WORDS 1000     // Supondo um limite máximo de palavras.

//Definição do nó da árvore
typedef struct TreeNode {
    char word[MAX_WORD_LENGTH];
    int count;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

//Função para criar um novo nó na árvore
TreeNode* createNode(char* word) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Função para inserir uma palavra na árvore
TreeNode* insert(TreeNode* root, char* word) {
    if (root == NULL) {
        return createNode(word);
    }

    int cmp = strcmp(word, root->word);
    if (cmp == 0) {
        root->count++;
    } else if (cmp < 0) {
        root->left = insert(root->left, word);
    } else {
        root->right = insert(root->right, word);
    }
    return root;
}

//Função para realizar a travessia em ordem na árvore e imprimir as palavras
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s (%d)\n", root->word, root->count);
        inorder(root->right);
    }
}

//Função para liberar a memória da árvore
void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

//Função para processar as palavras e montar a árvore
void processaPalavras(char* str[]) {
    TreeNode* root = NULL;
    for (int i = 0; str[i][0] != '\0'; i++) {
        root = insert(root, str[i]);
    }
    inorder(root);
    freeTree(root);
}

//Função principal para testar o código
int main() {
    char* palavras[MAX_WORDS];
    char buffer[MAX_WORD_LENGTH];
    int count = 0;

    printf("Digite as palavras (Pressione Enter em uma linha vazia para finalizar):\n");

    while (1) {
        fgets(buffer, MAX_WORD_LENGTH, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove o caractere de nova linha

        if (buffer[0] == '\0') {
            break;
        }

        palavras[count] = (char*)malloc(strlen(buffer) + 1);
        if (palavras[count] == NULL) {
            printf("Erro de alocação de memória!\n");
            exit(1);
        }
        strcpy(palavras[count], buffer);
        count++;
    }

    palavras[count] = "\0"; // Marca o final da lista de palavras

    processaPalavras(palavras);

    //Libera a memória alocada para as palavras
    for (int i = 0; i < count; i++) {
        free(palavras[i]);
    }

    return 0;
}

/*
Entrada do Usuário:

Utilizamos fgets para ler as palavras do usuário, garantindo que o buffer de
entrada não exceda o tamanho máximo permitido.
Removemos o caractere de nova linha (\n) que fgets adiciona ao final da entrada.
Armazenamento das Palavras:

Alocamos memória dinamicamente para cada palavra lida e armazenamos um ponteiro
para essa memória no array palavras.
Finalizamos a lista de palavras com uma string vazia ("\0").
Processamento e Impressão:

A função processaPalavras insere as palavras na árvore e imprime a frequência
das palavras em ordem alfabética.
A função freeTree libera a memória da árvore após o processamento.
A memória alocada para as palavras também é liberada após o uso.
Nosso código lê as palavras da entrada padrão, constrói uma árvore binária de
busca para contar as ocorrências de cada palavra, e imprime as palavras em
ordem alfabética com suas respectivas contagens. Ao final, libera toda a
 memória alocada dinamicamente"
 */
