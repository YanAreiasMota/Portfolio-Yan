#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxContatos 100

typedef struct {
    char nome[50];
    char telefone[15];
    char email[50];
} Contact;

Contact contatos[MaxContatos];
int quantidadeContatos = 0;

void addContatos() {
    if (quantidadeContatos >= MaxContatos) {
        printf("Lista de Contatos Cheia.\n");
        return;
    }

    printf("Digite o nome: ");
    scanf(" %[^\n]", contatos[quantidadeContatos].nome);
    printf("Digite o telefone: ");
    scanf(" %[^\n]", contatos[quantidadeContatos].telefone);
    printf("Digite o email: ");
    scanf(" %[^\n]", contatos[quantidadeContatos].email);

    quantidadeContatos++;
    printf("Contato adicionado.\n");
}

void MostrarContatos() {
    if (quantidadeContatos == 0) {
        printf("Nenhum contato adicionado.\n");
        return;
    }

    for (int i = 0; i < quantidadeContatos; i++) {
        printf("Contato %d:\n", i + 1);
        printf("nome: %s\n", contatos[i].nome);
        printf("telefone: %s\n", contatos[i].telefone);
        printf("Email: %s\n", contatos[i].email);
    }
}

void ProcurarContato() {
    char nome[50];
    printf("Insira o nome do contato: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < quantidadeContatos; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s\n", contatos[i].nome);
            printf("telefone: %s\n", contatos[i].telefone);
            printf("Email: %s\n", contatos[i].email);
            return;
        }
    }

    printf("O Contato não foi Encontrado.\n");
}

void DeletarContato() {
    char nome[50];
    printf("Insira o nome que deseja deletar: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < quantidadeContatos; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            for (int j = i; j < quantidadeContatos - 1; j++) {
                contatos[j] = contatos[j + 1];
            }
            quantidadeContatos--;
            printf("Contato Deletado.\n");
            return;
        }
    }

    printf("Contato não encontrado.\n");
}

int main() {
    int escolha;
    do {
        printf("\nLista de Contatos\n");
        printf("1. Adicionar Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Procurar Contato\n");
        printf("4. Deletar Contato\n");
        printf("5. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                addContatos();
                break;
            case 2:
                MostrarContatos();
                break;
            case 3:
                ProcurarContato();
                break;
            case 4:
                DeletarContato();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Escolha invalida, tente novamente.\n");
        }
    } while (escolha != 5);

    return 0;
}
