#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5
#define PLACA_SIZE 8

//Estrutura de uma pilha
typedef struct {
    char placa[PLACA_SIZE];
} Carro;

typedef struct {
    Carro carros[MAX];
    int topo;
} Pilha;

//Inicializa a pilha
void inicializaPilha(Pilha* p) {
    p->topo = -1;
}

//Verifica se a pilha está cheia
int pilhaCheia(Pilha* p) {
    return p->topo == MAX - 1;
}

//Verifica se a pilha está vazia
int pilhaVazia(Pilha* p) {
    return p->topo == -1;
}

//Empilha um carro
int empilha(Pilha* p, char placa[]) {
    if (pilhaCheia(p)) {
        return 0;
    }
    p->topo++;
    strcpy(p->carros[p->topo].placa, placa);
    return 1;
}

//Desempilha um carro
int desempilha(Pilha* p, char placa[]) {
    if (pilhaVazia(p)) {
        return 0;
    }
    strcpy(placa, p->carros[p->topo].placa);
    p->topo--;
    return 1;
}

//Função principal
int main() {
    Pilha estacionamento;
    inicializaPilha(&estacionamento);

    //Dados de entrada (podem ser alterados conforme necessário)
    char operacoes[][PLACA_SIZE + 2] = {
        "E ABC1234",
        "E DEF5678",
        "S ABC1234",
        "E GHI9012",
        "E JKL3456",
        "E MNO7890",
        "S DEF5678",
        "S GHI9012"
    };

    int n = sizeof(operacoes) / sizeof(operacoes[0]);

    for (int i = 0; i < n; i++) {
        char operacao = operacoes[i][0];
        char placa[PLACA_SIZE];
        strcpy(placa, operacoes[i] + 2);

        if (operacao == 'E') {
            printf("Carro %s chegou. ", placa);
            if (empilha(&estacionamento, placa)) {
                printf("Estacionado.\n");
            } else {
                printf("Sem vaga. O carro partiu sem entrar.\n");
            }
        } else if (operacao == 'S') {
            Pilha aux;
            inicializaPilha(&aux);
            char placaTemp[PLACA_SIZE];
            int manobras = 0;
            int found = 0;

            //Desempilhar até encontrar o carro desejado
            while (!pilhaVazia(&estacionamento)) {
                desempilha(&estacionamento, placaTemp);
                if (strcmp(placaTemp, placa) == 0) {
                    found = 1;
                    break;
                }
                empilha(&aux, placaTemp);
                manobras++;
            }

            //Voltar os carros para o estacionamento
            while (!pilhaVazia(&aux)) {
                desempilha(&aux, placaTemp);
                empilha(&estacionamento, placaTemp);
            }

            if (found) {
                printf("Carro %s saiu. Manobras realizadas: %d\n", placa, manobras);
            } else {
                printf("Carro %s não encontrado no estacionamento.\n", placa);
            }
        }
    }

    return 0;
}

/*
Nosso código em C implementa um sistema de gerenciamento de estacionamento de veículos usando uma estrutura de pilha.
A pilha é utilizada para armazenar as placas dos carros que estão estacionados, com a última placa empilhada sendo a do carro que chegou mais recentemente.

Funções principais:

inicializaPilha: Inicializa a pilha definindo o topo como -1, indicando que a pilha está vazia.
pilhaCheia: Verifica se a pilha está cheia, retornando 1 se o topo for igual ao tamanho máximo da pilha (-1).
pilhaVazia: Verifica se a pilha está vazia, retornando 1 se o topo for igual a -1.
empilha: Empilha uma placa na pilha, copiando-a para o topo da pilha e incrementando o topo. Retorna 1 em caso de sucesso e 0 se a pilha estiver cheia.
desempilha: Desempilha a placa do topo da pilha, copiando-a para a variável placa fornecida e decrementando o topo. Retorna 1 em caso de sucesso e 0 se a pilha estiver vazia.
main: Função principal do programa que simula o gerenciamento do estacionamento. Lê as operações de entrada (E para entrar e S para sair), processa cada operação e imprime as informações na tela.
Operações:

E (Entrada):
Tenta empilhar a placa do carro na pilha.
Se a pilha estiver cheia, imprime uma mensagem informando que o carro não conseguiu estacionar.
Se a pilha tiver vaga, empilha a placa e imprime uma mensagem informando que o carro foi estacionado.
S (Saída):
Procura a placa do carro na pilha.
Se a placa for encontrada, desempilha as placas até encontrar a placa desejada, contando as manobras realizadas.
Empilha as placas de volta na pilha na ordem inversa da desempilhagem.
Imprime uma mensagem informando se o carro foi encontrado e quantas manobras foram realizadas para retirá-lo, ou se o carro não foi encontrado.
Estrutura de dados:

Carro: Estrutura que armazena a placa do carro (string com 8 caracteres).
Pilha: Estrutura que armazena um vetor de carros (tamanho máximo MAX) e um contador de topo.
Observações:

O código assume que as placas dos carros são válidas e possuem o formato correto (8 caracteres).
O código não implementa tratamento de erros para situações como entrada de dados inválidos ou operações inválidas.
O código pode ser adaptado para diferentes cenários de estacionamento, como limite de tempo de estacionamento, cobrança de taxas, etc.
*/
