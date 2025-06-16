#include <stdio.h>

int main() {
    char estado1[50];
    char cidade1[50];
    char codigo1[50];
    int turisticos1;
    int populacao1;
    float pib1;
    float km1;

    char estado2[50];
    char cidade2[50];
    char codigo2[50];
    int turisticos2;
    int populacao2;
    float pib2;
    float km2;

    // entrada 1
    printf("Digite o nome do estado da primeira carta:\n");
    scanf("%49s", estado1);

    printf("Digite o nome da cidade da primeira carta:\n");
    scanf("%49s", cidade1);

    printf("Digite o código da cidade da primeira carta:\n");
    scanf("%49s", codigo1);

    printf("Digite a quantidade da população da primeira carta:\n");
    scanf("%d", &populacao1);

    printf("Digite a quantidade de pontos turísticos da primeira carta:\n");
    scanf("%d", &turisticos1);

    printf("Digite o valor do PIB para a primeira carta:\n");
    scanf("%f", &pib1);

    printf("Digite o tamanho da área em quilômetros quadrados da primeira carta:\n");
    scanf("%f", &km1);

    // entrada 2
    printf("Digite o nome do estado da segunda carta:\n");
    scanf("%49s", estado2);

    printf("Digite o nome da cidade da segunda carta:\n");
    scanf("%49s", cidade2);

    printf("Digite o código da cidade da segunda carta:\n");
    scanf("%49s", codigo2);

    printf("Digite a quantidade da população da segunda carta:\n");
    scanf("%d", &populacao2);

    printf("Digite a quantidade de pontos turísticos da segunda carta:\n");
    scanf("%d", &turisticos2);

    printf("Digite o valor do PIB para a segunda carta:\n");
    scanf("%f", &pib2);

    printf("Digite o tamanho da área em quilômetros quadrados da segunda carta:\n");
    scanf("%f", &km2);

    // saida
    printf("\nEstado1: %s - População: %d\n", estado1, populacao1);
    printf("Cidade: %s - Código: %s\n", cidade1, codigo1);
    printf("Pontos turísticos: %d - PIB: %.2f\n", turisticos1, pib1);
    printf("Quilômetros quadrados: %.2f\n", km1);
    printf("Estado2: %s - População: %d\n", estado2, populacao2);
    printf("Cidade: %s - Código: %s\n", cidade2, codigo2);
    printf("Pontos turísticos: %d - PIB: %.2f\n", turisticos2, pib2);
    printf("Quilômetros quadrados: %.2f\n", km2);

    // Determina PIB
    if (pib1 > pib2) {
        printf("Carta 1 venceu!\n");
    } else if (pib2 > pib1) {
        printf("Carta 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}