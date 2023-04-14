/*Elabore um programa de uma calculadora onde o usuário informará o primeiro valor, a operação e o segundo valor, deverão serem implementadas as funções le_valida_n1, le _valida_n2, le_valida_operador, soma, subtracao, multiplicacao, divisao (considerar o tratamento da divisão por zero).
Também deverão serem desenvolvidos os procedimentos cabecalho, rodape e a cada operação realizada a tela deverá ser limpa reapresentando o cabeçalho e rodapé a cada operação realizada.
O resultado deverá ser apresentado na  tela conforme o exemplo abaixo  com a opção "Deseja continuar" sendo apresentada ao final:
+-----------------------------------+
|            SUPER CALC             |
+-----------------------------------+
|          O resultado da           |
|          soma 10+10 eh            |
|                20                 |
+-----------------------------------+
|          Copyright 2023           |
+-----------------------------------+
|      Deseja continuar? (S/N):     |
+-----------------------------------+

*/



#include <stdio.h>
#include <stdlib.h>

void cabecalho() {
    system("cls"); // limpa a tela
    printf("+-----------------------------------+\n");
    printf("|            SUPER CALC             |\n");
    printf("+-----------------------------------+\n");
}

void rodape() {
    printf("+-----------------------------------+\n");
    printf("|          Copyright 2023           |\n");
    printf("+-----------------------------------+\n");
}

int le_valida_n1() {
    int n1;
    printf("Digite o primeiro valor: ");
    scanf("%d", &n1);
    return n1;
}

int le_valida_n2() {
    int n2;
    printf("Digite o segundo valor: ");
    scanf("%d", &n2);
    return n2;
}

char le_valida_operador() {
    char op;
    printf("Digite a operacao (+,-,*,/): ");
    scanf(" %c", &op); // note o espaço antes do %c para evitar o bug de buffer
    return op;
}

int soma(int n1, int n2) {
    return n1 + n2;
}

int subtracao(int n1, int n2) {
    return n1 - n2;
}

int multiplicacao(int n1, int n2) {
    return n1 * n2;
}

int divisao(int n1, int n2) {
    if (n2 == 0) {
        printf("Erro: divisao por zero\n");
        return 0;
    }
    return n1 / n2;
}

int main() {
    char continuar = 'S';

    while (continuar == 'S') {
        cabecalho();
        int n1 = le_valida_n1();
        int n2 = le_valida_n2();
        char op = le_valida_operador();

        int resultado;
        switch (op) {
            case '+':
                resultado = soma(n1, n2);
                printf("|          O resultado da           |\n");
                printf("|          soma %d+%d eh            |\n", n1, n2);
                break;
            case '-':
                resultado = subtracao(n1, n2);
                printf("|          O resultado da           |\n");
                printf("|        subtracao %d-%d eh         |\n", n1, n2);
                break;
            case '*':
                resultado = multiplicacao(n1, n2);
                printf("|          O resultado da           |\n");
                printf("|      multiplicacao %d*%d eh       |\n", n1, n2);
                break;
            case '/':
                resultado = divisao(n1, n2);
                printf("|          O resultado da           |\n");
                printf("|         divisao %d/%d eh          |\n", n1, n2);
                break;
            default:
                printf("Erro: operacao invalida\n");
                resultado = 0;
        }
        printf("|                %d                 |\n", resultado);
        rodape();

        printf("Deseja continuar? (S/N): ");
        scanf(" %c", &continuar); // note o espaço antes do %c para evitar o bug de buffer
    }

    return 0;
}

