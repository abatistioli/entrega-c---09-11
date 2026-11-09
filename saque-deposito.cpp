#include <stdio.h>

int main() {
    int senha, senhaDigitada, opcao;
    float saldo = 500.00;
    float deposito, saque;
    float maiorDeposito = 0.00;

    // Criacao da senha de 4 digitos
    printf("===== CADASTRO DE SENHA =====\n");

    do {
        printf("Crie uma senha numerica de 4 digitos: ");
        scanf("%d", &senha);

        if (senha < 1000 || senha > 9999) {
            printf("Senha invalida! Digite exatamente 4 digitos.\n");
        }

    } while (senha < 1000 || senha > 9999);

    printf("\nSenha cadastrada com sucesso!\n");

    // Menu principal
    do {
        printf("\n===== MENU BANCARIO =====\n");
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Consultar Saldo e Estatisticas\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                // Deposito
                printf("\n===== DEPOSITO =====\n");
                printf("Digite o valor do deposito: R$ ");
                scanf("%f", &deposito);

                if (deposito <= 0) {
                    printf("Valor invalido!\n");
                } else {
                    saldo = saldo + deposito;

                    if (deposito > maiorDeposito) {
                        maiorDeposito = deposito;
                    }

                    printf("Deposito realizado com sucesso!\n");
                    printf("Saldo atual: R$ %.2f\n", saldo);
                }
                break;

            case 2:
                // Saque com verificacao de senha
                printf("\n===== SAQUE =====\n");
                printf("Digite sua senha de 4 digitos: ");
                scanf("%d", &senhaDigitada);

                if (senhaDigitada != senha) {
                    printf("Senha Incorreta! Operacao cancelada.\n");
                } else {
                    printf("Digite o valor do saque: R$ ");
                    scanf("%f", &saque);

                    if (saque <= 0) {
                        printf("Valor invalido!\n");
                    } else if (saque > saldo) {
                        printf("Saldo Insuficiente!\n");
                    } else {
                        saldo = saldo - saque;

                        printf("Saque realizado com sucesso!\n");
                        printf("Saldo atual: R$ %.2f\n", saldo);
                    }
                }
                break;

            case 3:
                // Consulta de saldo e estatisticas
                printf("\n===== SALDO E ESTATISTICAS =====\n");
                printf("Saldo atual: R$ %.2f\n", saldo);
                printf("Maior deposito realizado: R$ %.2f\n",
                       maiorDeposito);
                break;

            case 4:
                // Encerramento
                printf("\nObrigado por usar nosso banco!\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                break;
        }

    } while (opcao != 4);

    return 0;
}

