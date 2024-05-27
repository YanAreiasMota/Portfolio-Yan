#include <stdio.h>

//Código feito para agilizar processo de cálculo de eventos para a empresa BoutiqueA
int main() {
    int quantidadeEventos, i;
    int tipoEvento, numeroPessoas, duracaoBrunch, buffetEscolhido;
    float valorEvento, valorTotal = 0.0;
    float eventos[100]; // Assuming a maximum of 100 events

    printf("Digite a quantidade de eventos no mes: ");
    scanf("%d", &quantidadeEventos);

    while (quantidadeEventos <= 0) {
        printf("Quantidade de eventos deve ser maior que 0. Digite novamente: ");
        scanf("%d", &quantidadeEventos);
    }

    for (i = 1; i <= quantidadeEventos; i++) {
        printf("\n--- Evento %d ---\n", i);

        printf("Digite o tipo de evento (1 - brunch, 2 - casamento): ");
        scanf("%d", &tipoEvento);

        while (tipoEvento != 1 && tipoEvento != 2) {
            printf("Tipo de evento invalido. Digite novamente: ");
            scanf("%d", &tipoEvento);
        }

        printf("Digite o numero de pessoas: ");
        scanf("%d", &numeroPessoas);

        while (numeroPessoas <= 0) {
            printf("Numero de pessoas deve ser maior que 0. Digite novamente: ");
            scanf("%d", &numeroPessoas);
        }

        if (tipoEvento == 1) { // Brunch
            printf("Digite a duracao do brunch em horas (2, 3 ou 4): ");
            scanf("%d", &duracaoBrunch);

            while (duracaoBrunch != 2 && duracaoBrunch != 3 && duracaoBrunch != 4) {
                printf("Duracao invalida. Digite novamente: ");
                scanf("%d", &duracaoBrunch);
            }

            if (duracaoBrunch == 2) {
                valorEvento = numeroPessoas * 80.0;
            } else if (duracaoBrunch == 3) {
                valorEvento = numeroPessoas * 120.0;
            } else {
                valorEvento = numeroPessoas * 150.0;
            }
        } else { // Casamento
            printf("Tipos de buffets:\n");
            printf("1 - Simples (sem bebida alcoolica)\n");
            printf("2 - Simples (com bebida alcoolica)\n");
            printf("3 - Simples (com open bar)\n");
            printf("4 - Simples (com Heineken)\n");
            printf("5 - Simples (com open bar e Heineken)\n");
            printf("6 - Intermediario (sem bebida alcoolica)\n");
            printf("7 - Intermediario (com bebida alcoolica)\n");
            printf("8 - Intermediario (com open bar)\n");
            printf("9 - Intermediario (com Heineken)\n");
            printf("10 - Intermediario (com open bar e Heineken)\n");
            printf("11 - Completo (sem bebida alcoolica)\n");
            printf("12 - Completo (com bebida alcoolica)\n");
            printf("13 - Completo (com open bar)\n");
            printf("14 - Completo (com Heineken)\n");
            printf("15 - Completo (com open bar e Heineken)\n");

            printf("Digite o numero correspondente ao buffet escolhido: ");
            scanf("%d", &buffetEscolhido);

            while (buffetEscolhido < 1 || buffetEscolhido > 15) {
                printf("Numero de buffet invalido. Digite novamente: ");
                scanf("%d", &buffetEscolhido);
            }

            switch (buffetEscolhido) {
                case 1: // Simples (sem bebida alcoólica)
                    valorEvento = numeroPessoas * 85.0;
                    break;
                case 2: // Simples (com bebida alcoólica)
                    valorEvento = numeroPessoas * 100.0;
                    break;
                case 3: // Simples (com open bar)
                    valorEvento = numeroPessoas * 130.0;
                    break;
                case 4: // Simples (com Heineken)
                    valorEvento = numeroPessoas * 115.0;
                    break;
                case 5: // Simples (com open bar e Heineken)
                    valorEvento = numeroPessoas * 145.0;
                    break;
                case 6: // Intermediário (sem bebida alcoólica)
                    valorEvento = numeroPessoas * 120.0;
                    break;
                case 7: // Intermediário (com bebida alcoólica)
                    valorEvento = numeroPessoas * 160.0;
                    break;
                case 8: // Intermediário (com open bar)
                    valorEvento = numeroPessoas * 190.0;
                    break;
                case 9: // Intermediário (com Heineken)
                    valorEvento = numeroPessoas * 175.0;
                    break;
                case 10: // Intermediário (com open bar e Heineken)
                    valorEvento = numeroPessoas * 205.0;
                    break;
                case 11: // Completo (sem bebida alcoólica)
                    valorEvento = numeroPessoas * 165.0;
                    break;
                case 12: // Completo (com bebida alcoólica)
                    valorEvento = numeroPessoas * 200.0;
                    break;
                case 13: // Completo (com open bar)
                    valorEvento = numeroPessoas * 230.0;
                    break;
                case 14: // Completo (com Heineken)
                    valorEvento = numeroPessoas * 215.0;
                    break;
                case 15: // Completo (com open bar e Heineken)
                    valorEvento = numeroPessoas * 245.0;
                    break;
            }
        }

        eventos[i - 1] = valorEvento;
        valorTotal += valorEvento;
    }


    printf("\n------ Eventos ------\n");
    for (i = 1; i <= quantidadeEventos; i++) {
        printf("Evento %d: R$ %.2f\n", i, eventos[i - 1]);
    }
        printf("\nValor total dos eventos: R$ %.2f\n", valorTotal);

    return 0;
}
