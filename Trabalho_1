#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da lista
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para adicionar um nó no início da lista
void addAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Função para adicionar um nó no final da lista
void addAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Função para adicionar um nó em uma posição específica da lista
void addAtPosition(Node** head, int data, int position) {
    if (position < 0) {
        printf("Posição inválida!\n");
        return;
    }
    if (position == 0) {
        addAtBeginning(head, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Posição fora dos limites da lista!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Função para listar todos os elementos da lista
void printList(Node* head) {
    if (head == NULL) {
        printf("Lista está vazia.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Função para listar um elemento específico da lista
void printElementAtPosition(Node* head, int position) {
    if (position < 0) {
        printf("Posição inválida!\n");
        return;
    }
    Node* temp = head;
    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Posição fora dos limites da lista!\n");
        return;
    }
    printf("Elemento na posição %d: %d\n", position, temp->data);
}

// Função para excluir o primeiro nó da lista
void deleteAtBeginning(Node** head) {
    if (*head == NULL) {
        printf("Lista está vazia.\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Função para excluir o último nó da lista
void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("Lista está vazia.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Função para excluir um nó em uma posição específica da lista
void deleteAtPosition(Node** head, int position) {
    if (position < 0) {
        printf("Posição inválida!\n");
        return;
    }
    if (*head == NULL) {
        printf("Lista está vazia.\n");
        return;
    }
    if (position == 0) {
        deleteAtBeginning(head);
        return;
    }
    Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Posição fora dos limites da lista!\n");
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

// Função para liberar todos os nós da lista
void freeList(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
    printf("Lista liberada e está vazia.\n");
}

int main() {
    Node* head = NULL;
    int choice, data, position;

    do {
        printf("------------------------------------------------------------------\n");
        printf("MENU DE OPÇÕES\n");
        printf("------------------------------------------------------------------\n");
        printf("[1] Adicionar no início da lista\n");
        printf("[2] Adicionar no final da lista\n");
        printf("[3] Adicionar em um ponto específico da lista\n");
        printf("[4] Listar todos os elementos da lista\n");
        printf("[5] Listar um elemento específico da lista\n");
        printf("[6] Excluir do início da lista\n");
        printf("[7] Excluir do final da lista\n");
        printf("[8] Excluir de um ponto específico da lista\n");
        printf("[9] Liberar os elementos e mostrar a lista vazia\n");
        printf("[0] Terminar\n");
        printf("------------------------------------------------------------------\n");
        printf("Qual a sua opção? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor a ser adicionado: ");
                scanf("%d", &data);
                addAtBeginning(&head, data);
                break;
            case 2:
                printf("Digite o valor a ser adicionado: ");
                scanf("%d", &data);
                addAtEnd(&head, data);
                break;
            case 3:
                printf("Digite o valor a ser adicionado: ");
                scanf("%d", &data);
                printf("Digite a posição: ");
                scanf("%d", &position);
                addAtPosition(&head, data, position);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                printf("Digite a posição: ");
                scanf("%d", &position);
                printElementAtPosition(head, position);
                break;
            case 6:
                deleteAtBeginning(&head);
                break;
            case 7:
                deleteAtEnd(&head);
                break;
            case 8:
                printf("Digite a posição: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 9:
                freeList(&head);
                break;
            case 0:
                printf("Terminando o programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (choice != 0);

    // Liberar memória antes de sair
    freeList(&head);

    return 0;
}
/*
Nosso código em C implementa uma lista ligada dinâmica com diversas operações, incluindo inserção, remoção e consulta de elementos. A lista é composta por nós (structs) que armazenam um valor (data) e um ponteiro para o próximo nó (next).

Funções principais:

createNode: Aloca memória para um novo nó, define o valor e o ponteiro next para NULL e retorna o ponteiro para o novo nó.
addAtBeginning: Adiciona um novo nó no início da lista.
addAtEnd: Adiciona um novo nó no final da lista.
addAtPosition: Adiciona um novo nó em uma posição específica da lista.
printList: Imprime todos os elementos da lista.
printElementAtPosition: Imprime o elemento em uma posição específica da lista.
deleteAtBeginning: Exclui o primeiro nó da lista.
deleteAtEnd: Exclui o último nó da lista.
deleteAtPosition: Exclui o nó em uma posição específica da lista.
freeList: Libera todos os nós da lista e define o ponteiro head como NULL.
Menu principal:

O programa apresenta um menu interativo com as seguintes opções:

Adicionar no início da lista
Adicionar no final da lista
Adicionar em um ponto específico da lista
Listar todos os elementos da lista
Listar um elemento específico da lista
Excluir do início da lista
Excluir do final da lista
Excluir de um ponto específico da lista
Liberar os elementos e mostrar a lista vazia
Terminar
O usuário escolhe uma opção e o programa executa a operação correspondente.

Observações:

O código assume que o usuário digita valores válidos para as operações.
A lista implementada é unidirecional, ou seja, os nós possuem apenas um ponteiro para o próximo nó.
O código pode ser adaptado para implementar outros tipos de listas ligadas, como listas duplamente ligadas ou listas circulares.
Exemplo de uso:

O usuário escolhe a opção 1 e digita o valor 10. O nó com valor 10 é adicionado no início da lista.
O usuário escolhe a opção 4 e a lista é impressa: 10 -> NULL.
O usuário escolhe a opção 3, digita o valor 20 e a posição 1. O nó com valor 20 é adicionado após o primeiro nó: 10 -> 20 -> NULL.
O usuário escolhe a opção 5 e digita a posição 1. O elemento na posição 1 é impresso: 20.
O usuário escolhe a opção 9. A lista é liberada e a mensagem "Lista liberada e está vazia." é impressa.
Melhorias possíveis:

Implementar verificação de erros para entrada de dados inválidos.
Implementar funções para buscar um elemento na lista por valor.
Implementar funções para inserir e remover vários elementos de uma vez.
Converter a lista para uma string.
Implementar ordenação da lista.
*/
